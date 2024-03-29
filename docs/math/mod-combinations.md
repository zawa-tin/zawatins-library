---
title: mod combinations (組み合わせの数 mod)
documentation_of: //src/math/mod-combinations.hpp
---

## 概要

順列の数、組み合わせの数、重複組み合わせの数 それぞれについて、素数で割った余りを提供します


> 順列の数 $_nP_r$
>
> $n$ 個の区別がつく要素から $r$ 個選択して一列に並べる通り数
>
> 例: $_5P_3\ =\ 20$

> 組み合わせの数 $_nC_r$
>
> $\binom{n}{r}$ の方が一般的な言い方？
>
> $n$ 個の区別がつく要素から $r$ 個選択する通り数
>
> 例: $_6C_2\ =\ 15$

> 重複組み合わせの数 $_nH_r$
>
> $n$ 種類の要素（同じ種類の要素は区別がつかない）がそれぞれ無数にあるなかで、 $r$ 個選択する通り数
>
> （ボールと仕切りのやつ）
>
> 例: $_3H_4\ =\ 15$

## 機能

- `zawa::mod_combinations<mod> mc(std::size_t n)`
	- コンストラクタ
		- `mod`: テンプレート引数
			- `mod`は`n`に対して十分大きい素数である必要があります
		- `n`: 配列の大きさ			
			- 求めたい $_n\text{hoge}_r$ のどの $n$ や $r$ より大きいものを指定してください
	- **計算量** : $O(n\ +\ \log \text{mod})$

- `long long mc.P(std::size_t n, std::size_t r)`
	- $_nP_r$ を`mod`で割った余りを返します 
		- $n < r$ は0を返します
	- **計算量**: $O(1)$

- `long long mc.C(std::size_t n, std::size_t r)`
	- $_nC_r$ を`mod`で割った余りを返します
		- $n < r$ は0を返します
	- **計算量** : $O(1)$

- `long long mc.H(std::size_t n, std::size_t r)`
	- $_nH_r$ を`mod`で割った余りを返します
		- $n < r$ は0を返します
		- $_0H_0$ は配列外参照 ですが、これは1を返します
	- **計算量** : $O(1)$

- `long long mc.F(std::size_t n)`
    - $n!$ 、すなわち $_nP_n$ を返します
    - **単体テストをしていません**
    - **計算量** : $O(1)$

- `long long mc.invF(std::size_t n)`
    - $a*_nP_n\ \equiv\ 1\ \pmod{\text{mod}}$ なる $a$ を返します。
    - **単体テストをしていません**
    - **計算量** : $O(1)$
