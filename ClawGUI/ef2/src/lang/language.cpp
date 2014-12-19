#include "language.hpp"
#include "text.hpp"

Language::Language(const boost::uuids::uuid& id, const boost::shared_ptr<const Text>& name):
UUID<Language>(id),
	name(name)
{ }

Language::Language(const boost::shared_ptr<const Text>& name):
	UUID<Language>(),
	name(name)
{ }