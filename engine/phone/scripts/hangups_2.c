#include "../constants.h"
#include "hangups_2.h"

void BeverlyComePickUpScript(void){
    //farwritetext ['BeverlyComePickUpText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return JoseComePickUpScript();
}

void JoseComePickUpScript(void){
//  //  unreferenced
    //farwritetext ['JoseComePickUpText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return WadeComeQuickScript();
}

void WadeComeQuickScript(void){
    //farwritetext ['WadeComeQuickText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return GinaComePickUpScript();
}

void GinaComePickUpScript(void){
    //farwritetext ['GinaComePickUpText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return AlanComePickUpScript();
}

void AlanComePickUpScript(void){
    //farwritetext ['AlanComePickUpGiftText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return DanaComePickUpScript();
}

void DanaComePickUpScript(void){
    //farwritetext ['DanaComePickUpText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return DerekComePickUpScript();
}

void DerekComePickUpScript(void){
    //farwritetext ['DerekComePickUpText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return TullyHurryScript();
}

void TullyHurryScript(void){
    //farwritetext ['TullyHurryText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return TiffanyHurryScript();
}

void TiffanyHurryScript(void){
    //farwritetext ['TiffanyHurryText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return WiltonWantThisScript();
}

void WiltonWantThisScript(void){
    //farwritetext ['WiltonWantThisText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

}
