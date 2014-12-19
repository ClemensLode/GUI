#ifndef _AUDIO_FIXTURE_SOUNDCONFIGURATIONFIXTURE_HPP
#define _AUDIO_FIXTURE_SOUNDCONFIGURATIONFIXTURE_HPP

#pragma warning(push, 0)  
#include <boost/smart_ptr.hpp>
#pragma warning(pop)

#include <audio/soundconfiguration.hpp>
#include <map>

struct SoundConfiguration_Fixture
{
	const std::string test_name;
	const unsigned int test_musicVolume;
	const unsigned int test_soundVolume;
	const unsigned int test_soundChannels;

	const boost::shared_ptr<const SoundConfiguration> test_soundConfiguration;

	SoundConfiguration_Fixture();	
	~SoundConfiguration_Fixture();

private:
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const SoundConfiguration> > test_soundConfigurationMap;
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const SoundConfiguration> > init_soundconfigurationmap_helper() const;
};

#endif // _AUDIO_FIXTURE_SOUNDCONFIGURATIONFIXTURE_HPP
