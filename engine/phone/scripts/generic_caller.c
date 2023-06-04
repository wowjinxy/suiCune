#include "../constants.h"
#include "generic_caller.h"

void Phone_GenericCall_Male(void){
    //special ['RandomPhoneMon']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', '.Bragging']
    //farscall ['PhoneScript_Generic_Male']
    //farsjump ['Phone_FoundAMon_Male']


Bragging:
    //farsjump ['Phone_BraggingCall_Male']

    return Phone_GenericCall_Female();
}

void Phone_GenericCall_Female(void){
    //special ['RandomPhoneMon']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', '.Bragging']
    //farscall ['PhoneScript_Generic_Female']
    //farsjump ['Phone_FoundAMon_Female']


Bragging:
    //farsjump ['Phone_BraggingCall_Female']

    return Phone_BraggingCall_Male();
}

void Phone_BraggingCall_Male(void){
    //farscall ['Phone_WhosBragging_Male']
    //farsjump ['Phone_FoundAMon_Male']

    return Phone_BraggingCall_Female();
}

void Phone_BraggingCall_Female(void){
    //farscall ['Phone_WhosBragging_Female']
    //farsjump ['Phone_FoundAMon_Female']

    return Phone_FoundAMon_Male();
}

void Phone_FoundAMon_Male(void){
    //special ['RandomPhoneWildMon']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', '.GotAway']
    //farscall ['Phone_WhoDefeatedMon_Male']
    //farsjump ['PhoneScript_HangUpText_Male']


GotAway:
    //farsjump ['Phone_GotAwayCall_Male']

    return Phone_FoundAMon_Female();
}

void Phone_FoundAMon_Female(void){
    //special ['RandomPhoneWildMon']
    //farscall ['PhoneScript_Random2']
    //ifequal ['0', '.GotAway']
    //farscall ['Phone_WhoDefeatedMon_Female']
    //farsjump ['PhoneScript_HangUpText_Female']


GotAway:
    //farsjump ['Phone_GotAwayCall_Female']

    return Phone_GotAwayCall_Male();
}

void Phone_GotAwayCall_Male(void){
    //farscall ['Phone_WhoLostAMon_Male']
    //farsjump ['PhoneScript_HangUpText_Male']

    return Phone_GotAwayCall_Female();
}

void Phone_GotAwayCall_Female(void){
    //farscall ['Phone_WhoLostAMon_Female']
    //farsjump ['PhoneScript_HangUpText_Female']

    return Phone_WhosBragging_Male();
}

