#pragma once

#include "ChromaSDKPluginTypes.h"

#ifdef _WIN64
#define CHROMA_EDITOR_DLL	_T("CChromaEditorLibrary64.dll")
#else
#define CHROMA_EDITOR_DLL	_T("CChromaEditorLibrary.dll")
#endif

/* Setup log mechanism */
typedef void(*DebugLogPtr)(const char *);
void LogDebug(const char* text, ...);
void LogError(const char* text, ...);
/* End of setup log mechanism */

#pragma region API typedefs
/*
	Adds a frame to the `Chroma` animation and sets the `duration` (in seconds).
	The `color` is expected to be an array of the dimensions for the `deviceType/device`.
	The `length` parameter is the size of the `color` array. For `EChromaSDKDevice1DEnum`
	the array size should be `MAX LEDS`. For `EChromaSDKDevice2DEnum` the array
	size should be `MAX ROW` * `MAX COLUMN`. Returns the animation id upon
	success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_ADD_FRAME)(int animationId, float duration, int* colors, int length);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES)(int sourceAnimationId, int targetAnimationId);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef double(*PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME_D)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET)(int sourceAnimationId, int targetAnimationId, int offset);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int offset);
/*
*/
typedef double(*PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double offset);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_ALL_KEYS_OFFSET)(int sourceAnimationId, int targetAnimationId, int frameId, int offset);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_ALL_KEYS_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId, int offset);
/*
*/
typedef double(*PLUGIN_ADD_NON_ZERO_ALL_KEYS_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId, double offset);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES)(int sourceAnimationId, int targetAnimationId);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef double(*PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME_D)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET)(int sourceAnimationId, int targetAnimationId, int offset);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int offset);
/*
*/
typedef double(*PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double offset);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_OFFSET)(int sourceAnimationId, int targetAnimationId, int frameId, int offset);
/*
*/
typedef void(*PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId, int offset);
/*
*/
typedef double(*PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId, double offset);
/*
*/
typedef void(*PLUGIN_APPEND_ALL_FRAMES)(int sourceAnimationId, int targetAnimationId);
/*
*/
typedef void(*PLUGIN_APPEND_ALL_FRAMES_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef double(*PLUGIN_APPEND_ALL_FRAMES_NAME_D)(const char* sourceAnimation, const char* targetAnimation);
/*
	`PluginClearAll` will issue a `CLEAR` effect for all devices.
*/
typedef void(*PLUGIN_CLEAR_ALL)();
/*
	`PluginClearAnimationType` will issue a `CLEAR` effect for the given device.
*/
typedef void(*PLUGIN_CLEAR_ANIMATION_TYPE)(int deviceType, int device);
/*
	`PluginCloseAll` closes all open animations so they can be reloaded from
	disk. The set of animations will be stopped if playing.
*/
typedef void(*PLUGIN_CLOSE_ALL)();
/*
	Closes the `Chroma` animation to free up resources referenced by id. Returns
	the animation id upon success. Returns -1 upon failure. This might be used
	while authoring effects if there was a change necessitating re-opening
	the animation. The animation id can no longer be used once closed.
*/
typedef int(*PLUGIN_CLOSE_ANIMATION)(int animationId);
/*
*/
typedef double(*PLUGIN_CLOSE_ANIMATION_D)(double animationId);
/*
	Closes the `Chroma` animation referenced by name so that the animation can
	be reloaded from disk.
*/
typedef void(*PLUGIN_CLOSE_ANIMATION_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_CLOSE_ANIMATION_NAME_D)(const char* path);
/*
	`PluginCloseComposite` closes a set of animations so they can be reloaded
	from disk. The set of animations will be stopped if playing.
*/
typedef void(*PLUGIN_CLOSE_COMPOSITE)(const char* name);
/*
*/
typedef double(*PLUGIN_CLOSE_COMPOSITE_D)(const char* name);
/*
*/
typedef int(*PLUGIN_COPY_ANIMATION)(int sourceAnimationId, const char* targetAnimation);
/*
*/
typedef void(*PLUGIN_COPY_ANIMATION_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef double(*PLUGIN_COPY_ANIMATION_NAME_D)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef void(*PLUGIN_COPY_BLUE_CHANNEL_ALL_FRAMES)(int animationId, float redIntensity, float greenIntensity);
/*
*/
typedef void(*PLUGIN_COPY_BLUE_CHANNEL_ALL_FRAMES_NAME)(const char* path, float redIntensity, float greenIntensity);
/*
*/
typedef double(*PLUGIN_COPY_BLUE_CHANNEL_ALL_FRAMES_NAME_D)(const char* path, double redIntensity, double greenIntensity);
/*
*/
typedef void(*PLUGIN_COPY_GREEN_CHANNEL_ALL_FRAMES)(int animationId, float redIntensity, float blueIntensity);
/*
*/
typedef void(*PLUGIN_COPY_GREEN_CHANNEL_ALL_FRAMES_NAME)(const char* path, float redIntensity, float blueIntensity);
/*
*/
typedef double(*PLUGIN_COPY_GREEN_CHANNEL_ALL_FRAMES_NAME_D)(const char* path, double redIntensity, double blueIntensity);
/*
	Copy animation key color from the source animation to the target animation
	for the given frame.
*/
typedef void(*PLUGIN_COPY_KEY_COLOR)(int sourceAnimationId, int targetAnimationId, int frameId, int rzkey);
/*
*/
typedef void(*PLUGIN_COPY_KEY_COLOR_ALL_FRAMES)(int sourceAnimationId, int targetAnimationId, int rzkey);
/*
*/
typedef void(*PLUGIN_COPY_KEY_COLOR_ALL_FRAMES_NAME)(const char* sourceAnimation, const char* targetAnimation, int rzkey);
/*
*/
typedef double(*PLUGIN_COPY_KEY_COLOR_ALL_FRAMES_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double rzkey);
/*
*/
typedef void(*PLUGIN_COPY_KEY_COLOR_ALL_FRAMES_OFFSET)(int sourceAnimationId, int targetAnimationId, int rzkey, int offset);
/*
*/
typedef void(*PLUGIN_COPY_KEY_COLOR_ALL_FRAMES_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int rzkey, int offset);
/*
*/
typedef double(*PLUGIN_COPY_KEY_COLOR_ALL_FRAMES_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double rzkey, double offset);
/*
	Copy animation key color from the source animation to the target animation
	for the given frame.
*/
typedef void(*PLUGIN_COPY_KEY_COLOR_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId, int rzkey);
/*
*/
typedef double(*PLUGIN_COPY_KEY_COLOR_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId, double rzkey);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_ALL_KEYS)(int sourceAnimationId, int targetAnimationId, int frameId);
/*
	Copy nonzero colors from a source animation to a target animation for all
	keys.
*/
typedef void(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES)(int sourceAnimationId, int targetAnimationId);
/*
	Copy nonzero colors from a source animation to a target animation for all
	keys.
*/
typedef void(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef double(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME_D)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET)(int sourceAnimationId, int targetAnimationId, int offset);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int offset);
/*
*/
typedef double(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double offset);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId);
/*
*/
typedef double(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_OFFSET)(int sourceAnimationId, int targetAnimationId, int frameId, int offset);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId, int offset);
/*
*/
typedef double(*PLUGIN_COPY_NON_ZERO_ALL_KEYS_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId, double offset);
/*
	Copy animation key color from the source animation to the target animation
	for the given frame where color is not zero.
*/
typedef void(*PLUGIN_COPY_NON_ZERO_KEY_COLOR)(int sourceAnimationId, int targetAnimationId, int frameId, int rzkey);
/*
	Copy animation key color from the source animation to the target animation
	for the given frame where color is not zero.
*/
typedef void(*PLUGIN_COPY_NON_ZERO_KEY_COLOR_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId, int rzkey);
/*
*/
typedef double(*PLUGIN_COPY_NON_ZERO_KEY_COLOR_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId, double rzkey);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS)(int sourceAnimationId, int targetAnimationId, int frameId);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES)(int sourceAnimationId, int targetAnimationId);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef double(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME_D)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET)(int sourceAnimationId, int targetAnimationId, int offset);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int offset);
/*
*/
typedef double(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double offset);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId);
/*
*/
typedef double(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_OFFSET)(int sourceAnimationId, int targetAnimationId, int frameId, int offset);
/*
*/
typedef void(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId, int offset);
/*
*/
typedef double(*PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId, double offset);
/*
*/
typedef void(*PLUGIN_COPY_RED_CHANNEL_ALL_FRAMES)(int animationId, float greenIntensity, float blueIntensity);
/*
*/
typedef void(*PLUGIN_COPY_RED_CHANNEL_ALL_FRAMES_NAME)(const char* path, float greenIntensity, float blueIntensity);
/*
*/
typedef double(*PLUGIN_COPY_RED_CHANNEL_ALL_FRAMES_NAME_D)(const char* path, double greenIntensity, double blueIntensity);
/*
*/
typedef void(*PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES)(int sourceAnimationId, int targetAnimationId);
/*
*/
typedef void(*PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef double(*PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES_NAME_D)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef void(*PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET)(int sourceAnimationId, int targetAnimationId, int offset);
/*
*/
typedef void(*PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int offset);
/*
*/
typedef double(*PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double offset);
/*
*/
typedef void(*PLUGIN_COPY_ZERO_KEY_COLOR)(int sourceAnimationId, int targetAnimationId, int frameId, int rzkey);
/*
*/
typedef void(*PLUGIN_COPY_ZERO_KEY_COLOR_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId, int rzkey);
/*
*/
typedef double(*PLUGIN_COPY_ZERO_KEY_COLOR_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId, double rzkey);
/*
*/
typedef void(*PLUGIN_COPY_ZERO_TARGET_ALL_KEYS_ALL_FRAMES)(int sourceAnimationId, int targetAnimationId);
/*
*/
typedef void(*PLUGIN_COPY_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef double(*PLUGIN_COPY_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME_D)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_CREATE_CHROMA_LINK_EFFECT)(ChromaSDK::ChromaLink::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_CREATE_EFFECT)(RZDEVICEID DeviceId, ChromaSDK::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_CREATE_HEADSET_EFFECT)(ChromaSDK::Headset::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_CREATE_KEYBOARD_EFFECT)(ChromaSDK::Keyboard::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_CREATE_KEYPAD_EFFECT)(ChromaSDK::Keypad::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_CREATE_MOUSE_EFFECT)(ChromaSDK::Mouse::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_CREATE_MOUSEPAD_EFFECT)(ChromaSDK::Mousepad::EFFECT_TYPE Effect, PRZPARAM pParam, RZEFFECTID *pEffectId);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_DELETE_EFFECT)(RZEFFECTID EffectId);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_INIT)();
/*
*/
typedef RZRESULT(*PLUGIN_CORE_QUERY_DEVICE)(RZDEVICEID DeviceId, ChromaSDK::DEVICE_INFO_TYPE &DeviceInfo);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_SET_EFFECT)(RZEFFECTID EffectId);
/*
*/
typedef RZRESULT(*PLUGIN_CORE_UNINIT)();
/*
	Creates a `Chroma` animation at the given path. The `deviceType` parameter
	uses `EChromaSDKDeviceTypeEnum` as an integer. The `device` parameter uses
	`EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` as an integer, respective
	to the `deviceType`. Returns the animation id upon success. Returns -1
	upon failure. Saves a `Chroma` animation file with the `.chroma` extension
	at the given path. Returns the animation id upon success. Returns -1 upon
	failure.
*/
typedef int(*PLUGIN_CREATE_ANIMATION)(const char* path, int deviceType, int device);
/*
	Creates a `Chroma` animation in memory without creating a file. The `deviceType`
	parameter uses `EChromaSDKDeviceTypeEnum` as an integer. The `device` parameter
	uses `EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` as an integer,
	respective to the `deviceType`. Returns the animation id upon success.
	Returns -1 upon failure. Returns the animation id upon success. Returns
	-1 upon failure.
*/
typedef int(*PLUGIN_CREATE_ANIMATION_IN_MEMORY)(int deviceType, int device);
/*
*/
typedef RZRESULT(*PLUGIN_CREATE_EFFECT)(RZDEVICEID deviceId, ChromaSDK::EFFECT_TYPE effect, int* colors, int size, ChromaSDK::FChromaSDKGuid* effectId);
/*
*/
typedef RZRESULT(*PLUGIN_DELETE_EFFECT)(const ChromaSDK::FChromaSDKGuid& effectId);
/*
*/
typedef void(*PLUGIN_DUPLICATE_FIRST_FRAME)(int animationId, int frameCount);
/*
*/
typedef void(*PLUGIN_DUPLICATE_FIRST_FRAME_NAME)(const char* path, int frameCount);
/*
*/
typedef double(*PLUGIN_DUPLICATE_FIRST_FRAME_NAME_D)(const char* path, double frameCount);
/*
*/
typedef void(*PLUGIN_DUPLICATE_FRAMES)(int animationId);
/*
*/
typedef void(*PLUGIN_DUPLICATE_FRAMES_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_DUPLICATE_FRAMES_NAME_D)(const char* path);
/*
*/
typedef void(*PLUGIN_DUPLICATE_MIRROR_FRAMES)(int animationId);
/*
*/
typedef void(*PLUGIN_DUPLICATE_MIRROR_FRAMES_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_DUPLICATE_MIRROR_FRAMES_NAME_D)(const char* path);
/*
*/
typedef void(*PLUGIN_FADE_END_FRAMES)(int animationId, int fade);
/*
*/
typedef void(*PLUGIN_FADE_END_FRAMES_NAME)(const char* path, int fade);
/*
*/
typedef double(*PLUGIN_FADE_END_FRAMES_NAME_D)(const char* path, double fade);
/*
*/
typedef void(*PLUGIN_FADE_START_FRAMES)(int animationId, int fade);
/*
*/
typedef void(*PLUGIN_FADE_START_FRAMES_NAME)(const char* path, int fade);
/*
*/
typedef double(*PLUGIN_FADE_START_FRAMES_NAME_D)(const char* path, double fade);
/*
	Set the RGB value for all colors in the specified frame. Use the range of
	0 to 255 for red, green, and blue parameters.
*/
typedef void(*PLUGIN_FILL_COLOR)(int animationId, int frameId, int color);
/*
*/
typedef void(*PLUGIN_FILL_COLOR_ALL_FRAMES)(int animationId, int color);
/*
	Set the RGB value for all colors for all frames.
*/
typedef void(*PLUGIN_FILL_COLOR_ALL_FRAMES_NAME)(const char* path, int color);
/*
*/
typedef double(*PLUGIN_FILL_COLOR_ALL_FRAMES_NAME_D)(const char* path, double color);
/*
	Set the RGB value for all colors for all frames. Use the range of 0 to 255
	for red, green, and blue parameters.
*/
typedef void(*PLUGIN_FILL_COLOR_ALL_FRAMES_RGB)(int animationId, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_FILL_COLOR_ALL_FRAMES_RGB_NAME)(const char* path, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_FILL_COLOR_ALL_FRAMES_RGB_NAME_D)(const char* path, double red, double green, double blue);
/*
	Set the RGB value for all colors in the specified frame. Use a BGR integer
	for the color parameter. 0xFF0000 (blue) 0x00FF00 (green) 0x0000FF (red)
*/
typedef void(*PLUGIN_FILL_COLOR_NAME)(const char* path, int frameId, int color);
/*
*/
typedef double(*PLUGIN_FILL_COLOR_NAME_D)(const char* path, double frameId, double color);
/*
	Set the RGB value for all colors in the specified frame. Use the range of
	0 to 255 for red, green, and blue parameters.
*/
typedef void(*PLUGIN_FILL_COLOR_RGB)(int animationId, int frameId, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_FILL_COLOR_RGB_NAME)(const char* path, int frameId, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_FILL_COLOR_RGB_NAME_D)(const char* path, double frameId, double red, double green, double blue);
/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame.
*/
typedef void(*PLUGIN_FILL_NON_ZERO_COLOR)(int animationId, int frameId, int color);
/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
*/
typedef void(*PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES)(int animationId, int color);
/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
*/
typedef void(*PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES_NAME)(const char* path, int color);
/*
*/
typedef double(*PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES_NAME_D)(const char* path, double color);
/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
	Use the range of 0 to 255 for red, green, and blue parameters.
