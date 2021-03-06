# [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/)

這題主要就是要求出樹每層的平均，可以使用 `DFS` 或是 `BFS` 來實作， `DFS` 可以使用 `function` 的 `recursion`來實現， `BFS` 可以使用 `queue`來實現。

---

</br>

我主要是使用 `DFS` 來做，利用另外兩個 `vector` 來分別儲存每層的總和與個數，這兩個 `vector` 可以用全域變數的方式或是 `pass by reference` 的方式來處理。

</br>

別人的寫法是使用 `BFS` 的方法，先記錄目前在 `queue` 的數量，即為當層 `level` node的個數，這個處理流程也不錯。

---

## 本次收獲

使用python的deque來操作，就不用每次都要複製一個list，能讓程式碼比較簡潔。

[python collectios](https://docs.python.org/zh-tw/3/library/collections.html#collections.deque)：
| namedtuple() | 用來建立一個欄位擁有名字的 tuple 子類別的函數             |
|--------------|---------------------------------------------|
| deque        | 一個類似 list 的容器，可以快速的在頭尾加入元素與取出元素。  |
| ChainMap     | 一個像是 dict 的類別，用來為多個 mapping 建立單一的 view 。 |
| Counter      | dict 的子類別，用來計算可 hash 物件的數量。                 |
| OrderedDict  | dict 的子類別，會記錄物件被加入的順序。                     |
| defaultdict  | dict 的子類別，在值不存在 dict 當中時會呼叫一個產生函式。   |
| UserDict     | 封裝了字典對象，簡化了字典子類化                           |
| UserList     | 封裝了列表對象，簡化了列表子類化                           |
| UserString   | 封裝了列表對象，簡化了字符串子類化                         |
