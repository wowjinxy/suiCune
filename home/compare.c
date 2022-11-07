#include "../constants.h"
#include "compare.h"

void CompareBytes(void){
    //  Compare c bytes at de and hl.
//  Return z if they all match.

loop:
        LD_A_de;
    CP_A_hl;
    RET_NZ ;
    INC_DE;
    INC_HL;
    DEC_C;
    IF_NZ goto loop;
    RET;

}

bool CompareBytes_Conv(uint16_t de, uint16_t hl, uint8_t c){
    //  Compare c bytes at de and hl.
//  Return z if they all match.

    do {
        if(gb_read(de) != gb_read(hl))
        {
            return false;
        }
        de++;
        hl++;
    } while(--c != 0);
    return true;
}

void CompareBytesLong(void){
    //  Compare bc bytes at de and hl.
//  Return carry if they all match.

loop:
        LD_A_de;
    CP_A_hl;
    IF_NZ goto diff;

    INC_DE;
    INC_HL;
    DEC_BC;

    LD_A_B;
    OR_A_C;
    IF_NZ goto loop;

    SCF;
    RET;


diff:
        AND_A_A;
    RET;

}

void CompareBytesLong_Conv(void){
    //  Compare bc bytes at de and hl.
//  Return carry if they all match.

    do {
        if(gb_read(REG_DE) != gb_read(REG_HL)) { 
            REG_F_C = 0;
            return;
        }

        REG_DE++;
        REG_HL++;
    } while(--REG_BC != 0);
    REG_F_C = 1;
}