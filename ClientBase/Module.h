#pragma once
#include "../Utils/RenderUtils.h"
#include "Setting.h"

class Module {
public:
    Module(std::string category = "Empty", std::string name = "Empty", std::string tooltip = "Empty", uintptr_t keybind = 0x07, bool enabled = false) { // Constructor
        this->category = category;
        this->name = name;
		this->tooltip = tooltip;
        this->keybind = keybind;
		this->enabled = enabled;
    };

public:
    std::string category;
    std::string name;
	std::string tooltip;
	VisualElement* vElement = new VisualElement();
    uintptr_t keybind;
    bool enabled;

	// Private variables
	std::vector<Setting*> settings;

public: // functions
	virtual void drawTooltip(TextHolder tooltip) {
		renderUtil.DrawString(Vector2(15, renderUtil.guiData->scaledResolution.y - 20.f), _RGB(255, 255, 255), tooltip, renderUtil.font, 0.8f);
	}
	
    virtual void OnEnable(ClientInstance* ci, Actor* lp) {}
    virtual void OnDisable(ClientInstance* ci, Actor* lp) {}

    virtual void OnFrameRender(RenderUtils* ctx) {}
    virtual void OnTick(ClientInstance* ci) {}
    virtual void OnGameTick(Actor* lp) {}
	virtual void OnContainerTick(ContainerManagement* a1, Actor* lp) {}
	virtual bool HoldMode() {
		return false;
	}

	void addSetting(Setting setting) {
		settings.push_back(&setting);
	}

	double _pow(double a, double b) {
		double c = 1;
		for (int i = 0; i < b; i++)
			c *= a;
		return c;
	}

	double _fact(double x) {
		double ret = 1;
		for (int i = 1; i <= x; i++)
			ret *= i;
		return ret;
	}
    
    float sin(float x) {
		float res = 0, pow = x, fact = 1;
		for (int i = 0; i < 5; i++) {
			res += pow / fact;
			pow *= -1 * x * x;
			fact *= (2 * (i + 1)) * (2 * (i + 1) + 1);
		}
		return res;
	}

	double cos(double x) {
		double y = 1;
		double s = -1;
		for (int i = 2; i <= 100; i += 2) {
			y += s * (_pow(x, i) / _fact(i));
			s *= -1;
		}
		return y;
	}
    //virtual void OnKeyDown(uintptr_t keyAddr, bool* cancel) {}
    //virtual void OnKeyUp(uintptr_t keyAddr, bool* cancel) {}
    //virtual void OnKeyHeld(uintptr_t keyAddr, bool* cancel) {}

    //virtual auto OnMouseDown(uintptr_t mouseKeyAddr, bool* cancel) -> void {}
    //virtual auto OnMouseUp(uintptr_t mouseKeyAddr, bool* cancel) -> void {}
    //virtual auto OnMouseHeld(uintptr_t mouseKeyAddr, bool* cancel) -> void {}
};