void Phone_WhosBragging_Male(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_SCHOOLBOY_JACK', '.Jack']
    //ifequal ['PHONE_COOLTRAINERM_GAVEN', '.Gaven']
    //ifequal ['PHONE_BIRDKEEPER_JOSE', '.Jose']
    //ifequal ['PHONE_YOUNGSTER_JOEY', '.Joey']
    //ifequal ['PHONE_BUG_CATCHER_WADE', '.Wade']
    //ifequal ['PHONE_FISHER_RALPH', '.Ralph']
    //ifequal ['PHONE_HIKER_ANTHONY', '.Anthony']
    //ifequal ['PHONE_CAMPER_TODD', '.Todd']
    //ifequal ['PHONE_BUG_CATCHER_ARNIE', '.Arnie']
    //ifequal ['PHONE_SCHOOLBOY_ALAN', '.Alan']
    //ifequal ['PHONE_SCHOOLBOY_CHAD', '.Chad']
    //ifequal ['PHONE_POKEFANM_DEREK', '.Derek']
    //ifequal ['PHONE_FISHER_TULLY', '.Tully']
    //ifequal ['PHONE_POKEMANIAC_BRENT', '.Brent']
    //ifequal ['PHONE_BIRDKEEPER_VANCE', '.Vance']
    //ifequal ['PHONE_FISHER_WILTON', '.Wilton']
    //ifequal ['PHONE_HIKER_PARRY', '.Parry']


Jack:
    //farwritetext ['JackIntelligenceKeepsRisingText']
    //promptbutton ['?']
    //end ['?']


Gaven:
    //farwritetext ['GavenMonGreaterThanImaginedText']
    //promptbutton ['?']
    //end ['?']


Jose:
    //farwritetext ['JoseMonsStickHasADeliciousAromaText']
    //promptbutton ['?']
    //end ['?']


Joey:
    //farwritetext ['JoeyMonLookingSharperText']
    //promptbutton ['?']
    //end ['?']


Wade:
    //farwritetext ['WadeAreYourMonGrowingText']
    //promptbutton ['?']
    //end ['?']


Ralph:
    //farwritetext ['RalphNeglectingKidsText']
    //promptbutton ['?']
    //end ['?']


Anthony:
    //farwritetext ['AnthonyMonAteSomeBerriesText']
    //promptbutton ['?']
    //end ['?']


Todd:
    //farwritetext ['ToddLooksCuteLikeMeText']
    //promptbutton ['?']
    //end ['?']


Arnie:
    //farwritetext ['ArnieMonIsSoCuteText']
    //promptbutton ['?']
    //end ['?']


Alan:
    //farwritetext ['AlanGettingStrongerText']
    //promptbutton ['?']
    //end ['?']


Chad:
    //farwritetext ['ChadObservingWildText']
    //promptbutton ['?']
    //end ['?']


Derek:
    //farwritetext ['DerekCheekPinchingText']
    //promptbutton ['?']
    //end ['?']


Tully:
    //farwritetext ['TullyMonHasGrownText']
    //promptbutton ['?']
    //end ['?']


Brent:
    //farwritetext ['BrentRareTradeText']
    //promptbutton ['?']
    //end ['?']


Vance:
    //farwritetext ['VanceMonHasBecomeTougherText']
    //promptbutton ['?']
    //end ['?']


Wilton:
    //farwritetext ['WiltonMonHasGrownText']
    //promptbutton ['?']
    //end ['?']


Parry:
    //farwritetext ['ParryNothingCanMatchText']
    //promptbutton ['?']
    //end ['?']

    return Phone_WhosBragging_Female();
}

void Phone_WhosBragging_Female(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_POKEFAN_BEVERLY', '.Beverly']
    //ifequal ['PHONE_COOLTRAINERF_BETH', '.Beth']
    //ifequal ['PHONE_COOLTRAINERF_REENA', '.Reena']
    //ifequal ['PHONE_PICNICKER_LIZ', '.Liz']
    //ifequal ['PHONE_PICNICKER_GINA', '.Gina']
    //ifequal ['PHONE_LASS_DANA', '.Dana']
    //ifequal ['PHONE_PICNICKER_TIFFANY', '.Tiffany']
    //ifequal ['PHONE_PICNICKER_ERIN', '.Erin']


Beverly:
    //farwritetext ['BeverlyMadeMonEvenCuterText']
    //promptbutton ['?']
    //end ['?']


Beth:
    //farwritetext ['BethExhilaratingRideText']
    //promptbutton ['?']
    //end ['?']


Reena:
    //farwritetext ['ReenaMonsIsAPerfectMatchText']
    //promptbutton ['?']
    //end ['?']


Liz:
    //farwritetext ['LizMonAlwaysWantsToNuzzleText']
    //promptbutton ['?']
    //end ['?']


Gina:
    //farwritetext ['GinaGettingInSyncWithMonText']
    //promptbutton ['?']
    //end ['?']


Dana:
    //farwritetext ['DanaTakingPhotosText']
    //promptbutton ['?']
    //end ['?']


Tiffany:
    //farwritetext ['TiffanyMonIsAdorableText']
    //promptbutton ['?']
    //end ['?']


Erin:
    //farwritetext ['ErinMonIsMuchStrongerText']
    //promptbutton ['?']
    //end ['?']

    return Phone_WhoDefeatedMon_Male();
}

