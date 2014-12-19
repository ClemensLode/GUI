#ifndef WIN32
#define BOOST_TEST_DYN_LINK
#endif
#define BOOST_TEST_MODULE AUDIO
#pragma warning(push, 0) 
#include <boost/test/unit_test.hpp>
#pragma warning(pop)

#include <audio/soundconfiguration_storage.hpp>
#include <audiofixture/soundconfiguration_fixture.hpp>
#include <audio/soundconfiguration.hpp>
#include <misc/ids.hpp>
#include <audio/sound_directories.hpp>

BOOST_FIXTURE_TEST_SUITE( SoundConfiguration_Test, SoundConfiguration_Fixture )

	BOOST_AUTO_TEST_CASE (SoundConfiguration_Constructor)
{

	BOOST_CHECK_EQUAL(test_soundConfiguration->getName(), test_name);
	BOOST_CHECK_EQUAL(test_soundConfiguration->getMusicVolume(), test_musicVolume);
	BOOST_CHECK_EQUAL(test_soundConfiguration->getSoundVolume(), test_soundVolume);
	BOOST_CHECK_EQUAL(test_soundConfiguration->getSoundChannels(), test_soundChannels);
	BOOST_CHECK_EQUAL(test_soundConfiguration->isMusic(), (test_musicVolume > 0));
	BOOST_CHECK_EQUAL(test_soundConfiguration->isSound(), (test_soundVolume > 0));
}

BOOST_AUTO_TEST_CASE(SoundConfiguration_Storage)
{
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->getName(), test_name);
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->getMusicVolume(), test_musicVolume);
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->getSoundVolume(), test_soundVolume);
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->getSoundChannels(), test_soundChannels);
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->isMusic(), (test_musicVolume > 0));
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->isSound(), (test_soundVolume > 0));

	SoundConfigurationStorage::saveToXML();
	SoundConfigurationStorage::reset();

	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->getName(), test_name);
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->getMusicVolume(), test_musicVolume);
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->getSoundVolume(), test_soundVolume);
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->getSoundChannels(), test_soundChannels);
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->isMusic(), (test_musicVolume > 0));
	BOOST_CHECK_EQUAL(SoundConfigurationStorage::instance().get(test_soundConfiguration->getId())->isSound(), (test_soundVolume > 0));
}

BOOST_AUTO_TEST_SUITE_END( )
