#include "TextureLoad.h"
#include <rend/rend.h>
#include "ResourceList.h"
#include "Core.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <string>
#include <fstream>
#include <iostream>

//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"

namespace myengine
{
	void TextureLoad::onLoad()
	{
		//std::ifstream file(getPath() + ".png");

		//std::cout << getPath() + ".png";
		//std::cout << std::endl;


		//if (!file.is_open())
		//{
		//	std::cout << "Texture did not load.";
		//}

		int w = 0;
		int h = 0;
		int bpp = 0;

		tex = getCore()->context->createTexture();

		unsigned char *data = stbi_load((getPath() + ".png").c_str(), &w, &h, &bpp, 3);

		if (!data)
		{
			throw Exception("Failed to open image");
		}

		tex->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int r = y * w * 3 + x * 3;

				tex->setPixel(x, y, rend::vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
			}
		}
		stbi_image_free(data);
	}


}
