#pragma once

#include "../Utils/Math.h"
#include "MinecraftGame.h"
#include "Player.h"
#include <memory>

class TimerClass {
private:
	char pad_0x0000[0xD0 + (0x8 * 1)]; //0x0000
public:
	float* mainTimer;
	float* otherTimer;

	void setTimerSpeed(float tps) {
		*this->mainTimer = tps;
		*this->otherTimer = tps;
		return;
	};
};

class LoopbackSender {
private:
	virtual void Constructor();
public:
	virtual void sendToServer(Packet* pkt);
};

class ClientInstance {
private:
	char pad_0x0000[0xA0]; //0x0000
public:
	MinecraftGame* mcGame; //0x00A8
	TimerClass* timerClass; //0x00B0

public:
	auto getGuiData() {
		return *reinterpret_cast<GuiData**>((uintptr_t)(this) + 0x4D0);
	};

	auto getLocalPlayer() {
		return *reinterpret_cast<Actor**>((uintptr_t)(this) + 0x148);
	};

	auto getLevelRender() {
		return reinterpret_cast<LevelRender*>((uintptr_t)(this) + 0xD0); // 0xC0 + 0x10
	};

	auto getFovX() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x658);
	};

	auto getFovY() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x66C);
	};

	auto getMatrix() {
		return reinterpret_cast<GLMatrix*>((uintptr_t)(this) + 0x2D8); //0x300
	};

	auto getMatrixCorrection() {
		GLMatrix toReturn = GLMatrix();

		GLMatrix* matrix = getMatrix();

		for (int i = 0; i < 4; i++) {
			toReturn.matrix[i * 4 + 0] = matrix->matrix[0 + i];
			toReturn.matrix[i * 4 + 1] = matrix->matrix[4 + i];
			toReturn.matrix[i * 4 + 2] = matrix->matrix[8 + i];
			toReturn.matrix[i * 4 + 3] = matrix->matrix[12 + i];
		}

		return &toReturn;
	};

	auto getTimerClass() {
		return reinterpret_cast<class TimerClass*>((uintptr_t)(this) + 0xC0); 
	};

	auto getLoopbackSender() {
		return reinterpret_cast<class LoopbackSender*>((uintptr_t)(this) + 0xE0);
	};

	auto getMcGame() {
		return reinterpret_cast<MinecraftGame*>((uintptr_t)(this) + 0xA8);
	};

	auto getFov() {
		return Vector2(*getFovX(), *getFovY());
	};

	auto getEntityList() {
		std::map<uintptr_t, Actor*> cleanMap = std::map<uintptr_t, Actor*>();

		int i = 0;
		for (auto ent : entityList) {
			if (ent.second == nullptr) continue; // skip nullptr entities
			cleanMap[i] = ent.second;
			i++;
		}

		return cleanMap;
	};

	Actor* getCPlayer() {
		if (getLocalPlayer() == nullptr)
			return nullptr;
		return getLocalPlayer();
	};

	__forceinline float transformx(const Vector3& p) { // I think minecraft corrected the GLMatrix wtf
		auto matrix = getMatrixCorrection()->matrix;
		return p.x * matrix[0] + p.y * matrix[4] + p.z * matrix[8] + matrix[12];
	}

	__forceinline float transformy(const Vector3& p) {
		auto matrix = getMatrixCorrection()->matrix;
		return p.x * matrix[1] + p.y * matrix[5] + p.z * matrix[9] + matrix[13];
	}

	__forceinline float transformz(const Vector3& p) { // std::shared_ptr<GLMatrix>(getMatrixCorrection());
		auto matrix = getMatrixCorrection()->matrix;
		return p.x * matrix[2] + p.y * matrix[6] + p.z * matrix[10] + matrix[14];
	}

	inline bool WorldToScreen(Vector3 origin, Vector3 pos, Vector2& screen, Vector2 fov, Vector2 displaySize) {
		pos.x -= origin.x;
		pos.y -= origin.y;
		pos.z -= origin.z;

		float x = transformx(pos);
		float y = transformy(pos);
		float z = transformz(pos);

		if (z > 0) return false;

		float mX = (float)displaySize.x / 2.0F;
		float mY = (float)displaySize.y / 2.0F;

		screen.x = mX + (mX * x / -z * fov.x);
		screen.y = mY - (mY * y / -z * fov.y);

		return true;
	}

	auto isInGame() {
		return getGuiData()->windowData->inWorld;
	};

private:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
public:
	virtual void requestLeaveGame(bool, bool); //9 (10)
	virtual void stopPlayScreen(); //10 (11)
private:
	virtual void Function11(); //
public:
	virtual void setupPlayScreenForLeaveGame(); //12 (13)
