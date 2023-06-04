#pragma once

// PhoneContacts indexes (see data/phone/phone_contacts.asm)
enum {
    PHONE_00,
    PHONE_MOM,
    PHONE_OAK,
    PHONE_BILL,
    PHONE_ELM,
    PHONE_SCHOOLBOY_JACK,
    PHONE_POKEFAN_BEVERLY,
    PHONE_SAILOR_HUEY,
    PHONE_UNUSED_01,
    PHONE_UNUSED_02,
    PHONE_UNUSED_03,
    PHONE_COOLTRAINERM_GAVEN,
    PHONE_COOLTRAINERF_BETH,
    PHONE_BIRDKEEPER_JOSE,
    PHONE_COOLTRAINERF_REENA,
    PHONE_YOUNGSTER_JOEY,
    PHONE_BUG_CATCHER_WADE,
    PHONE_FISHER_RALPH,
    PHONE_PICNICKER_LIZ,
    PHONE_HIKER_ANTHONY,
    PHONE_CAMPER_TODD,
    PHONE_PICNICKER_GINA,
    PHONE_JUGGLER_IRWIN,
    PHONE_BUG_CATCHER_ARNIE,
    PHONE_SCHOOLBOY_ALAN,
    PHONE_UNUSED_04,
    PHONE_LASS_DANA,
    PHONE_SCHOOLBOY_CHAD,
    PHONE_POKEFANM_DEREK,
    PHONE_FISHER_TULLY,
    PHONE_POKEMANIAC_BRENT,
    PHONE_PICNICKER_TIFFANY,
    PHONE_BIRDKEEPER_VANCE,
    PHONE_FISHER_WILTON,
    PHONE_BLACKBELT_KENJI,
    PHONE_HIKER_PARRY,
    PHONE_PICNICKER_ERIN,
    PHONE_BUENA,
};
#define NUM_PHONE_CONTACTS PHONE_BUENA

// SpecialPhoneCallList indexes (see data/phone/special_calls.asm)
enum {
    SPECIALCALL_NONE,
    SPECIALCALL_POKERUS,
    SPECIALCALL_ROBBED,
    SPECIALCALL_ASSISTANT,
    SPECIALCALL_WEIRDBROADCAST,
    SPECIALCALL_SSTICKET,
    SPECIALCALL_BIKESHOP,
    SPECIALCALL_WORRIED,
    SPECIALCALL_MASTERBALL,
};
#define NUM_SPECIALCALLS SPECIALCALL_MASTERBALL
#define SPECIALCALL_SIZE 6

// phone struct members
enum {
    PHONE_CONTACT_TRAINER_CLASS,
    PHONE_CONTACT_TRAINER_NUMBER,
    PHONE_CONTACT_MAP_GROUP,
    PHONE_CONTACT_MAP_NUMBER,
    PHONE_CONTACT_SCRIPT1_TIME,
    PHONE_CONTACT_SCRIPT1_BANK,
    PHONE_CONTACT_SCRIPT1_ADDR,
    PHONE_CONTACT_SCRIPT2_TIME = PHONE_CONTACT_SCRIPT1_ADDR + 2,
    PHONE_CONTACT_SCRIPT2_BANK,
    PHONE_CONTACT_SCRIPT2_ADDR,
    PHONE_CONTACT_SIZE = PHONE_CONTACT_SCRIPT2_ADDR + 2,
};

// maximum number of pokegear contacts
#define CONTACT_LIST_SIZE 10
