/*
* @author: Michal Medynski
* @contact: mail: misiek1566@gmail.com
*/
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <type_traits>
#include <math.h>
#include <cassert>

template<typename T>
struct Vector2
{
	//vector type must be arythmethic
	static_assert(std::is_arithmetic_v<T>, "Vector type must be arytmethic.");

	T x;
	T y;

	Vector2() :x(0), y(0) {};
	Vector2(T x, T y) :x(x), y(y) {};
	Vector2(T value) :x(value), y(value) {};
	Vector2(const Vector2<T>& copy) :x(copy.x), y(copy.y) {};

	template<typename T2> 
	Vector2(const Vector2<T2>& copy) :x(static_cast<T>(copy.x)), y(static_cast<T>(copy.y)) {};

	template<typename T2>
	operator Vector2<T2>() const { return Vector2<T2>(static_cast<T2>(x), static_cast<T2>(y)); };

	Vector2<T> normalized() const;
	Vector2<T> opposite() const;
	Vector2<T> cross(const Vector2<T>& vec) const;
	Vector2<T> scale_up(const Vector2<T>& vec) const;
	Vector2<T> scale_down(const Vector2<T>& vec) const;

	T length() const;
	T dot(const Vector2<T>& vec) const;
	float angle() const;

	Vector2<T> operator+(const Vector2<T>& vec) const;
	Vector2<T> operator-(const Vector2<T>& vec) const;
	Vector2<T> operator*(const Vector2<T>& vec) const;
	Vector2<T> operator/(const Vector2<T>& vec) const;
	Vector2<T> operator%(const Vector2<T>& vec) const;

	Vector2<T> operator+(T value) const;
	Vector2<T> operator-(T value) const;
	Vector2<T> operator*(T value) const;
	Vector2<T> operator/(T value) const;
	Vector2<T> operator%(T value) const;

	void operator=(const Vector2<T>& vec)  const;
	void operator+=(const Vector2<T>& vec) const;
	void operator-=(const Vector2<T>& vec) const;
	void operator*=(const Vector2<T>& vec) const;
	void operator/=(const Vector2<T>& vec) const;
	void operator%=(const Vector2<T>& vec) const;

	void operator=(T value)  const;
	void operator+=(T value) const;
	void operator-=(T value) const;
	void operator*=(T value) const;
	void operator/=(T value) const;
	void operator%=(T value) const;

	bool operator==(const Vector2<T>& vec) const;
	bool operator!=(const Vector2<T>& vec) const;
	bool operator<(const Vector2<T>& vec)  const;
	bool operator>(const Vector2<T>& vec)  const;
	bool operator<=(const Vector2<T>& vec) const;
	bool operator>=(const Vector2<T>& vec) const;

	bool operator==(T value) const;
	bool operator!=(T value) const;
	bool operator<(T value)  const;
	bool operator>(T value)  const;
	bool operator<=(T value) const;
	bool operator>=(T value) const;
};

template<typename T>
inline Vector2<T> Vector2<T>::normalized() const
{
	static_assert(std::is_floating_point_v<T>, "Vector2::normalized() is only supports floating point types");
	assert(length() != 0);

	return *this / length();
}

template<typename T>
inline Vector2<T> Vector2<T>::opposite() const
{
	static_assert(std::is_signed_v<T>, "Vector2::opposite() is only supports signed types");

	return Vector2<T>(x * (-1), y * (-1));
}

template<typename T>
inline Vector2<T> Vector2<T>::cross(const Vector2<T>& vec) const
{
	static_assert(std::is_floating_point_v<T>, "Vector2::cross() is only supports floating point types");

	return x * vec.x - y * vec.y;
}

template<typename T>
inline Vector2<T> Vector2<T>::scale_up(const Vector2<T>& vec) const
{
	static_assert(std::is_floating_point_v<T>, "Vector2::scale_up() is only supports floating point types");

	return Vector2<T>(x * vec.x, y * vec.y);
}

template<typename T>
inline Vector2<T> Vector2<T>::scale_down(const Vector2<T>& vec) const
{
	static_assert(std::is_floating_point_v<T>, "Vector2::scale_down() is only supports floating point types");
	assert(vec != 0);

	return Vector2<T>(x / vec.x, y / vec.y);
}

template<typename T>
inline T Vector2<T>::length() const
{
	static_assert(std::is_floating_point_v<T>, "Vector2::length() is only supports floating point types");

	return sqrt(x * x + y * y);
}

template<typename T>
inline T Vector2<T>::dot(const Vector2<T>& vec) const
{
	static_assert(std::is_floating_point_v<T>, "Vector2::dot() is only supports floating point types");

	return x * vec.x + y * vec.y;
}

