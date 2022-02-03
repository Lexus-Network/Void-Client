#pragma once

class GameMode {
public:
    class Actor* actorPtr; //0x0008
private:
    virtual __int64 Destructor();
public:
    virtual __int64 startDestroyBlock(struct Vector3i const& pos, unsigned char blockSide, bool& isDestroyedOut);
    virtual __int64 destroyBlock(struct Vector3i*, unsigned char);
    virtual __int64 continueDestroyBlock(struct Vector3i const&, unsigned char blockSide, bool& isDestroyedOut);
    virtual __int64 stopDestroyBlock(struct Vector3i const&);
    virtual __int64 startBuildBlock(struct Vector3i const&, unsigned char);
    virtual void buildBlock(struct Vector3i*, unsigned char);
    virtual __int64 continueBuildBlock(struct Vector3i const&, unsigned char);
    virtual __int64 stopBuildBlock(void);
    virtual __int64 tick(void);
    virtual float getPickRange();
    virtual __int64 useItem();
    virtual __int64 useItemOn();
    virtual __int64 interact(Actor*, struct Vector3*);
    virtual __int64 attack(Actor*);
    virtual __int64 releaseUsingItem();
    virtual __int64 setTrialMode(bool);
    virtual bool isInTrialMode(void);
};