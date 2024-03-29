#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../src/utility/monoid/minMonoid.hpp"
#include "../src/dataStructure/segmentTree.hpp"

#include <iostream>

int main() {
	int n, q; std::cin >> n >> q;
	zawa::segmentTree<zawa::minMonoid<int>> seg(n);
	for (int _ = 0 ; _ < q ; _++) {
		int com; std::cin >> com;
		if (com == 0) {
			int x, y; std::cin >> x >> y;
			seg.set(x, y);
		}
		if (com == 1) {
			int x, y; std::cin >> x >> y;
			std::cout << seg.prod(x, y + 1) << std::endl;
		}
	}
}
