/*
* @author: Micha³ Medyñski
* @contact: discord: budyn#2962, mail: misiek1566@gmail.com
*/
#include "vector.hpp"

#include <type_traits>

template<typename T>
struct Vector<T, 3>
{
	//vector type must be arythmethic
	static_assert(std::is_arithmetic_v<T>, "Vector type must be arytmethic.");

	//helper for methods
	using Vec3 = Vector<T, 3>;

	//<values>

	T x;
	T y;
	T z;

	//</values>

	//<constructors>

	Vector() :x(0), y(0), z(0) {};

	Vector(T x, T y, T z) :x(x), y(y), z(z) {};

	Vector(const Vec3& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}

	//</constructors>

	//<methods>

	void Scale(double factor)
	{
		this->x *= factor;
		this->y *= factor;
		this->z *= factor;
	}

	//</methods>

	//<operators>
	//<arythmetic>
	//<other vector>

	Vec3 operator+(const Vec3& v) const
	{
		return Vec3(this->x + v.x, this->y + v.y, this->z + v.z);
	}

	Vec3 operator-(const Vec3& v) const
	{
		return Vec3(this->x - v.x, this->y - v.y, this->z - v.z);
	}

	Vec3 operator*(const Vec3& v) const
	{
		return Vec3(this->x * v.x, this->y * v.y, this->z * v.z);
	}

	Vec3 operator/(const Vec3& v) const
	{
		return Vec3(this->x / v.x, this->y / v.y, this->z / v.z);
	}

	Vec3 operator%(const Vec3& v) const
	{
		return Vec3(this->x % v.x, this->y % v.y, this->z % v.z);
	}

	//</other vector>
	//<single value>

	Vec3 operator+(const T& v) const
	{
		return Vec3(this->x + v, this->y + v, this->z + v);
	}

	Vec3 operator-(const T& v) const
	{
		return Vec3(this->x - v, this->y - v, this->z - v);
	}

	Vec3 operator*(const T& v) const
	{
		return Vec3(this->x * v, this->y * v, this->z * v);
	}

	Vec3 operator/(const T& v) const
	{
		return Vec3(this->x / v, this->y / v, this->z / v);
	}

	Vec3 operator%(const T& v) const
	{
		return Vec3(this->x % v, this->y % v, this->z % v);
	}

	//</single value>
	//</arythmetic>

	//<assignment>
	//<other vector>
	void operator=(const Vec3& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
	}

	void operator+=(const Vec3& v)
	{
		this->x += v.x;
		this->y += v.y;
		this->z += v.z;
	}

	void operator-=(const Vec3& v)
	{
		this->x -= v.x;
		this->y -= v.y;
		this->z -= v.z;
	}

	void operator*=(const Vec3& v)
	{
		this->x *= v.x;
		this->y *= v.y;
		this->z *= v.z;
	}

	void operator/=(const Vec3& v)
	{
		this->x /= v.x;
		this->y /= v.y;
		this->z /= v.z;
	}

	void operator%=(const Vec3& v)
	{
		this->x %= v.x;
		this->y %= v.y;
		this->z %= v.z;
	}

	//</other vector>
	//<single value>

	void operator=(const T& v)
	{
		this->x = v;
		this->y = v;
		this->z = v;
	}

	void operator+=(const T& v)
	{
		this->x += v;
		this->y += v;
		this->z += v;
	}

	void operator-=(const T& v)
	{
		this->x -= v;
		this->y -= v;
		this->z -= v;
	}

	void operator*=(const T& v)
	{
		this->x *= v;
		this->y *= v;
		this->z *= v;
	}

	void operator/=(const T& v)
	{
		this->x /= v;
		this->y /= v;
		this->z /= v;
	}

	void operator%=(const T& v)
	{
		this->x %= v;
		this->y %= v;
		this->z %= v;
	}

	//<single value>
	//</assignment>
	//<logic>
	//<other vector>

	bool operator==(const Vec3& v) const
	{
		return this->x == v.x && this->y == v.y && this->z == v.z;
	}

	bool operator!=(const Vec3& v) const
	{
		return this->x != v.x && this->y != v.y && this->z != v.z;
	}

	bool operator<(const Vec3& v) const
	{
		return this->x < v.x && this->y < v.y && this->z < v.z;
	}

	bool operator>(const Vec3& v) const
	{
		return this->x > v.x && this->y > v.y && this->z > v.z;
	}

	bool operator<=(const Vec3& v) const
	{
		return this->x <= v.x && this->y <= v.y && this->z <= v.z;
	}

	bool operator>=(const Vec3& v) const
	{
		return this->x >= v.x && this->y >= v.y && this->z >= v.z;
	}

	//</other vector>
	//<single value>

	bool operator==(const T& v) const
	{
		return this->x == v && this->y == v && this->z == v;
	}

	bool operator!=(const T& v) const
	{
		return this->x != v && this->y != v && this->z != v;
	}

	bool operator<(const T& v) const
	{
		return this->x < v&& this->y < v && this->z < v;
	}

	bool operator>(const T& v) const
	{
		return this->x > v && this->y > v && this->z > v;
	}

	bool operator<=(const T& v) const
	{
		return this->x <= v && this->y <= v && this->z <= v;
	}

	bool operator>=(const T& v) const
	{
		return this->x >= v && this->y >= v && this->z >= v;
	}

	//</single value>
	//</logic>
	//</operators>
};