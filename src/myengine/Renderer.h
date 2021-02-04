#pragma once
#include "Component.h"

#include <rend/rend.h>

#include <memory>

namespace myengine
{
	struct Model;
	struct TextureLoad;
	/********************************************//**
	* \brief Handles rendering to the screen.
	***********************************************/
	struct Renderer : public Component
	{
		/********************************************//**
		* \brief Called on creation of a renderer, sets up the shaders.
		***********************************************/
		void onInitialize();
		/********************************************//**
		* \brief Handles rendering to the screen, called once per tick.
		***********************************************/
		void onRender();
		
		/********************************************//**
		* \brief Returns pointer to the model to be rendered.
		***********************************************/
		void setModel(std::shared_ptr<Model> model);
		/********************************************//**
		* \brief Returns pointer to the texture to be used.
		***********************************************/
		void setTexture(std::shared_ptr<TextureLoad> _texture);

	private:
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<TextureLoad> texture;
		std::shared_ptr<Model> model;
		//std::shared_ptr<rend::Mesh> shape;

		//std::shared_ptr<rend::Buffer> shape;

		//rend::mat4 Renderer::getProjectionMatrix();
		//rend::mat4 Renderer::getModelMatrix();
	};
}


