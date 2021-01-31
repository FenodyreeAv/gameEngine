#pragma once
#include <vector>
#include <memory>
#include "Component.h"
#include "Exception.h"

namespace myengine
{

	struct Component;
	struct Core;
	struct Exception;
	struct Transform;

	struct Entity
	{
		friend struct ::myengine::Core;

		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;

			components.push_back(rtn);

			rtn->onInitialize();   //Calls function based on template generation

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (size_t i = 0; i < components.size(); i++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(components.at(i));

				if (!rtn) continue;

				return rtn;
			}

			throw Exception("Entity does not contain requested type");
		}

		void tick();
		void render();

		void clearComponents();

		std::shared_ptr<Transform> getTransform();
		std::shared_ptr<Core> getCore();
		
		
	private:
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;
		bool broken;
	};
}