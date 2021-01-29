#pragma once
#include <glm/glm.hpp>
#include <SDL2/SDL.h>

namespace myengine
{
	struct Screen
	{
		void getWindowSize(SDL_Window* window);
		glm::mat4 getPerspective(float _angle, float _nearPlane, float _farPlane);
		//glm::mat4 getOrthographic(float _angle, float _nearPlane, float _farPlane);
		int getWidth() { return width; }
		int getHeight() { return height; }

	private:
		int width;
		int height;
	};


}
