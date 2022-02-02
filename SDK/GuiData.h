#pragma once

#include "../Utils/Math.h"

class WindowData
{
private:
	char pad_0x0000[0x1F0]; //0x0000
public:
	Vector2 renderWindow; //0x01F0
private:
	char pad_0x01F8[0x260]; //0x01F8
public:
	Vector2 mousePos; //0x0458
private:
	char pad_0x0460[0x54C]; //0x0460
public:
	__int8 inWorld; //0x09AC
}; 

class GuiData {
private:
	char pad_0x0000[0x18]; //0x0000
public:
	Vector2 resolution; //0x0018
	Vector2 resolution2; //0x0020
	Vector2 scaledResolution; //0x0028
private:
	char pad_0x0030[0x8]; //0x0030
public:
	float guiScale; //0x0034
private:
	char pad_0x004A[0x16]; //0x004A
public:
    short MouseX; //0x0052
	short MouseY; //0x0054
	__int8 IsInGame; //0x0056
private:
	char pad_0x0057[0x19]; //0x0057
public:
	WindowData* windowData; //0x0070
private:
	char pad_0x0078[0xA0]; //0x0078
public:
	__int32 gameTicks; //0x0118

public:
	Vector2 scaledMousePos() {
		return Vector2((this->MouseX) * this->guiScale, (this->MouseY) * this->guiScale);
	};
};