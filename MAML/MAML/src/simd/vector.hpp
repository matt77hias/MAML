#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "type\types.hpp"

#pragma endregion

//-----------------------------------------------------------------------------
// System Includes
//-----------------------------------------------------------------------------
#pragma region

#include <immintrin.h>
#include <xmmintrin.h>

#pragma endregion

//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace maml {

	struct alignas(16) F32x4S {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		explicit F32x4S(F32 xyzw = 0.0f) noexcept
			: F32x4S(_mm_set_ps1(xyzw)) {}
		F32x4S(F32 x, F32 y, F32 z, F32 w) noexcept
			: F32x4S(_mm_set_ps(w, z, y, x)) {}
		F32x4S(const F32x4& v) noexcept
			: F32x4S(v[0u], v[1u], v[2u], v[3u]) {}
		F32x4S(__m128 v) noexcept
			: m_v(v) {}
		
		F32x4S(const F32x4S& v) noexcept = default;
		F32x4S(F32x4S&& v) noexcept = default;
		~F32x4S() noexcept = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		F32x4S& operator=(const F32x4S& v) = default;
		F32x4S& operator=(F32x4S&& v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		[[nodiscard]]
		F32 __vectorcall X() const noexcept {
			return _mm_cvtss_f32(m_v);
		}
		[[nodiscard]]
		F32 __vectorcall Y() const noexcept {
			return _mm_cvtss_f32(_mm_permute_ps(m_v, _MM_SHUFFLE(1, 1, 1, 1)));
		}
		[[nodiscard]]
		F32 __vectorcall Z() const noexcept {
			return _mm_cvtss_f32(_mm_permute_ps(m_v, _MM_SHUFFLE(2, 2, 2, 2)));
		}
		[[nodiscard]]
		F32 __vectorcall W() const noexcept {
			return _mm_cvtss_f32(_mm_permute_ps(m_v, _MM_SHUFFLE(3, 3, 3, 3)));
		}

		[[nodiscard]]
		const F32x4S __vectorcall operator+() const noexcept {
			return m_v;
		}
		[[nodiscard]]
		const F32x4S __vectorcall operator-() const noexcept {
			return _mm_sub_ps(_mm_setzero_ps(), m_v);
		}
		
		[[nodiscard]]
		const F32x4S __vectorcall operator+(const F32x4S& v) const noexcept {
			return _mm_add_ps(m_v, v.m_v);
		}
		[[nodiscard]]
		const F32x4S __vectorcall operator-(const F32x4S& v) const noexcept {
			return _mm_sub_ps(m_v, v.m_v);
		}
		[[nodiscard]]
		const F32x4S __vectorcall operator*(const F32x4S& v) const noexcept {
			return _mm_mul_ps(m_v, v.m_v);
		}
		[[nodiscard]]
		const F32x4S __vectorcall operator/(const F32x4S& v) const noexcept {
			return _mm_div_ps(m_v, v.m_v);
		}
		
		[[nodiscard]]
		const F32x4S __vectorcall operator+(F32 a) const noexcept {
			return _mm_add_ps(m_v, _mm_set_ps1(a));
		}
		[[nodiscard]]
		const F32x4S __vectorcall operator-(F32 a) const noexcept {
			return _mm_sub_ps(m_v, _mm_set_ps1(a));
		}
		[[nodiscard]]
		const F32x4S __vectorcall operator*(F32 a) const noexcept {
			return _mm_mul_ps(m_v, _mm_set_ps1(a));
		}
		[[nodiscard]]
		const F32x4S __vectorcall operator/(F32 a) const noexcept {
			return _mm_div_ps(m_v, _mm_set_ps1(a));
		}

		F32x4S& __vectorcall operator+=(const F32x4S& v) noexcept {
			m_v = _mm_add_ps(m_v, v.m_v);
			return *this;
		}
		F32x4S& __vectorcall operator-=(const F32x4S& v) noexcept {
			m_v = _mm_sub_ps(m_v, v.m_v);
			return *this;
		}
		F32x4S& __vectorcall operator*=(const F32x4S& v) noexcept {
			m_v = _mm_mul_ps(m_v, v.m_v);
			return *this;
		}
		F32x4S& __vectorcall operator/=(const F32x4S& v) noexcept {
			m_v = _mm_div_ps(m_v, v.m_v);
			return *this;
		}
		
		F32x4S& __vectorcall operator+=(F32 a) noexcept {
			m_v = _mm_add_ps(m_v, _mm_set_ps1(a));
			return *this;
		}
		F32x4S& __vectorcall operator-=(F32 a) noexcept {
			m_v = _mm_sub_ps(m_v, _mm_set_ps1(a));
			return *this;
		}
		F32x4S& __vectorcall operator*=(F32 a) noexcept {
			m_v = _mm_mul_ps(m_v, _mm_set_ps1(a));
			return *this;
		}
		F32x4S& __vectorcall operator/=(F32 a) noexcept {
			m_v = _mm_div_ps(m_v, _mm_set_ps1(a));
			return *this;
		}

		[[nodiscard]]
		bool __vectorcall operator==(const F32x4S& v) const {
			const __m128i results = _mm_castps_si128(_mm_cmpeq_ps(m_v, v.m_v));
			return (0xFFFF == _mm_movemask_epi8(results));
		}
		[[nodiscard]]
		bool __vectorcall operator!=(const F32x4S& v) const {
			return !(*this == v);
		}

		__m128 m_v;
	};

	[[nodiscard]]
	const F32x4S __vectorcall operator+(F32 a, const F32x4S& v) noexcept {
		return _mm_add_ps(_mm_set_ps1(a), v.m_v);
	}
	[[nodiscard]]
	const F32x4S __vectorcall operator-(F32 a, const F32x4S& v) noexcept {
		return _mm_sub_ps(_mm_set_ps1(a), v.m_v);
	}
	[[nodiscard]]
	const F32x4S __vectorcall operator*(F32 a, const F32x4S& v) noexcept {
		return _mm_mul_ps(_mm_set_ps1(a), v.m_v);
	}
	[[nodiscard]]
	const F32x4S __vectorcall operator/(F32 a, const F32x4S& v) noexcept {
		return _mm_div_ps(_mm_set_ps1(a), v.m_v);
	}
}
