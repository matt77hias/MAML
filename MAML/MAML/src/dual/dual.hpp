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
		constexpr Dual(const Dual &v) noexcept = default;
		constexpr Dual(Dual &&v) noexcept = default;
		template< typename U >
		constexpr explicit Dual(const Dual< U > &v) noexcept
			: Dual(static_cast< T >(v.m_x),
				   static_cast< T >(v.m_y)) {}
		~Dual() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Dual &operator=(const Dual &v) = default;
		constexpr Dual &operator=(Dual &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr const Dual operator+() const noexcept {
			return Dual(m_x, m_y);
		}
		constexpr const Dual operator-() const noexcept {
			return Dual(-m_x, -m_y);
		}
		
		constexpr const Dual operator+(const Dual &v) const noexcept {
			return Dual(m_x + v.m_x, m_y + v.m_y);
		}
		constexpr const Dual operator-(const Dual &v) const noexcept {
			return Dual(m_x - v.m_x, m_y - v.m_y);
		}
		constexpr const Dual operator*(const Dual &v) const noexcept {
			return Dual(m_x * v.m_x, 
				        m_x * v.m_y + m_y * v.m_x);
		}
		constexpr const Dual operator/(const Dual &v) const noexcept {
			const T inv = 1 / v.m_x;
			return Dual(inv * m_x, 
				        inv * inv * (m_y * v.m_x - m_x * v.m_y));
		}
		
		constexpr const Dual operator+(T a) const noexcept {
			return Dual(m_x + a, m_y);
		}
		constexpr const Dual operator-(T a) const noexcept {
			return Dual(m_x - a, m_y);
		}
		constexpr const Dual operator*(T a) const noexcept {
			return Dual(m_x * a, m_y * a);
		}
		constexpr const Dual operator/(T a) const noexcept {
			const T inv = 1 / a;
			return Dual(m_x * inv, m_y * inv);
		}

		friend constexpr const Dual operator+(T a, const Dual &v) noexcept {
			return Dual(a + v.m_x, a + v.m_y);
		}
		friend constexpr const Dual operator-(T a, const Dual &v) noexcept {
			return Dual(a - v.m_x, a - v.m_y);
		}
		friend constexpr const Dual operator*(T a, const Dual &v) noexcept {
			return Dual(a * v.m_x, a * v.m_y);
		}
		friend constexpr const Dual operator/(T a, const Dual &v) noexcept {
			const T inv = 1 / v.m_x;
			return Dual(inv * a,
				        inv * inv * (-a * v.m_y));
		}

		constexpr Dual &operator+=(const Dual &v) noexcept {
			m_x += v.m_x;
			m_y += v.m_y;
			return *this;
		}
		constexpr Dual &operator-=(const Dual &v) noexcept {
			m_x -= v.m_x;
			m_y -= v.m_y;
			return *this;
		}
		constexpr Dual &operator*=(const Dual &v) noexcept {
			m_x = m_x * v.m_x;
			m_y = m_x * v.m_y + m_y * v.m_x;
			return *this;
		}
		constexpr Dual &operator/=(const Dual &v) noexcept {
			const T inv = 1 / v.m_x;
			m_x *= inv;
			m_y  = inv * inv * (m_y * v.m_x - m_x * v.m_y);
			return *this;
		}
		
		constexpr Dual &operator+=(T a) noexcept {
			m_x += a;
			return *this;
		}
		constexpr Dual &operator-=(T a) noexcept {
			m_x -= a;
			return *this;
		}
		constexpr Dual &operator*=(T a) noexcept {
			m_x *= a;
			m_y *= a;
			return *this;
		}
		constexpr Dual &operator/=(T a) noexcept {
			const T inv = 1 / a;
			m_x *= inv;
			m_y *= inv;
			return *this;
		}

		constexpr bool operator==(const Dual &v) const {
			return m_x == v.m_x && m_y == v.m_y;
		}
		constexpr bool operator!=(const Dual &v) const {
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