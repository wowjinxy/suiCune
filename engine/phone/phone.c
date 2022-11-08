#include "../../constants.h"
#include "phone.h"

void AddPhoneNumber(void){
    CALL(av_CheckCellNum);
    IF_C goto cant_add;
    CALL(aPhone_FindOpenSlot);
    IF_NC goto cant_add;
    LD_hl_C;
    XOR_A_A;
    RET;


cant_add:
    SCF;
    RET;

}

void DelCellNum(void){
    CALL(av_CheckCellNum);
    IF_NC goto not_in_list;
    XOR_A_A;
    LD_hl_A;
    RET;


not_in_list:
    SCF;
    RET;

}

void CheckCellNum(void){
    JP(mv_CheckCellNum);  // useless

}

void v_CheckCellNum(void){
    LD_HL(wPhoneList);
    LD_B(CONTACT_LIST_SIZE);

loop:
    LD_A_hli;
    CP_A_C;
    IF_Z goto got_it;
    DEC_B;
    IF_NZ goto loop;
    XOR_A_A;
    RET;


got_it:
    DEC_HL;
    SCF;
    RET;

}

void Phone_FindOpenSlot(void){
    CALL(aGetRemainingSpaceInPhoneList);
    LD_B_A;
    LD_HL(wPhoneList);

loop:
    LD_A_hli;
    AND_A_A;
    IF_Z goto FoundOpenSpace;
    DEC_B;
    IF_NZ goto loop;
    XOR_A_A;
    RET;


FoundOpenSpace:
    DEC_HL;
    SCF;
    RET;

}

void GetRemainingSpaceInPhoneList(void){
    XOR_A_A;
    LD_addr_A(wRegisteredPhoneNumbers);
    LD_HL(mPermanentNumbers);

loop:
    LD_A_hli;
    CP_A(-1);
    IF_Z goto done;
    CP_A_C;
    IF_Z goto continue_;

    PUSH_BC;
    PUSH_HL;
    LD_C_A;
    CALL(av_CheckCellNum);
    IF_C goto permanent;
    LD_HL(wRegisteredPhoneNumbers);
    INC_hl;

permanent:
    POP_HL;
    POP_BC;


continue_:
    goto loop;


done:
    LD_A(CONTACT_LIST_SIZE);
    LD_HL(wRegisteredPhoneNumbers);
    SUB_A_hl;
    RET;

// INCLUDE "data/phone/permanent_numbers.asm"

    return BrokenPlaceFarString();
}

void BrokenPlaceFarString(void){
//  This routine is not in bank 0 and will fail or crash if called.
    LDH_A_addr(hROMBank);
    PUSH_AF;
    LD_A_B;
    RST(aBankswitch);

    CALL(aPlaceString);

    POP_AF;
    RST(aBankswitch);
    RET;

}

void CheckPhoneCall(void){
//  Check if the phone is ringing in the overworld.

    CALL(aCheckStandingOnEntrance);
    IF_Z goto no_call;

    CALL(aCheckPhoneCall_timecheck);
    NOP;
    IF_NC goto no_call;

// 50% chance for a call
    CALL(aRandom);
    LD_B_A;
    AND_A(0b01111111);
    CP_A_B;
    IF_NZ goto no_call;

    CALL(aGetMapPhoneService);
    AND_A_A;
    IF_NZ goto no_call;

    CALL(aGetAvailableCallers);
    CALL(aChooseRandomCaller);
    IF_NC goto no_call;

    LD_E_A;
    CALL(aLoadCallerScript);
    LD_A(BANK(aScript_ReceivePhoneCall));
    LD_HL(mScript_ReceivePhoneCall);
    CALL(aCallScript);
    SCF;
    RET;


no_call:
    XOR_A_A;
    RET;


timecheck:
    FARCALL(aCheckReceiveCallTimer);
    RET;

}

void CheckPhoneContactTimeOfDay(void){
    PUSH_HL;
    PUSH_BC;
    PUSH_DE;
    PUSH_AF;

    FARCALL(aCheckTime);
    POP_AF;
    AND_A(ANYTIME);
    AND_A_C;

    POP_DE;
    POP_BC;
    POP_HL;
    RET;

}

void ChooseRandomCaller(void){
//  If no one is available to call, don't return anything.
    LD_A_addr(wNumAvailableCallers);
    AND_A_A;
    IF_Z goto NothingToSample;

//  Store the number of available callers in c.
    LD_C_A;
//  Sample a random number between 0 and 31.
    CALL(aRandom);
    LDH_A_addr(hRandomAdd);
    SWAP_A;
    AND_A(0x1f);
//  Compute that number modulo the number of available callers.
    CALL(aSimpleDivide);
//  Return the caller ID you just sampled.
    LD_C_A;
    LD_B(0);
    LD_HL(wAvailableCallers);
    ADD_HL_BC;
    LD_A_hl;
    SCF;
    RET;


NothingToSample:
    XOR_A_A;
    RET;

}

