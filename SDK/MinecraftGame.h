#pragma once

#include "../Utils/Math.h"

struct FontRepos { // FontRepos
private:
	char pad_0x000[0x28];  //0x0000
public:

	struct FontList { // FontRepos > FontList
	public:
		//class BitmapFont* fontEntries[7];

		struct FontEntry { // FontRepos > FontList > FontEntriesOption(FontEntry)
		public:
			class BitmapFont* font; //0x0000
		}
		fontEntries[7]; //0x0000

	}* fontList;   //0x0028

};

class MinecraftGame
{
private:
	char pad_0x0000[0xF8]; //0x0000
public:
	FontRepos* fontRepos; //0x00F8
private:
	char pad_0x0100[0x8]; //0x0100
public:
	class BitmapFont* defaultGameFont; //0x0108
private:
	char pad_0x0110[0x38]; //0x0110
public:
	class BitmapFont* font2; //0x0148 
private:
	char pad_0x0150[0x38]; //0x0150
public:
	class BitmapFont* invisGameFont; //0x0188 
private:
	char pad_0x042069; //lol idk how this works lmfao
public:
	class BitmapFont* defaultgameFont2; //idk, but it works lmfao

	auto canUseKeys() {
        return *reinterpret_cast<bool*>((uintptr_t)(this) + 0x300);
    };
}; // 0x110
