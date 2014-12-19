#ifndef _LANG_LANGUAGE_HPP
#define _LANG_LANGUAGE_HPP

class Text;

#include <misc/uuid.hpp>

#include "text_storage.hpp"

class Language : public UUID<Language>
{
public:
	// can't be initialized directly with Text because of interdependency to Text
	Language(const boost::uuids::uuid& id, const boost::shared_ptr<const Text>& name);
	Language(const boost::shared_ptr<const Text>& name);
	~Language() { }

	const boost::shared_ptr<const Text>& getName() const;

private:
	const boost::shared_ptr<const Text> name;

	Language(const Language& other);
	Language& operator=(const Language& other);
};

inline const boost::shared_ptr<const Text>& Language::getName() const {
	return name;
}


#endif // _LANG_LANGUAGE_HPP