void Phone_WhoDefeatedMon_Male(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_SCHOOLBOY_JACK', '.Jack']
    //ifequal ['PHONE_COOLTRAINERM_GAVEN', '.Gaven']
    //ifequal ['PHONE_BIRDKEEPER_JOSE', '.Jose']
    //ifequal ['PHONE_YOUNGSTER_JOEY', '.Joey']
    //ifequal ['PHONE_BUG_CATCHER_WADE', '.Wade']
    //ifequal ['PHONE_FISHER_RALPH', '.Ralph']
    //ifequal ['PHONE_HIKER_ANTHONY', '.Anthony']
    //ifequal ['PHONE_CAMPER_TODD', '.Todd']
    //ifequal ['PHONE_BUG_CATCHER_ARNIE', '.Arnie']
    //ifequal ['PHONE_SCHOOLBOY_ALAN', '.Alan']
    //ifequal ['PHONE_SCHOOLBOY_CHAD', '.Chad']
    //ifequal ['PHONE_POKEFANM_DEREK', '.Derek']
    //ifequal ['PHONE_FISHER_TULLY', '.Tully']
    //ifequal ['PHONE_POKEMANIAC_BRENT', '.Brent']
    //ifequal ['PHONE_BIRDKEEPER_VANCE', '.Vance']
    //ifequal ['PHONE_FISHER_WILTON', '.Wilton']
    //ifequal ['PHONE_HIKER_PARRY', '.Parry']


Jack:
    //farwritetext ['JackDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Gaven:
    //farwritetext ['GavenDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Jose:
    //farwritetext ['JoseDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Joey:
    //farwritetext ['JoeyDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Wade:
    //farwritetext ['WadeDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Ralph:
    //farwritetext ['RalphDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Anthony:
    //farwritetext ['AnthonyDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Todd:
    //farwritetext ['ToddDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Arnie:
    //farwritetext ['ArnieDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Alan:
    //farwritetext ['AlanDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Chad:
    //farwritetext ['ChadDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Derek:
    //farwritetext ['DerekDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Tully:
    //farwritetext ['TullyDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Brent:
    //farwritetext ['BrentDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Vance:
    //farwritetext ['VanceDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Wilton:
    //farwritetext ['WiltonDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Parry:
    //farwritetext ['ParryDefeatedMonText']
    //promptbutton ['?']
    //end ['?']

    return Phone_WhoDefeatedMon_Female();
}

void Phone_WhoDefeatedMon_Female(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_POKEFAN_BEVERLY', '.Beverly']
    //ifequal ['PHONE_COOLTRAINERF_BETH', '.Beth']
    //ifequal ['PHONE_COOLTRAINERF_REENA', '.Reena']
    //ifequal ['PHONE_PICNICKER_LIZ', '.Liz']
    //ifequal ['PHONE_PICNICKER_GINA', '.Gina']
    //ifequal ['PHONE_LASS_DANA', '.Dana']
    //ifequal ['PHONE_PICNICKER_TIFFANY', '.Tiffany']
    //ifequal ['PHONE_PICNICKER_ERIN', '.Erin']


Beverly:
    //farwritetext ['BeverlyDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Beth:
    //farwritetext ['BethDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Reena:
    //farwritetext ['ReenaDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Liz:
    //farwritetext ['LizDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Gina:
    //farwritetext ['GinaDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Dana:
    //farwritetext ['DanaDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Tiffany:
    //farwritetext ['TiffanyDefeatedMonText']
    //promptbutton ['?']
    //end ['?']


Erin:
    //farwritetext ['ErinDefeatedMonText']
    //promptbutton ['?']
    //end ['?']

    return Phone_WhoLostAMon_Male();
}

