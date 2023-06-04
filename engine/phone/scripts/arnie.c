#include "../constants.h"
#include "arnie.h"

void ArniePhoneCalleeScript(void){
    //gettrainername ['STRING_BUFFER_3', 'BUG_CATCHER', 'ARNIE1']
    //checkflag ['ENGINE_ARNIE_READY_FOR_REMATCH']
    //iftrue ['.WantsBattle']
    //farscall ['PhoneScript_AnswerPhone_Male']
    //checkflag ['ENGINE_ARNIE_TUESDAY_MORNING']
    //iftrue ['.NotTuesday']
    //readvar ['VAR_WEEKDAY']
    //ifnotequal ['TUESDAY', '.NotTuesday']
    //checktime ['MORN']
    //iftrue ['ArnieTuesdayMorning']


NotTuesday:
    //checkflag ['ENGINE_YANMA_SWARM']
    //iftrue ['.AlreadySwarming']
    //farsjump ['ArnieHangUpScript']


WantsBattle:
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_35']
    //farsjump ['ArnieReminderScript']


AlreadySwarming:
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_35']
    //farsjump ['ArnieHurryScript']

    return ArniePhoneCallerScript();
}

void ArniePhoneCallerScript(void){
    //gettrainername ['STRING_BUFFER_3', 'BUG_CATCHER', 'ARNIE1']
    //farscall ['PhoneScript_GreetPhone_Male']
    //checkflag ['ENGINE_ARNIE_READY_FOR_REMATCH']
    //iftrue ['.Swarm']
    //checkflag ['ENGINE_ARNIE_TUESDAY_MORNING']
    //iftrue ['.Swarm']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', 'ArnieWantsBattle']


Swarm:
    //farscall ['PhoneScript_Random5']
    //ifequal ['0', 'ArnieYanmaSwarm']
    //farscall ['PhoneScript_Random3']
    //ifequal ['0', 'ArnieFoundRare']
    //farsjump ['Phone_GenericCall_Male']

    return ArnieTuesdayMorning();
}

void ArnieTuesdayMorning(void){
    //setflag ['ENGINE_ARNIE_TUESDAY_MORNING']

    return ArnieWantsBattle();
}

void ArnieWantsBattle(void){
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_35']
    //setflag ['ENGINE_ARNIE_READY_FOR_REMATCH']
    //farsjump ['PhoneScript_WantsToBattle_Male']

    return ArnieYanmaSwarm();
}

void ArnieYanmaSwarm(void){
//  //  start swarm
    //checkflag ['ENGINE_YANMA_SWARM']
    //iftrue ['ArnieYanmaAlreadySwarming']
    //setflag ['ENGINE_YANMA_SWARM']
    //getmonname ['STRING_BUFFER_4', 'YANMA']
    //swarm ['SWARM_YANMA', 'ROUTE_35']
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_35']
    //farsjump ['ArnieSwarmScript']

    return ArnieFoundRare();
}

void ArnieFoundRare(void){
    //farsjump ['Phone_CheckIfUnseenRare_Male']

    return ArnieYanmaAlreadySwarming();
}

void ArnieYanmaAlreadySwarming(void){
    //farsjump ['Phone_GenericCall_Male']

}
