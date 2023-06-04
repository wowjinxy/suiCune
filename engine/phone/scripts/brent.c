#include "../constants.h"
#include "brent.h"

void BrentPhoneCalleeScript(void){
    //gettrainername ['STRING_BUFFER_3', 'POKEMANIAC', 'BRENT1']
    //checkflag ['ENGINE_BRENT_READY_FOR_REMATCH']
    //iftrue ['.WantsBattle']
    //farscall ['PhoneScript_AnswerPhone_Male']
    //checkflag ['ENGINE_BRENT_MONDAY_MORNING']
    //iftrue ['.NotMonday']
    //readvar ['VAR_WEEKDAY']
    //ifnotequal ['MONDAY', '.NotMonday']
    //checktime ['MORN']
    //iftrue ['BrentMondayMorning']


NotMonday:
    //farsjump ['BrentHangUpScript']


WantsBattle:
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_43']
    //farsjump ['BrentReminderScript']

    return BrentPhoneCallerScript();
}

void BrentPhoneCallerScript(void){
    //gettrainername ['STRING_BUFFER_3', 'POKEMANIAC', 'BRENT1']
    //farscall ['PhoneScript_GreetPhone_Male']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', 'BrentBillTrivia']
    //checkflag ['ENGINE_BRENT_READY_FOR_REMATCH']
    //iftrue ['.Generic']
    //checkflag ['ENGINE_BRENT_MONDAY_MORNING']
    //iftrue ['.Generic']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', 'BrentWantsBattle']


Generic:
    //farsjump ['Phone_GenericCall_Male']

    return BrentMondayMorning();
}

void BrentMondayMorning(void){
    //setflag ['ENGINE_BRENT_MONDAY_MORNING']

    return BrentWantsBattle();
}

void BrentWantsBattle(void){
    //getlandmarkname ['STRING_BUFFER_5', 'LANDMARK_ROUTE_43']
    //setflag ['ENGINE_BRENT_READY_FOR_REMATCH']
    //farsjump ['PhoneScript_WantsToBattle_Male']

    return BrentBillTrivia();
}

void BrentBillTrivia(void){
    //farsjump ['BrentBillTriviaScript']

}
