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

	constexpr std::size_t g_max_nb_factors = 20u;

	template< typename T >
	[[nodiscard]]
	constexpr const T Abs(T x) noexcept;

	template< typename T, typename... Ts >
	[[nodiscard]]
	constexpr const T Min(T x, T y, Ts... args) noexcept;

	template< typename T, typename... Ts >
	[[nodiscard]]
	constexpr const T Max(T x, T y, Ts... args) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Clamp(T x, T low, T high) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Saturate(T x) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr bool Equal(T x, T y) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Sqr(T x) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Exp(T x, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Ln(T x, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Log(T x, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Log(T x, T base, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Log2(T x, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Log10(T x, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Pow(T x, T exponent, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Sqrt(T x, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Cos(T x, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Sin(T x, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Cosh(T x, std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr const T Sinh(T x, std::size_t n = g_max_nb_factors) noexcept;
}

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "constexpr\math.tpp"

#pragma endregion
