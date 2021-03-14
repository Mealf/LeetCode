/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> arr;
        while(head) {
            arr.push_back(head);
            head = head->next;
        }
        
        k--;
        int back = arr.size()-1-k;
        swap(arr[k]->val, arr[back]->val);
        
        return arr[0];
    }
};