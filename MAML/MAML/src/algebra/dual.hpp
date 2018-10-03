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

	template< typename T, 
		      typename = std::enable_if_t< std::is_floating_point_v< T > > >
	struct Dual : public Array< T, 2 > {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Dual(T xy = 0) noexcept
			: Dual(xy, xy) {}
		constexpr Dual(T x, T y) noexcept
			: Array(x, y) {}
		constexpr Dual(const Dual& v) noexcept = default;
		constexpr Dual(Dual&& v) noexcept = default;
		template< typename U >
		constexpr explicit Dual(const Dual< U >& v) noexcept
			: Dual(static_cast< T >(v.Re()),
				   static_cast< T >(v.Du())) {}
		~Dual() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		Dual& operator=(const Dual& v) noexcept = default;
		Dual& operator=(Dual&& v) noexcept = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		[[nodiscard]]
		constexpr T Re() const noexcept {
			return operator[](0u);
		}
		[[nodiscard]]
		constexpr T Du() const noexcept {
			return operator[](1u);
		}

		[[nodiscard]]
		constexpr const Dual operator+() const noexcept {
			return { Re(), Du() };
		}
		[[nodiscard]]
		constexpr const Dual operator-() const noexcept {
			return { -Re(), -Du() };
		}
		
		[[nodiscard]]
		constexpr const Dual operator+(const Dual& v) const noexcept {
			return { Re() + v.Re(), Du() + v.Du() };
		}
		[[nodiscard]]
		constexpr const Dual operator-(const Dual& v) const noexcept {
			return { Re() - v.Re(), Du() - v.Du() };
		}
		[[nodiscard]]
		constexpr const Dual operator*(const Dual& v) const noexcept {
			return { Re() * v.Re(), Re() * v.Du() + Du() * v.Re() };
		}
		[[nodiscard]]
		constexpr const Dual operator/(const Dual& v) const noexcept {
			const T inv = 1 / v.Re();
			return { inv * Re(), inv * inv * (Du() * v.Re() - Re() * v.Du()) };
		}
		
		[[nodiscard]]
		constexpr const Dual operator+(T a) const noexcept {
			return { Re() + a, Du() };
		}
		[[nodiscard]]
		constexpr const Dual operator-(T a) const noexcept {
			return { Re() - a, Du() };
		}
		[[nodiscard]]
		constexpr const Dual operator*(T a) const noexcept {
			return { Re() * a, Du() * a };
		}
		[[nodiscard]]
		constexpr const Dual operator/(T a) const noexcept {
			const T inv = 1 / a;
			return { Re() * inv, Du() * inv };
		}

		Dual& operator+=(const Dual& v) noexcept {
			Re() += v.Re();
			Du() += v.Du();
			return *this;
		}
		Dual& operator-=(const Dual& v) noexcept {
			Re() -= v.Re();
			Du() -= v.Du();
			return *this;
		}
		Dual& operator*=(const Dual& v) noexcept {
			Re() = Re() * v.Re();
			Du() = Re() * v.Du() + Du() * v.Re();
			return *this;
		}
		Dual& operator/=(const Dual& v) noexcept {
			const T inv = 1 / v.Re();
			Re() *= inv;
			Du()  = inv * inv * (Du() * v.Re() - Re() * v.Du());
			return *this;
		}
		
		Dual& operator+=(T a) noexcept {
			Re() += a;
			return *this;
		}
		Dual& operator-=(T a) noexcept {
			Re() -= a;
			return *this;
		}
		Dual& operator*=(T a) noexcept {
			Re() *= a;
			Du() *= a;
			return *this;
		}
		Dual& operator/=(T a) noexcept {
			const T inv = 1 / a;
			Re() *= inv;
			Du() *= inv;
			return *this;
		}

		[[nodiscard]]
		constexpr bool operator==(const Dual& v) const {
			return Re() == v.Re() && Du() == v.Du();
		}
		[[nodiscard]]
		constexpr bool operator!=(const Dual& v) const {
			return Re() != v.Re() || Du() != v.Du();
		}
	};

	template< typename T >
	[[nodiscard]]
	constexpr const Dual< T > operator+(T a, const Dual< T >& v) noexcept {
		return { a + v.Re(), a + v.Du() };
	}
	template< typename T >
	[[nodiscard]]
	constexpr const Dual< T > operator-(T a, const Dual< T >& v) noexcept {
		return { a - v.Re(), a - v.Du() };
	}
	template< typename T >
	[[nodiscard]]
	constexpr const Dual< T > operator*(T a, const Dual< T >& v) noexcept {
		return { a * v.Re(), a * v.Du() };
	}
	template< typename T >
	[[nodiscard]]
	constexpr const Dual< T > operator/(T a, const Dual< T >& v) noexcept {
		const T inv = 1 / v.Re();
		return { inv * a, inv * inv * (-a * v.Du()) };
	}

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Dual
	//-------------------------------------------------------------------------

	using D32 = Dual< F32 >;
	using D64 = Dual< F64 >;

	static_assert(sizeof(D32) == sizeof(F32x2));
	static_assert(sizeof(D64) == sizeof(F64x2));
}
