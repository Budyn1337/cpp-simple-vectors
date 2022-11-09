/*
* @author: Michal Medynski
* @contact: mail: misiek1566@gmail.com
*/
#include "color.hpp"

Color::Color() 
	:r(0.0f), 
	g(0.0f), 
	b(0.0f), 
	a(1.0f) 
{}

Color::Color(float r, float g, float b, float a)
	:r(std::min(r, 1.0f)),
	g(std::min(g, 1.0f)),
	b(std::min(b, 1.0f)),
	a(std::min(a, 1.0f)) 
{}

Color::Color(HexColor hex)
{
	*this = HexToRgb(hex);
}

Color::Color(HexColor hex, float a)
{
	*this = HexToRgb(hex);

	this->a = a;
}

void Color::operator=(const Color& color)
{
	r = color.r;
	g = color.g;
	b = color.b;
	a = color.a;
}

void Color::operator=(HexColor hex)
{
	*this = HexToRgb(hex);
}

Color::operator Vector4<float>() const
{
	return Vector4<float>(r, g, b, a);
}

bool Color::operator==(const Color& color) const
{
	return r == color.r && g == color.g && b == color.b && a == color.a;
}

bool Color::operator!=(const Color& color) const
{
	return !(*this == color);
}

unsigned long Color::GetHexColor() const
{
	unsigned long ret = 0;

	ret |= (static_cast<unsigned long>(r * 255ul)) << 16ul;
	ret |= (static_cast<unsigned long>(g * 255ul)) << 8ul;
	ret |= (static_cast<unsigned long>(b * 255ul));

	return ret;
}

Color Color::HexToRgb(HexColor hex)
{
	hex = std::min(hex, static_cast<HexColor>(0xFFFFFF));

	return Color(
		static_cast<float>(((hex >> 16ul) & 0xFF) / 255.0f),
		static_cast<float>(((hex >> 8ul) & 0xFF) / 255.0f),
		static_cast<float>((hex & 0xFF) / 255.0f),
		1.0f
	);
}
