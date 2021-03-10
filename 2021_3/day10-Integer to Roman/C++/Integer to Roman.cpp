class Solution {
public:
    string intToRoman(int num) {
        char symbol[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int value[] = {1000, 500, 100, 50, 10, 5, 1};
        int sub[] = {2, 2, 4, 4, 6, 6};
        string ans = "";
        
        for(int i=0; i<7; i++) {
            ans += string(num/value[i], symbol[i]);
            num %= value[i];
            
            if(i!=6) {
                int combine = value[i]-value[sub[i]];
                if(num >= combine) {
                    ans += symbol[sub[i]];
                    ans += symbol[i];
                    num -= combine;
                }
            }         
        }
        return ans;
    }
};