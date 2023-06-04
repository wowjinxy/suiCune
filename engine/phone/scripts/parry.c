#include "../constants.h"
#include "parry.h"

void ParryPhoneCalleeScript(void){
    //gettrainername ['STRING_BUFFER_3', 'HIKER', 'PARRY1']
    //checkflag ['ENGINE_PARRY_READY_FOR_REMATCH']
    //iftrue ['.WantsBattle']
    //farscall ['PhoneScript_AnswerPhone_Male']
    //checkflag ['ENGINE_PARRY_FRIDAY_AFTERNOON']
    //iftrue ['.WantsRematch']
    //readvar ['VAR_WEEKDAY']
    //ifnotequal ['FRIDAY', '.WantsRematch']
    //checktime ['DAY']
    //iftrue ['ParryFridayDay']


WantsRematch:
    //farsjump ['ParryBattleWithMeScript']


WantsBattle:
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_45']
    //farsjump ['ParryHaventYouGottenToScript']

    return ParryPhoneCallerScript();
}

void ParryPhoneCallerScript(void){
    //gettrainername ['STRING_BUFFER_3', 'HIKER', 'PARRY1']
    //farscall ['PhoneScript_GreetPhone_Male']
    //checkflag ['ENGINE_PARRY_READY_FOR_REMATCH']
    //iftrue ['.GenericCall']
    //checkflag ['ENGINE_PARRY_FRIDAY_AFTERNOON']
    //iftrue ['.GenericCall']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', 'ParryWantsBattle']
    //ifequal ['1', 'ParryWantsBattle']


GenericCall:
    //farsjump ['Phone_GenericCall_Male']

    return ParryFridayDay();
}

void ParryFridayDay(void){
    //setflag ['ENGINE_PARRY_FRIDAY_AFTERNOON']

    return ParryWantsBattle();
}

void ParryWantsBattle(void){
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_45']
    //setflag ['ENGINE_PARRY_READY_FOR_REMATCH']
    //farsjump ['PhoneScript_WantsToBattle_Male']

}
