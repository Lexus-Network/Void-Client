#pragma once
#include "../TextHolder.h"
class Packet {
private:
	virtual void packetConstructor(void) {};
public:
	virtual int getId(void) { return 0x0; };
	virtual class TextHolder getTypeName(void) { return (class TextHolder)nullptr; };
	virtual void write(class BinaryStream&) {};
	virtual void read(class ReadOnlyBinaryStream&) {};
	virtual void readExtended(class ReadOnlyBinaryStream&) {};
	virtual void disallowBatching(void) {};

	// Returns packet name e.g "MovePlayerPacket"
	std::string getName()
	{
		return this->getTypeName().getText();
	}

	// Set vTable
	void setVTable(uint64_t vtable)
	{
		*(uint64_t*)(reinterpret_cast<uintptr_t>(this) + 0x0) = vtable;
	}

	// Returns vTable
	uint64_t getVTable()
	{
		return *(uint64_t*)(reinterpret_cast<uintptr_t>(this) + 0x0);
	}
};

//Still working on currently
class PlayerAuthInputPacket {
public:
    uint64_t VTable;
    uint64_t num4294967298;
    char padThingy[32];
    Vector2 bodyRot;
    Vector3 position;
    float headYaw;
    Vector3 velocity;
    float InputAD; // 1 for A, -1 for D, multiply by sqrt(2)/2 if mixed with InputWS 
    float InputWS; // 1 for W, -1 for S, multiply by sqrt(2)/2 if mixed with InputAD 
    uint8_t epicpad[12];
    uint32_t inputKeys;
    int zero;
    int one;
    int two;
    int counter;

    PlayerAuthInputPacket(Actor* Player, Vector3 position, Vector2 bodyRot) {
        //this->VTable = Minecraft.Windows.exe + 3EB98A8;
        for (int i = 0; i < 32; i++) {
            this->padThingy[i] = 0;
        }
        this->num4294967298 = 4294967298;
        this->position = position;
        this->bodyRot = bodyRot;
        this->headYaw = bodyRot.y;
        //this->velocity = Player->Velocity;
        this->InputAD = 0.f;
        this->InputWS = 0.f;
        for (int i = 0; i < 12; i++) {
            this->epicpad[i] = 0;
        }
        this->inputKeys = 0;
        this->zero = 0;
        this->one = 1;
        this->two = 2;
        this->counter = 0;
    }
};