*/
typedef void(*PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES_RGB)(int animationId, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES_RGB_NAME)(const char* path, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES_RGB_NAME_D)(const char* path, double red, double green, double blue);
/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame.
*/
typedef void(*PLUGIN_FILL_NON_ZERO_COLOR_NAME)(const char* path, int frameId, int color);
/*
*/
typedef double(*PLUGIN_FILL_NON_ZERO_COLOR_NAME_D)(const char* path, double frameId, double color);
/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame. Use the range of 0 to 255 for red, green, and blue parameters.
*/
typedef void(*PLUGIN_FILL_NON_ZERO_COLOR_RGB)(int animationId, int frameId, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_FILL_NON_ZERO_COLOR_RGB_NAME)(const char* path, int frameId, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_FILL_NON_ZERO_COLOR_RGB_NAME_D)(const char* path, double frameId, double red, double green, double blue);
/*
*/
typedef void(*PLUGIN_FILL_RANDOM_COLORS)(int animationId, int frameId);
/*
*/
typedef void(*PLUGIN_FILL_RANDOM_COLORS_ALL_FRAMES)(int animationId);
/*
*/
typedef void(*PLUGIN_FILL_RANDOM_COLORS_ALL_FRAMES_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_FILL_RANDOM_COLORS_ALL_FRAMES_NAME_D)(const char* path);
/*
*/
typedef void(*PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE)(int animationId, int frameId);
/*
*/
typedef void(*PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE_ALL_FRAMES)(int animationId);
/*
*/
typedef void(*PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE_ALL_FRAMES_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE_ALL_FRAMES_NAME_D)(const char* path);
/*
*/
typedef void(*PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE_NAME)(const char* path, int frameId);
/*
*/
typedef double(*PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE_NAME_D)(const char* path, double frameId);
/*
*/
typedef void(*PLUGIN_FILL_RANDOM_COLORS_NAME)(const char* path, int frameId);
/*
*/
typedef double(*PLUGIN_FILL_RANDOM_COLORS_NAME_D)(const char* path, double frameId);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS)(int animationId, int frameId, int threshold, int color);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES)(int animationId, int threshold, int color);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES_NAME)(const char* path, int threshold, int color);
/*
*/
typedef double(*PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES_NAME_D)(const char* path, double threshold, double color);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES_RGB)(int animationId, int threshold, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES_RGB_NAME)(const char* path, int threshold, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES_RGB_NAME_D)(const char* path, double threshold, double red, double green, double blue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_ALL_FRAMES_RGB)(int animationId, int minThreshold, int minRed, int minGreen, int minBlue, int maxThreshold, int maxRed, int maxGreen, int maxBlue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_ALL_FRAMES_RGB_NAME)(const char* path, int minThreshold, int minRed, int minGreen, int minBlue, int maxThreshold, int maxRed, int maxGreen, int maxBlue);
/*
*/
typedef double(*PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_ALL_FRAMES_RGB_NAME_D)(const char* path, double minThreshold, double minRed, double minGreen, double minBlue, double maxThreshold, double maxRed, double maxGreen, double maxBlue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_RGB)(int animationId, int frameId, int minThreshold, int minRed, int minGreen, int minBlue, int maxThreshold, int maxRed, int maxGreen, int maxBlue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_RGB_NAME)(const char* path, int frameId, int minThreshold, int minRed, int minGreen, int minBlue, int maxThreshold, int maxRed, int maxGreen, int maxBlue);
/*
*/
typedef double(*PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_RGB_NAME_D)(const char* path, double frameId, double minThreshold, double minRed, double minGreen, double minBlue, double maxThreshold, double maxRed, double maxGreen, double maxBlue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_NAME)(const char* path, int frameId, int threshold, int color);
/*
*/
typedef double(*PLUGIN_FILL_THRESHOLD_COLORS_NAME_D)(const char* path, double frameId, double threshold, double color);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_RGB)(int animationId, int frameId, int threshold, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_COLORS_RGB_NAME)(const char* path, int frameId, int threshold, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_FILL_THRESHOLD_COLORS_RGB_NAME_D)(const char* path, double frameId, double threshold, double red, double green, double blue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_RGB_COLORS_ALL_FRAMES_RGB)(int animationId, int redThreshold, int greenThreshold, int blueThreshold, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_RGB_COLORS_ALL_FRAMES_RGB_NAME)(const char* path, int redThreshold, int greenThreshold, int blueThreshold, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_FILL_THRESHOLD_RGB_COLORS_ALL_FRAMES_RGB_NAME_D)(const char* path, double redThreshold, double greenThreshold, double blueThreshold, double red, double green, double blue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_RGB_COLORS_RGB)(int animationId, int frameId, int redThreshold, int greenThreshold, int blueThreshold, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_FILL_THRESHOLD_RGB_COLORS_RGB_NAME)(const char* path, int frameId, int redThreshold, int greenThreshold, int blueThreshold, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_FILL_THRESHOLD_RGB_COLORS_RGB_NAME_D)(const char* path, double frameId, double redThreshold, double greenThreshold, double blueThreshold, double red, double green, double blue);
/*
*/
typedef void(*PLUGIN_FILL_ZERO_COLOR)(int animationId, int frameId, int color);
/*
*/
typedef void(*PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES)(int animationId, int color);
/*
*/
typedef void(*PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES_NAME)(const char* path, int color);
/*
*/
typedef double(*PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES_NAME_D)(const char* path, double color);
/*
*/
typedef void(*PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES_RGB)(int animationId, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES_RGB_NAME)(const char* path, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES_RGB_NAME_D)(const char* path, double red, double green, double blue);
/*
*/
typedef void(*PLUGIN_FILL_ZERO_COLOR_NAME)(const char* path, int frameId, int color);
/*
*/
typedef double(*PLUGIN_FILL_ZERO_COLOR_NAME_D)(const char* path, double frameId, double color);
/*
*/
typedef void(*PLUGIN_FILL_ZERO_COLOR_RGB)(int animationId, int frameId, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_FILL_ZERO_COLOR_RGB_NAME)(const char* path, int frameId, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_FILL_ZERO_COLOR_RGB_NAME_D)(const char* path, double frameId, double red, double green, double blue);
/*
*/
typedef int(*PLUGIN_GET_1D_COLOR)(int animationId, int frameId, int led);
/*
	Get the animation color for a frame given the `1D` `led`. The `led` should
	be greater than or equal to 0 and less than the `MaxLeds`.
*/
typedef int(*PLUGIN_GET_1D_COLOR_NAME)(const char* path, int frameId, int led);
/*
*/
typedef double(*PLUGIN_GET_1D_COLOR_NAME_D)(const char* path, double frameId, double led);
/*
*/
typedef int(*PLUGIN_GET_2D_COLOR)(int animationId, int frameId, int row, int column);
/*
	Get the animation color for a frame given the `2D` `row` and `column`. The
	`row` should be greater than or equal to 0 and less than the `MaxRow`.
	The `column` should be greater than or equal to 0 and less than the `MaxColumn`.
*/
typedef int(*PLUGIN_GET_2D_COLOR_NAME)(const char* path, int frameId, int row, int column);
/*
*/
typedef double(*PLUGIN_GET_2D_COLOR_NAME_D)(const char* path, double frameId, double row, double column);
/*
*/
typedef int(*PLUGIN_GET_ANIMATION)(const char* name);
/*
	`PluginGetAnimationCount` will return the number of loaded animations.
*/
typedef int(*PLUGIN_GET_ANIMATION_COUNT)();
/*
*/
typedef double(*PLUGIN_GET_ANIMATION_D)(const char* name);
/*
	`PluginGetAnimationId` will return the `animationId` given the `index` of
	the loaded animation. The `index` is zero-based and less than the number
	returned by `PluginGetAnimationCount`. Use `PluginGetAnimationName` to
	get the name of the animation.
*/
typedef int(*PLUGIN_GET_ANIMATION_ID)(int index);
/*
	`PluginGetAnimationName` takes an `animationId` and returns the name of
	the animation of the `.chroma` animation file. If a name is not available
	then an empty string will be returned.
*/
typedef const char*	(*PLUGIN_GET_ANIMATION_NAME)(int animationId);
/*
	Get the current frame of the animation referenced by id.
*/
typedef int(*PLUGIN_GET_CURRENT_FRAME)(int animationId);
/*
	Get the current frame of the animation referenced by name.
*/
typedef int(*PLUGIN_GET_CURRENT_FRAME_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_GET_CURRENT_FRAME_NAME_D)(const char* path);
/*
	Returns the `EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` of a `Chroma`
	animation respective to the `deviceType`, as an integer upon success. Returns
	-1 upon failure.
*/
typedef int(*PLUGIN_GET_DEVICE)(int animationId);
/*
	Returns the `EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` of a `Chroma`
	animation respective to the `deviceType`, as an integer upon success. Returns
	-1 upon failure.
*/
typedef int(*PLUGIN_GET_DEVICE_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_GET_DEVICE_NAME_D)(const char* path);
/*
	Returns the `EChromaSDKDeviceTypeEnum` of a `Chroma` animation as an integer
	upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_GET_DEVICE_TYPE)(int animationId);
/*
	Returns the `EChromaSDKDeviceTypeEnum` of a `Chroma` animation as an integer
	upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_GET_DEVICE_TYPE_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_GET_DEVICE_TYPE_NAME_D)(const char* path);
/*
	Gets the frame colors and duration (in seconds) for a `Chroma` animation.
	The `color` is expected to be an array of the expected dimensions for the
	`deviceType/device`. The `length` parameter is the size of the `color`
	array. For `EChromaSDKDevice1DEnum` the array size should be `MAX LEDS`.
	For `EChromaSDKDevice2DEnum` the array size should be `MAX ROW` * `MAX
	COLUMN`. Returns the animation id upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_GET_FRAME)(int animationId, int frameIndex, float* duration, int* colors, int length);
/*
	Returns the frame count of a `Chroma` animation upon success. Returns -1
	upon failure.
*/
typedef int(*PLUGIN_GET_FRAME_COUNT)(int animationId);
/*
	Returns the frame count of a `Chroma` animation upon success. Returns -1
	upon failure.
*/
typedef int(*PLUGIN_GET_FRAME_COUNT_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_GET_FRAME_COUNT_NAME_D)(const char* path);
/*
	Get the color of an animation key for the given frame referenced by id.
*/
typedef int(*PLUGIN_GET_KEY_COLOR)(int animationId, int frameId, int rzkey);
/*
*/
typedef double(*PLUGIN_GET_KEY_COLOR_D)(const char* path, double frameId, double rzkey);
/*
	Get the color of an animation key for the given frame referenced by name.
*/
typedef int(*PLUGIN_GET_KEY_COLOR_NAME)(const char* path, int frameId, int rzkey);
/*
	Returns the `MAX COLUMN` given the `EChromaSDKDevice2DEnum` device as an
	integer upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_GET_MAX_COLUMN)(int device);
/*
*/
typedef double(*PLUGIN_GET_MAX_COLUMN_D)(double device);
/*
	Returns the MAX LEDS given the `EChromaSDKDevice1DEnum` device as an integer
	upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_GET_MAX_LEDS)(int device);
/*
*/
typedef double(*PLUGIN_GET_MAX_LEDS_D)(double device);
/*
	Returns the `MAX ROW` given the `EChromaSDKDevice2DEnum` device as an integer
	upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_GET_MAX_ROW)(int device);
/*
*/
typedef double(*PLUGIN_GET_MAX_ROW_D)(double device);
/*
	`PluginGetPlayingAnimationCount` will return the number of playing animations.
*/
typedef int(*PLUGIN_GET_PLAYING_ANIMATION_COUNT)();
/*
*/
typedef int(*PLUGIN_GET_PLAYING_ANIMATION_ID)(int index);
/*
	`PluginGetPlayingAnimationId` will return the `animationId` given the `index`
	of the playing animation. The `index` is zero-based and less than the number
	returned by `PluginGetPlayingAnimationCount`. Use `PluginGetAnimationName`
	to get the name of the animation.
*/
typedef int(*PLUGIN_GET_RGB)(int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_GET_RGBD)(double red, double green, double blue);
/*
	Check if the animation has loop enabled referenced by id.
*/
typedef bool(*PLUGIN_HAS_ANIMATION_LOOP)(int animationId);
/*
	Check if the animation has loop enabled referenced by name.
*/
typedef bool(*PLUGIN_HAS_ANIMATION_LOOP_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_HAS_ANIMATION_LOOP_NAME_D)(const char* path);
/*
	Initialize the ChromaSDK. Zero indicates  success, otherwise failure. Many
	API methods auto initialize the ChromaSDK if not already initialized.
*/
typedef int(*PLUGIN_INIT)();
/*
*/
typedef double(*PLUGIN_INIT_D)();
/*
*/
typedef void(*PLUGIN_INSERT_DELAY)(int animationId, int frameId, int delay);
/*
*/
typedef void(*PLUGIN_INSERT_DELAY_NAME)(const char* path, int frameId, int delay);
/*
*/
typedef double(*PLUGIN_INSERT_DELAY_NAME_D)(const char* path, double frameId, double delay);
/*
*/
typedef void(*PLUGIN_INSERT_FRAME)(int animationId, int sourceFrame, int targetFrame);
/*
*/
typedef void(*PLUGIN_INSERT_FRAME_NAME)(const char* path, int sourceFrame, int targetFrame);
/*
*/
typedef double(*PLUGIN_INSERT_FRAME_NAME_D)(const char* path, double sourceFrame, double targetFrame);
/*
*/
typedef void(*PLUGIN_INVERT_COLORS)(int animationId, int frameId);
/*
*/
typedef void(*PLUGIN_INVERT_COLORS_ALL_FRAMES)(int animationId);
/*
*/
typedef void(*PLUGIN_INVERT_COLORS_ALL_FRAMES_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_INVERT_COLORS_ALL_FRAMES_NAME_D)(const char* path);
/*
*/
typedef void(*PLUGIN_INVERT_COLORS_NAME)(const char* path, int frameId);
/*
*/
typedef double(*PLUGIN_INVERT_COLORS_NAME_D)(const char* path, double frameId);
/*
	Check if the animation is paused referenced by id.
*/
typedef bool(*PLUGIN_IS_ANIMATION_PAUSED)(int animationId);
/*
	Check if the animation is paused referenced by name.
*/
typedef bool(*PLUGIN_IS_ANIMATION_PAUSED_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_IS_ANIMATION_PAUSED_NAME_D)(const char* path);
/*
	The editor dialog is a non-blocking modal window, this method returns true
	if the modal window is open, otherwise false.
*/
typedef bool(*PLUGIN_IS_DIALOG_OPEN)();
/*
*/
typedef double(*PLUGIN_IS_DIALOG_OPEN_D)();
/*
	Returns true if the plugin has been initialized. Returns false if the plugin
	is uninitialized.
*/
typedef bool(*PLUGIN_IS_INITIALIZED)();
/*
*/
typedef double(*PLUGIN_IS_INITIALIZED_D)();
/*
	If the method can be invoked the method returns true.
*/
typedef bool(*PLUGIN_IS_PLATFORM_SUPPORTED)();
/*
*/
typedef double(*PLUGIN_IS_PLATFORM_SUPPORTED_D)();
/*
*/
typedef bool(*PLUGIN_IS_PLAYING)(int animationId);
/*
*/
typedef double(*PLUGIN_IS_PLAYING_D)(double animationId);
/*
	`PluginIsPlayingName` automatically handles initializing the `ChromaSDK`.
	The named `.chroma` animation file will be automatically opened. The method
	will return whether the animation is playing or not.
*/
typedef bool(*PLUGIN_IS_PLAYING_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_IS_PLAYING_NAME_D)(const char* path);
/*
	`PluginIsPlayingType` automatically handles initializing the `ChromaSDK`.
	If any animation is playing for the `deviceType` and `device` combination,
	the method will return true, otherwise false.
*/
typedef bool(*PLUGIN_IS_PLAYING_TYPE)(int deviceType, int device);
/*
*/
typedef double(*PLUGIN_IS_PLAYING_TYPE_D)(double deviceType, double device);
/*
*/
typedef float(*PLUGIN_LERP)(float start, float end, float amt);
/*
*/
typedef int(*PLUGIN_LERP_COLOR)(int from, int to, float t);
/*
	Loads `Chroma` effects so that the animation can be played immediately.
	Returns the animation id upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_LOAD_ANIMATION)(int animationId);
/*
*/
typedef double(*PLUGIN_LOAD_ANIMATION_D)(double animationId);
/*
*/
typedef void(*PLUGIN_LOAD_ANIMATION_NAME)(const char* path);
/*
*/
typedef void(*PLUGIN_LOAD_COMPOSITE)(const char* name);
/*
*/
typedef void(*PLUGIN_MAKE_BLANK_FRAMES)(int animationId, int frameCount, float duration, int color);
/*
*/
typedef void(*PLUGIN_MAKE_BLANK_FRAMES_NAME)(const char* path, int frameCount, float duration, int color);
/*
*/
typedef double(*PLUGIN_MAKE_BLANK_FRAMES_NAME_D)(const char* path, double frameCount, double duration, double color);
/*
*/
typedef void(*PLUGIN_MAKE_BLANK_FRAMES_RANDOM)(int animationId, int frameCount, float duration);
/*
*/
typedef void(*PLUGIN_MAKE_BLANK_FRAMES_RANDOM_BLACK_AND_WHITE)(int animationId, int frameCount, float duration);
/*
*/
typedef void(*PLUGIN_MAKE_BLANK_FRAMES_RANDOM_BLACK_AND_WHITE_NAME)(const char* path, int frameCount, float duration);
/*
*/
typedef double(*PLUGIN_MAKE_BLANK_FRAMES_RANDOM_BLACK_AND_WHITE_NAME_D)(const char* path, double frameCount, double duration);
/*
*/
typedef void(*PLUGIN_MAKE_BLANK_FRAMES_RANDOM_NAME)(const char* path, int frameCount, float duration);
/*
*/
typedef double(*PLUGIN_MAKE_BLANK_FRAMES_RANDOM_NAME_D)(const char* path, double frameCount, double duration);
/*
*/
typedef void(*PLUGIN_MAKE_BLANK_FRAMES_RGB)(int animationId, int frameCount, float duration, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_MAKE_BLANK_FRAMES_RGB_NAME)(const char* path, int frameCount, float duration, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_MAKE_BLANK_FRAMES_RGB_NAME_D)(const char* path, double frameCount, double duration, double red, double green, double blue);
/*
	Flips the color grid horizontally for all `Chroma` animation frames. Returns
	the animation id upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_MIRROR_HORIZONTALLY)(int animationId);
/*
	Flips the color grid vertically for all `Chroma` animation frames. This
	method has no effect for `EChromaSDKDevice1DEnum` devices. Returns the
	animation id upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_MIRROR_VERTICALLY)(int animationId);
/*
*/
typedef void(*PLUGIN_MULTIPLY_COLOR_LERP_ALL_FRAMES)(int animationId, int color1, int color2);
/*
*/
typedef void(*PLUGIN_MULTIPLY_COLOR_LERP_ALL_FRAMES_NAME)(const char* path, int color1, int color2);
/*
*/
typedef double(*PLUGIN_MULTIPLY_COLOR_LERP_ALL_FRAMES_NAME_D)(const char* path, double color1, double color2);
/*
	Multiply all the colors in the frame by the intensity value. The valid the
	intensity range is from 0.0 to 255.0. RGB components are multiplied equally.
	An intensity of 0.5 would half the color value. Black colors in the frame
	will not be affected by this method.
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY)(int animationId, int frameId, float intensity);
/*
	Multiply all the colors for all frames by the intensity value. The valid
	the intensity range is from 0.0 to 255.0. RGB components are multiplied
	equally. An intensity of 0.5 would half the color value. Black colors in
	the frame will not be affected by this method.
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES)(int animationId, float intensity);
/*
	Multiply all the colors for all frames by the intensity value. The valid
	the intensity range is from 0.0 to 255.0. RGB components are multiplied
	equally. An intensity of 0.5 would half the color value. Black colors in
	the frame will not be affected by this method.
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES_NAME)(const char* path, float intensity);
/*
*/
typedef double(*PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES_NAME_D)(const char* path, double intensity);
/*
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES_RGB)(int animationId, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES_RGB_NAME)(const char* path, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES_RGB_NAME_D)(const char* path, double red, double green, double blue);
/*
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_COLOR)(int animationId, int frameId, int color);
/*
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_COLOR_ALL_FRAMES)(int animationId, int color);
/*
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_COLOR_ALL_FRAMES_NAME)(const char* path, int color);
/*
*/
typedef double(*PLUGIN_MULTIPLY_INTENSITY_COLOR_ALL_FRAMES_NAME_D)(const char* path, double color);
/*
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_COLOR_NAME)(const char* path, int frameId, int color);
/*
*/
typedef double(*PLUGIN_MULTIPLY_INTENSITY_COLOR_NAME_D)(const char* path, double frameId, double color);
/*
	Multiply all the colors in the frame by the intensity value. The valid the
	intensity range is from 0.0 to 255.0. RGB components are multiplied equally.
	An intensity of 0.5 would half the color value. Black colors in the frame
	will not be affected by this method.
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_NAME)(const char* path, int frameId, float intensity);
/*
*/
typedef double(*PLUGIN_MULTIPLY_INTENSITY_NAME_D)(const char* path, double frameId, double intensity);
/*
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_RGB)(int animationId, int frameId, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_MULTIPLY_INTENSITY_RGB_NAME)(const char* path, int frameId, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_MULTIPLY_INTENSITY_RGB_NAME_D)(const char* path, double frameId, double red, double green, double blue);
/*
*/
typedef void(*PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP)(int animationId, int frameId, int color1, int color2);
/*
*/
typedef void(*PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES)(int animationId, int color1, int color2);
/*
*/
typedef void(*PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES_NAME)(const char* path, int color1, int color2);
/*
*/
typedef double(*PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES_NAME_D)(const char* path, double color1, double color2);
/*
*/
typedef void(*PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES_RGB)(int animationId, int red1, int green1, int blue1, int red2, int green2, int blue2);
/*
*/
typedef void(*PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES_RGB_NAME)(const char* path, int red1, int green1, int blue1, int red2, int green2, int blue2);
/*
*/
typedef double(*PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES_RGB_NAME_D)(const char* path, double red1, double green1, double blue1, double red2, double green2, double blue2);
/*
*/
typedef void(*PLUGIN_MULTIPLY_TARGET_COLOR_LERP)(int animationId, int frameId, int color1, int color2);
/*
*/
typedef void(*PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES)(int animationId, int color1, int color2);
/*
*/
typedef void(*PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES_NAME)(const char* path, int color1, int color2);
/*
*/
typedef double(*PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES_NAME_D)(const char* path, double color1, double color2);
/*
*/
typedef void(*PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES_RGB)(int animationId, int red1, int green1, int blue1, int red2, int green2, int blue2);
/*
*/
typedef void(*PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES_RGB_NAME)(const char* path, int red1, int green1, int blue1, int red2, int green2, int blue2);
/*
*/
typedef double(*PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES_RGB_NAME_D)(const char* path, double red1, double green1, double blue1, double red2, double green2, double blue2);
/*
	Offset all colors in the frame using the RGB offset. Use the range of -255
	to 255 for red, green, and blue parameters. Negative values remove color.
	Positive values add color.
*/
typedef void(*PLUGIN_OFFSET_COLORS)(int animationId, int frameId, int red, int green, int blue);
/*
	Offset all colors for all frames using the RGB offset. Use the range of
	-255 to 255 for red, green, and blue parameters. Negative values remove
	color. Positive values add color.
*/
typedef void(*PLUGIN_OFFSET_COLORS_ALL_FRAMES)(int animationId, int red, int green, int blue);
/*
	Offset all colors for all frames using the RGB offset. Use the range of
	-255 to 255 for red, green, and blue parameters. Negative values remove
	color. Positive values add color.
*/
typedef void(*PLUGIN_OFFSET_COLORS_ALL_FRAMES_NAME)(const char* path, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_OFFSET_COLORS_ALL_FRAMES_NAME_D)(const char* path, double red, double green, double blue);
/*
	Offset all colors in the frame using the RGB offset. Use the range of -255
	to 255 for red, green, and blue parameters. Negative values remove color.
	Positive values add color.
*/
typedef void(*PLUGIN_OFFSET_COLORS_NAME)(const char* path, int frameId, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_OFFSET_COLORS_NAME_D)(const char* path, double frameId, double red, double green, double blue);
/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors in the frame using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
*/
typedef void(*PLUGIN_OFFSET_NON_ZERO_COLORS)(int animationId, int frameId, int red, int green, int blue);
/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors for all frames using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
*/
typedef void(*PLUGIN_OFFSET_NON_ZERO_COLORS_ALL_FRAMES)(int animationId, int red, int green, int blue);
/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors for all frames using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
*/
typedef void(*PLUGIN_OFFSET_NON_ZERO_COLORS_ALL_FRAMES_NAME)(const char* path, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_OFFSET_NON_ZERO_COLORS_ALL_FRAMES_NAME_D)(const char* path, double red, double green, double blue);
/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors in the frame using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
*/
typedef void(*PLUGIN_OFFSET_NON_ZERO_COLORS_NAME)(const char* path, int frameId, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_OFFSET_NON_ZERO_COLORS_NAME_D)(const char* path, double frameId, double red, double green, double blue);
/*
	Opens a `Chroma` animation file so that it can be played. Returns an animation
	id >= 0 upon success. Returns -1 if there was a failure. The animation
	id is used in most of the API methods.
*/
typedef int(*PLUGIN_OPEN_ANIMATION)(const char* path);
/*
*/
typedef double(*PLUGIN_OPEN_ANIMATION_D)(const char* path);
/*
	Opens a `Chroma` animation file with the `.chroma` extension. Returns zero
	upon success. Returns -1 if there was a failure.
*/
typedef int(*PLUGIN_OPEN_EDITOR_DIALOG)(const char* path);
/*
*/
typedef int(*PLUGIN_OPEN_EDITOR_DIALOG_AND_PLAY)(const char* path);
/*
*/
typedef double(*PLUGIN_OPEN_EDITOR_DIALOG_AND_PLAY_D)(const char* path);
/*
*/
typedef double(*PLUGIN_OPEN_EDITOR_DIALOG_D)(const char* path);
/*
	Sets the `duration` for all grames in the `Chroma` animation to the `duration`
	parameter. Returns the animation id upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_OVERRIDE_FRAME_DURATION)(int animationId, float duration);
/*
*/
typedef double(*PLUGIN_OVERRIDE_FRAME_DURATION_D)(double animationId, double duration);
/*
*/
typedef void(*PLUGIN_OVERRIDE_FRAME_DURATION_NAME)(const char* path, float duration);
/*
	Pause the current animation referenced by id.
*/
typedef void(*PLUGIN_PAUSE_ANIMATION)(int animationId);
/*
	Pause the current animation referenced by name.
*/
typedef void(*PLUGIN_PAUSE_ANIMATION_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_PAUSE_ANIMATION_NAME_D)(const char* path);
/*
	Plays the `Chroma` animation. This will load the animation, if not loaded
	previously. Returns the animation id upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_PLAY_ANIMATION)(int animationId);
/*
*/
typedef double(*PLUGIN_PLAY_ANIMATION_D)(double animationId);
/*
	`PluginPlayAnimationFrame` automatically handles initializing the `ChromaSDK`.
	The method will play the animation given the `animationId` with looping
	`on` or `off` starting at the `frameId`.
*/
typedef void(*PLUGIN_PLAY_ANIMATION_FRAME)(int animationId, int frameId, bool loop);
/*
	`PluginPlayAnimationFrameName` automatically handles initializing the `ChromaSDK`.
	The named `.chroma` animation file will be automatically opened. The animation
	will play with looping `on` or `off` starting at the `frameId`.
*/
typedef void(*PLUGIN_PLAY_ANIMATION_FRAME_NAME)(const char* path, int frameId, bool loop);
/*
*/
typedef double(*PLUGIN_PLAY_ANIMATION_FRAME_NAME_D)(const char* path, double frameId, double loop);
/*
	`PluginPlayAnimationLoop` automatically handles initializing the `ChromaSDK`.
	The method will play the animation given the `animationId` with looping
	`on` or `off`.
*/
typedef void(*PLUGIN_PLAY_ANIMATION_LOOP)(int animationId, bool loop);
/*
	`PluginPlayAnimationName` automatically handles initializing the `ChromaSDK`.
	The named `.chroma` animation file will be automatically opened. The animation
	will play with looping `on` or `off`.
*/
typedef void(*PLUGIN_PLAY_ANIMATION_NAME)(const char* path, bool loop);
/*
*/
typedef double(*PLUGIN_PLAY_ANIMATION_NAME_D)(const char* path, double loop);
/*
	`PluginPlayComposite` automatically handles initializing the `ChromaSDK`.
	The named animation files for the `.chroma` set will be automatically opened.
	The set of animations will play with looping `on` or `off`.
*/
typedef void(*PLUGIN_PLAY_COMPOSITE)(const char* name, bool loop);
/*
*/
typedef double(*PLUGIN_PLAY_COMPOSITE_D)(const char* name, double loop);
/*
	Displays the `Chroma` animation frame on `Chroma` hardware given the `frameIndex`.
	Returns the animation id upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_PREVIEW_FRAME)(int animationId, int frameIndex);
/*
*/
typedef double(*PLUGIN_PREVIEW_FRAME_D)(double animationId, double frameIndex);
/*
*/
typedef void(*PLUGIN_PREVIEW_FRAME_NAME)(const char* path, int frameIndex);
/*
*/
typedef void(*PLUGIN_REDUCE_FRAMES)(int animationId, int n);
/*
*/
typedef void(*PLUGIN_REDUCE_FRAMES_NAME)(const char* path, int n);
/*
*/
typedef double(*PLUGIN_REDUCE_FRAMES_NAME_D)(const char* path, double n);
/*
	Resets the `Chroma` animation to 1 blank frame. Returns the animation id
	upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_RESET_ANIMATION)(int animationId);
/*
	Resume the animation with loop `ON` or `OFF` referenced by id.
*/
typedef void(*PLUGIN_RESUME_ANIMATION)(int animationId, bool loop);
/*
	Resume the animation with loop `ON` or `OFF` referenced by name.
*/
typedef void(*PLUGIN_RESUME_ANIMATION_NAME)(const char* path, bool loop);
/*
*/
typedef double(*PLUGIN_RESUME_ANIMATION_NAME_D)(const char* path, double loop);
/*
	Reverse the animation frame order of the `Chroma` animation. Returns the
	animation id upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_REVERSE)(int animationId);
/*
*/
typedef void(*PLUGIN_REVERSE_ALL_FRAMES)(int animationId);
/*
*/
typedef void(*PLUGIN_REVERSE_ALL_FRAMES_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_REVERSE_ALL_FRAMES_NAME_D)(const char* path);
/*
*/
typedef int(*PLUGIN_SAVE_ANIMATION)(int animationId, const char* path);
/*
*/
typedef int(*PLUGIN_SAVE_ANIMATION_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef void(*PLUGIN_SET_1D_COLOR)(int animationId, int frameId, int led, int color);
/*
	Set the animation color for a frame given the `1D` `led`. The `led` should
	be greater than or equal to 0 and less than the `MaxLeds`.
*/
typedef void(*PLUGIN_SET_1D_COLOR_NAME)(const char* path, int frameId, int led, int color);
/*
*/
typedef double(*PLUGIN_SET_1D_COLOR_NAME_D)(const char* path, double frameId, double led, double color);
/*
*/
typedef void(*PLUGIN_SET_2D_COLOR)(int animationId, int frameId, int row, int column, int color);
/*
	Set the animation color for a frame given the `2D` `row` and `column`. The
	`row` should be greater than or equal to 0 and less than the `MaxRow`.
	The `column` should be greater than or equal to 0 and less than the `MaxColumn`.
*/
typedef void(*PLUGIN_SET_2D_COLOR_NAME)(const char* path, int frameId, int row, int column, int color);
/*
*/
typedef double(*PLUGIN_SET_2D_COLOR_NAME_D)(const char* path, double frameId, double rowColumnIndex, double color);
/*
*/
typedef void(*PLUGIN_SET_CHROMA_CUSTOM_COLOR_ALL_FRAMES)(int animationId);
/*
*/
typedef void(*PLUGIN_SET_CHROMA_CUSTOM_COLOR_ALL_FRAMES_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_SET_CHROMA_CUSTOM_COLOR_ALL_FRAMES_NAME_D)(const char* path);
/*
*/
typedef void(*PLUGIN_SET_CHROMA_CUSTOM_FLAG)(int animationId, bool flag);
/*
*/
typedef void(*PLUGIN_SET_CHROMA_CUSTOM_FLAG_NAME)(const char* path, bool flag);
/*
*/
typedef double(*PLUGIN_SET_CHROMA_CUSTOM_FLAG_NAME_D)(const char* path, double flag);
/*
	Set the current frame of the animation referenced by id.
*/
typedef void(*PLUGIN_SET_CURRENT_FRAME)(int animationId, int frameId);
/*
	Set the current frame of the animation referenced by name.
*/
typedef void(*PLUGIN_SET_CURRENT_FRAME_NAME)(const char* path, int frameId);
/*
*/
typedef double(*PLUGIN_SET_CURRENT_FRAME_NAME_D)(const char* path, double frameId);
/*
	Changes the `deviceType` and `device` of a `Chroma` animation. If the device
	is changed, the `Chroma` animation will be reset with 1 blank frame. Returns
	the animation id upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_SET_DEVICE)(int animationId, int deviceType, int device);
/*
*/
typedef RZRESULT(*PLUGIN_SET_EFFECT)(const ChromaSDK::FChromaSDKGuid& effectId);
/*
	Set animation key to a static color for the given frame.
*/
typedef void(*PLUGIN_SET_KEY_COLOR)(int animationId, int frameId, int rzkey, int color);
/*
*/
typedef void(*PLUGIN_SET_KEY_COLOR_ALL_FRAMES)(int animationId, int rzkey, int color);
/*
*/
typedef void(*PLUGIN_SET_KEY_COLOR_ALL_FRAMES_NAME)(const char* path, int rzkey, int color);
/*
*/
typedef double(*PLUGIN_SET_KEY_COLOR_ALL_FRAMES_NAME_D)(const char* path, double rzkey, double color);
/*
*/
typedef void(*PLUGIN_SET_KEY_COLOR_ALL_FRAMES_RGB)(int animationId, int rzkey, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEY_COLOR_ALL_FRAMES_RGB_NAME)(const char* path, int rzkey, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_SET_KEY_COLOR_ALL_FRAMES_RGB_NAME_D)(const char* path, double rzkey, double red, double green, double blue);
/*
	Set animation key to a static color for the given frame.
*/
typedef void(*PLUGIN_SET_KEY_COLOR_NAME)(const char* path, int frameId, int rzkey, int color);
/*
*/
typedef double(*PLUGIN_SET_KEY_COLOR_NAME_D)(const char* path, double frameId, double rzkey, double color);
/*
*/
typedef void(*PLUGIN_SET_KEY_COLOR_RGB)(int animationId, int frameId, int rzkey, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEY_COLOR_RGB_NAME)(const char* path, int frameId, int rzkey, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_SET_KEY_COLOR_RGB_NAME_D)(const char* path, double frameId, double rzkey, double red, double green, double blue);
/*
	Set animation key to a static color for the given frame if the existing
	color is not already black.
*/
typedef void(*PLUGIN_SET_KEY_NON_ZERO_COLOR)(int animationId, int frameId, int rzkey, int color);
/*
	Set animation key to a static color for the given frame if the existing
	color is not already black.
*/
typedef void(*PLUGIN_SET_KEY_NON_ZERO_COLOR_NAME)(const char* path, int frameId, int rzkey, int color);
/*
*/
typedef double(*PLUGIN_SET_KEY_NON_ZERO_COLOR_NAME_D)(const char* path, double frameId, double rzkey, double color);
/*
*/
typedef void(*PLUGIN_SET_KEY_NON_ZERO_COLOR_RGB)(int animationId, int frameId, int rzkey, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEY_NON_ZERO_COLOR_RGB_NAME)(const char* path, int frameId, int rzkey, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_SET_KEY_NON_ZERO_COLOR_RGB_NAME_D)(const char* path, double frameId, double rzkey, double red, double green, double blue);
/*
	Set an array of animation keys to a static color for the given frame.
*/
typedef void(*PLUGIN_SET_KEYS_COLOR)(int animationId, int frameId, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_COLOR_ALL_FRAMES)(int animationId, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_COLOR_ALL_FRAMES_NAME)(const char* path, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_COLOR_ALL_FRAMES_RGB)(int animationId, const int* rzkeys, int keyCount, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEYS_COLOR_ALL_FRAMES_RGB_NAME)(const char* path, const int* rzkeys, int keyCount, int red, int green, int blue);
/*
	Set an array of animation keys to a static color for the given frame.
*/
typedef void(*PLUGIN_SET_KEYS_COLOR_NAME)(const char* path, int frameId, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_COLOR_RGB)(int animationId, int frameId, const int* rzkeys, int keyCount, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEYS_COLOR_RGB_NAME)(const char* path, int frameId, const int* rzkeys, int keyCount, int red, int green, int blue);
/*
	Set an array of animation keys to a static color for the given frame if
	the existing color is not already black.
*/
typedef void(*PLUGIN_SET_KEYS_NON_ZERO_COLOR)(int animationId, int frameId, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_NON_ZERO_COLOR_ALL_FRAMES)(int animationId, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_NON_ZERO_COLOR_ALL_FRAMES_NAME)(const char* path, const int* rzkeys, int keyCount, int color);
/*
	Set an array of animation keys to a static color for the given frame if
	the existing color is not already black.
*/
typedef void(*PLUGIN_SET_KEYS_NON_ZERO_COLOR_NAME)(const char* path, int frameId, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_NON_ZERO_COLOR_RGB)(int animationId, int frameId, const int* rzkeys, int keyCount, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEYS_NON_ZERO_COLOR_RGB_NAME)(const char* path, int frameId, const int* rzkeys, int keyCount, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEYS_ZERO_COLOR)(int animationId, int frameId, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_ZERO_COLOR_ALL_FRAMES)(int animationId, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_ZERO_COLOR_ALL_FRAMES_NAME)(const char* path, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_ZERO_COLOR_ALL_FRAMES_RGB)(int animationId, const int* rzkeys, int keyCount, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEYS_ZERO_COLOR_ALL_FRAMES_RGB_NAME)(const char* path, const int* rzkeys, int keyCount, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEYS_ZERO_COLOR_NAME)(const char* path, int frameId, const int* rzkeys, int keyCount, int color);
/*
*/
typedef void(*PLUGIN_SET_KEYS_ZERO_COLOR_RGB)(int animationId, int frameId, const int* rzkeys, int keyCount, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEYS_ZERO_COLOR_RGB_NAME)(const char* path, int frameId, const int* rzkeys, int keyCount, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEY_ZERO_COLOR)(int animationId, int frameId, int rzkey, int color);
/*
*/
typedef void(*PLUGIN_SET_KEY_ZERO_COLOR_NAME)(const char* path, int frameId, int rzkey, int color);
/*
*/
typedef double(*PLUGIN_SET_KEY_ZERO_COLOR_NAME_D)(const char* path, double frameId, double rzkey, double color);
/*
*/
typedef void(*PLUGIN_SET_KEY_ZERO_COLOR_RGB)(int animationId, int frameId, int rzkey, int red, int green, int blue);
/*
*/
typedef void(*PLUGIN_SET_KEY_ZERO_COLOR_RGB_NAME)(const char* path, int frameId, int rzkey, int red, int green, int blue);
/*
*/
typedef double(*PLUGIN_SET_KEY_ZERO_COLOR_RGB_NAME_D)(const char* path, double frameId, double rzkey, double red, double green, double blue);
/*
	Invokes the setup for a debug logging callback so that `stdout` is redirected
	to the callback. This is used by `Unity` so that debug messages can appear
	in the console window.
*/
typedef void(*PLUGIN_SET_LOG_DELEGATE)(DebugLogPtr fp);
/*
	`PluginStopAll` will automatically stop all animations that are playing.
*/
typedef void(*PLUGIN_STOP_ALL)();
/*
	Stops animation playback if in progress. Returns the animation id upon success.
	Returns -1 upon failure.
*/
typedef int(*PLUGIN_STOP_ANIMATION)(int animationId);
/*
*/
typedef double(*PLUGIN_STOP_ANIMATION_D)(double animationId);
/*
	`PluginStopAnimationName` automatically handles initializing the `ChromaSDK`.
	The named `.chroma` animation file will be automatically opened. The animation
	will stop if playing.
*/
typedef void(*PLUGIN_STOP_ANIMATION_NAME)(const char* path);
/*
*/
typedef double(*PLUGIN_STOP_ANIMATION_NAME_D)(const char* path);
/*
	`PluginStopAnimationType` automatically handles initializing the `ChromaSDK`.
	If any animation is playing for the `deviceType` and `device` combination,
	it will be stopped.
*/
typedef void(*PLUGIN_STOP_ANIMATION_TYPE)(int deviceType, int device);
/*
*/
typedef double(*PLUGIN_STOP_ANIMATION_TYPE_D)(double deviceType, double device);
/*
	`PluginStopComposite` automatically handles initializing the `ChromaSDK`.
	The named animation files for the `.chroma` set will be automatically opened.
	The set of animations will be stopped if playing.
*/
typedef void(*PLUGIN_STOP_COMPOSITE)(const char* name);
/*
*/
typedef double(*PLUGIN_STOP_COMPOSITE_D)(const char* name);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES)(int sourceAnimationId, int targetAnimationId);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef double(*PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME_D)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET)(int sourceAnimationId, int targetAnimationId, int offset);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int offset);
/*
*/
typedef double(*PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double offset);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_OFFSET)(int sourceAnimationId, int targetAnimationId, int frameId, int offset);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId, int offset);
/*
*/
typedef double(*PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId, double offset);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES)(int sourceAnimationId, int targetAnimationId);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef double(*PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME_D)(const char* sourceAnimation, const char* targetAnimation);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET)(int sourceAnimationId, int targetAnimationId, int offset);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int offset);
/*
*/
typedef double(*PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double offset);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_OFFSET)(int sourceAnimationId, int targetAnimationId, int frameId, int offset);
/*
*/
typedef void(*PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME)(const char* sourceAnimation, const char* targetAnimation, int frameId, int offset);
/*
*/
typedef double(*PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME_D)(const char* sourceAnimation, const char* targetAnimation, double frameId, double offset);
/*
*/
typedef void(*PLUGIN_TRIM_END_FRAMES)(int animationId, int lastFrameId);
/*
*/
typedef void(*PLUGIN_TRIM_END_FRAMES_NAME)(const char* path, int lastFrameId);
/*
*/
typedef double(*PLUGIN_TRIM_END_FRAMES_NAME_D)(const char* path, double lastFrameId);
/*
*/
typedef void(*PLUGIN_TRIM_FRAME)(int animationId, int frameId);
/*
*/
typedef void(*PLUGIN_TRIM_FRAME_NAME)(const char* path, int frameId);
/*
*/
typedef double(*PLUGIN_TRIM_FRAME_NAME_D)(const char* path, double frameId);
/*
*/
typedef void(*PLUGIN_TRIM_START_FRAMES)(int animationId, int numberOfFrames);
/*
*/
typedef void(*PLUGIN_TRIM_START_FRAMES_NAME)(const char* path, int numberOfFrames);
/*
*/
typedef double(*PLUGIN_TRIM_START_FRAMES_NAME_D)(const char* path, double numberOfFrames);
/*
	Uninitializes the `ChromaSDK`. Returns 0 upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_UNINIT)();
/*
*/
typedef double(*PLUGIN_UNINIT_D)();
/*
	Unloads `Chroma` effects to free up resources. Returns the animation id
	upon success. Returns -1 upon failure.
*/
typedef int(*PLUGIN_UNLOAD_ANIMATION)(int animationId);
/*
*/
typedef double(*PLUGIN_UNLOAD_ANIMATION_D)(double animationId);
/*
*/
typedef void(*PLUGIN_UNLOAD_ANIMATION_NAME)(const char* path);
/*
*/
typedef void(*PLUGIN_UNLOAD_COMPOSITE)(const char* name);
/*
	Updates the `frameIndex` of the `Chroma` animation and sets the `duration`
	(in seconds). The `color` is expected to be an array of the dimensions
	for the `deviceType/device`. The `length` parameter is the size of the
	`color` array. For `EChromaSDKDevice1DEnum` the array size should be `MAX
	LEDS`. For `EChromaSDKDevice2DEnum` the array size should be `MAX ROW`
	* `MAX COLUMN`. Returns the animation id upon success. Returns -1 upon
	failure.
*/
typedef int(*PLUGIN_UPDATE_FRAME)(int animationId, int frameIndex, float duration, int* colors, int length);
#pragma endregion

