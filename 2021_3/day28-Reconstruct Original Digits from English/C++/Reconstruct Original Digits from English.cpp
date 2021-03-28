class Solution {
    struct number{
        int num;
        char unique;
        string english;
        number(int n,char u, string e){
            num=n;
            unique=u;
            english=e;
        }
    };
public:
    string originalDigits(string s) {
        string result="";
        vector<number> v;
        vector<int> count(10);
        map<char,int> m;

        v.push_back(number(0,'z',"zero"));
        v.push_back(number(2,'w',"two"));
        v.push_back(number(4,'u',"four"));
        v.push_back(number(6,'x',"six"));
        v.push_back(number(3,'r',"three"));
        v.push_back(number(1,'o',"one"));
        v.push_back(number(5,'f',"five"));
        v.push_back(number(7,'s',"seven"));
        v.push_back(number(8,'g',"eight"));
        v.push_back(number(9,'i',"nine"));

        for(auto &c:s)
            m[c]++;
            
        for(auto &num: v){
            count[num.num]+=m[num.unique];
            reduce_char(m, num.english, m[num.unique]);
        }
        
        for(int i=0;i<=9;i++){
            //cout<<count[i]<<endl;
            result += string(count[i],i+'0');
        }
        return result;
    }
    void reduce_char(map<char,int> &m, string s,int n) {
        for(auto &c:s)
            m[c]-=n;
    }
};