#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>

namespace myengine
{

	struct Entity;
	struct Core;
	struct Transform;

	struct Component
	{
		friend struct myengine::Entity; //Share private with entity

		virtual void onInitialize(); //Fallback, will not be called without correct parameter types

		void tick();
		virtual void onTick();

		void render();
		virtual void onRender(); 

		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Transform> getTransform();

	private:
		std::weak_ptr<Entity> entity; //Pointer to the entity this component belongs to

	};
	
}

#endif