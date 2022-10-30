/*
* @author: Michal Medynski
* @contact: mail: misiek1566@gmail.com
*/
#ifndef COLOR_HPP
#define COLOR_HPP

#include "vector4.hpp"

#include <algorithm>

struct Color
{
	float r;
	float g;
	float b;
	float a;

	Color();
	Color(float r, float g, float b, float a = 1.0f);
	Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a = 255u);

	Color(unsigned long hexColor);

	Color(const Color& copy);

	void operator=(const Color& color);
	void operator=(unsigned long hex);

	bool operator==(const Color& color) const;
	bool operator!=(const Color& color) const;

	operator Vector4<float>() const;

	unsigned long GetHexColor()  const;

	static Color HexToRgb(unsigned long hex);
};

#endif