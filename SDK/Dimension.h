#pragma once

#include <string>
#include "Weather.h"
#include "Packet/Packet.h"

class Dimension {
private:
	virtual void TryroFunc1();
	virtual void TryroFunc2();
	virtual void TryroFunc3();
	virtual void TryroFunc4();
public:
	virtual void onSourceCreated(class BlockSource&);
	virtual void onSourceDestroyed(class BlockSource&);
	virtual void onAreaChanged(class BlockSource&, class BlockPos const&, class BlockPos const&);
	virtual void onBlockChanged(class BlockSource&, class BlockPos const&, class uint, class Block const&, class Block const&, int, class ActorBlockSyncMessage const*, class BlockChangedEventTarget);
	virtual void onBrightnessChanged(class BlockSource&, class BlockPos const&);
	virtual void onBlockEntityChanged(class BlockSource&, class BlockActor&);
	virtual void onBlockEntityAboutToBeRemoved(); //removed
	virtual void onEntityChanged(class BlockSource&, class Actor&);
	virtual void onBlockEvent(class BlockSource&, int, int, int, int, int);
	virtual void allChanged(void);
	virtual void addParticle(class ParticleType, Vector3 const&, Vector3 const&, int, class CompoundTag const*, bool);
	virtual void sendServerLegacyParticle(ParticleType, Vector3 const&, Vector3 const&, int);
	virtual void addParticleEffect(class HashedString const&, Vector3 const&, class MolangVariableMap const&);
	virtual void addParticleEffect(class HashedString const&, class Actor const&, class HashedString const&, Vector3 const&, class MolangVariableMap const&);
	virtual void addTerrainParticleEffect(BlockPos const&, Block const&, Vector3 const&, float, float, float);
	virtual void addTerrainSlideEffect(BlockPos const&, Block const&, Vector3 const&, float, float, float);
	virtual void addBreakingItemParticleEffect(Vector3 const&, ParticleType, class TextureUVCoordinateSet const&, bool);
	virtual void playMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void playStreamingMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, int, int, int);
	virtual void onEntityAdded(class Actor&);
	virtual void onEntityRemoved(class Actor&);
	virtual void onChunkLoaded(class ChunkSource&, class LevelChunk&);
	virtual void onSubChunkLoaded(class ChunkSource&, class LevelChunk&, short);
	virtual void onChunkUnloaded(class LevelChunk&);
	virtual void onLevelDestruction(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void levelEvent(class LevelEvent, Vector3 const&, int);
	virtual void levelEvent(class LevelEvent, CompoundTag const&);
	virtual void levelSoundEvent(class LevelSoundEvent, Vector3 const&, int, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void levelSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void stopSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void stopAllSounds(void);
	virtual void takePicture(); //removed
	virtual void playerListChanged(void);
	virtual void init(void);
	virtual void tick(void);
	virtual void tickRedstone(void);
private:
	virtual void TryroFunc41();
	virtual void TryroFunc42();
	virtual void TryroFunc43();
public:
	virtual bool isNaturalDimension(void);
	virtual bool isValidSpawn(int, int);
	virtual float getBrightnessDependentFogColor(); //removed
	virtual bool isFoggyAt(int, int);
	virtual int getCloudHeight(void);
	virtual int getDefaultBiome(void);
	virtual void mayRespawnViaBed(void);
	virtual void hasGround(void);
	virtual int getSpawnPos(void);
	virtual int getSpawnYPosition(void);
	virtual void hasBedrockFog(void);
	virtual int getClearColorScale(void);
	virtual void showSky(void);
	virtual bool isDay(void);
	virtual float getSunIntensity(float, Vector3 const&, float);
	virtual void forceCheckAllNeighChunkSavedStat(void);
private:
	virtual void TryroFunc60();
public:
	virtual void deserialize(class CompoundTag const&);
	virtual void serialize(class CompoundTag&);
	virtual void sendBroadcast(class Packet const&, class Player*);
	virtual bool is2DPositionRelevantForPlayer(class BlockPos const&, class Player&);
	virtual bool isActorRelevantForPlayer(class Player&, class Actor const&);
	virtual int getLightTextureImageBuilder(void);
	virtual int getBrightnessRamp(void);
	virtual void startLeaveGame(void);
	virtual float getTimeOfDay(int, float);
	virtual void _createChunkBuildOrderPolicy(void);

private:
	char pad_0x0000[0x18]; //0x0000
public:
	std::string DimenstionName; //0x0034 
private:
	char pad_0x0038[0xD8]; //0x0038
public:
	Weather* weather; //0x0110
};