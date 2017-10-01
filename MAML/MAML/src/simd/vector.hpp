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

	__declspec(align(16)) struct SIMD32x4 final
		: public AlignedData< SIMD32x4 > {

	public:

		SIMD32x4(F32 x) noexcept;
		SIMD32x4(S32 x) noexcept;
		SIMD32x4(U32 x) noexcept;

		SIMD32x4(F32 x, F32 y) noexcept;
		SIMD32x4(S32 x, S32 y) noexcept;
		SIMD32x4(U32 x, U32 y) noexcept;
		explicit SIMD32x4(const F32x2 &v) noexcept;
		explicit SIMD32x4(const S32x2 &v) noexcept;
		explicit SIMD32x4(const U32x2 &v) noexcept;

		SIMD32x4(F32 x, F32 y, F32 z) noexcept;
		SIMD32x4(S32 x, S32 y, S32 z) noexcept;
		SIMD32x4(U32 x, U32 y, U32 z) noexcept;
		explicit SIMD32x4(const F32x3 &v) noexcept;
		explicit SIMD32x4(const S32x3 &v) noexcept;
		explicit SIMD32x4(const U32x3 &v) noexcept;

		SIMD32x4(F32 x, F32 y, F32 z, F32 w) noexcept;
		SIMD32x4(S32 x, S32 y, S32 z, S32 w) noexcept;
		SIMD32x4(U32 x, U32 y, U32 z, U32 w) noexcept;
		explicit SIMD32x4(const F32x4 &v) noexcept;
		explicit SIMD32x4(const S32x4 &v) noexcept;
		explicit SIMD32x4(const U32x4 &v) noexcept;

		constexpr SIMD32x4(const __m128 &v) noexcept
			: m_v(v) {}
		SIMD32x4(const SIMD32x4 &v) noexcept = default;
		SIMD32x4(SIMD32x4 &&v) noexcept = default;

		~SIMD32x4() = default;

		SIMD32x4 &operator=(const SIMD32x4 &v) = default;
		SIMD32x4 &operator=(SIMD32x4 &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		const SIMD32x4 operator-() const noexcept {
			return SIMD32x4(_mm_sub_ps(_mm_setzero_ps(), m_v));
		}
		
		const SIMD32x4 __vectorcall operator+(const SIMD32x4 &v) const noexcept {
			return SIMD32x4(_mm_add_ps(m_v, v.m_v));
		}
		const SIMD32x4 __vectorcall operator-(const SIMD32x4 &v) const noexcept {
			return SIMD32x4(_mm_sub_ps(m_v, v.m_v));
		}
		const SIMD32x4 __vectorcall operator*(const SIMD32x4 &v) const noexcept {
			return SIMD32x4(_mm_mul_ps(m_v, v.m_v));
		}
		const SIMD32x4 __vectorcall operator/(const SIMD32x4 &v) const noexcept {
			return SIMD32x4(_mm_div_ps(m_v, v.m_v));
		}
		
		const SIMD32x4 operator+(F32 a) const noexcept {
			return SIMD32x4(_mm_add_ps(m_v, _mm_set_ps1(a)));
		}
		const SIMD32x4 operator-(F32 a) const noexcept {
			return SIMD32x4(_mm_sub_ps(m_v, _mm_set_ps1(a)));
		}
		const SIMD32x4 operator*(F32 a) const noexcept {
			return SIMD32x4(_mm_mul_ps(m_v, _mm_set_ps1(a)));
		}
		const SIMD32x4 operator/(F32 a) const noexcept {
			return SIMD32x4(_mm_div_ps(m_v, _mm_set_ps1(a)));
		}

		friend const SIMD32x4 __vectorcall operator+(F32 a, const SIMD32x4 &v) noexcept {
			return SIMD32x4(_mm_add_ps(_mm_set_ps1(a), v.m_v));
		}
		friend const SIMD32x4 __vectorcall operator-(F32 a, const SIMD32x4 &v) noexcept {
			return SIMD32x4(_mm_sub_ps(_mm_set_ps1(a), v.m_v));
		}
		friend const SIMD32x4 __vectorcall operator*(F32 a, const SIMD32x4 &v) noexcept {
			return SIMD32x4(_mm_mul_ps(_mm_set_ps1(a), v.m_v));
		}
		friend const SIMD32x4 __vectorcall operator/(F32 a, const SIMD32x4 &v) noexcept {
			return SIMD32x4(_mm_div_ps(_mm_set_ps1(a), v.m_v));
		}

		SIMD32x4 & __vectorcall operator+=(const SIMD32x4 &v) noexcept {
			m_v = _mm_add_ps(m_v, v.m_v);
			return *this;
		}
		SIMD32x4 & __vectorcall operator-=(const SIMD32x4 &v) noexcept {
			m_v = _mm_sub_ps(m_v, v.m_v);
			return *this;
		}
		SIMD32x4 & __vectorcall operator*=(const SIMD32x4 &v) noexcept {
			m_v = _mm_mul_ps(m_v, v.m_v);
			return *this;
		}
		SIMD32x4 & __vectorcall operator/=(const SIMD32x4 &v) noexcept {
			m_v = _mm_div_ps(m_v, v.m_v);
			return *this;
		}
		
		SIMD32x4 &operator+=(F32 a) noexcept {
			m_v = _mm_add_ps(m_v, _mm_set_ps1(a));
			return *this;
		}
		SIMD32x4 &operator-=(F32 a) noexcept {
			m_v = _mm_sub_ps(m_v, _mm_set_ps1(a));
			return *this;
		}
		SIMD32x4 &operator*=(F32 a) noexcept {
			m_v = _mm_mul_ps(m_v, _mm_set_ps1(a));
			return *this;
		}
		SIMD32x4 &operator/=(F32 a) noexcept {
			m_v = _mm_div_ps(m_v, _mm_set_ps1(a));
			return *this;
		}

		__m128 m_v;
	};
}