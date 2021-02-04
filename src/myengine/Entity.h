#pragma once
#include <vector>
#include <memory>
#include "Component.h"
#include "Exception.h"

namespace myengine
{

	struct Component;
	struct Core;
	struct Exception;
	struct Transform;

	/********************************************//**
	* \brief Creates game objects.
	***********************************************/
	struct Entity
	{
		friend struct ::myengine::Core;

		/********************************************//**
		* \brief Template function, adds components to entities.
		***********************************************/
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->entity = self;
			rtn->broken = false;
			components.push_back(rtn);

			rtn->onInitialize();   //Calls function based on template generation

			return rtn;
		}

		/********************************************//**
		* \brief Returns pointer a component of a specific type.
		***********************************************/
		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (size_t i = 0; i < components.size(); i++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(components.at(i));

				if (!rtn) continue;

				return rtn;
			}

			throw Exception("Entity does not contain requested type");
		}
		/********************************************//**
		* \brief Iterates through all components, calling tick on them.
		***********************************************/
		void tick();
		/********************************************//**
		* \brief Iterates through all components, calling any renderer components.
		***********************************************/
		void render();

		/********************************************//**
		* \brief Iterates through all components, removing each one. 
		***********************************************/
		void clearComponents();

		/********************************************//**
		* \brief Shortcut. Returns pointer to the transform component.
		***********************************************/
		std::shared_ptr<Transform> getTransform();
		/********************************************//**
		* \brief Shortcut. Returns pointer to core.
		***********************************************/
		std::shared_ptr<Core> getCore();
		
	private:
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;
		bool broken;
	};
}