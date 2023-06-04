#include "../constants.h"
#include "mom.h"

void MomPhoneCalleeScript(void){
    //checkevent ['EVENT_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST']
    //iftrue ['.started_quest']
    //checkevent ['EVENT_DUDE_TALKED_TO_YOU']
    //iftrue ['MomPhoneLectureScript']
    //checkevent ['EVENT_GAVE_MYSTERY_EGG_TO_ELM']
    //iftrue ['MomPhoneNoGymQuestScript']
    //checkevent ['EVENT_GOT_A_POKEMON_FROM_ELM']
    //iftrue ['MomPhoneNoPokedexScript']
    //sjump ['MomPhoneNoPokemonScript']


started_quest:
    //checkevent ['EVENT_TEMPORARY_UNTIL_MAP_RELOAD_8']
    //iftrue ['MomPhoneHangUpScript']
    //farwritetext ['MomPhoneGreetingText']
    //promptbutton ['?']
    //getcurlandmarkname ['STRING_BUFFER_3']
    //readvar ['VAR_ENVIRONMENT']
    //ifequal ['TOWN', 'MomPhoneInTown']
    //ifequal ['ROUTE', 'MomPhoneOnRoute']
    //sjump ['MomPhoneOther']

    return MomPhoneLandmark();
}

void MomPhoneLandmark(void){
    //farwritetext ['MomPhoneLandmarkText']
    //promptbutton ['?']
    //sjump ['MomSavingMoney']

    return MomPhoneInTown();
}

void MomPhoneInTown(void){
    //readvar ['VAR_MAPGROUP']
    //ifequal ['GROUP_NEW_BARK_TOWN', '.newbark']
    //ifequal ['GROUP_CHERRYGROVE_CITY', '.cherrygrove']
    //ifequal ['GROUP_VIOLET_CITY', '.violet']
    //ifequal ['GROUP_AZALEA_TOWN', '.azalea']
    //ifequal ['GROUP_GOLDENROD_CITY', '.goldenrod']
    //farwritetext ['MomPhoneGenericAreaText']
    //promptbutton ['?']
    //sjump ['MomSavingMoney']


newbark:
    //farwritetext ['MomPhoneNewBarkText']
    //promptbutton ['?']
    //sjump ['MomSavingMoney']


cherrygrove:
    //farwritetext ['MomPhoneCherrygroveText']
    //promptbutton ['?']
    //sjump ['MomSavingMoney']


violet:
    //getlandmarkname ['STRING_BUFFER_4', 'LANDMARK_SPROUT_TOWER']
    //sjump ['MomPhoneLandmark']

azalea:
    //getlandmarkname ['STRING_BUFFER_4', 'LANDMARK_SLOWPOKE_WELL']
    //sjump ['MomPhoneLandmark']

goldenrod:
    //getlandmarkname ['STRING_BUFFER_4', 'LANDMARK_RADIO_TOWER']
    //sjump ['MomPhoneLandmark']

    return MomPhoneOnRoute();
}

void MomPhoneOnRoute(void){
    //farwritetext ['MomOtherAreaText']
    //promptbutton ['?']
    //sjump ['MomSavingMoney']

    return MomPhoneOther();
}

void MomPhoneOther(void){
    //farwritetext ['MomDeterminedText']
    //promptbutton ['?']
    //sjump ['MomSavingMoney']

    return MomSavingMoney();
}

void MomSavingMoney(void){
    //checkflag ['ENGINE_MOM_SAVING_MONEY']
    //iffalse ['.NotSaving']
    //checkmoney ['MOMS_MONEY', '0']
    //ifequal ['HAVE_MORE', '.SavingHasMoney']
    //sjump ['.SavingNoMoney']


NotSaving:
    //checkmoney ['MOMS_MONEY', '0']
    //ifequal ['HAVE_MORE', '.HasMoney']
    //sjump ['.NoMoney']


SavingHasMoney:
    //getmoney ['STRING_BUFFER_3', 'MOMS_MONEY']
    //farwritetext ['MomCheckBalanceText']
    //yesorno ['?']
    //iftrue ['MomPhoneSaveMoneyScript']
    //sjump ['MomPhoneWontSaveMoneyScript']


SavingNoMoney:
    //farwritetext ['MomImportantToSaveText']
    //yesorno ['?']
    //iftrue ['MomPhoneSaveMoneyScript']
    //sjump ['MomPhoneWontSaveMoneyScript']


NoMoney:
    //farwritetext ['MomYoureNotSavingText']
    //yesorno ['?']
    //iftrue ['MomPhoneSaveMoneyScript']
    //sjump ['MomPhoneWontSaveMoneyScript']


HasMoney:
    //getmoney ['STRING_BUFFER_3', 'MOMS_MONEY']
    //farwritetext ['MomYouveSavedText']
    //yesorno ['?']
    //iftrue ['MomPhoneSaveMoneyScript']
    //sjump ['MomPhoneWontSaveMoneyScript']

    return MomPhoneSaveMoneyScript();
}

void MomPhoneSaveMoneyScript(void){
    //setflag ['ENGINE_MOM_SAVING_MONEY']
    //farwritetext ['MomOKIllSaveText']
    //promptbutton ['?']
    //sjump ['MomPhoneHangUpScript']

    return MomPhoneWontSaveMoneyScript();
}

void MomPhoneWontSaveMoneyScript(void){
    //clearflag ['ENGINE_MOM_SAVING_MONEY']
    //farwritetext ['MomPhoneWontSaveMoneyText']
    //promptbutton ['?']
    //sjump ['MomPhoneHangUpScript']

    return MomPhoneHangUpScript();
}

void MomPhoneHangUpScript(void){
    //farwritetext ['MomPhoneHangUpText']
    //end ['?']

    return MomPhoneNoPokemonScript();
}

void MomPhoneNoPokemonScript(void){
    //farwritetext ['MomPhoneNoPokemonText']
    //end ['?']

    return MomPhoneNoPokedexScript();
}

void MomPhoneNoPokedexScript(void){
    //farwritetext ['MomPhoneNoPokedexText']
    //end ['?']

    return MomPhoneNoGymQuestScript();
}

void MomPhoneNoGymQuestScript(void){
    //farwritetext ['MomPhoneNoGymQuestText']
    //end ['?']

    return MomPhoneLectureScript();
}

void MomPhoneLectureScript(void){
    //setevent ['EVENT_TALKED_TO_MOM_AFTER_MYSTERY_EGG_QUEST']
    //setflag ['ENGINE_MOM_ACTIVE']
    //specialphonecall ['SPECIALCALL_NONE']
    //farwritetext ['MomPhoneLectureText']
    //yesorno ['?']
    //iftrue ['MomPhoneSaveMoneyScript']
    //sjump ['MomPhoneWontSaveMoneyScript']

}
