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

#include <limits>

#pragma endregion

//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace maml {

	template< typename FromT, typename ToT = FromT >
	using FloatingPoint = std::enable_if_t< std::is_floating_point_v< FromT >, ToT >;

	template< typename FromT, typename ToT = FromT >
	using Integral = std::enable_if_t< std::is_integral_v< FromT >, ToT >;

	constexpr std::size_t g_max_nb_factors = 20u;

	//-------------------------------------------------------------------------
	// Declarations and Definitions
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr T Abs(T x) noexcept;

	template< typename T, typename... Ts >
	[[nodiscard]]
	constexpr T Min(T x, T y, Ts... args) noexcept;

	template< typename T, typename... Ts >
	[[nodiscard]]
	constexpr T Max(T x, T y, Ts... args) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr T Clamp(T x, T low, T high) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr T Saturate(T x) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr bool Equal(T x, T y) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr T Sqr(T x) noexcept;

	//-------------------------------------------------------------------------
	// float       Exp(float x)       noexcept;
	// double      Exp(double x)      noexcept;
	// long double Exp(long double x) noexcept;
	// double      Exp(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Exp(T x,
									 std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Exp(T x,
									 std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Ln(float x)       noexcept;
	// double      Ln(double x)      noexcept;
	// long double Ln(long double x) noexcept;
	// double      Ln(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Ln(T x,
									std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Ln(T x,
									std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Log(float x)       noexcept;
	// double      Log(double x)      noexcept;
	// long double Log(long double x) noexcept;
	// double      Log(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Log(T x,
									 std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Log(T x,
									 std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Log(float x,       float base)       noexcept;
	// double      Log(double x,      double base)      noexcept;
	// long double Log(long double x, long double base) noexcept;
	// double      Log(Integral x,    Integral base)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Log(T x, T base,
									 std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Log(T x, T base,
									 std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Log2(float x)       noexcept;
	// double      Log2(double x)      noexcept;
	// long double Log2(long double x) noexcept;
	// double      Log2(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Log2(T x,
									  std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Log2(T x,
									  std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Log10(float x)       noexcept;
	// double      Log10(double x)      noexcept;
	// long double Log10(long double x) noexcept;
	// double      Log10(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Log10(T x,
									   std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Log10(T x,
									   std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Pow(float x,       float exponent)       noexcept;
	// double      Pow(double x,      double exponent)      noexcept;
	// long double Pow(long double x, long double exponent) noexcept;
	// double      Pow(Integral x,    Integral exponent)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Pow(T x, T exponent,
									 std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Pow(T x, T exponent,
									 std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Sqrt(float x)       noexcept;
	// double      Sqrt(double x)      noexcept;
	// long double Sqrt(long double x) noexcept;
	// double      Sqrt(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Sqrt(T x,
									  std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Sqrt(T x,
									  std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Cos(float x)       noexcept;
	// double      Cos(double x)      noexcept;
	// long double Cos(long double x) noexcept;
	// double      Cos(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Cos(T x,
									 std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Cos(T x,
									 std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Sin(float x)       noexcept;
	// double      Sin(double x)      noexcept;
	// long double Sin(long double x) noexcept;
	// double      Sin(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Sin(T x,
									 std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Sin(T x,
									 std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Cosh(float x)       noexcept;
	// double      Cosh(double x)      noexcept;
	// long double Cosh(long double x) noexcept;
	// double      Cosh(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Cosh(T x,
									  std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Cosh(T x,
									  std::size_t n = g_max_nb_factors) noexcept;

	//-------------------------------------------------------------------------
	// float       Sinh(float x)       noexcept;
	// double      Sinh(double x)      noexcept;
	// long double Sinh(long double x) noexcept;
	// double      Sinh(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Sinh(T x,
									  std::size_t n = g_max_nb_factors) noexcept;

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Sinh(T x,
									  std::size_t n = g_max_nb_factors) noexcept;
}

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "constexpr\math.tpp"

#pragma endregion
