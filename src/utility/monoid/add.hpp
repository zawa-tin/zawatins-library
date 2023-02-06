#pragma once

namespace zawa {

template <class T>
struct add_monoid {
	using value_type = T;
	static constexpr T identity{};
	static T operation(const T& a, const T& b) {
		return a + b;
	}
};

} // namespace zawa
