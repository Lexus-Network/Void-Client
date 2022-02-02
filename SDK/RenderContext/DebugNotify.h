class DebugNotify {
public:
	std::string notificationName;
	std::string notificationDesc;
	float canExistFor = 2;

	float fadeAlpha = 0;
	float existedTick = 0;
	float yOffset = 25;

	DebugNotify(std::string notificationName, std::string notificationDesc, float canExistFor = 6) {
		this->notificationName = notificationName;
		this->notificationDesc = notificationDesc;
		this->canExistFor = canExistFor;
	};
};