---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dataStructure/segment-tree.hpp
    title: "segment tree (\u4E00\u70B9\u5909\u66F4\u30FB\u533A\u9593\u6F14\u7B97)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/segment-tree2.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 2 \"src/dataStructure/segment-tree.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n#include <functional>\n\nnamespace zawa {\n\ntemplate <class T, T\
    \ (*op)(T, T), T (*e)()>\nclass segment_tree {\nprivate:\n    int n;\n    std::vector<T>\
    \ dat;\n\n    void update(int pos) {\n        while (pos > 1) {\n            pos\
    \ >>= 1;\n            dat[pos] = op(dat[(pos << 1) | 0], dat[(pos << 1) | 1]);\n\
    \        }\n    }\n\npublic:\n\n    segment_tree(int n) : n(n), dat(2 * n, e())\
    \ {}\n\n    segment_tree(const std::vector<T>& as) : n(as.size()), dat(2 * as.size(),\
    \ e()) {\n        for (int i = 0 ; i < n ; i++) {\n            dat[i + n] = as[i];\n\
    \        }\n        for (int i = n - 1 ; i >= 1 ; i--) {\n            dat[i] =\
    \ op(dat[(i << 1) | 0], dat[(i << 1) | 1]);\n        }\n    }\n\n    void set(int\
    \ pos, T val) {\n        assert(0 <= pos and pos < n);\n        pos += n;\n  \
    \      dat[pos] = val;  \n        update(pos);\n    }\n\n    void apply(int pos,\
    \ T val) {\n        assert(0 <= pos and pos < n);\n        pos += n;\n       \
    \ dat[pos] = op(dat[pos], val);\n        update(pos);\n    }\n\n    T query(int\
    \ l, int r) {\n        assert(0 <= l and l < n);\n        assert(l <= r and r\
    \ <= n);\n        l += n;\n        r += n;\n        T ans = e();\n        while\
    \ (l < r) {\n            if (l & 1) {\n                ans = op(ans, dat[l++]);\n\
    \            }\n            if (r & 1) {\n                ans = op(ans, dat[--r]);\n\
    \            }\n            l >>= 1;\n            r >>= 1;\n        }\n      \
    \  return ans;\n    }\n\n    T all_prod() {\n        return dat[1];\n    }\n\n\
    \    int max_right(int l, const std::function<bool(int)>& f) {\n        assert(0\
    \ <= l and l < n);\n        int r = 2 * n;\n        l += n;\n        T sum = e();\n\
    \        auto down_tree = [&](int v) -> int {\n            while (v < n) {\n \
    \               if (f(op(sum, dat[(v << 1) | 0]))) {\n                    sum\
    \ = op(sum, dat[(v << 1) | 0]);\n                    v = ((v << 1) | 1);\n   \
    \             }\n                else {\n                    v = ((v << 1) | 0);\n\
    \                }\n            }\n            return v - n;\n        };\n   \
    \     int cnt = 0;\n        for ( ; l < r ; cnt++) {\n            if (l & 1) {\n\
    \                if (!f(op(sum, dat[l]))) {\n                    return down_tree(l);\n\
    \                }\n                sum = op(sum, dat[l++]);\n            }\n\
    \            r -= (r & 1);\n            l >>= 1;\n            r >>= 1;\n     \
    \   }\n        while (cnt--) {\n            r <<= 1;\n            if (((r | 1)\
    \ << cnt) <= 2 * n) {\n                if (!f(op(sum, dat[r]))) {\n          \
    \          return down_tree(r);\n                }\n                else {\n \
    \                   sum = op(sum, dat[r++]);\n                }\n            }\n\
    \        }\n        return n;\n    }\n\n    T debug(int pos) {\n        return\
    \ dat[pos];\n    }\n};\n\n} // namespace zawa\n#line 4 \"test/segment-tree2.test.cpp\"\
    \n\n#include <iostream>\n#include <algorithm>\n#line 8 \"test/segment-tree2.test.cpp\"\
    \n\nint op(int x, int y) {\n    return std::min(x, y);\n}\n\nint e() {\n    return\
    \ (int)2e9;\n}\n\nint main() {\n    int n, q; std::cin >> n >> q;\n    std::vector\
    \ as(n, 0);\n    for (auto& a : as) {\n        std::cin >> a;\n    }\n    zawa::segment_tree<int,\
    \ op, e> seg(as);\n    for (int _ = 0 ; _ < q ; _++) {\n        int l, r; std::cin\
    \ >> l >> r;\n        std::cout << seg.query(l, r) << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../src/dataStructure/segment-tree.hpp\"\n\n#include <iostream>\n#include <algorithm>\n\
    #include <vector>\n\nint op(int x, int y) {\n    return std::min(x, y);\n}\n\n\
    int e() {\n    return (int)2e9;\n}\n\nint main() {\n    int n, q; std::cin >>\
    \ n >> q;\n    std::vector as(n, 0);\n    for (auto& a : as) {\n        std::cin\
    \ >> a;\n    }\n    zawa::segment_tree<int, op, e> seg(as);\n    for (int _ =\
    \ 0 ; _ < q ; _++) {\n        int l, r; std::cin >> l >> r;\n        std::cout\
    \ << seg.query(l, r) << std::endl;\n    }\n}\n"
  dependsOn:
  - src/dataStructure/segment-tree.hpp
  isVerificationFile: true
  path: test/segment-tree2.test.cpp
  requiredBy: []
  timestamp: '2022-12-12 17:22:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/segment-tree2.test.cpp
layout: document
redirect_from:
- /verify/test/segment-tree2.test.cpp
- /verify/test/segment-tree2.test.cpp.html
title: test/segment-tree2.test.cpp
---