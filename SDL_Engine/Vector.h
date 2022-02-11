#pragma once

/*===================================================================#
| 'Vector' source files last updated on 11 May 2021                  |
#====================================================================#
| Class has not been fully tested. No known issues found.            |
#===================================================================*/

#include <math.h>

template <class T> class Vector
{

public:

	static const Vector<T> Up;
	static const Vector<T> Down;
	static const Vector<T> Left;
	static const Vector<T> Right;
	static const Vector<T> Zero;
	static const Vector<T> One;

	Vector(T x = 0, T y = 0);

	Vector<T> operator+(const Vector<T>& second) const;
	Vector<T>& operator+=(const Vector<T>& second);

	Vector<T> operator-(const Vector<T>& second) const;
	Vector<T>& operator-=(const Vector<T>& second);

	Vector<T> operator*(const T second) const;
	Vector<T>& operator*=(const T second);

	Vector<T> operator/(const T second) const;
	Vector<T>& operator/=(const T second);

	Vector<T> operator-() const;

	T Magnitude() const;
	T SqrMagnitude() const;
	T Distance(const Vector<T>& second) const;
	T Dot(const Vector<T>& second) const;

	Vector<T> Normalize() const;
	Vector<T> Lerp(const Vector<T>& second, float delta) const;
	Vector<T> Slerp(const Vector<T>& second, float delta) const;

	T x;
	T y;
};

template <class T> const Vector<T> Vector<T>::Up = Vector<T>(0, 1);
template <class T> const Vector<T> Vector<T>::Down = Vector<T>(0, -1);
template <class T> const Vector<T> Vector<T>::Left = Vector<T>(-1, 0);
template <class T> const Vector<T> Vector<T>::Right = Vector<T>(1, 0);
template <class T> const Vector<T> Vector<T>::Zero = Vector<T>(0, 0);
template <class T> const Vector<T> Vector<T>::One = Vector<T>(1, 1);

//======================================================================================================
template <class T> Vector<T>::Vector(T x, T y)
{
	this->x = x;
	this->y = y;
}
//======================================================================================================
template <class T> Vector<T> Vector<T>::operator+(const Vector<T>& second) const
{
	Vector<T> result(*this);
	return (result += second);
}
//======================================================================================================
template <class T> Vector<T>& Vector<T>::operator+=(const Vector<T>& second)
{
	x += second.x;
	y += second.y;
	return *this;
}
//======================================================================================================
template <class T> Vector<T> Vector<T>::operator-(const Vector<T>& second) const
{
	Vector<T> result(*this);
	return (result -= second);
}
//======================================================================================================
template <class T> Vector<T>& Vector<T>::operator-=(const Vector<T>& second)
{
	x -= second.x;
	y -= second.y;
	return *this;
}
//======================================================================================================
template <class T> Vector<T> Vector<T>::operator*(const T second) const
{
	Vector<T> result(*this);
	return (result *= second);
}
//======================================================================================================
template <class T> Vector<T>& Vector<T>::operator*=(const T second)
{
	x *= second;
	y *= second;
	return *this;
}
//======================================================================================================
template <class T> Vector<T> Vector<T>::operator/(const T second) const
{
	Vector<T> result(*this);
	return (result /= second);
}
//======================================================================================================
template <class T> Vector<T>& Vector<T>::operator/=(const T second)
{
	if (second != 0) x /= second;
	if (second != 0) y /= second;
	return *this;
}
//======================================================================================================
template <class T> Vector<T> Vector<T>::operator-() const
{
	Vector<T> result(-x, -y);
	if (result.x == -0) result.x = 0;
	if (result.y == -0) result.y = 0;
	return result;
}
//======================================================================================================
template <class T> T Vector<T>::Magnitude() const
{
	return static_cast<T>(sqrtf(static_cast<float>(SqrMagnitude())));
}
//======================================================================================================
template <class T> T Vector<T>::SqrMagnitude() const
{
	return (x * x) + (y * y);
}
//======================================================================================================
template <class T> T Vector<T>::Distance(const Vector<T>& second) const
{
	return (*this - second).Magnitude();
}
//======================================================================================================
template <class T> T Vector<T>::Dot(const Vector<T>& second) const
{
	return (x * second.x) + (y * second.y);
}
//======================================================================================================
template <class T> Vector<T> Vector<T>::Normalize() const
{
	return *this / Magnitude();
}
//======================================================================================================
template <class T> Vector<T> Vector<T>::Lerp(const Vector<T>& second, float delta) const
{
	return *this + (second - *this) * delta;
}
//======================================================================================================
template<class T> Vector<T> Vector<T>::Slerp(const Vector<T>& second, float delta) const
{
	float dot = Dot(second);
	dot = max(min(dot, 1), -1);
	float angle = acosf(dot) * delta;
	Vector<T> relative = (second - *this * dot).Normalize();
	return (*this * cosf(angle)) + (relative * sinf(angle));
}