#pragma once

#include <algorithm>

#define PI 3.14159265359 // 3.14159265359

#include "Modules/TestModule.h"
#include "Modules/Watermark.h"


class ModuleHandler {
public:
    std::vector<Module*> modules;

public:

    struct CompareArg { bool operator()(Module* mod1, Module* mod2) { return mod1->name < mod2->name; } };

    void InitModules() {
        _logf(L"[VoidClient]: Registering modules...\n");

        // How to know what module goes where !
        std::string combat = "Combat"; // pvp stuff
        std::string world = "World"; // world stuff
        std::string movement = "Movement"; // movements
        std::string visual = "Visual"; // visual effects
        std::string player = "Player"; // player interacts 
        std::string misc = "Misc"; // other

        modules.push_back(new Example(combat)); // combat

        modules.push_back(new Example(world)); // world local

        modules.push_back(new Example(player)); // vis2

        modules.push_back(new Example(movement)); // movement

        modules.push_back(new Watermark(visual)); // visuals

        modules.push_back(new TestModule(misc)); // utils
        // Sort modules
        std::sort(modules.begin(), modules.end(), CompareArg());

        _logf(L"[VoidClient]: Registered modules!\n");
    }

    void FrameRender(RenderUtils* ctx) {
        for (auto mod : modules)
            if (mod->enabled) {
                mod->OnFrameRender(ctx);
            }
    }
};
