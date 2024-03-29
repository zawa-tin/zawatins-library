#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../src/dataStructure/squareDecomp.hpp"
#include "../src/utility/monoid/addMonoid.hpp"

#include <iostream>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::squareDecomp<zawa::addMonoid<int>> sq(n);
	for (int _ = 0 ; _ < q ; _++) {
		int com, x, y; std::cin >> com >> x >> y;
		if (com == 0) {
			sq.update(x - 1, y);
		}
		if (com == 1) {
			std::cout << sq.prod(x - 1, y) << std::endl;
		}
	}
}
