/*
* @author: Michal Medynski
* @contact: mail: misiek1566@gmail.com
*/
#include "vector.hpp"

#include <type_traits>

template<typename T>
struct Vector<T, 2>
{
	//vector type must be arythmethic
	static_assert(std::is_arithmetic_v<T>, "Vector type must be arytmethic.");

	//helper for methods
	using Vec2 = Vector<T, 2>;

	//<values>

	T x;
	T y;

	//</values>

	//<constructors>

	Vector() :x(0), y(0) {};

	Vector(T x, T y) :x(x), y(y) {};

	Vector(const Vec2& v)
	{
		this->x = v.x;
		this->y = v.y;
	}

	//</constructors>

	//<methods>
	
	void Scale(double factor)
	{
		this->x *= factor;
		this->y *= factor;
	}

	//</methods>
	
	//<operators>
	//<arythmetic>
	//<other vector>
	
	Vec2 operator+(const Vec2& v) const
	{
		return Vec2(this->x + v.x, this->y + v.y);
	}

	Vec2 operator-(const Vec2& v) const
	{
		return Vec2(this->x - v.x, this->y - v.y);
	}

	Vec2 operator*(const Vec2& v) const
	{
		return Vec2(this->x * v.x, this->y * v.y);
	}

	Vec2 operator/(const Vec2& v) const
	{
		return Vec2(this->x / v.x, this->y / v.y);
	}

	Vec2 operator%(const Vec2& v) const
	{
		return Vec2(this->x % v.x, this->y % v.y);
	}

	//</other vector>
	//<single value>

	Vec2 operator+(const T& v) const
	{
		return Vec2(this->x + v, this->y + v);
	}

	Vec2 operator-(const T& v) const
	{
		return Vec2(this->x - v, this->y - v);
	}

	Vec2 operator*(const T& v) const
	{
		return Vec2(this->x * v, this->y * v);
	}

	Vec2 operator/(const T& v) const
	{
		return Vec2(this->x / v, this->y / v);
	}

	Vec2 operator%(const T& v) const
	{
		return Vec2(this->x % v, this->y % v);
	}

	//</single value>
	//</arythmetic>
	
	//<assignment>
	//<other vector>
	void operator=(const Vec2& v)
	{
		this->x = v.x;
		this->y = v.y;
	}

	void operator+=(const Vec2& v)
	{
		this->x += v.x;
		this->y += v.y;
	}

	void operator-=(const Vec2& v)
	{
		this->x -= v.x;
		this->y -= v.y;
	}

	void operator*=(const Vec2& v)
	{
		this->x *= v.x;
		this->y *= v.y;
	}

	void operator/=(const Vec2& v)
	{
		this->x /= v.x;
		this->y /= v.y;
	}

	void operator%=(const Vec2& v)
	{
		this->x %= v.x;
		this->y %= v.y;
	}

	//</other vector>
	//<single value>

	void operator=(const T& v)
	{
		this->x = v;
		this->y = v;
	}

	void operator+=(const T& v)
	{
		this->x += v;
		this->y += v;
	}

	void operator-=(const T& v)
	{
		this->x -= v;
		this->y -= v;
	}

	void operator*=(const T& v)
	{
		this->x *= v;
		this->y *= v;
	}

	void operator/=(const T& v)
	{
		this->x /= v;
		this->y /= v;
	}

	void operator%=(const T& v)
	{
		this->x %= v;
		this->y %= v;
	}

	//<single value>
	//</assignment>
	//<logic>
	//<other vector>

	bool operator==(const Vec2& v) const
	{
		return this->x == v.x && this->y == v.y;
	}

	bool operator!=(const Vec2& v) const
	{
		return this->x != v.x && this->y != v.y;
	}

	bool operator<(const Vec2& v) const
	{
		return this->x < v.x && this->y < v.y;
	}

	bool operator>(const Vec2& v) const
	{
		return this->x > v.x && this->y > v.y;
	}

	bool operator<=(const Vec2& v) const
	{
		return this->x <= v.x && this->y <= v.y;
	}
	
	bool operator>=(const Vec2& v) const
	{
		return this->x >= v.x && this->y >= v.y;
	}

	//</other vector>
	//<single value>

	bool operator==(const T& v) const
	{
		return this->x == v && this->y == v;
	}

	bool operator!=(const T& v) const
	{
		return this->x != v && this->y != v;
	}

	bool operator<(const T& v) const
	{
		return this->x < v && this->y < v;
	}

	bool operator>(const T& v) const
	{
		return this->x > v && this->y > v;
	}

	bool operator<=(const T& v) const
	{
		return this->x <= v && this->y <= v;
	}

	bool operator>=(const T& v) const
	{
		return this->x >= v && this->y >= v;
	}

	//</single value>
	//</logic>
	//</operators>
};
