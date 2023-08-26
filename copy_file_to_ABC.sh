#!/bin/bash

# 引数を取得
NUMBER=$1
LETTER=$2


# 指定されたファイル（b.cppなど）を移動
if [ -f "./current/${LETTER}.cpp" ]; then
  cp "./current/${LETTER}.cpp" "./ABC/${LETTER^^}/${NUMBER}.cpp"
else
  echo "File ./current/${LETTER}.cpp does not exist."
fi

# 指定されたファイル以外を移動（a.cpp, c.cpp, d.cpp, ...)
for i in {a..z}; do
  if [ "$i" == "$LETTER" ]; then
    continue
  fi

  if [ -f "./current/${i}.cpp" ]; then
    cp "./current/${i}.cpp" "./ABC/${i^^}/${NUMBER}.cpp"
  else
    echo "File ./current/${i}.cpp does not exist."
  fi
done
