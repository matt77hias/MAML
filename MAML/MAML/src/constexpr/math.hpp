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
	constexpr T Abs(T x) noexcept;

	template< typename T >
	constexpr bool Equal(T x, T y) noexcept;

	template< typename T >
	constexpr T Sqr(T x) noexcept;

	template< typename T >
	constexpr T Exp(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr T Cos(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr T Sin(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr T Cosh(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr T Sinh(T x, std::size_t n = 20u) noexcept;
}

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "constexpr\math.tpp"

#pragma endregion