void Phone_WhoLostAMon_Male(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_SCHOOLBOY_JACK', '.Jack']
    //ifequal ['PHONE_COOLTRAINERM_GAVEN', '.Gaven']
    //ifequal ['PHONE_BIRDKEEPER_JOSE', '.Jose']
    //ifequal ['PHONE_YOUNGSTER_JOEY', '.Joey']
    //ifequal ['PHONE_BUG_CATCHER_WADE', '.Wade']
    //ifequal ['PHONE_FISHER_RALPH', '.Ralph']
    //ifequal ['PHONE_HIKER_ANTHONY', '.Anthony']
    //ifequal ['PHONE_CAMPER_TODD', '.Todd']
    //ifequal ['PHONE_BUG_CATCHER_ARNIE', '.Arnie']
    //ifequal ['PHONE_SCHOOLBOY_ALAN', '.Alan']
    //ifequal ['PHONE_SCHOOLBOY_CHAD', '.Chad']
    //ifequal ['PHONE_POKEFANM_DEREK', '.Derek']
    //ifequal ['PHONE_FISHER_TULLY', '.Tully']
    //ifequal ['PHONE_POKEMANIAC_BRENT', '.Brent']
    //ifequal ['PHONE_BIRDKEEPER_VANCE', '.Vance']
    //ifequal ['PHONE_FISHER_WILTON', '.Wilton']
    //ifequal ['PHONE_HIKER_PARRY', '.Parry']


Jack:
    //farwritetext ['JackLostAMonText']
    //promptbutton ['?']
    //end ['?']


Gaven:
    //farwritetext ['GavenLostAMonText']
    //promptbutton ['?']
    //end ['?']


Jose:
    //farwritetext ['JoseLostAMonText']
    //promptbutton ['?']
    //end ['?']


Joey:
    //farwritetext ['JoeyLostAMonText']
    //promptbutton ['?']
    //end ['?']


Wade:
    //farwritetext ['WadeLostAMonText']
    //promptbutton ['?']
    //end ['?']


Ralph:
    //farwritetext ['RalphLostAMonText']
    //promptbutton ['?']
    //end ['?']


Anthony:
    //farwritetext ['AnthonyLostAMonText']
    //promptbutton ['?']
    //end ['?']


Todd:
    //farwritetext ['ToddLostAMonText']
    //promptbutton ['?']
    //end ['?']


Arnie:
    //farwritetext ['ArnieLostAMonText']
    //promptbutton ['?']
    //end ['?']


Alan:
    //farwritetext ['AlanLostAMonText']
    //promptbutton ['?']
    //end ['?']


Chad:
    //farwritetext ['ChadLostAMonText']
    //promptbutton ['?']
    //end ['?']


Derek:
    //farwritetext ['DerekLostAMonText']
    //promptbutton ['?']
    //end ['?']


Tully:
    //farwritetext ['TullyLostAMonText']
    //promptbutton ['?']
    //end ['?']


Brent:
    //farwritetext ['BrentLostAMonText']
    //promptbutton ['?']
    //end ['?']


Vance:
    //farwritetext ['VanceLostAMonText']
    //promptbutton ['?']
    //end ['?']


Wilton:
    //farwritetext ['WiltonLostAMonText']
    //promptbutton ['?']
    //end ['?']


Parry:
    //farwritetext ['ParryLostAMonText']
    //promptbutton ['?']
    //end ['?']

    return Phone_WhoLostAMon_Female();
}

void Phone_WhoLostAMon_Female(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_POKEFAN_BEVERLY', '.Beverly']
    //ifequal ['PHONE_COOLTRAINERF_BETH', '.Beth']
    //ifequal ['PHONE_COOLTRAINERF_REENA', '.Reena']
    //ifequal ['PHONE_PICNICKER_LIZ', '.Liz']
    //ifequal ['PHONE_PICNICKER_GINA', '.Gina']
    //ifequal ['PHONE_LASS_DANA', '.Dana']
    //ifequal ['PHONE_PICNICKER_TIFFANY', '.Tiffany']
    //ifequal ['PHONE_PICNICKER_ERIN', '.Erin']


Beverly:
    //farwritetext ['BeverlyLostAMonText']
    //promptbutton ['?']
    //end ['?']


Beth:
    //farwritetext ['BethLostAMonText']
    //promptbutton ['?']
    //end ['?']


Reena:
    //farwritetext ['ReenaLostAMonText']
    //promptbutton ['?']
    //end ['?']


Liz:
    //farwritetext ['LizLostAMonText']
    //promptbutton ['?']
    //end ['?']


Gina:
    //farwritetext ['GinaLostAMonText']
    //promptbutton ['?']
    //end ['?']


Dana:
    //farwritetext ['DanaLostAMonText']
    //promptbutton ['?']
    //end ['?']


Tiffany:
    //farwritetext ['TiffanyLostAMonText']
    //promptbutton ['?']
    //end ['?']


Erin:
    //farwritetext ['ErinLostAMonText']
    //promptbutton ['?']
    //end ['?']

    return PhoneScript_WantsToBattle_Male();
}

void PhoneScript_WantsToBattle_Male(void){
    //farscall ['PhoneScript_RematchText_Male']
    //farsjump ['PhoneScript_HangUpText_Male']

    return PhoneScript_WantsToBattle_Female();
}

void PhoneScript_WantsToBattle_Female(void){
    //farscall ['PhoneScript_RematchText_Female']
    //farsjump ['PhoneScript_HangUpText_Female']

    return PhoneScript_RematchText_Male();
}

