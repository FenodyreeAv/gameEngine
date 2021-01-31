#pragma once
#include "Component.h"
#include "Exception.h"

namespace myengine
{

	struct ExceptionCheck: public Component
	{
		void onInitialize();
		//void onDestroy();
		void throwError();

		void onTick();

	private:

	};

}