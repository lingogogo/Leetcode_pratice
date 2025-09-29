Leetcode account: https://leetcode.com/u/CianSyue/


![LeetCode Stats](https://leetcard.jacoblin.cool/CianSyue?theme=white&extension=activity)
# Leetcode-answer
Daily Update 

practice C or C++ coding

# Note
int snprintf ( char * str, size_t size, const char * format, ... );
char** arr = (char**)malloc(sizeof(char*)*r);

A hash table uses a hash function to compute an index, also called a hash code, into an array of buckets or slots, from which the desired value can be found. During lookup, the key is hashed and the resulting hash indicates where the corresponding value is stored.

Binary search: arrangeCoins.c

Find target by high and low values.

Difference array: Difference array D[i] of a given array A[i] is defined as D[i] = A[i]-A[i-1] (for 0 < i < N ) and D[0] = A[0] considering 0 based indexing. Difference array can be used to perform range update queries “l r x” where l is left index, r is right index and x is value to be added and after all queries you can return original array from it. Where update range operations can be performed in O(1) complexity.

If the problem time complexity is too large, binary search might be the better solution.

常見的場景應用: 搜尋排序數組、查找邊界值、優化競技類問題、矩陣搜尋 (Leetcode problem: Zero Array Transformation II, minimum time to repair cars)

這是一個關於現代程式語言中**最常用且最靈活的特性**之一：Lambda 函式 (Lambda Function)，也被稱為匿名函式 (Anonymous Function) 或閉包 (Closure)。

我會詳細解釋 Lambda 函式的本質、結構，以及它在 C++ 等語言中的細節應用。

-----

## 什麼是 Lambda 函式？

**Lambda 函式是可以在程式碼中「就地 (Inline)」定義的小型、匿名函式。**

它是一種無需明確命名、無需單獨定義函式原型，就能夠直接作為表達式使用的函式。

可以把它想像成一個\*\*「即拋即用的小工具」\*\*：當需要一個簡單的、臨時性的操作（例如排序、過濾或單次計算）時，不需要大費周章地寫一個完整的具名函式，只需要在需要的地方寫一個 Lambda 表達式即可。

-----

## Lambda 函式的核心結構（以 C++ 為例）

在 C++ 中，Lambda 函式的結構是固定的，由三個關鍵部分組成：

### 1\. 捕獲列表 (Capture List) - `[]`

這是 Lambda 函式最特別、最複雜的部分。它決定了 Lambda 函式可以**存取其定義範圍外哪些變數**。

| 語法 | 意義 | 範例 |
| :--- | :--- | :--- |
| **`[]`** | **不捕獲**任何外部變數。 | `[] (int x) { return x * 2; }` |
| **`[x]`** | **值捕獲 (Capture by Value)**：將外部變數 `x` 的值複製一份到 Lambda 內部。Lambda 無法修改原始的 `x`。 | `int x = 10; [x]() { return x; }` |
| **`[&x]`** | **引用捕獲 (Capture by Reference)**：Lambda 內部透過引用存取外部的 `x`。Lambda 可以修改原始的 `x`。 | `int x = 10; [&x]() { x++; }` |
| **`[=]`** | **隱式值捕獲**：自動以**值**的方式捕獲所有外部需要的變數。 | `[=](){ return a + b; }` |
| **`[&]`** | **隱式引用捕獲**：自動以**引用**的方式捕獲所有外部需要的變數。 | `[&](){ if(count > 0) count--; }` |

> **細節：** 捕獲列表讓 Lambda 形成了**閉包 (Closure)** 的概念。**閉包**是一種特殊型別的函式，它能記住並存取其定義時所在的環境變數，即使該環境已經不存在了（例如，當原始函式已經返回）。

### 2\. 參數列表 (Parameter List) - `()`

與普通函式一樣，定義 Lambda 函式接受的輸入參數。

  * 範例：`(int a, int b)`。
  * 如果 Lambda 不接受任何參數，可以省略參數列表，例如 `[] {}`。

### 3\. 函式主體 (Body) - `{}`

這是 Lambda 函式實際執行的程式碼。

-----

## 什麼情況下會使用 Lambda 函式？

Lambda 函式之所以強大，是因為它極大地簡化了需要**函式作為參數**的場合。

### 1\. 演算法庫 (STL Algorithms)

在 C++ 中，當需要對容器執行排序、查找或過濾等操作時，Lambda 函式是最佳選擇，因為它們不需要定義一個獨立的比較函式。

**範例：客製化排序**
假設要對一個整數向量 `v` 進行**降冪排序**：

```cpp
std::vector<int> v = {3, 1, 4, 1, 5};

// 使用 Lambda 函式作為 std::sort 的比較參數
std::sort(v.begin(), v.end(), [](int a, int b) {
    // a > b 時回傳 true，實現降冪
    return a > b; 
});
```

如果沒有 Lambda，需要寫一個名為 `compareDesc` 的獨立函式。

### 2\. 多執行緒與並行計算

當啟動一個新的執行緒時，Lambda 可以很容易地作為執行緒的起點，並透過捕獲列表傳遞所需的參數。

**範例：執行緒 (Thread)**

```cpp
int start_value = 100;
std::thread t1([&start_value]() {
    // 透過引用捕獲 start_value，並在另一個執行緒中修改它
    start_value += 5; 
});
t1.join();
```

### 3\. 事件處理與回撥 (Callbacks)

在遊戲開發或 Web 應用程式中，當某個事件發生時（例如按下滑鼠），需要一個臨時函式來響應。Lambda 函式是定義這些一次性回撥的最佳方式。

-----

## Lambda 函式與傳統函式的主要區別

| 特性 | Lambda 函式 (匿名函式) | 傳統函式 (具名函式) |
| :--- | :--- | :--- |
| **名稱** | **沒有名稱**，通常只在原地定義和使用。 | 必須有一個唯一的名稱。 |
| **定義位置** | 可以在任何表達式內**內嵌定義**。 | 必須在檔案範圍或類別內單獨定義。 |
| **環境存取** | 透過**捕獲列表**，可以存取定義它的作用域內的變數。 | 只能存取全域變數或透過參數傳遞進來的變數。 |
| **型別** | 每個 Lambda 都有一個**獨特的、未命名的類別型別**。 | 型別由其簽名（參數和回傳值）決定。 |

-----

問題：**如果已經在 `[]` 裡面指定了要使用的外部變數，為什麼還需要 `()` 參數列表呢？**

答案是：**`[]` 和 `()` 服務於完全不同的目的。**

-----

## `[]` 捕獲列表的目的：環境依賴 (Context Dependency)

**目的：** 告訴編譯器這個函式需要**存取外部環境中的哪些變數**。

  * **性質：** 這是 Lambda 函式的**定義時**屬性。它決定了 Lambda 閉包的**狀態 (State)**，或者說它「記住了」什麼。
  * 捕獲的變數（例如 `int x`）成為 Lambda 內部**隱藏的成員變數**。
  * **範例：**
    ```cpp
    int offset = 5;
    auto add_offset = [offset](int val) { return val + offset; };
    // Lambda 已經透過 [offset] 記住了 5 這個值。
    ```
    `offset` 在這裡是一個**常數**，是 Lambda 執行時所需的背景資料。

-----

## `()` 參數列表的目的：函式簽名 (Function Signature)

**目的：** 告訴編譯器這個函式在**被呼叫時**需要傳入哪些**輸入資料**。

  * **性質：** 這是 Lambda 函式的**呼叫時**屬性。它決定了 Lambda 的**行為 (Behavior)**。

  * 這些參數在每次呼叫 Lambda 時都會被重新傳入。

  * **範例：**

    ```cpp
    // 這裡的 (int val) 是呼叫時的新輸入
    auto add_offset = [offset](int val) { return val + offset; };

    add_offset(10); // 呼叫時傳入 val = 10
    add_offset(20); // 呼叫時傳入 val = 20
    ```

    `val` 在這裡是一個**變數**，是每次執行所需的動態輸入。

-----

## 總結：兩者不可或缺

可以用「**背景**」和「**前景**」來區分它們：

| 語法部分 | 角色 | 作用時機 | 概念 |
| :--- | :--- | :--- | :--- |
| **`[]` 捕獲列表** | **背景資料**（狀態） | **定義 Lambda 時**設定 | **閉包**：記住定義環境的資料。 |
| **`()` 參數列表** | **前景資料**（輸入） | **呼叫 Lambda 時**傳入 | **函式**：每次執行所需的動態輸入。 |

如果沒有 `()`，Lambda 就無法接受新的輸入，那它就只是一個封裝了狀態的單純表達式。它之所以是「函式」，就是因為它遵循了標準函式呼叫約定（例如：可以傳遞參數、可以回傳值），而這些都是由 `()` 參數列表定義的。

### 📌 即使沒有參數，`()` 仍是必須的

即使 Lambda 函式不需要任何外部輸入（只依賴捕獲的變數，或根本不依賴），仍然需要 `()`，只不過它是空的：

```cpp
// 必須使用 ()，即使參數列表為空
auto greet = [name]() { 
    std::cout << "Hello, " << name << "!"; 
};

greet(); // 呼叫時仍需使用 ()
```
---

## `()` 參數列表可以省略的唯一條件

在 C++ 中，`()` 參數列表只有在滿足以下兩個嚴格條件時才可以被省略：

### 條件 1: 捕獲列表必須是空的

$$\text{Lambda 必須是：} \mathbf{[]}$$

這表示 Lambda 函式**沒有捕獲**任何外部作用域中的變數。

### 條件 2: 參數列表必須是空的

$$\text{Lambda 必須是：}\mathbf{()}$$

這表示 Lambda 函式**不接受**任何輸入參數。

如果同時滿足這兩個條件，編譯器允許你省略 `()`，以達到最簡潔的寫法。

| 程式碼 | 是否有效？ | 說明 |
| :--- | :--- | :--- |
| `[] { return 42; }` | **✅ 有效** | 這是最簡潔的寫法，等價於 `[]() { return 42; }`。 |
| `[]() { return 42; }` | **✅ 有效** | 完整且清晰的寫法。 |

---

## `()` 參數列表必須使用的情況 (絕大多數情況)

除了上述最簡單的例外情況外，在所有其他實際應用中，`()` 都是定義 Lambda **函式簽名**的必備部分。

### 情況一：有任何變數捕獲時 (`[]` 不為空)

一旦你捕獲了任何外部變數，即使 Lambda 不接受參數，你也**必須**保留 `()`。

| 程式碼 | 結果 | 說明 |
| :--- | :--- | :--- |
| `int x = 5;` | | |
| `[x] { return x; }` | **❌ 錯誤** | 捕獲列表不為空，必須加上 `()`。 |
| `[x]() { return x; }` | **✅ 正確** | 即使參數為空，也必須定義 `()`。 |

### 情況二：接受任何輸入參數時 (`()` 不為空)

這就是我們前面討論的核心：`()` 告訴編譯器，這個函式在被呼叫時需要什麼樣的輸入。

| 程式碼 | 結果 | 說明 |
| :--- | :--- | :--- |
| `[](int a) { return a * 2; }` | **✅ 正確** | 接收 `int a` 作為輸入，`()` 是定義輸入的語法。 |

### 情況三：需要定義回傳型別 (Trailing Return Type)

如果需要明確指定 Lambda 的回傳型別，`()` 也是不可或缺的：

| 程式碼 | 結果 | 說明 |
| :--- | :--- | :--- |
| `[]->double { return 42.0; }` | **❌ 錯誤** | 必須在箭頭前定義 `()`。 |
| `[]()->double { return 42.0; }` | **✅ 正確** | `()` 用來分隔捕獲列表和回傳型別。 |

---

## 結論

雖然在最簡單的情況下（`[] {}`），C++ 允許你省略 `()` 實現簡潔，但在任何更複雜或更實用的情況下（有捕獲或有參數），`()` 都是必要的。

**`()` 存在的意義是定義「函式輸入」的語法結構，這是它與 `[]`（定義「函式背景」的語法結構）的根本區別。**

# problem

1. What is *(int*)a in compare function on the internet.

  ans:

  The function takes a void*, but somehow it knows (perhaps it's required in some documentation somewhere) that the pointer it's given actually points to an int.
  So, (int*)number is "the original pointer, converted to an int* so that I can read an int from it", and *(int*)number is the int value that it points to.
  
