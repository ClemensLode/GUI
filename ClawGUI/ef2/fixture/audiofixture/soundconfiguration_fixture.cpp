#include <misc/randomgenerator.hpp>
#include <audio/sound_directories.hpp>

#include "soundconfiguration_fixture.hpp"
#include <audio/soundconfiguration_storage.hpp>

SoundConfiguration_Fixture::SoundConfiguration_Fixture():
	test_name("test sound configuration"),
	test_musicVolume(RandomGenerator::instance().rnd()),
	test_soundVolume(RandomGenerator::instance().rnd()),
	test_soundChannels(RandomGenerator::instance().rnd()),

	test_soundConfiguration(new SoundConfiguration(test_name, test_musicVolume, test_soundVolume, test_soundChannels)),
	test_soundConfigurationMap(init_soundconfigurationmap_helper())
{
	SoundDirectories::initTemp("temp");

	SoundConfigurationStorage::instance(test_soundConfigurationMap);
}

SoundConfiguration_Fixture::~SoundConfiguration_Fixture() 
{ 
	SoundDirectories::initTemp("temp");

	SoundConfigurationStorage::clear();

	SoundDirectories::init();
}


const std::map<const boost::uuids::uuid, const boost::shared_ptr<const SoundConfiguration> > SoundConfiguration_Fixture::init_soundconfigurationmap_helper() const {
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const SoundConfiguration> > soundconfigurationmap;
	soundconfigurationmap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const SoundConfiguration> >(test_soundConfiguration->getId(), test_soundConfiguration));
	return soundconfigurationmap;
}