---
title: disjointSetUnion (互いに素な集合の森）
documentation_of: //src/dataStructure/disjointSetUnion.hpp
---

## 概要
```
zawa::disjointSetUnion(std::size_t n)
```

 Union-Findアルゴリズムを使用し、互いに素な集合の属 $\{S_1,\ S_2,\ \dots ,\ S_k\}$ に対し以下のクエリを処理することができるデータ構造
 - $x$ を含む集合と $y$ を含む集合を合併して和集合を生成する
 - $x$ と $y$ が同じ集合に含まれているかを確認する

集合に含まれる元を一つ、代表元とすることでそれぞれの集合を識別する。互いに素(どの集合の組も和集合が空集合)なので、代表元のとり方は重要ではない。

## 機能

#### コンストラクタ

```
zawa::disjointSetUnion(std::size_t n)
```

$S_0 = \\{ 0 \\}, S_1 = \\{ 1 \\}, \dots, S_{n - 1} = \\{ n - 1 \\}$ と集合族を生成、初期化する

#### メンバ

**leader**
```
int leader(int x)
```

元 $x$ が含まれる集合の代表元を返す

<br/>

**merge**
```
void merge(int x, int y)
```

元 $x$ を含む集合と元 $y$ を含む集合を合併する

<br/>

**same**
```
bool same(int x, int y)
```

元 $x$ と $y$ が同じ集合族に含まれているかを判定する

<br/>

**size**
```
int size(int x)
```

元 $x$ を含む集合の要素数を返す

<br/>

**groups**
```
std::vector<std::vector<int>> groups()
```

現在の集合属を返す。元に対して昇順とは限らない

<br/>

## 計算量

TODO: 書く

## 参考

[AC Library](https://atcoder.github.io/ac-library/document_ja/dsu.html)
- メンバの名前等はこちらに揃えています

[アルゴリズムイントロダクション 第二巻](https://www.kindaikagaku.co.jp/book_list/detail/9784764904071/)
- ドキュメントの文言はこちらを参考にしました
