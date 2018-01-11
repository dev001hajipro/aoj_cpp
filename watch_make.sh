#!/bin/bash -eu

# bashのオプションは、以下コマンドで確認できる
# bash -c "help set"
# -e : エラーがあったら、(exit 0以外)止まる
# -u : 未定義変数を使ったらエラーになる

    
trap "exit 0" QUIT # 3) SIGQUIT


echo "sleep 10..."
sleep 10
echo "end"

