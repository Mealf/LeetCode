class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return {};
        
        //Pacific fill 1; Atlantic fill 2; Both fill 3(binary 11)
        vector<vector<int>> v(matrix.size(),vector<int>(matrix[0].size()));
        
        vector<vector<int>> result;
        
        /*fill edge*/
        for(int i=0;i<v.size();i++){
            v[i][0]|=1;
            v[i][v[0].size()-1]|=2;
        }
        for(int i=0;i<v[0].size();i++){
            v[0][i]|=1;
            v[v.size()-1][i]|=2;
        }
       
        /*flood*/
        for(int i=0;i<v.size();i++){
            flood(i,0,v,matrix);
            flood(i,v[0].size()-1,v,matrix);
        }
        for(int i=0;i<v[0].size();i++){
            flood(0,i,v,matrix);
            flood(v.size()-1,i,v,matrix);
        }
        
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==3)
                    result.push_back({i,j});
            }
        }
        return result;
    }
    /*從低地勢往高地勢找，當可以更新且有需要更新時再去更新，同時flood*/
    void flood(int row, int col, vector<vector<int>> &v, vector<vector<int>> &m){
        int value=m[row][col], w=v[row][col];
        
        //a&b!=b 等同於 a&(b!=b)
        //往上找
        if(row+1<m.size() && m[row+1][col]>=value && (v[row+1][col]&w)!=w){
            v[row+1][col] |= v[row][col];
            flood(row+1,col,v,m);
        }
        //往右找
        if(col+1<m[0].size() && m[row][col+1]>=value && (v[row][col+1]&w)!=w){
            v[row][col+1] |= w;
            flood(row,col+1,v,m);
        }
        //往下找
        if(row!=0 && m[row-1][col]>=value && (v[row-1][col]&w)!=w){
            v[row-1][col]|=w;
            flood(row-1,col,v,m);
        }
        //往左找
        if(col!=0 && m[row][col-1]>=value && (v[row][col-1]&w)!=w){
            v[row][col-1]|=w;
            flood(row,col-1,v,m);
        }
    }
};