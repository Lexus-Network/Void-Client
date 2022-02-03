#pragma once

class Weather {
public:
	virtual void Destructor();
	virtual void onSourceCreated(class BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void onAreaChanged(BlockSource&, class BlockPos const&, BlockPos const&);
	virtual void onBlockChanged(BlockSource&, BlockPos const&, struct uint, class Block const&, Block const&, int, class ActorBlockSyncMessage const*, class BlockChangedEventTarget);
	virtual void onBrightnessChanged(BlockSource&, BlockPos const&);
	virtual void onBlockEntityChanged(BlockSource&, class BlockActor&);
	virtual void onBlockEntityAboutToBeRemoved(BlockSource&, __int64);//Could be broke
	virtual void onEntityChanged(BlockSource&, Actor&);
	virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
	virtual void allChanged(void);
	virtual void addParticle(class ParticleType, Vector3 const&, Vector3 const&, int, class CompoundTag const*, bool);
	virtual void sendServerLegacyParticle(ParticleType, Vector3 const&, Vector3 const&, int);
	virtual void addParticleEffect(class HashedString const&, Vector3 const&, class MolangVariableMap const&);
	virtual void addParticleEffect(HashedString const&, Actor const&, HashedString const&, Vector3 const&, MolangVariableMap const&);
	virtual void addTerrainParticleEffect(BlockPos const&, Block const&, Vector3 const&, float, float, float);
	virtual void addTerrainSlideEffect(BlockPos const&, Block const&, Vector3 const&, float, float, float);
	virtual void addBreakingItemParticleEffect(Vector3 const&, ParticleType, class TextureUVCoordinateSet const&, bool);
	virtual void playMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void playStreamingMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, int, int, int);
	virtual void onEntityAdded(Actor&);
	virtual void onEntityRemoved(Actor&);
	virtual void onChunkLoaded(class ChunkSource&, class LevelChunk&);
	virtual void onChunkReloaded(ChunkSource&, LevelChunk&);
	virtual void onSubChunkLoaded(ChunkSource&, LevelChunk&, short);
	virtual void onChunkUnloaded(LevelChunk&);
	virtual void onLevelDestruction(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void levelEvent(class LevelEvent, Vector3 const&, int);
	virtual void levelEvent(LevelEvent, CompoundTag const&);
	virtual void levelSoundEvent(class LevelSoundEvent, Vector3 const&, int, struct ActorDefinitionIdentifier const&, bool, bool);
	virtual void levelSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void stopSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void stopAllSounds(void);
	virtual void takePicture(__int64, Actor*, Actor*, class ScreenshotOptions&);//Could be broke
	virtual void playerListChanged(void);

private:
	char pad_0x0000[0x38]; //0x0000
public:
	bool isRaining; //0x0038
private:
	char pad_0x0039[0xB]; //0x0039
public:
	bool isLightning; //0x0044
private:
	char pad_0x0045[0x3]; //0x0045
public:
	float lightningLevel; //0x0048
};