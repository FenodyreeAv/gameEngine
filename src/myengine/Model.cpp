#include "Model.h"
#include <rend/rend.h>
#include "ResourceList.h"
#include "Core.h"
#include "Model.h"

#include <string>
#include <fstream>
#include <iostream>

namespace myengine
{

	void Model::onLoad()
	{
		mesh = getCore()->context->createMesh();
		std::ifstream file(getPath() + ".obj");

		bool eof = false;
		if (!file.is_open())
		{
			eof = true;
			std::cout << "Mesh did not load.";
		}

		std::string line;
		std::string data;

		while (!file.eof())
		{
			getline(file, line);
			data += line + "\n";
		}

		std::cout << data;

		mesh->parse(data);
	}


}