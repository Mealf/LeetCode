# [Short Encoding of Words](https://leetcode.com/problems/short-encoding-of-words/)

## 我的解法

起初沒想到比較好的解法，就先將vector根據長度由小到大排序，接著用雙層迴圈去比對長度較長的子字串，效率整個低到不行。

---

## 別人的解法

參考別人的的解法才知道這題可以用Trie來解，排序完vector後，先將字串反向，若這次有新增節點，表示這個word不能接在前面別的word的後面。

或是使用set的資料結構，先將全部的word放進set，然後找出所有word的substr，去刪除set中的元素，剩下的再跑個迴圈將長度給加總後就差不多了。

在效率上好像使用set的方式還是優於Trie。

---

## 本次收穫

### python3

set再刪除時有兩個方法：set.remove(element) 跟 set.discard(element)，差別在於若set中沒有這個element時，使用remove會跳出error。

多使用內建函式來簡化程式碼：如sum、單行for迴圈

### typescript

可以使用for...of loop來迭代元素，類似C++的for(auto ... : ...)
