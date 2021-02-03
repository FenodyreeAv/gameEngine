#pragma once
#include <memory>
#include <vector>
#include <rend/rend.h>
#include <SDL2/SDL.h>

namespace myengine
{
	struct Entity;
	struct Renderer;
	struct Screen;
	struct ResourceList;
	struct Model;
	struct Camera;
	struct Input;
	struct Collider;
	struct TextureLoad;
	
	struct Core
	{
		static std::shared_ptr<Core> initialize();
		
		std::shared_ptr<Entity> addEntity();
		std::shared_ptr<Screen> getScreen();
		std::shared_ptr<Camera> getCamera();
		std::shared_ptr<Input> getInput();
		std::shared_ptr<ResourceList> getResourceList();
		std::shared_ptr<rend::Context> context; //Used to reuse shaders

		void run();
		
	private:
		friend struct myengine::Renderer;
		friend struct myengine::Model;
		friend struct myengine::Camera;
		friend struct myengine::Collider;
		//friend struct myengine::TextureLoad;
		

		std::vector<std::shared_ptr<Entity>> entities;
		std::weak_ptr<Core> self;

		SDL_Window* window;
		SDL_GLContext glContext; //Here to be deleted, to prevent memory leaks


		std::shared_ptr<Screen> screen;
		std::shared_ptr<Input> input;

		std::shared_ptr<ResourceList> resourceList; //list of loaded assets

		std::weak_ptr<Camera> currentCamera;
		std::vector<std::weak_ptr<Camera> > cameras;
		std::vector<std::weak_ptr<Collider> > colliders;
	};
}
