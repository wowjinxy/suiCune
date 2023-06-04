#include "../constants/trainer_constants.h"
#include "../constants/map_constants.h"
#include "../engine/phone/scripts.h"

typedef enum {
    ANYTIME,
    NULL,
} CallTime;

typedef struct {
    int trainerClass;
    int trainerName;
    Map *map_id;
    CallTime calleeTime;
    void (*calleeScript)(void);
    CallTime callerTime;
    void (*callerScript)(void);
} PhoneContact;

PhoneContact PhoneContacts[] = {
    { TRAINER_NONE, PHONECONTACT_00, 		&N_A, 						 NULL, 		 UnusedPhoneScript, 		 NULL, 		 UnusedPhoneScript},
    { TRAINER_NONE, PHONECONTACT_MOM, 		&PLAYERS_HOUSE_1F, 			 ANYTIME, 	 MomPhoneCalleeScript, 		 NULL, 		 UnusedPhoneScript },
    { TRAINER_NONE, PHONECONTACT_BIKESHOP, 	&OAKS_LAB, 					 NULL, 		 UnusedPhoneScript, 		 NULL, 		 UnusedPhoneScript },
    { TRAINER_NONE, PHONECONTACT_BILL, 		&N_A, 						 ANYTIME, 	 BillPhoneCalleeScript, 	 NULL, 		 BillPhoneCallerScript },
    { TRAINER_NONE, PHONECONTACT_ELM, 		&ELMS_LAB, 					 ANYTIME, 	 ElmPhoneCalleeScript, 		 NULL, 		 ElmPhoneCallerScript },
	{ SCHOOLBOY,	JACK1,             		&NATIONAL_PARK,            	 ANYTIME,	 JackPhoneCalleeScript,   	 ANYTIME,	 JackPhoneCallerScript },
	{ POKEFANF,     BEVERLY1,               &NATIONAL_PARK,              ANYTIME,    BeverlyPhoneCalleeScript,   ANYTIME,    BeverlyPhoneCallerScript },
	{ SAILOR,       HUEY1,                  &OLIVINE_LIGHTHOUSE_2F,      ANYTIME,    HueyPhoneCalleeScript,      ANYTIME,    HueyPhoneCallerScript },
	{ TRAINER_NONE, PHONECONTACT_00,        &N_A,                        NULL,       UnusedPhoneScript,          NULL,       UnusedPhoneScript },
	{ TRAINER_NONE, PHONECONTACT_00,        &N_A,                        NULL,       UnusedPhoneScript,          NULL,       UnusedPhoneScript },
	{ TRAINER_NONE, PHONECONTACT_00,        &N_A,                        NULL,       UnusedPhoneScript,          NULL,       UnusedPhoneScript },
	{ COOLTRAINERM, GAVEN3,                 &ROUTE_26,                   ANYTIME,    GavenPhoneCalleeScript,     ANYTIME,    GavenPhoneCallerScript },
	{ COOLTRAINERF, BETH1,                  &ROUTE_26,                   ANYTIME,    BethPhoneCalleeScript,      ANYTIME,    BethPhoneCallerScript },
	{ BIRD_KEEPER,  JOSE2,                  &ROUTE_27,                   ANYTIME,    JosePhoneCalleeScript,      ANYTIME,    JosePhoneCallerScript },
	{ COOLTRAINERF, REENA1,                 &ROUTE_27,                   ANYTIME,    ReenaPhoneCalleeScript,     ANYTIME,    ReenaPhoneCallerScript },
	{ YOUNGSTER,    JOEY1,                  &ROUTE_30,                   ANYTIME,    JoeyPhoneCalleeScript,      ANYTIME,    JoeyPhoneCallerScript },
	{ BUG_CATCHER,  WADE1,                  &ROUTE_31,                   ANYTIME,    WadePhoneCalleeScript,      ANYTIME,    WadePhoneCallerScript },
	{ FISHER,       RALPH1,                 &ROUTE_32,                   ANYTIME,    RalphPhoneCalleeScript,     ANYTIME,    RalphPhoneCallerScript },
	{ PICNICKER,    LIZ1,                   &ROUTE_32,                   ANYTIME,    LizPhoneCalleeScript,       ANYTIME,    LizPhoneCallerScript },
	{ HIKER,        ANTHONY2,               &ROUTE_33,                   ANYTIME,    AnthonyPhoneCalleeScript,   ANYTIME,    AnthonyPhoneCallerScript },
	{ CAMPER,       TODD1,                  &ROUTE_34,                   ANYTIME,    ToddPhoneCalleeScript,      ANYTIME,    ToddPhoneCallerScript },
	{ PICNICKER,    GINA1,                  &ROUTE_34,                   ANYTIME,    GinaPhoneCalleeScript,      ANYTIME,    GinaPhoneCallerScript },
	{ JUGGLER,      IRWIN1,                 &ROUTE_35,                   ANYTIME,    IrwinPhoneCalleeScript,     ANYTIME,    IrwinPhoneCallerScript },
	{ BUG_CATCHER,  ARNIE1,                 &ROUTE_35,                   ANYTIME,    ArniePhoneCalleeScript,     ANYTIME,    ArniePhoneCallerScript },
	{ SCHOOLBOY,    ALAN1,                  &ROUTE_36,                   ANYTIME,    AlanPhoneCalleeScript,      ANYTIME,    AlanPhoneCallerScript },
	{ TRAINER_NONE, PHONECONTACT_00,        &N_A,                        NULL,       UnusedPhoneScript,          NULL,       UnusedPhoneScript },
	{ LASS,         DANA1,                  &ROUTE_38,                   ANYTIME,    DanaPhoneCalleeScript,      ANYTIME,    DanaPhoneCallerScript },
	{ SCHOOLBOY,    CHAD1,                  &ROUTE_38,                   ANYTIME,    ChadPhoneCalleeScript,      ANYTIME,    ChadPhoneCallerScript },
	{ POKEFANM,     DEREK1,                 &ROUTE_39,                   ANYTIME,    DerekPhoneCalleeScript,     ANYTIME,    DerekPhoneCallerScript },
	{ FISHER,       TULLY1,                 &ROUTE_42,                   ANYTIME,    TullyPhoneCalleeScript,     ANYTIME,    TullyPhoneCallerScript },
	{ POKEMANIAC,   BRENT1,                 &ROUTE_43,                   ANYTIME,    BrentPhoneCalleeScript,     ANYTIME,    BrentPhoneCallerScript },
	{ PICNICKER,    TIFFANY3,               &ROUTE_43,                   ANYTIME,    TiffanyPhoneCalleeScript,   ANYTIME,    TiffanyPhoneCallerScript },
	{ BIRD_KEEPER,  VANCE1,                 &ROUTE_44,                   ANYTIME,    VancePhoneCalleeScript,     ANYTIME,    VancePhoneCallerScript },
	{ FISHER,       WILTON1,                &ROUTE_44,                   ANYTIME,    WiltonPhoneCalleeScript,    ANYTIME,    WiltonPhoneCallerScript },
	{ BLACKBELT_T,  KENJI3,                 &ROUTE_45,                   ANYTIME,    KenjiPhoneCalleeScript,     ANYTIME,    KenjiPhoneCallerScript },
	{ HIKER,        PARRY1,                 &ROUTE_45,                   ANYTIME,    ParryPhoneCalleeScript,     ANYTIME,    ParryPhoneCallerScript },
	{ PICNICKER,    ERIN1,                  &ROUTE_46,                   ANYTIME,    ErinPhoneCalleeScript,      ANYTIME,    ErinPhoneCallerScript },
	{ TRAINER_NONE, PHONECONTACT_BUENA,     &GOLDENROD_DEPT_STORE_ROOF,  ANYTIME,    BuenaPhoneCalleeScript,     ANYTIME,    BuenaPhoneCallerScript },
};
