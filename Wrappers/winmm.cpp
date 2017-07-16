/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "Settings\Settings.h"
#include "wrapper.h"
#include "Utils\Utils.h"

#define module winmm

#define VISIT_PROCS(visit) \
	visit(CloseDriver) \
	visit(DefDriverProc) \
	visit(DriverCallback) \
	visit(DrvGetModuleHandle) \
	visit(GetDriverModuleHandle) \
	visit(NotifyCallbackData) \
	visit(OpenDriver) \
	visit(PlaySound) \
	visit(PlaySoundA) \
	visit(PlaySoundW) \
	visit(SendDriverMessage) \
	visit(WOW32DriverCallback) \
	visit(WOW32ResolveMultiMediaHandle) \
	visit(WOWAppExit) \
	visit(aux32Message) \
	visit(auxGetDevCapsA) \
	visit(auxGetDevCapsW) \
	visit(auxGetNumDevs) \
	visit(auxGetVolume) \
	visit(auxOutMessage) \
	visit(auxSetVolume) \
	visit(joy32Message) \
	visit(joyConfigChanged) \
	visit(joyGetDevCapsA) \
	visit(joyGetDevCapsW) \
	visit(joyGetNumDevs) \
	visit(joyGetPos) \
	visit(joyGetPosEx) \
	visit(joyGetThreshold) \
	visit(joyReleaseCapture) \
	visit(joySetCapture) \
	visit(joySetThreshold) \
	visit(mci32Message) \
	visit(mciDriverNotify) \
	visit(mciDriverYield) \
	visit(mciExecute) \
	visit(mciFreeCommandResource) \
	visit(mciGetCreatorTask) \
	visit(mciGetDeviceIDA) \
	visit(mciGetDeviceIDFromElementIDA) \
	visit(mciGetDeviceIDFromElementIDW) \
	visit(mciGetDeviceIDW) \
	visit(mciGetDriverData) \
	visit(mciGetErrorStringA) \
	visit(mciGetErrorStringW) \
	visit(mciGetYieldProc) \
	visit(mciLoadCommandResource) \
	visit(mciSendCommandA) \
	visit(mciSendCommandW) \
	visit(mciSendStringA) \
	visit(mciSendStringW) \
	visit(mciSetDriverData) \
	visit(mciSetYieldProc) \
	visit(mid32Message) \
	visit(midiConnect) \
	visit(midiDisconnect) \
	visit(midiInAddBuffer) \
	visit(midiInClose) \
	visit(midiInGetDevCapsA) \
	visit(midiInGetDevCapsW) \
	visit(midiInGetErrorTextA) \
	visit(midiInGetErrorTextW) \
	visit(midiInGetID) \
	visit(midiInGetNumDevs) \
	visit(midiInMessage) \
	visit(midiInOpen) \
	visit(midiInPrepareHeader) \
	visit(midiInReset) \
	visit(midiInStart) \
	visit(midiInStop) \
	visit(midiInUnprepareHeader) \
	visit(midiOutCacheDrumPatches) \
	visit(midiOutCachePatches) \
	visit(midiOutClose) \
	visit(midiOutGetDevCapsA) \
	visit(midiOutGetDevCapsW) \
	visit(midiOutGetErrorTextA) \
	visit(midiOutGetErrorTextW) \
	visit(midiOutGetID) \
	visit(midiOutGetNumDevs) \
	visit(midiOutGetVolume) \
	visit(midiOutLongMsg) \
	visit(midiOutMessage) \
	visit(midiOutOpen) \
	visit(midiOutPrepareHeader) \
	visit(midiOutReset) \
	visit(midiOutSetVolume) \
	visit(midiOutShortMsg) \
	visit(midiOutUnprepareHeader) \
	visit(midiStreamClose) \
	visit(midiStreamOpen) \
	visit(midiStreamOut) \
	visit(midiStreamPause) \
	visit(midiStreamPosition) \
	visit(midiStreamProperty) \
	visit(midiStreamRestart) \
	visit(midiStreamStop) \
	visit(mixerClose) \
	visit(mixerGetControlDetailsA) \
	visit(mixerGetControlDetailsW) \
	visit(mixerGetDevCapsA) \
	visit(mixerGetDevCapsW) \
	visit(mixerGetID) \
	visit(mixerGetLineControlsA) \
	visit(mixerGetLineControlsW) \
	visit(mixerGetLineInfoA) \
	visit(mixerGetLineInfoW) \
	visit(mixerGetNumDevs) \
	visit(mixerMessage) \
	visit(mixerOpen) \
	visit(mixerSetControlDetails) \
	visit(mmDrvInstall) \
	visit(mmGetCurrentTask) \
	visit(mmTaskBlock) \
	visit(mmTaskCreate) \
	visit(mmTaskSignal) \
	visit(mmTaskYield) \
	visit(mmioAdvance) \
	visit(mmioAscend) \
	visit(mmioClose) \
	visit(mmioCreateChunk) \
	visit(mmioDescend) \
	visit(mmioFlush) \
	visit(mmioGetInfo) \
	visit(mmioInstallIOProcA) \
	visit(mmioInstallIOProcW) \
	visit(mmioOpenA) \
	visit(mmioOpenW) \
	visit(mmioRead) \
	visit(mmioRenameA) \
	visit(mmioRenameW) \
	visit(mmioSeek) \
	visit(mmioSendMessage) \
	visit(mmioSetBuffer) \
	visit(mmioSetInfo) \
	visit(mmioStringToFOURCCA) \
	visit(mmioStringToFOURCCW) \
	visit(mmioWrite) \
	visit(mmsystemGetVersion) \
	visit(mod32Message) \
	visit(mxd32Message) \
	visit(sndPlaySoundA) \
	visit(sndPlaySoundW) \
	visit(tid32Message) \
	visit(timeBeginPeriod) \
	visit(timeEndPeriod) \
	visit(timeGetDevCaps) \
	visit(timeGetSystemTime) \
	visit(timeGetTime) \
	visit(timeKillEvent) \
	visit(timeSetEvent) \
	visit(waveInAddBuffer) \
	visit(waveInClose) \
	visit(waveInGetDevCapsA) \
	visit(waveInGetDevCapsW) \
	visit(waveInGetErrorTextA) \
	visit(waveInGetErrorTextW) \
	visit(waveInGetID) \
	visit(waveInGetNumDevs) \
	visit(waveInGetPosition) \
	visit(waveInMessage) \
	visit(waveInOpen) \
	visit(waveInPrepareHeader) \
	visit(waveInReset) \
	visit(waveInStart) \
	visit(waveInStop) \
	visit(waveInUnprepareHeader) \
	visit(waveOutBreakLoop) \
	visit(waveOutClose) \
	visit(waveOutGetDevCapsA) \
	visit(waveOutGetDevCapsW) \
	visit(waveOutGetErrorTextA) \
	visit(waveOutGetErrorTextW) \
	visit(waveOutGetID) \
	visit(waveOutGetNumDevs) \
	visit(waveOutGetPitch) \
	visit(waveOutGetPlaybackRate) \
	visit(waveOutGetPosition) \
	visit(waveOutGetVolume) \
	visit(waveOutMessage) \
	visit(waveOutOpen) \
	visit(waveOutPause) \
	visit(waveOutPrepareHeader) \
	visit(waveOutReset) \
	visit(waveOutRestart) \
	visit(waveOutSetPitch) \
	visit(waveOutSetPlaybackRate) \
	visit(waveOutSetVolume) \
	visit(waveOutUnprepareHeader) \
	visit(waveOutWrite) \
	visit(wid32Message) \
	visit(winmmDbgOut) \
	visit(winmmSetDebugLevel) \
	visit(wod32Message) \

struct winmm_dll
{
	HMODULE dll = nullptr;
	VISIT_PROCS(ADD_FARPROC_MEMBER);
} winmm;

VISIT_PROCS(CREATE_PROC_STUB)

void LoadWinmm()
{
	// Load real dll
	winmm.dll = LoadDll(dtype.winmm);

	// Load dll functions
	if (winmm.dll)
	{
		VISIT_PROCS(LOAD_ORIGINAL_PROC);
	}
}