#if defined(_FMOD_SOUND) || defined(_SDL_MIXER_SOUND)

#include "soundconfiguration.hpp"

SoundConfiguration::SoundConfiguration(const boost::uuids::uuid id,
	const std::string& name,
	const unsigned int musicVolume,
	const unsigned int soundVolume,
	const unsigned int soundChannels		
	):
UUID<SoundConfiguration>(id),
	name(name),
	musicVolume(musicVolume),
	soundVolume(soundVolume),
	soundChannels(soundChannels)
{ }

SoundConfiguration::SoundConfiguration(
	const std::string& name,
	const unsigned int musicVolume,
	const unsigned int soundVolume,
	const unsigned int soundChannels		
	):
UUID<SoundConfiguration>(),
	name(name),
	musicVolume(musicVolume),
	soundVolume(soundVolume),
	soundChannels(soundChannels)
{ }


const SoundConfiguration SoundConfiguration::getDefaultConfiguration() {
	return SoundConfiguration("default", 100, 100, 8);
}

bool SoundConfiguration::equals(const SoundConfiguration& soundConfiguration) const {
	return soundConfiguration.getMusicVolume() == musicVolume && soundConfiguration.getSoundVolume() == soundVolume && soundConfiguration.getSoundChannels() == soundChannels;
}

#endif