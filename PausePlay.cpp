#include "framework.h"

#define MAX_LOADSTRING 100


int APIENTRY _tWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR    lpCmdLine,
    int       nCmdShow)
{
    INPUT inputs[2] = {};
    ZeroMemory(inputs, sizeof(inputs));

    WORD mVk;

    switch (lpCmdLine[1])
    {
        case 'p':
        case 'P':
            mVk = VK_MEDIA_PREV_TRACK;
			break;
        case 'n':
        case 'N':
			mVk = VK_MEDIA_NEXT_TRACK;
            break;
        default:
			mVk = VK_MEDIA_PLAY_PAUSE;
    }

    inputs[0].type = INPUT_KEYBOARD;
	inputs[0].ki.wVk = mVk;

    inputs[1].type = INPUT_KEYBOARD;
	inputs[1].ki.wVk = mVk;
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

    UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));

    return uSent != ARRAYSIZE(inputs) ? 1 : 0;
}
