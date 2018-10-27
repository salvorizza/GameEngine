#include "matrix4.h"

#include<cstring>
#include<cmath>

namespace GameEngine {

	Matrix4::Matrix4()
	{
		memset(elements, 0, sizeof(elements));
	}

	Matrix4::Matrix4(F32 d)
	{
		memset(elements, 0, sizeof(elements));
		elements[0 * 4 + 0] = d;
		elements[1 * 4 + 1] = d;
		elements[2 * 4 + 2] = d;
		elements[3 * 4 + 3] = d;
	}

	Matrix4& Matrix4::Mul(const Matrix4& other)
	{
		Matrix4 result;
		return result;
	}

	Matrix4& Matrix4::Identity()
	{
		Matrix4 identity(1);;
		return identity;
	}

	Matrix4& Matrix4::Translation(const Vector3& translation)
	{
		Matrix4 result(1);
		result.elements[3 * 4 + 0] = translation.x;
		result.elements[3 * 4 + 1] = translation.y;
		result.elements[3 * 4 + 2] = translation.z;
		return result;
	}

	Matrix4& Matrix4::Rotation(const Vector3& axis, F32 angleInRadians)
	{
		Matrix4 result;

		F32 c = cosf(angleInRadians);
		F32 s = sinf(angleInRadians);

		F32 x = axis.x;
		F32 y = axis.y;
		F32 z = axis.z;

		F32 omc = 1 - c;

		result.elements[0 * 4 + 0] = x * x * omc + c;
		result.elements[0 * 4 + 1] = x * y * omc + z * s;
		result.elements[0 * 4 + 2] = x * z * omc - y * s;

		result.elements[1 * 4 + 0] = x * y * omc - z * s;
		result.elements[1 * 4 + 1] = y * y * omc + c;
		result.elements[1 * 4 + 2] = y * z * omc + x * s;

		result.elements[2 * 4 + 0] = x * z * omc + y * s;
		result.elements[2 * 4 + 1] = y * z * omc - x * s;
		result.elements[2 * 4 + 2] = z * z * omc + c;

		result.elements[3 * 4 + 3] = 1;

		return result;
	}

	Matrix4& Matrix4::Scale(const Vector3& scale)
	{
		Matrix4 result(1);
		result.elements[0 * 4 + 0] = scale.x;
		result.elements[1 * 4 + 1] = scale.y;
		result.elements[2 * 4 + 2] = scale.z;
		return result;
	}

	Matrix4 & Matrix4::Ortho(F32 left, F32 top, F32 right, F32 bottom, F32 near, F32 far)
	{
		Matrix4 result;

		result.elements[0 * 4 + 0] = 2 / (right - left);
		result.elements[1 * 4 + 1] = 2 / (top - bottom);
		result.elements[2 * 4 + 2] = (-2) / (far - near);

		result.elements[3 * 4 + 0] = -((right + left) / (right - left));
		result.elements[3 * 4 + 1] = -((top + bottom) / (top - bottom));
		result.elements[3 * 4 + 2] = -((far + near) / (far - near));

		result.elements[3 * 4 + 3] = 1;

		return result;
	}

	Matrix4& Matrix4::Perspective(F32 aspect_ratio, F32 fovInDegrees, F32 zNear, F32 zFar)
	{
		Matrix4 result;
		F32 t = tanf(fovInDegrees);

		result.elements[0 * 4 + 0] = 1 / (aspect_ratio * t);

		result.elements[1 * 4 + 1] = 1 / t;

		result.elements[2 * 4 + 2] = -((zFar + zNear) / (zFar - zNear));
		result.elements[2 * 4 + 3] = -1;

		result.elements[3 * 4 + 2] = -((2 * zFar * zNear)/(zFar - zNear));

		return result;
	}

}