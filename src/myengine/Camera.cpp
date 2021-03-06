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

	rend::mat4 Camera::getView()
	{
		rend::mat4 view = rend::inverse(getTransform()->getModelMatrix());
		//	std::cout << "getView" << std::endl;
		//	std::cout << glm::to_string(view) << std::endl;
		return rend::inverse(getTransform()->getModelMatrix());
	}

	rend::vec3 Camera::getCameraPos()
	{
		return getEntity()->getComponent<Transform>()->getPosition();
	}

}