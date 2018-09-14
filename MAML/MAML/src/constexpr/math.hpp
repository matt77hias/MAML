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
	constexpr T abs(T x) noexcept {
		static_assert(!std::is_unsigned_v< T >);
		return (0 <= x) ? x : -x;
	}

	template< typename T >
	constexpr bool equal(T x, T y) noexcept {
		static_assert(std::is_floating_point_v< T >);
		return std::numeric_limits< T >::epsilon() >= abs(x - y);
	}

	template< typename T >
	constexpr T exp(T x, std::size_t n = 20u) noexcept {
		static_assert(std::is_floating_point_v< T >);

		//          inf x^n
		// exp(x) = sum ---
		//          i=0  n!

		T sum_old(-1);
		T sum(0);
		T ci(1);
		for (std::size_t i = 0u; i < n && !equal(sum_old, sum); ++i) {
			sum_old = sum;
			sum += ci;
			ci *= x / (i + 1);
		}

		return sum;
	}

	template< typename T >
	constexpr T cos(T x, std::size_t n = 20u) noexcept {
		static_assert(std::is_floating_point_v< T >);

		//          inf  (-1)^i            inf
		// cos(x) = sum -------- x^(2*i) = sum ci
		//          i=0  (2*i)!            i=0
		
		const T x2 = x * x;

		T sum_old(-1);
		T sum(0);
		T ci(1);
		for (std::size_t i = 0u; i < n && !equal(sum_old, sum); ++i) {
			sum_old = sum;
			sum += ci;
			ci *= -x2;
			ci /= ((2 * i + 1) * (2 * i + 2));
		}
		
		return sum;
	}

	template< typename T >
	constexpr T sin(T x, std::size_t n = 20u) noexcept {
		static_assert(std::is_floating_point_v< T >);

		//          inf  (-1)^i              inf
		// sin(x) = sum -------- x^(2*i+1) = sum ci
		//          i=0 (2*i+1)!             i=0
		
		const T x2 = x * x;

		T sum_old(-1);
		T sum(0);
		T ci(x);
		for (std::size_t i = 0u; i < n && !equal(sum_old, sum); ++i) {
			sum_old = sum;
			sum += ci;
			ci *= -x2;
			ci /= ((2 * i + 2) * (2 * i + 3));
		}
		
		return sum;
	}
}