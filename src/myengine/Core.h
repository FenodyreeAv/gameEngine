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
	
	/********************************************//**
	* \brief Engine's main class, contains all core functionality.
	***********************************************/
	struct Core
	{
		/********************************************//**
		* \brief Initializes program, creates a pointer to the core.
		***********************************************/
		static std::shared_ptr<Core> initialize();
		
		/********************************************//**
		* \brief Creates an entity, adds it to the list of entities.
		***********************************************/
		std::shared_ptr<Entity> addEntity();

		/********************************************//**
		* \brief Returns a pointer to the screen.
		***********************************************/
		std::shared_ptr<Screen> getScreen();
		/********************************************//**
		* \brief Returns a pointer to the current camera.
		***********************************************/
		std::shared_ptr<Camera> getCamera();
		/********************************************//**
		* \brief Returns a pointer to the input.
		***********************************************/
		std::shared_ptr<Input> getInput();
		/********************************************//**
		* \brief Returns pointer to the resource manager.
		***********************************************/
		std::shared_ptr<ResourceList> getResourceList();
		/********************************************//**
		* \brief Returns a pointer to the rendering context.
		***********************************************/
		std::shared_ptr<rend::Context> context; //Used to reuse shaders

		/********************************************//**
		* \brief Begins the main loop.
		***********************************************/
		void run();
		
	private:
		friend struct myengine::Renderer;
		friend struct myengine::Model;
		friend struct myengine::Camera;
		friend struct myengine::Collider;

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
