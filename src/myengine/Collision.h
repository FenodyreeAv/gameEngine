#pragma once
#include "Component.h"
#include "rend/rend.h"

namespace myengine
{
	struct Transform;

	struct Collider : public Component
	{
		void onInitialize();
		
		void onTick();

		void setSize(rend::vec3 _size);
		void setCentre(rend::vec3 _centre);

		rend::vec3 Collider::getSize();
		rend::vec3 Collider::getCentre();


		//bool isColliding(rend::vec3 position, rend::vec3 size);

		//void Collider::collisionResponse(rend::vec3 cludge);
				

		bool Collider::isColliding(rend::vec3 centre, rend::vec3 size, rend::vec3 targetCentre, rend::vec3 targetSize);

		void Collider::setOffset(rend::vec3 offset);

		rend::vec3 Collider::getCollisionResponse(rend::vec3 centre, rend::vec3 size, rend::vec3 targetCentre, rend::vec3 targetSize);


	private:
		rend::vec3 centre;
		rend::vec3 size;
		rend::vec3 offset;

		std::shared_ptr<Collider> self;

		float collisionMultiplier;
		std::weak_ptr<Entity> parent;
		std::weak_ptr<Collider> thisCollider;
		std::weak_ptr<Transform> parentTransform;
		rend::vec3 targetSize;
		rend::vec3 targetCentre;
		std::weak_ptr<Collider> weakptrTarget;

	}; 
}