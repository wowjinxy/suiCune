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

//  Compare c bytes at de and hl.
//  Return z if they all match.
bool CompareBytes_Conv(uint16_t de, uint16_t hl, uint8_t c){
    do {
        if(gb_read(de) != gb_read(hl)) 
            return false;
        de++, hl++;
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

//  Compare bc bytes at de and hl.
//  Return true if they all match.
bool CompareBytesLong_Conv(uint16_t de, uint16_t hl, uint16_t bc){
    do {
        if(gb_read(de) != gb_read(hl)) 
            return false;
        de++, hl++;
    } while(--bc != 0);
    return true;
}