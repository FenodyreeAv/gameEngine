#include "Collision.h"
#include "Entity.h"
#include "Core.h"
#include "rend/rend.h"
#include "Transform.h"
#include "glm/gtx/string_cast.hpp"
#include <iostream>

namespace myengine
{
	void Collider::onInitialize()
	{
		centre = getTransform()->getPosition();
		size = rend::vec3(0.0f);

		self = getEntity()->getComponent<Collider>();
		getCore()->colliders.push_back(self);

		thisCollider = getEntity()->getComponent<Collider>();
		std::weak_ptr<Transform> parentTransform = getEntity()->getTransform();
	}
	
	void Collider::onTick() 
	{
		centre = getTransform()->getPosition();
		
		for (size_t c1 = 0; c1 < getCore()->colliders.size(); c1++) //Iterates through pointers to Collider Objects
		{
			std::weak_ptr<Collider> weakptrTarget = getCore()->colliders.at(c1);
			rend::vec3 targetSize = weakptrTarget.lock()->getSize();
			rend::vec3 targetCentre = weakptrTarget.lock()->getCentre();

			//if (thisCollider.owner_before(getCore()->colliders.at(c1))) //Checks if the weak pointers are the same
			if (centre == targetCentre)
			{
				std::cout << "Ignored self collision." <<std::endl;
			}
			else
			{				
				//std::weak_ptr<Collider> weakptrTarget = getCore()->colliders.at(c1);
				//rend::vec3 targetSize = weakptrTarget.lock()->getSize();
				//rend::vec3 targetCentre = weakptrTarget.lock()->getCentre();

				std::cout << "onTick Centre: ";
				std::cout << glm::to_string(centre) << std::endl;

				getTransform()->setPosition(getCollisionResponse(centre, size, targetSize, targetCentre));

				//std::cout << "This object Size: ";
				//std::cout << glm::to_string(size) << std::endl;
				//std::cout << "This object Centre: ";
				//std::cout << glm::to_string(centre) << std::endl;

				//std::cout << c1;
				//std::cout << " object Size: ";
				//std::cout << glm::to_string(targetSize) << std::endl;

				//std::cout << c1;
				std::cout << "onTick targetCentre: ";
				std::cout << glm::to_string(targetCentre) << std::endl;

				//bool x = true;
				//bool y = true;
				//bool z = true;
				//if (centre.x > targetCentre.x)
				//{
				//	if (targetCentre.x + (targetSize.x / 2.0f) < centre.x - (size.x / 2.0f)) { x = false; }
				//}
				//else
				//{
				//	if (targetCentre.x - (targetSize.x / 2.0f) > centre.x + (size.x / 2.0f)) { x = false; }
				//}

				//if (centre.y > targetCentre.y)
				//{
				//	if (targetCentre.y + (targetSize.y / 2.0f) < centre.y - (size.y / 2.0f)) { y = false; }
				//}
				//else
				//{
				//	if (targetCentre.y - (targetSize.y / 2.0f) > centre.y + (size.y / 2.0f)) { y = false; }
				//}

				//if (centre.z > targetCentre.z)
				//{
				//	if (targetCentre.z + (targetSize.z / 2.0f) < centre.z - (size.z / 2.0f)) { z = false; }
				//}
				//else
				//{
				//	if (targetCentre.z - (targetSize.z / 2.0f) > centre.z + (size.z / 2.0f)) { z = false; }
				//}
				//if (x == true && y == true && z == true)
				//{


					//////getEntity()->getComponent<Collider>()->collisionResponse(rend::vec3(oldCentre));
					//rend::vec3 seperation = centre - targetCentre;
					//if (seperation.x < seperation.y && seperation.x < seperation.y)
					//{
					//	getEntity()->getComponent<Collider>()->collisionResponse(rend::vec3(0.1, 0.0, 0.0));
					//}
					////if (seperation.y < seperation.x && seperation.z < seperation.y)
					////{
					////	getEntity()->getComponent<Collider>()->collisionResponse(rend::vec3(0.0, 0.1, 0.0));
					////}
					//if (seperation.z < seperation.y && seperation.x < seperation.y)
					//{
					//	getEntity()->getComponent<Collider>()->collisionResponse(rend::vec3(0.0, 0.0, 0.1));
					//}
			


				//std::cout << "Collision with: " << c1 << std::endl;
			}
		}
	}


