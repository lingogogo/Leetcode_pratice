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
