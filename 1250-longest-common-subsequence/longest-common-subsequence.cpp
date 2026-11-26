class Solution {
public:
    int check(int i,int j,string &text1,string &text2,vector<vector<int>>&dp){
        if(i>=text1.size() || j>=text2.size()){
            return 0;
        }
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        else if(text1[i]==text2[j]){
            return dp[i][j]=1+check(i+1,j+1,text1,text2,dp);
        }
        else{
            int a=check(i+1,j,text1,text2,dp);
            int b=check(i,j+1,text1,text2,dp);
            return dp[i][j]=max(a,b);
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return check(0,0,text1,text2,dp);
    }
};