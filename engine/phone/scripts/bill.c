#include "../constants.h"
#include "bill.h"

void BillPhoneCalleeScript(void){
    //checktime ['DAY']
    //iftrue ['.daygreet']
    //checktime ['NITE']
    //iftrue ['.nitegreet']
    //farwritetext ['BillPhoneMornGreetingText']
    //promptbutton ['?']
    //sjump ['.main']


daygreet:
    //farwritetext ['BillPhoneDayGreetingText']
    //promptbutton ['?']
    //sjump ['.main']


nitegreet:
    //farwritetext ['BillPhoneNiteGreetingText']
    //promptbutton ['?']
    //sjump ['.main']


main:
    //farwritetext ['BillPhoneGenericText']
    //promptbutton ['?']
    //readvar ['VAR_BOXSPACE']
    //getnum ['STRING_BUFFER_3']
    //ifequal ['0', '.full']
    //ifless ['PARTY_LENGTH', '.nearlyfull']
    //farwritetext ['BillPhoneNotFullText']
    //end ['?']


nearlyfull:
    //farwritetext ['BillPhoneNearlyFullText']
    //end ['?']


full:
    //farwritetext ['BillPhoneFullText']
    //end ['?']

    return BillPhoneCallerScript();
}

void BillPhoneCallerScript(void){
    //farwritetext ['BillPhoneNewlyFullText']
    //waitbutton ['?']
    //end ['?']

}
