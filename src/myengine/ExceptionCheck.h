#pragma once
#include "Component.h"
#include "Exception.h"

namespace myengine
{
	/********************************************//**
	* \brief Tests the error handling by adding faulty components.
	***********************************************/
	struct ExceptionCheck: public Component
	{
		/********************************************//**
		* \brief Prints to console that a debug error has been caused.
		***********************************************/
		void onInitialize();
		//void onDestroy();

		/********************************************//**
		* \brief Throws an error.
		***********************************************/
		void throwError();
		/********************************************//**
		* \brief Throws an error each tick.
		***********************************************/
		void onTick();

	private:

	};

}