void PhoneScript_RematchText_Male(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_SCHOOLBOY_JACK', '.Jack']
    //ifequal ['PHONE_SAILOR_HUEY', '.Huey']
    //ifequal ['PHONE_COOLTRAINERM_GAVEN', '.Gaven']
    //ifequal ['PHONE_BIRDKEEPER_JOSE', '.Jose']
    //ifequal ['PHONE_YOUNGSTER_JOEY', '.Joey']
    //ifequal ['PHONE_BUG_CATCHER_WADE', '.Wade']
    //ifequal ['PHONE_FISHER_RALPH', '.Ralph']
    //ifequal ['PHONE_HIKER_ANTHONY', '.Anthony']
    //ifequal ['PHONE_CAMPER_TODD', '.Todd']
    //ifequal ['PHONE_BUG_CATCHER_ARNIE', '.Arnie']
    //ifequal ['PHONE_SCHOOLBOY_ALAN', '.Alan']
    //ifequal ['PHONE_SCHOOLBOY_CHAD', '.Chad']
    //ifequal ['PHONE_FISHER_TULLY', '.Tully']
    //ifequal ['PHONE_POKEMANIAC_BRENT', '.Brent']
    //ifequal ['PHONE_BIRDKEEPER_VANCE', '.Vance']
    //ifequal ['PHONE_FISHER_WILTON', '.Wilton']
    //ifequal ['PHONE_HIKER_PARRY', '.Parry']


Jack:
    //farwritetext ['JackBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Huey:
    //farwritetext ['HueyBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Gaven:
    //farwritetext ['GavenBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Jose:
    //farwritetext ['JoseBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Joey:
    //farwritetext ['JoeyBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Wade:
    //farwritetext ['WadeBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Ralph:
    //farwritetext ['RalphBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Anthony:
    //farwritetext ['AnthonyBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Todd:
    //farwritetext ['ToddBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Arnie:
    //farwritetext ['ArnieBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Alan:
    //farwritetext ['AlanBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Chad:
    //farwritetext ['ChadBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Tully:
    //farwritetext ['TullyBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Brent:
    //farwritetext ['BrentBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Vance:
    //farwritetext ['VanceBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Wilton:
    //farwritetext ['WiltonBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Parry:
    //farwritetext ['ParryBattleRematchText']
    //promptbutton ['?']
    //end ['?']

    return PhoneScript_RematchText_Female();
}

void PhoneScript_RematchText_Female(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_COOLTRAINERF_BETH', '.Beth']
    //ifequal ['PHONE_COOLTRAINERF_REENA', '.Reena']
    //ifequal ['PHONE_PICNICKER_LIZ', '.Liz']
    //ifequal ['PHONE_PICNICKER_GINA', '.Gina']
    //ifequal ['PHONE_LASS_DANA', '.Dana']
    //ifequal ['PHONE_PICNICKER_TIFFANY', '.Tiffany']
    //ifequal ['PHONE_PICNICKER_ERIN', '.Erin']


Beth:
    //farwritetext ['BethBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Reena:
    //farwritetext ['ReenaBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Liz:
    //farwritetext ['LizBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Gina:
    //farwritetext ['GinaBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Dana:
    //farwritetext ['DanaBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Tiffany:
    //farwritetext ['TiffanyBattleRematchText']
    //promptbutton ['?']
    //end ['?']


Erin:
    //farwritetext ['ErinBattleRematchText']
    //promptbutton ['?']
    //end ['?']

    return LizWrongNumberScript();
}

void LizWrongNumberScript(void){
    //farwritetext ['LizWrongNumberText']
    //end ['?']

    return TiffanyItsAwful();
}

void TiffanyItsAwful(void){
    //farwritetext ['TiffanyItsAwfulText']
    //end ['?']

    return PhoneScript_HangUpText_Male();
}

