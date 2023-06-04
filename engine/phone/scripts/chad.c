#include "../constants.h"
#include "chad.h"

void ChadPhoneCalleeScript(void){
    //gettrainername ['STRING_BUFFER_3', 'SCHOOLBOY', 'CHAD1']
    //checkflag ['ENGINE_CHAD_READY_FOR_REMATCH']
    //iftrue ['.WantsBattle']
    //farscall ['PhoneScript_AnswerPhone_Male']
    //checkflag ['ENGINE_CHAD_FRIDAY_MORNING']
    //iftrue ['.NotFriday']
    //readvar ['VAR_WEEKDAY']
    //ifnotequal ['FRIDAY', '.NotFriday']
    //checktime ['MORN']
    //iftrue ['ChadFridayMorning']


NotFriday:
    //farsjump ['ChadHangUpScript']


WantsBattle:
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_38']
    //farsjump ['ChadReminderScript']

    return ChadPhoneCallerScript();
}

void ChadPhoneCallerScript(void){
    //gettrainername ['STRING_BUFFER_3', 'SCHOOLBOY', 'CHAD1']
    //farscall ['PhoneScript_GreetPhone_Male']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', 'ChadOakGossip']
    //checkflag ['ENGINE_CHAD_READY_FOR_REMATCH']
    //iftrue ['.Generic']
    //checkflag ['ENGINE_CHAD_FRIDAY_MORNING']
    //iftrue ['.Generic']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', 'ChadWantsBattle']


Generic:
    //farscall ['PhoneScript_Random3']
    //ifequal ['0', 'ChadFoundRare']
    //farsjump ['Phone_GenericCall_Male']

    return ChadFridayMorning();
}

void ChadFridayMorning(void){
    //setflag ['ENGINE_CHAD_FRIDAY_MORNING']

    return ChadWantsBattle();
}

void ChadWantsBattle(void){
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_38']
    //setflag ['ENGINE_CHAD_READY_FOR_REMATCH']
    //farsjump ['PhoneScript_WantsToBattle_Male']

    return ChadFoundRare();
}

void ChadFoundRare(void){
    //farsjump ['Phone_CheckIfUnseenRare_Male']

    return ChadOakGossip();
}

void ChadOakGossip(void){
    //farsjump ['ChadOakGossipScript']

}
