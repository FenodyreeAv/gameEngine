#pragma once
#include "Component.h"

#include <rend/rend.h>

#include <memory>

namespace myengine
{
	struct Model;
	struct TextureLoad;

	struct Renderer : public Component
	{
		void onInitialize();
		void onRender();
		
		void setModel(std::shared_ptr<Model> model);
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


