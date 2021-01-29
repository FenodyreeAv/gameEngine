#include "Renderer.h"
#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Transform.h"
#include "Camera.h"
#include "Model.h"
#include <string>
#include <iostream>
#include <fstream>

namespace myengine 
{
	void Renderer::onInitialize() //When component is added, the Renderer must initialize the shader and shape
	{//Not included in a constructer, because then it is not placed inside a shared pointer & no knowledge of parent's class

		//const char* src =
		//	"\n#ifdef VERTEX\n                       " \
		//	"attribute vec2 a_Position;              " \
		//	"                                        " \
		//	"void main()                             " \
		//	"{                                       " \
		//	"  gl_Position = vec4(a_Position, 0, 1); " \
		//	"}                                       " \
		//	"                                        " \
		//	"\n#endif\n                              " \
		//	"\n#ifdef FRAGMENT\n                     " \
		//	"                                        " \
		//	"void main()                             " \
		//	"{                                       " \
		//	"  gl_FragColor = vec4(1, 0, 0, 1);		 " \
		//	"}                                       " \
		//	"                                        " \
		//	"\n#endif\n                              ";

		const char* src =
			"\n#ifdef VERTEX\n                       " \
			"attribute vec3 a_Position;              " \
			"attribute vec2 a_TexCoord;              " \
			"attribute vec3 a_Normal;                " \
			"uniform mat4 u_Projection;              " \
			"uniform mat4 u_View;                    " \
			"uniform mat4 u_Model;                   " \
			"varying vec2 v_TexCoord;                " \
			"                                        " \
			"void main()                             " \
			"{                                       " \
			"  gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1); " \
			"  v_TexCoord = a_TexCoord;              " \
			"  if(a_Normal.x == 9) gl_Position.x = 7;" \
			"}                                       " \
			"                                        " \
			"\n#endif\n                              " \
			"\n#ifdef FRAGMENT\n                     " \
			"uniform sampler2D u_Texture;            " \
			"varying vec2 v_TexCoord;                " \
			"                                        " \
			"void main()                             " \
			"{                                       " \
			"  gl_FragColor = vec4(v_TexCoord, 0, 1);" \
			"}                                       " \
			"                                        " \
			"\n#endif\n                              ";



		shader = getCore()->context->createShader();
		shader->parse(src);

		//shape = getCore()->context->createBuffer();
		//shape->add(rend::vec2(0, 0.5f));
		//shape->add(rend::vec2(-0.5, -0.5f));
		//shape->add(rend::vec2(0.5f, -0.5f)); 

		//shader = getCore()->context->createShader();
		//shader->parse(src);

		//shape = getCore()->context->createMesh();

		//std::ifstream file("cube.obj");

		//if (!file.is_open())
		//{
		//	throw Exception("Failed to open model file");
		//}

		//std::string content;
		//std::string line;

		//while (!file.eof())
		//{
		//	getline(file, line);
		//	content += line + "\n";
		//	std::cout << line << "\n";
		//}

		//shape->parse(content);



		//shape->getComponent<Transform>();

	}
	//rend::mat4 Renderer::getProjectionMatrix()
	//{
	//	return getEntity()->getCore()->getScreen()->getPerspective(45.0f, 0.1f, 100.0f);
	//}
	//rend::mat4 Renderer::getModelMatrix()
	//{
	//	modelMatrix->getComponent<Transform>();
	//	return;
	//}
	   
	void Renderer::onRender()
	{
		//shader->setMesh(shape);

		shader->setMesh(model->mesh);

		shader->setUniform("u_Projection", rend::perspective(rend::radians(45.0f),
			1.0f, 0.1f, 100.0f));
			   		 
		shader->setUniform("u_View", 
			getCore()->
			getCamera()->
			getView());
		shader->setUniform("u_Model", getEntity()->getTransform()->getModelMatrix());

		std::shared_ptr<Camera> c = getCore()->getCamera();

		if (c->getRenderTexture())
		{
			shader->render(c->getRenderTexture());
		}
		else
		{
			shader->render();
		}
	} 

	void Renderer::setModel(std::shared_ptr<Model> model)
	{
		this->model = model;
	}
}