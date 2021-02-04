#pragma once

#include <vector>
#include <SDL2/SDL.h>

namespace myengine
{
	struct Core;

	/********************************************//**
	* \brief Stores and processes inputs (key presses).
	***********************************************/
	struct Input
	{
		/********************************************//**
		* \brief Returns true if a specified key has been pressed this frame.
		***********************************************/
		bool getKey(int key);
		/********************************************//**
		* \brief Returns true if a specified key is down this frame.
		***********************************************/
		bool keyDown(int key);
		/********************************************//**
		* \brief Returns true if a specified key is up this frame.
		***********************************************/
		bool keyUp(int key);

		//bool getMouse(int mouse);

	private:
			friend struct myengine::Core;
		std::vector<int>keys;
		std::vector<int>downKeys;
		std::vector<int>upKeys;

		//std::vector<int>mouseClick;
		//std::vector<int>mouseUp;
		//std::vector<int>mouseDown;

		void addKey(SDL_Keycode key);
		void eraseKey(SDL_Keycode key);
		void clearKeyBuffer();		
	};
}