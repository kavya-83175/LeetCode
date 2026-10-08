class Solution {
public:
    string convert(string s, int nR) {
       if(nR==1 || s.size()==1) return s;
       vector<vector<char>>mat(nR);
       int d=0,idx=0;
       for(int i=0;i<s.size();i++){
            if(idx==0){
                d=1;
            }
            else if(idx==nR-1){
                d=-1;
            }
            mat[idx].push_back(s[i]);
            idx+=d;
       }
       string str="";
       for(int i=0;i<mat.size();i++){
          for(int j=0;j<mat[i].size();j++){
            str.push_back(mat[i][j]);
          }
       }
       return str;
    }
};