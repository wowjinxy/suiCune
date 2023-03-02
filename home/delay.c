#include "../constants.h"
#include "delay.h"
#include "vblank.h"

void DelayFrame_Old(void){
    //  Wait for one frame
    LD_A(1);
    LD_addr_A(wVBlankOccurred);

//  Wait for the next VBlank, halting to conserve battery

halt:
        //halt ['']  // rgbasm adds a nop after this instruction by default
    LD_A_addr(wVBlankOccurred);
    AND_A_A;
    IF_NZ goto halt;
    RET;

}

void DelayFrame(void){
    //  Wait for one frame
    gb_write(wVBlankOccurred, 1);
    do {
        gb_finish_frame();
        CALL(aVBlank);
    } while(gb_read(wVBlankOccurred) != 0);
    RET;
}

void DelayFrames(void){
    //  Wait c frames
    CALL(aDelayFrame);
    DEC_C;
    JR_NZ (mDelayFrames);
    RET;

}


void DelayFrames_Conv(uint8_t count) {
    for(uint8_t x = count; x > 0; --x)
    {
        //  Wait for one frame
        gb_write(wVBlankOccurred, 1);
        do {
            gb_finish_frame();
            VBlank();
        } while(gb_read(wVBlankOccurred) != 0);
    }
}