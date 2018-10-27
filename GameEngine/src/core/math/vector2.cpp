#include "vector2.h"

#include<cmath>

namespace GameEngine {

	Vector2::Vector2()
		:x(0.0f),y(0.0f)
	{}

	Vector2::Vector2(F32 _x, F32 _y)
		:x(_x),y(_y)
	{}

	F32 Vector2::Length() const
	{
		return sqrtf(x * x + y * y);
	}

	F32 Vector2::Dot(const Vector2& other) const
	{
		return x * other.x + y * other.y;
	}

	Vector2& Vector2::Normalize()
	{
		F32 len = Length();
		x /= len;
		y /= len;
		return *this;
	}

	Vector2 & Vector2::Rotate(F32 angleInRadians)
	{
		F32 cos = cosf(angleInRadians);
		F32 sin = sinf(angleInRadians);

		F32 rotated_x = cos * x - sin * y;
		F32 rotated_y = sin * x + cos * y;

		x = rotated_x;
		y = rotated_y;

		return *this;
	}

	Vector2& Vector2::Add(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2& Vector2::Sub(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2& Vector2::Mul(const Vector2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vector2& Vector2::Div(const Vector2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vector2& Vector2::Add(const float& scalar)
	{
		x += scalar;
		y += scalar;
		return *this;
	}

	Vector2& Vector2::Sub(const float& scalar)
	{
		x -= scalar;
		y -= scalar;
		return *this;
	}

	Vector2& Vector2::Mul(const float& scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2& Vector2::Div(const float& scalar)
	{
		x /= scalar;
		y /= scalar;
		return *this;
	}

	Vector2& operator+(Vector2 left, const Vector2& right)
	{
		return left.Add(right);
	}

	Vector2& operator-(Vector2 left, const Vector2& right)
	{
		return left.Sub(right);
	}

	Vector2& operator*(Vector2 left, const Vector2& right)
	{
		return left.Mul(right);
	}

	Vector2& operator/(Vector2 left, const Vector2& right)
	{
		return left.Div(right);
	}

	Vector2& operator+(Vector2 left, const float& scalar)
	{									   
		return left.Add(scalar);
	}									   
										   
	Vector2& operator-(Vector2 left, const float& scalar)
	{									   
		return left.Sub(scalar);
	}									   
										   
	Vector2& operator*(Vector2 left, const float& scalar)
	{									   
		return left.Mul(scalar);
	}									   
										   
	Vector2& operator/(Vector2 left, const float& scalar)
	{
		return left.Div(scalar);
	}

	Vector2& operator+(const float& scalar, Vector2 right)
	{
		return right.Add(scalar);
	}

	Vector2& operator-(const float& scalar, Vector2 right)
	{
		return right.Sub(scalar);
	}

	Vector2& operator*(const float& scalar, Vector2 right)
	{
		return right.Mul(scalar);
	}

	Vector2& operator/(const float& scalar, Vector2 right)
	{
		return right.Div(scalar);
	}

	Vector2& Vector2::operator+=(const Vector2& other)
	{
		return Add(other);
	}

	Vector2& Vector2::operator-=(const Vector2& other)
	{
		return Sub(other);
	}

	Vector2& Vector2::operator*=(const Vector2& other)
	{
		return Mul(other);
	}

	Vector2& Vector2::operator/=(const Vector2& other)
	{
		return Div(other);
	}

	Vector2& Vector2::operator+=(const float& other)
	{
		return Add(other);
	}

	Vector2& Vector2::operator-=(const float& other)
	{
		return Sub(other);
	}

	Vector2& Vector2::operator*=(const float& other)
	{
		return Mul(other);
	}

	Vector2& Vector2::operator/=(const float& other)
	{
		return Div(other);
	}

}