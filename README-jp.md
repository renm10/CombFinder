# コンビネーションファインディングアルゴリズム
[![en](https://img.shields.io/badge/lang-en-blue.svg)](https://github.com/renm10/CombFinder/blob/main/README.MD)

この一から作られたアルゴリズムは候補の数字のリストから足したら特定の合計になる全ての数字パターンを挙げることが出来ます。

## 使い方
1. ファイル「numberselect.txt」の**二行目**を編集し候補となる数字をスペースで区切って入力します。  

2. 同じく**四行目**を編集し目指す合計の数字を入力します。

3. ファイルをセーブします

4. 以下でコンパイルします
    ```
    g++ main.cpp
    ```
5. 以下で実行します。
    ```
    ./a.out //For Unix
    ./a.exe //For Windows
    ```

## 例
### サンプルインプット（ユーザー）
numberselect.txt ファイル内:
```
1    Enter the candidate numbers separated by a space: Ex. 1 9 12 14
2    1 2 3 //ユーザー変更可
3    Enter the Sum: Ex. 13
4    4 //ユーザー変更可
```

### サンプルアウトプット（上記の内容をインプットした場合）
```
Combination:
1 1 1 1
Combination:
2 1 1
Combination:
1 2 1
Combination:
3 1
Combination:
1 1 2
Combination:
2 2
Combination:
1 3
``` 