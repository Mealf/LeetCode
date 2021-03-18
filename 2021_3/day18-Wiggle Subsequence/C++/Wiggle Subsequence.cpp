class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        
        int result = 1, i=1;
        bool needPos = false;
        while(i<nums.size()&&nums[i]==nums[i-1])
            i++;
        
        if(i<nums.size()&&nums[i]>nums[i-1])
            needPos = true;
        
        /*[1,5,10,7] 1>5 5>10 因此可以去掉5，長度一樣而且因為數字更大，下一個更容易找到小的。
          結論就是反轉時再計數就能得到答案。
        */
        for(int i=1;i<nums.size();i++) {
            if(needPos && nums[i]>nums[i-1]) {
                needPos = !needPos;
                result++;
            } else if(!needPos && nums[i]<nums[i-1]) {
                needPos = !needPos;
                result++;
            }
        }
        return result;
    }
};