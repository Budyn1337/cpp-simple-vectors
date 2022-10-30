/*
* @author: Michal Medynski
* @contact: mail: misiek1566@gmail.com
*/
#ifndef VECTOR4_HPP
#define VECTOR4_HPP

#include <type_traits>
#include <math.h>
#include <cassert>

template<typename T>
struct Vector4
{
	//vector type must be arythmethic
	static_assert(std::is_arithmetic_v<T>, "Vector type must be arytmethic.");

	T x;
	T y;
	T z;
	T w;

	Vector4() :x(0), y(0), z(0), w(0) {};
	Vector4(T x, T y, T z, T w) :x(x), y(y), z(z), w(w) {};
	Vector4(T value) :x(value), y(value), z(value), w(value) {};
	Vector4(const Vector4<T>& copy) :x(copy.x), y(copy.y), z(copy.z), w(copy.w) {};

	template<typename T2>
	Vector4(const Vector4<T2>& copy) :x(static_cast<T>(copy.x)), y(static_cast<T>(copy.y)), z(static_cast<T>(copy.z)), w(static_cast<T>(copy.w)) {};

	template<typename T2>
	operator Vector4<T2>() const { return Vector4<T2>(static_cast<T2>(x), static_cast<T2>(y), static_cast<T2>(z), static_cast<T2>(w)); };

	Vector4<T> normalized() const;
	Vector4<T> opposite() const;
	Vector4<T> scale_up(const Vector4<T>& vec) const;
	Vector4<T> scale_down(const Vector4<T>& vec) const;
	T length() const;

	Vector4<T> operator+(const Vector4<T>& vec) const;
	Vector4<T> operator-(const Vector4<T>& vec) const;
	Vector4<T> operator*(const Vector4<T>& vec) const;
	Vector4<T> operator/(const Vector4<T>& vec) const;
	Vector4<T> operator%(const Vector4<T>& vec) const;

	Vector4<T> operator+(T value) const;
	Vector4<T> operator-(T value) const;
	Vector4<T> operator*(T value) const;
	Vector4<T> operator/(T value) const;
	Vector4<T> operator%(T value) const;

	void operator=(const Vector4<T>& vec);
	void operator+=(const Vector4<T>& vec);
	void operator-=(const Vector4<T>& vec);
	void operator*=(const Vector4<T>& vec);
	void operator/=(const Vector4<T>& vec);
	void operator%=(const Vector4<T>& vec);

	void operator=(T value);
	void operator+=(T value);
	void operator-=(T value);
	void operator*=(T value);
	void operator/=(T value);
	void operator%=(T value);

	bool operator==(const Vector4<T>& vec) const;
	bool operator!=(const Vector4<T>& vec) const;
	bool operator<(const Vector4<T>& vec)  const;
	bool operator>(const Vector4<T>& vec)  const;
	bool operator<=(const Vector4<T>& vec) const;
	bool operator>=(const Vector4<T>& vec) const;

	bool operator==(T value) const;
	bool operator!=(T value) const;
	bool operator<(T value)  const;
	bool operator>(T value)  const;
	bool operator<=(T value) const;
	bool operator>=(T value) const;
};

template<typename T>
inline Vector4<T> Vector4<T>::normalized() const
{
	static_assert(std::is_floating_point_v<T>, "Vector4::normalized() is only supports floating point types");
	assert(length() != 0);

	return *this / length;
}

template<typename T>
inline Vector4<T> Vector4<T>::opposite() const
{
	static_assert(std::is_signed_v<T>, "Vector4::opposite() is only supports signed types");

	return Vector4<T>(x * (-1), y * (-1), z * (-1), w * (-1));
}

