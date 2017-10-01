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
	// Declarations and Definitions: Dual
	//-------------------------------------------------------------------------

	template< typename T >
	struct Dual : public Vector2< T > {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Dual(T xy = 0) noexcept
			: Dual(xy, xy) {}
		constexpr Dual(T x, T y) noexcept
			: Vector2(x, y) {}
		constexpr Dual(const Dual< T > &v) noexcept = default;
		constexpr Dual(Dual< T > &&v) noexcept = default;
		template< typename U >
		constexpr explicit Dual(const Dual< U > &v) noexcept
			: Dual(
				static_cast< T >(v.m_x),
				static_cast< T >(v.m_y)) {}
		~Dual() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Dual< T > &operator=(const Dual< T > &v) = default;
		constexpr Dual< T > &operator=(Dual< T > &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr const Dual< T > operator-() const noexcept {
			return Dual< T >(-m_x, -m_y);
		}
		
		constexpr const Dual< T > operator+(const Dual< T > &v) const noexcept {
			return Dual< T >(m_x + v.m_x, m_y + v.m_y);
		}
		constexpr const Dual< T > operator-(const Dual< T > &v) const noexcept {
			return Dual< T >(m_x - v.m_x, m_y - v.m_y);
		}
		constexpr const Dual< T > operator*(const Dual< T > &v) const noexcept {
			return Dual< T >(
				m_x * v.m_x, 
				m_x * v.m_y + m_y * v.m_x);
		}
		constexpr const Dual< T > operator/(const Dual< T > &v) const noexcept {
			const T inv = 1 / v.m_x;
			return Dual< T >(
				inv * m_x, 
				inv * inv * (m_y * v.m_x - m_x * v.m_y));
		}
		
		constexpr const Dual< T > operator+(T a) const noexcept {
			return Dual< T >(m_x + a, m_y);
		}
		constexpr const Dual< T > operator-(T a) const noexcept {
			return Dual< T >(m_x - a, m_y);
		}
		constexpr const Dual< T > operator*(T a) const noexcept {
			return Dual< T >(m_x * a, m_y * a);
		}
		constexpr const Dual< T > operator/(T a) const noexcept {
			const T inv = 1 / a;
			return Dual< T >(m_x * inv, m_y * inv);
		}

		friend constexpr const Dual< T > operator+(T a, const Dual< T > &v) noexcept {
			return Dual< T >(a + v.m_x, a + v.m_y);
		}
		friend constexpr const Dual< T > operator-(T a, const Dual< T > &v) noexcept {
			return Dual< T >(a - v.m_x, a - v.m_y);
		}
		friend constexpr const Dual< T > operator*(T a, const Dual< T > &v) noexcept {
			return Dual< T >(a * v.m_x, a * v.m_y);
		}
		friend constexpr const Dual< T > operator/(T a, const Dual< T > &v) noexcept {
			const T inv = 1 / v.m_x;
			return Dual< T >(
				inv * a,
				inv * inv * (-a * v.m_y));
		}

		constexpr Dual< T > &operator+=(const Dual< T > &v) noexcept {
			m_x += v.m_x;
			m_y += v.m_y;
			return *this;
		}
		constexpr Dual< T > &operator-=(const Dual< T > &v) noexcept {
			m_x -= v.m_x;
			m_y -= v.m_y;
			return *this;
		}
		constexpr Dual< T > &operator*=(const Dual< T > &v) noexcept {
			m_x = m_x * v.m_x;
			m_y = m_x * v.m_y + m_y * v.m_x;
			return *this;
		}
		constexpr Dual< T > &operator/=(const Dual< T > &v) noexcept {
			const T inv = 1 / v.m_x;
			m_x *= inv;
			m_y  = inv * inv * (m_y * v.m_x - m_x * v.m_y);
			return *this;
		}
		
		constexpr Dual< T > &operator+=(T a) noexcept {
			m_x += a;
			return *this;
		}
		constexpr Dual< T > &operator-=(T a) noexcept {
			m_x -= a;
			return *this;
		}
		constexpr Dual< T > &operator*=(T a) noexcept {
			m_x *= a;
			m_y *= a;
			return *this;
		}
		constexpr Dual< T > &operator/=(T a) noexcept {
			const T inv = 1 / a;
			m_x *= inv;
			m_y *= inv;
			return *this;
		}

		constexpr bool operator==(const Dual< T > &v) const {
			return m_x == v.m_x && m_y == v.m_y;
		}
		constexpr bool operator!=(const Dual< T > &v) const {
			return m_x != v.m_x || m_y != v.m_y;
		}

		constexpr T real() const noexcept {
			return m_x;
		}
		constexpr T dual() const noexcept {
			return m_y;
		}
	};

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Dual
	//-------------------------------------------------------------------------

	using D32 = Dual< F32 >;
	using D64 = Dual< F64 >;

	static_assert(sizeof(D32) == sizeof(F32x2));
	static_assert(sizeof(D64) == sizeof(F64x2));
}