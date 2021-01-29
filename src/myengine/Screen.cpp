#include "Screen.h"
#include <rend/rend.h>
#include <iostream>
#include <glm/gtx/string_cast.hpp>

namespace myengine 
{
	void Screen::getWindowSize(SDL_Window *window)
	{
		SDL_GetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);
	}

	rend::mat4 Screen::getPerspective(float _angle, float _nearPlane, float _farPlane)
	{
		rend::mat4 projectionMatrix = rend::perspective(glm::radians(_angle), float(width) / float(height), _nearPlane, _farPlane);

		std::cout << "projectionMatrix / getPerspective" << std::endl;
		std::cout << glm::to_string(projectionMatrix) << std::endl;

		return projectionMatrix;
	}

	//rend::mat4 Screen::getOrthographic(float _angle, float _nearPlane, float _farPlane)
	//{
	//	rend::mat4 projectionMatrix = rend::ortho(glm::radians(_angle), float(width) / float(height), _nearPlane, _farPlane);
	//	return projectionMatrix;
	//}
}
