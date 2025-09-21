## 學習紀錄
#### Union-find技巧

建立起一個connected component，並且對其做path compression，會將其建立起來的新的union component變成一個較平的樹，在搜索上會較快
發現: edge的順序會影響其建立起來的graph長相會不一樣

#### Digital DP

查找 [0, x] 區間內，符合條件的個數。用非常少的狀態（處理每個digit）來得到需要的下一個狀態，避免疊代每個數字衍生的重複計算。

資料來源: https://yuihuang.com/digit-dp/

#### Fenwick Tree

可以快速處理 前綴和（Prefix Sum）或頻率統計問題 的資料結構，尤其是在需要頻繁修改與查詢的動態情況下非常有效。
並且透過lowbit(i)，進行binary indexed tree(binary指的是二進位)。
![image](https://github.com/user-attachments/assets/b636ec5e-2c04-4322-9e6d-6117bcc8d0ba)

這張圖就是BIT常見的樣子，下面則為每個節點所包含的資訊多寡。

tree[1] => 管理 [1]

tree[2] => 管理 [1,2]

tree[3] => 管理 [3]

tree[4] => 管理 [1,2,3,4]

tree[5] => 管理 [5]

tree[6] => 管理 [5,6]

tree[7] => 管理 [7]

tree[8] => 管理 [1,2,3,4,5,6,7,8]

1. 點更新(單點修改)
2. 區間查詢(前綴和): 就是透過lowbit()的方式，可以找其所有父代的父代資訊。

進行i + lowbit()，表示找下一個更大的範圍，比如說tree[4]更新完後，他就會找tree[8](因為tree[8]通常會包含更多的資訊)。

進行i - lowbit()，這個動作通常都是找父節點，比如說tree[3]->tree[2]，如果將裡面的資訊相加，就是1-3的資訊量，但對於tree[4]，他不需要再往上找，就有1-4資訊量


網址:https://hackmd.io/@wiwiho/cp-note/%2F%40wiwiho%2FCPN-binary-indexed-tree

#### 使用C數找其排列組合

3343. Count Number of Balanced Permutations

建立C表，並且使用八死卡一個connected component，並且對其做path compression，會將其建立起來的新的union component變成一個較平的樹，在搜索上會較快
發現: edge的順序會影響其建立起來的graph長相會不一樣

## 定義

連通圖（Connected Graph): 整個圖是單一連通分量（即任意兩個節點之間都有路徑）。

連通分量（Connected Component）: 無向圖中的極大連通子圖，即內部所有節點都有路徑相連，但不與外部節點相連。

非連通圖（Disconnected Graph）: 圖中有兩個或以上的連通分量，即存在無法互相連通的節點群組。

強連通分量(strongly connected component): 一張有向圖的「強連通分量」，是所有兩點之間，雙向皆有路可通的連通分量。一張有向圖的強連通分量們，不可能互相重疊。

資料來源: https://web.ntnu.edu.tw/~algo/ConnectedComponent.html

#### 1912 note

`std::map` 可以直接使用 `std::pair<int, int>` 作為 key，但 `std::unordered_map` **預設情況下不行**。

-----
`std::map` 的底層是**平衡二元搜尋樹**，它依賴一個嚴格的**弱排序 (strict weak ordering)** 規則來排列 key。對於 `std::pair`，C++ 標準函式庫已經預設實現了 `operator<`。

`std::pair` 的 `operator<` 是這樣運作的：

1.  首先比較 `first` 元素。
2.  如果 `first` 元素相等，就比較 `second` 元素。

這正是 `std::map` 所需要的排序規則，所以可以直接將 `std::pair` 作為 key。

##### **為什麼 `std::unordered_map` 不行？**

`std::unordered_map` 的底層是**哈希表**，它依賴一個**哈希函式 (hash function)** 來將 key 轉換成一個索引值。

`std::unordered_map` 預設只為**基本型別**（如 `int`、`char`、`string` 等）提供了內建的哈希函式。但對於像 `std::pair` 這種**複合型別**，C++ 標準函式庫並沒有提供預設的哈希函式。

如果直接嘗試用 `std::unordered_map<pair<int, int>, ...>`，編譯器會報錯，找不到對應的哈希函式。


