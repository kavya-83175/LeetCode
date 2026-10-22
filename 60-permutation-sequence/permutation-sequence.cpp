class Solution {
public:
    void check(string &s,string &dum,int &n,vector<string>&mat,vector<int>&vis){
        if(dum.size()==n){
            mat.push_back(dum);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dum+=s[i];
                vis[i]=true;
                check(s,dum,n,mat,vis);
                dum.pop_back();
                vis[i]=false;
            }
        }
    }
    string getPermutation(int n, int k) {
        string s="",dum="";
        for(int i=1;i<=n;i++){
            s+=char(i+'0');
        }
        vector<int>vis(n,false);
        vector<string>mat;
        check(s,dum,n,mat,vis);
        return mat[k-1];
    }
};