#pragma once

namespace zawa {

template <class T>
struct xorMonoid {
	using valueType = T;
	static constexpr valueType identity{};
	static valueType operation(const valueType& a, const valueType& b) {
		return (a ^ b);
	}
};

} // namespace zawa
