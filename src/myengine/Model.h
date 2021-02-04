#pragma once
#include "Exception.h"
#include "Resource.h"
#include <rend/rend.h>

#include <string>
#include <memory>

namespace myengine
{
	struct Renderer;
	/********************************************//**
	* \brief Manages model resources.
	***********************************************/
	struct Model : public Resource
	{
		/********************************************//**
		* \brief Loads model data from file.
		***********************************************/
		void onLoad();

	private:
		friend struct Renderer;

		std::shared_ptr<rend::Mesh> mesh;
	};

}