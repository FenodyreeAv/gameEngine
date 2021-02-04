#pragma once
#include <glm/glm.hpp>
#include <SDL2/SDL.h>

namespace myengine
{
	/********************************************//**
	* \brief Manages screen data.
	***********************************************/
	struct Screen
	{
		/********************************************//**
		* \brief Returns size of the window.
		***********************************************/
		void getWindowSize(SDL_Window* window);
		/********************************************//**
		* \brief Returns the perception matrix.
		***********************************************/
		glm::mat4 getPerspective(float _angle, float _nearPlane, float _farPlane);
		//glm::mat4 getOrthographic(float _angle, float _nearPlane, float _farPlane);
		/********************************************//**
		* \brief Returns screen width.
		***********************************************/
		int getWidth() { return width; }
		/********************************************//**
		* \brief Returns the screen height.
		***********************************************/
		int getHeight() { return height; }

	private:
		int width;
		int height;
	};


}
