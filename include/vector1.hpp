/*
* @author: Micha³ Medyñski
* @contact: discord: budyn#2962, mail: misiek1566@gmail.com
*/
#include "vector.hpp"

#include <type_traits>

template<typename T>
struct Vector<T, 1>
{
	//vector type must be arythmethic
	static_assert(std::is_arithmetic_v<T>, "Vector type must be arytmethic.");

	//helper for methods
	using Vec1 = Vector<T, 1>;

	//<values>

	T x;

	//</values>

	//<constructors>

	Vector() :x(0) {};

	Vector(T x) :x(x) {};

	Vector(const Vec1& v)
	{
		this->x = v.x;
	}

	//</constructors>

	//<methods>

	void Scale(double factor)
	{
		this->x *= factor;
	}

	//</methods>

	//<operators>
	//<arythmetic>
	//<other vector>

	Vec1 operator+(const Vec1& v) const
	{
		return Vec1(this->x + v.x);
	}

	Vec1 operator-(const Vec1& v) const
	{
		return Vec1(this->x - v.x);
	}

	Vec1 operator*(const Vec1& v) const
	{
		return Vec1(this->x * v.x);
	}

	Vec1 operator/(const Vec1& v) const
	{
		return Vec1(this->x / v.x);
	}

	Vec1 operator%(const Vec1& v) const
	{
		return Vec1(this->x % v.x);
	}

	//</other vector>
	//<single value>

	Vec1 operator+(const T& v) const
	{
		return Vec1(this->x + v);
	}

	Vec1 operator-(const T& v) const
	{
		return Vec1(this->x - v);
	}

	Vec1 operator*(const T& v) const
	{
		return Vec1(this->x * v);
	}

	Vec1 operator/(const T& v) const
	{
		return Vec1(this->x / v);
	}

	Vec1 operator%(const T& v) const
	{
		return Vec1(this->x % v);
	}

	//</single value>
	//</arythmetic>

	//<assignment>
	//<other vector>
	void operator=(const Vec1& v)
	{
		this->x = v.x;
	}

	void operator+=(const Vec1& v)
	{
		this->x += v.x;
	}

	void operator-=(const Vec1& v)
	{
		this->x -= v.x;
	}

	void operator*=(const Vec1& v)
	{
		this->x *= v.x;
	}

	void operator/=(const Vec1& v)
	{
		this->x /= v.x;
	}

	void operator%=(const Vec1& v)
	{
		this->x %= v.x;
	}

	//</other vector>
	//<single value>

	void operator=(const T& v)
	{
		this->x = v;
	}

	void operator+=(const T& v)
	{
		this->x += v;
	}

	void operator-=(const T& v)
	{
		this->x -= v;
	}

	void operator*=(const T& v)
	{
		this->x *= v;
	}

	void operator/=(const T& v)
	{
		this->x /= v;
	}

	void operator%=(const T& v)
	{
		this->x %= v;
	}

	//<single value>
	//</assignment>
	//<logic>
	//<other vector>

	bool operator==(const Vec1& v) const
	{
		return this->x == v.x;
	}

	bool operator!=(const Vec1& v) const
	{
		return this->x != v.x;
	}

	bool operator<(const Vec1& v) const
	{
		return this->x < v.x;
	}

	bool operator>(const Vec1& v) const
	{
		return this->x > v.x;
	}

	bool operator<=(const Vec1& v) const
	{
		return this->x <= v.x;
	}

	bool operator>=(const Vec1& v) const
	{
		return this->x >= v.x;
	}

	//</other vector>
	//<single value>

	bool operator==(const T& v) const
	{
		return this->x == v;
	}

	bool operator!=(const T& v) const
	{
		return this->x != v;
	}

	bool operator<(const T& v) const
	{
		return this->x < v;
	}

	bool operator>(const T& v) const
	{
		return this->x > v;
	}

	bool operator<=(const T& v) const
	{
		return this->x <= v;
	}

	bool operator>=(const T& v) const
	{
		return this->x >= v;
	}

	//</single value>
	//</logic>
	//</operators>
};
