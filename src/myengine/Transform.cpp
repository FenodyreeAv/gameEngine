#include "Transform.h"
#include <glm/gtx/string_cast.hpp>
#include <iostream>

namespace myengine
{
	void Transform::onInitialize()
	{
		position = rend::vec3(0.0f);
		rotation = rend::vec3(0.0f);
		scale = rend::vec3(1, 1, 1);
	}


	rend::mat4 Transform::getModelMatrix()
	{
		rend::mat4 modelMatrix = rend::mat4(1.0f);
		modelMatrix = rend::translate(modelMatrix, position);
		modelMatrix = rend::rotate(modelMatrix, rend::radians(rotation.x), rend::vec3(1, 0, 0));
		modelMatrix = rend::rotate(modelMatrix, rend::radians(rotation.y), rend::vec3(0, 1, 0));
		modelMatrix = rend::rotate(modelMatrix, rend::radians(rotation.z), rend::vec3(0, 0, 1));
		modelMatrix = rend::scale(modelMatrix, scale);

		//std::cout << "getModelMatrix" << std::endl;
		//std::cout << glm::to_string(modelMatrix) << std::endl;

		return modelMatrix;
	}

	rend::vec3 Transform::getPosition()
	{
		return position;
	}

	void Transform::translate(float x, float y, float z)
	{
		rend::vec4 forward = getModelMatrix() * rend::vec4(x, y, z, 0.0f);
		position += rend::vec3(forward);
	}
	void Transform::rotate(float x, float y, float z)
	{
		rend::vec3 spin = rend::vec3(x, y, z);
		rotation += spin;
	}

	void Transform::setPosition(rend::vec3 _position)
	{
		this->position = _position;
	}
	void Transform::setRotation(rend::vec3 _rotation)
	{
		this->rotation = _rotation;
	}
	void Transform::setScale(rend::vec3 _scale)
	{
		scale = _scale;
	}
}
