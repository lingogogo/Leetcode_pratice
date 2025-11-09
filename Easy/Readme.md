#### 問題: 如果要使用comparator in class function, 直接在裡面定義必須使用回傳 static bool

如果我們必須將一個**非靜態成員函數**作為 `std::sort` 的比較器，我們需要將其綁定到一個特定的類別實例（即提供 `this` 指針）。

您不能直接在 `std::sort` 的參數中傳遞 `this` 指針，但可以使用 C++ 的標準庫工具來實現**綁定 (Binding)**。

最常見和推薦的方法是使用 `std::bind` 配合 `std::function`，或者更現代的 **Lambda 表達式**來捕獲 `this`。

-----

###### 修正方法：使用 Lambda 表達式捕獲 `this` (最推薦)

這是最現代、最乾淨，且通常最容易理解的方法。

####### 步驟：

1.  在 `findXSum` 內部使用 **Lambda 表達式**。
2.  在 Lambda 的捕獲列表 `[]` 中明確寫入 **`this`**。
3.  在 Lambda 內部，通過捕獲到的 `this` 來**呼叫**非靜態成員函數 `customComparison`。

<!-- end list -->

```cpp
class Solution {
public:
    // 非靜態成員函數
    bool customComparison(pair<int, int> a, pair<int, int> b) 
    {
        if (a.first != b.first)
            return a.first > b.first;
        else
            return a.second > b.second;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        // ... (其他代碼) ...

        vector<pair<int, int>> fre;
        // ... (填充 fre) ...

        // 關鍵修正：使用 Lambda 捕獲 this
        // Lambda 充當了排序的比較器，它在內部呼叫了成員函數
        sort(fre.begin(), fre.end(), [this](const pair<int, int>& a, const pair<int, int>& b) {
            // 在這裡，我們可以使用 'this->' 來呼叫非靜態成員函數
            return this->customComparison(a, b);
        });

        // ... (後續代碼) ...
    }
};
```

####### 優勢：

  * **語義清晰：** 明確表達了排序邏輯依賴於當前的 `Solution` 物件。
  * **簡潔：** 避免了複雜的 `std::bind` 語法。

-----

###### 替代方法：使用 `std::bind` (較複雜)

如果不想使用 Lambda 捕獲 `this`，可以使用 `std::bind` 來預先綁定 `this` 指針到成員函數上。

```cpp
#include <functional> // 需要包含此標頭檔

// ... (Solution 類別結構不變) ...

vector<int> findXSum(vector<int>& nums, int k, int x) {
    // ... (其他代碼) ...

    vector<pair<int, int>> fre;
    // ... (填充 fre) ...

    // 關鍵修正：使用 std::bind 綁定 this
    using namespace std::placeholders;

    // 創建一個新的可調用對象，它已經綁定了當前的 this 指針，
    // 並且期望接收兩個參數（_1 和 _2 代表傳給 sort 的 a 和 b）
    auto bound_comp = std::bind(&Solution::customComparison, this, _1, _2);

    sort(fre.begin(), fre.end(), bound_comp);

    // ... (後續代碼) ...
}
```

總結來說，您的思路是正確的：如果比較器是一個非靜態成員函數，就**必須**提供一個 `this` 指針。在 C++ 中，**Lambda 表達式捕獲 `this`** 是實現這一目標最慣用的方法。
