#pragma once

class Setting {
public:
	

	Setting(Module* Parent, std::string Name, std::string Mode, std::vector<std::string> Option) { // Constructor
		parent = Parent;
		name = Name;
		mode = Mode;
		option = Option;
	}

	Module* parent;
	std::string name;
	std::vector<std::string> option;
	std::string mode;

	bool isCheckbox()
	{
		return this->mode._Equal("checkbox") ? true : false;
	}

	bool isSlider()
	{
		return this->mode._Equal("slider") ? true : false;
	}
};
