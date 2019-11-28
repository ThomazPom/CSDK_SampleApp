// CSDKGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <chrono>
#include <iostream>

#include "HandleInput.h"
#include "Razer\ChromaSDKPluginTypes.h"
#include "Razer\ChromaAnimationAPI.h"
#include "RazerKeyboardMapping.h"

using namespace std;
using namespace std::chrono;
using namespace ChromaSDK;

const float MATH_PI = 3.14159f;

#define USE_EFFECT_CACHE true;

#ifdef USE_EFFECT_CACHE
// add a cache mechanism
map<string, string> _gCacheEffect = map<string, string>();
#endif


void HideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void ShowConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

bool IsConsoleVisible()
{
	return ::IsWindowVisible(::GetConsoleWindow()) != FALSE;
}



void ShowEffectCustom()
{
	// start with a blank animation
	const char* baseLayer = "Animations/Custom_Keyboard.chroma";
	// close the blank animation if it's already loaded, discarding any changes
	ChromaAnimationAPI::CloseAnimationName(baseLayer);
	// open the blank animation, passing a reference to the base animation when loading has completed
	ChromaAnimationAPI::GetAnimation(baseLayer);
	// double the number of the frames
	ChromaAnimationAPI::DuplicateFramesName(baseLayer);
	// set animation playback to 30 FPS
	ChromaAnimationAPI::OverrideFrameDurationName(baseLayer, 0.033f);
	// play the animation on the dynamic canvas
	ChromaAnimationAPI::PlayAnimationName(baseLayer, true);
}
void ShowEffectCustomChromaLink()
{
	// start with a blank animation
	const char* baseLayer = "Animations/Custom_ChromaLink.chroma";
	// close the blank animation if it's already loaded, discarding any changes
	ChromaAnimationAPI::CloseAnimationName(baseLayer);
	// open the blank animation, passing a reference to the base animation when loading has completed
	ChromaAnimationAPI::GetAnimation(baseLayer);
	// double the number of the frames
	ChromaAnimationAPI::DuplicateFramesName(baseLayer);
	// set animation playback to 30 FPS
	ChromaAnimationAPI::OverrideFrameDurationName(baseLayer, 0.033f);
	// play the animation on the dynamic canvas
	ChromaAnimationAPI::PlayAnimationName(baseLayer, true);
}
void ShowEffectCustomHeadset()
{
	// start with a blank animation
	const char* baseLayer = "Animations/Custom_Headset.chroma";
	// close the blank animation if it's already loaded, discarding any changes
	ChromaAnimationAPI::CloseAnimationName(baseLayer);
	// open the blank animation, passing a reference to the base animation when loading has completed
	ChromaAnimationAPI::GetAnimation(baseLayer);
	// double the number of the frames
	ChromaAnimationAPI::DuplicateFramesName(baseLayer);
	// set animation playback to 30 FPS
	ChromaAnimationAPI::OverrideFrameDurationName(baseLayer, 0.033f);
	// play the animation on the dynamic canvas
	ChromaAnimationAPI::PlayAnimationName(baseLayer, true);
}
void ShowEffectCustomMousepad()
{
	// start with a blank animation
	const char* baseLayer = "Animations/Custom_Mousepad.chroma";
	// close the blank animation if it's already loaded, discarding any changes
	ChromaAnimationAPI::CloseAnimationName(baseLayer);
	// open the blank animation, passing a reference to the base animation when loading has completed
	ChromaAnimationAPI::GetAnimation(baseLayer);
	// double the number of the frames
	ChromaAnimationAPI::DuplicateFramesName(baseLayer);
	// set animation playback to 30 FPS
	ChromaAnimationAPI::OverrideFrameDurationName(baseLayer, 0.033f);
	// play the animation on the dynamic canvas
	ChromaAnimationAPI::PlayAnimationName(baseLayer, true);
}
void ShowEffectCustomMouse()
{
	// start with a blank animation
	const char* baseLayer = "Animations/Custom_Mouse.chroma";
	// close the blank animation if it's already loaded, discarding any changes
	ChromaAnimationAPI::CloseAnimationName(baseLayer);
	// open the blank animation, passing a reference to the base animation when loading has completed
	ChromaAnimationAPI::GetAnimation(baseLayer);
	// double the number of the frames
	ChromaAnimationAPI::DuplicateFramesName(baseLayer);
	// set animation playback to 30 FPS
	ChromaAnimationAPI::OverrideFrameDurationName(baseLayer, 0.033f);
	// play the animation on the dynamic canvas
	ChromaAnimationAPI::PlayAnimationName(baseLayer, true);
}
int main(int argc, char* argv[])
{		
	if (argc >= 2)
	{
		HideConsole();
	}
	fprintf(stderr, "App launched!\r\n");
	if (ChromaAnimationAPI::InitAPI() != 0)
	{
		return -1;
	}

	RZRESULT result = ChromaAnimationAPI::Init();
	if (result == RZRESULT_DLL_NOT_FOUND)
	{
		fprintf(stderr, "Chroma DLL is not found! %d", result);
		return -1;
	}
	else if (result == RZRESULT_DLL_INVALID_SIGNATURE)
	{
		fprintf(stderr, "Chroma DLL has an invalid signature! %d", result);
		return -1;
	}
	else if (result != 0)
	{
		fprintf(stderr, "Failed to initialize Chroma! %d", result);
		return -1;
	}

	ShowEffectCustom();
	ShowEffectCustomChromaLink();
	ShowEffectCustomHeadset();
	ShowEffectCustomMousepad();
	ShowEffectCustomMouse();
	while (true)
	{
		Sleep(3600*1000);
	}
    return 0;
}

