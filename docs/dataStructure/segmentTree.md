---
title: segmentTree (一点更新・区間演算セグ木)
documentation_of: //src/dataStructure/segmentTree.hpp
---

## 概要

セグメント木を用いて列上のクエリを高速を処理します。

#### セグメント木について

2冪の区間についての区間和を保持することで要素の更新に $\log$ かけるかわりに任意の区間和を $\log$ にする。
- 詳しくはTODO?

#### クエリについて

[モノイド](https://ja.wikipedia.org/wiki/%E3%83%A2%E3%83%8E%E3%82%A4%E3%83%89) $(S, \oplus, \text{id})$ と $S$ の要素からなる長さ $N$ の数列 $A$ について

- `set i p`: $A_i\ \leftarrow\ p$
- `action i p`: $A_i\ \leftarrow A_i \oplus p$
- `prod l r` : get $\displaystyle \bigoplus_{i = l}^r A_i$

のクエリを処理することができる

## 機能

#### コンストラクタ

```
(1) zawa::segmentTree<monoid>()
(2) zawa::segmentTree<monoid>(int _N)
(3) zawa::segmentTree<monoid>(const std::vector<monoid::valueType>& A)
```

テンプレート引数`monoid`について
- 以下の機能をもたせた`struct`を用意してください
	- `using value_type`: $S$ の型
	- `static constexpr value_type identity` : モノイドの単位元 $\text{id}$
	- `static value_type operation(const value_type& a, const value_type& b)`: $a\oplus b$ を返す関数

**(1)**
デフォルトコンストラクタ

<br />

**(2)**

$A$ を長さ $N$ で各要素を`monoid::identity`で初期化する

**計算量**

$O(N)$

<br />

**(3)**

$A$ を引数に与えた `std::vector`で初期化する

**計算量**

$O(\mid A\mid)$

以降、 $\mid A \mid\ =\ N$ とする

<br />

#### メンバ関数

**set**
```
void set(std::size_t pos, const monoid::value_type& value)
```

$A_{\text{pos}}\ \leftarrow\ \text{value}$ とする

**制約**

$0\ \le\ \text{pos}\ <\ N$

**計算量**

$O(\log N)$

<br />

**update**
```
T update(std::size_t pos, const monoid::value_type& value)
```

$A_{\text{pos}}\ \leftarrow\ A_{\text{pos}} \oplus \text{value}$ とする

**制約**

$0\ \le\ \text{pos}\ <\ N$

**計算量**

$O(\log N)$

<br />

**prod**
```
T prod(std::size_t l, std::size_t r) const
```
$\displaystyle \bigoplus_{i = l}^r A_i$  を返す

**制約**

$0\ \le\ l\ <\ N$

$l\ \le\ r\ \le\ N$

**計算量**

$O(\log N)$

<br />

**maxRight**
```
int maxRight<functionType>(int l, const function_type& f) const
```

単調性を持つブール関数 $f$ について、 $\displaystyle f(\bigoplus_{i = l}^r A_i)\ =\ \text{false}$ となる最小の $r$ を返す。


`functionType`は`std::function<bool(monoid::value_type)>`

**制約**

$0\ \le\ l\ <\ N$

**計算量**

$O(\log N)$

<br />

**minLeft**
```
int min_left<functionType>(int r, const function_type& f) const
```

単調性を持つブール関数 $f$ について、 $\displaystyle f(\bigoplus_{i = l}^r A_i)\ =\ \text{false}$ となる最大の $l$ を返す。

`functionType`は`std::function<bool(monoid::value_type)>`

**制約**

$0\ \le\ r\ <\ N$

**計算量** 

$O(\log N)$

<br />

##  参考

- [お手軽非再帰 Segment Tree の書き方](https://hackmd.io/@tatyam-prime/rkA5wJMdo)
- [非再帰セグ木サイコー！ 一番すきなセグ木です](https://hcpc-hokudai.github.io/archive/structure_segtree_001.pdf)
