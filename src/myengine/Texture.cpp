#include "Texture.h"
#include <rend/rend.h>
#include "ResourceList.h"
#include "Core.h"

#include <string>
#include <fstream>
#include <iostream>

namespace myengine
{

	void Texture::onLoad()
	{

		//std::ifstream file(getPath() + ".png");

		//std::cout << getPath() + ".png";
		//std::cout << std::endl;

		//bool eof = false;
		//if (!file.is_open())
		//{
		//	eof = true;
		//	std::cout << "Texture did not load.";
		//}

		//std::string line;
		//std::string data;

		//while (!file.eof())
		//{
		//	getline(file, line);
		//	data += line + "\n";
		//}

		//std::cout << data;

		//mesh->parse(data);
	}


}