void GetAvailableCallers(void){
    FARCALL(aCheckTime);
    LD_A_C;
    LD_addr_A(wCheckedTime);
    LD_HL(wNumAvailableCallers);
    LD_BC(CONTACT_LIST_SIZE + 1);
    XOR_A_A;
    CALL(aByteFill);
    LD_DE(wPhoneList);
    LD_A(CONTACT_LIST_SIZE);


loop:
    LD_addr_A(wPhoneListIndex);
    LD_A_de;
    AND_A_A;
    IF_Z goto not_good_for_call;
    LD_HL(mPhoneContacts + PHONE_CONTACT_SCRIPT2_TIME);
    LD_BC(PHONE_CONTACT_SIZE);
    CALL(aAddNTimes);
    LD_A_addr(wCheckedTime);
    AND_A_hl;
    IF_Z goto not_good_for_call;
    LD_BC(PHONE_CONTACT_MAP_GROUP - PHONE_CONTACT_SCRIPT2_TIME);
    ADD_HL_BC;
    LD_A_addr(wMapGroup);
    CP_A_hl;
    IF_NZ goto different_map;
    INC_HL;
    LD_A_addr(wMapNumber);
    CP_A_hl;
    IF_Z goto not_good_for_call;

different_map:
    LD_A_addr(wNumAvailableCallers);
    LD_C_A;
    LD_B(0);
    INC_A;
    LD_addr_A(wNumAvailableCallers);
    LD_HL(wAvailableCallers);
    ADD_HL_BC;
    LD_A_de;
    LD_hl_A;

not_good_for_call:
    INC_DE;
    LD_A_addr(wPhoneListIndex);
    DEC_A;
    IF_NZ goto loop;
    RET;

}

void CheckSpecialPhoneCall(void){
    LD_A_addr(wSpecialPhoneCallID);
    AND_A_A;
    IF_Z goto NoPhoneCall;

    DEC_A;
    LD_C_A;
    LD_B(0);
    LD_HL(mSpecialPhoneCallList);
    LD_A(SPECIALCALL_SIZE);
    CALL(aAddNTimes);
    LD_A_hli;
    LD_H_hl;
    LD_L_A;
    CALL(av_hl_);
    IF_NC goto NoPhoneCall;

    CALL(aCheckSpecialPhoneCall_DoSpecialPhoneCall);
    INC_HL;
    INC_HL;
    LD_A_hli;
    LD_E_A;
    PUSH_HL;
    CALL(aLoadCallerScript);
    POP_HL;
    LD_DE(wCallerContact + PHONE_CONTACT_SCRIPT2_BANK);
    LD_A_hli;
    LD_de_A;
    INC_DE;
    LD_A_hli;
    LD_de_A;
    INC_DE;
    LD_A_hli;
    LD_de_A;
    LD_A(BANK(aCheckSpecialPhoneCall_script));
    LD_HL(mCheckSpecialPhoneCall_script);
    CALL(aCallScript);
    SCF;
    RET;

NoPhoneCall:
    XOR_A_A;
    RET;


script:
    //pause ['30']
    //sjump ['Script_ReceivePhoneCall']


DoSpecialPhoneCall:
    LD_A_addr(wSpecialPhoneCallID);
    DEC_A;
    LD_C_A;
    LD_B(0);
    LD_HL(mSpecialPhoneCallList);
    LD_A(SPECIALCALL_SIZE);
    CALL(aAddNTimes);
    RET;

}

void SpecialCallOnlyWhenOutside(void){
    LD_A_addr(wEnvironment);
    CP_A(TOWN);
    IF_Z goto outside;
    CP_A(ROUTE);
    IF_Z goto outside;
    XOR_A_A;
    RET;


outside:
    SCF;
    RET;

}

void SpecialCallWhereverYouAre(void){
    SCF;
    RET;

}

