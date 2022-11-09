/*
* @author: Michal Medynski
* @contact: mail: misiek1566@gmail.com
*/
#ifndef COLOR_HPP
#define COLOR_HPP

#include "vector4.hpp"

#include <algorithm>
#include <type_traits>

using HexColor = unsigned long;

struct Color
{
	float r;
	float g;
	float b;
	float a;

	Color();

	template<typename T> Color(T r, T g, T b, T a); //constructor for integral types

	Color(float r, float g, float b, float a = 1.0f);

	Color(HexColor hex);
	Color(HexColor hex, float a);

	Color(const Color&) = default;

	void operator=(const Color&);
	void operator=(HexColor hex);

	bool operator==(const Color& color) const;
	bool operator!=(const Color& color) const;

	operator Vector4<float>() const;

	HexColor GetHexColor() const;

	static Color HexToRgb(HexColor hex);
};

template<typename T>
inline Color::Color(T r, T g, T b, T a)
{
	static_assert(
		std::is_floating_point_v<T> || std::is_integral_v<T>, 
		"Color value must be floating point or integral"
	);

	if (std::is_floating_point_v<T>)
	{
		this->r = static_cast<float>(r);
		this->g = static_cast<float>(g);
		this->b = static_cast<float>(b);
		this->a = static_cast<float>(a);
	}
	else
	{
		this->r = static_cast<float>(std::min<T>(std::max<T>(r, 0), 255) / 255.0f);
		this->g = static_cast<float>(std::min<T>(std::max<T>(g, 0), 255) / 255.0f);
		this->b = static_cast<float>(std::min<T>(std::max<T>(b, 0), 255) / 255.0f);
		this->a = static_cast<float>(std::min<T>(std::max<T>(a, 0), 255) / 255.0f);
	}
}

#endif

