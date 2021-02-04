#include "Entity.h"
#include "Component.h"
#include "Transform.h"
#include <iostream>
#include "Exception.h"

namespace myengine
{

void Entity::tick()
{

	for (size_t ci = 0; ci < components.size(); ci++) //Iterates through entities list
	{
		//TODO: Verbose flag, prints these to console when true

		//std::cout << "Component Index: "; 
		//std::cout << ci << std::endl;
		try
		{
			components.at(ci)->tick();
		}
		catch (Exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
			components.at(ci)->kill();
		}

		if (components.at(ci)->broken == true)
		{
			components.erase(components.begin() + ci);
			ci--;
			std::cout << "Exception Caught: Deleted component that threw the exception." << std::endl;
		}
	}
}

void Entity::render()
{
	for (size_t ci = 0; ci < components.size(); ci++)
	{
		components.at(ci)->render();
	}
}

void Entity::clearComponents() //Ask if this is necessary?
{
	for (size_t ci = 0; ci < components.size(); ci++)
	{
		components.erase(components.begin() + ci);
		ci--;
	}
}

std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}
std::shared_ptr<Transform> Entity::getTransform()
{
	return getComponent<Transform>();
}

}

