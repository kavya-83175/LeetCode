class Solution {
public:
    int check(int n,int m,int i,int j,string &word1,string &word2,vector<vector<int>>&dp){
        if(i>=n){
            return (m-j);
        }
        else if(j>=m){
            return (n-i);
        }
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else if(word1[i]==word2[j]){
            return dp[i][j]=check(n,m,i+1,j+1,word1,word2,dp);
        }
        else{
            int a=1+check(n,m,i+1,j,word1,word2,dp);
            int b=1+check(n,m,i,j+1,word1,word2,dp);
            return dp[i][j]=min(a,b);
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return check(n,m,0,0,word1,word2,dp);
       
    }
};