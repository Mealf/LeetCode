class Solution {
public:
    int countSubstrings(string s) {
        int result=0;
        
        for(int i=0;i<s.size();i++){
            int delta=1;
            result++;
            while(i-delta>=0 && i+delta<s.size()){
                if(s[i-delta]!=s[i+delta])
                    break;
                result++;
                delta++;
            }
            
            delta=0;
            while(i-delta>=0 && i+1+delta<s.size()){
                if(s[i-delta]!=s[i+1+delta])
                    break;
                result++;
                delta++;
            }
                
        }
        return result;
    }
};