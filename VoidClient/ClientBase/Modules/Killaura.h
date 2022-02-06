#pragma once

class Killaura : public Module {
public:
	Killaura(std::string cat) : Module(cat, "Killaura", "Hit every entity around you", 0x07) {};

	void OnGameTick(Actor* lp) override {
		auto localPlayer = clientInst->getCPlayer();
		auto gamemode = localPlayer->getGamemode();
        for (auto ent : clientInst->getEntityList()) {
			if (ent.first == reinterpret_cast<uintptr_t>(localPlayer))
				return;

			if (ent.second == nullptr)
				continue;

			localPlayer->swing();
			gamemode->attack(ent.second);
        }
	}
};