#include "../constants.h"
#include "kenji.h"

void KenjiPhoneCalleeScript(void){
    //gettrainername ['STRING_BUFFER_3', 'BLACKBELT_T', 'KENJI3']
    //farscall ['PhoneScript_AnswerPhone_Male']
    //farsjump ['KenjiAnswerPhoneScript']

    return KenjiPhoneCallerScript();
}

void KenjiPhoneCallerScript(void){
    //gettrainername ['STRING_BUFFER_3', 'BLACKBELT_T', 'KENJI3']
    //farscall ['PhoneScript_GreetPhone_Male']
    //farsjump ['KenjiCallingPhoneScript']

}
