#pragma once
#include <string>
#include <vector>
#include "../SDK/Actor.h"
#include "../SDK/ClientInstance.h"

class Command {
public:
	Command(std::string name, std::string description/*, std::vector<std::string> aliases*/) { // Constructor
		this->name = name;
		this->description = description;
		//this->aliases = aliases;
	};

public:
	std::string name;
	std::string description;
	std::vector<std::string> aliases;

public: // functions
	virtual void Execute(std::vector<std::string> args) {};
	virtual bool CheckName(std::string MName) {
		if (MName == this->name) {
			return true;
		}
		return false;
    }
	virtual bool isNumber(const std::string& str) {
		for (char const& c : str) {
			if (std::isdigit(c) == 0) return false;
		}
		return true;
	}
};
