#include "../constants.h"
#include "copy.h"

void CopyBytes(void){
    //  copy bc bytes from hl to de
    INC_B;  // we bail the moment b hits 0, so include the last run
    INC_C;  // same thing// include last byte
    goto HandleLoop;

CopyByte:
        LD_A_hli;
    LD_de_A;
    INC_DE;

HandleLoop:
        DEC_C;
    IF_NZ goto CopyByte;
    DEC_B;
    IF_NZ goto CopyByte;
    RET;

}

void CopyBytes_Conv(void){
    //  copy bc bytes from hl to de
    REG_B++;  // we bail the moment b hits 0, so include the last run
    REG_C++;  // same thing// include last byte

    while(--REG_C != 0 || --REG_B != 0)
    {
        REG_A = gb_read(REG_HL++);
        gb_write(REG_DE++, REG_A);
    }
    return;
}

void SwapBytes(void){
    //  swap bc bytes between hl and de

Loop:
    // stash [hl] away on the stack
    LD_A_hl;
    PUSH_AF;

// copy a byte from [de] to [hl]
    LD_A_de;
    LD_hli_A;

// retrieve the previous value of [hl]// put it in [de]
    POP_AF;
    LD_de_A;
    INC_DE;

// handle loop stuff
    DEC_BC;
    LD_A_B;
    OR_A_C;
    IF_NZ goto Loop;
    RET;

}

void SwapBytes_Conv(void){
    //  swap bc bytes between hl and de
    // Input
    //   hl: buffer a
    //   de: buffer b
    //   bc: byte count

    do {
        // stash [hl] away on the stack
        uint8_t temp = gb_read(REG_HL);

        // copy a byte from [de] to [hl]
        gb_write(REG_HL++, gb_read(REG_DE));

        // retrieve the previous value of [hl]// put it in [de]
        gb_write(REG_DE++, temp);

        // handle loop stuff
    } while(--REG_BC != 0);
}

void ByteFill(void){
    //  fill bc bytes with the value of a, starting at hl
    INC_B;  // we bail the moment b hits 0, so include the last run
    INC_C;  // same thing// include last byte
    goto HandleLoop;

PutByte:
        LD_hli_A;

HandleLoop:
        DEC_C;
    IF_NZ goto PutByte;
    DEC_B;
    IF_NZ goto PutByte;
    RET;

}

void ByteFill_Conv(void){
    //  fill bc bytes with the value of a, starting at hl
    REG_B++;  // we bail the moment b hits 0, so include the last run
    REG_C++;  // same thing// include last byte

    while(--REG_C != 0 || --REG_B != 0)
    {
        gb_write(REG_HL++, REG_A);
    }
    return;
}

void GetFarByte(void){
    //  retrieve a single byte from a:hl, and return it in a.
// bankswitch to new bank
    LDH_addr_A(hTempBank);
    LDH_A_addr(hROMBank);
    PUSH_AF;
    LDH_A_addr(hTempBank);
    RST(aBankswitch);

// get byte from new bank
    LD_A_hl;
    LDH_addr_A(hFarByte);

// bankswitch to previous bank
    POP_AF;
    RST(aBankswitch);

// return retrieved value in a
    LDH_A_addr(hFarByte);
    RET;

}

void GetFarByte_Conv(void){
    //  retrieve a single byte from a:hl, and return it in a.
    // bankswitch to new bank
    uint8_t temp = gb_read(hROMBank);
    RST(aBankswitch);

    // get byte from new bank
    uint8_t farbyte = gb_read(REG_HL);

    // bankswitch to previous bank
    REG_A = temp;
    RST(aBankswitch);

    // return retrieved value in a
    REG_A = farbyte;
}

void GetFarWord(void){
    //  retrieve a word from a:hl, and return it in hl.
// bankswitch to new bank
    LDH_addr_A(hTempBank);
    LDH_A_addr(hROMBank);
    PUSH_AF;
    LDH_A_addr(hTempBank);
    RST(aBankswitch);

// get word from new bank, put it in hl
    LD_A_hli;
    LD_H_hl;
    LD_L_A;

// bankswitch to previous bank and return
    POP_AF;
    RST(aBankswitch);
    RET;

}

void FarCopyWRAM(void){
        LDH_addr_A(hTempBank);
    LDH_A_addr(rSVBK);
    PUSH_AF;
    LDH_A_addr(hTempBank);
    LDH_addr_A(rSVBK);

    CALL(aCopyBytes);

    POP_AF;
    LDH_addr_A(rSVBK);
    RET;

}

void GetFarWRAMByte(void){
        LDH_addr_A(hTempBank);
    LDH_A_addr(rSVBK);
    PUSH_AF;
    LDH_A_addr(hTempBank);
    LDH_addr_A(rSVBK);
    LD_A_hl;
    LDH_addr_A(hFarByte);
    POP_AF;
    LDH_addr_A(rSVBK);
    LDH_A_addr(hFarByte);
    RET;

}

void GetFarWRAMWord(void){
    //  //  unreferenced
    LDH_addr_A(hTempBank);
    LDH_A_addr(rSVBK);
    PUSH_AF;
    LDH_A_addr(hTempBank);
    LDH_addr_A(rSVBK);
    LD_A_hli;
    LD_H_hl;
    LD_L_A;
    POP_AF;
    LDH_addr_A(rSVBK);
    RET;

}
