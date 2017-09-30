#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#pragma region

#include "memory\allocation.hpp"
#include "memory\types.hpp"

#pragma endregion

//-----------------------------------------------------------------------------
// System Includes
//-----------------------------------------------------------------------------
#pragma region

#include <xmmintrin.h>

#pragma endregion

//-----------------------------------------------------------------------------
// Declarations and Definitions
//-----------------------------------------------------------------------------
namespace maml {

	//-------------------------------------------------------------------------
	// Declarations and Definitions: Vector2
	//-------------------------------------------------------------------------

	template< typename T >
	struct Vector2 {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Vector2(T xy = 0) noexcept
			: Vector2(xy, xy) {}
		constexpr explicit Vector2(T x, T y) noexcept
			: m_x(x), m_y(y) {}
		constexpr Vector2(const Vector2< T > &v) noexcept = default;
		constexpr Vector2(Vector2< T > &&v) noexcept = default;
		~Vector2() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Vector2 &operator=(const Vector2< T > &v) = default;
		constexpr Vector2 &operator=(Vector2< T > &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr T operator[](size_t i) const noexcept {
			return (&m_x)[i];
		}
		constexpr T &operator[](size_t i) noexcept {
			return (&m_x)[i];
		}

		//---------------------------------------------------------------------
		// Member Variables
		//---------------------------------------------------------------------

		T m_x;
		T m_y;
	};

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Vector2
	//-------------------------------------------------------------------------

	using F32x2 = Vector2< F32 >;
	using S32x2 = Vector2< S32 >;
	using U32x2 = Vector2< U32 >;

	static_assert(sizeof(F32x2) == 8);
	static_assert(sizeof(S32x2) == 8);
	static_assert(sizeof(U32x2) == 8);

	//-------------------------------------------------------------------------
	// Declarations and Definitions: Vector3
	//-------------------------------------------------------------------------

	template< typename T >
	struct Vector3 {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Vector3(T xyz = 0) noexcept
			: Vector3(xyz, xyz, xyz) {}
		constexpr explicit Vector3(T x, T y, T z) noexcept
			: m_x(x), m_y(y), m_z(z) {}
		constexpr explicit Vector3(const Vector2< T > &v, T z = 0) noexcept
			: Vector3(v.m_x, v.m_y, z) {}
		constexpr Vector3(const Vector3< T > &v) noexcept = default;
		constexpr Vector3(Vector3< T > &&v) noexcept = default;
		~Vector3() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Vector3 &operator=(const Vector3< T > &v) = default;
		constexpr Vector3 &operator=(Vector3< T > &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr T operator[](size_t i) const noexcept {
			return (&m_x)[i];
		}
		constexpr T &operator[](size_t i) noexcept {
			return (&m_x)[i];
		}

		//---------------------------------------------------------------------
		// Member Variables
		//---------------------------------------------------------------------

		T m_x;
		T m_y;
		T m_z;
	};

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Vector3
	//-------------------------------------------------------------------------

	using F32x3 = Vector3< F32 >;
	using S32x3 = Vector3< S32 >;
	using U32x3 = Vector3< U32 >;

	static_assert(sizeof(F32x3) == 12);
	static_assert(sizeof(S32x3) == 12);
	static_assert(sizeof(U32x3) == 12);

	//-------------------------------------------------------------------------
	// Declarations and Definitions: Vector4
	//-------------------------------------------------------------------------

	template< typename T >
	struct Vector4 {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Vector4(T xyzw = 0) noexcept
			: Vector4(xyzw, xyzw, xyzw, xyzw) {}
		constexpr explicit Vector4(T x, T y, T z, T w) noexcept
			: m_x(x), m_y(y), m_z(z), m_w(w) {}
		constexpr explicit Vector4(const Vector2< T > &v, T z = 0, T w = 0) noexcept
			: Vector3(v.m_x, v.m_y, z, w) {}
		constexpr explicit Vector4(const Vector3< T > &v, T w = 0)
			: Vector3(v.m_x, v.m_y, v.m_z, w) noexcept {}
		constexpr Vector4(const Vector4< T > &v) noexcept = default;
		constexpr Vector4(Vector4< T > &&v) noexcept = default;
		~Vector4() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Vector4 &operator=(const Vector4< T > &v) = default;
		constexpr Vector4 &operator=(Vector4< T > &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr T operator[](size_t i) const noexcept {
			return (&m_x)[i];
		}
		constexpr T &operator[](size_t i) noexcept {
			return (&m_x)[i];
		}

		//---------------------------------------------------------------------
		// Member Variables
		//---------------------------------------------------------------------

		T m_x;
		T m_y;
		T m_z;
		T m_w;
	};

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Vector4
	//-------------------------------------------------------------------------

	using F32x4 = Vector4< F32 >;
	using S32x4 = Vector4< S32 >;
	using U32x4 = Vector4< U32 >;

	static_assert(sizeof(F32x4) == 16);
	static_assert(sizeof(S32x4) == 16);
	static_assert(sizeof(U32x4) == 16);

	//-------------------------------------------------------------------------
	// Declarations and Definitions: Vector2A
	//-------------------------------------------------------------------------

