#pragma once

#include <algorithm>

#define PI 3.14159265359 // 3.14159265359

#include "Modules/Example.h" // when adding a modules make sure to do this first!
#include "Modules/AirJump.h"
#include "Modules/Watermark.h"


class ModuleHandler {
public:
    std::vector<Module*> modules;

public:

    struct CompareArg { bool operator()(Module* mod1, Module* mod2) { return mod1->name < mod2->name; } };

    void InitModules() {
        _logf(L"[FallenClient]: Registering modules...\n");

        // How to know what module goes where !
        std::string combat = "Combat"; // pvp stuff
        std::string world = "World"; // world stuff
        std::string movement = "Movement"; // movements
        std::string visual = "Visual"; // visual effects
        std::string player = "Player"; // player interacts 
        std::string misc = "Misc"; // other

        modules.push_back(new Example(combat)); // to add the holder to the gui u would have to type it out like this, if its in whatever u type at end (section));

        modules.push_back(new Example(world)); // to add the holder to the gui u would have to type it out like this, if its in whatever u type at end (section));

        modules.push_back(new Example(player)); // to add the holder to the gui u would have to type it out like this, if its in whatever u type at end (section));

        modules.push_back(new Example(movement)); // to add the holder to the gui u would have to type it out like this, if its in whatever u type at end (section));

        modules.push_back(new Watermark(visual));

        modules.push_back(new TestModule(misc));
        // Sort modules
        std::sort(modules.begin(), modules.end(), CompareArg());

        _logf(L"[ClientName]: Registered modules!\n");
    }

    void FrameRender(RenderUtils* ctx) {
        for (auto mod : modules)
            if (mod->enabled) {
                mod->OnFrameRender(ctx);
            }
    }
};