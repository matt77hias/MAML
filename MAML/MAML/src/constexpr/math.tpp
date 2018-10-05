#pragma once

//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace maml {

	template< typename T >
	[[nodiscard]]
	constexpr T Abs(T x) noexcept {
		static_assert(!std::is_unsigned_v< T >);
		return (0 <= x) ? x : -x;
	}

	template< typename T >
	[[nodiscard]]
	constexpr T Min(T x) noexcept {
		return x;
	}

	template< typename T, typename... Ts >
	[[nodiscard]]
	constexpr T Min(T x, T y, Ts... args) noexcept {
		return Min((x <= y ? x : y), args...);
	}

	template< typename T >
	[[nodiscard]]
	constexpr T Max(T x) noexcept {
		return x;
	}

	template< typename T, typename... Ts >
	[[nodiscard]]
	constexpr T Max(T x, T y, Ts... args) noexcept {
		return Max((x >= y ? x : y), args...);
	}

	template< typename T >
	[[nodiscard]]
	constexpr T Clamp(T x, T low, T high) noexcept {
		return Min(Max(x, low), high);
	}

	template< typename T >
	[[nodiscard]]
	constexpr T Saturate(T x) noexcept {
		return Clamp(x, T(0), T(1));
	}

	template< typename T >
	[[nodiscard]]
	constexpr bool Equal(T x, T y) noexcept {
		return std::numeric_limits< T >::epsilon() >= Abs(x - y);
	}

	template< typename T >
	[[nodiscard]]
	constexpr T Sqr(T x) noexcept {
		return x * x;
	}

	//-------------------------------------------------------------------------
	// float       Exp(float x)       noexcept;
	// double      Exp(double x)      noexcept;
	// long double Exp(long double x) noexcept;
	// double      Exp(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Exp(T x, std::size_t n) noexcept {
		//          inf x^n   inf
		// exp(x) = sum --- = sum ci
		//          i=0  n!   i=0

		T sum_old(-1);
		T sum(0);
		T ci(1);
		for (std::size_t i = 0u; i < n && !Equal(sum_old, sum); ++i) {
			sum_old = sum;
			sum += ci;
			ci *= x / (i + T(1));
		}

		return sum;
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Exp(T x, std::size_t n) noexcept {
		return Exp(static_cast< F64 >(x), n);
	}

	//-------------------------------------------------------------------------
	// float       Ln(float x)       noexcept;
	// double      Ln(double x)      noexcept;
	// long double Ln(long double x) noexcept;
	// double      Ln(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Ln(T x, std::size_t n) noexcept {
		return 0; //TODO
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Ln(T x, std::size_t n) noexcept {
		return Ln(static_cast< F64 >(x), n);
	}

	//-------------------------------------------------------------------------
	// float       Log(float x)       noexcept;
	// double      Log(double x)      noexcept;
	// long double Log(long double x) noexcept;
	// double      Log(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Log(T x, std::size_t n) noexcept {
		return Ln(x, n);
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Log(T x, std::size_t n) noexcept {
		return Log(static_cast< F64 >(x), n);
	}

	//-------------------------------------------------------------------------
	// float       Log(float x,       float base)       noexcept;
	// double      Log(double x,      double base)      noexcept;
	// long double Log(long double x, long double base) noexcept;
	// double      Log(Integral x,    Integral base)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Log(T x, T base, std::size_t n) noexcept {
		return Ln(x, n) / Ln(base, n);
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Log(T x, T base, std::size_t n) noexcept {
		return Log(static_cast< F64 >(x), base, n);
	}

	//-------------------------------------------------------------------------
	// float       Log2(float x)       noexcept;
	// double      Log2(double x)      noexcept;
	// long double Log2(long double x) noexcept;
	// double      Log2(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Log2(T x, std::size_t n) noexcept {
		constexpr T inv_ln2(1.44269504089);
		return Ln(x, n) * inv_ln2;
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Log2(T x, std::size_t n) noexcept {
		return Log2(static_cast< F64 >(x), n);
	}

	//-------------------------------------------------------------------------
	// float       Log10(float x)       noexcept;
	// double      Log10(double x)      noexcept;
	// long double Log10(long double x) noexcept;
	// double      Log10(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Log10(T x, std::size_t n) noexcept {
		constexpr T inv_ln10(0.4342944819);
		return Ln(x, n) * inv_ln10;
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Log10(T x, std::size_t n) noexcept {
		return Log10(static_cast< F64 >(x), n);
	}

	//-------------------------------------------------------------------------
	// float       Pow(float x,       float exponent)       noexcept;
	// double      Pow(double x,      double exponent)      noexcept;
	// long double Pow(long double x, long double exponent) noexcept;
	// double      Pow(Integral x,    Integral exponent)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Pow(T x, T exponent, std::size_t n) noexcept {
		return Exp(exponent * Ln(x, n), n);
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Pow(T x, T exponent, std::size_t n) noexcept {
		return Pow(static_cast< F64 >(x), exponent, n);
	}

	//-------------------------------------------------------------------------
	// float       Sqrt(float x)       noexcept;
	// double      Sqrt(double x)      noexcept;
	// long double Sqrt(long double x) noexcept;
	// double      Sqrt(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Sqrt(T x, std::size_t n) noexcept {
		return Pow(x, T(0.5), n);
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Sqrt(T x, std::size_t n) noexcept {
		return Sqrt(static_cast< F64 >(x), n);
	}

	//-------------------------------------------------------------------------
	// float       Cos(float x)       noexcept;
	// double      Cos(double x)      noexcept;
	// long double Cos(long double x) noexcept;
	// double      Cos(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Cos(T x, std::size_t n) noexcept {
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
			ci /= ((T(2) * i + T(1)) * (T(2) * i + T(2)));
		}
		
		return sum;
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Cos(T x, std::size_t n) noexcept {
		return Cos(static_cast< F64 >(x), n);
	}

	//-------------------------------------------------------------------------
	// float       Sin(float x)       noexcept;
	// double      Sin(double x)      noexcept;
	// long double Sin(long double x) noexcept;
	// double      Sin(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Sin(T x, std::size_t n) noexcept {
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
			ci /= ((T(2) * i + T(2)) * (T(2) * i + T(3)));
		}
		
		return sum;
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Sin(T x, std::size_t n) noexcept {
		return Sin(static_cast< F64 >(x), n);
	}

	//-------------------------------------------------------------------------
	// float       Cosh(float x)       noexcept;
	// double      Cosh(double x)      noexcept;
	// long double Cosh(long double x) noexcept;
	// double      Cosh(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Cosh(T x, std::size_t n) noexcept {
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
			ci /= ((T(2) * i + T(1)) * (T(2) * i + T(2)));
		}
		
		return sum;
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Cosh(T x, std::size_t n) noexcept {
		return Cosh(static_cast< F64 >(x), n);
	}

	//-------------------------------------------------------------------------
	// float       Sinh(float x)       noexcept;
	// double      Sinh(double x)      noexcept;
	// long double Sinh(long double x) noexcept;
	// double      Sinh(Integral x)    noexcept;
	//-------------------------------------------------------------------------

	template< typename T >
	[[nodiscard]]
	constexpr FloatingPoint< T > Sinh(T x, std::size_t n) noexcept {
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
			ci /= ((T(2) * i + T(2)) * (T(2) * i + T(3)));
		}
		
		return sum;
	}

	template< typename T >
	[[nodiscard]]
	constexpr Integral< T, F64 > Sinh(T x, std::size_t n) noexcept {
		return Sinh(static_cast< F64 >(x), n);
	}
}
