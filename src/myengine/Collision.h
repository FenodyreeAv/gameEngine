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
		* \brief Sets up the collider, adds it to the list of colliders.
		*
		* Initializes the size and centre variables, gets a weak pointer to the transform component attached to the parent entity and assigns a shared pointer to itself.
		***********************************************/
		void onInitialize();
		
		/********************************************//**
		* \brief Iterates through the list of colliders, checks if they are colliding.
		*
		* Updates the centre variable, iterates through the colliders list, assigns each collider to the target shared pointer.
		* Compares the self-pointer to target-pointer and ends if they point to the same object. Calls the getCollisionResponse function, passing it the centre, size, targetCentre and targetSize variables.
		***********************************************/
		void onTick();

		/********************************************//**
		* \brief Sets the size variable.
		***********************************************/
		void Collider::setSize(rend::vec3 _size);	

		/********************************************//**
		* \brief Sets the centre variable.
		***********************************************/
		void Collider::setCentre(rend::vec3 _centre);

		/********************************************//**
		* \brief Sets the anchored boolean.
		***********************************************/
		void Collider::setAnchor(bool _anchored);
		
		/********************************************//**
		* \brief Sets offset variable.
		***********************************************/
		void Collider::setOffset(rend::vec3 offset);


		/********************************************//**
		* \brief Returns the size variable.
		***********************************************/
		rend::vec3 Collider::getSize();

		/********************************************//**
		* \brief Returns the centre variable.
		***********************************************/
		rend::vec3 Collider::getCentre();

		/********************************************//**
		* \brief Transforms the attached entity until it is no longer colliding.
		*
		* Calls the isColliding function, when it returns true, returns a vec3, passed to the translate function in the transform component.
		***********************************************/
		rend::vec3 Collider::getCollisionResponse(rend::vec3 centre, rend::vec3 size, rend::vec3 targetCentre, rend::vec3 targetSize);

		/********************************************//**
		* \brief Returns true if two objects are colliding.
		*
		* Compares the centre and size variables of the self and target, returns true if a collision is occuring.
		***********************************************/
		bool Collider::isColliding(rend::vec3 centre, rend::vec3 size, rend::vec3 targetCentre, rend::vec3 targetSize);

		/********************************************//**
		* \brief Returns the anchored boolean.
		***********************************************/
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
	}; 
}