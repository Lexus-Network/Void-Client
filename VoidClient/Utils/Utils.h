#pragma once

#include <Windows.h>
#include <Psapi.h>

#define INRANGE(x,a,b)   (x >= a && x <= b)
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

class Mem {
public:
    static std::vector<char*> getAddrPtrPad(uintptr_t addr, int size) {
        std::vector<char*> padding;
        for (int i = 0; i < size; ++i) {
            auto byteData = reinterpret_cast<char*>(addr + size);
            padding.push_back(byteData);
        }
        return padding;
    };
    static std::vector<char> getAddrPad(uintptr_t addr, int size) {
        std::vector<char> padding;
        for (int i = 0; i < size; ++i) {
            auto byteData = *reinterpret_cast<char*>(addr + size);
            padding.push_back(byteData);
        }
        return padding;
    };
    static std::vector<char> setAddrPad(uintptr_t addr, std::vector<char> replacementCode) {
        std::vector<char> padding;
        for (int i = 0; i < replacementCode.size(); ++i) {
            auto byteData = reinterpret_cast<char*>(addr + (i - 1));
            *byteData = replacementCode[i];
        }
        return padding;
    };
    static void nopAddress(uintptr_t addr, int size) { // its either protected or im stupid
        for (int i = 0; i < size; ++i) {
            auto byteData = *reinterpret_cast<char*>(addr + size);
            byteData = 0x90;
        }
    };
    static void retAddress(const char* sig, int size) {
        uintptr_t address = findSig(sig);
        for (int i = 0; i < size; ++i) {
            auto byteData = *reinterpret_cast<char*>(address + size);
            byteData = 0xC3;
        }
    };
    static uintptr_t findSig(const char* sig) {
        const char* pattern = sig;
        uintptr_t firstMatch = 0;
        static const uintptr_t rangeStart = (uintptr_t)GetModuleHandleA("Minecraft.Windows.exe");
        static MODULEINFO miModInfo;
        static bool init = false;
        if (!init) {
            init = true;
            GetModuleInformation(GetCurrentProcess(), (HMODULE)rangeStart, &miModInfo, sizeof(MODULEINFO));
        }
        static const uintptr_t rangeEnd = rangeStart + miModInfo.SizeOfImage;

        BYTE patByte = GET_BYTE(pattern);
        const char* oldPat = pattern;

        for (uintptr_t pCur = rangeStart; pCur < rangeEnd; pCur++) {
            if (!*pattern)
                return firstMatch;

            while (*(PBYTE)pattern == ' ')
                pattern++;

            if (!*pattern)
                return firstMatch;

            if (oldPat != pattern) {
                oldPat = pattern;
                if (*(PBYTE)pattern != '\?')
                    patByte = GET_BYTE(pattern);
            };

            if (*(PBYTE)pattern == '\?' || *(BYTE*)pCur == patByte) {
                if (!firstMatch)
                    firstMatch = pCur;

                if (!pattern[2])
                    return firstMatch;

                pattern += 2;
            }
            else {
                pattern = sig;
                firstMatch = 0;
            };
        };
    };
    static void patchBytes(BYTE* dst, BYTE* src, unsigned int size) {
        DWORD oldprotect;
        VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
        memcpy(dst, src, size);
        VirtualProtect(dst, size, oldprotect, &oldprotect);
    }
};