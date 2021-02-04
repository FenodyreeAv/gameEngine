#pragma once
#include <string>
#include <memory>

namespace myengine
{
	struct Core;
	struct ResourceList;

	/********************************************//**
	* \brief Loads data from files.
	***********************************************/
	struct Resource
	{
		/********************************************//**
		* \brief Calls onLoad function.
		***********************************************/
		void load();
		/********************************************//**
		* \brief Function overwritten with individual resource loading functions.
		***********************************************/
		virtual void onLoad() {};
		/********************************************//**
		* \brief Returns path variable.
		***********************************************/
		std::string getPath();
		/********************************************//**
		* \brief Returns pointer to the Core.
		***********************************************/
		std::shared_ptr<Core> getCore();
	private:
		friend struct myengine::ResourceList;

		std::string path;
		std::weak_ptr<ResourceList> resourceList;
		std::weak_ptr<Core> core;
	};
}


