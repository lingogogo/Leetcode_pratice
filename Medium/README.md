#### 快速冪

x^13 -> x = 3, y = 13

13 -> 1101 (二進位制)

| y   | y % 2 | 操作              | ret     | mul        |
|-----|--------|---------------------|----------|-------------|
| 13  | 1      | ret ×= 3            | 3        | 3 → 9       |
| 6   | 0      | 無操作              | 3        | 9 → 81      |
| 3   | 1      | ret ×= 81           | 243      | 81 → 6561   |
| 1   | 1      | ret ×= 6561         | 1594323  | 6561 → ...  |
| 0   | -      | 結束                | 1594323  |             |


網址:https://zh.wikipedia.org/zh-tw/%E4%BA%8C%E8%BF%9B%E5%88%B6

#### Dijkstra algorithms
Use BFS + priority_queue;

因為單純的nested loop會有相對的更新方向(左下到右上)，這個動作會使得問題的值在不是最佳化的時間下更新，導致結果不符合，所以使用greedy algorithms(priority queue)來搜尋最短路徑。

又可以稱作Best-First Search

#### 3408 improvement note

---

##### **1. 關鍵效能瓶頸：`edit` 與 `rmv` 函式**

| 舊有的程式碼 | 優化後的程式碼 | 說明 |
| :--- | :--- | :--- |
| `edit` 和 `rmv` 使用 `for` 迴圈來遍歷 `std::set`。 | `edit` 和 `rmv` 使用 `std::set` 的 `erase` 和 `insert` 方法，並透過 `unordered_map` 來快速定位。 | 這是最主要的效能差異。`for` 迴圈的**時間複雜度是 O(n)**，當任務數量 `n` 很大時，會導致程式超時。而 `std::set` 的 `erase` 和 `insert` 方法的**時間複雜度是 O(log n)**，效率更高。|

---

##### **2. 資料結構設計**

| 舊的程式碼 | 優化後的程式碼 | 說明 |
| :--- | :--- | :--- |
| 使用 `unordered_map<int, int> task_user`，只儲存 `taskId` 到 `userId` 的映射。 | 使用 `unordered_map<int, pair<int, int>> task_user_info`，儲存 `taskId` 到 `{priority, userId}` 的映射。 | 舊有的 `unordered_map` 無法儲存優先級，因此在 `edit` 和 `rmv` 函式中，舊有版本必須透過遍歷 `set` 來找到對應的優先級，這造成了效能瓶頸。修改後的版本則將所有任務資訊都儲存在 `map` 中，方便快速查找。|

---

##### **3. `execTop` 函式的處理邏輯**

| 舊有程式碼 | 優化後的程式碼 | 說明 |
| :--- | :--- | :--- |
| 在 `execTop` 中，舊版本使用 `task_user[pri_task_set.begin()->second]` 來取得 `userId`。 | 在 `execTop` 中，新版本先取得 `taskId`，再用 `taskId` 去 `task_user_info` 查詢 `userId`。 | 雖然原本的寫法也能運作，但修改後的版本在邏輯上更清晰。因為 `pri_task_set` 儲存的是 `{priority, taskId}`，先從 `set` 取得 `taskId`，再用 `taskId` 去 `map` 找詳細資訊，符合一般資料庫查詢的思維模式。|

---

##### **總結**

程式碼主要的問題在於**沒有充分利用資料結構的優勢**。`std::set` 雖然是有序的，但要透過線性搜尋來尋找特定元素，其效能與 `std::vector` 相去不遠。

修改版則結合了 `std::set` 的**自動排序**功能和 `std::unordered_map` 的**快速查找**功能，將兩者的優點結合起來，從而大幅提升了整體效能。

本身set資料結構是使用balanced binary search，所以其符合BST性質

1. 以左邊節點 ( left node ) 作為根的子樹 ( sub-tree ) 的所有值都小於根節點 ( root )
2.  以右邊節點 ( right node ) 作為根的子樹 ( sub-tree ) 的所有值都大於根節點 ( root )
3.  任意節點 ( node ) 的左、右子樹也分別符合 BST 的定義
4.  不存在任何鍵值 ( key/value ) 相等的節點。

#### 3508 note

只有vector, array, deque這一種資料結構可以使用upper_bound lower_bound找上下限的概念去找其中間元素有幾個。(Random Access Iterator)

其他迭代器因為記憶體不連續，並不支持使用記憶體互減的方式獲得中間有多少元素值。

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


