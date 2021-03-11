# [Coin Change](https://leetcode.com/problems/coin-change/)

熟悉的硬幣問題，使用動態規劃就能輕鬆地解出來，金額從1~amount，去找出 [當前金額-coin] 所需的硬幣數，將其 +1 就是當前金額所需硬幣數量的一種情形，從所有的情形中找出最少硬幣數量，就是當前金額所需最小硬幣數，最後去找陣列的[amount]，其數量就是最終答案。

---

以前就寫過類似的題目，不過太久沒練，寫起來就沒那麼的簡潔、漂亮。

## 本次收穫
* C++在宣告變動長度的陣列時，不能同時將整個陣列的值都初始化，還要另外使用memset或迴圈來初始化，但能使用vector的constructor：
`vector (size_type n, const value_type& val)`，就能達到宣告時初始化陣列的效果了。

* 妥善利用語言內部的常數，例如：INT_MAX
