class Solution {
    struct Num {
        int index, value;
        Num(int i, int v) {
            index = i;
            value = v;
        }
    };
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> result(A.size(), -1);
        vector<Num> b; //可以換成vector<pair<int,int>>
        for(int i=0;i<B.size();i++) 
            b.push_back(Num(i,B[i]));

        sort(A.begin(), A.end(), [](int a, int b){return a>b;});
        sort(b.begin(), b.end(), [](Num a, Num b){return a.value>b.value;});

        int index_a=0, index_b=0;
        while(index_a<A.size() && index_b<B.size()) {
            if(A[index_a]>b[index_b].value) {
                result[b[index_b].index] = A[index_a];
                index_a++;
                index_b++;
            } else {
                index_b++;
            }
        }
        
        for(int i=0;i<result.size();i++) {
            if(result[i]==-1) {
                //可以換成result[i] = A[index_a++];
                result[i] = A[index_a];
                index_a++;
            }
        }
        return result;
    }
};