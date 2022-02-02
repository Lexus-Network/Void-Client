#pragma once

#include <cstdint>
#include "../Utils/Math.h"
#include "TextHolder.h"

// 48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 B8 0F 29 78 A8 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B FA 48 89 54 24 ? 4C 8B

class NinesliceInfo { // how the fuck did onix find what goes in this
private:
    char pad_0x0000[0xFF]; //0x0000
};

class MinecraftUIRenderContext {
private:
    virtual auto Constructor() -> void {};
public:
    virtual float getLineLength(class BitmapFont* font, TextHolder* text, float textSize);
    virtual float getTextAlpha();
    virtual auto setTextAlpha(float alpha) -> void {};
    virtual auto drawDebugText(const float* pos, TextHolder* text, float* color, float alpha, unsigned int textAlignment, const float* textMeasureData, const void* caretMeasureData) -> void {};
    virtual auto drawText(class BitmapFont* font, Rect* position, TextHolder* text, _RGB colour, float alpha, unsigned int* textAlignment, const float* textMeasureData, const CaretMeasureData* caretMeasureData) -> void {};
    virtual auto flushText(float timeSinceLastFlush) -> void {};
    virtual auto drawImage(class TexturePtr* const& texture, Rect _1, Rect _2, Rect _3, Rect _4) -> void {};
    virtual auto drawNineslice(class TexturePtr* const& texturePtr, NinesliceInfo NinesliceInfo) -> void {};
    virtual auto flushImages(float timeSinceLastFlush) -> void {};
    virtual auto beginSharedMeshBatch(uintptr_t ComponentRenderBatch) -> void {};
    virtual auto endSharedMeshBatch(float timeSinceLastFlush) -> void {};
    virtual auto drawRectangle(Rect position, _RGB colour, float alpha, int lineWidth) -> void {};
    virtual auto fillRectangle(Rect position, _RGB colour, float alpha) -> void {};
    virtual auto increaseStencilRef() -> void {};
    virtual auto decreaseStencilRef() -> void {};
    virtual auto resetStencilRef() -> void {};
    virtual auto fillRectangleStencil(Rect position) -> void {};
    virtual auto enableScissorTest(Rect position) -> void {};
    virtual auto disableScissorTest() -> void {};
    virtual auto setClippingRectangle(Rect position) -> void {};
    virtual auto setFullClippingRectangle() -> void {};
    virtual auto saveCurrentClippingRectangle() -> void {};
    virtual auto restoreSavedClippingRectangle() -> void {};
    virtual auto getFullClippingRectangle() -> int {};
    virtual auto updateCustom(uintptr_t a1) -> void {};
    virtual auto renderCustom(uintptr_t a1, int a2, Rect position) -> void {};
    virtual auto cleanup() -> void {};
    virtual auto removePersistentMeshes() -> void {};
    virtual auto getTexture(class TexturePtr* ResourceLocation, bool a2) -> int {};
    virtual auto getZippedTexture(class TexturePtr* Path, class TexturePtr* ResourceLocation, bool a3) -> int {};
    virtual auto unloadTexture(class TexturePtr* ResourceLocation) -> void {};
    virtual auto getUITextureInfo(class TexturePtr* ResourceLocation, bool a2) -> int {};
    virtual auto touchTexture(class TexturePtr* ResourceLocation) -> void {};
    virtual auto getMeasureStrategy(Vector2 const&) -> int {};
    virtual auto snapImageSizeToGrid(Vector2 const&) -> void {};
    virtual auto snapImagePositionToGrid(Vector2 const&) -> void {};
    virtual auto notifyImageEstimate(ULONG) -> void {};
};