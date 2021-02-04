#ifndef MYENGINE_COMPONENT_H
#define MYENGINE_COMPONENT_H

#include <memory>

namespace myengine
{

	struct Entity;
	struct Core;
	struct Transform;

	/********************************************//**
	* \brief 
	***********************************************/
	struct Component
	{
		friend struct myengine::Entity; //Share private with entity
		/********************************************//**
		* \brief Called on component creation. Overwritten by component types.
		***********************************************/
		virtual void onInitialize();

		/********************************************//**
		* \brief Called each tick, calls onTick.
		***********************************************/
		void tick();
		/********************************************//**
		* \brief Function overwritten by component types.
		***********************************************/
		virtual void onTick();

		/********************************************//**
		* \brief Called each tick, calls onRender.
		***********************************************/
		void render();
		/********************************************//**
		* \brief Function overwritten by Renderer class.
		***********************************************/
		virtual void onRender(); 

		/********************************************//**
		* \brief Flags component to be removed next tick.
		***********************************************/
		void kill();

		/********************************************//**
		* \brief Returns pointer to parent entity.
		***********************************************/
		std::shared_ptr<Entity> getEntity();
		/********************************************//**
		* \brief Returns pointer to the Core.
		***********************************************/
		std::shared_ptr<Core> getCore();
		/********************************************//**
		* \brief Shortcut. Returns pointer to parent entity's transform component.
		***********************************************/
		std::shared_ptr<Transform> getTransform();

	private:
		std::weak_ptr<Entity> entity; //Pointer to the entity this component belongs to
		bool broken;
	};
}

#endif