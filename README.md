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

## 問題：**如果已經在 `[]` 裡面指定了要使用的外部變數，為什麼還需要 `()` 參數列表呢？**

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


## Lambda 函式 (Lambda Function)** 底層機制的進階問題！

Lambda 函式有一個**獨特的、未命名的類別型別 (Unique, Unnamed Class Type)** 時，意思是：

**在編譯器（Compiler）的眼裡，每一個 Lambda 函式都不是一個簡單的函式指標，而是一個自動產生的、具備特殊功能的匿名物件。**

-----

## 1\. 匿名類別的自動產生 (Compiler Magic)

當你寫下一個 Lambda 表達式時，例如：

```cpp
int x = 10;
auto my_lambda = [x](int y) { return x + y; };
```

編譯器在幕後會執行以下操作：

### 步驟 A: 產生一個唯一的類別 (Closure Type)

編譯器會為這個 Lambda 函式**自動生成一個全新的、從未命名過的類別**。這個類別通常被稱為 **Closure Type**（閉包型別）。

### 步驟 B: 捕獲變數成為成員變數

這個自動生成的類別的內部，會將你在**捕獲列表 `[x]`** 中指定的變數，轉換成它的**成員變數**。

**等價的幕後程式碼概念 (非真實程式碼)：**

```cpp
// 這是編譯器在後台自動生成的，你看不到
class UniqueLambdaName_12345 {
private:
    // 捕獲的變數 [x] 成為類別的成員變數
    const int x; 
public:
    // 建構子，用於接收捕獲的值
    UniqueLambdaName_12345(int val) : x(val) {} 

    // 關鍵！重載了函式呼叫運算符 operator()
    int operator()(int y) const {
        // Lambda 的主體程式碼就在這裡執行
        return x + y; 
    }
};

// 你的 auto my_lambda 實際上是這個類別的物件
// UniqueLambdaName_12345 my_lambda(10);
```

### 步驟 C: 實作函式呼叫運算符 (`operator()`)

為了讓這個物件可以像函式一樣被呼叫（例如 `my_lambda(5)`），編譯器會在該類別中**重載 (Overload)** 了 **函式呼叫運算符 `operator()`**。

**結論：** 當執行 `my_lambda(5)` 時，你並不是在呼叫一個函式，而是在呼叫這個**匿名物件**的**成員函式 `operator()`**。

-----

## 2\. 為什麼要是獨特的型別？（型別安全性）

這種設計有兩個主要優勢：

### 優勢一：狀態封裝 (State Encapsulation)

因為捕獲的變數（如 `x`）變成了類別的成員，所以這個 **Lambda 物件**可以**保存它在定義時的狀態**。這就是「閉包」的實現方式。

### 優勢二：每個 Lambda 都是不同的

即使寫了兩個看起來一模一樣的 Lambda 函式：

```cpp
auto lambda1 = [] { return 1; };
auto lambda2 = [] { return 1; };
```

在編譯器看來，`lambda1` 和 `lambda2` 仍然屬於**兩個不同的、獨特的、匿名類別型別**。

  * 可以使用 `std::is_same_v<decltype(lambda1), decltype(lambda2)>` 來驗證，結果會是 `false`。
  * 這保證了**型別安全性**，並且能讓編譯器對每個獨立的 Lambda 進行高度優化，因為它們知道每個閉包的確切結構。

-----

## 3\. `auto` 與 `std::function`

正因為 Lambda 函式具有這種獨特的匿名型別，所以在使用時通常會：

1.  **使用 `auto` 關鍵字：**

    ```cpp
    auto my_lambda = [x](int y) { /* ... */ }; 
    ```

    這是最常見且推薦的方式。`auto` 讓編譯器自己去推導這個獨特的匿名型別。

