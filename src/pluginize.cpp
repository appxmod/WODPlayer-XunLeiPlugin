// MIT License
#include <windows.h>
#include <shlwapi.h>
#include <string>

#include "VideoPlayer/simpleplayer.h"


struct VWCreateOptions{
	HMODULE hPlugin=0;
	HINSTANCE hHost=0;
	HWND hParent=0;
	LONG_PTR* ret;
};

extern "C" __declspec(dllexport) int vwCreatePlayer(VWCreateOptions VWOpt) 
{
	int error_code=-1;
	CMyPlayer* ret = new CMyPlayer(error_code, VWOpt.hPlugin, VWOpt.hHost, VWOpt.hParent);
	if(VWOpt.ret) *VWOpt.ret = (LONG_PTR)ret;
	return error_code;
}

extern "C" __declspec(dllexport) HWND vwGetHWND(CMyPlayer* player) 
{
	return player->m_hAPlayerWnd;
}

extern "C" __declspec(dllexport) void vwRelease(CMyPlayer* player) 
{
	player->Release();
}

extern "C" __declspec(dllexport) void vwPlay(CMyPlayer* player) 
{
	player->Play();
}

extern "C" __declspec(dllexport) void vwPause(CMyPlayer* player) 
{
	player->Pause();
}

extern "C" __declspec(dllexport) void vwStop(CMyPlayer* player) 
{
	player->Stop();
}

extern "C" __declspec(dllexport) bool vwIsPlaying(CMyPlayer* player) 
{
	return player->IsPlaying();
}

extern "C" __declspec(dllexport) bool vwIsPaused(CMyPlayer* player) 
{
	return player->IsPaused();
}

extern "C" __declspec(dllexport) long vwGetPosition(CMyPlayer* player) 
{
	return player->GetPosition();
}

extern "C" __declspec(dllexport) long vwGetDuration(CMyPlayer* player) 
{
	return player->GetDuration();
}

extern "C" __declspec(dllexport) void vwSetPosition(CMyPlayer* player, long pos) 
{
	return player->SetPosition(pos);
}

extern "C" __declspec(dllexport) void vwSetFullScreen(CMyPlayer* player, bool val) 
{
	player->SetFullScreen(val);
}

extern "C" __declspec(dllexport) bool vwPlayVideoFile(CMyPlayer* player, TCHAR* path) 
{
	return player->PlayVideoFile(path);
}

extern "C" __declspec(dllexport) void vwClose(CMyPlayer* player) 
{
	player->Close();
}