	rend::vec3 Collider::getSize()
	{
		return size;
	}

	rend::vec3 Collider::getCentre()
	{
		return centre;
	}
	
	void Collider::setSize(rend::vec3 _size)
	{
		this->size = _size;
		std::cout << glm::to_string(size) << std::endl;
	}
	void Collider::setCentre(rend::vec3 _centre)
	{
		this->centre = _centre;
		std::cout << glm::to_string(centre) << std::endl;
	}

	bool Collider::isColliding(rend::vec3 centre, rend::vec3 size, rend::vec3 targetCentre, rend::vec3 targetSize)
	{
		centre = getCentre();

		//std::cout << "This object Size: ";
		//std::cout << glm::to_string(size) << std::endl;
		std::cout << "isColliding Centre: ";
		std::cout << glm::to_string(centre) << std::endl;


		//std::cout << " object Size: ";
		//std::cout << glm::to_string(targetSize) << std::endl;
		std::cout << "isColliding targetCentre: ";
		std::cout << glm::to_string(targetCentre) << std::endl;

		if (centre.x > targetCentre.x)
		{
			if (targetCentre.x + (targetSize.x / 2.0f) < centre.x - (size.x / 2.0f)) { return false; }
		}
		else
		{
			if (targetCentre.x - (targetSize.x / 2.0f) > centre.x + (size.x / 2.0f)) { return false; }
		}

		if (centre.y > targetCentre.y)
		{
			if (targetCentre.y + (targetSize.y / 2.0f) < centre.y - (size.y / 2.0f)) { return false; }
		}
		else
		{
			if (targetCentre.y - (targetSize.y / 2.0f) > centre.y + (size.y / 2.0f)) { return false; }
		}

		if (centre.z > targetCentre.z)
		{
			if (targetCentre.z + (targetSize.z / 2.0f) < centre.z - (size.z / 2.0f)) { return false; }
		}
		else
		{
			if (targetCentre.z - (targetSize.z / 2.0f) > centre.z + (size.z / 2.0f)) { return false; }
		}

		return true;

	}

	void Collider::setOffset(rend::vec3 _offset)
	{
		offset = _offset;
	}

	rend::vec3 Collider::getCollisionResponse(rend::vec3 centre, rend::vec3 size, rend::vec3 targetCentre, rend::vec3 targetSize)
	{
		{
			centre = (getTransform()->getPosition());
			float amount = 0.1f;
			float step = 0.1f;
			while (true)
			{

				std::cout << "getCollisionResponse Centre: ";
				std::cout << glm::to_string(centre) << std::endl;

				////std::cout << "This object Size: ";
				////std::cout << glm::to_string(size) << std::endl;
				//std::cout << "This object Centre: ";
				//std::cout << glm::to_string(centre) << std::endl;

				////std::cout << " object Size: ";
				////std::cout << glm::to_string(targetSize) << std::endl;
				std::cout << "getCollisionResponse targetCentre: ";
				std::cout << glm::to_string(targetCentre) << std::endl;

				if (!isColliding(centre, size, targetCentre, targetSize)) break;
				centre.x += amount;
				if (!isColliding(centre, size, targetCentre, targetSize)) break;
				centre.x -= amount;
				centre.x -= amount;
				if (!isColliding(centre, size, targetCentre, targetSize)) break;
				centre.x += amount;
				centre.z += amount;
				if (!isColliding(centre, size, targetCentre, targetSize)) break;
				centre.z -= amount;
				centre.z -= amount;
				if (!isColliding(centre, size, targetCentre, targetSize)) break;
				centre.z += amount;
				centre.y += amount;
				if (!isColliding(centre, size, targetCentre, targetSize)) break;
				centre.y -= amount;
				centre.y -= amount;
				if (!isColliding(centre, size, targetCentre, targetSize)) break;
				centre.y += amount;
				amount += step;
			}
			return centre;
		}
	}

	//void Collider::collisionResponse(rend::vec3 cludge)
	//{
	//	getTransform()->translate(cludge.x, cludge.y, cludge.z);
	//	//getTransform()->setPosition(cludge);
	//}
}