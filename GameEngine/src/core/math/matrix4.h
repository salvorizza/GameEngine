#ifndef MATRIX4_H
#define MATRIX4_H

#include "../utils/primitive_types.h"
#include "vector3.h"

namespace GameEngine {

	struct Matrix4 {

		F32 elements[16];

		Matrix4();
		Matrix4(F32 d);

		Matrix4& Mul(const Matrix4& other);

		static Matrix4& Identity();
		static Matrix4& Translation(const Vector3& translation);
		static Matrix4& Rotation(const Vector3& axis, F32 angleInRadians);
		static Matrix4& Scale(const Vector3& scale);
		static Matrix4& Ortho(F32 left, F32 top, F32 right, F32 bottom, F32 near, F32 far);
		static Matrix4& Perspective(F32 aspect_ratio, F32 fovInDegrees, F32 zNear, F32 zFar);

	};

}

#endif // !MATRIX4_H
