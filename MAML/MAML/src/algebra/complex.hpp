#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "type\types.hpp"

#pragma endregion

//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace maml {

	//-------------------------------------------------------------------------
	// Complex
	//-------------------------------------------------------------------------

	template< typename T, 
		      typename = std::enable_if_t< std::is_floating_point_v< T > > >
	struct Complex : public Array< T, 2 > {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Complex(T xy = 0) noexcept
			: Complex(xy, xy) {}
		constexpr Complex(T x, T y) noexcept
			: Array(x, y) {}
		constexpr Complex(const Complex& v) noexcept = default;
		constexpr Complex(Complex&& v) noexcept = default;
		template< typename U >
		constexpr explicit Complex(const Complex< U >& v) noexcept
			: Complex(static_cast< T >(v.Re()),
				      static_cast< T >(v.Im())) {}
		~Complex() noexcept = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		Complex& operator=(const Complex& v) = default;
		Complex& operator=(Complex&& v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		[[nodiscard]]
		constexpr T Re() const noexcept {
			return operator[](0u);
		}
		[[nodiscard]]
		constexpr T Im() const noexcept {
			return operator[](1u);
		}

		[[nodiscard]]
		constexpr const Complex operator+() const noexcept {
			return { Re(), Im() };
		}
		[[nodiscard]]
		constexpr const Complex operator-() const noexcept {
			return { -Re(), -Im() };
		}
		
		[[nodiscard]]
		constexpr const Complex operator+(const Complex& v) const noexcept {
			return { Re() + v.Re(), Im() + v.Im() };
		}
		[[nodiscard]]
		constexpr const Complex operator-(const Complex& v) const noexcept {
			return { Re() - v.Re(), Im() - v.Im() };
		}
		[[nodiscard]]
		constexpr const Complex operator*(const Complex& v) const noexcept {
			return { 
				Re() * v.Re() - Im() * v.Im(), 
				Re() * v.Im() + Im() * v.Re() 
			};
		}
		[[nodiscard]]
		constexpr const Complex operator/(const Complex& v) const noexcept {
			const T inv = 1 / v.SqrAbs();
			return {
				inv * (Re() * v.Re() + Im() * v.Im()),
				inv * (Im() * v.Re() - Re() * v.Im()) 
			};
		}
		
		[[nodiscard]]
		constexpr const Complex operator+(T a) const noexcept {
			return { Re() + a, Im() };
		}
		[[nodiscard]]
		constexpr const Complex operator-(T a) const noexcept {
			return { Re() - a, Im() };
		}
		[[nodiscard]]
		constexpr const Complex operator*(T a) const noexcept {
			return { Re() * a, Im() * a };
		}
		[[nodiscard]]
		constexpr const Complex operator/(T a) const noexcept {
			const T inv = 1 / a;
			return { Re() * inv, Im() * inv };
		}

		Complex& operator+=(const Complex& v) noexcept {
			Re() += v.Re();
			Im() += v.Im();
			return *this;
		}
		Complex& operator-=(const Complex& v) noexcept {
			Re() -= v.Re();
			Im() -= v.Im();
			return *this;
		}
		Complex& operator*=(const Complex& v) noexcept {
			Re() = Re() * v.Re() - Im() * v.Im();
			Im() = Re() * v.Im() + Im() * v.Re();
			return *this;
		}
		Complex& operator/=(const Complex& v) noexcept {
			const T inv = 1 / v.SqrAbs();
			Re() = inv * (Re() * v.Re() + Im() * v.Im());
			Im() = inv * (Im() * v.Re() - Re() * v.Im());
			return *this;
		}
		
		Complex& operator+=(T a) noexcept {
			Re() += a;
			return *this;
		}
		Complex& operator-=(T a) noexcept {
			Re() -= a;
			return *this;
		}
		Complex& operator*=(T a) noexcept {
			Re() *= a;
			Im() *= a;
			return *this;
		}
		Complex& operator/=(T a) noexcept {
			const T inv = 1 / a;
			Re() *= inv;
			Im() *= inv;
			return *this;
		}

		[[nodiscard]]
		constexpr bool operator==(const Complex& v) const {
			return Re() == v.Re() && Im() == v.Im();
		}
		[[nodiscard]]
		constexpr bool operator!=(const Complex& v) const {
			return Re() != v.Re() || Im() != v.Im();
		}

		[[nodiscard]]
		constexpr const Complex Conjugate() const noexcept {
			return { Re(), -Im() };
		}
		
		[[nodiscard]]
		constexpr T Norm() const noexcept {
			return SqrAbs();
		}
		[[nodiscard]]
		constexpr T SqrAbs() const noexcept {
			return Re() * Re() + Im() * Im();
		}
		[[nodiscard]]
		T Abs() const noexcept {
			return std::sqrt(SqrAbs());
		}
		Complex& Normalize() noexcept {
			const T a = 1 / Abs();
			Re() *= a;
			Im() *= a;
			return *this;
		}
		[[nodiscard]]
		T Arg() const noexcept {
			return std::atan2(Im(), Re());
		}
	};

	template< typename T >
	[[nodiscard]]
	constexpr const Complex< T > operator+(T a, const Complex< T >& v) noexcept {
		return { a + v.Re(), a + v.Im() };
	}
	template< typename T >
	[[nodiscard]]
	constexpr const Complex< T > operator-(T a, const Complex< T >& v) noexcept {
		return { a - v.Re(), a - v.Im() };
	}
	template< typename T >
	[[nodiscard]]
	constexpr const Complex< T > operator*(T a, const Complex< T >& v) noexcept {
		return { a * v.Re(), a * v.Im() };
	}
	template< typename T >
	[[nodiscard]]
	constexpr const Complex< T > operator/(T a, const Complex< T >& v) noexcept {
		const T inv = 1 / v.SqrAbs();
		return { inv * (a * v.Re()), inv * (-a * v.Im()) };
	}

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions
	//-------------------------------------------------------------------------

	using C32 = Complex< F32 >;
	using C64 = Complex< F64 >;

	static_assert(sizeof(C32) == sizeof(F32x2));
	static_assert(sizeof(C64) == sizeof(F64x2));
}
