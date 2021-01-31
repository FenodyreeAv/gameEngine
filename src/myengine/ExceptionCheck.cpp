#pragma once
#include "ExceptionCheck.h"
#include "Exception.h"
#include <iostream>

namespace myengine
{

		void ExceptionCheck::onInitialize()
		{
			std::cout << "Debug: Deliberately added broken component." << std::endl;
		}

		void ExceptionCheck::onTick()
		{
			throw Exception("I am a debug exception!");
		}
		//void ExceptionCheck::onTick()
		//{
		//	
		//}
		//void onDestroy();

		void ExceptionCheck::throwError()
		{
			throw Exception("I am a debug exception!");
		}

}