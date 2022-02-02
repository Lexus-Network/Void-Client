#pragma once

class LevelRender {
public:
	Vector3 getOrigin() {
		return *reinterpret_cast<Vector3*>((uintptr_t)this + 0x878);
	}
};