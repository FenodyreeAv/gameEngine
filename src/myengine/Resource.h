#pragma once
#include <string>
#include <memory>

namespace myengine
{
	struct Core;
	struct ResourceList;

	struct Resource
	{


		void load();

		virtual void onLoad() {}; //override with instructions on loading
		
		std::string getPath();
		std::shared_ptr<Core> getCore();
	private:
		friend struct myengine::ResourceList;

		std::string path;
		std::weak_ptr<ResourceList> resourceList;
		std::weak_ptr<Core> core;
	};
}


