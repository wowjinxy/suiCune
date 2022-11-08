#include "../../constants.h"
#include "sliding_intro.h"

void BattleIntroSlidingPics(void){
    LDH_A_addr(rSVBK);
    PUSH_AF;
    LD_A(BANK(wLYOverrides));
    LDH_addr_A(rSVBK);
    CALL(aBattleIntroSlidingPics_subfunction1);
    LD_A(LOW(rSCX));
    LDH_addr_A(hLCDCPointer);
    CALL(aBattleIntroSlidingPics_subfunction2);
    XOR_A_A;
    LDH_addr_A(hLCDCPointer);
    POP_AF;
    LDH_addr_A(rSVBK);
    RET;


subfunction1:
    CALL(aBattleIntroSlidingPics_subfunction4);
    LD_A(0x90);
    LDH_addr_A(hSCX);
    LD_A(0b11100100);
    CALL(aDmgToCgbBGPals);
    LD_DE((0b11100100 << 8) | 0b11100100);
    CALL(aDmgToCgbObjPals);
    RET;


subfunction2:
    LD_D(0x90);
    LD_E(0x72);
    LD_A(0x48);
    INC_A;

loop1:
    PUSH_AF;

loop2:
    LDH_A_addr(rLY);
    CP_A(0x60);
    IF_C goto loop2;
    LD_A_D;
    LDH_addr_A(hSCX);
    CALL(aBattleIntroSlidingPics_subfunction5);
    INC_E;
    INC_E;
    DEC_D;
    DEC_D;
    POP_AF;
    PUSH_AF;
    CP_A(0x1);
    IF_Z goto skip1;
    PUSH_DE;
    CALL(aBattleIntroSlidingPics_subfunction3);
    POP_DE;


skip1:
    CALL(aDelayFrame);
    POP_AF;
    DEC_A;
    IF_NZ goto loop1;
    RET;


subfunction3:
    LD_HL(wVirtualOAMSprite00XCoord);
    LD_C(0x12);  // 18
    LD_DE(SPRITEOAMSTRUCT_LENGTH);

loop3:
    DEC_hl;
    DEC_hl;
    ADD_HL_DE;
    DEC_C;
    IF_NZ goto loop3;
    RET;


subfunction4:
    LD_HL(wLYOverrides);
    LD_A(0x90);
    LD_BC(SCREEN_HEIGHT_PX);
    CALL(aByteFill);
    RET;


subfunction5:
    LD_HL(wLYOverrides);
    LD_A_D;
    LD_C(0x3e);  // 62

loop4:
    LD_hli_A;
    DEC_C;
    IF_NZ goto loop4;
    LD_A_E;
    LD_C(0x22);  // 34

loop5:
    LD_hli_A;
    DEC_C;
    IF_NZ goto loop5;
    XOR_A_A;
    LD_C(0x30);  // 48

loop6:
    LD_hli_A;
    DEC_C;
    IF_NZ goto loop6;
    RET;

}
