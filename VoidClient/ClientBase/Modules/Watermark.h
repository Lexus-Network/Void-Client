#pragma once

class Watermark : public Module {
public:
	Watermark(std::string cat) : Module(cat, "Watermark", "Display watermark of client", 0x07, true) {};

	void OnFrameRender(RenderUtils* ctx) override {
		auto vText1 = TextHolder("void client"); //"rgb"

		//RGB
		_RGB rainbow;
		float offset = 0.f;
		long rainbowIndex = offset * 900;
		rainbow = ctx->getRainbow(5, 1.0f, 1.0f, rainbowIndex, 255.f, 255.f, 255.f, 255.f);

		Vector2 strPos = Vector2(0, 0);

		strPos.x = ctx->guiData->scaledResolution.x - ctx->ctx->getLineLength(ctx->font, &vText1, 1) - 4;
		strPos.y = ctx->guiData->scaledResolution.y - 20.f;

		ctx->DrawString(strPos, rainbow, vText1, ctx->font);
	}

	//void OnGameTick(Actor* lp) override {};
};