void PhoneScript_HangUpText_Male(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_SCHOOLBOY_JACK', '.Jack']
    //ifequal ['PHONE_SAILOR_HUEY', '.Huey']
    //ifequal ['PHONE_COOLTRAINERM_GAVEN', '.Gaven']
    //ifequal ['PHONE_BIRDKEEPER_JOSE', '.Jose']
    //ifequal ['PHONE_YOUNGSTER_JOEY', '.Joey']
    //ifequal ['PHONE_BUG_CATCHER_WADE', '.Wade']
    //ifequal ['PHONE_FISHER_RALPH', '.Ralph']
    //ifequal ['PHONE_HIKER_ANTHONY', '.Anthony']
    //ifequal ['PHONE_CAMPER_TODD', '.Todd']
    //ifequal ['PHONE_JUGGLER_IRWIN', '.Irwin']
    //ifequal ['PHONE_BUG_CATCHER_ARNIE', '.Arnie']
    //ifequal ['PHONE_SCHOOLBOY_ALAN', '.Alan']
    //ifequal ['PHONE_SCHOOLBOY_CHAD', '.Chad']
    //ifequal ['PHONE_POKEFANM_DEREK', '.Derek']
    //ifequal ['PHONE_FISHER_TULLY', '.Tully']
    //ifequal ['PHONE_POKEMANIAC_BRENT', '.Brent']
    //ifequal ['PHONE_BIRDKEEPER_VANCE', '.Vance']
    //ifequal ['PHONE_FISHER_WILTON', '.Wilton']
    //ifequal ['PHONE_BLACKBELT_KENJI', '.Kenji']
    //ifequal ['PHONE_HIKER_PARRY', '.Parry']


Jack:
    //farwritetext ['JackHangUpText']
    //end ['?']


Huey:
    //farwritetext ['HueyHangUpText']
    //end ['?']


Gaven:
    //farwritetext ['GavenHangUpText']
    //end ['?']


Jose:
    //farwritetext ['JoseHangUpText']
    //end ['?']


Joey:
    //farwritetext ['JoeyHangUpText']
    //end ['?']


Wade:
    //farwritetext ['WadeHangUpText']
    //end ['?']


Ralph:
    //farwritetext ['RalphHangUpText']
    //end ['?']


Anthony:
    //farwritetext ['AnthonyHangUpText']
    //end ['?']


Todd:
    //farwritetext ['ToddHangUpText']
    //end ['?']


Irwin:
    //farwritetext ['IrwinHangUpText']
    //end ['?']


Arnie:
    //farwritetext ['ArnieHangUpText']
    //end ['?']


Alan:
    //farwritetext ['AlanHangUpText']
    //end ['?']


Chad:
    //farwritetext ['ChadHangUpText']
    //end ['?']


Derek:
    //farwritetext ['DerekHangUpText']
    //end ['?']


Tully:
    //farwritetext ['TullyHangUpText']
    //end ['?']


Brent:
    //farwritetext ['BrentHangUpText']
    //end ['?']


Vance:
    //farwritetext ['VanceHangUpText']
    //end ['?']


Wilton:
    //farwritetext ['WiltonHangUpText']
    //end ['?']


Kenji:
    //farwritetext ['KenjiHangUpText']
    //end ['?']


Parry:
    //farwritetext ['ParryHangUpText']
    //end ['?']

    return PhoneScript_HangUpText_Female();
}

void PhoneScript_HangUpText_Female(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_POKEFAN_BEVERLY', '.Beverly']
    //ifequal ['PHONE_COOLTRAINERF_BETH', '.Beth']
    //ifequal ['PHONE_COOLTRAINERF_REENA', '.Reena']
    //ifequal ['PHONE_PICNICKER_LIZ', '.Liz']
    //ifequal ['PHONE_PICNICKER_GINA', '.Gina']
    //ifequal ['PHONE_LASS_DANA', '.Dana']
    //ifequal ['PHONE_PICNICKER_TIFFANY', '.Tiffany']
    //ifequal ['PHONE_PICNICKER_ERIN', '.Erin']


Beverly:
    //farwritetext ['BeverlyHangUpText']
    //end ['?']


Beth:
    //farwritetext ['BethHangUpText']
    //end ['?']


Reena:
    //farwritetext ['ReenaHangUpText']
    //end ['?']


Liz:
    //farwritetext ['LizHangUpText']
    //end ['?']


Gina:
    //farwritetext ['GinaHangUpText']
    //end ['?']


Dana:
    //farwritetext ['DanaHangUpText']
    //end ['?']


Tiffany:
    //farwritetext ['TiffanyHangUpText']
    //end ['?']


Erin:
    //farwritetext ['ErinHangUpText']
    //end ['?']

    return Phone_CheckIfUnseenRare_Male();
}