template<typename T>
float Vector2<T>::angle() const
{
	static_assert(std::is_floating_point_v<T>, "Vector2::angle() is only supports floating point types");

	return atan2(y, x);
}


template<typename T>
inline Vector2<T> Vector2<T>::operator+(const Vector2<T>& vec) const
{
	return Vector2<T>(x + vec.x, y + vec.y);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator-(const Vector2<T>& vec) const
{
	return Vector2<T>(x - vec.x, y - vec.y);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator*(const Vector2<T>& vec) const
{
	return Vector2<T>(x * vec.x, y * vec.y);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator/(const Vector2<T>& vec) const
{
	assert(vec != 0);

	return Vector2<T>(x / vec.x, y / vec.y);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator%(const Vector2<T>& vec) const
{
	assert(vec != 0);

	return Vector2<T>(x % vec.x, y % vec.y);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator+(T value) const
{
	return Vector2<T>(x + value, y + value);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator-(T value) const
{
	return Vector2<T>(x - value, y - value);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator*(T value) const
{
	return Vector2<T>(x * value, y * value);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator/(T value) const
{
	assert(value != 0);

	return Vector2<T>(x / value, y / value);
}

template<typename T>
inline Vector2<T> Vector2<T>::operator%(T value) const
{
	assert(value != 0);

	return Vector2<T>(x % value, y % value);
}

template<typename T>
inline void Vector2<T>::operator=(const Vector2<T>& vec) const
{
	x = vec.x;
	y = vec.y;
}

template<typename T>
inline void Vector2<T>::operator+=(const Vector2<T>& vec) const
{
	x += vec.x;
	y += vec.y;
}

template<typename T>
inline void Vector2<T>::operator-=(const Vector2<T>& vec) const
{
	x -= vec.x;
	y -= vec.y;
}

template<typename T>
inline void Vector2<T>::operator*=(const Vector2<T>& vec) const
{
	x *= vec.x;
	y *= vec.y;
}

template<typename T>
inline void Vector2<T>::operator/=(const Vector2<T>& vec) const
{
	assert(vec != 0);

	x /= vec.x;
	y /= vec.y;
}

template<typename T>
inline void Vector2<T>::operator%=(const Vector2<T>& vec) const
{
	assert(vec != 0);

	x %= vec.x;
	y %= vec.y;
}

template<typename T>
inline void Vector2<T>::operator=(T value) const
{
	x = value;
	y = value;
}

template<typename T>
inline void Vector2<T>::operator+=(T value) const
{
	x += value;
	y += value;
}

template<typename T>
inline void Vector2<T>::operator-=(T value) const
{
	x -= value;
	y -= value;
}

template<typename T>
inline void Vector2<T>::operator*=(T value) const
{
	x *= value;
	y *= value;
}

template<typename T>
inline void Vector2<T>::operator/=(T value) const
{
	assert(value != 0);

	x /= value;
	y /= value;
}

template<typename T>
inline void Vector2<T>::operator%=(T value) const
{
	assert(value != 0);

	x %= value;
	y %= value;
}

template<typename T>
inline bool Vector2<T>::operator==(const Vector2<T>& vec) const
{
	return x == vec.x && y == vec.y;
}

template<typename T>
inline bool Vector2<T>::operator!=(const Vector2<T>& vec) const
{
	return x != vec.x && y != vec.y;
}

template<typename T>
inline bool Vector2<T>::operator<(const Vector2<T>& vec) const
{
	return x < vec.x && y < vec.y;
}

template<typename T>
inline bool Vector2<T>::operator>(const Vector2<T>& vec) const
{
	return x > vec.x && y > vec.y;
}

template<typename T>
inline bool Vector2<T>::operator<=(const Vector2<T>& vec) const
{
	return x <= vec.x && y <= vec.y;
}

template<typename T>
inline bool Vector2<T>::operator>=(const Vector2<T>& vec) const
{
	return x >= vec.x && y >= vec.y;
}

template<typename T>
inline bool Vector2<T>::operator==(T value) const
{
	return x == value && y == value;
}

template<typename T>
inline bool Vector2<T>::operator!=(T value) const
{
	return x != value && y != value;
}

template<typename T>
inline bool Vector2<T>::operator<(T value) const
{
	return x < value && y < value;
}

template<typename T>
inline bool Vector2<T>::operator>(T value) const
{
	return x > value && y > value;
}

template<typename T>
inline bool Vector2<T>::operator<=(T value) const
{
	return x <= value && y <= value;
}

template<typename T>
inline bool Vector2<T>::operator>=(T value) const
{
	return x >= value && y >= value;
}


#endif
