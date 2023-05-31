#include "../constants.h"
#include "sram.h"

void OpenSRAM(void){
//  if invalid bank, sram is disabled
    CP_A(NUM_SRAM_BANKS);
    IF_C goto valid;
/*
#if _DEBUG
    PUSH_AF;
    PUSH_BC;
    LD_B(1);

loop:
    SLA_B;
    DEC_A;
    IF_NZ goto loop;
    LD_A(BANK(sOpenedInvalidSRAM));
    CALL(aOpenSRAM);
    LD_A_addr(sOpenedInvalidSRAM);
    OR_A_B;
    LD_addr_A(sOpenedInvalidSRAM);
    POP_BC;
    POP_AF;
#endif
*/
    JR(mCloseSRAM);


valid:
//  switch to sram bank a
    PUSH_AF;
//  latch clock data
    LD_A(1);
    LD_addr_A(MBC3LatchClock);
//  enable sram/clock write
    LD_A(SRAM_ENABLE);
    LD_addr_A(MBC3SRamEnable);
//  select sram bank
    POP_AF;
    LD_addr_A(MBC3SRamBank);
    RET;

}

void CloseSRAM(void){
    PUSH_AF;
    LD_A(SRAM_DISABLE);
//  reset clock latch for next time
    LD_addr_A(MBC3LatchClock);
//  disable sram/clock write
    LD_addr_A(MBC3SRamEnable);
    POP_AF;
    RET;

}
