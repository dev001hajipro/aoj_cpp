# aoj_cpp

AOJでデータ構造とアルゴリズムの勉強。

## ALDS1 - Introduction to Algorithms and Data Structures 
- http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=ALDS1

## [Memo]分類
- ソート
ALDS1_1_A 挿入ソート
ALDS1_1_B バブルソート

- 3 データ構造の実装
ALDS1_3_A スタックの実装
ALDS1_3_B キューの実装
ALDS1_3_C リンクトリスト


### [Tips] Ubuntuでclangをデフォルトにする方法
- https://stackoverflow.com/questions/7031126/switching-between-gcc-and-clang-llvm-using-cmake


### [Tips] 競技プログラミングのTIPS

C++初心者がC++を使って競技プログラミングするための備忘録のようなもの
- https://gist.github.com/rigibun/7905920

cinの入力について
- http://d.hatena.ne.jp/mintsu123/20130503/1367583661



### [Tips] cinとgetlineの注意点。改行コードを読み捨てるためcin.ignore()を使う
入力データが以下の場合、cin >> nは、9のみ読む。その後の改行コードを読まないので、
cin.ignore()で、改行コードを読み捨てる。

```
9⏎
insert 50⏎
delete 10⏎
```

```c++
    int n;
    cin >> n;     // ここで9を読む
    cin.ignore(); // 改行コードを読み捨てる
    string msg;
    getline(cin, msg); // getlineは改行コードを読み捨てる
```

### [整形]
allman(BSD)スタイル。--suffix=noneで、ファイル上書き。
これをしないとmain.cppの場合、main.cpp.orgが作成される。

```bash
astyle --style=allman --suffix=none main.cpp
```

### ファイル監視してmakeを実行する
Linuxの場合、inotify-toolsをインストールして、bashを書けばよい。

- https://qiita.com/sonodar/items/ddeeb98525ef4c03d48e