void MakePhoneCallFromPokegear(void){
// Don't do the call if you're in a link communication
    LD_A_addr(wLinkMode);
    AND_A_A;
    IF_NZ goto OutOfArea;
// If you're in an area without phone service, don't do the call
    CALL(aGetMapPhoneService);
    AND_A_A;
    IF_NZ goto OutOfArea;
// If the person can't take a call at that time, don't do the call
    LD_A_B;
    LD_addr_A(wCurCaller);
    LD_HL(mPhoneContacts);
    LD_BC(PHONE_CONTACT_SIZE);
    CALL(aAddNTimes);
    LD_D_H;
    LD_E_L;
    LD_HL(PHONE_CONTACT_SCRIPT1_TIME);
    ADD_HL_DE;
    LD_A_hl;
    CALL(aCheckPhoneContactTimeOfDay);
    IF_Z goto OutOfArea;
// If we're in the same map as the person we're calling,
// use the "Just talk to that person" script.
    LD_HL(PHONE_CONTACT_MAP_GROUP);
    ADD_HL_DE;
    LD_A_addr(wMapGroup);
    CP_A_hl;
    IF_NZ goto GetPhoneScript;
    LD_HL(PHONE_CONTACT_MAP_NUMBER);
    ADD_HL_DE;
    LD_A_addr(wMapNumber);
    CP_A_hl;
    IF_NZ goto GetPhoneScript;
    LD_B(BANK(aPhoneScript_JustTalkToThem));
    LD_HL(mPhoneScript_JustTalkToThem);
    goto DoPhoneCall;


GetPhoneScript:
    LD_HL(PHONE_CONTACT_SCRIPT1_BANK);
    ADD_HL_DE;
    LD_B_hl;
    LD_HL(PHONE_CONTACT_SCRIPT1_ADDR);
    ADD_HL_DE;
    LD_A_hli;
    LD_H_hl;
    LD_L_A;
    goto DoPhoneCall;


OutOfArea:
    LD_B(BANK(aLoadOutOfAreaScript));
    LD_DE(mLoadOutOfAreaScript);
    CALL(aExecuteCallbackScript);
    RET;


DoPhoneCall:
    LD_A_B;
    LD_addr_A(wPhoneScriptBank);
    LD_A_L;
    LD_addr_A(wPhoneCaller);
    LD_A_H;
    LD_addr_A(wPhoneCaller + 1);
    LD_B(BANK(aLoadPhoneScriptBank));
    LD_DE(mLoadPhoneScriptBank);
    CALL(aExecuteCallbackScript);
    RET;

}

void LoadPhoneScriptBank(void){
    //memcall ['wPhoneScriptBank']
    //endcallback ['?']

    return LoadOutOfAreaScript();
}

void LoadOutOfAreaScript(void){
    //scall ['PhoneOutOfAreaScript']
    //endcallback ['?']

    return LoadCallerScript();
}

void LoadCallerScript(void){
    NOP;
    NOP;
    LD_A_E;
    LD_addr_A(wCurCaller);
    AND_A_A;
    IF_NZ goto actualcaller;
    LD_A(BANK(aWrongNumber));
    LD_HL(mWrongNumber);
    goto proceed;


actualcaller:
    LD_HL(mPhoneContacts);
    LD_BC(PHONE_CONTACT_SIZE);
    LD_A_E;
    CALL(aAddNTimes);
    LD_A(BANK(aPhoneContacts));

proceed:
    LD_DE(wCallerContact);
    LD_BC(PHONE_CONTACT_SIZE);
    CALL(aFarCopyBytes);
    RET;

}

void WrongNumber(void){
    //db ['TRAINER_NONE', 'PHONE_00'];
    //dba ['.script']

script:
    //writetext ['.PhoneWrongNumberText']
    //end ['?']

PhoneWrongNumberText:
    //text_far ['_PhoneWrongNumberText']
    //text_end ['?']

    return Script_ReceivePhoneCall();
}

void Script_ReceivePhoneCall(void){
    //refreshscreen ['?']
    //callasm ['RingTwice_StartCall']
    //memcall ['wCallerContact + PHONE_CONTACT_SCRIPT2_BANK']
    //waitbutton ['?']
    //callasm ['HangUp']
    //closetext ['?']
    //callasm ['InitCallReceiveDelay']
    //end ['?']

    return Script_SpecialBillCall();
}

void Script_SpecialBillCall(void){
    //callasm ['.LoadBillScript']
    //sjump ['Script_ReceivePhoneCall']


LoadBillScript:
    LD_E(PHONE_BILL);
    JP(mLoadCallerScript);

}

void Script_SpecialElmCall(void){
//  //  unreferenced
    //callasm ['.LoadElmScript']
    //pause ['30']
    //sjump ['Script_ReceivePhoneCall']


LoadElmScript:
    LD_E(PHONE_ELM);
    JP(mLoadCallerScript);

}

