#include "algebra\complex.hpp"
#include "algebra\dual.hpp"
#include "algebra\hyperbolic.hpp"
#include "simd\vector.hpp"

#include "constexpr\math.hpp"

#include <iostream>

using namespace maml;

int main() {

	const SIMD32x4 simd1 = _mm_set_ps1(5.0f);
	const SIMD32x4 simd2 = _mm_set_ps1(7.0f);
	const SIMD32x4 smul  = simd1 * simd2;
	
	constexpr C32 c1(1.0f, 2.0f);
	constexpr C32 c2(3.0f, 4.0f);
	constexpr C32 cmul = c1 * c2;
	constexpr C32 cdiv = c1 / c2;

	constexpr D32 d1(1.0f, 2.0f);
	constexpr D32 d2(3.0f, 4.0f);
	constexpr D32 dmul = d1 * d2;
	constexpr D32 ddiv = d1 / d2;

	constexpr H32 h1(1.0f, 2.0f);
	constexpr H32 h2(3.0f, 4.0f);
	constexpr H32 hmul = h1 * h2;

	constexpr F32 s = maml::sin(3.14f);

	return 0;
}