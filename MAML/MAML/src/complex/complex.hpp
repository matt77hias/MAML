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
	// Declarations and Definitions: Complex
	//-------------------------------------------------------------------------

	template< typename T >
	struct Complex : public Vector2< T > {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Complex(T xy = 0) noexcept
			: Complex(xy, xy) {}
		constexpr explicit Complex(T x, T y) noexcept
			: Vector2(x, y) {}
		constexpr Complex(const Complex< T > &v) noexcept = default;
		constexpr Complex(Complex< T > &&v) noexcept = default;
		template< typename U >
		constexpr explicit Complex(const Complex< U > &v) noexcept
			: Complex(
				static_cast< T >(v.m_x),
				static_cast< T >(v.m_y)) {}
		~Complex() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Complex< T > &operator=(const Complex< T > &v) = default;
		constexpr Complex< T > &operator=(Complex< T > &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr const Complex< T > operator-() const noexcept {
			return Complex< T >(-m_x, -m_y);
		}
		
		constexpr const Complex< T > operator+(const Complex< T > &v) const noexcept {
			return Complex< T >(m_x + v.m_x, m_y + v.m_y);
		}
		constexpr const Complex< T > operator-(const Complex< T > &v) const noexcept {
			return Complex< T >(m_x - v.m_x, m_y - v.m_y);
		}
		constexpr const Complex< T > operator*(const Complex< T > &v) const noexcept {
			return Complex< T >(
				m_x * v.m_x - m_y * v.m_y, 
				m_x * v.m_y + m_y * v.m_x);
		}
		constexpr const Complex< T > operator/(const Complex< T > &v) const noexcept {
			const T inv = 1 / v.SqrAbs();
			return Complex< T >(
				inv * (m_x * v.m_x + m_y * v.m_y), 
				inv * (m_y * v.m_x - m_x * v.m_y));
		}
		
		constexpr const Complex< T > operator+(T a) const noexcept {
			return Complex< T >(m_x + a, m_y);
		}
		constexpr const Complex< T > operator-(T a) const noexcept {
			return Complex< T >(m_x - a, m_y);
		}
		constexpr const Complex< T > operator*(T a) const noexcept {
			return Complex< T >(m_x * a, m_y * a);
		}
		constexpr const Complex< T > operator/(T a) const noexcept {
			const T inv = 1 / a;
			return Complex< T >(m_x * inv, m_y * inv);
		}

		friend constexpr const Complex< T > operator+(T a, const Complex< T > &v) noexcept {
			return Complex< T >(a + v.m_x, a + v.m_y);
		}
		friend constexpr const Complex< T > operator-(T a, const Complex< T > &v) noexcept {
			return Complex< T >(a - v.m_x, a - v.m_y);
		}
		friend constexpr const Complex< T > operator*(T a, const Complex< T > &v) noexcept {
			return Complex< T >(a * v.m_x, a * v.m_y);
		}
		friend constexpr const Complex< T > operator/(T a, const Complex< T > &v) noexcept {
			const T inv = 1 / v.SqrAbs();
			return Complex< T >(
				inv * ( a * v.m_x),
				inv * (-a * v.m_y));
		}

		constexpr Complex< T > &operator+=(const Complex< T > &v) noexcept {
			m_x += v.m_x;
			m_y += v.m_y;
			return *this;
		}
		constexpr Complex< T > &operator-=(const Complex< T > &v) noexcept {
			m_x -= v.m_x;
			m_y -= v.m_y;
			return *this;
		}
		constexpr Complex< T > &operator*=(const Complex< T > &v) noexcept {
			m_x = m_x * v.m_x - m_y * v.m_y;
			m_y = m_x * v.m_y + m_y * v.m_x;
			return *this;
		}
		constexpr Complex< T > &operator/=(const Complex< T > &v) noexcept {
			const T inv = 1 / v.SqrAbs();
			m_x = inv * (m_x * v.m_x + m_y * v.m_y);
			m_y = inv * (m_y * v.m_x - m_x * v.m_y);
			return *this;
		}
		
		constexpr Complex< T > &operator+=(T a) noexcept {
			m_x += a;
			return *this;
		}
		constexpr Complex< T > &operator-=(T a) noexcept {
			m_x -= a;
			return *this;
		}
		constexpr Complex< T > &operator*=(T a) noexcept {
			m_x *= a;
			m_y *= a;
			return *this;
		}
		constexpr Complex< T > &operator/=(T a) noexcept {
			const T inv = 1 / a;
			m_x *= inv;
			m_y *= inv;
			return *this;
		}

		constexpr bool operator==(const Complex< T > &v) const {
			return m_x == v.m_x && m_y == v.m_y;
		}
		constexpr bool operator!=(const Complex< T > &v) const {
			return m_x != v.m_x || m_y != v.m_y;
		}

		constexpr T real() const noexcept {
			return m_x;
		}
		constexpr T imag() const noexcept {
			return m_y;
		}
	
		constexpr const Complex< T > Conjugate() const noexcept {
			return Complex< T >(m_x, -m_y);
		}
		
		constexpr T Norm() const noexcept {
			return SqrAbs();
		}
		constexpr T SqrAbs() const noexcept {
			return m_x * m_x + m_y * m_y;
		}
		T Abs() const noexcept {
			return sqrt(SqrAbs());
		}
		Complex< T > &Normalize() noexcept {
			const T a = 1 / Abs();
			m_x *= a;
			m_y *= a;
			return *this;
		}
		T Arg() const noexcept {
			return atan2(m_y, m_x);
		}
	};

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Complex
	//-------------------------------------------------------------------------

	using C32 = Complex< F32 >;
	using C64 = Complex< F64 >;

	static_assert(sizeof(C32) == sizeof(F32x2));
	static_assert(sizeof(C64) == sizeof(F64x2));
}