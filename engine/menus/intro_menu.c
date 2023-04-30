#include "../../constants.h"
#include "intro_menu.h"

void Intro_MainMenu() {
    PlayMusic(MUSIC_NONE);
    CALL(aDelayFrame);
    LD_A_E;
    LD_addr_A(wMapMusic);
    PlayMusic(MUSIC_MAIN_MENU);
    FARCALL(aMainMenu);
    CALL(aStartTitleScreen);
}
