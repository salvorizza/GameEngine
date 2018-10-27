#ifndef VECTOR3_H
#define VECTOR3_H

#include "../utils/primitive_types.h"

namespace GameEngine {

	struct Vector3 {

		F32 x;
		F32 y;
		F32 z;

		Vector3();
		Vector3(F32 _x, F32 _y, F32 _z);

		F32 Length() const;
		F32 Dot(const Vector3& other) const;
		Vector3& Normalize();
		Vector3& Cross(const Vector3& other);

		Vector3& Add(const Vector3& other);
		Vector3& Sub(const Vector3& other);
		Vector3& Mul(const Vector3& other);
		Vector3& Div(const Vector3& other);

		Vector3& Add(const float& scalar);
		Vector3& Sub(const float& scalar);
		Vector3& Mul(const float& scalar);
		Vector3& Div(const float& scalar);

		friend Vector3& operator+(Vector3 left, const Vector3& right);
		friend Vector3& operator-(Vector3 left, const Vector3& right);
		friend Vector3& operator*(Vector3 left, const Vector3& right);
		friend Vector3& operator/(Vector3 left, const Vector3& right);

		friend Vector3& operator+(Vector3 left, const float& scalar);
		friend Vector3& operator-(Vector3 left, const float& scalar);
		friend Vector3& operator*(Vector3 left, const float& scalar);
		friend Vector3& operator/(Vector3 left, const float& scalar);

		friend Vector3& operator+(const float& scalar, Vector3 right);
		friend Vector3& operator-(const float& scalar, Vector3 right);
		friend Vector3& operator*(const float& scalar, Vector3 right);
		friend Vector3& operator/(const float& scalar, Vector3 right);

		Vector3& operator+=(const Vector3& other);
		Vector3& operator-=(const Vector3& other);
		Vector3& operator*=(const Vector3& other);
		Vector3& operator/=(const Vector3& other);

		Vector3& operator+=(const float& other);
		Vector3& operator-=(const float& other);
		Vector3& operator*=(const float& other);
		Vector3& operator/=(const float& other);

	};

}

#endif
