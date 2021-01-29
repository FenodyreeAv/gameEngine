#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace myengine
{
	void Component::tick()
	{
		onTick();
	}

	void Component::render()
	{
		onRender();
	}

	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}

	std::shared_ptr<Core> Component::getCore()
	{
		return getEntity()->getCore();
	}

	std::shared_ptr<Transform> Component::getTransform()
	{
		return getEntity()->getTransform();
	}

	void Component::onTick() {}
	void Component::onInitialize() {}
	void Component::onRender() {}
}

