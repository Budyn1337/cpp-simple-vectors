/*
* @author: Michal Medynski
* @contact: mail: misiek1566@gmail.com
*/
#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <type_traits>
#include <math.h>
#include <cassert>
#include <string.h>

template<typename T>
struct Vector3
{
	//vector type must be arythmethic
	static_assert(std::is_arithmetic_v<T>, "Vector type must be arytmethic.");

	T x;
	T y;
	T z;

	Vector3() :x(0), y(0), z(0) {};
	Vector3(T x, T y, T z) :x(x), y(y), z(z) {};
	Vector3(T value) :x(value), y(value), z(value) {};
	Vector3(const Vector3<T>& copy) :x(copy.x), y(copy.y), z(copy.z) {};

	template<typename T2>
	Vector3(const Vector3<T2>& copy) :x(static_cast<T>(copy.x)), y(static_cast<T>(copy.y)), z(static_cast<T>(copy.z)) {};

	template<typename T2>
	operator Vector3<T2>() const { return Vector3<T2>(static_cast<T2>(x), static_cast<T2>(y), static_cast<T2>(z)); };

	Vector3<T> normalized() const;
	Vector3<T> opposite() const;
	Vector3<T> cross(const Vector3<T>& vec) const;
	Vector3<T> scale_up(const Vector3<T>& vec) const;
	Vector3<T> scale_down(const Vector3<T>& vec) const;

	T dot(const Vector3<T>& vec) const;
	T length() const;

	Vector3<T> operator+(const Vector3<T>& vec) const;
	Vector3<T> operator-(const Vector3<T>& vec) const;
	Vector3<T> operator*(const Vector3<T>& vec) const;
	Vector3<T> operator/(const Vector3<T>& vec) const;
	Vector3<T> operator%(const Vector3<T>& vec) const;

	Vector3<T> operator+(T value) const;
	Vector3<T> operator-(T value) const;
	Vector3<T> operator*(T value) const;
	Vector3<T> operator/(T value) const;
	Vector3<T> operator%(T value) const;

	void operator=(const Vector3<T>& vec)  const;
	void operator+=(const Vector3<T>& vec) const;
	void operator-=(const Vector3<T>& vec) const;
	void operator*=(const Vector3<T>& vec) const;
	void operator/=(const Vector3<T>& vec) const;
	void operator%=(const Vector3<T>& vec) const;

	void operator=(T value)  const;
	void operator+=(T value) const;
	void operator-=(T value) const;
	void operator*=(T value) const;
	void operator/=(T value) const;
	void operator%=(T value) const;

	bool operator==(const Vector3<T>& vec) const;
	bool operator!=(const Vector3<T>& vec) const;
	bool operator<(const Vector3<T>& vec)  const;
	bool operator>(const Vector3<T>& vec)  const;
	bool operator<=(const Vector3<T>& vec) const;
	bool operator>=(const Vector3<T>& vec) const;

	bool operator==(T value) const;
	bool operator!=(T value) const;
	bool operator<(T value)  const;
	bool operator>(T value)  const;
	bool operator<=(T value) const;
	bool operator>=(T value) const;
};

template<typename T>
inline Vector3<T> Vector3<T>::normalized() const
{
	static_assert(std::is_floating_point_v<T>, "Vector3::normalized() is only supports floating point types");
	assert(length() != 0);

	return *this / length();
}

template<typename T>
inline Vector3<T> Vector3<T>::opposite() const
{
	static_assert(std::is_signed_v<T>, "Vector3::opposite() is only supports signed types");

	return Vector3<T>(x * (-1), y * (-1), z * (-1));
}

template<typename T>
inline Vector3<T> Vector3<T>::cross(const Vector3<T>& vec) const
{
	static_assert(std::is_floating_point_v<T>, "Vector3::cross() is only supports floating point types");

	return Vector3<T>((y * vec.z) - (z * vec.y), (z * vec.x) - (x * vec.z), (x * vec.y) - (y * vec.x));
}

template<typename T>
inline Vector3<T> Vector3<T>::scale_up(const Vector3<T>& vec) const
{
	static_assert(std::is_floating_point_v<T>, "Vector3::scale_up() is only supports floating point types");

	return Vector3<T>(x * vec.x, y * vec.y, z * vec.z);
}

template<typename T>
inline Vector3<T> Vector3<T>::scale_down(const Vector3<T>& vec) const
{
	static_assert(std::is_floating_point_v<T>, "Vector3::scale_down() is only supports floating point types");
	assert(vec != 0);

	return Vector3<T>(x / vec.x, y / vec.y, z / vec.z);
}

template<typename T>
inline T Vector3<T>::dot(const Vector3<T>& vec) const
{
	static_assert(std::is_floating_point_v<T>, "Vector3::dot() is only supports floating point types");

	return x * vec.x + y * vec.y + z * vec.z;
}

