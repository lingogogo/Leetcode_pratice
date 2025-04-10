## 學習紀錄
#### Union-find技巧

建立起一個connected component，並且對其做path compression，會將其建立起來的新的union component變成一個較平的樹，在搜索上會較快
發現: edge的順序會影響其建立起來的graph長相會不一樣

#### Digital DP

查找 [0, x] 區間內，符合條件的個數。用非常少的狀態（處理每個digit）來得到需要的下一個狀態，避免疊代每個數字衍生的重複計算。

資料來源: https://yuihuang.com/digit-dp/

## 定義

連通圖（Connected Graph): 整個圖是單一連通分量（即任意兩個節點之間都有路徑）。

連通分量（Connected Component）: 無向圖中的極大連通子圖，即內部所有節點都有路徑相連，但不與外部節點相連。

非連通圖（Disconnected Graph）: 圖中有兩個或以上的連通分量，即存在無法互相連通的節點群組。

強連通分量(strongly connected component): 一張有向圖的「強連通分量」，是所有兩點之間，雙向皆有路可通的連通分量。一張有向圖的強連通分量們，不可能互相重疊。

資料來源: https://web.ntnu.edu.tw/~algo/ConnectedComponent.html
