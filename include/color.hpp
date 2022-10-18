/*
* @author: Micha³ Medyñski
* @contact: discord: budyn#2962, mail: misiek1566@gmail.com
*/
#include <algorithm>

struct Color
{
	//<values>
	
	float r;
	float g;
	float b;
	float a;

	//</values>

	//<constructors>
	
	Color() :r(0.0f), g(0.0f), b(0.0f), a(1.0f) {};

	Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a = 255u)
		:r((float)std::min(r, 255u) / 255.0f),
		g((float)std::min(g, 255u) / 255.0f),
		b((float)std::min(b, 255u) / 255.0f),
		a((float)std::min(a, 255u) / 255.0f) {};

	Color(float r, float g, float b, float a = 1.0f)
		:r(std::min(r, 1.0f)),
		g(std::min(g, 1.0f)),
		b(std::min(b, 1.0f)),
		a(std::min(a, 1.0f)) {};

	Color(unsigned long hexColor)
	{
		*this = HexToRgb(hexColor);
	}
	
	//</constructors>

	//<methods>
	
	static unsigned long GetHexColor(const Color& color)
	{
		unsigned long ret = 0;

		ret |= (static_cast<unsigned long>(color.r * 255ul)) << 16ul;
		ret |= (static_cast<unsigned long>(color.g * 255ul)) << 8ul;
		ret |= (static_cast<unsigned long>(color.b * 255ul));
	}

	static Color HexToRgb(unsigned long hex)
	{
		hex = std::min(hex, static_cast<unsigned long>(0xFFFFFF));

		return Color(
			static_cast<float>(((hex >> 16ul) & 0xFF) / 255.0f),
			static_cast<float>(((hex >> 8ul) & 0xFF) / 255.0f),
			static_cast<float>((hex & 0xFF) / 255.0f),
			1.0f
		);
	}

	//</methods>
};