#define CHROMASDK_DECLARE_METHOD(Signature, FieldName) static Signature FieldName;

namespace ChromaSDK
{
	class ChromaAnimationAPI
	{
	public:
		
#pragma region API declare prototypes
		/*
			Adds a frame to the `Chroma` animation and sets the `duration` (in seconds).
			The `color` is expected to be an array of the dimensions for the `deviceType/device`.
			The `length` parameter is the size of the `color` array. For `EChromaSDKDevice1DEnum`
			the array size should be `MAX LEDS`. For `EChromaSDKDevice2DEnum` the array
			size should be `MAX ROW` * `MAX COLUMN`. Returns the animation id upon
			success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_FRAME, AddFrame);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES, AddNonZeroAllKeysAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME, AddNonZeroAllKeysAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME_D, AddNonZeroAllKeysAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET, AddNonZeroAllKeysAllFramesOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME, AddNonZeroAllKeysAllFramesOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D, AddNonZeroAllKeysAllFramesOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_ALL_KEYS_OFFSET, AddNonZeroAllKeysOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_ALL_KEYS_OFFSET_NAME, AddNonZeroAllKeysOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_ALL_KEYS_OFFSET_NAME_D, AddNonZeroAllKeysOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES, AddNonZeroTargetAllKeysAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME, AddNonZeroTargetAllKeysAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME_D, AddNonZeroTargetAllKeysAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET, AddNonZeroTargetAllKeysAllFramesOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME, AddNonZeroTargetAllKeysAllFramesOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D, AddNonZeroTargetAllKeysAllFramesOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_OFFSET, AddNonZeroTargetAllKeysOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME, AddNonZeroTargetAllKeysOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_ADD_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME_D, AddNonZeroTargetAllKeysOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_APPEND_ALL_FRAMES, AppendAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_APPEND_ALL_FRAMES_NAME, AppendAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_APPEND_ALL_FRAMES_NAME_D, AppendAllFramesNameD);
		/*
			`PluginClearAll` will issue a `CLEAR` effect for all devices.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CLEAR_ALL, ClearAll);
		/*
			`PluginClearAnimationType` will issue a `CLEAR` effect for the given device.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CLEAR_ANIMATION_TYPE, ClearAnimationType);
		/*
			`PluginCloseAll` closes all open animations so they can be reloaded from
			disk. The set of animations will be stopped if playing.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CLOSE_ALL, CloseAll);
		/*
			Closes the `Chroma` animation to free up resources referenced by id. Returns
			the animation id upon success. Returns -1 upon failure. This might be used
			while authoring effects if there was a change necessitating re-opening
			the animation. The animation id can no longer be used once closed.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CLOSE_ANIMATION, CloseAnimation);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CLOSE_ANIMATION_D, CloseAnimationD);
		/*
			Closes the `Chroma` animation referenced by name so that the animation can
			be reloaded from disk.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CLOSE_ANIMATION_NAME, CloseAnimationName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CLOSE_ANIMATION_NAME_D, CloseAnimationNameD);
		/*
			`PluginCloseComposite` closes a set of animations so they can be reloaded
			from disk. The set of animations will be stopped if playing.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CLOSE_COMPOSITE, CloseComposite);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CLOSE_COMPOSITE_D, CloseCompositeD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ANIMATION, CopyAnimation);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ANIMATION_NAME, CopyAnimationName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ANIMATION_NAME_D, CopyAnimationNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_BLUE_CHANNEL_ALL_FRAMES, CopyBlueChannelAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_BLUE_CHANNEL_ALL_FRAMES_NAME, CopyBlueChannelAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_BLUE_CHANNEL_ALL_FRAMES_NAME_D, CopyBlueChannelAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_GREEN_CHANNEL_ALL_FRAMES, CopyGreenChannelAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_GREEN_CHANNEL_ALL_FRAMES_NAME, CopyGreenChannelAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_GREEN_CHANNEL_ALL_FRAMES_NAME_D, CopyGreenChannelAllFramesNameD);
		/*
			Copy animation key color from the source animation to the target animation
			for the given frame.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_KEY_COLOR, CopyKeyColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_KEY_COLOR_ALL_FRAMES, CopyKeyColorAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_KEY_COLOR_ALL_FRAMES_NAME, CopyKeyColorAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_KEY_COLOR_ALL_FRAMES_NAME_D, CopyKeyColorAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_KEY_COLOR_ALL_FRAMES_OFFSET, CopyKeyColorAllFramesOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_KEY_COLOR_ALL_FRAMES_OFFSET_NAME, CopyKeyColorAllFramesOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_KEY_COLOR_ALL_FRAMES_OFFSET_NAME_D, CopyKeyColorAllFramesOffsetNameD);
		/*
			Copy animation key color from the source animation to the target animation
			for the given frame.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_KEY_COLOR_NAME, CopyKeyColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_KEY_COLOR_NAME_D, CopyKeyColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS, CopyNonZeroAllKeys);
		/*
			Copy nonzero colors from a source animation to a target animation for all
			keys.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES, CopyNonZeroAllKeysAllFrames);
		/*
			Copy nonzero colors from a source animation to a target animation for all
			keys.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME, CopyNonZeroAllKeysAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME_D, CopyNonZeroAllKeysAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET, CopyNonZeroAllKeysAllFramesOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME, CopyNonZeroAllKeysAllFramesOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D, CopyNonZeroAllKeysAllFramesOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_NAME, CopyNonZeroAllKeysName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_NAME_D, CopyNonZeroAllKeysNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_OFFSET, CopyNonZeroAllKeysOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_OFFSET_NAME, CopyNonZeroAllKeysOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_ALL_KEYS_OFFSET_NAME_D, CopyNonZeroAllKeysOffsetNameD);
		/*
			Copy animation key color from the source animation to the target animation
			for the given frame where color is not zero.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_KEY_COLOR, CopyNonZeroKeyColor);
		/*
			Copy animation key color from the source animation to the target animation
			for the given frame where color is not zero.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_KEY_COLOR_NAME, CopyNonZeroKeyColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_KEY_COLOR_NAME_D, CopyNonZeroKeyColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS, CopyNonZeroTargetAllKeys);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES, CopyNonZeroTargetAllKeysAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME, CopyNonZeroTargetAllKeysAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME_D, CopyNonZeroTargetAllKeysAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET, CopyNonZeroTargetAllKeysAllFramesOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME, CopyNonZeroTargetAllKeysAllFramesOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D, CopyNonZeroTargetAllKeysAllFramesOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_NAME, CopyNonZeroTargetAllKeysName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_NAME_D, CopyNonZeroTargetAllKeysNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_OFFSET, CopyNonZeroTargetAllKeysOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME, CopyNonZeroTargetAllKeysOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME_D, CopyNonZeroTargetAllKeysOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_RED_CHANNEL_ALL_FRAMES, CopyRedChannelAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_RED_CHANNEL_ALL_FRAMES_NAME, CopyRedChannelAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_RED_CHANNEL_ALL_FRAMES_NAME_D, CopyRedChannelAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES, CopyZeroAllKeysAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES_NAME, CopyZeroAllKeysAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES_NAME_D, CopyZeroAllKeysAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET, CopyZeroAllKeysAllFramesOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME, CopyZeroAllKeysAllFramesOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D, CopyZeroAllKeysAllFramesOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_KEY_COLOR, CopyZeroKeyColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_KEY_COLOR_NAME, CopyZeroKeyColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_KEY_COLOR_NAME_D, CopyZeroKeyColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_TARGET_ALL_KEYS_ALL_FRAMES, CopyZeroTargetAllKeysAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME, CopyZeroTargetAllKeysAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_COPY_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME_D, CopyZeroTargetAllKeysAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_CREATE_CHROMA_LINK_EFFECT, CoreCreateChromaLinkEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_CREATE_EFFECT, CoreCreateEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_CREATE_HEADSET_EFFECT, CoreCreateHeadsetEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_CREATE_KEYBOARD_EFFECT, CoreCreateKeyboardEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_CREATE_KEYPAD_EFFECT, CoreCreateKeypadEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_CREATE_MOUSE_EFFECT, CoreCreateMouseEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_CREATE_MOUSEPAD_EFFECT, CoreCreateMousepadEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_DELETE_EFFECT, CoreDeleteEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_INIT, CoreInit);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_QUERY_DEVICE, CoreQueryDevice);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_SET_EFFECT, CoreSetEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CORE_UNINIT, CoreUnInit);
		/*
			Creates a `Chroma` animation at the given path. The `deviceType` parameter
			uses `EChromaSDKDeviceTypeEnum` as an integer. The `device` parameter uses
			`EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` as an integer, respective
			to the `deviceType`. Returns the animation id upon success. Returns -1
			upon failure. Saves a `Chroma` animation file with the `.chroma` extension
			at the given path. Returns the animation id upon success. Returns -1 upon
			failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CREATE_ANIMATION, CreateAnimation);
		/*
			Creates a `Chroma` animation in memory without creating a file. The `deviceType`
			parameter uses `EChromaSDKDeviceTypeEnum` as an integer. The `device` parameter
			uses `EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` as an integer,
			respective to the `deviceType`. Returns the animation id upon success.
			Returns -1 upon failure. Returns the animation id upon success. Returns
			-1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CREATE_ANIMATION_IN_MEMORY, CreateAnimationInMemory);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_CREATE_EFFECT, CreateEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_DELETE_EFFECT, DeleteEffect);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_DUPLICATE_FIRST_FRAME, DuplicateFirstFrame);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_DUPLICATE_FIRST_FRAME_NAME, DuplicateFirstFrameName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_DUPLICATE_FIRST_FRAME_NAME_D, DuplicateFirstFrameNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_DUPLICATE_FRAMES, DuplicateFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_DUPLICATE_FRAMES_NAME, DuplicateFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_DUPLICATE_FRAMES_NAME_D, DuplicateFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_DUPLICATE_MIRROR_FRAMES, DuplicateMirrorFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_DUPLICATE_MIRROR_FRAMES_NAME, DuplicateMirrorFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_DUPLICATE_MIRROR_FRAMES_NAME_D, DuplicateMirrorFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FADE_END_FRAMES, FadeEndFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FADE_END_FRAMES_NAME, FadeEndFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FADE_END_FRAMES_NAME_D, FadeEndFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FADE_START_FRAMES, FadeStartFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FADE_START_FRAMES_NAME, FadeStartFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FADE_START_FRAMES_NAME_D, FadeStartFramesNameD);
		/*
			Set the RGB value for all colors in the specified frame. Use the range of
			0 to 255 for red, green, and blue parameters.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR, FillColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_ALL_FRAMES, FillColorAllFrames);
		/*
			Set the RGB value for all colors for all frames.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_ALL_FRAMES_NAME, FillColorAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_ALL_FRAMES_NAME_D, FillColorAllFramesNameD);
		/*
			Set the RGB value for all colors for all frames. Use the range of 0 to 255
			for red, green, and blue parameters.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_ALL_FRAMES_RGB, FillColorAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_ALL_FRAMES_RGB_NAME, FillColorAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_ALL_FRAMES_RGB_NAME_D, FillColorAllFramesRGBNameD);
		/*
			Set the RGB value for all colors in the specified frame. Use a BGR integer
			for the color parameter. 0xFF0000 (blue) 0x00FF00 (green) 0x0000FF (red)
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_NAME, FillColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_NAME_D, FillColorNameD);
		/*
			Set the RGB value for all colors in the specified frame. Use the range of
			0 to 255 for red, green, and blue parameters.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_RGB, FillColorRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_RGB_NAME, FillColorRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_COLOR_RGB_NAME_D, FillColorRGBNameD);
		/*
			This method will only update colors in the animation that are not already
			set to black. Set the RGB value for a subset of colors in the specified
			frame.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR, FillNonZeroColor);
		/*
			This method will only update colors in the animation that are not already
			set to black. Set the RGB value for a subset of colors for all frames.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES, FillNonZeroColorAllFrames);
		/*
			This method will only update colors in the animation that are not already
			set to black. Set the RGB value for a subset of colors for all frames.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES_NAME, FillNonZeroColorAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES_NAME_D, FillNonZeroColorAllFramesNameD);
		/*
			This method will only update colors in the animation that are not already
			set to black. Set the RGB value for a subset of colors for all frames.
			Use the range of 0 to 255 for red, green, and blue parameters.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES_RGB, FillNonZeroColorAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES_RGB_NAME, FillNonZeroColorAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_ALL_FRAMES_RGB_NAME_D, FillNonZeroColorAllFramesRGBNameD);
		/*
			This method will only update colors in the animation that are not already
			set to black. Set the RGB value for a subset of colors in the specified
			frame.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_NAME, FillNonZeroColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_NAME_D, FillNonZeroColorNameD);
		/*
			This method will only update colors in the animation that are not already
			set to black. Set the RGB value for a subset of colors in the specified
			frame. Use the range of 0 to 255 for red, green, and blue parameters.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_RGB, FillNonZeroColorRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_RGB_NAME, FillNonZeroColorRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_NON_ZERO_COLOR_RGB_NAME_D, FillNonZeroColorRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS, FillRandomColors);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_ALL_FRAMES, FillRandomColorsAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_ALL_FRAMES_NAME, FillRandomColorsAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_ALL_FRAMES_NAME_D, FillRandomColorsAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE, FillRandomColorsBlackAndWhite);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE_ALL_FRAMES, FillRandomColorsBlackAndWhiteAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE_ALL_FRAMES_NAME, FillRandomColorsBlackAndWhiteAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE_ALL_FRAMES_NAME_D, FillRandomColorsBlackAndWhiteAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE_NAME, FillRandomColorsBlackAndWhiteName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_BLACK_AND_WHITE_NAME_D, FillRandomColorsBlackAndWhiteNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_NAME, FillRandomColorsName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_RANDOM_COLORS_NAME_D, FillRandomColorsNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS, FillThresholdColors);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES, FillThresholdColorsAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES_NAME, FillThresholdColorsAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES_NAME_D, FillThresholdColorsAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES_RGB, FillThresholdColorsAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES_RGB_NAME, FillThresholdColorsAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_ALL_FRAMES_RGB_NAME_D, FillThresholdColorsAllFramesRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_ALL_FRAMES_RGB, FillThresholdColorsMinMaxAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_ALL_FRAMES_RGB_NAME, FillThresholdColorsMinMaxAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_ALL_FRAMES_RGB_NAME_D, FillThresholdColorsMinMaxAllFramesRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_RGB, FillThresholdColorsMinMaxRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_RGB_NAME, FillThresholdColorsMinMaxRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_MIN_MAX_RGB_NAME_D, FillThresholdColorsMinMaxRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_NAME, FillThresholdColorsName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_NAME_D, FillThresholdColorsNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_RGB, FillThresholdColorsRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_RGB_NAME, FillThresholdColorsRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_COLORS_RGB_NAME_D, FillThresholdColorsRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_RGB_COLORS_ALL_FRAMES_RGB, FillThresholdRGBColorsAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_RGB_COLORS_ALL_FRAMES_RGB_NAME, FillThresholdRGBColorsAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_RGB_COLORS_ALL_FRAMES_RGB_NAME_D, FillThresholdRGBColorsAllFramesRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_RGB_COLORS_RGB, FillThresholdRGBColorsRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_RGB_COLORS_RGB_NAME, FillThresholdRGBColorsRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_THRESHOLD_RGB_COLORS_RGB_NAME_D, FillThresholdRGBColorsRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR, FillZeroColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES, FillZeroColorAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES_NAME, FillZeroColorAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES_NAME_D, FillZeroColorAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES_RGB, FillZeroColorAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES_RGB_NAME, FillZeroColorAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_ALL_FRAMES_RGB_NAME_D, FillZeroColorAllFramesRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_NAME, FillZeroColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_NAME_D, FillZeroColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_RGB, FillZeroColorRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_RGB_NAME, FillZeroColorRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_FILL_ZERO_COLOR_RGB_NAME_D, FillZeroColorRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_1D_COLOR, Get1DColor);
		/*
			Get the animation color for a frame given the `1D` `led`. The `led` should
			be greater than or equal to 0 and less than the `MaxLeds`.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_1D_COLOR_NAME, Get1DColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_1D_COLOR_NAME_D, Get1DColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_2D_COLOR, Get2DColor);
		/*
			Get the animation color for a frame given the `2D` `row` and `column`. The
			`row` should be greater than or equal to 0 and less than the `MaxRow`.
			The `column` should be greater than or equal to 0 and less than the `MaxColumn`.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_2D_COLOR_NAME, Get2DColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_2D_COLOR_NAME_D, Get2DColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_ANIMATION, GetAnimation);
		/*
			`PluginGetAnimationCount` will return the number of loaded animations.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_ANIMATION_COUNT, GetAnimationCount);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_ANIMATION_D, GetAnimationD);
		/*
			`PluginGetAnimationId` will return the `animationId` given the `index` of
			the loaded animation. The `index` is zero-based and less than the number
			returned by `PluginGetAnimationCount`. Use `PluginGetAnimationName` to
			get the name of the animation.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_ANIMATION_ID, GetAnimationId);
		/*
			`PluginGetAnimationName` takes an `animationId` and returns the name of
			the animation of the `.chroma` animation file. If a name is not available
			then an empty string will be returned.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_ANIMATION_NAME, GetAnimationName);
		/*
			Get the current frame of the animation referenced by id.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_CURRENT_FRAME, GetCurrentFrame);
		/*
			Get the current frame of the animation referenced by name.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_CURRENT_FRAME_NAME, GetCurrentFrameName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_CURRENT_FRAME_NAME_D, GetCurrentFrameNameD);
		/*
			Returns the `EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` of a `Chroma`
			animation respective to the `deviceType`, as an integer upon success. Returns
			-1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_DEVICE, GetDevice);
		/*
			Returns the `EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` of a `Chroma`
			animation respective to the `deviceType`, as an integer upon success. Returns
			-1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_DEVICE_NAME, GetDeviceName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_DEVICE_NAME_D, GetDeviceNameD);
		/*
			Returns the `EChromaSDKDeviceTypeEnum` of a `Chroma` animation as an integer
			upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_DEVICE_TYPE, GetDeviceType);
		/*
			Returns the `EChromaSDKDeviceTypeEnum` of a `Chroma` animation as an integer
			upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_DEVICE_TYPE_NAME, GetDeviceTypeName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_DEVICE_TYPE_NAME_D, GetDeviceTypeNameD);
		/*
			Gets the frame colors and duration (in seconds) for a `Chroma` animation.
			The `color` is expected to be an array of the expected dimensions for the
			`deviceType/device`. The `length` parameter is the size of the `color`
			array. For `EChromaSDKDevice1DEnum` the array size should be `MAX LEDS`.
			For `EChromaSDKDevice2DEnum` the array size should be `MAX ROW` * `MAX
			COLUMN`. Returns the animation id upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_FRAME, GetFrame);
		/*
			Returns the frame count of a `Chroma` animation upon success. Returns -1
			upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_FRAME_COUNT, GetFrameCount);
		/*
			Returns the frame count of a `Chroma` animation upon success. Returns -1
			upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_FRAME_COUNT_NAME, GetFrameCountName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_FRAME_COUNT_NAME_D, GetFrameCountNameD);
		/*
			Get the color of an animation key for the given frame referenced by id.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_KEY_COLOR, GetKeyColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_KEY_COLOR_D, GetKeyColorD);
		/*
			Get the color of an animation key for the given frame referenced by name.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_KEY_COLOR_NAME, GetKeyColorName);
		/*
			Returns the `MAX COLUMN` given the `EChromaSDKDevice2DEnum` device as an
			integer upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_MAX_COLUMN, GetMaxColumn);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_MAX_COLUMN_D, GetMaxColumnD);
		/*
			Returns the MAX LEDS given the `EChromaSDKDevice1DEnum` device as an integer
			upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_MAX_LEDS, GetMaxLeds);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_MAX_LEDS_D, GetMaxLedsD);
		/*
			Returns the `MAX ROW` given the `EChromaSDKDevice2DEnum` device as an integer
			upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_MAX_ROW, GetMaxRow);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_MAX_ROW_D, GetMaxRowD);
		/*
			`PluginGetPlayingAnimationCount` will return the number of playing animations.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_PLAYING_ANIMATION_COUNT, GetPlayingAnimationCount);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_PLAYING_ANIMATION_ID, GetPlayingAnimationId);
		/*
			`PluginGetPlayingAnimationId` will return the `animationId` given the `index`
			of the playing animation. The `index` is zero-based and less than the number
			returned by `PluginGetPlayingAnimationCount`. Use `PluginGetAnimationName`
			to get the name of the animation.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_RGB, GetRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_GET_RGBD, GetRGBD);
		/*
			Check if the animation has loop enabled referenced by id.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_HAS_ANIMATION_LOOP, HasAnimationLoop);
		/*
			Check if the animation has loop enabled referenced by name.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_HAS_ANIMATION_LOOP_NAME, HasAnimationLoopName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_HAS_ANIMATION_LOOP_NAME_D, HasAnimationLoopNameD);
		/*
			Initialize the ChromaSDK. Zero indicates  success, otherwise failure. Many
			API methods auto initialize the ChromaSDK if not already initialized.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INIT, Init);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INIT_D, InitD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INSERT_DELAY, InsertDelay);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INSERT_DELAY_NAME, InsertDelayName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INSERT_DELAY_NAME_D, InsertDelayNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INSERT_FRAME, InsertFrame);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INSERT_FRAME_NAME, InsertFrameName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INSERT_FRAME_NAME_D, InsertFrameNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INVERT_COLORS, InvertColors);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INVERT_COLORS_ALL_FRAMES, InvertColorsAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INVERT_COLORS_ALL_FRAMES_NAME, InvertColorsAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INVERT_COLORS_ALL_FRAMES_NAME_D, InvertColorsAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INVERT_COLORS_NAME, InvertColorsName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_INVERT_COLORS_NAME_D, InvertColorsNameD);
		/*
			Check if the animation is paused referenced by id.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_ANIMATION_PAUSED, IsAnimationPaused);
		/*
			Check if the animation is paused referenced by name.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_ANIMATION_PAUSED_NAME, IsAnimationPausedName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_ANIMATION_PAUSED_NAME_D, IsAnimationPausedNameD);
		/*
			The editor dialog is a non-blocking modal window, this method returns true
			if the modal window is open, otherwise false.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_DIALOG_OPEN, IsDialogOpen);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_DIALOG_OPEN_D, IsDialogOpenD);
		/*
			Returns true if the plugin has been initialized. Returns false if the plugin
			is uninitialized.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_INITIALIZED, IsInitialized);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_INITIALIZED_D, IsInitializedD);
		/*
			If the method can be invoked the method returns true.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_PLATFORM_SUPPORTED, IsPlatformSupported);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_PLATFORM_SUPPORTED_D, IsPlatformSupportedD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_PLAYING, IsPlaying);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_PLAYING_D, IsPlayingD);
		/*
			`PluginIsPlayingName` automatically handles initializing the `ChromaSDK`.
			The named `.chroma` animation file will be automatically opened. The method
			will return whether the animation is playing or not.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_PLAYING_NAME, IsPlayingName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_PLAYING_NAME_D, IsPlayingNameD);
		/*
			`PluginIsPlayingType` automatically handles initializing the `ChromaSDK`.
			If any animation is playing for the `deviceType` and `device` combination,
			the method will return true, otherwise false.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_PLAYING_TYPE, IsPlayingType);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_IS_PLAYING_TYPE_D, IsPlayingTypeD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_LERP, Lerp);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_LERP_COLOR, LerpColor);
		/*
			Loads `Chroma` effects so that the animation can be played immediately.
			Returns the animation id upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_LOAD_ANIMATION, LoadAnimation);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_LOAD_ANIMATION_D, LoadAnimationD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_LOAD_ANIMATION_NAME, LoadAnimationName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_LOAD_COMPOSITE, LoadComposite);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES, MakeBlankFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_NAME, MakeBlankFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_NAME_D, MakeBlankFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_RANDOM, MakeBlankFramesRandom);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_RANDOM_BLACK_AND_WHITE, MakeBlankFramesRandomBlackAndWhite);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_RANDOM_BLACK_AND_WHITE_NAME, MakeBlankFramesRandomBlackAndWhiteName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_RANDOM_BLACK_AND_WHITE_NAME_D, MakeBlankFramesRandomBlackAndWhiteNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_RANDOM_NAME, MakeBlankFramesRandomName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_RANDOM_NAME_D, MakeBlankFramesRandomNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_RGB, MakeBlankFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_RGB_NAME, MakeBlankFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MAKE_BLANK_FRAMES_RGB_NAME_D, MakeBlankFramesRGBNameD);
		/*
			Flips the color grid horizontally for all `Chroma` animation frames. Returns
			the animation id upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MIRROR_HORIZONTALLY, MirrorHorizontally);
		/*
			Flips the color grid vertically for all `Chroma` animation frames. This
			method has no effect for `EChromaSDKDevice1DEnum` devices. Returns the
			animation id upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MIRROR_VERTICALLY, MirrorVertically);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_COLOR_LERP_ALL_FRAMES, MultiplyColorLerpAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_COLOR_LERP_ALL_FRAMES_NAME, MultiplyColorLerpAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_COLOR_LERP_ALL_FRAMES_NAME_D, MultiplyColorLerpAllFramesNameD);
		/*
			Multiply all the colors in the frame by the intensity value. The valid the
			intensity range is from 0.0 to 255.0. RGB components are multiplied equally.
			An intensity of 0.5 would half the color value. Black colors in the frame
			will not be affected by this method.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY, MultiplyIntensity);
		/*
			Multiply all the colors for all frames by the intensity value. The valid
			the intensity range is from 0.0 to 255.0. RGB components are multiplied
			equally. An intensity of 0.5 would half the color value. Black colors in
			the frame will not be affected by this method.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES, MultiplyIntensityAllFrames);
		/*
			Multiply all the colors for all frames by the intensity value. The valid
			the intensity range is from 0.0 to 255.0. RGB components are multiplied
			equally. An intensity of 0.5 would half the color value. Black colors in
			the frame will not be affected by this method.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES_NAME, MultiplyIntensityAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES_NAME_D, MultiplyIntensityAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES_RGB, MultiplyIntensityAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES_RGB_NAME, MultiplyIntensityAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_ALL_FRAMES_RGB_NAME_D, MultiplyIntensityAllFramesRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_COLOR, MultiplyIntensityColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_COLOR_ALL_FRAMES, MultiplyIntensityColorAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_COLOR_ALL_FRAMES_NAME, MultiplyIntensityColorAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_COLOR_ALL_FRAMES_NAME_D, MultiplyIntensityColorAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_COLOR_NAME, MultiplyIntensityColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_COLOR_NAME_D, MultiplyIntensityColorNameD);
		/*
			Multiply all the colors in the frame by the intensity value. The valid the
			intensity range is from 0.0 to 255.0. RGB components are multiplied equally.
			An intensity of 0.5 would half the color value. Black colors in the frame
			will not be affected by this method.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_NAME, MultiplyIntensityName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_NAME_D, MultiplyIntensityNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_RGB, MultiplyIntensityRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_RGB_NAME, MultiplyIntensityRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_INTENSITY_RGB_NAME_D, MultiplyIntensityRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP, MultiplyNonZeroTargetColorLerp);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES, MultiplyNonZeroTargetColorLerpAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES_NAME, MultiplyNonZeroTargetColorLerpAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES_NAME_D, MultiplyNonZeroTargetColorLerpAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES_RGB, MultiplyNonZeroTargetColorLerpAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES_RGB_NAME, MultiplyNonZeroTargetColorLerpAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_NON_ZERO_TARGET_COLOR_LERP_ALL_FRAMES_RGB_NAME_D, MultiplyNonZeroTargetColorLerpAllFramesRGBNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_TARGET_COLOR_LERP, MultiplyTargetColorLerp);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES, MultiplyTargetColorLerpAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES_NAME, MultiplyTargetColorLerpAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES_NAME_D, MultiplyTargetColorLerpAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES_RGB, MultiplyTargetColorLerpAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES_RGB_NAME, MultiplyTargetColorLerpAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_MULTIPLY_TARGET_COLOR_LERP_ALL_FRAMES_RGB_NAME_D, MultiplyTargetColorLerpAllFramesRGBNameD);
		/*
			Offset all colors in the frame using the RGB offset. Use the range of -255
			to 255 for red, green, and blue parameters. Negative values remove color.
			Positive values add color.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_COLORS, OffsetColors);
		/*
			Offset all colors for all frames using the RGB offset. Use the range of
			-255 to 255 for red, green, and blue parameters. Negative values remove
			color. Positive values add color.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_COLORS_ALL_FRAMES, OffsetColorsAllFrames);
		/*
			Offset all colors for all frames using the RGB offset. Use the range of
			-255 to 255 for red, green, and blue parameters. Negative values remove
			color. Positive values add color.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_COLORS_ALL_FRAMES_NAME, OffsetColorsAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_COLORS_ALL_FRAMES_NAME_D, OffsetColorsAllFramesNameD);
		/*
			Offset all colors in the frame using the RGB offset. Use the range of -255
			to 255 for red, green, and blue parameters. Negative values remove color.
			Positive values add color.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_COLORS_NAME, OffsetColorsName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_COLORS_NAME_D, OffsetColorsNameD);
		/*
			This method will only update colors in the animation that are not already
			set to black. Offset a subset of colors in the frame using the RGB offset.
			Use the range of -255 to 255 for red, green, and blue parameters. Negative
			values remove color. Positive values add color.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_NON_ZERO_COLORS, OffsetNonZeroColors);
		/*
			This method will only update colors in the animation that are not already
			set to black. Offset a subset of colors for all frames using the RGB offset.
			Use the range of -255 to 255 for red, green, and blue parameters. Negative
			values remove color. Positive values add color.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_NON_ZERO_COLORS_ALL_FRAMES, OffsetNonZeroColorsAllFrames);
		/*
			This method will only update colors in the animation that are not already
			set to black. Offset a subset of colors for all frames using the RGB offset.
			Use the range of -255 to 255 for red, green, and blue parameters. Negative
			values remove color. Positive values add color.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_NON_ZERO_COLORS_ALL_FRAMES_NAME, OffsetNonZeroColorsAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_NON_ZERO_COLORS_ALL_FRAMES_NAME_D, OffsetNonZeroColorsAllFramesNameD);
		/*
			This method will only update colors in the animation that are not already
			set to black. Offset a subset of colors in the frame using the RGB offset.
			Use the range of -255 to 255 for red, green, and blue parameters. Negative
			values remove color. Positive values add color.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_NON_ZERO_COLORS_NAME, OffsetNonZeroColorsName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OFFSET_NON_ZERO_COLORS_NAME_D, OffsetNonZeroColorsNameD);
		/*
			Opens a `Chroma` animation file so that it can be played. Returns an animation
			id >= 0 upon success. Returns -1 if there was a failure. The animation
			id is used in most of the API methods.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OPEN_ANIMATION, OpenAnimation);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OPEN_ANIMATION_D, OpenAnimationD);
		/*
			Opens a `Chroma` animation file with the `.chroma` extension. Returns zero
			upon success. Returns -1 if there was a failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OPEN_EDITOR_DIALOG, OpenEditorDialog);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OPEN_EDITOR_DIALOG_AND_PLAY, OpenEditorDialogAndPlay);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OPEN_EDITOR_DIALOG_AND_PLAY_D, OpenEditorDialogAndPlayD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OPEN_EDITOR_DIALOG_D, OpenEditorDialogD);
		/*
			Sets the `duration` for all grames in the `Chroma` animation to the `duration`
			parameter. Returns the animation id upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OVERRIDE_FRAME_DURATION, OverrideFrameDuration);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OVERRIDE_FRAME_DURATION_D, OverrideFrameDurationD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_OVERRIDE_FRAME_DURATION_NAME, OverrideFrameDurationName);
		/*
			Pause the current animation referenced by id.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PAUSE_ANIMATION, PauseAnimation);
		/*
			Pause the current animation referenced by name.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PAUSE_ANIMATION_NAME, PauseAnimationName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PAUSE_ANIMATION_NAME_D, PauseAnimationNameD);
		/*
			Plays the `Chroma` animation. This will load the animation, if not loaded
			previously. Returns the animation id upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PLAY_ANIMATION, PlayAnimation);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PLAY_ANIMATION_D, PlayAnimationD);
		/*
			`PluginPlayAnimationFrame` automatically handles initializing the `ChromaSDK`.
			The method will play the animation given the `animationId` with looping
			`on` or `off` starting at the `frameId`.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PLAY_ANIMATION_FRAME, PlayAnimationFrame);
		/*
			`PluginPlayAnimationFrameName` automatically handles initializing the `ChromaSDK`.
			The named `.chroma` animation file will be automatically opened. The animation
			will play with looping `on` or `off` starting at the `frameId`.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PLAY_ANIMATION_FRAME_NAME, PlayAnimationFrameName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PLAY_ANIMATION_FRAME_NAME_D, PlayAnimationFrameNameD);
		/*
			`PluginPlayAnimationLoop` automatically handles initializing the `ChromaSDK`.
			The method will play the animation given the `animationId` with looping
			`on` or `off`.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PLAY_ANIMATION_LOOP, PlayAnimationLoop);
		/*
			`PluginPlayAnimationName` automatically handles initializing the `ChromaSDK`.
			The named `.chroma` animation file will be automatically opened. The animation
			will play with looping `on` or `off`.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PLAY_ANIMATION_NAME, PlayAnimationName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PLAY_ANIMATION_NAME_D, PlayAnimationNameD);
		/*
			`PluginPlayComposite` automatically handles initializing the `ChromaSDK`.
			The named animation files for the `.chroma` set will be automatically opened.
			The set of animations will play with looping `on` or `off`.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PLAY_COMPOSITE, PlayComposite);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PLAY_COMPOSITE_D, PlayCompositeD);
		/*
			Displays the `Chroma` animation frame on `Chroma` hardware given the `frameIndex`.
			Returns the animation id upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PREVIEW_FRAME, PreviewFrame);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PREVIEW_FRAME_D, PreviewFrameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_PREVIEW_FRAME_NAME, PreviewFrameName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_REDUCE_FRAMES, ReduceFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_REDUCE_FRAMES_NAME, ReduceFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_REDUCE_FRAMES_NAME_D, ReduceFramesNameD);
		/*
			Resets the `Chroma` animation to 1 blank frame. Returns the animation id
			upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_RESET_ANIMATION, ResetAnimation);
		/*
			Resume the animation with loop `ON` or `OFF` referenced by id.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_RESUME_ANIMATION, ResumeAnimation);
		/*
			Resume the animation with loop `ON` or `OFF` referenced by name.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_RESUME_ANIMATION_NAME, ResumeAnimationName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_RESUME_ANIMATION_NAME_D, ResumeAnimationNameD);
		/*
			Reverse the animation frame order of the `Chroma` animation. Returns the
			animation id upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_REVERSE, Reverse);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_REVERSE_ALL_FRAMES, ReverseAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_REVERSE_ALL_FRAMES_NAME, ReverseAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_REVERSE_ALL_FRAMES_NAME_D, ReverseAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SAVE_ANIMATION, SaveAnimation);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SAVE_ANIMATION_NAME, SaveAnimationName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_1D_COLOR, Set1DColor);
		/*
			Set the animation color for a frame given the `1D` `led`. The `led` should
			be greater than or equal to 0 and less than the `MaxLeds`.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_1D_COLOR_NAME, Set1DColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_1D_COLOR_NAME_D, Set1DColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_2D_COLOR, Set2DColor);
		/*
			Set the animation color for a frame given the `2D` `row` and `column`. The
			`row` should be greater than or equal to 0 and less than the `MaxRow`.
			The `column` should be greater than or equal to 0 and less than the `MaxColumn`.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_2D_COLOR_NAME, Set2DColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_2D_COLOR_NAME_D, Set2DColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_CHROMA_CUSTOM_COLOR_ALL_FRAMES, SetChromaCustomColorAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_CHROMA_CUSTOM_COLOR_ALL_FRAMES_NAME, SetChromaCustomColorAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_CHROMA_CUSTOM_COLOR_ALL_FRAMES_NAME_D, SetChromaCustomColorAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_CHROMA_CUSTOM_FLAG, SetChromaCustomFlag);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_CHROMA_CUSTOM_FLAG_NAME, SetChromaCustomFlagName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_CHROMA_CUSTOM_FLAG_NAME_D, SetChromaCustomFlagNameD);
		/*
			Set the current frame of the animation referenced by id.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_CURRENT_FRAME, SetCurrentFrame);
		/*
			Set the current frame of the animation referenced by name.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_CURRENT_FRAME_NAME, SetCurrentFrameName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_CURRENT_FRAME_NAME_D, SetCurrentFrameNameD);
		/*
			Changes the `deviceType` and `device` of a `Chroma` animation. If the device
			is changed, the `Chroma` animation will be reset with 1 blank frame. Returns
			the animation id upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_DEVICE, SetDevice);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_EFFECT, SetEffect);
		/*
			Set animation key to a static color for the given frame.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR, SetKeyColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_ALL_FRAMES, SetKeyColorAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_ALL_FRAMES_NAME, SetKeyColorAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_ALL_FRAMES_NAME_D, SetKeyColorAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_ALL_FRAMES_RGB, SetKeyColorAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_ALL_FRAMES_RGB_NAME, SetKeyColorAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_ALL_FRAMES_RGB_NAME_D, SetKeyColorAllFramesRGBNameD);
		/*
			Set animation key to a static color for the given frame.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_NAME, SetKeyColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_NAME_D, SetKeyColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_RGB, SetKeyColorRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_RGB_NAME, SetKeyColorRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_COLOR_RGB_NAME_D, SetKeyColorRGBNameD);
		/*
			Set animation key to a static color for the given frame if the existing
			color is not already black.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_NON_ZERO_COLOR, SetKeyNonZeroColor);
		/*
			Set animation key to a static color for the given frame if the existing
			color is not already black.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_NON_ZERO_COLOR_NAME, SetKeyNonZeroColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_NON_ZERO_COLOR_NAME_D, SetKeyNonZeroColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_NON_ZERO_COLOR_RGB, SetKeyNonZeroColorRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_NON_ZERO_COLOR_RGB_NAME, SetKeyNonZeroColorRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_NON_ZERO_COLOR_RGB_NAME_D, SetKeyNonZeroColorRGBNameD);
		/*
			Set an array of animation keys to a static color for the given frame.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_COLOR, SetKeysColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_COLOR_ALL_FRAMES, SetKeysColorAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_COLOR_ALL_FRAMES_NAME, SetKeysColorAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_COLOR_ALL_FRAMES_RGB, SetKeysColorAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_COLOR_ALL_FRAMES_RGB_NAME, SetKeysColorAllFramesRGBName);
		/*
			Set an array of animation keys to a static color for the given frame.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_COLOR_NAME, SetKeysColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_COLOR_RGB, SetKeysColorRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_COLOR_RGB_NAME, SetKeysColorRGBName);
		/*
			Set an array of animation keys to a static color for the given frame if
			the existing color is not already black.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_NON_ZERO_COLOR, SetKeysNonZeroColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_NON_ZERO_COLOR_ALL_FRAMES, SetKeysNonZeroColorAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_NON_ZERO_COLOR_ALL_FRAMES_NAME, SetKeysNonZeroColorAllFramesName);
		/*
			Set an array of animation keys to a static color for the given frame if
			the existing color is not already black.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_NON_ZERO_COLOR_NAME, SetKeysNonZeroColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_NON_ZERO_COLOR_RGB, SetKeysNonZeroColorRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_NON_ZERO_COLOR_RGB_NAME, SetKeysNonZeroColorRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_ZERO_COLOR, SetKeysZeroColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_ZERO_COLOR_ALL_FRAMES, SetKeysZeroColorAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_ZERO_COLOR_ALL_FRAMES_NAME, SetKeysZeroColorAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_ZERO_COLOR_ALL_FRAMES_RGB, SetKeysZeroColorAllFramesRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_ZERO_COLOR_ALL_FRAMES_RGB_NAME, SetKeysZeroColorAllFramesRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_ZERO_COLOR_NAME, SetKeysZeroColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_ZERO_COLOR_RGB, SetKeysZeroColorRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEYS_ZERO_COLOR_RGB_NAME, SetKeysZeroColorRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_ZERO_COLOR, SetKeyZeroColor);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_ZERO_COLOR_NAME, SetKeyZeroColorName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_ZERO_COLOR_NAME_D, SetKeyZeroColorNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_ZERO_COLOR_RGB, SetKeyZeroColorRGB);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_ZERO_COLOR_RGB_NAME, SetKeyZeroColorRGBName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_KEY_ZERO_COLOR_RGB_NAME_D, SetKeyZeroColorRGBNameD);
		/*
			Invokes the setup for a debug logging callback so that `stdout` is redirected
			to the callback. This is used by `Unity` so that debug messages can appear
			in the console window.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SET_LOG_DELEGATE, SetLogDelegate);
		/*
			`PluginStopAll` will automatically stop all animations that are playing.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_STOP_ALL, StopAll);
		/*
			Stops animation playback if in progress. Returns the animation id upon success.
			Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_STOP_ANIMATION, StopAnimation);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_STOP_ANIMATION_D, StopAnimationD);
		/*
			`PluginStopAnimationName` automatically handles initializing the `ChromaSDK`.
			The named `.chroma` animation file will be automatically opened. The animation
			will stop if playing.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_STOP_ANIMATION_NAME, StopAnimationName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_STOP_ANIMATION_NAME_D, StopAnimationNameD);
		/*
			`PluginStopAnimationType` automatically handles initializing the `ChromaSDK`.
			If any animation is playing for the `deviceType` and `device` combination,
			it will be stopped.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_STOP_ANIMATION_TYPE, StopAnimationType);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_STOP_ANIMATION_TYPE_D, StopAnimationTypeD);
		/*
			`PluginStopComposite` automatically handles initializing the `ChromaSDK`.
			The named animation files for the `.chroma` set will be automatically opened.
			The set of animations will be stopped if playing.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_STOP_COMPOSITE, StopComposite);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_STOP_COMPOSITE_D, StopCompositeD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES, SubtractNonZeroAllKeysAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME, SubtractNonZeroAllKeysAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES_NAME_D, SubtractNonZeroAllKeysAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET, SubtractNonZeroAllKeysAllFramesOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME, SubtractNonZeroAllKeysAllFramesOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D, SubtractNonZeroAllKeysAllFramesOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_OFFSET, SubtractNonZeroAllKeysOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_OFFSET_NAME, SubtractNonZeroAllKeysOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_ALL_KEYS_OFFSET_NAME_D, SubtractNonZeroAllKeysOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES, SubtractNonZeroTargetAllKeysAllFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME, SubtractNonZeroTargetAllKeysAllFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_NAME_D, SubtractNonZeroTargetAllKeysAllFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET, SubtractNonZeroTargetAllKeysAllFramesOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME, SubtractNonZeroTargetAllKeysAllFramesOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_ALL_FRAMES_OFFSET_NAME_D, SubtractNonZeroTargetAllKeysAllFramesOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_OFFSET, SubtractNonZeroTargetAllKeysOffset);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME, SubtractNonZeroTargetAllKeysOffsetName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_SUBTRACT_NON_ZERO_TARGET_ALL_KEYS_OFFSET_NAME_D, SubtractNonZeroTargetAllKeysOffsetNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_TRIM_END_FRAMES, TrimEndFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_TRIM_END_FRAMES_NAME, TrimEndFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_TRIM_END_FRAMES_NAME_D, TrimEndFramesNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_TRIM_FRAME, TrimFrame);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_TRIM_FRAME_NAME, TrimFrameName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_TRIM_FRAME_NAME_D, TrimFrameNameD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_TRIM_START_FRAMES, TrimStartFrames);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_TRIM_START_FRAMES_NAME, TrimStartFramesName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_TRIM_START_FRAMES_NAME_D, TrimStartFramesNameD);
		/*
			Uninitializes the `ChromaSDK`. Returns 0 upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_UNINIT, Uninit);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_UNINIT_D, UninitD);
		/*
			Unloads `Chroma` effects to free up resources. Returns the animation id
			upon success. Returns -1 upon failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_UNLOAD_ANIMATION, UnloadAnimation);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_UNLOAD_ANIMATION_D, UnloadAnimationD);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_UNLOAD_ANIMATION_NAME, UnloadAnimationName);
		/*
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_UNLOAD_COMPOSITE, UnloadComposite);
		/*
			Updates the `frameIndex` of the `Chroma` animation and sets the `duration`
			(in seconds). The `color` is expected to be an array of the dimensions
			for the `deviceType/device`. The `length` parameter is the size of the
			`color` array. For `EChromaSDKDevice1DEnum` the array size should be `MAX
			LEDS`. For `EChromaSDKDevice2DEnum` the array size should be `MAX ROW`
			* `MAX COLUMN`. Returns the animation id upon success. Returns -1 upon
			failure.
		*/
		CHROMASDK_DECLARE_METHOD(PLUGIN_UPDATE_FRAME, UpdateFrame);
#pragma endregion

		static int InitAPI();
	};
}
