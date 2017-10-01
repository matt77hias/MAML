#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "vector\vector.hpp"

#pragma endregion

//-----------------------------------------------------------------------------
// System Includes
//-----------------------------------------------------------------------------
#pragma region

#include <xmmintrin.h>

#pragma endregion

//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace maml {

	//-------------------------------------------------------------------------
	// Declarations and Definitions: Vector
	//-------------------------------------------------------------------------

	using SIMD32x4 = __m128;

	inline SIMD32x4 __vectorcall operator+(const SIMD32x4 &v) {
		return v;
	}
	inline SIMD32x4 __vectorcall operator-(const SIMD32x4 &v) {
		return _mm_sub_ps(_mm_setzero_ps(), v);
	}

	inline SIMD32x4 & __vectorcall operator+=(SIMD32x4 &v1, const SIMD32x4 &v2) {
		v1 = _mm_add_ps(v1, v2);
		return v1;
	}
	inline SIMD32x4 & __vectorcall operator-=(SIMD32x4 &v1, const SIMD32x4 &v2) {
		v1 = _mm_sub_ps(v1, v2);
		return v1;
	}
	inline SIMD32x4 & __vectorcall operator*=(SIMD32x4 &v1, const SIMD32x4 &v2) {
		v1 = _mm_mul_ps(v1, v2);
		return v1;
	}
	inline SIMD32x4 & __vectorcall operator/=(SIMD32x4 &v1, const SIMD32x4 &v2) {
		v1 = _mm_div_ps(v1, v2);
		return v1;
	}

	inline SIMD32x4 &operator+=(SIMD32x4 &v, float a) {
		v = _mm_add_ps(v, _mm_set_ps1(a));
		return v;
	}
	inline SIMD32x4 &operator-=(SIMD32x4 &v, float a) {
		v = _mm_sub_ps(v, _mm_set_ps1(a));
		return v;
	}
	inline SIMD32x4 &operator*=(SIMD32x4 &v, float a) {
		v = _mm_mul_ps(v, _mm_set_ps1(a));
		return v;
	}
	inline SIMD32x4 &operator/=(SIMD32x4 &v, float a) {
		v = _mm_div_ps(v, _mm_set_ps1(a));
		return v;
	}

	inline SIMD32x4 __vectorcall operator+(const SIMD32x4 &v1, const SIMD32x4 &v2) {
		return _mm_add_ps(v1, v2);
	}
	inline SIMD32x4 __vectorcall operator-(const SIMD32x4 &v1, const SIMD32x4 &v2) {
		return _mm_sub_ps(v1, v2);
	}
	inline SIMD32x4 __vectorcall operator*(const SIMD32x4 &v1, const SIMD32x4 &v2) {
		return _mm_mul_ps(v1, v2);
	}
	inline SIMD32x4 __vectorcall operator/(const SIMD32x4 &v1, const SIMD32x4 &v2) {
		return _mm_div_ps(v1, v2);
	}
	
	inline SIMD32x4 __vectorcall operator+(const SIMD32x4 &v, float a) {
		return _mm_add_ps(v, _mm_set_ps1(a));
	}
	inline SIMD32x4 __vectorcall operator-(const SIMD32x4 &v, float a) {
		return _mm_sub_ps(v, _mm_set_ps1(a));
	}
	inline SIMD32x4 __vectorcall operator*(const SIMD32x4 &v, float a) {
		return _mm_mul_ps(v, _mm_set_ps1(a));
	}
	inline SIMD32x4 __vectorcall operator/(const SIMD32x4 &v, float a) {
		return _mm_div_ps(v, _mm_set_ps1(a));
	}

	inline SIMD32x4 __vectorcall operator+(float a, const SIMD32x4 &v) {
		return _mm_add_ps(_mm_set_ps1(a), v);
	}
	inline SIMD32x4 __vectorcall operator-(float a, const SIMD32x4 &v) {
		return _mm_sub_ps(_mm_set_ps1(a), v);
	}
	inline SIMD32x4 __vectorcall operator*(float a, const SIMD32x4 &v) {
		return _mm_mul_ps(_mm_set_ps1(a), v);
	}
	inline SIMD32x4 __vectorcall operator/(float a, const SIMD32x4 &v) {
		return _mm_div_ps(_mm_set_ps1(a), v);
	}
}