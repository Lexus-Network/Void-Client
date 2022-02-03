class VirtualFuncHook {
public:
	std::string hookName;
	void* function;
	void* ptr;

	VirtualFuncHook(std::string hookName, uintptr_t ptr, void* function) {
		this->hookName = hookName;
		this->ptr = reinterpret_cast<void*>(ptr);
		this->function = function;
		MH_CreateHook(this->ptr, function, &this->function);
	};

	void enableHook(bool enable = true) {
		if (this->ptr != nullptr) {
			enable ? MH_EnableHook(this->ptr) : MH_DisableHook(this->ptr);
		}
	}
	void disableHook() {
		enableHook(false);
	}

	template <typename TRet, typename... TArgs>
	inline auto* GetFastcall() {
		using Fn = TRet(__fastcall*)(TArgs...);
		return reinterpret_cast<Fn>(ptr);
	};
};