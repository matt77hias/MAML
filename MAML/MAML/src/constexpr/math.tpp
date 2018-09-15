#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include <cstddef>
#include <limits>
#include <type_traits>

#pragma endregion

//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace maml {

	template< typename T >
	constexpr T Abs(T x) noexcept {
		static_assert(!std::is_unsigned_v< T >);
		return (0 <= x) ? x : -x;
	}

	template< typename T >
	constexpr bool Equal(T x, T y) noexcept {
		static_assert(std::is_floating_point_v< T >);
		return std::numeric_limits< T >::epsilon() >= abs(x - y);
	}

	template< typename T >
	constexpr T Sqr(T x) noexcept {
		return x * x;
	}

	template< typename T >
	constexpr T Exp(T x, std::size_t n) noexcept {
		static_assert(std::is_floating_point_v< T >);

		//          inf x^n   inf
		// exp(x) = sum --- = sum ci
		//          i=0  n!   i=0

		T sum_old(-1);
		T sum(0);
		T ci(1);
		for (std::size_t i = 0u; i < n && !Equal(sum_old, sum); ++i) {
			sum_old = sum;
			sum += ci;
			ci *= x / (i + 1);
		}

		return sum;
	}

	template< typename T >
	constexpr T Cos(T x, std::size_t n) noexcept {
		static_assert(std::is_floating_point_v< T >);

		//          inf  (-1)^i            inf
		// cos(x) = sum -------- x^(2*i) = sum ci
		//          i=0  (2*i)!            i=0
		
		const T x2 = Sqr(x);

		T sum_old(-1);
		T sum(0);
		T ci(1);
		for (std::size_t i = 0u; i < n && !Equal(sum_old, sum); ++i) {
			sum_old = sum;
			sum += ci;
			ci *= -x2;
			ci /= ((2 * i + 1) * (2 * i + 2));
		}
		
		return sum;
	}

	template< typename T >
	constexpr T Sin(T x, std::size_t n) noexcept {
		static_assert(std::is_floating_point_v< T >);

		//          inf  (-1)^i              inf
		// sin(x) = sum -------- x^(2*i+1) = sum ci
		//          i=0 (2*i+1)!             i=0
		
		const T x2 = Sqr(x);

		T sum_old(-1);
		T sum(0);
		T ci(x);
		for (std::size_t i = 0u; i < n && !Equal(sum_old, sum); ++i) {
			sum_old = sum;
			sum += ci;
			ci *= -x2;
			ci /= ((2 * i + 2) * (2 * i + 3));
		}
		
		return sum;
	}

	template< typename T >
	constexpr T Cosh(T x, std::size_t n) noexcept {
		static_assert(std::is_floating_point_v< T >);

		//           inf  x^(2*i)   inf
		// cosh(x) = sum -------- = sum ci
		//           i=0  (2*i)!    i=0
		
		const T x2 = Sqr(x);

		T sum_old(-1);
		T sum(0);
		T ci(1);
		for (std::size_t i = 0u; i < n && !Equal(sum_old, sum); ++i) {
			sum_old = sum;
			sum += ci;
			ci *= x2;
			ci /= ((2 * i + 1) * (2 * i + 2));
		}
		
		return sum;
	}

	template< typename T >
	constexpr T Sinh(T x, std::size_t n) noexcept {
		static_assert(std::is_floating_point_v< T >);

		//           inf x^(2*i+1)  inf
		// sinh(x) = sum -------- = sum ci
		//           i=0 (2*i+1)!   i=0
		
		const T x2 = Sqr(x);

		T sum_old(-1);
		T sum(0);
		T ci(x);
		for (std::size_t i = 0u; i < n && !Equal(sum_old, sum); ++i) {
			sum_old = sum;
			sum += ci;
			ci *= x2;
			ci /= ((2 * i + 2) * (2 * i + 3));
		}
		
		return sum;
	}
}