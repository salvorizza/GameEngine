#include "vector3.h"

#include<cmath>

namespace GameEngine {

	Vector3::Vector3()
		:x(0.0f), y(0.0f),z(0.0f)
	{}

	Vector3::Vector3(F32 _x, F32 _y, F32 _z)
		: x(_x), y(_y), z(_z)
	{}

	F32 Vector3::Length() const
	{
		return sqrtf(x * x + y * y + z * z);
	}

	F32 Vector3::Dot(const Vector3& other) const
	{
		return x * other.x + y * other.y + z * other.z;
	}

	Vector3& Vector3::Normalize()
	{
		F32 len = Length();
		x /= len;
		y /= len;
		z /= len;
		return *this;
	}

	Vector3& Vector3::Cross(const Vector3& other)
	{
		float crossed_x = y * other.z - other.y * z;
		float crossed_y = z * other.x - other.z * x;
		float crossed_z = x * other.y - other.x * y;

		x = crossed_x;
		y = crossed_y;
		z = crossed_z;

		return *this;
	}

	Vector3& Vector3::Add(const Vector3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3& Vector3::Sub(const Vector3& other)
	{
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3& Vector3::Mul(const Vector3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vector3& Vector3::Div(const Vector3& other)
	{
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	Vector3& Vector3::Add(const float& scalar)
	{
		x += scalar;
		y += scalar;
		z += scalar;
		return *this;
	}

	Vector3& Vector3::Sub(const float& scalar)
	{
		x -= scalar;
		y -= scalar;
		z -= scalar;
		return *this;
	}

	Vector3& Vector3::Mul(const float& scalar)
	{
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	Vector3& Vector3::Div(const float& scalar)
	{
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	Vector3& operator+(Vector3 left, const Vector3& right)
	{
		return left.Add(right);
	}

	Vector3& operator-(Vector3 left, const Vector3& right)
	{
		return left.Sub(right);
	}

	Vector3& operator*(Vector3 left, const Vector3& right)
	{
		return left.Mul(right);
	}

	Vector3& operator/(Vector3 left, const Vector3& right)
	{
		return left.Div(right);
	}

	Vector3& operator+(Vector3 left, const float& scalar)
	{
		return left.Add(scalar);
	}

	Vector3& operator-(Vector3 left, const float& scalar)
	{
		return left.Sub(scalar);
	}

	Vector3& operator*(Vector3 left, const float& scalar)
	{
		return left.Mul(scalar);
	}

	Vector3& operator/(Vector3 left, const float& scalar)
	{
		return left.Div(scalar);
	}

	Vector3& operator+(const float& scalar, Vector3 right)
	{
		return right.Add(scalar);
	}

	Vector3& operator-(const float& scalar, Vector3 right)
	{
		return right.Sub(scalar);
	}

	Vector3& operator*(const float& scalar, Vector3 right)
	{
		return right.Mul(scalar);
	}

	Vector3& operator/(const float& scalar, Vector3 right)
	{
		return right.Div(scalar);
	}

	Vector3& Vector3::operator+=(const Vector3& other)
	{
		return Add(other);
	}

	Vector3& Vector3::operator-=(const Vector3& other)
	{
		return Sub(other);
	}

	Vector3& Vector3::operator*=(const Vector3& other)
	{
		return Mul(other);
	}

	Vector3& Vector3::operator/=(const Vector3& other)
	{
		return Div(other);
	}

	Vector3& Vector3::operator+=(const float& other)
	{
		return Add(other);
	}

	Vector3& Vector3::operator-=(const float& other)
	{
		return Sub(other);
	}

	Vector3& Vector3::operator*=(const float& other)
	{
		return Mul(other);
	}

	Vector3& Vector3::operator/=(const float& other)
	{
		return Div(other);
	}

}