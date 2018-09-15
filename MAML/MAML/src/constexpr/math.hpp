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
	constexpr const T Abs(T x) noexcept;

	template< typename T, typename... Ts >
	constexpr const T Min(T x, T y, Ts... args) noexcept;

	template< typename T, typename... Ts >
	constexpr const T Max(T x, T y, Ts... args) noexcept;

	template< typename T >
	constexpr const T Clamp(T x, T low, T high) noexcept;

	template< typename T >
	constexpr const T Saturate(T x) noexcept;

	template< typename T >
	constexpr bool Equal(T x, T y) noexcept;

	template< typename T >
	constexpr const T Sqr(T x) noexcept;

	template< typename T >
	constexpr const T Exp(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr const T Log(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr const T Pow(T x, T exponent, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr const T Sqrt(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr const T Cos(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr const T Sin(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr const T Cosh(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr const T Sinh(T x, std::size_t n = 20u) noexcept;
}

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "constexpr\math.tpp"

#pragma endregion