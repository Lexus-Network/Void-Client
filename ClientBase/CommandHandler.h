#pragma once

#include <algorithm>
#include <vector>
#include "Command.h"
#include "Commands/HelpCommand.h"
#include "Commands/TestCommand.h"
#include "Example.h" // type like this when adding a . command

class CommandHandler {
public:
    std::vector<Command*> commands;

public:

    void InitCommands() {
        commands.push_back(new TestCommand("test"));
        commands.push_back(new HelpCommand("help"));
        commands.push_back(new ExampleCommand("example")); // type like this when adding a . command
    }

    Command* findCommand(std::string name){
        std::vector<Command*> allCmds = commands;
        for (auto cmd : allCmds) {
            if (cmd->CheckName(name)) {
                return cmd;
            }
        }
	return nullptr;
    }
};
