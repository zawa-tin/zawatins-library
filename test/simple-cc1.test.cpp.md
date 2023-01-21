---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/simple/connected-components.hpp
    title: "connected components (\u9023\u7D50\u6210\u5206\u5206\u89E3 simple ver)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D
  bundledCode: "#line 1 \"test/simple-cc1.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D\"\
    \n\n#line 2 \"src/graph/simple/connected-components.hpp\"\n\n#include <vector>\n\
    #include <stack>\n\nnamespace zawa {\n\nclass connected_components {\nprivate:\n\
    \    std::vector<int> ids;\n    std::vector<std::vector<int>> groups;    \n\n\t\
    void build(const std::vector<std::vector<int>>& G) {\n\t\tint id = 0;\n\t\tfor\
    \ (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tif (ids[i] == -1) {\n\t\t\t\t\
    ids[i] = id;\n\t\t\t\tstd::stack<int> stk({ i });\t\t\n\t\t\t\twhile (stk.size())\
    \ {\n\t\t\t\t\tint v = stk.top();\n\t\t\t\t\tstk.pop();\n\t\t\t\t\tfor (auto x\
    \ : G[v]) {\n\t\t\t\t\t\tif (ids[x] == -1) {\n\t\t\t\t\t\t\tids[x] = id;\n\t\t\
    \t\t\t\t\tstk.push(x);\n\t\t\t\t\t\t}\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tid++;\n\
    \t\t\t}\n\t\t}\n\t\tgroups = std::vector(id, std::vector(0, 0));\n\t\tfor (int\
    \ i = 0 ; i < (int)ids.size() ; i++) {\n\t\t\tgroups[ids[i]].push_back(i);\n\t\
    \t}\n\t}\n\npublic:\n\n    connected_components(const std::vector<std::vector<int>>&\
    \ G) : ids(G.size(), -1) {\n\t\tbuild(G);\n    }\n\n\ttemplate <class cost_type>\n\
    \tconnected_components(const std::vector<std::vector<std::pair<int, cost_type>>>&\
    \ G) : ids(G.size(), -1) {\n\t\tstd::vector tmp_G(G.size(), std::vector(0, 0));\n\
    \t\tfor (int i = 0 ; i < (int)G.size() ; i++) {\n\t\t\tfor (auto [x, _] : G[i])\
    \ {\n\t\t\t\ttmp_G[i].push_back(x);\n\t\t\t}\n\t\t}\n\t\tbuild(tmp_G);\n\t}\n\n\
    \    int &operator [](int i) {\n        return ids[i];\n    }\n\n\tstd::size_t\
    \ size() {\n\t\treturn groups.size();\n\t}\n\n\tstd::size_t size(int x) {\n\t\t\
    return groups[ids[x]].size();\n\t}\n\n    const std::vector<std::vector<int>>\
    \ &comps() {\n        return groups;\n    }\n\n    const std::vector<int> &comp(int\
    \ id) {\n        return groups[id];\n    }\n\n    bool same(int i, int j) {\n\
    \        return ids[i] == ids[j];\n    }\n};\n\ntemplate <class cost_type>\nconnected_components\
    \ weighted_cc(const std::vector<std::vector<std::pair<int, cost_type>>>& G) {\n\
    \    std::vector tmp_G(G.size(), std::vector(0, 0));\n    for (std::size_t i =\
    \ 0 ; i < G.size() ; i++) {\n        for (auto x : G[i]) {\n            tmp_G[i].push_back(x.first);\n\
    \        }\n    }\n    return connected_components(tmp_G);\n}\n\n} // namespace\
    \ zawa\n#line 4 \"test/simple-cc1.test.cpp\"\n\n#include <cassert>\n#line 7 \"\
    test/simple-cc1.test.cpp\"\n#include <iostream>\n\nint main() {\n    int n, m;\
    \ std::cin >> n >> m;\n    std::vector G1(n, std::vector(0, 0));\n    std::vector\
    \ G2(n, std::vector(0, std::pair(0, 0)));\n    for (int _ = 0 ; _ < m ; _++) {\n\
    \        int s, t; std::cin >> s >> t;\n        G1[s].push_back(t);\n        G1[t].push_back(s);\n\
    \        G2[s].emplace_back(t, 0);\n        G2[t].emplace_back(s, 0);\n    }\n\
    \    zawa::connected_components cc1(G1);\n\tzawa::connected_components cc2(G2);\n\
    \    int q; std::cin >> q;\n    for (int _ = 0 ; _ < q ; _++) {\n        int s,\
    \ t; std::cin >> s >> t;\n        assert(cc1.same(s, t) == cc2.same(s, t));\n\
    \        assert(cc1.same(s, t) == (cc1[s] == cc1[t]));\n        assert(cc2.same(s,\
    \ t) == (cc2[s] == cc2[t]));\n        std::cout << (cc1.same(s, t) ? \"yes\" :\
    \ \"no\") << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_D\"\
    \n\n#include \"../src/graph/simple/connected-components.hpp\"\n\n#include <cassert>\n\
    #include <vector>\n#include <iostream>\n\nint main() {\n    int n, m; std::cin\
    \ >> n >> m;\n    std::vector G1(n, std::vector(0, 0));\n    std::vector G2(n,\
    \ std::vector(0, std::pair(0, 0)));\n    for (int _ = 0 ; _ < m ; _++) {\n   \
    \     int s, t; std::cin >> s >> t;\n        G1[s].push_back(t);\n        G1[t].push_back(s);\n\
    \        G2[s].emplace_back(t, 0);\n        G2[t].emplace_back(s, 0);\n    }\n\
    \    zawa::connected_components cc1(G1);\n\tzawa::connected_components cc2(G2);\n\
    \    int q; std::cin >> q;\n    for (int _ = 0 ; _ < q ; _++) {\n        int s,\
    \ t; std::cin >> s >> t;\n        assert(cc1.same(s, t) == cc2.same(s, t));\n\
    \        assert(cc1.same(s, t) == (cc1[s] == cc1[t]));\n        assert(cc2.same(s,\
    \ t) == (cc2[s] == cc2[t]));\n        std::cout << (cc1.same(s, t) ? \"yes\" :\
    \ \"no\") << std::endl;\n    }\n}\n"
  dependsOn:
  - src/graph/simple/connected-components.hpp
  isVerificationFile: true
  path: test/simple-cc1.test.cpp
  requiredBy: []
  timestamp: '2023-01-08 00:30:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/simple-cc1.test.cpp
layout: document
redirect_from:
- /verify/test/simple-cc1.test.cpp
- /verify/test/simple-cc1.test.cpp.html
title: test/simple-cc1.test.cpp
---