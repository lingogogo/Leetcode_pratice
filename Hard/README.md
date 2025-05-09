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

建立C表，並且使用巴斯卡定理建立 網址: https://tpdjdje0525.medium.com/%E5%B7%B4%E6%96%AF%E5%8D%A1%E5%AE%9A%E7%90%86-%E6%9C%89%E4%BB%80%E9%BA%BC%E6%84%8F%E7%BE%A9-21690183d2d1

並且根據oddCnt and evenCnt 排列組合去計算結果

網址: https://leetcode.com/problems/count-number-of-balanced-permutations/editorial

## 定義

連通圖（Connected Graph): 整個圖是單一連通分量（即任意兩個節點之間都有路徑）。

連通分量（Connected Component）: 無向圖中的極大連通子圖，即內部所有節點都有路徑相連，但不與外部節點相連。

非連通圖（Disconnected Graph）: 圖中有兩個或以上的連通分量，即存在無法互相連通的節點群組。

強連通分量(strongly connected component): 一張有向圖的「強連通分量」，是所有兩點之間，雙向皆有路可通的連通分量。一張有向圖的強連通分量們，不可能互相重疊。

資料來源: https://web.ntnu.edu.tw/~algo/ConnectedComponent.html


