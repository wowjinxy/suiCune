#include "../constants.h"
#include "wilton.h"

void WiltonPhoneCalleeScript(void){
    //gettrainername ['STRING_BUFFER_3', 'FISHER', 'WILTON1']
    //checkflag ['ENGINE_WILTON_READY_FOR_REMATCH']
    //iftrue ['.WantsBattle']
    //farscall ['PhoneScript_AnswerPhone_Male']
    //checkflag ['ENGINE_WILTON_THURSDAY_MORNING']
    //iftrue ['.NotThursday']
    //checkflag ['ENGINE_WILTON_HAS_ITEM']
    //iftrue ['.HasItem']
    //readvar ['VAR_WEEKDAY']
    //ifnotequal ['THURSDAY', '.NotThursday']
    //checktime ['MORN']
    //iftrue ['WiltonThursdayMorning']


NotThursday:
    //farsjump ['WiltonHaventFoundAnythingScript']


WantsBattle:
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_44']
    //farsjump ['WiltonNotBitingScript']


HasItem:
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_44']
    //farsjump ['WiltonWantThisScript']

    return WiltonPhoneCallerScript();
}

void WiltonPhoneCallerScript(void){
    //gettrainername ['STRING_BUFFER_3', 'FISHER', 'WILTON1']
    //farscall ['PhoneScript_GreetPhone_Male']
    //checkflag ['ENGINE_WILTON_READY_FOR_REMATCH']
    //iftrue ['.GenericCall']
    //checkflag ['ENGINE_WILTON_THURSDAY_MORNING']
    //iftrue ['.GenericCall']
    //checkflag ['ENGINE_WILTON_HAS_ITEM']
    //iftrue ['.GenericCall']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', 'WiltonWantsBattle']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', 'WiltonHasItem']


GenericCall:
    //farsjump ['Phone_GenericCall_Male']

    return WiltonThursdayMorning();
}

void WiltonThursdayMorning(void){
    //setflag ['ENGINE_WILTON_THURSDAY_MORNING']

    return WiltonWantsBattle();
}

void WiltonWantsBattle(void){
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_44']
    //setflag ['ENGINE_WILTON_READY_FOR_REMATCH']
    //farsjump ['PhoneScript_WantsToBattle_Male']

    return WiltonHasItem();
}

void WiltonHasItem(void){
    //setflag ['ENGINE_WILTON_HAS_ITEM']
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_44']
    //clearevent ['EVENT_WILTON_HAS_ULTRA_BALL']
    //clearevent ['EVENT_WILTON_HAS_GREAT_BALL']
    //clearevent ['EVENT_WILTON_HAS_POKE_BALL']
    //random ['5']
    //ifequal ['0', '.UltraBall']
    //random ['3']
    //ifequal ['0', '.GreatBall']
    //sjump ['.PokeBall']


UltraBall:
    //setevent ['EVENT_WILTON_HAS_ULTRA_BALL']
    //sjump ['.FoundItem']


GreatBall:
    //setevent ['EVENT_WILTON_HAS_GREAT_BALL']
    //sjump ['.FoundItem']


PokeBall:
    //setevent ['EVENT_WILTON_HAS_POKE_BALL']


FoundItem:
    //farsjump ['PhoneScript_FoundItem_Male']

}
