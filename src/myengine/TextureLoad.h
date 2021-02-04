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
	* \brief Manages texture data.
	***********************************************/
	struct TextureLoad: public Resource
	{
		/********************************************//**
		* \brief Loads texture from file.
		***********************************************/
		void onLoad();

	private:
		friend struct Renderer;

		std::shared_ptr<rend::Texture> tex;
	};
}