void Phone_CheckIfUnseenRare_Male(void){
    //scall ['PhoneScriptRareWildMon']
    //iffalse ['.HangUp']
    //farsjump ['Phone_GenericCall_Male']


HangUp:
    //farsjump ['PhoneScript_HangUpText_Male']

    return Phone_CheckIfUnseenRare_Female();
}

void Phone_CheckIfUnseenRare_Female(void){
    //scall ['PhoneScriptRareWildMon']
    //iffalse ['.HangUp']
    //farsjump ['Phone_GenericCall_Female']


HangUp:
    //farsjump ['PhoneScript_HangUpText_Female']

    return PhoneScriptRareWildMon();
}

void PhoneScriptRareWildMon(void){
    //special ['RandomUnseenWildMon']
    //end ['?']

    return PhoneScript_BugCatchingContest();
}

void PhoneScript_BugCatchingContest(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_BUG_CATCHER_WADE', '.Wade']
    //ifequal ['PHONE_POKEFANM_DEREK', '.Derek']


Wade:
    //farwritetext ['WadeBugCatchingContestText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']


Derek:
    //farwritetext ['DerekBugCatchingContestText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return IrwinRocketRumorScript();
}

void IrwinRocketRumorScript(void){
    //farwritetext ['IrwinRocketTakeoverRumorText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return GinaRocketRumorScript();
}

void GinaRocketRumorScript(void){
    //farwritetext ['GinaRocketTakeoverRumorText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Female']

    return ArnieSwarmScript();
}

void ArnieSwarmScript(void){
    //farwritetext ['ArnieSwarmText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return RalphItemScript();
}

void RalphItemScript(void){
    //farwritetext ['RalphItemText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return AnthonySwarmScript();
}

void AnthonySwarmScript(void){
    //farwritetext ['AnthonySwarmText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return PhoneScript_FoundItem_Male();
}

void PhoneScript_FoundItem_Male(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_BIRDKEEPER_JOSE', '.Jose']
    //ifequal ['PHONE_BUG_CATCHER_WADE', '.Wade']
    //ifequal ['PHONE_SCHOOLBOY_ALAN', '.Alan']
    //ifequal ['PHONE_POKEFANM_DEREK', '.Derek']
    //ifequal ['PHONE_FISHER_TULLY', '.Tully']
    //ifequal ['PHONE_FISHER_WILTON', '.Wilton']


Jose:
    //farwritetext ['JoseFoundItemText']
    //end ['?']


Wade:
    //farwritetext ['WadeFoundItemText']
    //end ['?']


Alan:
    //farwritetext ['AlanFoundItemText']
    //end ['?']


Derek:
    //farwritetext ['DerekFoundItemText']
    //end ['?']


Tully:
    //farwritetext ['TullyFoundItemText']
    //end ['?']


Wilton:
    //farwritetext ['WiltonFoundItemText']
    //end ['?']

    return PhoneScript_FoundItem_Female();
}

void PhoneScript_FoundItem_Female(void){
    //readvar ['VAR_CALLERID']
    //ifequal ['PHONE_POKEFAN_BEVERLY', '.Beverly']
    //ifequal ['PHONE_PICNICKER_GINA', '.Gina']
    //ifequal ['PHONE_LASS_DANA', '.Dana']
    //ifequal ['PHONE_PICNICKER_TIFFANY', '.Tiffany']


Beverly:
    //farwritetext ['BeverlyFoundItemText']
    //end ['?']


Gina:
    //farwritetext ['GinaFoundItemText']
    //end ['?']


Dana:
    //farwritetext ['DanaFoundItemText']
    //end ['?']


Tiffany:
    //farwritetext ['TiffanyFoundItemText']
    //end ['?']

    return ToddItemScript();
}

void ToddItemScript(void){
    //farwritetext ['ToddDepartmentStoreBargainSaleText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

    return KenjiCallingPhoneScript();
}

void KenjiCallingPhoneScript(void){
    //farwritetext ['KenjiRemainDedicatedText']
    //promptbutton ['?']
    //sjump ['PhoneScript_HangUpText_Male']

}