private:
	virtual void Function13(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual void Function55(); //
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual void Function61(); //
	virtual void Function62(); //
	virtual void Function63(); //
	virtual void Function64(); //
	virtual void Function65(); //
	virtual void Function66(); //
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74(); //
	virtual void Function75(); //
	virtual void Function76(); //
	virtual void Function77(); //
	virtual void Function78(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void Function81(); //
	virtual void Function82(); //
	virtual void Function83(); //
	virtual void Function84(); //
	virtual void Function85(); //
	virtual void Function86(); //
	virtual void Function87(); //
	virtual void Function88(); //
	virtual void Function89(); //
	virtual void Function90(); //
	virtual void Function91(); //
	virtual void Function92(); //
	virtual void Function93(); //
	virtual void Function94(); //
	virtual void Function95(); //
	virtual void Function96(); //
	virtual void Function97(); //
	virtual void Function98(); //
	virtual void Function99(); //
	virtual void Function100(); //
	virtual void Function101(); //
	virtual void Function102(); //
	virtual void Function103(); //
	virtual void Function104(); //
	virtual void Function105(); //
	virtual void Function106(); //
	virtual void Function107(); //
	virtual void Function108(); //
	virtual void Function109(); //
	virtual void Function110(); //
	virtual void Function111(); //
	virtual void Function112(); //
	virtual void Function113(); //
	virtual void Function114(); //
	virtual void Function115(); //
	virtual void Function116(); //
	virtual void Function117(); //
	virtual void Function118(); //
	virtual void Function119(); //
	virtual void Function120(); //
	virtual void Function121(); //
	virtual void Function122(); //
	virtual void Function123(); //
	virtual void Function124(); //
	virtual void Function125(); //
	virtual void Function126(); //
	virtual void Function127(); //
	virtual void Function128(); //
	virtual void Function129(); //
	virtual void Function130(); //
	virtual void Function131(); //
	virtual void Function132(); //
	virtual void Function133(); //
	virtual void Function134(); //
	virtual void Function135(); //
	virtual void Function136(); //
	virtual void Function137(); //
	virtual void Function138(); //
	virtual void Function139(); //
	virtual void Function140(); //
	virtual void Function141(); //
	virtual void Function142(); //
	virtual void Function143(); //
	virtual void Function144(); //
	virtual void Function145(); //
	virtual void Function146(); //
	virtual void Function147(); //
	virtual void Function148(); //
	virtual void Function149(); //
	virtual void Function150(); //
	virtual void Function151(); //
	virtual void Function152(); //
	virtual void Function153(); //
	virtual void Function154(); //
	virtual void Function155(); //
	virtual void Function156(); //
	virtual void Function157(); //
	virtual void Function158(); //
	virtual void Function159(); //
	virtual void Function160(); //
	virtual void Function161(); //
	virtual void Function162(); //
	virtual void Function163(); //
	virtual void Function164(); //
	virtual void Function165(); //
	virtual void Function166(); //
	virtual void Function167(); //
	virtual void Function168(); //
	virtual void Function169(); //
	virtual void Function170(); //
	virtual void Function171(); //
	virtual void Function172(); //
	virtual void Function173(); //
	virtual void Function174(); //
	virtual void Function175(); //
	virtual void Function176(); //
	virtual void Function177(); //
	virtual void Function178(); //
	virtual void Function179(); //
	virtual void Function180(); //
	virtual void Function181(); //
	virtual void Function182(); //
	virtual void Function183(); //
	virtual void Function184(); //
	virtual void Function185(); //
	virtual void Function186(); //
	virtual void Function187(); //
	virtual void Function188(); //
	virtual void Function189(); //
	virtual void Function190(); //
	virtual void Function191(); //
	virtual void Function192(); //
	virtual void Function193(); //
	virtual void Function194(); //
	virtual void Function195(); //
	virtual void Function196(); //
	virtual void Function197(); //
	virtual void Function198(); //
	virtual void Function199(); //
	virtual void Function200(); //
	virtual void Function201(); //
	virtual void Function202(); //
	virtual void Function203(); //
	virtual void Function204(); //
	virtual void Function205(); //
	virtual void Function206(); //
	virtual void Function207(); //
	virtual void Function208(); //
	virtual void Function209(); //
	virtual void Function210(); //
	virtual void Function211(); //
	virtual void Function212(); //
	virtual void Function213(); //
	virtual void Function214(); //
	virtual void Function215(); //
	virtual void Function216(); //
	virtual void Function217(); //
	virtual void Function218(); //
	virtual void Function219(); //
	virtual void Function220(); //
	virtual void Function221(); //
	virtual void Function222(); //
	virtual void Function223(); //
	virtual void Function224(); //
	virtual void Function225(); //
	virtual void Function226(); //
	virtual void Function227(); //
	virtual void Function228(); //
	virtual void Function229(); //
	virtual void Function230(); //
	virtual void Function231(); //
	virtual void Function232(); //
	virtual void Function233(); //
	virtual void Function234(); //
	virtual void Function235(); //
	virtual void Function236(); //
	virtual void Function237(); //
	virtual void Function238(); //
	virtual void Function239(); //
	virtual void Function240(); //
	virtual void Function241(); //
	virtual void Function242(); //
	virtual void Function243(); //
	virtual void Function244(); //
	virtual void Function245(); //
	virtual void Function246(); //
	virtual void Function247(); //
	virtual void Function248(); //
	virtual void Function249(); //
	virtual void Function250(); //
	virtual void Function251(); //
	virtual void Function252(); //
	virtual void Function253(); //
	virtual void Function254(); //
	virtual void Function255(); //
	virtual void Function256(); //
	virtual void Function257(); //
	virtual void Function258(); //
	virtual void Function259(); //
	virtual void Function260(); //
	virtual void Function261(); //
	virtual void Function262(); //
	virtual void Function263(); //
	virtual void Function264(); //
	virtual void Function265(); //
	virtual void Function266(); //
	virtual void Function267(); //
	virtual void Function268(); //
	virtual void Function269(); //
	virtual void Function270(); //
public:
	virtual void releaseMouse(); //271 (272)
	virtual void grabMouse(); //272 (273)
	virtual void refocusMouse(); //273 (274)
};
