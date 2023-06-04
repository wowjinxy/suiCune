#include "../constants.h"
#include "buena.h"

void BuenaPhoneCalleeScript(void){
    //checkflag ['ENGINE_ROCKETS_IN_RADIO_TOWER']
    //iftrue ['BuenaPhoneScript_Rocket']
    //readvar ['VAR_HOUR']
    //ifgreater ['17', 'BuenaPhoneScript_AfterMidnightCallee']
    //scall ['BuenaPhoneScript_CheckTimeOfDayCallee']
    //sjump ['BuenaPhoneScript_RandomCallee']

    return BuenaPhoneCallerScript();
}

void BuenaPhoneCallerScript(void){
    //checkflag ['ENGINE_ROCKETS_IN_RADIO_TOWER']
    //iftrue ['BuenaPhoneScript_Rocket']
    //scall ['BuenaPhoneScript_CheckTimeOfDayCaller']
    //sjump ['BuenaPhoneScript_RandomCaller']

    return BuenaPhoneScript_CheckTimeOfDayCallee();
}

void BuenaPhoneScript_CheckTimeOfDayCallee(void){
    //checktime ['MORN']
    //iftrue ['.morn']
    //checktime ['DAY']
    //iftrue ['.day']
    //writetext ['BuenaPhoneNiteAnswerText']
    //promptbutton ['?']
    //end ['?']


morn:
    //writetext ['BuenaPhoneMorningAnswerText']
    //promptbutton ['?']
    //end ['?']


day:
    //writetext ['BuenaPhoneDayAnswerText']
    //promptbutton ['?']
    //end ['?']

    return BuenaPhoneScript_AfterMidnightCallee();
}

void BuenaPhoneScript_AfterMidnightCallee(void){
    //writetext ['BuenaPhoneMidnightAnswerText']
    //end ['?']

    return BuenaPhoneScript_CheckTimeOfDayCaller();
}

void BuenaPhoneScript_CheckTimeOfDayCaller(void){
    //readvar ['VAR_HOUR']
    //ifgreater ['17', 'BuenaPhoneScript_AfterMidnightCaller']
    //checktime ['MORN']
    //iftrue ['.morn']
    //checktime ['DAY']
    //iftrue ['.day']
    //writetext ['BuenaPhoneNiteText']
    //promptbutton ['?']
    //end ['?']


morn:
    //writetext ['BuenaPhoneMorningText']
    //promptbutton ['?']
    //end ['?']


day:
    //writetext ['BuenaPhoneDayText']
    //promptbutton ['?']
    //end ['?']

    return BuenaPhoneScript_AfterMidnightCaller();
}

void BuenaPhoneScript_AfterMidnightCaller(void){
    //writetext ['BuenaPhoneMidnightText']
    //promptbutton ['?']
    //end ['?']

    return BuenaPhoneScript_Rocket();
}

void BuenaPhoneScript_Rocket(void){
    //writetext ['BuenaPhoneRocketText']
    //end ['?']

    return BuenaPhoneScript_RandomCaller();
}

void BuenaPhoneScript_RandomCaller(void){
    //checkevent ['EVENT_BEAT_ELITE_FOUR']
    //iftrue ['.PostE4']
    //random ['11']
    //sjump ['.Jumptable']


PostE4:
    //random ['14']


Jumptable:
    //ifequal ['0', '.zero']
    //ifequal ['1', '.one']
    //ifequal ['2', '.two']
    //ifequal ['3', '.three']
    //ifequal ['4', '.four']
    //ifequal ['5', '.five']
    //ifequal ['6', '.six']
    //ifequal ['7', '.seven']
    //ifequal ['8', '.eight']
    //ifequal ['9', '.nine']
    //ifequal ['10', '.ten']
    //ifequal ['11', '.eleven']
    //ifequal ['12', '.twelve']
    //ifequal ['13', '.thirteen']


zero:
    //writetext ['BuenaPhoneWentOutWithBenText']
    //sjump ['.finish']


one:
    //writetext ['BuenaPhoneReceptionistText']
    //sjump ['.finish']


two:
    //writetext ['BuenaPhoneLuckyNumberShowText']
    //sjump ['.finish']


three:
    //writetext ['BuenaPhoneStressedFromWorkText']
    //sjump ['.finish']


four:
    //writetext ['BuenaPhoneProfessorOakText']
    //sjump ['.finish']


five:
    //writetext ['BuenaPhoneGotAColdText']
    //sjump ['.finish']


six:
    //writetext ['BuenaPhoneRadioCardQuestionsText']
    //sjump ['.finish']


seven:
    //writetext ['BuenaPhonePikachuFanClubText']
    //sjump ['.finish']


eight:
    //writetext ['BuenaPhoneRadioTowerDirectorText']
    //sjump ['.finish']


nine:
    //writetext ['BuenaPhoneWhenDoYouRelaxText']
    //sjump ['.finish']


ten:
    //writetext ['BuenaPhoneStarterPokemonText']
    //sjump ['.finish']


eleven:
    //writetext ['BuenaPhoneCompanyVacationText']
    //sjump ['.finish']


twelve:
    //writetext ['BuenaPhoneBenAndFernText']
    //sjump ['.finish']


thirteen:
    //writetext ['BuenaPhoneGoingShoppingText']


finish:
    //end ['?']

    return BuenaPhoneScript_RandomCallee();
}

void BuenaPhoneScript_RandomCallee(void){
    //random ['3']
    //ifequal ['0', '.zero']
    //ifequal ['1', '.one']
    //ifequal ['2', '.two']


zero:
    //writetext ['BuenaPhoneFavoriteSlotMachineAnswerText']
    //end ['?']


one:
    //writetext ['BuenaPhonePokegearAnswerText']
    //end ['?']


two:
    //writetext ['BuenaPhoneCoopedUpInRadioTowerAnswerText']
    //end ['?']

// INCLUDE "data/phone/text/buena.asm"

}
