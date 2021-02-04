#pragma once

#include "Component.h"
#include <rend/rend.h>

namespace myengine
{
	/********************************************//**
	* \brief Component attached to camera entities.
	***********************************************/
	struct Camera : public Component
	{
		/********************************************//**
		* \brief Sets a self pointer to the camera, adds it to the list of cameras.
		***********************************************/
		void onInitialize();

		/********************************************//**
		* \brief Returns the camera's view matrix.
		***********************************************/
		rend::mat4 getView();

		/********************************************//**
		* \brief Retrieves the camera's position from it's transform component and returns it.
		***********************************************/
		rend::vec3 getCameraPos();
	private:

	};

}