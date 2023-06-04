#include "../constants.h"
#include "irwin.h"

void IrwinPhoneCalleeScript(void){
    //gettrainername ['STRING_BUFFER_3', 'JUGGLER', 'IRWIN1']
    //farscall ['PhoneScript_AnswerPhone_Male']
    //checkflag ['ENGINE_ROCKETS_IN_RADIO_TOWER']
    //iftrue ['.Rockets']
    //farsjump ['IrwinRandomTextScript']


Rockets:
    //farsjump ['IrwinRocketRumorScript']

    return IrwinPhoneCallerScript();
}

void IrwinPhoneCallerScript(void){
    //gettrainername ['STRING_BUFFER_3', 'JUGGLER', 'IRWIN1']
    //farscall ['PhoneScript_GreetPhone_Male']
    //checkflag ['ENGINE_ROCKETS_IN_RADIO_TOWER']
    //iftrue ['.Rockets']
    //farsjump ['IrwinRumorScript']


Rockets:
    //farsjump ['IrwinRocketRumorScript']

}
