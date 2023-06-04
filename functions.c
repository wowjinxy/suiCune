#include "functions.h"

#define ROM_SIZE 0x200000
void init_function_pointers(void) {
    for (int i = 0; i < ROM_SIZE; i++) redirectFunc[i] = convertedFunc[i] = NULL;

    // home/array.c
    REDIRECTED(AddNTimes);
    REDIRECTED(IsInArray);
    REDIRECTED(SkipNames);

    // home/audio.c
    REDIRECTED(MaxVolume);
    REDIRECTED(PlayMusic2);
    REDIRECTED(MinVolume);
    REDIRECTED(RestartMapMusic);
    REDIRECTED(IsSFXPlaying);
    REDIRECTED(UpdateSound);
    REDIRECTED(FadeOutToMusic);
    REDIRECTED(SpecialMapMusic);
    REDIRECTED(GetMapMusic_MaybeSpecial);
    REDIRECTED(WaitPlaySFX);
    REDIRECTED(PlaceBCDNumberSprite);
    REDIRECTED(LowVolume);
    REDIRECTED(PlaySFX);
    REDIRECTED(TerminateExpBarSound);
    REDIRECTED(InitSound);
    REDIRECTED(TryRestartMapMusic);
    REDIRECTED(FadeInToMusic);
    REDIRECTED(PlayMapMusicBike);
    REDIRECTED(WaitSFX);
    REDIRECTED(PlayMapMusic);
    REDIRECTED(PlayMusic);
    REDIRECTED(FadeToMapMusic);
    REDIRECTED(PlayCry);
    REDIRECTED(SkipMusic);
    REDIRECTED(CheckSFX);
    REDIRECTED(ChannelsOff);
    REDIRECTED(SFXChannelsOff);

    // home/battle.c
    REDIRECTED(UpdateBattleHuds);
    REDIRECTED(OpponentPartyAttr);
    REDIRECTED(UpdateOpponentInParty);
    REDIRECTED(GetPartyLocation);
    REDIRECTED(UserPartyAttr);
    REDIRECTED(SetPlayerTurn);
    REDIRECTED(PushLYOverrides);
    REDIRECTED(GetBattleAnimByte);
    REDIRECTED(RefreshBattleHuds);
    REDIRECTED(MobileTextBorder);
    REDIRECTED(OTPartyAttr);
    REDIRECTED(FarCopyRadioText);
    REDIRECTED(BattleTextbox);
    REDIRECTED(UpdateUserInParty);
    REDIRECTED(GetPartyParamLocation);
    REDIRECTED(BattlePartyAttr);
    REDIRECTED(UpdateBattleMonInParty);
    REDIRECTED(GetDexNumber);
    REDIRECTED(GetBattleAnimPointer);
    REDIRECTED(StdBattleTextbox);
    REDIRECTED(SetEnemyTurn);
    REDIRECTED(UpdateBattleMon);
    REDIRECTED(UpdateEnemyMonInParty);
    REDIRECTED(ResetDamage);

    // home/battle_vars.c
    // REDIRECTED(BattleVarLocations);
    // REDIRECTED(BattleVarPairs);
    // REDIRECTED(GetBattleVar);
    // REDIRECTED(GetBattleVarAddr);

    // home/call_regs.c
    // REDIRECTED(v_hl_);
    REDIRECTED(v_de_);

    // home/clear_sprites.c
    REDIRECTED(HideSprites);
    REDIRECTED(ClearSprites);

    // home/compare.c
    REDIRECTED(CompareBytesLong);
    REDIRECTED(CompareBytes);

    // home/copy.c
    REDIRECTED(GetFarWRAMWord);
    REDIRECTED(GetFarByte);
    REDIRECTED(FarCopyWRAM);
    REDIRECTED(CopyBytes);
    REDIRECTED(GetFarWRAMByte);
    REDIRECTED(ByteFill);
    REDIRECTED(SwapBytes);
    REDIRECTED(GetFarWord);

    // home/copy_name.c
    // REDIRECTED(CopyName1);
    // REDIRECTED(CopyName2);

    // home/copy_tilemap.c
    REDIRECTED(LoadTilemapToTempTilemap);
    REDIRECTED(LoadTempTilemapToTilemap);
    REDIRECTED(SafeLoadTempTilemapToTilemap);

    // home/decompress.c
    REDIRECTED(Decompress);
    REDIRECTED(FarDecompress);

    // home/delay.c
    CONVERTED(DelayFrame);
    CONVERTED(DelayFrames);

    // home/double_speed.c
    // REDIRECTED(DoubleSpeed);
    // REDIRECTED(NormalSpeed);
    // REDIRECTED(SwitchSpeed);

    // home/fade.c
    // REDIRECTED(TimeOfDayFade);
    // REDIRECTED(RotateThreePalettesRight);
    // REDIRECTED(IncGradGBPalTable_04);
    // REDIRECTED(RotateFourPalettesRight);
    // REDIRECTED(IncGradGBPalTable_14);
    // REDIRECTED(IncGradGBPalTable_12);
    // REDIRECTED(RotateThreePalettesLeft);
    // REDIRECTED(IncGradGBPalTable_02);
    // REDIRECTED(IncGradGBPalTable_08);
    // REDIRECTED(IncGradGBPalTable_07);
    // REDIRECTED(IncGradGBPalTable_03);
    // REDIRECTED(IncGradGBPalTable_06);
    // REDIRECTED(IncGradGBPalTable_11);
    // REDIRECTED(IncGradGBPalTable_01);
    // REDIRECTED(IncGradGBPalTable_10);
    // REDIRECTED(IncGradGBPalTable_15);
    // REDIRECTED(RotatePalettesLeft);
    // REDIRECTED(RotatePalettesRight);
    // REDIRECTED(IncGradGBPalTable_13);
    // REDIRECTED(RotateFourPalettesLeft);
    // REDIRECTED(IncGradGBPalTable_00);
    // REDIRECTED(IncGradGBPalTable_05);
    // REDIRECTED(IncGradGBPalTable_09);

    // home/farcall.c
    // REDIRECTED(FarCall_hl);
    // REDIRECTED(ReturnFarCall);
    // REDIRECTED(FarCall_JumpToHL);
    // REDIRECTED(FarCall_de);
    // REDIRECTED(FarCall_JumpToDE);

    // home/flag.c
    // REDIRECTED(xor_a);
    // REDIRECTED(xor_a_dec_a);
    // REDIRECTED(ResetMapBufferEventFlags);
    // REDIRECTED(FlagAction);
    // REDIRECTED(ResetFlashIfOutOfCave);
    // REDIRECTED(CheckReceivedDex);
    // REDIRECTED(ResetBikeFlags);
    // REDIRECTED(CheckFieldDebug);
    // REDIRECTED(EventFlagAction);
    // REDIRECTED(CheckBPressedDebug);

    // home/game_time.c
    // REDIRECTED(ResetGameTime);
    // REDIRECTED(GameTimer);

    // home/gfx.c
    REDIRECTED(Get2bppViaHDMA);
    REDIRECTED(LoadFontsExtra);
    REDIRECTED(SafeHDMATransfer);
    REDIRECTED(Copy2bpp);
    REDIRECTED(DecompressRequest2bpp);
    REDIRECTED(UpdatePlayerSprite);
    REDIRECTED(LoadStandardFont);
    REDIRECTED(Request1bpp);
    REDIRECTED(Request2bpp);
    REDIRECTED(Get1bppViaHDMA);
    REDIRECTED(Copy1bpp);
    REDIRECTED(LoadFontsBattleExtra);
    REDIRECTED(FarCopyBytes);
    REDIRECTED(FarCopyBytesDouble_DoubleBankSwitch);
    REDIRECTED(Get2bpp);
    REDIRECTED(LoadFontsExtra2);
    REDIRECTED(FarCopyBytesDouble);
    REDIRECTED(Get1bpp);

    // home/header.c
    // CONVERTED(Bankswitch);
    // REDIRECTED(FarCall);
    // REDIRECTED(Start);
    // CONVERTED(JumpTable);

    // home/hm_moves.c
    // REDIRECTED(IsHM);
    // REDIRECTED(IsHMMove);

    // home/init.c
    REDIRECTED(ClearsScratch);
    REDIRECTED(ClearWRAM);
    REDIRECTED(Reset);
    REDIRECTED(ClearVRAM);
    REDIRECTED(Init);
    REDIRECTED(v_Start);

    // home/item.c
    // REDIRECTED(ReceiveItem);
    // REDIRECTED(CheckTossableItem);
    // REDIRECTED(CheckItem);
    // REDIRECTED(DoItemEffect);
    // REDIRECTED(TossItem);

    // home/joypad.c
    // REDIRECTED(ClearJoypad);
    // REDIRECTED(Joypad);
    // REDIRECTED(StopAutoInput);
    // REDIRECTED(UpdateJoypad);
    // REDIRECTED(JoyTitleScreenInput);
    // REDIRECTED(JoyTextDelay);
    // REDIRECTED(PromptButton);
    // REDIRECTED(GetJoypad);
    // REDIRECTED(SimpleWaitPressAorB);
    // REDIRECTED(JoyWaitAorB);
    // REDIRECTED(BlinkCursor);
    // REDIRECTED(WaitPressAorB_BlinkCursor);
    // REDIRECTED(WaitButton);
    // REDIRECTED(StartAutoInput);

    // home/lcd.c
    // REDIRECTED(Function547);
    REDIRECTED(DisableLCD);
    REDIRECTED(EnableLCD);
    CONVERTED(LCD);

    // home/map_objects.c
    // REDIRECTED(GetSpriteVTile);
    // REDIRECTED(SetSpriteDirection);
    // REDIRECTED(CheckIceTile);
    // REDIRECTED(GetPlayerStandingTile);
    // REDIRECTED(ApplyDeletionToMapObject);
    // REDIRECTED(GetSpritePalette);
    // REDIRECTED(DeleteObjectStruct);
    // REDIRECTED(DoesObjectHaveASprite);
    // REDIRECTED(CheckSuperTallGrassTile);
    // REDIRECTED(CheckWhirlpoolTile);
    // REDIRECTED(ResetVramState_Bit0);
    // REDIRECTED(CheckObjectVisibility);
    // REDIRECTED(CheckCounterTile);
    // REDIRECTED(GetSpriteMovementFunction);
    // REDIRECTED(CopyPlayerObjectTemplate);
    // REDIRECTED(GetSpriteDirection);
    // REDIRECTED(DeleteFollowerMapObject);
    // REDIRECTED(CopyMapObjectStruct);
    // REDIRECTED(CheckGrassTile);
    // REDIRECTED(GetMapObject);
    // REDIRECTED(CheckOnWater);
    // REDIRECTED(CheckHeadbuttTreeTile);
    // REDIRECTED(CheckStandingOnEntrance);
    // REDIRECTED(SetVramState_Bit0);
    // REDIRECTED(CopySpriteMovementData);
    // REDIRECTED(GetObjectStruct);
    // REDIRECTED(DoesSpriteHaveFacings);
    // REDIRECTED(CheckCutTreeTile);
    // REDIRECTED(LoadMovementDataPointer);
    // REDIRECTED(CheckObjectTime);
    // REDIRECTED(CheckPitTile);
    // REDIRECTED(GetTileCollision);
    // REDIRECTED(v_GetMovementByte);
    // REDIRECTED(UpdateSprites);
    // REDIRECTED(UnmaskCopyMapObjectStruct);
    // REDIRECTED(GetInitialFacing);
    // REDIRECTED(FindFirstEmptyObjectStruct);
    // REDIRECTED(CheckWaterfallTile);

    // home/math.c
    // REDIRECTED(Divide);
    // REDIRECTED(SimpleMultiply);
    // REDIRECTED(SimpleDivide);
    // REDIRECTED(Multiply);
    // REDIRECTED(SubtractAbsolute);

    // home/menu.c
    // REDIRECTED(InterpretBattleMenu);
    // REDIRECTED(HideCursor);
    // REDIRECTED(LoadStandardMenuHeader);
    // REDIRECTED(MenuTextbox);
    // REDIRECTED(PlayClickSFX);
    // REDIRECTED(SetUpMenu);
    // REDIRECTED(PlaceHollowCursor);
    // REDIRECTED(CopyMenuHeader);
    // REDIRECTED(DrawVariableLengthMenuBox);
    // REDIRECTED(PlaceMenuStrings);
    // REDIRECTED(PlaceVerticalMenuItems);
    // REDIRECTED(GetMenuDataPointerTableEntry);
    // REDIRECTED(PlaceGenericTwoOptionBox);
    // REDIRECTED(PushWindow);
    // REDIRECTED(MenuClickSound);
    // REDIRECTED(RestoreTileBackup);
    // REDIRECTED(ClearWholeMenuBox);
    // REDIRECTED(Place2DMenuItemName);
    // REDIRECTED(v_OffsetMenuHeader);
    // REDIRECTED(GetWindowStackTop);
    // REDIRECTED(GetMenu2);
    // REDIRECTED(GetStaticMenuJoypad);
    // REDIRECTED(GetScrollingMenuJoypad);
    // REDIRECTED(Coord2Tile);
    // REDIRECTED(PlaceYesNoBox);
    // REDIRECTED(InterpretTwoOptionMenu);
    // REDIRECTED(InitVerticalMenuCursor);
    // REDIRECTED(YesNoMenuHeader);
    // REDIRECTED(MenuTextboxBackup);
    // REDIRECTED(LoadMenuTextbox);
    // REDIRECTED(DoNthMenu);
    // REDIRECTED(MenuBox);
    // REDIRECTED(LoadMenuHeader);
    // REDIRECTED(MenuBoxCoord2Attr);
    // REDIRECTED(GetMenuTextStartCoord);
    // REDIRECTED(Call_ExitMenu);
    // REDIRECTED(InterpretMobileMenu);
    // REDIRECTED(CloseWindow);
    // REDIRECTED(StaticMenuJoypad);
    // REDIRECTED(GetNthMenuStrings);
    // REDIRECTED(OffsetMenuHeader);
    // REDIRECTED(MenuTextboxWaitButton);
    // REDIRECTED(RunMenuItemPrintingFunction);
    // REDIRECTED(InitMenuCursorAndButtonPermissions);
    // REDIRECTED(Load2DMenuData);
    // REDIRECTED(VerticalMenu);
    // REDIRECTED(GetMenuJoypad);
    // REDIRECTED(MenuJumptable);
    // REDIRECTED(ExitMenu);
    // REDIRECTED(CopyMenuData);
    // REDIRECTED(GetMenuBoxDims);
    // REDIRECTED(ScrollingMenuJoypad);
    // REDIRECTED(YesNoBox);
    // REDIRECTED(Coord2Attr);
    // REDIRECTED(AutomaticGetMenuBottomCoord);
    // REDIRECTED(ContinueGettingMenuJoypad);
    // REDIRECTED(v_YesNoBox);
    // REDIRECTED(v_2DMenu);
    // REDIRECTED(MenuWriteText);
    // REDIRECTED(ClearMenuBoxInterior);
    // REDIRECTED(PopWindow);
    // REDIRECTED(Menu_DummyFunction);
    // REDIRECTED(MenuBoxCoord2Tile);
    // REDIRECTED(CopyNameFromMenu);
    // REDIRECTED(GetMenuIndexSet);
    // REDIRECTED(PlaceNthMenuStrings);
    // REDIRECTED(StoreMenuCursorPosition);
    REDIRECTED(ClearWindowData);

    // home/mobile.c
    // REDIRECTED(Function3f9f);
    // REDIRECTED(Function3f7c);
    // REDIRECTED(ReturnMobileAPI);
    // REDIRECTED(Function3f35);
    // REDIRECTED(MobileTimer);
    // REDIRECTED(Function3ed7);
    // REDIRECTED(MobileAPI);
    // REDIRECTED(Function3eea);
    // REDIRECTED(Function3efd);
    // REDIRECTED(Function3f20);
    // REDIRECTED(MobileHome_PlaceBox);
    // REDIRECTED(Function3f88);
    // REDIRECTED(MobileReceive);

    // home/movement.c
    // REDIRECTED(ComputePathToWalkToPlayer);
    // REDIRECTED(DecrementMovementBufferCount);
    // REDIRECTED(InitMovementBuffer);
    // REDIRECTED(AppendToMovementBufferNTimes);
    // REDIRECTED(AppendToMovementBuffer);

    // home/names.c
    // REDIRECTED(GetItemName);
    // REDIRECTED(GetMoveName);
    // REDIRECTED(GetBasePokemonName);
    // REDIRECTED(GetPokemonName);
    // REDIRECTED(GetName);
    // REDIRECTED(GetTMHMName);
    // REDIRECTED(GetNthString);
    // REDIRECTED(NamesPointers);

    // home/palettes.c
    REDIRECTED(UpdatePalsIfCGB);
    REDIRECTED(ClearVBank1);
    // REDIRECTED(DmgToCgbObjPal0);
    REDIRECTED(UpdateCGBPals);
    REDIRECTED(DmgToCgbBGPals);
    REDIRECTED(DmgToCgbObjPals);
    REDIRECTED(CopyPals);
    // REDIRECTED(SwapTextboxPalettes);
    // REDIRECTED(ScrollBGMapPalettes);
    REDIRECTED(ForceUpdateCGBPals);
    // REDIRECTED(DmgToCgbObjPal1);
    // REDIRECTED(ReloadSpritesNoPalettes);
    // REDIRECTED(GSReloadPalettes);

    // home/pokedex_flags.c
    // REDIRECTED(CheckCaughtMon);
    // REDIRECTED(PokedexFlagAction);
    // REDIRECTED(SetSeenAndCaughtMon);
    // REDIRECTED(GetWeekday);
    // REDIRECTED(CheckSeenMon);
    // REDIRECTED(CountSetBits);
    // REDIRECTED(SetSeenMon);

    // home/pokemon.c
    // REDIRECTED(PlayStereoCry);
    // REDIRECTED(PlayMonCry);
    // REDIRECTED(GetBaseData);
    // REDIRECTED(v_PlayMonCry);
    // REDIRECTED(PrepMonFrontpic);
    // REDIRECTED(GetCryIndex);
    // REDIRECTED(GetNthMove);
    // REDIRECTED(GetCurNickname);
    // REDIRECTED(LoadCry);
    // REDIRECTED(IsAPokemon);
    // REDIRECTED(PlayStereoCry2);
    // REDIRECTED(PrintLevel_Force3Digits);
    // REDIRECTED(GetNickname);
    // REDIRECTED(PlayMonCry2);
    // REDIRECTED(Print8BitNumLeftAlign);
    // REDIRECTED(DrawBattleHPBar);
    // REDIRECTED(v_PrepMonFrontpic);
    // REDIRECTED(PrintLevel);

    // home/predef.c
    REDIRECTED(Predef);
    REDIRECTED(Predef_Return);

    // home/print_bcd.c
    REDIRECTED(PrintBCDNumber);
    REDIRECTED(PrintBCDDigit);

    // home/printer.c
    // REDIRECTED(PrinterReceive);
    // REDIRECTED(AskSerial);

    // home/print_text.c
    REDIRECTED(CopyDataUntil);
    REDIRECTED(PrintNum);
    REDIRECTED(FarPrintText);
    REDIRECTED(MobilePrintNum);
    REDIRECTED(PrintLetterDelay);
    REDIRECTED(CallPointerAt);

    // home/queue_script.c
    // REDIRECTED(FarQueueScript);
    // REDIRECTED(QueueScript);

    // home/random.c
    // REDIRECTED(BattleRandom);
    // REDIRECTED(Random);
    // REDIRECTED(RandomRange);

    // home/region.c
    // REDIRECTED(IsInJohto);
    // REDIRECTED(SetXYCompareFlags);

    // home/scrolling_menu.c
    // REDIRECTED(InitScrollingMenu);
    // REDIRECTED(JoyTextDelay_ForcehJoyDown);
    // REDIRECTED(ScrollingMenu);

    // home/serial.c
    // REDIRECTED(Serial);
    // REDIRECTED(Serial_PrintWaitingTextAndSyncAndExchangeNybble);
    // REDIRECTED(Serial_SyncAndExchangeNybble);
    // REDIRECTED(Serial_ExchangeByte);
    // REDIRECTED(WaitLinkTransfer);
    // REDIRECTED(Serial_ExchangeSyncBytes);
    // REDIRECTED(SerialDisconnected);
    // REDIRECTED(LinkDataReceived);
    // REDIRECTED(CheckLinkTimeoutFramesNonzero);
    // REDIRECTED(Serial_ExchangeBytes);
    // REDIRECTED(LinkTransfer);
    // REDIRECTED(SetBitsForTimeCapsuleRequestIfNotLinked);

    // home/sine.c
    // REDIRECTED(Cosine);
    // REDIRECTED(Sine);

    // home/sprite_anims.c
    // REDIRECTED(InitSpriteAnimStruct);
    // REDIRECTED(ReinitSpriteAnimFrame);

    // home/sprite_updates.c
    // REDIRECTED(DisableSpriteUpdates);
    // REDIRECTED(EnableSpriteUpdates);

    // home/sram.c
    REDIRECTED(CloseSRAM);
    REDIRECTED(OpenSRAM);

    // home/stone_queue.c
    // REDIRECTED(HandleStoneQueue);

    // home/string.c
    // REDIRECTED(InitName);
    // REDIRECTED(InitString);
    // REDIRECTED(v_InitString);

    // home/text.c
    // REDIRECTED(PlaceWatashiText);
    // REDIRECTED(String_Space);
    // REDIRECTED(PlaceNextChar);
    // REDIRECTED(TextCommand_RAM);
    // REDIRECTED(TextCommand_STRINGBUFFER);
    // REDIRECTED(TextboxPalette);
    // REDIRECTED(v_ContText);
    // REDIRECTED(CheckDict);  // Manualy convert?
    // REDIRECTED(PCChar);
    // REDIRECTED(PlaceString);
    // REDIRECTED(LineFeedChar);
    // REDIRECTED(TextCommand_SOUND);
    // REDIRECTED(Paragraph);
    // REDIRECTED(PokeFluteTerminator);
    // REDIRECTED(Diacritic);
    // REDIRECTED(PlaceMoveTargetsName);
    // REDIRECTED(TMCharText);
    // REDIRECTED(TextCommand_START);
    // REDIRECTED(PlaceKokoWaText);
    // REDIRECTED(PlacePOKe);
    // REDIRECTED(LineChar);
    // REDIRECTED(TextCommand_FAR);
    // REDIRECTED(TrainerCharText);
    // REDIRECTED(KougekiText);
    // REDIRECTED(PlacePOKEText);
    // REDIRECTED(NextChar);
    // REDIRECTED(PlacePKMNText);
    // REDIRECTED(PlaceJPRouteText);
    // REDIRECTED(TMChar);
    // REDIRECTED(PlaceJPRoute);
    // REDIRECTED(RocketCharText);
    // REDIRECTED(MobileScriptChar);
    // REDIRECTED(TextCommand_SCROLL);
    // REDIRECTED(PlaceBattlersName);
    // REDIRECTED(TextSFX);
    // REDIRECTED(NextLineChar);
    // REDIRECTED(TextboxBorder);
    // REDIRECTED(TextCommand_PROMPT_BUTTON);
    // REDIRECTED(v_ContTextNoPause);
    // REDIRECTED(CarriageReturnChar);
    // REDIRECTED(UnloadBlinkingCursor);
    // REDIRECTED(Text_WaitBGMap);
    // REDIRECTED(PlaceGenderedPlayerName);
    // REDIRECTED(PlaceWatashi);
    // REDIRECTED(PlacePOKeText);
    REDIRECTED(FillBoxWithByte);
    // REDIRECTED(GameFreakText);
    // REDIRECTED(TextCommand_DOTS);
    // REDIRECTED(NullChar);
    // REDIRECTED(PlaceDexEnd);
    // REDIRECTED(TextCommand_MOVE);
    // REDIRECTED(PrintText);
    // REDIRECTED(Textbox);
    // REDIRECTED(SixDotsChar);
    // REDIRECTED(PlaceKokoWa);
    // REDIRECTED(PlaceCommandCharacter);
    // REDIRECTED(TextCommand_BCD);
    // REDIRECTED(TextCommand_LOW);
    // REDIRECTED(TextCommand_WAIT_BUTTON);
    // REDIRECTED(SpeechTextbox);
    // REDIRECTED(BuenaPrintText);
    // REDIRECTED(PlaceKougeki);
    // REDIRECTED(SixDotsCharText);
    // REDIRECTED(LoadBlinkingCursor);
    REDIRECTED(DoTextUntilTerminator);
    REDIRECTED(DoTextUntilTerminator_TextCommand);
    // REDIRECTED(ContText);
    // REDIRECTED(PrintPlayerName);
    // REDIRECTED(DummyChar);
    // REDIRECTED(RocketChar);
    // REDIRECTED(TextCommand_START_ASM);
    // REDIRECTED(PrintRivalName);
    // REDIRECTED(PlaceFarString);
    // REDIRECTED(ClearScreen);
    REDIRECTED(PlaceHLTextAtBC);
    // REDIRECTED(PlaceMoveUsersName);
    // REDIRECTED(PCCharText);
    REDIRECTED(ClearBox);
    // REDIRECTED(PrintRedsName);
    // REDIRECTED(EnemyText);
    // REDIRECTED(TextCommand_DECIMAL);
    // REDIRECTED(PrintGreensName);
    // REDIRECTED(TextCommand_CRY);
    // REDIRECTED(RadioTerminator);
    // REDIRECTED(TextCommand_PAUSE);
    // REDIRECTED(TrainerChar);
    // REDIRECTED(TextScroll);
    // REDIRECTED(TextCommand_DAY);
    // REDIRECTED(PromptText);
    // REDIRECTED(PlaceEnemysName);
    // REDIRECTED(DoneText);
    // REDIRECTED(ChanSuffixText);
    // REDIRECTED(TextCommands);
    // REDIRECTED(SetUpTextbox);
    // REDIRECTED(KunSuffixText);
    // REDIRECTED(TextCommand_BOX);
    // REDIRECTED(ClearTilemap);
    // REDIRECTED(PlacePOKE);
    // REDIRECTED(PlacePKMN);
    // REDIRECTED(PrintMomsName);
    // REDIRECTED(PrintTextboxText);

    // home/time.c
    // REDIRECTED(GetClock);
    // REDIRECTED(LatchClock);
    // REDIRECTED(FixDays);
    // REDIRECTED(UpdateTime);
    // REDIRECTED(Timer);
    // REDIRECTED(FixTime);
    // REDIRECTED(InitDayOfWeek);
    // REDIRECTED(RecordRTCStatus);
    // REDIRECTED(InitTimeOfDay);
    // REDIRECTED(ClearClock);
    // REDIRECTED(SetClock);
    // REDIRECTED(CheckRTCStatus);
    // REDIRECTED(ClearRTCStatus);
    // REDIRECTED(InitTime);

    // home/time_palettes.c
    // REDIRECTED(UpdateTimeAndPals);
    // REDIRECTED(TimeOfDayPals);
    // REDIRECTED(UpdateTimePals);

    // home/trainers.c
    // REDIRECTED(CheckTrainerFlag);
    // REDIRECTED(FacingPlayerDistance_bc);
    // REDIRECTED(TalkToTrainer);
    // REDIRECTED(LoadTrainer_continue);
    // REDIRECTED(FacingPlayerDistance);
    // REDIRECTED(PrintWinLossText);
    // REDIRECTED(v_CheckTrainerBattle);
    // REDIRECTED(CheckTrainerBattle);

    // home/vblank.c
    REDIRECTED(VBlank3);
    REDIRECTED(VBlank1);
    REDIRECTED(UpdatePals);
    REDIRECTED(VBlank2);
    REDIRECTED(VBlank);
    REDIRECTED(VBlank0);
    REDIRECTED(VBlank5);
    REDIRECTED(VBlank6);
    REDIRECTED(VBlank4);

    // home/video.c
    REDIRECTED(WaitTop);
    REDIRECTED(DMATransfer);
    REDIRECTED(UpdateBGMapBuffer);
    REDIRECTED(Serve1bppRequest);
    REDIRECTED(UpdateBGMap);
    REDIRECTED(v_Serve2bppRequest);
    REDIRECTED(Serve2bppRequest_VBlank);
    REDIRECTED(Serve2bppRequest);
    REDIRECTED(AnimateTileset);

    // home/window.c
    REDIRECTED(CloseText);
    REDIRECTED(SafeUpdateSprites);
    REDIRECTED(RefreshScreen);
    REDIRECTED(OpenText);
    // REDIRECTED(SetCarryFlag);
    REDIRECTED(v_OpenAndCloseMenu_HDMATransferTilemapAndAttrmap);

    // home/tilemap.c
    REDIRECTED(IsCGB);
    REDIRECTED(SetHPPal);
    REDIRECTED(WaitBGMap);
    REDIRECTED(CGBOnly_CopyTilemapAtOnce);
    REDIRECTED(v_CopyTilemapAtOnce);
    REDIRECTED(v_CopyTilemapAtOnce_CopyBGMapViaStack);
    REDIRECTED(SetPalettes);
    REDIRECTED(ClearBGPalettes);
    REDIRECTED(CopyTilemapAtOnce);
    REDIRECTED(CopyAttrmapAndTilemapToWRAMBank3);
    REDIRECTED(GetMemSGBLayout);
    REDIRECTED(GetHPPal);
    REDIRECTED(GetSGBLayout);
    REDIRECTED(ApplyTilemap);
    REDIRECTED(WaitBGMap2);
    REDIRECTED(ClearPalettes);

    // engine/menus/savemenu_copytilemapatonce.c
    REDIRECTED(SaveMenu_CopyTilemapAtOnce);
    REDIRECTED(SaveMenu_CopyTilemapAtOnce_CopyBGMapViaStack);

    // engine/overworld/map_objects.c
    REDIRECTED(StepFunction_PlayerJump);
    REDIRECTED(StepFunction_14);
    // REDIRECTED(TryResetPlayerAction);
    // REDIRECTED(GetIndexedMovementByte1);
    // REDIRECTED(WaitStep_InPlace);
    // REDIRECTED(GetIndexedMovementByte2);
    // REDIRECTED(v_ContinueSpawnFacing);
    // REDIRECTED(MovementFunction_Indexed2);
    // REDIRECTED(MovementFunction_RandomWalkXY);
    // REDIRECTED(FreezeAllObjects);
    // REDIRECTED(GetMovementByte);
    // REDIRECTED(GetFollowerNextMovementByte);
    // REDIRECTED(UpdateJumpPosition);
    // REDIRECTED(InitSprites);
    // REDIRECTED(MovementFunction_0a);
    // REDIRECTED(StepVectors);
    // REDIRECTED(MovementFunction_Indexed1);
    // REDIRECTED(v_MovementSpinNextFacing);
    // REDIRECTED(SetFacing_Standing);
    // REDIRECTED(UpdateObjectNextTile);
    // REDIRECTED(CopyStandingCoordsTileToNextCoordsTile);
    // REDIRECTED(UpdatePlayerStep);
    REDIRECTED(StepFunction_TeleportTo);
    // REDIRECTED(ResetStepVector);
    // REDIRECTED(UpdateAllObjectsFrozen);
    REDIRECTED(StepFunction_Restore);
    // REDIRECTED(CallObjectAction);
    // REDIRECTED(MovementFunction_0d);
    // REDIRECTED(CheckObjectCoveredByTextbox);
    // REDIRECTED(GetMovementObject);
    // REDIRECTED(SetLeaderIfVisible);
    // REDIRECTED(v_MovementSpinRepeat);
    // REDIRECTED(InitTempObject);
    // REDIRECTED(HandleMovementData);
    REDIRECTED(StepFunction_Reset);
    REDIRECTED(StepFunction_NPCWalk);
    REDIRECTED(StepFunction_TrackingObject);
    // REDIRECTED(ResetLeader);
    REDIRECTED(StepFunction_TeleportFrom);
    // REDIRECTED(UpdateTallGrassFlags);
    // REDIRECTED(RestoreDefaultMovement);
    REDIRECTED(StepFunction_PlayerWalk);
    // REDIRECTED(MovementFunction_RandomWalkX);
    // REDIRECTED(v_MovementSpinTurnRight);
    // REDIRECTED(MovementFunction_Emote);
    // REDIRECTED(RespawnPlayer);
    // REDIRECTED(MovementFunction_ShakingGrass);
    // REDIRECTED(UpdateRespawnedObjectFrozen);
    REDIRECTED(StepFunction_SkyfallTop);
    // REDIRECTED(DoStepsForAllObjects);
    // REDIRECTED(GetStepVector);
    // REDIRECTED(ShakeGrass);
    REDIRECTED(StepFunction_StrengthBoulder);
    // REDIRECTED(AddStepVector);
    // REDIRECTED(DeleteMapObject);
    // REDIRECTED(SpawnInCustomFacing);
    ////REDIRECTED(Field1c_AnonJumptable);
    // REDIRECTED(MovementFunction_Null);
    // REDIRECTED(Stubbed_UpdateYOffset);
    REDIRECTED(StepFunction_NPCJump);
    // REDIRECTED(RespawnPlayerAndOpponent);
    // REDIRECTED(RespawnObject);
    // REDIRECTED(MovementFunction_RandomWalkY);
    REDIRECTED(StepFunction_GotBite);
    REDIRECTED(StepFunction_ContinueWalk);
    // REDIRECTED(MovementFunction_SpinClockwise);
    // REDIRECTED(SpawnStrengthBoulderDust);
    REDIRECTED(StepFunction_Skyfall);
    // REDIRECTED(MovementFunction_RandomSpinFast);
    // REDIRECTED(v_MovementSpinTurnLeft);
    // REDIRECTED(RandomStepDuration_Slow);
    // REDIRECTED(MovementFunction_Follow);
    // REDIRECTED(v_SetRandomStepDuration);
    // REDIRECTED(CopyTempObjectData);
    REDIRECTED(StepFunction_Sleep);
    // REDIRECTED(MovementFunction_0b);
    // REDIRECTED(FreezeObject);
    // REDIRECTED(MovementFunction_Strength);
    // REDIRECTED(FreezeAllOtherObjects);
    // REDIRECTED(MovementFunction_ScreenShake);
    // REDIRECTED(InitMovementField1dField1e);
    // REDIRECTED(GetNextTile);
    // REDIRECTED(ObjectMovementByte_AnonJumptable);
    REDIRECTED(StepFunction_FromMovement);
    // REDIRECTED(ObjectMovementByte_DecAnonJumptableIndex);
    REDIRECTED(StepFunction_ScreenShake);
    // REDIRECTED(DespawnEmote);
    // REDIRECTED(SpawnInFacingDown);
    // REDIRECTED(ResetObject);
    // REDIRECTED(ContinueReadingMovement);
    // REDIRECTED(UnfreezeAllObjects);
    // REDIRECTED(Field1c_IncAnonJumptableIndex);
    // REDIRECTED(ObjectMovementByte_IncAnonJumptableIndex);
    // REDIRECTED(v_GetMovementObject);
    // REDIRECTED(UselessAndA);
    REDIRECTED(StepFunction_DigTo);
    // REDIRECTED(StepTypesJumptable);
    // REDIRECTED(HandleStepType);
    // REDIRECTED(GetStepVectorSign);
    // REDIRECTED(ObjectMovementByte_ZeroAnonJumptableIndex);
    // REDIRECTED(MovementFunction_Shadow);
    // REDIRECTED(HandleObjectAction);
    // REDIRECTED(InitStep);
    REDIRECTED(StepFunction_Bump);
    REDIRECTED(StepFunction_RockSmash);
    // REDIRECTED(GetMapObjectField);
    // REDIRECTED(v_RandomWalkContinue);
    // REDIRECTED(DoMovementFunction);
    // REDIRECTED(CheckObjectStillVisible);
    // REDIRECTED(MovementFunction_RandomSpinSlow);
    // REDIRECTED(v_MovementSpinInit);
    // REDIRECTED(v_UnfreezeFollowerObject);
    // REDIRECTED(SetFollowerIfVisible);
    // REDIRECTED(MovementFunction_Script);
    // REDIRECTED(MovementFunction_SpinCounterclockwise);
    // REDIRECTED(v_CallFrozenObjectAction);
    // REDIRECTED(v_SetPlayerPalette);
    // REDIRECTED(SpawnEmote);
    // REDIRECTED(SpawnShadow);
    // REDIRECTED(Field1c_SetAnonJumptableIndex);
    // REDIRECTED(RefreshPlayerSprite);
    // REDIRECTED(ShakeScreen);
    // REDIRECTED(ResetFollower);
    REDIRECTED(StepFunction_Turn);
    // REDIRECTED(ApplyMovementToFollower);
    // REDIRECTED(RandomStepDuration_Fast);
    // REDIRECTED(ApplyBGMapAnchorToObjects);
    // REDIRECTED(MovementFunction_Standing);
    REDIRECTED(StepFunction_Delete);
    // REDIRECTED(MovementFunction_FollowNotExact);
    // REDIRECTED(MovementFunction_0c);
    // REDIRECTED(Field1c_GetAnonJumptableIndex);
    // REDIRECTED(CheckObjectOnScreen);
    // REDIRECTED(EndSpriteMovement);
    // REDIRECTED(HandleNPCStep);
    // REDIRECTED(CopyNextCoordsTileToStandingCoordsTile);
    // REDIRECTED(MovementFunction_ObeyDPad);
    // REDIRECTED(UnfreezeObject);
    // REDIRECTED(HandleFrozenObjectAction);
    // REDIRECTED(v_UpdateSprites);
    // REDIRECTED(HandleObjectStep);
    // REDIRECTED(MovementFunction_0e);
    // REDIRECTED(SetTallGrassFlags);
    // REDIRECTED(StartFollow);
    REDIRECTED(StepFunction_17);
    // REDIRECTED(MovementFunction_BoulderDust);
    // REDIRECTED(MovementFunction_Bouncing);
    // REDIRECTED(GetPlayerNextMovementByte);
    // REDIRECTED(UpdateObjectFrozen);
    REDIRECTED(StepFunction_Standing);
    // REDIRECTED(Field1c_ZeroAnonJumptableIndex);
    REDIRECTED(StepFunction_16);
    // REDIRECTED(HideAllObjects);
    // REDIRECTED(MovementFunction_BigStanding);
    // REDIRECTED(StopFollow);
    // REDIRECTED(JumpMovementPointer);

    // engine/battle_anims/functions.c
    REDIRECTED(BattleAnimFunction_MoveWaveToTarget);
    REDIRECTED(BattleAnimFunction_FloatUp);
    REDIRECTED(BattleAnimFunction_ThrowFromUserToTargetAndDisappear);
    // REDIRECTED(BattleAnim_Cosine_e);
    REDIRECTED(BattleAnimFunction_MoveFromUserToTargetSpinAround);
    REDIRECTED(BattleAnimFunction_SacredFire);
    REDIRECTED(BattleAnimFunction_PerishSong);
    REDIRECTED(BattleAnimFunction_PsychUp);
    REDIRECTED(BattleAnimFunction_Null);
    REDIRECTED(BattleAnimFunction_Drop);
    REDIRECTED(BattleAnimFunction_SpeedLine);
    REDIRECTED(BattleAnimFunction_SpiralDescent);
    REDIRECTED(BattleAnimFunction_AncientPower);
    // REDIRECTED(BattleAnim_AbsCosinePrecise);
    REDIRECTED(BattleAnimFunction_Agility);
    REDIRECTED(BattleAnimFunction_RapidSpin);
    REDIRECTED(BattleAnimFunction_SwaggerMorningSun);
    REDIRECTED(BattleAnimFunction_BatonPass);
    REDIRECTED(BattleAnimFunction_LeechSeed);
    // REDIRECTED(BattleAnim_Sine_e);
    REDIRECTED(BattleAnimFunction_Recover);
    // REDIRECTED(BattleAnimSineWave);
    REDIRECTED(BattleAnimFunction_Conversion);
    REDIRECTED(BattleAnimFunction_BetaPursuit);
    REDIRECTED(BattleAnimFunction_Horn);
    REDIRECTED(BattleAnimFunction_Bite);
    // REDIRECTED(BattleAnim_Cosine);
    REDIRECTED(BattleAnimFunction_Absorb);
    // REDIRECTED(GetBallAnimPal);
    REDIRECTED(BattleAnimFunction_ConfuseRay);
    REDIRECTED(BattleAnimFunction_SafeguardProtect);
    REDIRECTED(BattleAnimFunction_Ember);
    REDIRECTED(BattleAnimFunction_EncoreBellyDrum);
    REDIRECTED(BattleAnimFunction_Amnesia);
    REDIRECTED(BattleAnimFunction_PokeBallBlocked);
    REDIRECTED(BattleAnimFunction_Spikes);
    REDIRECTED(BattleAnimFunction_Dig);
    REDIRECTED(BattleAnimFunction_Shiny);
    REDIRECTED(BattleAnimFunction_SkyAttack);
    REDIRECTED(BattleAnimFunction_GrowthSwordsDance);
    REDIRECTED(BattleAnimFunction_WaterGun);
    REDIRECTED(BattleAnimFunction_Needle);
    // REDIRECTED(BattleAnim_Sine);
    REDIRECTED(BattleAnimFunction_Sound);
    REDIRECTED(BattleAnimFunction_PoisonGas);
    REDIRECTED(BattleAnimFunction_String);
    REDIRECTED(BattleAnimFunction_FireBlast);
    REDIRECTED(BattleAnimFunction_PokeBall);
    REDIRECTED(BattleAnimFunction_Sludge);
    REDIRECTED(BattleAnimFunction_Surf);
    // REDIRECTED(BattleAnim_AbsSinePrecise);
    // REDIRECTED(BattleAnim_StepThrownToTarget);
    REDIRECTED(BattleAnimFunction_Dizzy);
    REDIRECTED(BattleAnimFunction_ThiefPayday);
    // REDIRECTED(BattleAnim_StepToTarget);
    REDIRECTED(BattleAnimFunction_ThunderWave);
    REDIRECTED(BattleAnimFunction_Cotton);
    REDIRECTED(BattleAnimFunction_Egg);
    REDIRECTED(BattleAnimFunction_MetronomeHand);
    REDIRECTED(BattleAnimFunction_PresentSmokescreen);
    // REDIRECTED(BattleAnim_IncAnonJumptableIndex);
    REDIRECTED(BattleAnimFunction_Wrap);
    REDIRECTED(BattleAnimFunction_RazorLeaf);
    REDIRECTED(BattleAnimFunction_Sing);
    REDIRECTED(BattleAnimFunction_HiddenPower);
    REDIRECTED(BattleAnimFunction_SmokeFlameWheel);
    REDIRECTED(BattleAnimFunction_Paralyzed);
    REDIRECTED(BattleAnimFunction_HealBellNotes);
    REDIRECTED(BattleAnimFunction_Curse);
    REDIRECTED(BattleAnimFunction_Bubble);
    REDIRECTED(BattleAnimFunction_AbsorbCircle);
    // REDIRECTED(DoBattleAnimFrame);
    REDIRECTED(BattleAnimFunction_AnimObjB0);
    // REDIRECTED(BattleAnim_ScatterHorizontal);
    REDIRECTED(BattleAnimFunction_RazorWind);
    REDIRECTED(BattleAnimFunction_Clamp_Encore);
    // REDIRECTED(BattleAnim_StepCircle);
    // REDIRECTED(BattleAnim_AnonJumptable);
    REDIRECTED(BattleAnimFunction_MetronomeSparkleSketch);
    REDIRECTED(BattleAnimFunction_Bonemerang);
    REDIRECTED(BattleAnimFunction_ThrowFromUserToTarget);
    REDIRECTED(BattleAnimFunction_MoveFromUserToTarget);
    REDIRECTED(BattleAnimFunction_LockOnMindReader);
    REDIRECTED(BattleAnimFunction_SolarBeam);
    REDIRECTED(BattleAnimFunction_RockSmash);
    REDIRECTED(BattleAnimFunction_Gust);
    REDIRECTED(BattleAnimFunction_Powder);
    REDIRECTED(BattleAnimFunction_PetalDance);
    REDIRECTED(BattleAnimFunction_StrengthSeismicToss);
    REDIRECTED(BattleAnimFunction_Kick);
    REDIRECTED(BattleAnimFunction_MoveInCircle);
    REDIRECTED(BattleAnimFunction_Shake);
    REDIRECTED(BattleAnimFunction_RainSandstorm);
    REDIRECTED(BattleAnimFunction_MoveUp);
    REDIRECTED(BattleAnimFunction_MoveFromUserToTargetAndDisappear);

    // engine/battle_anims/bg_effects.c
    REDIRECTED(BattleBGEffect_BetaSendOutMon1);
    REDIRECTED(BattleBGEffect_Psychic);
    // REDIRECTED(BGEffects_LoadBGPal1_OBPal0);
    // REDIRECTED(BGEffect_CheckBattleTurn);
    // REDIRECTED(DeformWater);
    REDIRECTED(BattleBGEffect_FlashWhite);
    REDIRECTED(BattleBGEffect_GetNextDMGPal);
    REDIRECTED(BattleBGEffect_SetLCDStatCustoms1);
    REDIRECTED(BattleBGEffect_ReturnMon);
    // REDIRECTED(BattleAnim_ResetLCDStatCustom);
    REDIRECTED(BattleBGEffect_BounceDown);
    REDIRECTED(BattleBGEffects_ClearLYOverrides);
    REDIRECTED(BattleBGEffect_EndWater);
    // REDIRECTED(BattleBGEffects_SetLYOverrides);
    REDIRECTED(BattleBGEffect_Teleport);
    REDIRECTED(BattleBGEffect_WobbleMon);
    // REDIRECTED(VitalThrow_MoveBackwards);
    REDIRECTED(BattleBGEffect_Rollout);
    // REDIRECTED(BGEffect_CheckFlyDigStatus);
    REDIRECTED(BattleBGEffect_FadeMonToBlackRepeating);
    REDIRECTED(BattleBGEffect_GetFirstDMGPal);
    REDIRECTED(BattleBGEffect_HideMon);
    REDIRECTED(BattleBGEffect_ShakeScreenX);
    // REDIRECTED(DeformScreen);
    // REDIRECTED(BGEffect_FillLYOverridesBackup);
    // REDIRECTED(BGEffects_LoadBGPal0_OBPal1);
    REDIRECTED(BattleBGEffect_BodySlam);
    REDIRECTED(BattleBGEffect_CycleOBPalsGrayAndYellow);
    REDIRECTED(BattleBGEffect_FadeMonsToBlackRepeating);
    REDIRECTED(BattleBGEffect_NightShade);
    // REDIRECTED(BGEffect_DisplaceLYOverridesBackup);
    REDIRECTED(BattleBGEffect_WhiteHues);
    // REDIRECTED(Tackle_MoveForward);
    REDIRECTED(BattleBGEffect_WobbleScreen);
    REDIRECTED(BattleBGEffect_FlashContinue);
    REDIRECTED(BattleBGEffect_FlashInverted);
    REDIRECTED(BattleBGEffect_Withdraw);
    REDIRECTED(BattleBGEffect_BattlerObj_1Row);
    REDIRECTED(BattleBGEffect_End);
    // REDIRECTED(BatttleBGEffects_GetNamedJumptablePointer);
    REDIRECTED(BattleBGEffects_AnonJumptable);
    REDIRECTED(BattleBGEffect_CycleMonLightDarkRepeating);
    // REDIRECTED(BattleBGEffects_CheckSGB);
    //  REDIRECTED(BGEffect_RapidCyclePals);
    // REDIRECTED(BattleBGEffects_Cosine);
    //  REDIRECTED(Rollout_FillLYOverridesBackup);
    REDIRECTED(BattleBGEffect_FadeMonToBlack);
    REDIRECTED(BattleBGEffect_Whirlpool);
    REDIRECTED(BattleBGEffect_AcidArmor);
    // REDIRECTED(Tackle_ReturnMove);
    // REDIRECTED(DoBattleBGEffectFunction);
    REDIRECTED(BattleBGEffect_AlternateHues);
    REDIRECTED(BattleBGEffect_Surf);
    REDIRECTED(BattleBGEffect_FlashMonRepeating);
    REDIRECTED(BattleBGEffect_DoubleTeam);
    REDIRECTED(BattleBGEffect_RemoveMon);
    REDIRECTED(BattleBGEffect_EnterMon);
    // REDIRECTED(v_QueueBattleAnimation);
    REDIRECTED(BattleBGEffect_Water);
    REDIRECTED(BattleBGEffect_GetNthDMGPal);
    // REDIRECTED(BattleBGEffects_ResetVideoHRAM);
    //  REDIRECTED(InitSurfWaves);
    REDIRECTED(BattleBGEffects_GetShakeAmount);
    REDIRECTED(BattleBGEffect_BattlerObj_2Row);
    REDIRECTED(BattleBGEffect_FadeMonToLight);
    REDIRECTED(BattleBGEffect_Tackle);
    REDIRECTED(BattleBGEffect_VibrateMon);
    REDIRECTED(BattleBGEffect_VitalThrow);
    REDIRECTED(BattleBGEffect_StartWater);
    // REDIRECTED(QueueBGEffect);
    REDIRECTED(BattleBGEffect_Flail);
    REDIRECTED(BattleBGEffect_Dig);
    // REDIRECTED(ExecuteBGEffects);
    REDIRECTED(BattleBGEffect_BlackHues);
    REDIRECTED(BattleBGEffect_FadeMonToLightRepeating);
    REDIRECTED(BattleBGEffect_WavyScreenFX);
    REDIRECTED(BattleBGEffect_SetLCDStatCustoms2);
    REDIRECTED(BattleBGEffect_WaveDeformMon);
    // REDIRECTED(BattleBGEffects);
    REDIRECTED(BattleBGEffect_CycleBGPals_Inverted);
    REDIRECTED(BattleBGEffect_RapidFlash);
    REDIRECTED(BattleBGEffect_WobblePlayer);
    REDIRECTED(BattleBGEffect_BetaPursuit);
    REDIRECTED(BattleBGEffects_Sine);
    REDIRECTED(BattleBGEffect_FadeMonToWhiteWaitFadeBack);
    REDIRECTED(BattleBGEffect_BetaSendOutMon2);
    REDIRECTED(BattleBGEffect_ShowMon);
    REDIRECTED(BattleBGEffect_FadeMonFromWhite);
    REDIRECTED(BattleBGEffect_RunPicResizeScript);
    // REDIRECTED(EndBattleBGEffect);
    REDIRECTED(BattleBGEffect_CycleMidOBPalsGrayAndYellow);
    REDIRECTED(BattleBGEffect_ShakeScreenY);
    // REDIRECTED(BattleBGEffects_IncAnonJumptableIndex);

    // engine/gfx/dma_transfer.c
    // REDIRECTED(HDMATransferAttrmapToWRAMBank3);
    REDIRECTED(v_continue_HDMATransfer);
    REDIRECTED(HDMATransfer_NoDI);
    // REDIRECTED(HDMATransfer_OnlyTopFourRows);
    // REDIRECTED(HDMATransfer1bpp);
    // REDIRECTED(Mobile_OpenAndCloseMenu_HDMATransferTilemapAndAttrmap);
    // REDIRECTED(WaitDMATransfer);
    // REDIRECTED(HDMATransfer_Wait127Scanlines);
    // REDIRECTED(HDMATransfer2bpp);
    // REDIRECTED(HDMATransfer_Wait123Scanlines_toBGMap);
    // REDIRECTED(HDMATransferAttrmapAndTilemapToWRAMBank3);
    // REDIRECTED(HDMATransfer_Wait123Scanlines);
    // REDIRECTED(HDMATransferToWRAMBank3);
    // REDIRECTED(Function1040fb);
    // REDIRECTED(Function1040d4);
    // REDIRECTED(HDMATransfer_Wait127Scanlines_toBGMap);
    // REDIRECTED(Mobile_ReloadMapPart);
    // REDIRECTED(PadMapForHDMATransfer);
    // REDIRECTED(HDMATransferTilemapToWRAMBank3);
    // REDIRECTED(ReloadMapPart);
    // REDIRECTED(OpenAndCloseMenu_HDMATransferTilemapAndAttrmap);
    // REDIRECTED(CallInSafeGFXMode);
    // REDIRECTED(v_LoadHDMAParameters);
    // REDIRECTED(PadAttrmapForHDMATransfer);
    // REDIRECTED(PadTilemapForHDMATransfer);

    // audio/engine.c
    CONVERTED(v_InitSound);
    CONVERTED(MusicFadeRestart);
    CONVERTED(MusicOn);
    CONVERTED(MusicOff);
    CONVERTED(v_UpdateSound);
    CONVERTED(UpdateChannels);
    // CONVERTED(v_CheckSFX);
    CONVERTED(PlayDanger);
    CONVERTED(FadeMusic);
    CONVERTED(LoadNote);
    CONVERTED(HandleTrackVibrato);
    CONVERTED(ApplyPitchSlide);
    CONVERTED(HandleNoise);
    CONVERTED(ReadNoiseSample);
    CONVERTED(ParseMusic);
    CONVERTED(RestoreVolume);
    CONVERTED(ParseSFXOrCry);
    CONVERTED(GetNoiseSample);
    CONVERTED(ParseMusicCommand);
    CONVERTED(Music_Ret);
    CONVERTED(Music_Call);
    CONVERTED(Music_Jump);
    CONVERTED(Music_Loop);
    CONVERTED(Music_SetCondition);
    CONVERTED(Music_JumpIf);
    CONVERTED(MusicEE);
    CONVERTED(MusicNone);
    CONVERTED(MusicE2);
    CONVERTED(Music_Vibrato);
    CONVERTED(Music_PitchSlide);
    CONVERTED(Music_PitchOffset);
    CONVERTED(MusicE7);
    CONVERTED(Music_DutyCyclePattern);
    CONVERTED(MusicE8);
    CONVERTED(Music_ToggleSFX);
    CONVERTED(Music_ToggleNoise);
    CONVERTED(Music_SFXToggleNoise);
    CONVERTED(Music_NoteType);
    CONVERTED(Music_PitchSweep);
    CONVERTED(Music_DutyCycle);
    CONVERTED(Music_VolumeEnvelope);
    CONVERTED(Music_Tempo);
    CONVERTED(Music_Octave);
    CONVERTED(Music_Transpose);
    CONVERTED(Music_StereoPanning);
    CONVERTED(Music_ForceStereoPanning);
    CONVERTED(Music_Volume);
    CONVERTED(Music_TempoRelative);
    CONVERTED(Music_SFXPriorityOn);
    CONVERTED(Music_SFXPriorityOff);
    CONVERTED(Music_RestartChannel);
    CONVERTED(Music_NewSong);
    // CONVERTED(GetMusicByte);
    // CONVERTED(GetFrequency);
    // CONVERTED(SetNoteDuration);
    // CONVERTED(SetGlobalTempo);
    CONVERTED(StartChannel);
    CONVERTED(SetLRTracks);
    // CONVERTED(v_PlayMusic);
    CONVERTED(v_PlayCry);
    CONVERTED(v_PlaySFX);
    CONVERTED(PlayStereoSFX);
    // CONVERTED(LoadChannel);
    // CONVERTED(ChannelInit);
    // CONVERTED(LoadMusicByte);
    CONVERTED(GetLRTracks);
    CONVERTED(ClearChannels);
    // CONVERTED(ClearChannel);
    REDIRECTED(PlayTrainerEncounterMusic);

    // home/map.c
    REDIRECTED(ClearBGMapBuffer);
    REDIRECTED(UpdateBGMapColumn);
    // REDIRECTED(ReadMapScripts);
    // REDIRECTED(GetAnyMapAttributesBank);
    // REDIRECTED(GetMapScriptsBank);
    // REDIRECTED(ObjectEvent);
    // REDIRECTED(GetFishingGroup);
    // REDIRECTED(ReloadTilesetAndPalettes);
    // REDIRECTED(FillNorthConnectionStrip);
    // REDIRECTED(CopyMapPartial);
    // REDIRECTED(GetMapAttributesPointer);
    // REDIRECTED(BackupBGMapColumn);
    // REDIRECTED(SaveScreen);
    // REDIRECTED(BGEvent);
    // REDIRECTED(Call_a_de);
    // REDIRECTED(GetBlockLocation);
    // REDIRECTED(GetWarpDestCoords);
    // REDIRECTED(GetMapPointer);
    // REDIRECTED(CopyMapPartialAndAttributes);
    REDIRECTED(GetWorldMapLocation);
    REDIRECTED(GetMapMusic);
    // REDIRECTED(UpdateBGMapRow);
    // REDIRECTED(CheckFacingBGEvent);
    // REDIRECTED(LoadMapTileset);
    // REDIRECTED(CoordinatesEventText);
    // REDIRECTED(LoadMapAttributes_SkipObjects);
    // REDIRECTED(FillWestConnectionStrip);
    // REDIRECTED(ScrollMapRight);
    // REDIRECTED(GetAnyMapTileset);
    // REDIRECTED(ScrollMapLeft);
    // REDIRECTED(SaveScreen_LoadConnection);
    // REDIRECTED(GetDestinationWarpNumber);
    // REDIRECTED(GetMapSceneID);
    // REDIRECTED(ReadCoordEvents);
    // REDIRECTED(GetFacingTileCoord);
    // REDIRECTED(ReadObjectEvents);
    // REDIRECTED(GetAnyMapPointer);
    // REDIRECTED(LoadMapAttributes);
    // REDIRECTED(FinishExitMenu);
    // REDIRECTED(ExecuteCallbackScript);
    // REDIRECTED(FillMapConnections);
    // REDIRECTED(SwitchToMapScriptsBank);
    // REDIRECTED(ReturnToMapFromSubmenu);
    // REDIRECTED(ReadMapEvents);
    // REDIRECTED(ReadBGEvents);
    // REDIRECTED(BGEventText);
    // REDIRECTED(BufferScreen);
    // REDIRECTED(CheckScenes);
    // REDIRECTED(ReadMapSceneScripts);
    REDIRECTED(MapTextbox);
    // REDIRECTED(Map_DummyFunction);
    // REDIRECTED(CopyMapAttributes);
    // REDIRECTED(SwitchToMapAttributesBank);
    // REDIRECTED(ChangeMap);
    // REDIRECTED(LoadMetatiles);
    // REDIRECTED(CheckIndoorMap);
    // REDIRECTED(GetScriptByte);
    // REDIRECTED(BackupBGMapRow);
    // REDIRECTED(ReadWarps);
    // REDIRECTED(OverworldTextModeSwitch);
    // REDIRECTED(GetMapField);
    // REDIRECTED(CheckObjectMask);
    // REDIRECTED(GetCoordTile);
    // REDIRECTED(GetMovementPermissions);
    // REDIRECTED(GetMapConnections);
    // REDIRECTED(GetMapAttributesBank);
    // REDIRECTED(SwitchToAnyMapAttributesBank);
    // REDIRECTED(GetMapTimeOfDay);
    // REDIRECTED(CheckWarpTile);
    // REDIRECTED(GetMovementData);
    // REDIRECTED(GetPhoneServiceTimeOfDayByte);
    // REDIRECTED(GetCurrentMapSceneID);
    // REDIRECTED(ExitAllMenus);
    // REDIRECTED(CheckIfFacingTileCoordIsBGEvent);
    // REDIRECTED(ClearObjectStructs);
    // REDIRECTED(RunMapCallback);
    // REDIRECTED(GetAnyMapEnvironment);
    // REDIRECTED(LoadConnectionBlockData);
    // REDIRECTED(GetAnyMapField);
    // REDIRECTED(ClearUnusedMapBuffer);
    // REDIRECTED(CheckOutdoorMap);
    // REDIRECTED(LoadMapStatus);
    // REDIRECTED(CopyMapObjectEvents);
    // REDIRECTED(GetMapEnvironment);
    // REDIRECTED(MaskObject);
    // REDIRECTED(CopyWarpData);
    // REDIRECTED(LoadTilesetGFX);
    // REDIRECTED(CloseSubmenu);
    // REDIRECTED(CheckUnknownMap);
    // REDIRECTED(CallMapScript);
    // REDIRECTED(UnmaskObject);
    // REDIRECTED(ScrollMapUp);
    // REDIRECTED(LoadMapPart);
    // REDIRECTED(GetMapPhoneService);
    // REDIRECTED(FillSouthConnectionStrip);
    // REDIRECTED(ScrollMapDown);
    // REDIRECTED(GetMapConnection);
    // REDIRECTED(GetAnyMapBlocksBank);
    // REDIRECTED(ReadMapCallbacks);
    // REDIRECTED(CallScript);
    // REDIRECTED(CoordinatesEvent);
    // REDIRECTED(ReturnToMapWithSpeechTextbox);
    // REDIRECTED(FadeToMenu);
    // REDIRECTED(LoadBlockData);
    // REDIRECTED(DummyEndPredef);
    // REDIRECTED(CheckCurrentMapCoordEvents);
    // REDIRECTED(FillEastConnectionStrip);
    // REDIRECTED(WarpCheck);
    // REDIRECTED(ObjectEventText);

    // engine/pokegear/pokegear.c
    // REDIRECTED(PokegearMap_JohtoMap);
    // REDIRECTED(PokegearPhone_MakePhoneCall);
    // REDIRECTED(PokegearPressButtonText);
    // REDIRECTED(NoRadioMusic);
    //REDIRECTED(PhoneTilemapRLE);
    // REDIRECTED(PokegearAskDeleteText);
    // REDIRECTED(v_TownMap);
    //REDIRECTED(BuenasPasswordName);
    // REDIRECTED(Pokegear_FinishTilemap);
    // REDIRECTED(LoadStation_RocketRadio);
    REDIRECTED(PokeGear);
    // REDIRECTED(TownMapPlayerIcon);
    //REDIRECTED(NotBuenasPasswordName);
    // REDIRECTED(Radio_BackUpFarCallParams);
    // REDIRECTED(v_UpdateRadioStation);
    // REDIRECTED(PokegearMap_Init);
    // REDIRECTED(TownMapBubble);
    // REDIRECTED(Pokegear_InitJumptableIndices);
    // REDIRECTED(PokegearPhone_FinishPhoneCall);
    // REDIRECTED(PokegearPhoneContactSubmenu);
    //REDIRECTED(ClockTilemapRLE);
    // REDIRECTED(PokegearMap);
    //REDIRECTED(LetsAllSingName);
    // REDIRECTED(InitPokegearModeIndicatorArrow);
    // REDIRECTED(PokegearMap_KantoMap);
    // REDIRECTED(PokegearMap_InitPlayerIcon);
    // REDIRECTED(EntireFlyMap);
    // REDIRECTED(FillTownMap);
    // REDIRECTED(GetAMPMHours);
    // REDIRECTED(LoadStation_BuenasPassword);
    // REDIRECTED(LoadStation_PlacesAndPeople);
    //REDIRECTED(PlacesAndPeopleName);
    // REDIRECTED(PokegearPhone_GetDPad);
    // REDIRECTED(RadioMusicRestartPokemonChannel);
    // REDIRECTED(PokegearPhone_UpdateCursor);
    // REDIRECTED(PokegearMap_ContinueMap);
    // REDIRECTED(TownMap_InitCursorAndPlayerIconPositions);
    // REDIRECTED(PokegearMap_UpdateCursorPosition);
    // REDIRECTED(TownMap_GetKantoLandmarkLimits);
    // REDIRECTED(LoadStation_LuckyChannel);
    // REDIRECTED(PokegearPhone_DeletePhoneNumber);
    // REDIRECTED(NoRadioStation);
    REDIRECTED(Pokegear_UpdateClock);
    // REDIRECTED(CheckIfVisitedFlypoint);
    // REDIRECTED(PokegearSpritesGFX);
    // REDIRECTED(TownMapMon);
    // REDIRECTED(LoadStation_PokemonMusic);
    // REDIRECTED(PokegearRadio_Joypad);
    // REDIRECTED(LoadStation_LetsAllSing);
    //REDIRECTED(RadioChannels);
    // REDIRECTED(DummyLoadStation);
    // REDIRECTED(Pokegear_DummyFunction);
    // REDIRECTED(FlyMap);
    //REDIRECTED(PokeFluteStationName);
    //REDIRECTED(OaksPKMNTalkName);
    // REDIRECTED(TownMap_GetCurrentLandmark);
    // REDIRECTED(TownMapBGUpdate);
    // REDIRECTED(PokegearPhone_UpdateDisplayList);
    //REDIRECTED(Pokegear_LoadTilemapRLE);
    // REDIRECTED(PokegearPhone_Joypad);
    REDIRECTED(PokegearClock_Init);
    // REDIRECTED(JohtoMap);
    // REDIRECTED(PokegearPhone_Init);
    // REDIRECTED(AnimateTuningKnob);
    //REDIRECTED(LuckyChannelName);
    // REDIRECTED(Pokedex_GetArea);
    // REDIRECTED(FillJohtoMap);
    //REDIRECTED(RadioTilemapRLE);
    // REDIRECTED(v_FlyMap);
    //REDIRECTED(NoRadioName);
    //REDIRECTED(PokegearAskWhoCallText);
    // REDIRECTED(RadioMusicRestartDE);
    // REDIRECTED(PokegearMap_InitCursor);
    // REDIRECTED(PlayRadioStationPointers);
    // REDIRECTED(FillKantoMap);
    //REDIRECTED(UnownStationName);
    // REDIRECTED(PlayRadio);
    //REDIRECTED(FastShipGFX);
    // REDIRECTED(PokegearMap_UpdateLandmarkName);
    // REDIRECTED(Pokegear_SwitchPage);
    // REDIRECTED(LoadStation_OaksPokemonTalk);
    // REDIRECTED(HasVisitedSpawn);
    // REDIRECTED(DeleteSpriteAnimStruct2ToEnd);
    REDIRECTED(PokegearJumptable);
    // REDIRECTED(LoadStation_PokeFluteRadio);
    // REDIRECTED(LoadPokegearRadioChannelPointer);
    REDIRECTED(PokegearClock_Joypad);
    REDIRECTED(PokegearClock_Joypad_UpdateClock);
    // REDIRECTED(PokegearMap_CheckRegion);
    //REDIRECTED(PokemonMusicName);
    // REDIRECTED(LoadStation_PokedexShow);
    REDIRECTED(InitPokegearTilemap);
    //REDIRECTED(FlyMapLabelBorderGFX);
    // REDIRECTED(LoadStation_UnownRadio);
    // REDIRECTED(TownMapPals);
    // REDIRECTED(LoadStation_PokemonChannel);
    // REDIRECTED(LoadTownMapGFX);
    //REDIRECTED(KantoMap);
    // REDIRECTED(AnimatePokegearModeIndicatorArrow);
    // REDIRECTED(ExitPokegearRadio_HandleMusic);
    // REDIRECTED(Pokegear_LoadGFX);
    //REDIRECTED(PokedexShowName);
    // REDIRECTED(PokegearRadio_Init);
    //REDIRECTED(PokedexNestIconGFX);
    // REDIRECTED(UpdateRadioStation);
    // REDIRECTED(GetMapCursorCoordinates);
    // REDIRECTED(LoadStation_EvolutionRadio);
    REDIRECTED(PokeGear_InitTilemap);

    // engine/overworld/wildmons.c
    // REDIRECTED(CheckEncounterRoamMon);
    // REDIRECTED(LoadWildMonDataPointer);
    // REDIRECTED(ChooseWildEncounter);
    // REDIRECTED(CheckRepelEffect);
    // REDIRECTED(GetMapEncounterRate);
    // REDIRECTED(TryWildEncounter);
    // REDIRECTED(RandomPhoneWildMon);
    // REDIRECTED(v_NoSwarmWildmon);
    // REDIRECTED(UpdateRoamMons);
    // REDIRECTED(LoadWildMonData);
    // REDIRECTED(RandomPhoneMon);
    // REDIRECTED(LookUpWildmonsForMapDE);
    // REDIRECTED(JumpRoamMon);
    // REDIRECTED(JumpRoamMons);
    // REDIRECTED(v_SwarmWildmonCheck);
    // REDIRECTED(ApplyMusicEffectOnEncounterRate);
    // REDIRECTED(v_JohtoWildmonCheck);
    // REDIRECTED(CopyCurrMapDE);
    // REDIRECTED(ValidateTempWildMonSpecies);
    // REDIRECTED(ApplyCleanseTagEffectOnEncounterRate);
    // REDIRECTED(FindNest);
    // REDIRECTED(InitRoamMons);
    // REDIRECTED(v_GrassWildmonLookup);
    // REDIRECTED(v_NormalWildmonOK);
    // REDIRECTED(RandomUnseenWildMon);
    // REDIRECTED(v_WaterWildmonLookup);
    // REDIRECTED(v_BackUpMapIndices);

    // engine/battle/core.c
    // REDIRECTED(HandleHPHealingItem);
    // REDIRECTED(SubtractHP);
    // REDIRECTED(DisplayLinkBattleResult);
    // REDIRECTED(GetHalfHP);
    // REDIRECTED(ExitBattle);
    // REDIRECTED(GetPartyMonDVs);
    // REDIRECTED(PrintPlayerHUD);
    // REDIRECTED(EndUserDestinyBond);
    // REDIRECTED(CheckContestBattleOver);
    // REDIRECTED(HandleBetweenTurnEffects);
    // REDIRECTED(UpdateBattleHUDs);
    // REDIRECTED(LoadHPExpBarGFX);
    // REDIRECTED(CheckWhetherSwitchmonIsPredetermined);
    // REDIRECTED(CleanUpBattleRAM);
    // REDIRECTED(Battle_DummyFunction);
    // REDIRECTED(CheckIfCurPartyMonIsFitToFight);
    // REDIRECTED(FillEnemyMovesFromMoveIndicesBuffer);
    // REDIRECTED(PlayerMonFaintedAnimation);
    // REDIRECTED(SendOutPlayerMon);
    // REDIRECTED(BattleMenu_PKMN);
    // REDIRECTED(EndOpponentProtectEndureDestinyBond);
    // REDIRECTED(GetRoamMonMapGroup);
    // REDIRECTED(BoostStat);
    // REDIRECTED(SwapBattlerLevels);
    // REDIRECTED(DropEnemySub);
    // REDIRECTED(UseHeldStatusHealingItem);
    // REDIRECTED(ScoreMonTypeMatchups);
    // REDIRECTED(OfferSwitch);
    // REDIRECTED(ApplyBrnEffectOnAttack);
    // REDIRECTED(DoBattle);
    // REDIRECTED(PlayerPartyMonEntrance);
    // REDIRECTED(PursuitSwitch);
    // REDIRECTED(CompareMovePriority);
    // REDIRECTED(ParsePlayerAction);
    // REDIRECTED(IsGymLeaderCommon);
    // REDIRECTED(AddBattleMoneyToAccount);
    // REDIRECTED(StartBattle);
    // REDIRECTED(Battle_EnemyFirst);
    // REDIRECTED(InitBattleMon);
    // REDIRECTED(IsMobileBattle);
    // REDIRECTED(v_LoadHPBar);
    // REDIRECTED(SwitchMonAlreadyOut);
    // REDIRECTED(CallDoBattle);
    // REDIRECTED(MoveSelectionScreen);
    // REDIRECTED(ComeBackText);
    // REDIRECTED(MoveInfoBox);
    // REDIRECTED(SwitchPlayerMon);
    // REDIRECTED(CheckDanger);
    // REDIRECTED(PassedBattleMonEntrance);
    // REDIRECTED(HandleHealingItems);
    // REDIRECTED(CheckEnemyLockedIn);
    // REDIRECTED(PlayerSwitch);
    // REDIRECTED(YourFoesWeakGetmMonText);
    // REDIRECTED(EnemyMonEntrance);
    // REDIRECTED(IsKantoGymLeader);
    // REDIRECTED(SelectBattleMon);
    // REDIRECTED(HandlePlayerMonFaint);
    // REDIRECTED(GoMonText);
    // REDIRECTED(ResidualDamage);
    // REDIRECTED(BattleStartMessage);
    // REDIRECTED(EnemySwitch);
    // REDIRECTED(BattleTurn);
    // REDIRECTED(EnemyTurn_EndOpponentProtectEndureDestinyBond);
    // REDIRECTED(GetSixteenthMaxHP);
    // REDIRECTED(GetMaxHP);
    // REDIRECTED(PickSwitchMonInBattle);
    // REDIRECTED(FinishBattleAnim);
    // REDIRECTED(BattleMenu);
    // REDIRECTED(UpdateHPBar);
    // REDIRECTED(CheckSleepingTreeMon);
    // REDIRECTED(CheckUserHasEnoughHP);
    // REDIRECTED(LoadTrainerOrWildMonPic);
    // REDIRECTED(BattleWinSlideInEnemyTrainerFrontpic);
    // REDIRECTED(PickPartyMonInBattle);
    // REDIRECTED(AskUseNextPokemon);
    // REDIRECTED(HandlePerishSong);
    // REDIRECTED(ResetEnemyStatLevels);
    // REDIRECTED(ShowSetEnemyMonAndSendOutAnimation);
    // REDIRECTED(ExpPointsText);
    // REDIRECTED(PlayerTurn_EndOpponentProtectEndureDestinyBond);
    // REDIRECTED(UseConfusionHealingItem);
    // REDIRECTED(BadgeStatBoosts);
    // REDIRECTED(DrawEnemyHUD);
    // REDIRECTED(CheckEnemyTrainerDefeated);
    // REDIRECTED(SubtractHPFromTarget);
    // REDIRECTED(HasUserFainted);
    // REDIRECTED(ResetPlayerStatLevels);
    // REDIRECTED(ReadAndPrintLinkBattleRecord);
    // REDIRECTED(BreakAttraction);
    // REDIRECTED(FillInExpBar);
    // REDIRECTED(GetHalfMaxHP);
    // REDIRECTED(GetPartymonItem);
    // REDIRECTED(ThatsEnoughComeBackText);
    // REDIRECTED(InitEnemyWildmon);
    // REDIRECTED(ResetVarsForSubstatusRage);
    // REDIRECTED(DoItMonText);
    // REDIRECTED(GetRoamMonHP);
    // REDIRECTED(ApplyStatLevelMultiplier);
    // REDIRECTED(DropPlayerSub);
    // REDIRECTED(BattleMonNicknameText);
    // REDIRECTED(HasPlayerFainted);
    // REDIRECTED(DrawPlayerHUD);
    // REDIRECTED(GetTrainerBackpic);
    // REDIRECTED(GetRoamMonDVs);
    // REDIRECTED(HandleScreens);
    // REDIRECTED(HandleDefrost);
    // REDIRECTED(SwitchTurnCore);
    // REDIRECTED(CheckPlayerPartyForFitMon);
    // REDIRECTED(ItemRecoveryAnim);
    // REDIRECTED(ShowLinkBattleParticipantsAfterEnd);
    // REDIRECTED(UpdateBattleStateAndExperienceAfterEnemyFaint);
    // REDIRECTED(GetRoamMonMapNumber);
    // REDIRECTED(RecallPlayerMon);
    // REDIRECTED(NewBattleMonStatus);
    // REDIRECTED(AddBattleParticipant);
    // REDIRECTED(LoadEnemyMonToSwitchTo);
    // REDIRECTED(InitEnemyTrainer);
    // REDIRECTED(UpdateHPBarBattleHuds);
    // REDIRECTED(LoadEnemyMon);
    // REDIRECTED(LoadBattleMenu2);
    // REDIRECTED(SendOutMonText);
    // REDIRECTED(TextJump_ComeBack);
    // REDIRECTED(CheckMobileBattleError);
    // REDIRECTED(GetOTPartymonItem);
    // REDIRECTED(BoostedExpPointsText);
    // REDIRECTED(HandleSafeguard);
    // REDIRECTED(JumpToPartyMenuAndPrintText);
    // REDIRECTED(CheckPayDay);
    // REDIRECTED(FindMonInOTPartyToSwitchIntoBattle);
    // REDIRECTED(GetEnemyMonFrontpic);
    // REDIRECTED(BoostExp);
    // REDIRECTED(ApplyPrzEffectOnSpeed);
    // REDIRECTED(Battle_PlayerFirst);
    // REDIRECTED(FaintEnemyPokemon);
    // REDIRECTED(ApplyStatusEffectOnEnemyStats);
    // REDIRECTED(HandleMysteryberry);
    // REDIRECTED(RestoreHP);
    // REDIRECTED(BattleMenu_Run);
    // REDIRECTED(GoForItMonText);
    // REDIRECTED(ParseEnemyAction);
    // REDIRECTED(GetEighthMaxHP);
    // REDIRECTED(SetUpBattlePartyMenu);
    // REDIRECTED(InitEnemyMon);
    // REDIRECTED(CopyBackpic);
    // REDIRECTED(IsThePlayerMonTypesEffectiveAgainstOTMon);
    // REDIRECTED(SetUpBattlePartyMenu_Loop);
    // REDIRECTED(BattleEnd_HandleRoamMons);
    // REDIRECTED(HandleEncore);
    // REDIRECTED(ForcePlayerMonChoice);
    // REDIRECTED(NewEnemyMonStatus);
    // REDIRECTED(AddLastLinkBattleToLinkRecord);
    // REDIRECTED(BackUpBGMap2);
    // REDIRECTED(BattleMenuPKMN_Loop);
    // REDIRECTED(Call_PlayBattleAnim_OnlyIfVisible);
    // REDIRECTED(GetMoveEffect);
    // REDIRECTED(EnemyMonFaintedAnimation);
    // REDIRECTED(ShowBattleTextEnemySentOut);
    // REDIRECTED(SpikesDamage);
    // REDIRECTED(BattleMonEntrance);
    // REDIRECTED(WithdrawMonText);
    // REDIRECTED(CheckIfHPIsZero);
    // REDIRECTED(HandleLeftovers);
    // REDIRECTED(ApplyStatusEffectOnStats);
    // REDIRECTED(CheckPlayerLockedIn);
    // REDIRECTED(UpdatePlayerHPPal);
    // REDIRECTED(CheckUnownLetter);
    // REDIRECTED(HandleFutureSight);
    // REDIRECTED(Text_MonGainedExpPoint);
    // REDIRECTED(IsGymLeader);
    // REDIRECTED(LinkBattleSendReceiveAction);
    // REDIRECTED(InitEnemy);
    // REDIRECTED(BattleCheckShininess);
    // REDIRECTED(v_BattleRandom);
    // REDIRECTED(ForcePickSwitchMonInBattle);
    // REDIRECTED(HandleWrap);
    // REDIRECTED(GiveExperiencePoints);
    // REDIRECTED(CheckPlayerHasUsableMoves);
    // REDIRECTED(Call_PlayBattleAnim);
    // REDIRECTED(LostBattle);
    // REDIRECTED(HandleWeather);
    // REDIRECTED(TryPlayerSwitch);
    // REDIRECTED(BattleMenu_Fight);
    // REDIRECTED(GoodComeBackText);
    // REDIRECTED(IsAnyMonHoldingExpShare);
    // REDIRECTED(HandleEnemySwitch);
    // REDIRECTED(HandleStatBoostingHeldItems);
    // REDIRECTED(CheckFaint_PlayerThenEnemy);
    // REDIRECTED(ForcePickPartyMonInBattle);
    // REDIRECTED(UpdateEnemyHPPal);
    // REDIRECTED(PlaceExpBar);
    // REDIRECTED(BattleCheckPlayerShininess);
    // REDIRECTED(GetEnemyMonDVs);
    // REDIRECTED(EmptyBattleTextbox);
    // REDIRECTED(BattleIntro);
    // REDIRECTED(HasEnemyFainted);
    // REDIRECTED(EnemyPartyMonEntrance);
    // REDIRECTED(GetBattleMonBackpic_DoAnim);
    // REDIRECTED(StopDangerSound);
    // REDIRECTED(UpdateFaintedPlayerMon);
    // REDIRECTED(ResetEnemyBattleVars);
    // REDIRECTED(PlayVictoryMusic);
    // REDIRECTED(UseOpponentItem);
    // REDIRECTED(CheckWhetherToAskSwitch);
    // REDIRECTED(TryEnemyFlee);
    // REDIRECTED(AnimateExpBar);
    // REDIRECTED(DoubleSwitch);
    // REDIRECTED(Battle_StatsScreen);
    // REDIRECTED(WildFled_EnemyFled_LinkBattleCanceled);
    // REDIRECTED(EnemySwitch_SetMode);
    // REDIRECTED(ClearEnemyMonBox);
    // REDIRECTED(Stubbed_Increments5_a89a);
    // REDIRECTED(BattleCheckEnemyShininess);
    // REDIRECTED(MonFaintedAnimation);
    // REDIRECTED(WinTrainerBattle);
    // REDIRECTED(EnemyTriesToFlee);
    // REDIRECTED(CheckFaint_EnemyThenPlayer);
    // REDIRECTED(TryToRunAwayFromBattle);
    // REDIRECTED(UpdateHPPal);
    // REDIRECTED(BattleMenuPKMN_ReturnFromStats);
    // REDIRECTED(PrepareBattleMonNicknameText);
    // REDIRECTED(GetEnemyMonFrontpic_DoAnim);
    // REDIRECTED(SubtractHPFromUser);
    // REDIRECTED(GetQuarterMaxHP);
    // REDIRECTED(HandleBerserkGene);
    // REDIRECTED(OKComeBackText);
    // REDIRECTED(FaintYourPokemon);
    // REDIRECTED(LookUpTheEffectivenessOfEveryMove);
    // REDIRECTED(UpdatePlayerHUD);
    // REDIRECTED(HandleEnemyMonFaint);
    // REDIRECTED(UpdateEnemyHUD);
    // REDIRECTED(GetMovePriority);
    // REDIRECTED(CalcExpBar);
    // REDIRECTED(GetRoamMonSpecies);
    // REDIRECTED(ApplyStatusEffectOnPlayerStats);
    // REDIRECTED(v_LoadBattleFontsHPBar);
    // REDIRECTED(InitBattleDisplay);
    // REDIRECTED(DetermineMoveOrder);
    // REDIRECTED(ApplyStatLevelMultiplierOnAllStats);
    // REDIRECTED(SlideBattlePicOut);
    // REDIRECTED(BattleMenu_Pack);
    // REDIRECTED(ForceEnemySwitch);
    // REDIRECTED(ResetBattleParticipants);
    // REDIRECTED(IsMobileBattle2);
    // REDIRECTED(GetBattleMonBackpic);
    // REDIRECTED(HandleSafariAngerEatingStatus);
    // REDIRECTED(CheckAmuletCoin);
    // REDIRECTED(v_DisplayLinkRecord);

    // engine/movie/intro.c
    REDIRECTED(IntroScene27);
    // REDIRECTED(IntroGrass4GFX);
    // REDIRECTED(IntroSuicuneCloseTilemap);
    REDIRECTED(IntroScene6);
    // REDIRECTED(IntroPichuWooperGFX);
    // REDIRECTED(IntroSuicuneClosePalette);
    // REDIRECTED(IntroUnownHIAttrmap);
    // REDIRECTED(IntroCrystalUnownsTilemap);
    REDIRECTED(IntroScene24);
    REDIRECTED(Intro_ColoredSuicuneFrameSwap);
    CONVERTED(CrystalIntro);
    REDIRECTED(Intro_PerspectiveScrollBG);
    // REDIRECTED(IntroUnownHITilemap);
    REDIRECTED(IntroScene15);
    REDIRECTED(Intro_Scene16_AnimateSuicune);
    // REDIRECTED(IntroCrystalUnownsGFX);
    REDIRECTED(Intro_FadeUnownWordPals);
    REDIRECTED(IntroScene9);
    REDIRECTED(IntroScene2);
    // REDIRECTED(IntroGrass3GFX);
    REDIRECTED(IntroScene28);
    // REDIRECTED(IntroScenes);
    REDIRECTED(IntroScene8);
    // REDIRECTED(IntroUnownAAttrmap);
    // REDIRECTED(IntroSuicuneBackAttrmap);
    REDIRECTED(CrystalIntro_InitUnownAnim);
    // REDIRECTED(IntroUnownsGFX);
    REDIRECTED(IntroScene1);
    REDIRECTED(IntroScene12);
    REDIRECTED(IntroScene13);
    // REDIRECTED(IntroUnownATilemap);
    // REDIRECTED(IntroUnownBackGFX);
    REDIRECTED(Intro_DecompressRequest2bpp_255Tiles);
    // REDIRECTED(IntroCrystalUnownsPalette);
    REDIRECTED(IntroScene7);
    REDIRECTED(IntroScene25);
    // REDIRECTED(IntroBackgroundTilemap);
    REDIRECTED(IntroScene4);
    REDIRECTED(Intro_Scene20_AppearUnown);
    REDIRECTED(Intro_DecompressRequest2bpp_64Tiles);
    REDIRECTED(IntroScene21);
    REDIRECTED(IntroScene3);
    // REDIRECTED(IntroSuicuneJumpTilemap);
    REDIRECTED(IntroScene5);
    // REDIRECTED(IntroGrass2GFX);
    REDIRECTED(Intro_DecompressRequest2bpp_128Tiles);
    // REDIRECTED(IntroUnownsAttrmap);
    REDIRECTED(Intro_ClearBGPals);
    // REDIRECTED(IntroSuicuneBackGFX);
    REDIRECTED(IntroScene22);
    REDIRECTED(Intro_Scene24_ApplyPaletteFade);
    // REDIRECTED(IntroUnownsPalette);
    REDIRECTED(IntroScene20);
    // REDIRECTED(IntroSuicuneJumpGFX);
    // REDIRECTED(IntroSuicunePalette);
    // REDIRECTED(IntroSuicuneJumpAttrmap);
    // REDIRECTED(IntroGrass1GFX);
    REDIRECTED(IntroScene10);
    REDIRECTED(CrystalIntro_UnownFade);
    REDIRECTED(IntroScene19);
    REDIRECTED(Intro_LoadTilemap);
    // REDIRECTED(IntroSuicuneRunGFX);
    // REDIRECTED(IntroBackgroundGFX);
    // REDIRECTED(Intro_RustleGrass);
    // REDIRECTED(IntroSceneJumper);
    REDIRECTED(IntroScene26);
    // REDIRECTED(IntroUnownsTilemap);
    // REDIRECTED(IntroCrystalUnownsAttrmap);
    REDIRECTED(NextIntroScene);
    // REDIRECTED(IntroBackgroundAttrmap);
    REDIRECTED(IntroScene11);
    REDIRECTED(IntroScene16);
    REDIRECTED(IntroScene18);
    REDIRECTED(Intro_SetCGBPalUpdate);
    REDIRECTED(Intro_ResetLYOverrides);
    // REDIRECTED(IntroBackgroundPalette);
    // REDIRECTED(IntroSuicuneCloseAttrmap);
    // REDIRECTED(IntroPulseGFX);
    REDIRECTED(IntroScene23);
    // REDIRECTED(IntroSuicuneBackTilemap);
    REDIRECTED(IntroScene17);
    // REDIRECTED(IntroSuicuneCloseGFX);
    REDIRECTED(IntroScene14);

    // engine/pokegear/radio.c
    REDIRECTED(OaksPKMNTalk12);
    REDIRECTED(LuckyNumberShow7);
    REDIRECTED(BuenasPassword6);
    // REDIRECTED(LC_DragText1);
    REDIRECTED(PokedexShow2);
    REDIRECTED(BenFernMusic5);
    REDIRECTED(LuckyNumberShow1);
    REDIRECTED(LuckyNumberShow4);
    REDIRECTED(PeoplePlaces5);
    REDIRECTED(PokedexShow1);
    // REDIRECTED(PnP_Text3);
    // REDIRECTED(RocketRadioText2);
    // REDIRECTED(RocketRadioText9);
    // REDIRECTED(BenFernText3A);
    REDIRECTED(EvolutionRadio);
    REDIRECTED(PlayRadioShow);
    // REDIRECTED(PnP_Text5);
    // REDIRECTED(BuenaRadioMidnightText10);
    REDIRECTED(BenMonMusic1);
    REDIRECTED(BuenasPassword4);
    REDIRECTED(BenMonMusic3);
    // REDIRECTED(RocketRadioText7);
    REDIRECTED(LuckyNumberShow14);
    REDIRECTED(LuckyNumberShow9);
    // REDIRECTED(LC_Text7);
    // REDIRECTED(PnP_PickyText);
    REDIRECTED(ReplacePeriodsWithSpaces);
    REDIRECTED(RocketRadio8);
    // REDIRECTED(OPT_IntroText3);
    REDIRECTED(OaksPKMNTalk7);
    // REDIRECTED(RocketRadioText1);
    REDIRECTED(NextRadioLine);
    REDIRECTED(RocketRadio5);
    REDIRECTED(BuenasPassword20);
    REDIRECTED(PokedexShow3);
    REDIRECTED(PeoplePlaces3);
    REDIRECTED(RadioScroll);
    REDIRECTED(CopyDexEntryPart1);
    REDIRECTED(BuenasPassword7);
    REDIRECTED(PeoplePlaces4);
    REDIRECTED(LuckyNumberShow12);
    REDIRECTED(OaksPKMNTalk11);
    // REDIRECTED(BuenaRadioMidnightText7);
    REDIRECTED(LuckyNumberShow6);
    REDIRECTED(CopyDexEntryPart2);
    REDIRECTED(BuenasPassword21);
    REDIRECTED(PeoplePlaces6);
    // REDIRECTED(RocketRadioText5);
    // REDIRECTED(BuenaRadioMidnightText3);
    REDIRECTED(BenFernMusic7);
    // REDIRECTED(PnP_HappyText);
    REDIRECTED(BuenasPassword14);
    // REDIRECTED(LC_Text10);
    // REDIRECTED(PnP_PrecociousText);
    // REDIRECTED(PnP_SortOfOKText);
    REDIRECTED(RocketRadio6);
    REDIRECTED(PokedexShow_GetDexEntryBank);
    REDIRECTED(ClearBottomLine);
    // REDIRECTED(OPT_IntroText2);
    REDIRECTED(CopyDexEntry);
    // REDIRECTED(BuenaRadioText6);
    // REDIRECTED(PnP_MyTypeText);
    // REDIRECTED(LC_Text1);
    REDIRECTED(RadioJumptable);
    // REDIRECTED(PnP_InspiringText);
    // REDIRECTED(PnP_RightForMeText);
    REDIRECTED(PrintRadioLine);
    REDIRECTED(BuenasPassword15);
    REDIRECTED(BuenasPassword9);
    // REDIRECTED(OPT_IntroText1);
    REDIRECTED(BuenasPasswordChannelName);
    REDIRECTED(BuenasPassword18);
    REDIRECTED(OaksPKMNTalk4);
    REDIRECTED(PeoplePlaces2);
    REDIRECTED(LuckyNumberShow10);
    REDIRECTED(OaksPKMNTalk13);
    REDIRECTED(OaksPKMNTalk5);
    REDIRECTED(OaksPKMNTalk9);
    // REDIRECTED(PnP_CuteText);
    // REDIRECTED(OPT_OakText2);
    // REDIRECTED(BenFernText2A);
    REDIRECTED(RocketRadioText8);
    REDIRECTED(RocketRadio4);
    REDIRECTED(OaksPKMNTalk2);
    REDIRECTED(BuenasPasswordAfterMidnight);
    // REDIRECTED(LC_Text3);
    // REDIRECTED(PnP_NoisyText);
    REDIRECTED(PokedexShow6);
    REDIRECTED(OaksPKMNTalk10);
    // REDIRECTED(PnP_SoSoText);
    REDIRECTED(BuenasPassword1);
    REDIRECTED(OaksPKMNTalk8);
    // REDIRECTED(BuenaRadioMidnightText2);
    // REDIRECTED(BuenaRadioMidnightText6);
    REDIRECTED(LuckyNumberShow8);
    // REDIRECTED(LC_Text5);
    // REDIRECTED(PnP_GreatText);
    REDIRECTED(FernMonMusic2);
    REDIRECTED(StartPokemonMusicChannel);
    REDIRECTED(OaksPKMNTalk3);
    // REDIRECTED(LC_Text4);
    REDIRECTED(RocketRadio1);
    REDIRECTED(RocketRadio3);
    REDIRECTED(LuckyNumberShow2);
    REDIRECTED(LuckyNumberShow15);
    REDIRECTED(RocketRadio9);
    REDIRECTED(PokedexShow7);
    REDIRECTED(BuenasPassword13);
    // REDIRECTED(BenFernText1);
    // REDIRECTED(LC_Text9);
    // REDIRECTED(BuenaRadioMidnightText8);
    // REDIRECTED(BenIntroText1);
    REDIRECTED(LuckyNumberShow13);
    // REDIRECTED(LC_Text6);
    REDIRECTED(LuckyNumberShow11);
    // REDIRECTED(PnP_LazyText);
    // REDIRECTED(PnP_Text1);
    REDIRECTED(BenMonMusic2);
    // REDIRECTED(LC_DragText2);
    // REDIRECTED(BuenaRadioMidnightText1);
    // REDIRECTED(BuenaRadioMidnightText5);
    REDIRECTED(OaksPKMNTalk1);
    REDIRECTED(PokedexShow8);
    // REDIRECTED(PokedexShowText);
    REDIRECTED(BenFernMusic4);
    REDIRECTED(StartRadioStation);
    REDIRECTED(PokeFluteRadio);
    // REDIRECTED(OPT_OakText3);
    REDIRECTED(GetBuenasPassword);
    // REDIRECTED(BenFernText3B);
    REDIRECTED(LuckyNumberShow5);
    // REDIRECTED(PnP_WeirdText);
    REDIRECTED(PeoplePlaces7);
    // REDIRECTED(RocketRadioText3);
    REDIRECTED(BuenasPassword8);
    REDIRECTED(BuenasPassword3);
    // REDIRECTED(FernIntroText2);
    // REDIRECTED(BuenaOffTheAirText);
    // REDIRECTED(BuenaRadioMidnightText9);
    REDIRECTED(FernMonMusic1);
    REDIRECTED(PokedexShow4);
    REDIRECTED(BuenasPassword19);
    // REDIRECTED(OPT_PokemonChannelText);
    REDIRECTED(BuenasPassword12);
    REDIRECTED(BuenasPasswordCheckTime);
    // REDIRECTED(BuenaRadioText5);
    REDIRECTED(BuenasPassword11);
    // REDIRECTED(PnP_Text4);
    REDIRECTED(BuenasPassword5);
    // REDIRECTED(BuenaRadioText3);
    // REDIRECTED(FernIntroText1);
    // REDIRECTED(BuenaRadioText1);
    // REDIRECTED(RocketRadioText4);
    // REDIRECTED(BenFernText2B);
    REDIRECTED(RocketRadio10);
    // REDIRECTED(BuenaRadioText4);
    REDIRECTED(PokedexShow5);
    // REDIRECTED(BuenaRadioText2);
    REDIRECTED(UnownRadio);
    // REDIRECTED(LC_Text2);
    // REDIRECTED(OPT_RestartText);
    REDIRECTED(OaksPKMNTalk6);
    // REDIRECTED(PnP_OddText);
    // REDIRECTED(PnP_CoolText);
    REDIRECTED(RocketRadio2);
    // REDIRECTED(LC_Text8);
    // REDIRECTED(BuenaRadioMidnightText4);
    REDIRECTED(BuenasPassword16);
    // REDIRECTED(LC_Text11);
    REDIRECTED(OaksPKMNTalk14);
    REDIRECTED(LuckyNumberShow3);
    // REDIRECTED(OPT_MaryText1);
    REDIRECTED(BuenasPassword2);
    REDIRECTED(CopyBottomLineToTopLine);
    REDIRECTED(BenFernMusic6);
    // REDIRECTED(CopyRadioTextToRAM);
    // REDIRECTED(PnP_BoldText);
    // REDIRECTED(BenIntroText2);
    REDIRECTED(BuenasPassword10);
    REDIRECTED(BuenasPassword17);
    // REDIRECTED(OPT_OakText1);
    REDIRECTED(PeoplePlaces1);
    // REDIRECTED(RocketRadioText10);
    // REDIRECTED(PnP_Text2);
    REDIRECTED(PlaceRadioString);
    // REDIRECTED(RocketRadioText6);
    // REDIRECTED(BenIntroText3);
    REDIRECTED(RocketRadio7);
    // REDIRECTED(BuenaRadioText7);

    // engine/battle_anims/core.c
    REDIRECTED(v_QueueBGEffect);
    REDIRECTED(InitBattleAnimation);
    REDIRECTED(GetBattleAnimTileOffset);
    REDIRECTED(InitBattleAnimBuffer);
    REDIRECTED(DeinitBattleAnimation);
    REDIRECTED(BattleAnimOAMUpdate);
    REDIRECTED(v_ExecuteBGEffects);
    REDIRECTED(QueueBattleAnimation);

    // engine/battle/battle_transition.c
    REDIRECTED(StartTrainerBattle_ZoomToBlack);
    REDIRECTED(StartTrainerBattle_NextScene);
    REDIRECTED(BattleTransitionJumptable);
    REDIRECTED(StartTrainerBattle_SetUpForSpinOutro);
    REDIRECTED(DoBattleTransition);
    REDIRECTED(PokeBallTransition);
    REDIRECTED(StartTrainerBattle_SetUpBGMap);
    REDIRECTED(StartTrainerBattle_Flash);
    REDIRECTED(StartTrainerBattle_Finish);
    REDIRECTED(StartTrainerBattle_SpinToBlack);
    REDIRECTED(TrainerBattlePokeballTiles);
    REDIRECTED(StartTrainerBattle_SineWave);
    REDIRECTED(UnusedWaitBGMapOnce);
    REDIRECTED(ConvertTrainerBattlePokeballTilesTo2bpp);
    REDIRECTED(StartTrainerBattle_DetermineWhichAnimation);
    REDIRECTED(StartTrainerBattle_SetUpForWavyOutro);
    REDIRECTED(StartTrainerBattle_SpeckleToBlack);
    REDIRECTED(WipeLYOverrides);
    REDIRECTED(StartTrainerBattle_DrawSineWave);
    REDIRECTED(StartTrainerBattle_SetUpForRandomScatterOutro);
    REDIRECTED(StartTrainerBattle_LoadPokeBallGraphics);
    REDIRECTED(LoadTrainerBattlePokeballTiles);

    // engine/menus/main_menu.c
    // REDIRECTED(MainMenuItems);
    // REDIRECTED(ClearTilemapEtc);
    // REDIRECTED(MainMenu_Continue);
    // REDIRECTED(MainMenu_Option);
    // REDIRECTED(MainMenu_MysteryGift);
    // REDIRECTED(MainMenuJoypadLoop);
    // REDIRECTED(MainMenu_PrintCurrentTimeAndDay);
    // REDIRECTED(MobileMenuGFX);
    // REDIRECTED(MainMenu_GetWhichMenu);
    // REDIRECTED(MainMenu);
    // REDIRECTED(MainMenu_NewGame);

    // engine/phone/phone.c
    // REDIRECTED(HangUp_Beep);
    // REDIRECTED(SpecialCallOnlyWhenOutside);
    // REDIRECTED(Phone_FindOpenSlot);
    // REDIRECTED(Phone_StartRinging);
    // REDIRECTED(HangUp_Wait20Frames);
    // REDIRECTED(v_CheckCellNum);
    // REDIRECTED(PhoneThankYouText);
    // REDIRECTED(PhoneEllipseText);
    // REDIRECTED(GetRemainingSpaceInPhoneList);
    // REDIRECTED(SpecialCallWhereverYouAre);
    // REDIRECTED(Script_SpecialElmCall);
    // REDIRECTED(HangUp_BoopOff);
    // REDIRECTED(LoadCallerScript);
    // REDIRECTED(WrongNumber);
    // REDIRECTED(PhoneOutOfAreaScript);
    // REDIRECTED(LoadOutOfAreaScript);
    // REDIRECTED(GetCallerClassAndName);
    // REDIRECTED(HangUp_BoopOn);
    // REDIRECTED(HangUp_ShutDown);
    // REDIRECTED(CheckCellNum);
    // REDIRECTED(CheckPhoneCall);
    // REDIRECTED(MakePhoneCallFromPokegear);
    // REDIRECTED(Phone_Wait20Frames);
    // REDIRECTED(Phone_GetTrainerClassName);
    // REDIRECTED(DelCellNum);
    // REDIRECTED(Phone_GetTrainerName);
    // REDIRECTED(CheckSpecialPhoneCall);
    // REDIRECTED(HangUp);
    // REDIRECTED(AddPhoneNumber);
    // REDIRECTED(Phone_CallerTextbox);
    // REDIRECTED(GetCallerTrainerClass);
    // REDIRECTED(PhoneJustTalkToThemText);
    // REDIRECTED(Phone_TextboxWithName);
    // REDIRECTED(ChooseRandomCaller);
    // REDIRECTED(Script_SpecialBillCall);
    // REDIRECTED(LoadPhoneScriptBank);
    // REDIRECTED(PhoneOutOfAreaText);
    // REDIRECTED(PhoneClickText);
    // REDIRECTED(RingTwice_StartCall);
    // REDIRECTED(PhoneThankYouTextScript);
    // REDIRECTED(BrokenPlaceFarString);
    // REDIRECTED(CheckPhoneContactTimeOfDay);
    // REDIRECTED(PhoneCall);
    // REDIRECTED(GetAvailableCallers);
    // REDIRECTED(Phone_NoSignal);
    // REDIRECTED(GetCallerName);
    // REDIRECTED(Phone_CallEnd);
    // REDIRECTED(Script_ReceivePhoneCall);
    // REDIRECTED(CheckCanDeletePhoneNumber);
    // REDIRECTED(GetCallerLocation);
    // REDIRECTED(PhoneScript_JustTalkToThem);

    // engine/gfx/sprites.c
    // REDIRECTED(ClearSpriteAnims);
    // REDIRECTED(PlaySpriteAnimationsAndDelayFrame);
    // REDIRECTED(DoNextFrameForFirst16Sprites);
    // REDIRECTED(GetSpriteAnimFrame);
    // REDIRECTED(InitSpriteAnimBuffer);
    // REDIRECTED(AnimateEndOfExpBar);
    //REDIRECTED(Sprites_Sine);
    // REDIRECTED(UpdateAnimFrame);
    // REDIRECTED(AddOrSubtractX);
    //REDIRECTED(Sprites_Cosine);
    // REDIRECTED(DeinitializeAllSprites);
    // REDIRECTED(v_ReinitSpriteAnimFrame);
    // REDIRECTED(v_InitSpriteAnimStruct);
    // REDIRECTED(PlaySpriteAnimations);
    // REDIRECTED(GetSpriteOAMAttr);
    // REDIRECTED(DoNextFrameForAllSprites);
    // REDIRECTED(GetSpriteAnimVTile);
    // REDIRECTED(GetFrameOAMPointer);
    // REDIRECTED(SGBEndOfExpBarGFX);
    // REDIRECTED(ClearSpriteAnims2);
    // REDIRECTED(UnusedLoadSpriteAnimGFX);
    // REDIRECTED(EndOfExpBarGFX);
    // REDIRECTED(DeinitializeSprite);
    // REDIRECTED(AddOrSubtractY);

    // engine/gfx/sprite_anims.c
    // REDIRECTED(AnimSeq_PartyMonSwitch);
    // REDIRECTED(AnimSeq_FlyLeaf);
    // REDIRECTED(AnimSeq_NamingScreenCursor);
    // REDIRECTED(AnimSeq_IntroUnownF);
    // REDIRECTED(AnimSeq_MemoryGameCursor);
    // REDIRECTED(AnimSeq_MailCursor);
    // REDIRECTED(AnimSeq_GSGameFreakLogoStar);
    // REDIRECTED(AnimSeq_GSIntroHoOhLugia);
    // REDIRECTED(AnimSeq_EZChatCursor);
    // REDIRECTED(AnimSeqs_Cosine);
    // REDIRECTED(AnimSeqs_Sine);
    // REDIRECTED(AnimSeq_TradeTubeBulge);
    // REDIRECTED(AnimSeq_TrademonInTube);
    // REDIRECTED(AnimSeq_Celebi);
    // REDIRECTED(AnimSeq_GSGameFreakLogoSparkle);
    // REDIRECTED(AnimSeq_SlotsChanseyEgg);
    // REDIRECTED(AnimSeq_GameFreakLogo);
    // REDIRECTED(AnimSeq_TradePokeBall);
    // REDIRECTED(AnimSeq_IntroUnown);
    // REDIRECTED(AnimSeq_PartyMon);
    // REDIRECTED(AnimSeq_GSTitleTrail);
    // REDIRECTED(AnimSeq_SlotsChansey);
    // REDIRECTED(AnimSeq_SlotsGolem);
    // REDIRECTED(AnimSeq_CutLeaves);
    // REDIRECTED(AnimSeq_IntroSuicuneAway);
    // REDIRECTED(AnimSeq_RadioTuningKnob);
    // REDIRECTED(AnimSeq_MobileTradeSentPulse);
    // REDIRECTED(AnimSeq_MobileTradeOTPulse);
    // REDIRECTED(AnimSeqs_AnonJumptable);
    // REDIRECTED(AnimSeq_PokegearArrow);
    // REDIRECTED(AnimSeq_FlyFrom);
    // REDIRECTED(AnimSeqs_IncAnonJumptableIndex);
    // REDIRECTED(AnimSeq_FlyTo);
    // REDIRECTED(AnimSeq_IntroPichuWooper);
    // REDIRECTED(AnimSeq_UnusedCursor);
    // REDIRECTED(AnimSeq_RevealNewMon);
    // REDIRECTED(AnimSeq_IntroSuicune);
    // REDIRECTED(AnimSeq_Null);
    // REDIRECTED(DoAnimFrame);
    // REDIRECTED(AnimSeq_PartyMonSelected);

    // engine/gfx/player_gfx.c
    // REDIRECTED(GetPlayerBackpic);
    // REDIRECTED(TrainerCardGFX);
    // REDIRECTED(ShowPlayerNamingChoices);
    // REDIRECTED(GetChrisBackpic);
    // REDIRECTED(MovePlayerPic);
    // REDIRECTED(KrisCardPic);
    // REDIRECTED(ChrisPic);
    // REDIRECTED(HOF_LoadTrainerFrontpic);
    // REDIRECTED(GetPlayerNameArray);
    // REDIRECTED(GetPlayerIcon);
    // REDIRECTED(GetKrisBackpic);
    // REDIRECTED(GetCardPic);
    // REDIRECTED(DrawIntroPlayerPic);
    // REDIRECTED(BetaLoadPlayerTrainerClass);
    // REDIRECTED(MovePlayerPicRight);
    // REDIRECTED(KrisPic);
    // REDIRECTED(ChrisCardPic);
    // REDIRECTED(MovePlayerPicLeft);
    // REDIRECTED(KrisBackpic);

    // engine/battle/start_battle.c
    // REDIRECTED(ShowLinkBattleParticipants);
    // REDIRECTED(ClearBattleRAM);
    // REDIRECTED(PlayBattleMusic);
    // REDIRECTED(FindFirstAliveMonAndStartBattle);

    // engine/battle/sliding_intro.c
    CONVERTED(BattleIntroSlidingPics);

    // engine/rtc/rtc.c
    // REDIRECTED(SaveRTC);
    // REDIRECTED(v_InitTime);
    // REDIRECTED(GetTimeOfDay);
    // REDIRECTED(StartClock);
    // REDIRECTED(TimesOfDay);
    // REDIRECTED(StopRTC);
    // REDIRECTED(StartRTC);
    // REDIRECTED(StageRTCTimeForSave);
    // REDIRECTED(v_FixDays);
    // REDIRECTED(ClockContinue);
    // REDIRECTED(BetaTimesOfDay);

    // engine/math/print_num.c
    REDIRECTED(v_PrintNum);

    // engine/math/math.c
    REDIRECTED(v_Multiply);
    REDIRECTED(v_Divide);

    // engine/battle/hidden_power.c
    // REDIRECTED(HiddenPowerDamage);

    // engine/phone/phonering_copytilemapatonce.c
    CONVERTED(PhoneRing_CopyTilemapAtOnce);


    // engine/phone/scripts/elm.c
    //REDIRECTED(ElmPhoneCalleeScript);
    //REDIRECTED(ElmPhoneCallerScript);

    // engine/phone/scripts/alan.c
    //REDIRECTED(AlanHasFireStone);
    //REDIRECTED(AlanPhoneCallerScript);
    //REDIRECTED(AlanWantsBattle);
    //REDIRECTED(AlanWednesdayDay);
    //REDIRECTED(AlanPhoneCalleeScript);

    // engine/phone/scripts/anthony.c
    //REDIRECTED(AnthonyWantsBattle);
    //REDIRECTED(AnthonyPhoneCalleeScript);
    //REDIRECTED(AnthonyTriesDunsparceSwarm);
    //REDIRECTED(AnthonyPhoneCallerScript);
    //REDIRECTED(AnthonyFridayNight);

    // engine/phone/scripts/arnie.c
    //REDIRECTED(ArnieWantsBattle);
    //REDIRECTED(ArnieYanmaSwarm);
    //REDIRECTED(ArniePhoneCalleeScript);
    //REDIRECTED(ArniePhoneCallerScript);
    //REDIRECTED(ArnieFoundRare);
    //REDIRECTED(ArnieTuesdayMorning);
    //REDIRECTED(ArnieYanmaAlreadySwarming);

    // engine/phone/scripts/beth.c
    //REDIRECTED(BethPhoneCallerScript);
    //REDIRECTED(BethWantsBattle);
    //REDIRECTED(BethPhoneCalleeScript);
    //REDIRECTED(BethFridayAfternoon);

    // engine/phone/scripts/beverly.c
    //REDIRECTED(BeverlyPhoneCallerScript);
    //REDIRECTED(BeverlyPhoneCalleeScript);

    // engine/phone/scripts/bike_shop.c
    //REDIRECTED(BikeShopPhoneCallerScript);

    // engine/phone/scripts/bill.c
    //REDIRECTED(BillPhoneCallerScript);
    //REDIRECTED(BillPhoneCalleeScript);

    // engine/phone/scripts/brent.c
    //REDIRECTED(BrentMondayMorning);
    //REDIRECTED(BrentPhoneCalleeScript);
    //REDIRECTED(BrentBillTrivia);
    //REDIRECTED(BrentPhoneCallerScript);
    //REDIRECTED(BrentWantsBattle);

    // engine/phone/scripts/brent_gossip.c
    //REDIRECTED(BrentBillTriviaScript);

    // engine/phone/scripts/buena.c
    //REDIRECTED(BuenaPhoneScript_Rocket);
    //REDIRECTED(BuenaPhoneScript_AfterMidnightCallee);
    //REDIRECTED(BuenaPhoneCallerScript);
    //REDIRECTED(BuenaPhoneCalleeScript);
    //REDIRECTED(BuenaPhoneScript_RandomCallee);
    //REDIRECTED(BuenaPhoneScript_CheckTimeOfDayCaller);
    //REDIRECTED(BuenaPhoneScript_RandomCaller);
    //REDIRECTED(BuenaPhoneScript_CheckTimeOfDayCallee);
    //REDIRECTED(BuenaPhoneScript_AfterMidnightCaller);

    // engine/phone/scripts/chad.c
    //REDIRECTED(ChadFoundRare);
    //REDIRECTED(ChadFridayMorning);
    //REDIRECTED(ChadPhoneCalleeScript);
    //REDIRECTED(ChadPhoneCallerScript);
    //REDIRECTED(ChadOakGossip);
    //REDIRECTED(ChadWantsBattle);

    // engine/phone/scripts/chad_gossip.c
    //REDIRECTED(ChadOakGossipScript);

    // engine/phone/scripts/dana.c
    //REDIRECTED(DanaPhoneCallerScript);
    //REDIRECTED(DanaFoundRare);
    //REDIRECTED(DanaThursdayNight);
    //REDIRECTED(DanaWantsBattle);
    //REDIRECTED(DanaPhoneCalleeScript);
    //REDIRECTED(DanaHasThunderstone);

    // engine/phone/scripts/derek.c
    //REDIRECTED(DerekPhoneCalleeScript);
    //REDIRECTED(DerekPhoneCallerScript);

    // engine/phone/scripts/erin.c
    //REDIRECTED(ErinPhoneCallerScript);
    //REDIRECTED(ErinWantsBattle);
    //REDIRECTED(ErinPhoneCalleeScript);
    //REDIRECTED(ErinSaturdayNight);

    // engine/phone/scripts/gaven.c
    //REDIRECTED(GavenPhoneCalleeScript);
    //REDIRECTED(GavenWantsRematch);
    //REDIRECTED(GavenThursdayMorningScript);
    //REDIRECTED(GavenPhoneCallerScript);
    //REDIRECTED(GavenFoundRare);

    // engine/phone/scripts/generic_callee.c
    //REDIRECTED(PhoneScript_AnswerPhone_Male_Day);
    //REDIRECTED(PhoneScript_Generic_Female);
    //REDIRECTED(PhoneScript_AnswerPhone_Male);
    //REDIRECTED(DadString);
    //REDIRECTED(PhoneScript_GreetPhone_Female_Day);
    //REDIRECTED(PhoneScript_MonFlavorText);
    //REDIRECTED(SisterString);
    //REDIRECTED(PhoneScript_AnswerPhone_Female_Nite);
    //REDIRECTED(PhoneScript_AnswerPhone_Female_Day);
    //REDIRECTED(PhoneScript_GreetPhone_Female);
    //REDIRECTED(PhoneScript_GreetPhone_Female_Nite);
    //REDIRECTED(PhoneScript_Generic_Male);
    //REDIRECTED(PhoneScript_GreetPhone_Male);
    //REDIRECTED(PhoneScript_Random2);
    //REDIRECTED(PhoneScript_GreetPhone_Male_Nite);
    //REDIRECTED(PhoneScript_Random5);
    //REDIRECTED(PhoneScript_AnswerPhone_Female);
    //REDIRECTED(PhoneScript_GreetPhone_Male_Day);
    //REDIRECTED(GrandmaString);
    //REDIRECTED(MomString);
    //REDIRECTED(GrandpaString);
    //REDIRECTED(PhoneScript_AnswerPhone_Male_Nite);
    //REDIRECTED(BrotherString);
    //REDIRECTED(PhoneScript_Random4);
    //REDIRECTED(PhoneScript_Random11);
    //REDIRECTED(PhoneScript_Random3);

    // engine/phone/scripts/generic_caller.c
    //REDIRECTED(PhoneScript_BugCatchingContest);
    //REDIRECTED(IrwinRocketRumorScript);
    //REDIRECTED(PhoneScript_RematchText_Female);
    //REDIRECTED(Phone_FoundAMon_Female);
    //REDIRECTED(Phone_GotAwayCall_Female);
    //REDIRECTED(ArnieSwarmScript);
    //REDIRECTED(Phone_CheckIfUnseenRare_Male);
    //REDIRECTED(PhoneScript_HangUpText_Female);
    //REDIRECTED(PhoneScript_HangUpText_Male);
    //REDIRECTED(Phone_BraggingCall_Male);
    //REDIRECTED(Phone_WhoDefeatedMon_Male);
    //REDIRECTED(RalphItemScript);
    //REDIRECTED(PhoneScript_WantsToBattle_Female);
    //REDIRECTED(KenjiCallingPhoneScript);
    //REDIRECTED(Phone_GenericCall_Female);
    //REDIRECTED(PhoneScript_FoundItem_Female);
    //REDIRECTED(TiffanyItsAwful);
    //REDIRECTED(PhoneScript_WantsToBattle_Male);
    //REDIRECTED(Phone_FoundAMon_Male);
    //REDIRECTED(PhoneScript_FoundItem_Male);
    //REDIRECTED(Phone_GotAwayCall_Male);
    //REDIRECTED(Phone_WhoDefeatedMon_Female);
    //REDIRECTED(LizWrongNumberScript);
    //REDIRECTED(GinaRocketRumorScript);
    //REDIRECTED(Phone_BraggingCall_Female);
    //REDIRECTED(Phone_CheckIfUnseenRare_Female);
    //REDIRECTED(PhoneScript_RematchText_Male);
    //REDIRECTED(Phone_GenericCall_Male);
    //REDIRECTED(Phone_WhosBragging_Male);
    //REDIRECTED(PhoneScriptRareWildMon);
    //REDIRECTED(ToddItemScript);
    //REDIRECTED(AnthonySwarmScript);
    //REDIRECTED(Phone_WhosBragging_Female);
    //REDIRECTED(Phone_WhoLostAMon_Female);
    //REDIRECTED(Phone_WhoLostAMon_Male);

    // engine/phone/scripts/gina.c
    //REDIRECTED(GinaPhoneCallerScript);
    //REDIRECTED(GinaRockets);
    //REDIRECTED(GinaSundayDay);
    //REDIRECTED(GinaPhoneCalleeScript);
    //REDIRECTED(GinaWantsBattle);
    //REDIRECTED(GinaHasLeafStone);

    // engine/phone/scripts/hangups.c
    //REDIRECTED(IrwinSoMuchToChatAboutScript);
    //REDIRECTED(BrentHangUpScript);
    //REDIRECTED(GinaHangUpScript);
    //REDIRECTED(AlanHangUpScript);
    //REDIRECTED(JoeyHangUpScript);
    //REDIRECTED(TullyNoItemScript);
    //REDIRECTED(AnthonyHangUpScript);
    //REDIRECTED(ParryBattleWithMeScript);
    //REDIRECTED(HueyHangUpScript);
    //REDIRECTED(ToddNoItemScript);
    //REDIRECTED(RalphNoItemScript);
    //REDIRECTED(ReenaForwardScript);
    //REDIRECTED(JackPhoneTipsScript);
    //REDIRECTED(DanaHangUpScript);
    //REDIRECTED(JoseHangUpScript);
    //REDIRECTED(DerekHangUpScript);
    //REDIRECTED(ArnieHangUpScript);
    //REDIRECTED(WiltonHaventFoundAnythingScript);
    //REDIRECTED(GavenHangUpNotThursdayScript);
    //REDIRECTED(WadeNoBerriesScript);
    //REDIRECTED(TiffanyNoItemScript);
    //REDIRECTED(ErinWorkingHardScript);
    //REDIRECTED(IrwinRandomTextScript);
    //REDIRECTED(VanceLookingForwardScript);
    //REDIRECTED(LizHangUpScript);
    //REDIRECTED(BethHangUpScript);
    //REDIRECTED(IrwinGoodMatchScript);
    //REDIRECTED(KenjiAnswerPhoneScript);
    //REDIRECTED(ChadHangUpScript);
    //REDIRECTED(IrwinEscapadeScript);
    //REDIRECTED(BeverlyHangUpScript);

    // engine/phone/scripts/hangups_2.c
    //REDIRECTED(WadeComeQuickScript);
    //REDIRECTED(DerekComePickUpScript);
    //REDIRECTED(WiltonWantThisScript);
    //REDIRECTED(JoseComePickUpScript);
    //REDIRECTED(AlanComePickUpScript);
    //REDIRECTED(TullyHurryScript);
    //REDIRECTED(BeverlyComePickUpScript);
    //REDIRECTED(DanaComePickUpScript);
    //REDIRECTED(TiffanyHurryScript);
    //REDIRECTED(GinaComePickUpScript);

    // engine/phone/scripts/huey.c
    //REDIRECTED(HueyPhoneCallerScript);
    //REDIRECTED(HueyPhoneCalleeScript);
    //REDIRECTED(HueyWednesdayNight);
    //REDIRECTED(HueyWantsBattle);

    // engine/phone/scripts/irwin.c
    //REDIRECTED(IrwinPhoneCallerScript);
    //REDIRECTED(IrwinPhoneCalleeScript);

    // engine/phone/scripts/irwin_gossip.c
    //REDIRECTED(IrwinRumorScript);

    // engine/phone/scripts/jack.c
    //REDIRECTED(JackWantsToBattle);
    //REDIRECTED(JackPhoneCalleeScript);
    //REDIRECTED(JackFindsRare);
    //REDIRECTED(JackBattleTrivia);
    //REDIRECTED(JackPhoneCallerScript);
    //REDIRECTED(JackMondayMorning);

    // engine/phone/scripts/jack_gossip.c
    //REDIRECTED(JackTriviaScript);

    // engine/phone/scripts/joey.c
    //REDIRECTED(JoeyPhoneCalleeScript);
    //REDIRECTED(JoeyPhoneCallerScript);
    //REDIRECTED(JoeyMondayAfternoon);
    //REDIRECTED(JoeyWantsBattle);

    // engine/phone/scripts/jose.c
    //REDIRECTED(JosePhoneCallerScript);
    //REDIRECTED(JoseWantsBattle);
    //REDIRECTED(JosePhoneCalleeScript);
    //REDIRECTED(JoseSaturdayNight);
    //REDIRECTED(JoseHasStarPiece);
    //REDIRECTED(JoseFoundRare);

    // engine/phone/scripts/kenji.c
    //REDIRECTED(KenjiPhoneCalleeScript);
    //REDIRECTED(KenjiPhoneCallerScript);

    // engine/phone/scripts/liz.c
    //REDIRECTED(LizPhoneCallerScript);
    //REDIRECTED(LizPhoneCalleeScript);
    //REDIRECTED(LizGossip);
    //REDIRECTED(LizWantsBattle);
    //REDIRECTED(LizGossipScript);
    //REDIRECTED(LizThursdayAfternoon);
    //REDIRECTED(LizWrongNumber);

    // engine/phone/scripts/liz_gossip.c
    //REDIRECTED(LizGossipRandomScript);

    // engine/phone/scripts/mom.c
    //REDIRECTED(MomPhoneNoPokedexScript);
    //REDIRECTED(MomPhoneHangUpScript);
    //REDIRECTED(MomPhoneInTown);
    //REDIRECTED(MomPhoneCalleeScript);
    //REDIRECTED(MomPhoneSaveMoneyScript);
    //REDIRECTED(MomPhoneWontSaveMoneyScript);
    //REDIRECTED(MomPhoneLandmark);
    //REDIRECTED(MomPhoneOnRoute);
    //REDIRECTED(MomPhoneOther);
    //REDIRECTED(MomPhoneNoGymQuestScript);
    //REDIRECTED(MomPhoneNoPokemonScript);
    //REDIRECTED(MomSavingMoney);
    //REDIRECTED(MomPhoneLectureScript);

    // engine/phone/scripts/parry.c
    //REDIRECTED(ParryPhoneCalleeScript);
    //REDIRECTED(ParryPhoneCallerScript);
    //REDIRECTED(ParryWantsBattle);
    //REDIRECTED(ParryFridayDay);

    // engine/phone/scripts/ralph.c
    //REDIRECTED(Ralph_WednesdayMorning);
    //REDIRECTED(Ralph_FightMe);
    //REDIRECTED(RalphPhoneCalleeScript);
    //REDIRECTED(RalphPhoneCallerScript);
    //REDIRECTED(Ralph_SetUpSwarm);

    // engine/phone/scripts/reena.c
    //REDIRECTED(ReenaPhoneCallerScript);
    //REDIRECTED(ReenaPhoneCalleeScript);
    //REDIRECTED(ReenaSundayMorning);
    //REDIRECTED(ReenaWantsBattle);

    // engine/phone/scripts/reminders.c
    //REDIRECTED(GavenReminderScript);
    //REDIRECTED(JoeyReminderScript);
    //REDIRECTED(VanceHurryHurryScript);
    //REDIRECTED(WadeQuickBattleScript);
    //REDIRECTED(HueyWantsBattleScript);
    //REDIRECTED(LizReminderScript);
    //REDIRECTED(ArnieReminderScript);
    //REDIRECTED(AlanReminderScript);
    //REDIRECTED(GinaReminderScript);
    //REDIRECTED(RalphReminderScript);
    //REDIRECTED(WiltonNotBitingScript);
    //REDIRECTED(JoseReminderScript);
    //REDIRECTED(ErinComeBattleScript);
    //REDIRECTED(BrentReminderScript);
    //REDIRECTED(ChadReminderScript);
    //REDIRECTED(TiffanyAsleepScript);
    //REDIRECTED(JackWantsBattleScript);
    //REDIRECTED(BethBattleReminderScript);
    //REDIRECTED(ReenaHurryScript);
    //REDIRECTED(AnthonyReminderScript);
    //REDIRECTED(ParryHaventYouGottenToScript);
    //REDIRECTED(ToddForwardScript);
    //REDIRECTED(DanaReminderScript);
    //REDIRECTED(TullyForwardScript);

    // engine/phone/scripts/reminders_2.c
    //REDIRECTED(AnthonyHurryScript);
    //REDIRECTED(ArnieHurryScript);
    //REDIRECTED(ToddHurryScript);
    //REDIRECTED(RalphHurryScript);

    // engine/phone/scripts/tiffany.c
    //REDIRECTED(TiffanyPhoneCalleeScript);
    //REDIRECTED(TiffanyWantsBattle);
    //REDIRECTED(TiffanyTuesdayAfternoon);
    //REDIRECTED(TiffanyPhoneCallerScript);
    //REDIRECTED(TiffanysFamilyMembers);
    //REDIRECTED(TiffanyHasPinkBow);

    // engine/phone/scripts/todd.c
    //REDIRECTED(ToddPhoneCallerScript);
    //REDIRECTED(ToddDeptStoreSale);
    //REDIRECTED(ToddWantsBattle);
    //REDIRECTED(ToddFoundRare);
    //REDIRECTED(ToddSaturdayMorning);
    //REDIRECTED(ToddPhoneCalleeScript);

    // engine/phone/scripts/tully.c
    //REDIRECTED(TullyPhoneCalleeScript);
    //REDIRECTED(TullySundayNight);
    //REDIRECTED(TullyPhoneCallerScript);
    //REDIRECTED(TullyWantsBattle);
    //REDIRECTED(TullyFoundWaterStone);

    // engine/phone/scripts/unused.c
    //REDIRECTED(UnusedPhoneScript);

    // engine/phone/scripts/vance.c
    //REDIRECTED(VancePhoneCalleeScript);
    //REDIRECTED(VanceWednesdayNight);
    //REDIRECTED(VanceWantsRematch);
    //REDIRECTED(VancePhoneCallerScript);

    // engine/phone/scripts/wade.c
    //REDIRECTED(WadeHasItem2);
    //REDIRECTED(WadePhoneCallerScript);
    //REDIRECTED(WadePhoneCalleeScript);
    //REDIRECTED(WadeTuesdayNight);
    //REDIRECTED(WadeWantsBattle2);
    //REDIRECTED(WadeFoundRare);

    // engine/phone/scripts/wilton.c
    //REDIRECTED(WiltonThursdayMorning);
    //REDIRECTED(WiltonHasItem);
    //REDIRECTED(WiltonWantsBattle);
    //REDIRECTED(WiltonPhoneCalleeScript);
    //REDIRECTED(WiltonPhoneCallerScript);
}