template<typename T>
inline T Vector3<T>::length() const
{
	static_assert(std::is_floating_point_v<T>, "Vector3::length() is only supports floating point types");

	return sqrt(x * x + y * y + z * z);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator+(const Vector3<T>& vec) const
{
	return Vector3<T>(x + vec.x, y + vec.y, z + vec.z);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-(const Vector3<T>& vec) const
{
	return Vector3<T>(x - vec.x, y - vec.y, z - vec.z);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator*(const Vector3<T>& vec) const
{
	return Vector3<T>(x * vec.x, y * vec.y, z * vec.z);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator/(const Vector3<T>& vec) const
{
	assert(vec != 0);

	return Vector3<T>(x / vec.x, y / vec.y, z / vec.z);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator%(const Vector3<T>& vec) const
{
	assert(vec != 0);

	return Vector3<T>(x % vec.x, y % vec.y, z % vec.z);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator+(T value) const
{
	return Vector3<T>(x + value, y + value, z + value);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator-(T value) const
{
	return Vector3<T>(x - value, y - value, z - value);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator*(T value) const
{
	return Vector3<T>(x * value, y * value, z * value);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator/(T value) const
{
	assert(value != 0);

	return Vector3<T>(x / value, y / value, z / value);
}

template<typename T>
inline Vector3<T> Vector3<T>::operator%(T value) const
{
	assert(value != 0);

	return Vector3<T>(x % value, y % value, z % value);
}

template<typename T>
inline void Vector3<T>::operator=(const Vector3<T>& vec) const
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

template<typename T>
inline void Vector3<T>::operator+=(const Vector3<T>& vec) const
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
}

template<typename T>
inline void Vector3<T>::operator-=(const Vector3<T>& vec) const
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
}

template<typename T>
inline void Vector3<T>::operator*=(const Vector3<T>& vec) const
{
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
}

template<typename T>
inline void Vector3<T>::operator/=(const Vector3<T>& vec) const
{
	assert(vec != 0);

	x /= vec.x;
	y /= vec.y;
	z /= vec.z;
}

template<typename T>
inline void Vector3<T>::operator%=(const Vector3<T>& vec) const
{
	assert(vec != 0);

	x %= vec.x;
	y %= vec.y;
	z %= vec.z;
}

template<typename T>
inline void Vector3<T>::operator=(T value) const
{
	x = value;
	y = value;
	z = value;
}

template<typename T>
inline void Vector3<T>::operator+=(T value) const
{
	x += value;
	y += value;
	z += value;
}

template<typename T>
inline void Vector3<T>::operator-=(T value) const
{
	x -= value;
	y -= value;
	z -= value;
}

template<typename T>
inline void Vector3<T>::operator*=(T value) const
{
	x *= value;
	y *= value;
	z *= value;
}

template<typename T>
inline void Vector3<T>::operator/=(T value) const
{
	assert(value != 0);

	x /= value;
	y /= value;
	z /= value;
}

template<typename T>
inline void Vector3<T>::operator%=(T value) const
{
	assert(value != 0);

	x %= value;
	y %= value;
	z %= value;
}

template<typename T>
inline bool Vector3<T>::operator==(const Vector3<T>& vec) const
{
	return x == vec.x && y == vec.y && z == vec.z;
}

template<typename T>
inline bool Vector3<T>::operator!=(const Vector3<T>& vec) const
{
	return x != vec.x && y != vec.y && z != vec.z;
}

template<typename T>
inline bool Vector3<T>::operator<(const Vector3<T>& vec) const
{
	return x < vec.x&& y < vec.y && z < vec.z;
}

template<typename T>
inline bool Vector3<T>::operator>(const Vector3<T>& vec) const
{
	return x > vec.x && y > vec.y && z > vec.z;
}

template<typename T>
inline bool Vector3<T>::operator<=(const Vector3<T>& vec) const
{
	return x <= vec.x && y <= vec.y && z <= vec.z;
}

template<typename T>
inline bool Vector3<T>::operator>=(const Vector3<T>& vec) const
{
	return x >= vec.x && y >= vec.y && z >= vec.z;
}

template<typename T>
inline bool Vector3<T>::operator==(T value) const
{
	return x == value && y == value && z == value;
}

template<typename T>
inline bool Vector3<T>::operator!=(T value) const
{
	return x != value && y != value && z != value;
}

template<typename T>
inline bool Vector3<T>::operator<(T value) const
{
	return x < value&& y < value && z < value;
}

template<typename T>
inline bool Vector3<T>::operator>(T value) const
{
	return x > value && y > value && z > value;
}

template<typename T>
inline bool Vector3<T>::operator<=(T value) const
{
	return x <= value && y <= value && z <= value;
}

template<typename T>
inline bool Vector3<T>::operator>=(T value) const
{
	return x >= value && y >= value && z >= value;
}


#endif

