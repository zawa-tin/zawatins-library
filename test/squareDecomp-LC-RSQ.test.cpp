#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../src/utility/monoid/addMonoid.hpp"
#include "../src/dataStructure/squareDecomp.hpp"

#include <iostream>

int main() {
	std::cin.tie(nullptr);
	std::ios::sync_with_stdio(false);
	int N, Q; std::cin >> N >> Q;
	std::vector<long long> A(N);
	for (auto& a : A) {
		std::cin >> a;
	}
	zawa::squareDecomp<zawa::addMonoid<long long>> sq(A);
	for (int _ = 0 ; _ < Q ; _++) {
		int t; std::cin >> t;
		if (t == 0) {
			int p, x; std::cin >> p >> x;
			sq.update(p, x);
		}
		if (t == 1) {
			int l, r; std::cin >> l >> r;
			std::cout << sq.prod(l, r) << std::endl;
		}
	}
}
