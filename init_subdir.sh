#!/bin/bash

help () {
    echo "このスクリプトは、１つ引数が必要です。"
    echo "例: $0 dirname"
    echo "以下の作業が面倒なので作りました。"
    echo "1.引数の名前でディレクトリーを作成します。"
    echo "2.サブディレクトリーにCMakeLists.txtを作成します。"
    echo "3.ルートのCMakeLists.txtに追記します。"
    echo "4.単純なのmain.cppを作成します。"
    echo "5. 'cmake .'コマンドを実行します。"
}

if [ $# = 0 ]; then
    echo "ディレクトリーを入力してください。"
    echo "$0 dirname"
    help
    exit 1
fi

name=$1

echo $name

# 引数のディレクトリーを作成
if [ -d $name ]; then
    rm -r $name
fi
echo "ディレクトリー($name)作成"
mkdir $name



# CMakeLists.txtを作成し、add_executable(dirname main.cpp)を書き込む
echo "CMakeLists.txt作成"
echo "add_executable(${name} main.cpp)"
echo "add_executable(${name} main.cpp)" > $name/CMakeLists.txt



# ルートのCMakeLists.txtにadd_subdirectory(dirname)を追加
echo "このディレクトリーのCMakeLists.txtにadd_subdirectory(${name})を追記"
echo "add_subdirectory(${name})" >> CMakeLists.txt


# main.cppの作成
cat <<EOF > $name/main.cpp
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cout << "XXXXXXXXXXXXXXXXXXhello worldXXXXXXXXXXXXX" << endl;
    return 0;
}
EOF


# cmake .の実行
cmake . 
