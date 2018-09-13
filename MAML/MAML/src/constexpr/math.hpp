#pragma once

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------

#include <cstddef>
#include <type_traits>

//-----------------------------------------------------------------------------
// Factorial
//-----------------------------------------------------------------------------
namespace cm::details {

	template< typename T, 
              typename = std::enable_if_t< std::is_unsigned_v< T > > >
    struct Factorial {

        constexpr T operator()(T x) const noexcept {
            T result(1);
            for (T i = 2u; i <= x; ++i) {
                result *= i;
            }
            return result;
        }
    };
}

namespace cm {

	template< typename T >
	constexpr T factorial(T x) noexcept {
		return details::Factorial< T >()(x);
	}
}

//-----------------------------------------------------------------------------
// Power
//-----------------------------------------------------------------------------  
namespace cm::details {

	template< typename T, typename E,
              typename = std::enable_if_t< std::is_unsigned_v< E > > >
    struct Power {
    
        constexpr T operator()(T x, E e) const noexcept {
            T result(1);
            for (std::size_t i = 0u; i < e; ++i) {
                result *= x;
            }
            return result;
        }
    };
}

namespace cm {

	template< typename T, typename E >
	constexpr T power(T x, E e) noexcept {
		return details::Power< T, E >()(x, e);
	}
}

//-----------------------------------------------------------------------------
// Exponential Function
//-----------------------------------------------------------------------------
namespace cm::details {

	template< typename T, std::size_t N,
		      typename = std::enable_if_t< std::is_floating_point_v< T > > >
	struct Exponential {

		constexpr T operator()(T x) const noexcept {
			T result(0);
			for (std::size_t i = 0u; i < N; ++i) {
				result += power(x, i) / factorial(i);
			}
			return result;
		}
	};
}

namespace cm {

	template< typename T, std::size_t N = 10 >
	constexpr T exp(T x) noexcept {
		return details::Exponential< T, N >()(x);
	}
}

//-----------------------------------------------------------------------------
// Sine
//-----------------------------------------------------------------------------
namespace cm::details {

	template< typename T, std::size_t N, 
              typename = std::enable_if_t< std::is_floating_point_v< T > > >
    struct Sine {
        
        constexpr T operator()(T x) const noexcept {
            T result(0);
            for (std::size_t i = 0u; i < N; ++i) {
                result += power(-1, i) * power(x, 2u * i + 1u) / factorial(2u * i + 1u);        
            }
            return result;
        }
    };
}

namespace cm {

	template< typename T, std::size_t N = 10 >
	constexpr T sin(T x) noexcept {
		return details::Sine< T, N >()(x);
	}
}
    
//-----------------------------------------------------------------------------
// Cosine
//-----------------------------------------------------------------------------
namespace cm::details {

	template< typename T, std::size_t N,
		      typename = std::enable_if_t< std::is_floating_point_v< T > > >
		struct Cosine {

		constexpr T operator()(T x) const noexcept {
			T result(0);
			for (std::size_t i = 0u; i < N; ++i) {
				result += power(-1, i) * power(x, 2u * i) / factorial(2u * i);
			}
			return result;
		}
	};
}

namespace cm {

	template< typename T, std::size_t N = 10 >
	constexpr T cos(T x) noexcept {
		return details::Cosine< T, N >()(x);
	}
}
