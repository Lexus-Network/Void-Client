#pragma once
class VisualElement {
public:
	float x, y, len, fade = 0;
	bool initialised, open = false;
	VisualElement() {
		this->initialised = false;
		this->open = false;
		this->x = 0.0f;
		this->y = 0.0f;
		this->fade = 0.0f;
	}

	void increment(float value, float limit, bool positive)
	{
		if (positive)
			fade += value;
		else
			fade -= value;
		overflowCheck(limit);
	}

	void overflowCheck(float limit)
	{
		if (fade <= 0)
			fade = 0;
		if (fade >= limit)
			fade = limit;
	}
};