2.  **使用 `std::function` 包裝：**

    ```cpp
    std::function<int(int)> func = my_lambda;
    ```

    如果需要將 Lambda 賦值給一個明確的變數型別，或者將它作為函式參數傳遞，`std::function` 提供了一個**通用、具名**的容器來持有任何符合特定簽名（例如 `int(int)`）的**可呼叫對象 (Callable Object)**，包括 Lambda、普通函式或函式物件。

總而言之，Lambda 的「獨特型別」是 C++ **高效且靈活地實作閉包**的底層機制，可以像寫普通函式一樣寫出一個具備狀態的匿名物件。

## 問題:關於 C++ **作用域規則 (Scoping Rules)** 和 **變數遮蔽 (Variable Shadowing)** 

如果 Lambda 函式中，**捕獲的變數名稱**和**參數列表中的變數名稱**一樣，會發生什麼呢？

-----

## 答案：參數會遮蔽捕獲的變數

簡潔的答案是：**Lambda 參數列表中的變數會遮蔽 (Shadow) 掉外部捕獲列表中的同名變數。**

在 C++ 中，當一個名稱（例如 `x`）在多個嵌套的作用域中定義時，最內層作用域的定義會覆蓋（或遮蔽）外層的定義。

在 Lambda 函式中，作用域層次是這樣的：

$$\text{最外層} \rightarrow \text{外部作用域}$$$$\mathbf{\downarrow}$$$$\text{中層} \rightarrow \mathbf{Lambda \ 捕獲列表 (State)}$$$$\mathbf{\downarrow}$$$$\text{最內層} \rightarrow \mathbf{Lambda \ 參數列表 (Input)}$$$$\mathbf{\downarrow}$$$$\text{內層} \rightarrow \mathbf{Lambda \ 主體 (\text{Body})}$$

當 Lambda 主體內使用 `x` 時，編譯器會從最內層往外層尋找 `x` 的定義。

### 範例分析

假設外部定義了一個變數 `x`：

```cpp
int x = 10; // 外部變數 x
```

現在來看這個 Lambda 函式：

```cpp
// 捕獲 x 的值 [x]，但參數列表又定義了 int x
auto my_lambda = [x](int x) { 
    return x; // 這裡的 x 究竟是哪個？
};
```

#### 1\. 參數列表優先 (遮蔽發生)

當編譯器看到 Lambda 主體內的 `return x;` 時：

  * **它首先找到的是**：參數列表中的 `int x`。
  * **它會忽略的是**：捕獲列表中的 `[x]` 成員變數。

因此，**Lambda 主體內的 `x` 始終指向參數列表中的 `int x`**。

#### 2\. 結果與輸出

  * **當你定義 Lambda 時**：捕獲列表 `[x]` 成功捕獲了外部的 `10`。這個 `10` 已經作為 Lambda 物件的一個**隱藏成員變數**儲存起來了。
  * **當你呼叫 Lambda 時**：
    ```cpp
    int result = my_lambda(5); 
    // 此時，參數 x = 5
    // Lambda 主體執行 return x; 
    // x 指向參數 5
    // result = 5
    ```

**結論：** 雖然你捕獲了 `10`，但由於參數的遮蔽效應，你永遠無法在 Lambda 主體內直接透過名稱 `x` 存取到那個被捕獲的值 `10`。

-----

## 實用建議 (Best Practice)

### **強烈建議：使用不同的名稱**

為了避免任何歧義和遮蔽問題，請務必為捕獲的變數和函式參數使用不同的名稱：

這樣可以確保程式碼的邏輯清晰，一眼就能看出哪個變數是 Lambda 的**固定狀態 (State)**，哪個是**動態輸入 (Input)**。

-----

# problem

1. What is *(int*)a in compare function on the internet.

  ans:

  The function takes a void*, but somehow it knows (perhaps it's required in some documentation somewhere) that the pointer it's given actually points to an int.
  So, (int*)number is "the original pointer, converted to an int* so that I can read an int from it", and *(int*)number is the int value that it points to.
  
