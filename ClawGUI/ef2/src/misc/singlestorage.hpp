#ifndef _MISC_SINGLESTORAGE_HPP
#define _MISC_SINGLESTORAGE_HPP

#include <map>

#pragma warning(push, 0)
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/noncopyable.hpp>
#include <boost/assign/list_of.hpp>
#pragma warning(pop)

#include "uuid.hpp"
#include "miscellaneous.hpp"
#include "nodecreator.hpp"
#include "loadsave.hpp"
#include "io.hpp"

template<class T>
class SingleStorage : public NodeCreator<T>, public LoadSave, private boost::noncopyable
{
public:
	static SingleStorage<T>& instance(const std::map<const boost::uuids::uuid, const boost::shared_ptr<const T> >& itemMap)
    {
		if(!initialized) {
			t.reset(new SingleStorage<T>(itemMap));
			initialized = true;			
		} else {
			for(typename std::map<const boost::uuids::uuid, const boost::shared_ptr<const T> >::const_iterator i = itemMap.begin(); i != itemMap.end(); i++) {
				t->itemMap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const T> >(i->first, i->second));
			}
		}
		return *t;
    }

	static SingleStorage<T>& instance()
    {
		if(!initialized) {
			SingleStorage<T>* temp = NULL;
			loadFromXML(temp);
			t.reset(temp);
			initialized = true;
		}
        return *t;
    }

	static void reset() {
		initialized = false;
	}

	static void clear() {
		reset();
		IO::removeFile(DATA_FILE_NAME);
	}

	const boost::shared_ptr<const T> get(const boost::uuids::uuid& id) const {
		if(id.is_nil()) {
			return boost::shared_ptr<const T>();
		}
		if(itemMap.find(id) == itemMap.end()) {
			std::ostringstream os;
			os << "ERROR: Could not retrieve entry, UUID " << id << " not found.";
			throw os.str();
		}
		return itemMap.find(id)->second;
	}

	const boost::shared_ptr<const T> get(const std::string& id) const {
		if(id.empty()) {
			return boost::shared_ptr<const T>();
		}
		return get(Misc::uuid(id));
	}
	
	static void saveToXML() {
		XmlNode node("itemMap");
		for(typename std::map<const boost::uuids::uuid, const boost::shared_ptr<const T> >::const_iterator i = t->itemMap.begin(); i != t->itemMap.end(); i++) {
			node.addChild(NodeCreator<T>::createNodeFromObject(*(i->second)));
		}
		LoadSave::saveToXML(node, DATA_FILE_NAME, DATA_FILE_IDENTIFIER);
	}

	~SingleStorage() { 
		// saveToXML(); TODO segfault... better save it individually called by the editor UI?
	}
	const std::map<const boost::uuids::uuid, const boost::shared_ptr<const T> >& getItemMap() const { return itemMap;}

	static std::string DATA_FILE_NAME;
	static const std::string DATA_FILE_NAME_BASE;
protected:
	std::map<const boost::uuids::uuid, const boost::shared_ptr<const T> > itemMap;
	static boost::scoped_ptr<SingleStorage<T> > t;
private:
	
	
	static void loadFromXML(SingleStorage<T>*& tis) {
		XmlNode node = LoadSave::loadFromXML(DATA_FILE_NAME, DATA_FILE_IDENTIFIER);
		std::map<const boost::uuids::uuid, const boost::shared_ptr<const T> > newmap;
		for(std::vector<XmlNode>::const_iterator i = node.getChildren().begin(); i != node.getChildren().end(); i++) {
			std::string id = i->getChildren().front().getValue();
			newmap.insert(std::pair<const boost::uuids::uuid, const boost::shared_ptr<const T> >(Misc::uuid(id), NodeCreator<T>::createObjectFromNode(i->getChildren())));
		}

		tis = new SingleStorage<T>(newmap);
	}
	
	
	SingleStorage(const std::map<const boost::uuids::uuid, const boost::shared_ptr<const T> >& itemMap):itemMap(itemMap) { }

	static bool initialized;
	
	
	static const std::string DATA_FILE_IDENTIFIER;

};

template<class T> std::string SingleStorage<T>::DATA_FILE_NAME = "";
template<class T> bool SingleStorage<T>::initialized = false;
template<class T> boost::scoped_ptr<SingleStorage<T> > SingleStorage<T>::t(0);

#endif // _MISC_SINGLESTORAGE_HPP
