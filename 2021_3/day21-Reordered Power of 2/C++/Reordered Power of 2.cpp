class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int num=1;
        unordered_map<int,int> set_n,set_num;
        int i=N,t=0;
        
        while(i){
            set_n[i%10]++;
            i/=10;
        }
        
        int log_n = log10(N);
        int log_num = log10(num);
        
        while(t<30 && log_num<=log_n) { // 2^30 = 1,073,741,824
            if(log_num == log_n){   //同樣位數時再來判斷
                i = num;
                while(i) {
                    set_num[i%10]++;
                    i/=10;
                }
                
                if(set_n==set_num)
                    return true;
                
                set_num.clear();
            }
            num=num<<1;
            log_num = log10(num);
            t++;
        }
        
        return false;
    }
};