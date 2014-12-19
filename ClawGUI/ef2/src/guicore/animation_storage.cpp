#include "animation_storage.hpp"
#include "animation.hpp"

#include <misc/miscellaneous.hpp>
#include <misc/io.hpp>

template<> const std::string SingleStorage<Animation>::DATA_FILE_NAME_BASE = IO::getDirectory(boost::assign::list_of("data")("storage")("guicore")) + "animation.xml";
template<> const std::string SingleStorage<Animation>::DATA_FILE_IDENTIFIER = "AnimationStorage";
