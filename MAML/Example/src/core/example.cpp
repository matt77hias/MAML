#include <iostream>

#include "simd\simd.hpp"
#include "complex\complex.hpp"
#include "dual\dual.hpp"
#include "hyperbolic\hyperbolic.hpp"

using namespace maml;

int main() {

	SIMD32x4 simd1 = _mm_set_ps1(5.0f);
	SIMD32x4 simd2 = _mm_set_ps1(7.0f);
	SIMD32x4 smul  = simd1 * simd2;
	
	C32 c1(1.0f, 2.0f);
	C32 c2(3.0f, 4.0f);
	C32 cmul = c1 * c2;
	C32 cdiv = c1 / c2;

	D32 d1(1.0f, 2.0f);
	D32 d2(3.0f, 4.0f);
	D32 dmul = d1 * d2;
	D32 ddiv = d1 / d2;

	H32 h1(1.0f, 2.0f);
	H32 h2(3.0f, 4.0f);
	H32 hmul = h1 * h2;

	std::cout << "End";
}