#include "../constants.h"
#include "array.h"

void IsInArray(void){
    //  Find value a for every de bytes in array hl.
//  Return index in b and carry if found.

    LD_B(0);
    LD_C_A;

loop:
        LD_A_hl;
    CP_A(-1);
    IF_Z goto NotInArray;
    CP_A_C;
    IF_Z goto InArray;
    INC_B;
    ADD_HL_DE;
    goto loop;


NotInArray:
        AND_A_A;
    RET;


InArray:
        SCF;
    RET;

}

void IsInArray_Conv(void)
{
    REG_B = 0;
    REG_C = REG_A;
    while(1)
    {
        REG_A = gb_read(REG_HL);
        if(REG_A == 0xFF)
        {
            AND_A_A;
            return;
        }
        if(REG_A == REG_C)
        {
            SCF;
            return;
        }
        REG_B++;
        REG_HL += REG_DE;
    }
}

void SkipNames(void){
    //  Skip a names.
    LD_BC(NAME_LENGTH);
    AND_A_A;
    RET_Z ;

loop:
        ADD_HL_BC;
    DEC_A;
    IF_NZ goto loop;
    RET;

}

void SkipNames_Conv(void)
{
    REG_BC = NAME_LENGTH;
    if(REG_A == 0) return;
    do {
        REG_HL += REG_BC;
        REG_A--;
    } while(REG_A != 0);
    return;
}

void AddNTimes(void){
    //  Add bc * a to hl.
    AND_A_A;
    RET_Z ;

loop:
        ADD_HL_BC;
    DEC_A;
    IF_NZ goto loop;
    RET;

}

void AddNTimes_Conv(void)
{
    if(REG_A == 0) return;
    do {
        REG_HL += REG_BC;
        REG_A--;
    } while(REG_A != 0);
}