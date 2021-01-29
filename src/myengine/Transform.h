#pragma once
#include <rend/rend.h>
#include "Component.h"

namespace myengine
{
	struct Transform : public Component
	{
		void onInitialize();

		rend::mat4 getModelMatrix();

		void translate(float x, float y, float z);
		void rotate(float x, float y, float z);

		void setPosition(rend::vec3 _position);
		void setRotation(rend::vec3 _rotation);
		void setScale(rend::vec3 _scale);

		rend::vec3 getPosition();

	private:
			rend::vec3 rotation;
			rend::vec3 position;
			rend::vec3 scale;
	};
}

//#include "Component.h"
//
//#include <rend/rend.h>
//
//namespace myengine
//{
//
//	struct Transform : public Component
//	{
//		void onInitialize();
//
//		rend::mat4 getModel();
//		void setPosition(rend::vec3 position);
//		void translate(rend::vec3 translation);
//		void translate(float x, float y, float z);
//		void rotate(float x, float y, float z);
//
//	private:
//		rend::vec3 position;
//		rend::vec3 rotation;
//		rend::vec3 scale;
//
//	};
//
//}

