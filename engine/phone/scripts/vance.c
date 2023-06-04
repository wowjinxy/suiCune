#include "../constants.h"
#include "vance.h"

void VancePhoneCalleeScript(void){
    //gettrainername ['STRING_BUFFER_3', 'BIRD_KEEPER', 'VANCE1']
    //checkflag ['ENGINE_VANCE_READY_FOR_REMATCH']
    //iftrue ['.WantsBattle']
    //farscall ['PhoneScript_AnswerPhone_Male']
    //checkflag ['ENGINE_VANCE_WEDNESDAY_NIGHT']
    //iftrue ['.NotWednesday']
    //readvar ['VAR_WEEKDAY']
    //ifnotequal ['WEDNESDAY', '.NotWednesday']
    //checktime ['NITE']
    //iftrue ['VanceWednesdayNight']


NotWednesday:
    //farsjump ['VanceLookingForwardScript']


WantsBattle:
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_44']
    //farsjump ['VanceHurryHurryScript']

    return VancePhoneCallerScript();
}

void VancePhoneCallerScript(void){
    //gettrainername ['STRING_BUFFER_3', 'BIRD_KEEPER', 'VANCE1']
    //farscall ['PhoneScript_GreetPhone_Male']
    //checkflag ['ENGINE_VANCE_READY_FOR_REMATCH']
    //iftrue ['.WantsBattle']
    //checkflag ['ENGINE_VANCE_WEDNESDAY_NIGHT']
    //iftrue ['.WantsBattle']
    //farscall ['PhoneScript_Random3']
    //ifequal ['0', 'VanceWantsRematch']
    //ifequal ['1', 'VanceWantsRematch']


WantsBattle:
    //farsjump ['Phone_GenericCall_Male']

    return VanceWednesdayNight();
}

void VanceWednesdayNight(void){
    //setflag ['ENGINE_VANCE_WEDNESDAY_NIGHT']

    return VanceWantsRematch();
}

void VanceWantsRematch(void){
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_44']
    //setflag ['ENGINE_VANCE_READY_FOR_REMATCH']
    //farsjump ['PhoneScript_WantsToBattle_Male']

}