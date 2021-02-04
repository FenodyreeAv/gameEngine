#pragma once
#include "Component.h"
#include "rend/rend.h"

namespace myengine
{
	struct Transform;

	/********************************************//**
	* \brief Component attached to physics entities, handles collisions between objects.
	***********************************************/
	struct Collider : public Component
	{
		/********************************************//**
		* \brief 
		***********************************************/
		void onInitialize();
		
		void onTick();

		void Collider::setSize(rend::vec3 _size);
		void Collider::setCentre(rend::vec3 _centre);
		void Collider::setAnchor(bool _anchored);
		void Collider::setOffset(rend::vec3 offset);

		rend::vec3 Collider::getSize();
		rend::vec3 Collider::getCentre();
		rend::vec3 Collider::getCollisionResponse(rend::vec3 centre, rend::vec3 size, rend::vec3 targetCentre, rend::vec3 targetSize);

		bool Collider::isColliding(rend::vec3 centre, rend::vec3 size, rend::vec3 targetCentre, rend::vec3 targetSize);
		bool Collider::getAnchor();

	private:
		rend::vec3 centre;
		rend::vec3 size;
		rend::vec3 offset;

		std::shared_ptr<Collider> self;

		bool anchored;

		std::weak_ptr<Entity> parent;
		std::weak_ptr<Collider> thisCollider;
		std::weak_ptr<Transform> parentTransform;
		//std::weak_ptr<Collider> weakptrTarget;

	}; 
}