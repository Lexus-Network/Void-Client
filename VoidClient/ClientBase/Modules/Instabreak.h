#pragma once
class Block {};
class Instabreak : public Module {
public:
    VirtualFuncHook* func;
    Instabreak(std::string cat) : Module(cat, "Instabreak", "Lets you break blocks instantly", 0x07) {
        uintptr_t address = Mem::findSig("48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 40 48 8B FA 0F 29 74 24 ?");
        func = hooks->createHook("getDestroySpeed", address, getDestroySpeed);

    }

    void OnEnable(ClientInstance* a1, Actor* a2) override {
        func->enableHook();
    }

    void OnDisable(ClientInstance* a1, Actor* a2) override {
        func->disableHook();
    }

    static float getDestroySpeed(class Player, Block) {
        return 1000.f;
    }
};