template<typename T>
inline Vector4<T> Vector4<T>::scale_up(const Vector4<T>& vec) const
{
	static_assert(std::is_floating_point_v<T>, "Vector3::scale_up() is only supports floating point types");

	return Vector4<T>(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
}

template<typename T>
inline Vector4<T> Vector4<T>::scale_down(const Vector4<T>& vec) const
{
	static_assert(std::is_floating_point_v<T>, "Vector3::scale_down() is only supports floating point types");
	assert(vec != 0);

	return Vector4<T>(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
}

template<typename T>
inline T Vector4<T>::length() const
{
	static_assert(std::is_floating_point_v<T>, "Vector4::length() is only supports floating point types");

	return sqrt(x * x + y * y + z * z + w * w);
}

template<typename T>
inline Vector4<T> Vector4<T>::operator+(const Vector4<T>& vec) const
{
	return Vector4<T>(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}

template<typename T>
inline Vector4<T> Vector4<T>::operator-(const Vector4<T>& vec) const
{
	return Vector4<T>(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}

template<typename T>
inline Vector4<T> Vector4<T>::operator*(const Vector4<T>& vec) const
{
	return Vector4<T>(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
}

template<typename T>
inline Vector4<T> Vector4<T>::operator/(const Vector4<T>& vec) const
{
	assert(vec != 0);

	return Vector4<T>(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
}

template<typename T>
inline Vector4<T> Vector4<T>::operator%(const Vector4<T>& vec) const
{
	assert(vec != 0);

	return Vector4<T>(x % vec.x, y % vec.y, z % vec.z, w % vec.w);
}

template<typename T>
inline Vector4<T> Vector4<T>::operator+(T value) const
{
	return Vector4<T>(x + value, y + value, z + value, w + value);
}

template<typename T>
inline Vector4<T> Vector4<T>::operator-(T value) const
{
	return Vector4<T>(x - value, y - value, z - value, w - value);
}

template<typename T>
inline Vector4<T> Vector4<T>::operator*(T value) const
{
	return Vector4<T>(x * value, y * value, z * value, w * value);
}

template<typename T>
inline Vector4<T> Vector4<T>::operator/(T value) const
{
	assert(value != 0);

	return Vector4<T>(x / value, y / value, z / value, w / value);
}

template<typename T>
inline Vector4<T> Vector4<T>::operator%(T value) const
{
	assert(value != 0);

	return Vector4<T>(x % value, y % value, z % value, w % value);
}

template<typename T>
inline void Vector4<T>::operator=(const Vector4<T>& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
	w = vec.w;
}

template<typename T>
inline void Vector4<T>::operator+=(const Vector4<T>& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	w += vec.w;
}

template<typename T>
inline void Vector4<T>::operator-=(const Vector4<T>& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	w -= vec.w;
}

template<typename T>
inline void Vector4<T>::operator*=(const Vector4<T>& vec)
{
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
	w *= vec.w;
}

template<typename T>
inline void Vector4<T>::operator/=(const Vector4<T>& vec)
{
	assert(vec != 0);

	x /= vec.x;
	y /= vec.y;
	z /= vec.z;
	w /= vec.w;
}

template<typename T>
inline void Vector4<T>::operator%=(const Vector4<T>& vec)
{
	assert(vec != 0);

	x %= vec.x;
	y %= vec.y;
	z %= vec.z;
	w %= vec.w;
}

template<typename T>
inline void Vector4<T>::operator=(T value)
{
	x = value;
	y = value;
	z = value;
	w = value;
}

template<typename T>
inline void Vector4<T>::operator+=(T value)
{
	x += value;
	y += value;
	z += value;
	w += value;
}

template<typename T>
inline void Vector4<T>::operator-=(T value)
{
	x -= value;
	y -= value;
	z -= value;
	w -= value;
}

template<typename T>
inline void Vector4<T>::operator*=(T value)
{
	x *= value;
	y *= value;
	z *= value;
	w *= value;
}

template<typename T>
inline void Vector4<T>::operator/=(T value)
{
	assert(value != 0);

	x /= value;
	y /= value;
	z /= value;
	w /= value;
}

template<typename T>
inline void Vector4<T>::operator%=(T value)
{
	assert(value != 0);

	x %= value;
	y %= value;
	z %= value;
	w %= value;
}

template<typename T>
inline bool Vector4<T>::operator==(const Vector4<T>& vec) const
{
	return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
}

template<typename T>
inline bool Vector4<T>::operator!=(const Vector4<T>& vec) const
{
	return x != vec.x && y != vec.y && z != vec.z && w != vec.w;
}

template<typename T>
inline bool Vector4<T>::operator<(const Vector4<T>& vec) const
{
	return x < vec.x&& y < vec.y&& z < vec.z && w < vec.w;
}

template<typename T>
inline bool Vector4<T>::operator>(const Vector4<T>& vec) const
{
	return x > vec.x && y > vec.y && z > vec.z && w > vec.w;
}

template<typename T>
inline bool Vector4<T>::operator<=(const Vector4<T>& vec) const
{
	return x <= vec.x && y <= vec.y && z <= vec.z && w <= vec.w;
}

template<typename T>
inline bool Vector4<T>::operator>=(const Vector4<T>& vec) const
{
	return x >= vec.x && y >= vec.y && z >= vec.z && w >= vec.w;
}

template<typename T>
inline bool Vector4<T>::operator==(T value) const
{
	return x == value && y == value && z == value && w == value;
}

template<typename T>
inline bool Vector4<T>::operator!=(T value) const
{
	return x != value && y != value && z != value && w != value;
}

template<typename T>
inline bool Vector4<T>::operator<(T value) const
{
	return x < value&& y < value&& z < value&& w < value;
}

template<typename T>
inline bool Vector4<T>::operator>(T value) const
{
	return x > value && y > value && z > value && w > value;
}

template<typename T>
inline bool Vector4<T>::operator<=(T value) const
{
	return x <= value && y <= value && z <= value && w <= value;
}

template<typename T>
inline bool Vector4<T>::operator>=(T value) const
{
	return x >= value && y >= value && z >= value && w >= value;
}

#endif

