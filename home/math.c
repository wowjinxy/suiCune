#include "../constants.h"
#include "math.h"

void SimpleMultiply(void){
    //  Return a * c.
    AND_A_A;
    RET_Z ;

    PUSH_BC;
    LD_B_A;
    XOR_A_A;

loop:
        ADD_A_C;
    DEC_B;
    IF_NZ goto loop;
    POP_BC;
    RET;

}

void SimpleMultiply_Conv(void)
{
    uint16_t temp = REG_BC;
    if(REG_A == 0) return;
    REG_B = REG_A;
    REG_A = 0;

    do {
        REG_A += REG_C;
        REG_B--;
    } while(REG_B != 0);

    REG_BC = temp;
}

void SimpleDivide(void){
    //  Divide a by c. Return quotient b and remainder a.
    LD_B(0);

loop:
        INC_B;
    SUB_A_C;
    IF_NC goto loop;
    DEC_B;
    ADD_A_C;
    RET;

}

void SimpleDivide_Conv(void)
{
    REG_B = 0;
    uint8_t cont = 1;
    do {
        REG_B++;
        if(REG_A < REG_C)
        {
            cont = 0;
        }
        REG_A -= REG_C;
    } while(cont);
    REG_B--;
    REG_A += REG_C;
}

void Multiply(void){
    //  Multiply hMultiplicand (3 bytes) by hMultiplier. Result in hProduct.
//  All values are big endian.
    PUSH_HL;
    PUSH_BC;

    CALLFAR(av_Multiply);

    POP_BC;
    POP_HL;
    RET;

}

void Divide(void){
    //  Divide hDividend length b (max 4 bytes) by hDivisor. Result in hQuotient.
//  All values are big endian.
    PUSH_HL;
    PUSH_DE;
    PUSH_BC;
    HOMECALL(av_Divide);
    POP_BC;
    POP_DE;
    POP_HL;
    RET;

}

void SubtractAbsolute(void){
    //  //  unreferenced
//  Return |a - b|, sign in carry.
    SUB_A_B;
    RET_NC ;
    CPL;
    ADD_A(1);
    SCF;
    RET;

}
