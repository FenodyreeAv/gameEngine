#pragma once
#include "Resource.h"

#include <memory>
#include <string>
#include <vector>
#include <iostream>

namespace myengine
{

	struct Core;

	struct ResourceList
	{

		template <typename T>
		std::shared_ptr<T> loadPath(const char* path)
		{
			for (size_t i = 0; i < resourceList.size(); i++)
			{
				
				if (resourceList.at(i)->path == path) //checks if path is already in list
				{
					std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(resourceList.at(i)); //if it is in the list, get a pointer to it & return

					if (!rtn) continue;
					return rtn;
				}
			}
			std::shared_ptr<T> rtn = std::make_shared<T>(); //if not in the list, load it & add it to the list
			rtn->core = core;
			rtn->path = path;
			rtn->onLoad();
			resourceList.push_back(rtn);
			std::cout << resourceList.size();

			return rtn;


		}

	private:
		friend struct myengine::Core;
		std::weak_ptr<ResourceList> self;
		std::vector<std::shared_ptr<Resource> > resourceList;
		std::weak_ptr<Core> core;
	};
}