#include "../../constants.h"

struct SpecialCall {
    bool (*condition)(void);
    uint8_t contact;
    const uint8_t* script;
};

bool SpecialCallOnlyWhenOutside(void);
bool SpecialCallWhereverYouAre(void);
extern const uint8_t ElmPhoneCallerScript[];
extern const uint8_t BikeShopPhoneCallerScript[];

const struct SpecialCall SpecialPhoneCallList[] = {
    [SPECIALCALL_NONE] = {SpecialCallOnlyWhenOutside, PHONECONTACT_ELM, ElmPhoneCallerScript},
};