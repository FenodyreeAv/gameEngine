#pragma once
#include <rend/rend.h>
#include "Component.h"

namespace myengine
{
	/********************************************//**
	* \brief Manages positional data.
	***********************************************/
	struct Transform : public Component
	{
		/********************************************//**
		* \brief Called when transform component is created.
		***********************************************/
		void onInitialize();

		/********************************************//**
		* \brief Returns the model matrix.
		***********************************************/
		rend::mat4 getModelMatrix();

		/********************************************//**
		* \brief Moves the parent entity.
		***********************************************/
		void translate(float x, float y, float z);
		/********************************************//**
		* \brief Rotates the parent entity.
		***********************************************/
		void rotate(float x, float y, float z);

		/********************************************//**
		* \brief Sets the position of the parent entity.
		***********************************************/
		void setPosition(rend::vec3 _position);
		/********************************************//**
		* \brief Sets the rotation of the parent entity.
		***********************************************/
		void setRotation(rend::vec3 _rotation);
		/********************************************//**
		* \brief Sets the scale of the parent entity.
		***********************************************/
		void setScale(rend::vec3 _scale);

		/********************************************//**
		* \brief Returns the position of the parent entity.
		***********************************************/
		rend::vec3 getPosition();

	private:
			rend::vec3 rotation;
			rend::vec3 position;
			rend::vec3 scale;
	};
}