void RingTwice_StartCall(void){
    CALL(aRingTwice_StartCall_Ring);
    CALL(aRingTwice_StartCall_Ring);
    FARCALL(aStubbedTrainerRankings_PhoneCalls);
    RET;


Ring:
    CALL(aPhone_StartRinging);
    CALL(aPhone_Wait20Frames);
    CALL(aRingTwice_StartCall_CallerTextboxWithName);
    CALL(aPhone_Wait20Frames);
    CALL(aPhone_CallerTextbox);
    CALL(aPhone_Wait20Frames);
    CALL(aRingTwice_StartCall_CallerTextboxWithName);
    RET;


CallerTextboxWithName:
    LD_A_addr(wCurCaller);
    LD_B_A;
    CALL(aPhone_TextboxWithName);
    RET;

}

void PhoneCall(void){
    LD_A_B;
    LD_addr_A(wPhoneScriptBank);
    LD_A_E;
    LD_addr_A(wPhoneCaller);
    LD_A_D;
    LD_addr_A(wPhoneCaller + 1);
    CALL(aPhoneCall_Ring);
    CALL(aPhoneCall_Ring);
    FARCALL(aStubbedTrainerRankings_PhoneCalls);
    RET;


Ring:
    CALL(aPhone_StartRinging);
    CALL(aPhone_Wait20Frames);
    CALL(aPhoneCall_CallerTextboxWithName);
    CALL(aPhone_Wait20Frames);
    CALL(aPhone_CallerTextbox);
    CALL(aPhone_Wait20Frames);
    CALL(aPhoneCall_CallerTextboxWithName);
    RET;


CallerTextboxWithName:
    CALL(aPhone_CallerTextbox);
    hlcoord(1, 2, wTilemap);
    LD_hl(0x62);
    INC_HL;
    INC_HL;
    LD_A_addr(wPhoneScriptBank);
    LD_B_A;
    LD_A_addr(wPhoneCaller);
    LD_E_A;
    LD_A_addr(wPhoneCaller + 1);
    LD_D_A;
    CALL(aBrokenPlaceFarString);
    RET;

}

void Phone_NoSignal(void){
    LD_DE(SFX_NO_SIGNAL);
    CALL(aPlaySFX);
    JR(mPhone_CallEnd);

}

void HangUp(void){
    CALL(aHangUp_Beep);
    CALL(aHangUp_Wait20Frames);
    return Phone_CallEnd();
}

void Phone_CallEnd(void){
    CALL(aHangUp_BoopOn);
    CALL(aHangUp_Wait20Frames);
    CALL(aHangUp_BoopOff);
    CALL(aHangUp_Wait20Frames);
    CALL(aHangUp_BoopOn);
    CALL(aHangUp_Wait20Frames);
    CALL(aHangUp_BoopOff);
    CALL(aHangUp_Wait20Frames);
    CALL(aHangUp_BoopOn);
    CALL(aHangUp_Wait20Frames);
    CALL(aHangUp_BoopOff);
    CALL(aHangUp_Wait20Frames);
    RET;

}

void HangUp_ShutDown(void){
//  //  unreferenced
    LD_DE(SFX_SHUT_DOWN_PC);
    CALL(aPlaySFX);
    RET;

}

void HangUp_Beep(void){
    LD_HL(mPhoneClickText);
    CALL(aPrintText);
    LD_DE(SFX_HANG_UP);
    CALL(aPlaySFX);
    RET;

}

void PhoneClickText(void){
    //text_far ['_PhoneClickText']
    //text_end ['?']

    return HangUp_BoopOn();
}

void HangUp_BoopOn(void){
    LD_HL(mPhoneEllipseText);
    CALL(aPrintText);
    RET;

}

void PhoneEllipseText(void){
    //text_far ['_PhoneEllipseText']
    //text_end ['?']

    return HangUp_BoopOff();
}

void HangUp_BoopOff(void){
    CALL(aSpeechTextbox);
    RET;

}

void Phone_StartRinging(void){
    CALL(aWaitSFX);
    LD_DE(SFX_CALL);
    CALL(aPlaySFX);
    CALL(aPhone_CallerTextbox);
    CALL(aUpdateSprites);
    FARCALL(aPhoneRing_CopyTilemapAtOnce);
    RET;

}

void HangUp_Wait20Frames(void){
    JR(mPhone_Wait20Frames);

}

void Phone_Wait20Frames(void){
    LD_C(20);
    CALL(aDelayFrames);
    FARCALL(aPhoneRing_CopyTilemapAtOnce);
    RET;

}

