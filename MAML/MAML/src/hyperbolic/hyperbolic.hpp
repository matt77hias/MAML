#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "vector\vector.hpp"

#pragma endregion

//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace maml {

	//-------------------------------------------------------------------------
	// Declarations and Definitions: Hyperbolic
	//-------------------------------------------------------------------------

	template< typename T >
	struct Hyperbolic : public Vector2< T > {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Hyperbolic(T xy = 0) noexcept
			: Hyperbolic(xy, xy) {}
		constexpr Hyperbolic(T x, T y) noexcept
			: Vector2(x, y) {}
		constexpr Hyperbolic(const Hyperbolic< T > &v) noexcept = default;
		constexpr Hyperbolic(Hyperbolic< T > &&v) noexcept = default;
		template< typename U >
		constexpr explicit Hyperbolic(const Hyperbolic< U > &v) noexcept
			: Hyperbolic(
				static_cast< T >(v.m_x),
				static_cast< T >(v.m_y)) {}
		~Hyperbolic() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Hyperbolic< T > &operator=(const Hyperbolic< T > &v) = default;
		constexpr Hyperbolic< T > &operator=(Hyperbolic< T > &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr const Hyperbolic< T > operator-() const noexcept {
			return Hyperbolic< T >(-m_x, -m_y);
		}

		constexpr const Hyperbolic< T > operator+(const Hyperbolic< T > &v) const noexcept {
			return Hyperbolic< T >(m_x + v.m_x, m_y + v.m_y);
		}
		constexpr const Hyperbolic< T > operator-(const Hyperbolic< T > &v) const noexcept {
			return Hyperbolic< T >(m_x - v.m_x, m_y - v.m_y);
		}
		constexpr const Hyperbolic< T > operator*(const Hyperbolic< T > &v) const noexcept {
			return Hyperbolic< T >(
				m_x * v.m_x + m_y * v.m_y,
				m_x * v.m_y + m_y * v.m_x);
		}
		
		constexpr const Hyperbolic< T > operator+(T a) const noexcept {
			return Hyperbolic< T >(m_x + a, m_y);
		}
		constexpr const Hyperbolic< T > operator-(T a) const noexcept {
			return Hyperbolic< T >(m_x - a, m_y);
		}
		constexpr const Hyperbolic< T > operator*(T a) const noexcept {
			return Hyperbolic< T >(m_x * a, m_y * a);
		}
		constexpr const Hyperbolic< T > operator/(T a) const noexcept {
			const T inv = 1 / a;
			return Hyperbolic< T >(m_x * inv, m_y * inv);
		}

		friend constexpr const Hyperbolic< T > operator+(T a, const Hyperbolic< T > &v) noexcept {
			return Hyperbolic< T >(a + v.m_x, a + v.m_y);
		}
		friend constexpr const Hyperbolic< T > operator-(T a, const Hyperbolic< T > &v) noexcept {
			return Hyperbolic< T >(a - v.m_x, a - v.m_y);
		}
		friend constexpr const Hyperbolic< T > operator*(T a, const Hyperbolic< T > &v) noexcept {
			return Hyperbolic< T >(a * v.m_x, a * v.m_y);
		}
		
		constexpr Hyperbolic< T > &operator+=(const Hyperbolic< T > &v) noexcept {
			m_x += v.m_x;
			m_y += v.m_y;
			return *this;
		}
		constexpr Hyperbolic< T > &operator-=(const Hyperbolic< T > &v) noexcept {
			m_x -= v.m_x;
			m_y -= v.m_y;
			return *this;
		}
		constexpr Hyperbolic< T > &operator*=(const Hyperbolic< T > &v) noexcept {
			m_x = m_x * v.m_x + m_y * v.m_y;
			m_y = m_x * v.m_y + m_y * v.m_x;
			return *this;
		}

		constexpr Hyperbolic< T > &operator+=(T a) noexcept {
			m_x += a;
			return *this;
		}
		constexpr Hyperbolic< T > &operator-=(T a) noexcept {
			m_x -= a;
			return *this;
		}
		constexpr Hyperbolic< T > &operator*=(T a) noexcept {
			m_x *= a;
			m_y *= a;
			return *this;
		}
		constexpr Hyperbolic< T > &operator/=(T a) noexcept {
			const T inv = 1 / a;
			m_x *= inv;
			m_y *= inv;
			return *this;
		}

		constexpr bool operator==(const Hyperbolic< T > &v) const {
			return m_x == v.m_x && m_y == v.m_y;
		}
		constexpr bool operator!=(const Hyperbolic< T > &v) const {
			return m_x != v.m_x || m_y != v.m_y;
		}

		constexpr T real() const noexcept {
			return m_x;
		}
		constexpr T imag() const noexcept {
			return m_y;
		}

		constexpr const Hyperbolic< T > Conjugate() const noexcept {
			return Hyperbolic< T >(m_x, -m_y);
		}

		constexpr T Modulus() const noexcept {
			return m_x * m_x - m_y * m_y;
		}
	};

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Hyperbolic
	//-------------------------------------------------------------------------

	using H32 = Hyperbolic< F32 >;
	using H64 = Hyperbolic< F64 >;

	static_assert(sizeof(H32) == sizeof(F32x2));
	static_assert(sizeof(H64) == sizeof(F64x2));
}