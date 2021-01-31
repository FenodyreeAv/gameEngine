#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Transform.h"
#include "Screen.h"
#include "ResourceList.h"
#include "Input.h"
#include <iostream>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

namespace myengine
{

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;

		rtn->window = SDL_CreateWindow("myengine", //Accesses window pointer within the created object
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

		if (!rtn->window)
		{
			throw Exception("Failed to generate window");
		}

		rtn->glContext = SDL_GL_CreateContext(rtn->window);

		if (!rtn->glContext)
		{
			throw Exception("Failed to generate openGL context");
		}

		rtn->screen = std::make_shared<Screen>();
		rtn->screen->getWindowSize(rtn->window);
		
		rtn->context = rend::Context::initialize();
		
		rtn->resourceList = std::make_shared<ResourceList>();
		rtn->resourceList->core = rtn;

		rtn->input = std::make_shared<Input>();

		return rtn;
	}

	std::shared_ptr<Screen> Core::getScreen()
	{
		std::weak_ptr<Screen> rtn = screen;
		return rtn.lock();
	}

	std::shared_ptr<Input> Core::getInput()
	{
		std::weak_ptr<Input> rtn = input;
		return rtn.lock();
	}

	std::shared_ptr<Camera> Core::getCamera()
	{
		return currentCamera.lock();
	}

	std::shared_ptr<ResourceList> Core::getResourceList()
	{
		return resourceList;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->core = self;
		rtn->self = rtn;
		rtn->addComponent<Transform>();
		rtn->broken = false; //If set to true, entity is deleted at the start of the next loop
	 	entities.push_back(rtn);

		return rtn;
	}

	float frameStart = SDL_GetTicks();
	float idealTime = 1.0f/60.0f;
	float deltaTime = 0;
	float frameTime = 0;

	void Core::run()
	{
		bool gameRunning = true;
		
		
		SDL_Event e = {0};

		while (gameRunning)
		{
			while(SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
					gameRunning = false;
				}
				else if (e.type == SDL_KEYDOWN)
				{
					input->addKey(e.key.keysym.sym);
				}
				else if (e.type == SDL_KEYUP)
				{
					input->eraseKey(e.key.keysym.sym);
				}
			}

			for (size_t i = 0; i < entities.size(); i++)
			{
				if (entities.at(i)->broken == true)
				{
					entities.at(i)->clearComponents();
					entities.erase(entities.begin() + i);
					i--;
				}
			}

			for (size_t ei = 0; ei < entities.size(); ei++) //Iterates through entities list
			{
				//std::cout << "Entities Index: ";
				//std::cout << ei << std::endl;
				entities.at(ei)->tick();
			}

			screen->getWindowSize(window);

			glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (size_t ci = 0; ci < cameras.size(); ci++)
			{
				currentCamera = cameras.at(ci);
				glClear(GL_DEPTH_BUFFER_BIT);
				for (size_t ei = 0; ei < entities.size(); ei++)
				{
					entities.at(ei)->render();
				}
			}
			
			SDL_GL_SwapWindow(window);

			float time = SDL_GetTicks();
			frameTime = time - frameStart;
			deltaTime = frameTime / 1000.0f;
			if (idealTime > deltaTime)
			{
				SDL_Delay(((idealTime - deltaTime) * 1000.0f));
			}

			input->clearKeyBuffer();
			frameStart = time;
			std::cout << deltaTime;
		}
	}
}