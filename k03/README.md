# 課題3 レポート
bb35319025 新開　大生


## 課題  

以下の2つのアルゴリズムで文字列を検索するプログラムを作成する。  
- 力ずく法
- BM法

1. 使用するデータ  
以下のデータを使用する。ただし、検索対象文字列、検索する文字列は変更しても良い。  
    - StrOriginal: 検索対象データ
    - StrKey: 検索する文字列

2. 必須問題：実装する関数  
本課題では、以下の関数を実装する。C言語の標準ライブラリは使用しないこと。  
    (1) ForceSearch: 力ずく法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  

    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

    (2) BMSearch: BM法で文字列を検索する。  
    [入力]  
    - char text[]: 検索対象文字列  
    - char key[]: 検索する文字列  
 
    [出力]  
    - return値：検索する文字列が出現した場所(ポインタ)。ただし、検索する文字列が見つからない場合はNULL。  

3. 補助関数  
なし

## ソースコードの説明
力ずく法

16行目　    探索対象文字列の先頭から順番に探索対象がなくなるまで以下の処理を繰り返す。

17行目      キーの先頭文字から順番に、キーの最後の文字まで以下の処理を繰り返す。

18～26行目  比較場所の文字を比較する。一致している場合、すべて一致(pos=key_len - 1)であれば終了。不一致の場合は比較開始位置をずらす(break)

29行目　    比較位置が探索対象文字列の最後を超えたらNULLを返す。

BM法

40～45行目　不一致となった場合、文字毎にどれだけずらすかを計算するテーブルを用意する。

47行目　    探索対象文字列の探索対象がなくなるまで以下の処理を繰り返す。

49行目　最初の比較場所をキー文字列の末尾にし、キー文字列の末尾から前に向かって文字列を比較する。

50～58行目　一致した場合は、次の文字を比較する。不一致の場合、文字毎に決められた量だけ、比較の開始点をずらす。

60～64行目　比較開始位置が前回の開始位置より前か同じ場合、比較開始位置を一つ右にずらす。

51～53行目　キー文字列がすべて一致したならば比較位置を返す。

66行目　比較位置が探索文字列の最後を超えたらNULLを返す。

## 出力結果

```
Force Search. Find keyword at:wind in my hair.
BM Search. Find keyword at:wind in my hair.
```

## 修正履歴

