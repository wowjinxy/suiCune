#include "../constants.h"
#include "hangups.h"

void JackPhoneTipsScript(void){
    //farwritetext ['JackHeardSomeGreatTipsText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return BeverlyHangUpScript();
}

void BeverlyHangUpScript(void){
    //farwritetext ['BeverlyLetsChatAboutMonAgainText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return HueyHangUpScript();
}

void HueyHangUpScript(void){
    //farwritetext ['HueyWeHaveToBattleAgainSometimeText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return GavenHangUpNotThursdayScript();
}

void GavenHangUpNotThursdayScript(void){
    //farwritetext ['GavenHangUpNotThursdayText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return BethHangUpScript();
}

void BethHangUpScript(void){
    //farwritetext ['BethLetsBattleAgainSometimeText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return JoseHangUpScript();
}

void JoseHangUpScript(void){
    //farwritetext ['JoseHaventGottenItemYetText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return ReenaForwardScript();
}

void ReenaForwardScript(void){
    //farwritetext ['ReenaForwardText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return JoeyHangUpScript();
}

void JoeyHangUpScript(void){
    //farwritetext ['JoeyDevisingStrategiesText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return WadeNoBerriesScript();
}

void WadeNoBerriesScript(void){
    //farwritetext ['WadeNoBerriesText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return RalphNoItemScript();
}

void RalphNoItemScript(void){
    //farwritetext ['RalphNoItemText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return LizHangUpScript();
}

void LizHangUpScript(void){
    //farwritetext ['LizFawningOverMonText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return AnthonyHangUpScript();
}

void AnthonyHangUpScript(void){
    //farwritetext ['AnthonyWasntPayingAttentionText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return ToddNoItemScript();
}

void ToddNoItemScript(void){
    //farwritetext ['ToddSavingUpForBargainSaleText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return GinaHangUpScript();
}

void GinaHangUpScript(void){
    //farwritetext ['GinaHaventFoundAnythingYetText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return ArnieHangUpScript();
}

void ArnieHangUpScript(void){
    //farwritetext ['ArnieHaventSeenRareMonText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return AlanHangUpScript();
}

void AlanHangUpScript(void){
    //farwritetext ['AlanHaventPickedUpAnythingText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return DanaHangUpScript();
}

void DanaHangUpScript(void){
    //farwritetext ['DanaCanYouWaitABitLongerText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return ChadHangUpScript();
}

void ChadHangUpScript(void){
    //farwritetext ['ChadGoingToStudyHardText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return DerekHangUpScript();
}

void DerekHangUpScript(void){
    //farwritetext ['DerekLetsGetTogetherText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return TullyNoItemScript();
}

void TullyNoItemScript(void){
    //farwritetext ['TullyNoItemText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return BrentHangUpScript();
}

void BrentHangUpScript(void){
    //farwritetext ['BrentSorryImTooBusyText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return TiffanyNoItemScript();
}

void TiffanyNoItemScript(void){
    //farwritetext ['TiffanyNoItemText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return VanceLookingForwardScript();
}

void VanceLookingForwardScript(void){
    //farwritetext ['VanceLookingForwardText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return WiltonHaventFoundAnythingScript();
}

void WiltonHaventFoundAnythingScript(void){
    //farwritetext ['WiltonHaventFoundAnythingText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return ParryBattleWithMeScript();
}

void ParryBattleWithMeScript(void){
    //farwritetext ['ParryBattleWithMeText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return ErinWorkingHardScript();
}

void ErinWorkingHardScript(void){
    //farwritetext ['ErinWorkingHardText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return IrwinRandomTextScript();
}

void IrwinRandomTextScript(void){
    //random ['3']
    //ifequal ['0', 'IrwinEscapadeScript']
    //ifequal ['1', 'IrwinGoodMatchScript']
    //ifequal ['2', 'IrwinSoMuchToChatAboutScript']

    return IrwinEscapadeScript();
}

void IrwinEscapadeScript(void){
    //farwritetext ['IrwinYourEscapadesRockText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return IrwinGoodMatchScript();
}

void IrwinGoodMatchScript(void){
    //farwritetext ['IrwinGoodMatchText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return IrwinSoMuchToChatAboutScript();
}

void IrwinSoMuchToChatAboutScript(void){
    //farwritetext ['IrwinSoMuchToChatAboutText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return KenjiAnswerPhoneScript();
}

void KenjiAnswerPhoneScript(void){
    //readvar ['VAR_KENJI_BREAK']
    //ifequal ['2', '.Training']
    //ifequal ['1', '.OnBreak']
    //farwritetext ['KenjiCallMeBackAnotherTimeText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']


Training:
    //farwritetext ['KenjiIllHaveTimeToChatTomorrowText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']


OnBreak:
    //checktime ['MORN']
    //iftrue ['.Morning']
    //checktime ['NITE']
    //iftrue ['.Night']
    //setevent ['EVENT_KENJI_ON_BREAK']
    //farwritetext ['KenjiTakingABreakText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']


Morning:
    //farwritetext ['KenjiHangUpMorningText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']


Night:
    //farwritetext ['KenjiHangUpNightText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

}
