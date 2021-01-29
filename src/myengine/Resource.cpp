#include "Resource.h"
#include "ResourceList.h"

namespace myengine
{
	struct Core;
	struct ResourceList;

	void Resource::load()
	{
		onLoad();
	}

	std::string Resource::getPath()
	{
		return path;
	}

	std::shared_ptr<Core> Resource::getCore()
	{
		return core.lock();
	}

}