	template< typename T >
	struct __declspec(align(16)) Vector2A : public AlignedData< Vector2A< T > > {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Vector2A(T xy = 0) noexcept
			: Vector2A(xy, xy) {}
		constexpr explicit Vector2A(T x, T y) noexcept
			: m_x(x), m_y(y) {}
		constexpr Vector2A(const Vector2A< T > &v) noexcept = default;
		constexpr Vector2A(Vector2A< T > &&v) noexcept = default;
		~Vector2A() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Vector2A &operator=(const Vector2A< T > &v) = default;
		constexpr Vector2A &operator=(Vector2A< T > &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr T operator[](size_t i) const noexcept {
			return (&m_x)[i];
		}
		constexpr T &operator[](size_t i) noexcept {
			return (&m_x)[i];
		}

		//---------------------------------------------------------------------
		// Member Variables
		//---------------------------------------------------------------------

		T m_x;
		T m_y;
	};

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Vector2A
	//-------------------------------------------------------------------------

	using F32x2A = Vector2A< F32 >;
	using S32x2A = Vector2A< S32 >;
	using U32x2A = Vector2A< U32 >;

	static_assert(sizeof(F32x2A) == 16);
	static_assert(sizeof(S32x2A) == 16);
	static_assert(sizeof(U32x2A) == 16);

	//-------------------------------------------------------------------------
	// Declarations and Definitions: Vector3A
	//-------------------------------------------------------------------------

	template< typename T >
	struct __declspec(align(16)) Vector3A : public AlignedData< Vector3A< T > > {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Vector3A(T xyz = 0) noexcept
			: Vector3A(xyz, xyz, xyz) {}
		constexpr explicit Vector3A(T x, T y, T z) noexcept
			: m_x(x), m_y(y), m_z(z) {}
		constexpr explicit Vector3A(const Vector2A< T > &v, T z = 0) noexcept
			: Vector3A(v.m_x, v.m_y, z) {}
		constexpr Vector3A(const Vector3A< T > &v) noexcept = default;
		constexpr Vector3A(Vector3A< T > &&v) noexcept = default;
		~Vector3A() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Vector3A &operator=(const Vector3A< T > &v) = default;
		constexpr Vector3A &operator=(Vector3A< T > &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr T operator[](size_t i) const noexcept {
			return (&m_x)[i];
		}
		constexpr T &operator[](size_t i) noexcept {
			return (&m_x)[i];
		}

		//---------------------------------------------------------------------
		// Member Variables
		//---------------------------------------------------------------------

		T m_x;
		T m_y;
		T m_z;
	};

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Vector3A
	//-------------------------------------------------------------------------

	using F32x3A = Vector3A< F32 >;
	using S32x3A = Vector3A< S32 >;
	using U32x3A = Vector3A< U32 >;

	static_assert(sizeof(F32x3A) == 16);
	static_assert(sizeof(S32x3A) == 16);
	static_assert(sizeof(U32x3A) == 16);

	//-------------------------------------------------------------------------
	// Declarations and Definitions: Vector4A
	//-------------------------------------------------------------------------

	template< typename T >
	struct __declspec(align(16)) Vector4A : public AlignedData< Vector4A< T > > {

	public:

		//---------------------------------------------------------------------
		// Constructors and Destructors
		//---------------------------------------------------------------------

		constexpr explicit Vector4A(T xyzw = 0) noexcept
			: Vector4A(xyzw, xyzw, xyzw, xyzw) {}
		constexpr explicit Vector4A(T x, T y, T z, T w) noexcept
			: m_x(x), m_y(y), m_z(z), m_w(w) {}
		constexpr explicit Vector4A(const Vector2A< T > &v, T z = 0, T w = 0) noexcept
			: Vector3A(v.m_x, v.m_y, z, w) {}
		constexpr explicit Vector4A(const Vector3A< T > &v, T w = 0)
			: Vector3A(v.m_x, v.m_y, v.m_z, w) noexcept {}
		constexpr Vector4A(const Vector4A< T > &v) noexcept = default;
		constexpr Vector4A(Vector4A< T > &&v) noexcept = default;
		~Vector4A() = default;

		//---------------------------------------------------------------------
		// Assignment Operators
		//---------------------------------------------------------------------

		constexpr Vector4A &operator=(const Vector4A< T > &v) = default;
		constexpr Vector4A &operator=(Vector4A< T > &&v) = default;

		//---------------------------------------------------------------------
		// Member Methods
		//---------------------------------------------------------------------

		constexpr T operator[](size_t i) const noexcept {
			return (&m_x)[i];
		}
		constexpr T &operator[](size_t i) noexcept {
			return (&m_x)[i];
		}

		//---------------------------------------------------------------------
		// Member Variables
		//---------------------------------------------------------------------

		T m_x;
		T m_y;
		T m_z;
		T m_w;
	};

	//-------------------------------------------------------------------------
	// Type Declarations and Definitions: Vector4A
	//-------------------------------------------------------------------------

	using F32x4A = Vector4A< F32 >;
	using S32x4A = Vector4A< S32 >;
	using U32x4A = Vector4A< U32 >;

	static_assert(sizeof(F32x4A) == 16);
	static_assert(sizeof(S32x4A) == 16);
	static_assert(sizeof(U32x4A) == 16);

	//-------------------------------------------------------------------------
	// Declarations and Definitions: Vector
	//-------------------------------------------------------------------------

	using VECTOR = __m128;
}