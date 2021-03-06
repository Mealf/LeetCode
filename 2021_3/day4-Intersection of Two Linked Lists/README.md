# [Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)

這題最主要就是要將尾巴對齊，找出最長相同的`ListNode`

解法一：</br>
將A、B接成 `A-null-B-null` 跟 `B-null-A-null`，因為長度一樣，所以最後在掃的時候有將結尾對齊的效果，只要找出第一次相等的就OK了，例如： `listA = [1,9,1,2,4], listB = [3,2,4]` ，變成 `[1,9,1,2,4,null,3,2,4]` 與 `[3,2,4,null,1,9,1,2,4]` 去做比對，可以看到這樣做有將結尾對齊的效果。

</br>

解法二：</br>
先用兩個迴圈去計算A、B兩個 `Linked list` 的長度，然後將較長的 `Linked list` 從頭扣掉兩個長度的差值，例如： `listA = [1,9,1,2,4], listB = [3,2,4]` ，將 `listA` 跳過兩個，變成 `[1,2,4]` 後，再去與 `listB` 做比對。

---

## 語法部分

python: 使用 `,` 同時賦值給多個變數，並且使用單行的`if-else`使得程式看起來更加的簡潔
