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
	// Hyperbolic
	//-------------------------------------------------------------------------

	template< typename T, 
		      typename = std::enable_if_t< std::is_floating_point_v< T > > >
	struct Hyperbolic : public Array< T, 2 > {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Hyperbolic(T xy = 0) noexcept
			: Hyperbolic(xy, xy) {}
		constexpr Hyperbolic(T x, T y) noexcept
			: Array(x, y) {}
		constexpr Hyperbolic(const Hyperbolic& v) noexcept = default;
		constexpr Hyperbolic(Hyperbolic&& v) noexcept = default;
		template< typename U >
		constexpr explicit Hyperbolic(const Hyperbolic< U >& v) noexcept
			: Hyperbolic(static_cast< T >(v.Re()),
				         static_cast< T >(v.Im())) {}
		~Hyperbolic() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		Hyperbolic& operator=(const Hyperbolic& v) = default;
		Hyperbolic& operator=(Hyperbolic&& v) = default;

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
		constexpr const Hyperbolic operator+() const noexcept {
			return { Re(), Im() };
		}
		[[nodiscard]]
		constexpr const Hyperbolic operator-() const noexcept {
			return { -Re(), -Im() };
		}

		[[nodiscard]]
		constexpr const Hyperbolic operator+(const Hyperbolic& v) const noexcept {
			return { Re() + v.Re(), Im() + v.Im() };
		}
		[[nodiscard]]
		constexpr const Hyperbolic operator-(const Hyperbolic& v) const noexcept {
			return { Re() - v.Re(), Im() - v.Im() };
		}
		[[nodiscard]]
		constexpr const Hyperbolic operator*(const Hyperbolic& v) const noexcept {
			return { 
				Re() * v.Re() + Im() * v.Im(), 
				Re() * v.Im() + Im() * v.Re() 
			};
		}

		[[nodiscard]]
		constexpr const Hyperbolic operator+(T a) const noexcept {
			return { Re() + a, Im() };
		}
		[[nodiscard]]
		constexpr const Hyperbolic operator-(T a) const noexcept {
			return { Re() - a, Im() };
		}
		[[nodiscard]]
		constexpr const Hyperbolic operator*(T a) const noexcept {
			return { Re() * a, Im() * a };
		}
		[[nodiscard]]
		constexpr const Hyperbolic operator/(T a) const noexcept {
			const T inv = 1 / a;
			return { Re() * inv, Im() * inv };
		}

		Hyperbolic& operator+=(const Hyperbolic& v) noexcept {
			Re() += v.Re();
			Im() += v.Im();
			return *this;
		}
		Hyperbolic& operator-=(const Hyperbolic& v) noexcept {
			Re() -= v.Re();
			Im() -= v.Im();
			return *this;
		}
		Hyperbolic& operator*=(const Hyperbolic& v) noexcept {
			Re() = Re() * v.Re() + Im() * v.Im();
			Im() = Re() * v.Im() + Im() * v.Re();
			return *this;
		}

		Hyperbolic& operator+=(T a) noexcept {
			Re() += a;
			return *this;
		}
		Hyperbolic& operator-=(T a) noexcept {
			Re() -= a;
			return *this;
		}
		Hyperbolic& operator*=(T a) noexcept {
			Re() *= a;
			Im() *= a;
			return *this;
		}
		Hyperbolic& operator/=(T a) noexcept {
			const T inv = 1 / a;
			Re() *= inv;
			Im() *= inv;
			return *this;
		}

		[[nodiscard]]
		constexpr bool operator==(const Hyperbolic& v) const {
			return Re() == v.Re() && Im() == v.Im();
		}
		[[nodiscard]]
		constexpr bool operator!=(const Hyperbolic& v) const {
			return Re() != v.Re() || Im() != v.Im();
		}

		[[nodiscard]]
		constexpr const Hyperbolic Conjugate() const noexcept {
			return { Re(), -Im() };
		}

		[[nodiscard]]
		constexpr T Modulus() const noexcept {
			return Re() * Re() - Im() * Im();
		}
	};

	template< typename T >
	[[nodiscard]]
	constexpr const Hyperbolic< T > operator+(T a, const Hyperbolic< T >& v) noexcept {
		return { a + v.Re(), a + v.Im() };
	}
	template< typename T >
	[[nodiscard]]
	constexpr const Hyperbolic< T > operator-(T a, const Hyperbolic< T >& v) noexcept {
		return { a - v.Re(), a - v.Im() };
	}
	template< typename T >
	[[nodiscard]]
	constexpr const Hyperbolic< T > operator*(T a, const Hyperbolic< T >& v) noexcept {
		return { a * v.Re(), a * v.Im() };
	}

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Hyperbolic
	//-------------------------------------------------------------------------

	using H32 = Hyperbolic< F32 >;
	using H64 = Hyperbolic< F64 >;

	static_assert(sizeof(H32) == sizeof(F32x2));
	static_assert(sizeof(H64) == sizeof(F64x2));
}