void Phone_TextboxWithName(void){
    PUSH_BC;
    CALL(aPhone_CallerTextbox);
    hlcoord(1, 1, wTilemap);
    LD_hl(0x62);
    INC_HL;
    INC_HL;
    LD_D_H;
    LD_E_L;
    POP_BC;
    CALL(aGetCallerClassAndName);
    RET;

}

void Phone_CallerTextbox(void){
    hlcoord(0, 0, wTilemap);
    LD_B(2);
    LD_C(SCREEN_WIDTH - 2);
    CALL(aTextbox);
    RET;

}

void GetCallerClassAndName(void){
    LD_H_D;
    LD_L_E;
    LD_A_B;
    CALL(aGetCallerTrainerClass);
    CALL(aGetCallerName);
    RET;

}

void CheckCanDeletePhoneNumber(void){
    LD_A_C;
    CALL(aGetCallerTrainerClass);
    LD_A_C;
// and a
    RET_NZ ;
    LD_A_B;
    CP_A(PHONECONTACT_MOM);
    RET_Z ;
    CP_A(PHONECONTACT_ELM);
    RET_Z ;
    LD_C(0x1);
    RET;

}

void GetCallerTrainerClass(void){
    PUSH_HL;
    LD_HL(mPhoneContacts + PHONE_CONTACT_TRAINER_CLASS);
    LD_BC(PHONE_CONTACT_SIZE);
    CALL(aAddNTimes);
    LD_A_hli;
    LD_B_hl;
    LD_C_A;
    POP_HL;
    RET;

}

void GetCallerName(void){
    LD_A_C;
    AND_A_A;
    IF_Z goto NotTrainer;

    CALL(aPhone_GetTrainerName);
    PUSH_HL;
    PUSH_BC;
    CALL(aPlaceString);
    LD_A(0x9c);
    LD_bc_A;
    POP_BC;
    POP_HL;
    LD_DE(SCREEN_WIDTH + 3);
    ADD_HL_DE;
    CALL(aPhone_GetTrainerClassName);
    CALL(aPlaceString);
    RET;


NotTrainer:
    PUSH_HL;
    LD_C_B;
    LD_B(0);
    LD_HL(mNonTrainerCallerNames);
    ADD_HL_BC;
    ADD_HL_BC;
    LD_A_hli;
    LD_E_A;
    LD_D_hl;
    POP_HL;
    CALL(aPlaceString);
    RET;

// INCLUDE "data/phone/non_trainer_names.asm"

    return Phone_GetTrainerName();
}

void Phone_GetTrainerName(void){
    PUSH_HL;
    PUSH_BC;
    FARCALL(aGetTrainerName);
    POP_BC;
    POP_HL;
    RET;

}

void Phone_GetTrainerClassName(void){
    PUSH_HL;
    PUSH_BC;
    FARCALL(aGetTrainerClassName);
    POP_BC;
    POP_HL;
    RET;

}

void GetCallerLocation(void){
    LD_A_addr(wCurCaller);
    CALL(aGetCallerTrainerClass);
    LD_D_C;
    LD_E_B;
    PUSH_DE;
    LD_A_addr(wCurCaller);
    LD_HL(mPhoneContacts + PHONE_CONTACT_MAP_GROUP);
    LD_BC(PHONE_CONTACT_SIZE);
    CALL(aAddNTimes);
    LD_B_hl;
    INC_HL;
    LD_C_hl;
    PUSH_BC;
    CALL(aGetWorldMapLocation);
    LD_E_A;
    FARCALL(aGetLandmarkName);
    POP_BC;
    POP_DE;
    RET;

// INCLUDE "data/phone/phone_contacts.asm"

// INCLUDE "data/phone/special_calls.asm"

    return PhoneOutOfAreaScript();
}

void PhoneOutOfAreaScript(void){
    //writetext ['PhoneOutOfAreaText']
    //end ['?']

    return PhoneOutOfAreaText();
}

void PhoneOutOfAreaText(void){
    //text_far ['_PhoneOutOfAreaText']
    //text_end ['?']

    return PhoneScript_JustTalkToThem();
}

void PhoneScript_JustTalkToThem(void){
    //writetext ['PhoneJustTalkToThemText']
    //end ['?']

    return PhoneJustTalkToThemText();
}

void PhoneJustTalkToThemText(void){
    //text_far ['_PhoneJustTalkToThemText']
    //text_end ['?']

    return PhoneThankYouTextScript();
}

void PhoneThankYouTextScript(void){
//  //  unreferenced
    //writetext ['PhoneThankYouText']
    //end ['?']

    return PhoneThankYouText();
}

void PhoneThankYouText(void){
    //text_far ['_PhoneThankYouText']
    //text_end ['?']

}
