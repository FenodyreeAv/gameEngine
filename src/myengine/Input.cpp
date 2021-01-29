#include "Input.h"

namespace myengine
{
	bool Input::getKey(int key)
	{
		for (size_t k = 0; k < keys.size(); k++)
		{
			if (keys.at(k) == key)
			{
				return true;
			}
		}
		return false;
	}

	bool Input::keyDown(int key)
	{
		for (size_t kd = 0; kd < downKeys.size(); kd++)
		{
			if (downKeys.at(kd) == key)
			{
				return true;
			}
		}
		return false;
	}

	bool Input::keyUp(int key)
	{
		for (size_t ku = 0; ku < upKeys.size(); ku++)
		{
			if (upKeys.at(ku) == key)
			{
				return true;
			}
		}
		return false;
	}

	void Input::clearKeyBuffer()
	{
		upKeys.clear();
		downKeys.clear();
	}

	void Input::addKey(SDL_Keycode key)
	{
		keys.push_back(key);
		downKeys.push_back(key);
	}
	void Input::eraseKey(SDL_Keycode key)
	{
		for (std::vector<int>::iterator it = keys.begin(); it != keys.end();)
		{
			upKeys.push_back(key);
			if (*it == key)
			{
				it = keys.erase(it);
			}
			else it++;
		}
	}


}