#ifndef VECTOR2_H
#define VECTOR2_H

#include "../utils/primitive_types.h"

namespace GameEngine {

	struct Vector2 {

		F32 x;
		F32 y;

		Vector2();
		Vector2(F32 _x, F32 _y);

		F32 Length() const;
		F32 Dot(const Vector2& other) const;
		Vector2& Normalize();
		Vector2& Rotate(F32 angleInRadians);

		Vector2& Add(const Vector2& other);
		Vector2& Sub(const Vector2& other);
		Vector2& Mul(const Vector2& other);
		Vector2& Div(const Vector2& other);

		Vector2& Add(const float& scalar);
		Vector2& Sub(const float& scalar);
		Vector2& Mul(const float& scalar);
		Vector2& Div(const float& scalar);

		friend Vector2& operator+(Vector2 left, const Vector2& right);
		friend Vector2& operator-(Vector2 left, const Vector2& right);
		friend Vector2& operator*(Vector2 left, const Vector2& right);
		friend Vector2& operator/(Vector2 left, const Vector2& right);

		friend Vector2& operator+(Vector2 left, const float& scalar);
		friend Vector2& operator-(Vector2 left, const float& scalar);
		friend Vector2& operator*(Vector2 left, const float& scalar);
		friend Vector2& operator/(Vector2 left, const float& scalar);

		friend Vector2& operator+(const float& scalar, Vector2 right);
		friend Vector2& operator-(const float& scalar, Vector2 right);
		friend Vector2& operator*(const float& scalar, Vector2 right);
		friend Vector2& operator/(const float& scalar, Vector2 right);

		Vector2& operator+=(const Vector2& other);
		Vector2& operator-=(const Vector2& other);
		Vector2& operator*=(const Vector2& other);
		Vector2& operator/=(const Vector2& other);

		Vector2& operator+=(const float& other);
		Vector2& operator-=(const float& other);
		Vector2& operator*=(const float& other);
		Vector2& operator/=(const float& other);

	};

}

#endif
