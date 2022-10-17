/*
* @author: Micha³ Medyñski
* @contact: discord: budyn#2962, mail: misiek1566@gmail.com
*/
#include "vector.hpp"

#include <type_traits>

template<typename T>
struct Vector<T, 4>
{
	//vector type must be arythmethic
	static_assert(std::is_arithmetic_v<T>, "Vector type must be arytmethic.");

	//helper for methods
	using Vec4 = Vector<T, 4>;

	//<values>

	T x;
	T y;
	T z;
	T w;

	//</values>

	//<constructors>

	Vector() :x(0), y(0), z(0), w(0) {};

	Vector(T x, T y, T z, T w) :x(x), y(y), z(z), w(w) {};

	Vector(const Vec4& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
	}

	//</constructors>

	//<methods>

	void Scale(double factor)
	{
		this->x *= factor;
		this->y *= factor;
		this->z *= factor;
		this->w *= factor;
	}

	//</methods>

	//<operators>
	//<arythmetic>
	//<other vector>

	Vec4 operator+(const Vec4& v) const
	{
		return Vec4(this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w);
	}

	Vec4 operator-(const Vec4& v) const
	{
		return Vec4(this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w);
	}

	Vec4 operator*(const Vec4& v) const
	{
		return Vec4(this->x * v.x, this->y * v.y, this->z * v.z, this->w * v.w);
	}

	Vec4 operator/(const Vec4& v) const
	{
		return Vec4(this->x / v.x, this->y / v.y, this->z / v.z, this->w / v.w);
	}

	Vec4 operator%(const Vec4& v) const
	{
		return Vec4(this->x % v.x, this->y % v.y, this->z % v.z, this->w % v.w);
	}

	//</other vector>
	//<single value>

	Vec4 operator+(const T& v) const
	{
		return Vec4(this->x + v, this->y + v, this->z + v, this->w + v);
	}

	Vec4 operator-(const T& v) const
	{
		return Vec4(this->x - v, this->y - v, this->z - v, this->w - v);
	}

	Vec4 operator*(const T& v) const
	{
		return Vec4(this->x * v, this->y * v, this->z * v, this->w * v);
	}

	Vec4 operator/(const T& v) const
	{
		return Vec4(this->x / v, this->y / v, this->z / v, this->w / v);
	}

	Vec4 operator%(const T& v) const
	{
		return Vec4(this->x % v, this->y % v, this->z % v, this->w % v);
	}

	//</single value>
	//</arythmetic>

	//<assignment>
	//<other vector>
	void operator=(const Vec4& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
	}

	void operator+=(const Vec4& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
		this->w += v.w;
	}

	void operator-=(const Vec4& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
		this->w -= v.w;
	}

	void operator*=(const Vec4& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;
		this->w *= v.w;
	}

	void operator/=(const Vec4& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;
		this->w /= v.w;
	}

	void operator%=(const Vec4& v)
	{
		this->x %= v.x;
		this->y %= v.y;
		this->z %= v.z;
		this->w %= v.w;
	}

	//</other vector>
	//<single value>

	void operator=(const T& v)
	{
		this->x = v;
		this->y = v;
		this->z = v;
		this->w = v;
	}

	void operator+=(const T& v)
	{
		this->x += v;
		this->y += v;
		this->z += v;
		this->w += v;
	}

	void operator-=(const T& v)
	{
		this->x -= v;
		this->y -= v;
		this->z -= v;
		this->w -= v;
	}

	void operator*=(const T& v)
	{
		this->x *= v;
		this->y *= v;
		this->z *= v;
		this->w *= v;
	}

	void operator/=(const T& v)
	{
		this->x /= v;
		this->y /= v;
		this->z /= v;
		this->w /= v;
	}

	void operator%=(const T& v)
	{
		this->x %= v;
		this->y %= v;
		this->z %= v;
		this->w %= v;
	}

	//<single value>
	//</assignment>
	//<logic>
	//<other vector>

	bool operator==(const Vec4& v) const
	{
		return this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w;
	}

	bool operator!=(const Vec4& v) const
	{
		return this->x != v.x && this->y != v.y && this->z != v.z && this->w != v.w;
	}

	bool operator<(const Vec4& v) const
	{
		return this->x < v.x&& this->y < v.y&& this->z < v.z && this->w < v.w;
	}

	bool operator>(const Vec4& v) const
	{
		return this->x > v.x && this->y > v.y && this->z > v.z && this->w > v.w;
	}

	bool operator<=(const Vec4& v) const
	{
		return this->x <= v.x && this->y <= v.y && this->z <= v.z && this->w <= v.w;
	}

	bool operator>=(const Vec4& v) const
	{
		return this->x >= v.x && this->y >= v.y && this->z >= v.z && this->w >= v.w;
	}

	//</other vector>
	//<single value>

	bool operator==(const T& v) const
	{
		return this->x == v && this->y == v && this->z == v && this->w == v;
	}

	bool operator!=(const T& v) const
	{
		return this->x != v && this->y != v && this->z != v && this->w != v;
	}

	bool operator<(const T& v) const
	{
		return this->x < v&& this->y < v&& this->z < v && this->w < v;
	}

	bool operator>(const T& v) const
	{
		return this->x > v && this->y > v && this->z > v && this->w > v;
	}

	bool operator<=(const T& v) const
	{
		return this->x <= v && this->y <= v && this->z <= v && this->w <= v;
	}

	bool operator>=(const T& v) const
	{
		return this->x >= v && this->y >= v && this->z >= v && this->w >= v;
	}

	//</single value>
	//</logic>
	//</operators>
};
