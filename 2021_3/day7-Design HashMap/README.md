# [Design HashMap](https://leetcode.com/problems/design-hashmap/)

## 我的解法

我開了16個list<pair<int,int>>的陣列，將key做mod 16後做為index，存到對應的list中。我這邊使用mod來做為簡易的hash function，當遇到collision，就串在list的後方。

當陣列開越多個，使用的記憶體空間就越大，但在查詢、新增或移除時，掃描的list就不會這麼長，可以加快執行的速度。

我python程式的執行時間有點久，只贏過8.92%，我在想有可能是`self.table[index].remove(entry)`的問題。

---

## 別人的解法

我是有看到別人開足1000001個陣列，這樣就不會發生collision，直接對陣列做操作就行，但在資料量少時，就浪費的大量的空間。

---

## 本次收穫

### python3

使用 `*` 來宣告出具有固定數量的list，看別人都是在宣告另一個class，有空再來研究研究。

### typescript

由於功力不足，寫不出來，使用了偷吃步的作法，但看別人的作法，好像用一般的list就能做到了?
