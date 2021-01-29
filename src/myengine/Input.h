#pragma once

#include <vector>
#include <SDL2/SDL.h>

namespace myengine
{
	struct Core;

	struct Input
	{
		bool getKey(int key);
		bool keyDown(int key);
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