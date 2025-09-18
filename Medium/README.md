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

### **1. 關鍵效能瓶頸：`edit` 與 `rmv` 函式**

| 舊有的程式碼 | 優化後的程式碼 | 說明 |
| :--- | :--- | :--- |
| `edit` 和 `rmv` 使用 `for` 迴圈來遍歷 `std::set`。 | `edit` 和 `rmv` 使用 `std::set` 的 `erase` 和 `insert` 方法，並透過 `unordered_map` 來快速定位。 | 這是最主要的效能差異。`for` 迴圈的**時間複雜度是 O(n)**，當任務數量 `n` 很大時，會導致程式超時。而 `std::set` 的 `erase` 和 `insert` 方法的**時間複雜度是 O(log n)**，效率更高。|

---

### **2. 資料結構設計**

| 舊的程式碼 | 優化後的程式碼 | 說明 |
| :--- | :--- | :--- |
| 使用 `unordered_map<int, int> task_user`，只儲存 `taskId` 到 `userId` 的映射。 | 使用 `unordered_map<int, pair<int, int>> task_user_info`，儲存 `taskId` 到 `{priority, userId}` 的映射。 | 舊有的 `unordered_map` 無法儲存優先級，因此在 `edit` 和 `rmv` 函式中，舊有版本必須透過遍歷 `set` 來找到對應的優先級，這造成了效能瓶頸。修改後的版本則將所有任務資訊都儲存在 `map` 中，方便快速查找。|

---

### **3. `execTop` 函式的處理邏輯**

| 你的程式碼 | 我優化後的程式碼 | 說明 |
| :--- | :--- | :--- |
| 在 `execTop` 中，舊版本使用 `task_user[pri_task_set.begin()->second]` 來取得 `userId`。 | 在 `execTop` 中，新版本先取得 `taskId`，再用 `taskId` 去 `task_user_info` 查詢 `userId`。 | 雖然原本的寫法也能運作，但修改後的版本在邏輯上更清晰。因為 `pri_task_set` 儲存的是 `{priority, taskId}`，先從 `set` 取得 `taskId`，再用 `taskId` 去 `map` 找詳細資訊，符合一般資料庫查詢的思維模式。|

---

### **總結**

程式碼主要的問題在於**沒有充分利用資料結構的優勢**。`std::set` 雖然是有序的，但要透過線性搜尋來尋找特定元素，其效能與 `std::vector` 相去不遠。

修改版則結合了 `std::set` 的**自動排序**功能和 `std::unordered_map` 的**快速查找**功能，將兩者的優點結合起來，從而大幅提升了整體效能。


