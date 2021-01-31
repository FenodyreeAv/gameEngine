#include "Camera.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

#include <iostream>
#include <glm/gtx/string_cast.hpp>

namespace myengine
{

	void Camera::onInitialize()
	{
		std::shared_ptr<Camera> self = getEntity()->getComponent<Camera>();
		getCore()->cameras.push_back(self);
	}

	//rend::mat4 Camera::getView()
	//{
	//	rend::mat4 view = rend::inverse(getTransform()->getModelMatrix());
	//				
	//	std::cout << "getView" << std::endl;
	//	std::cout << glm::to_string(view) << std::endl;

	//	return rend::inverse(getTransform()->getModelMatrix());
	//}

	rend::mat4 Camera::getView()
	{
		rend::mat4 view = rend::inverse(getTransform()->getModelMatrix());
		return rend::inverse(getTransform()->getModelMatrix());
	}

	std::shared_ptr<rend::RenderTexture> Camera::getRenderTexture()
	{
		return renderTexture;
	}

	std::shared_ptr<rend::RenderTexture> Camera::addRenderTexture()
	{
		renderTexture = getCore()->context->createRenderTexture();

		return renderTexture;
	}

}