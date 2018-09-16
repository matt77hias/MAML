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
	[[nodicard]]
	constexpr const T Abs(T x) noexcept {
		static_assert(!std::is_unsigned_v< T >);
		return (0 <= x) ? x : -x;
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Min(T x) noexcept {
		return x;
	}

	template< typename T, typename... Ts >
	[[nodicard]]
	constexpr const T Min(T x, T y, Ts... args) noexcept {
		return Min((x <= y ? x : y), args...);
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Max(T x) noexcept {
		return x;
	}

	template< typename T, typename... Ts >
	[[nodicard]]
	constexpr const T Max(T x, T y, Ts... args) noexcept {
		return Max((x >= y ? x : y), args...);
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Clamp(T x, T low, T high) noexcept {
		return Min(Max(x, low), high);
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Saturate(T x) noexcept {
		return Clamp(x, T(0), T(1));
	}

	template< typename T >
	[[nodicard]]
	constexpr bool Equal(T x, T y) noexcept {
		static_assert(std::is_floating_point_v< T >);
		return std::numeric_limits< T >::epsilon() >= Abs(x - y);
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Sqr(T x) noexcept {
		return x * x;
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Exp(T x, std::size_t n) noexcept {
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
	[[nodicard]]
	constexpr const T Ln(T x, std::size_t n) noexcept {
		return 0; //TODO
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Log(T x, std::size_t n) noexcept {
		return Ln(x, n);
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Log(T x, T base, std::size_t n) noexcept {
		return Ln(x, n) / Ln(base, n);
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Log2(T x, std::size_t n) noexcept {
		constexpr T inv_ln2(1.44269504089);
		return Ln(x, n) * inv_ln2;
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Log10(T x, std::size_t n) noexcept {
		constexpr T inv_ln10(0.4342944819);
		return Ln(x, n) * inv_ln10;
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Pow(T x, T exponent, std::size_t n) noexcept {
		static_assert(std::is_floating_point_v< T >);
		return Exp(exponent * Ln(x, n), n);
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Sqrt(T x, std::size_t n) noexcept {
		static_assert(std::is_floating_point_v< T >);
		return Pow(x, T(0.5), n);
	}

	template< typename T >
	[[nodicard]]
	constexpr const T Cos(T x, std::size_t n) noexcept {
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
	[[nodicard]]
	constexpr const T Sin(T x, std::size_t n) noexcept {
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
	[[nodicard]]
	constexpr const T Cosh(T x, std::size_t n) noexcept {
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
	[[nodicard]]
	constexpr const T Sinh(T x, std::size_t n) noexcept {
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
