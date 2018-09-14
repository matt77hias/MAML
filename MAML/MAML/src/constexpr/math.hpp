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
	constexpr T abs(T x) noexcept;

	template< typename T >
	constexpr bool equal(T x, T y) noexcept;

	template< typename T >
	constexpr T exp(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr T cos(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr T sin(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr T cosh(T x, std::size_t n = 20u) noexcept;

	template< typename T >
	constexpr T sinh(T x, std::size_t n = 20u) noexcept;
}

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "constexpr\math.tpp"

#pragma endregion