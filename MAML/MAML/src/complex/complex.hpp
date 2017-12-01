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
		constexpr Complex(T x, T y) noexcept
			: Vector2(x, y) {}
		constexpr Complex(const Complex &v) noexcept = default;
		constexpr Complex(Complex &&v) noexcept = default;
		template< typename U >
		constexpr explicit Complex(const Complex< U > &v) noexcept
			: Complex(
				static_cast< T >(v.m_x),
				static_cast< T >(v.m_y)) {}
		~Complex() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Complex &operator=(const Complex &v) = default;
		constexpr Complex &operator=(Complex &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr const Complex operator+() const noexcept {
			return Complex(m_x, m_y);
		}
		constexpr const Complex operator-() const noexcept {
			return Complex(-m_x, -m_y);
		}
		
		constexpr const Complex operator+(const Complex &v) const noexcept {
			return Complex(m_x + v.m_x, m_y + v.m_y);
		}
		constexpr const Complex operator-(const Complex &v) const noexcept {
			return Complex(m_x - v.m_x, m_y - v.m_y);
		}
		constexpr const Complex operator*(const Complex &v) const noexcept {
			return Complex(
				m_x * v.m_x - m_y * v.m_y, 
				m_x * v.m_y + m_y * v.m_x);
		}
		constexpr const Complex operator/(const Complex &v) const noexcept {
			const T inv = 1 / v.SqrAbs();
			return Complex(
				inv * (m_x * v.m_x + m_y * v.m_y), 
				inv * (m_y * v.m_x - m_x * v.m_y));
		}
		
		constexpr const Complex operator+(T a) const noexcept {
			return Complex(m_x + a, m_y);
		}
		constexpr const Complex operator-(T a) const noexcept {
			return Complex(m_x - a, m_y);
		}
		constexpr const Complex operator*(T a) const noexcept {
			return Complex(m_x * a, m_y * a);
		}
		constexpr const Complex operator/(T a) const noexcept {
			const T inv = 1 / a;
			return Complex(m_x * inv, m_y * inv);
		}

		friend constexpr const Complex operator+(T a, const Complex &v) noexcept {
			return Complex(a + v.m_x, a + v.m_y);
		}
		friend constexpr const Complex operator-(T a, const Complex &v) noexcept {
			return Complex(a - v.m_x, a - v.m_y);
		}
		friend constexpr const Complex operator*(T a, const Complex &v) noexcept {
			return Complex(a * v.m_x, a * v.m_y);
		}
		friend constexpr const Complex operator/(T a, const Complex &v) noexcept {
			const T inv = 1 / v.SqrAbs();
			return Complex(
				inv * ( a * v.m_x),
				inv * (-a * v.m_y));
		}

		constexpr Complex &operator+=(const Complex &v) noexcept {
			m_x += v.m_x;
			m_y += v.m_y;
			return *this;
		}
		constexpr Complex &operator-=(const Complex &v) noexcept {
			m_x -= v.m_x;
			m_y -= v.m_y;
			return *this;
		}
		constexpr Complex &operator*=(const Complex &v) noexcept {
			m_x = m_x * v.m_x - m_y * v.m_y;
			m_y = m_x * v.m_y + m_y * v.m_x;
			return *this;
		}
		constexpr Complex &operator/=(const Complex &v) noexcept {
			const T inv = 1 / v.SqrAbs();
			m_x = inv * (m_x * v.m_x + m_y * v.m_y);
			m_y = inv * (m_y * v.m_x - m_x * v.m_y);
			return *this;
		}
		
		constexpr Complex &operator+=(T a) noexcept {
			m_x += a;
			return *this;
		}
		constexpr Complex &operator-=(T a) noexcept {
			m_x -= a;
			return *this;
		}
		constexpr Complex &operator*=(T a) noexcept {
			m_x *= a;
			m_y *= a;
			return *this;
		}
		constexpr Complex &operator/=(T a) noexcept {
			const T inv = 1 / a;
			m_x *= inv;
			m_y *= inv;
			return *this;
		}

		constexpr bool operator==(const Complex &v) const {
			return m_x == v.m_x && m_y == v.m_y;
		}
		constexpr bool operator!=(const Complex &v) const {
			return m_x != v.m_x || m_y != v.m_y;
		}

		constexpr T real() const noexcept {
			return m_x;
		}
		constexpr T imag() const noexcept {
			return m_y;
		}
	
		constexpr const Complex Conjugate() const noexcept {
			return Complex(m_x, -m_y);
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
		Complex &Normalize() noexcept {
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