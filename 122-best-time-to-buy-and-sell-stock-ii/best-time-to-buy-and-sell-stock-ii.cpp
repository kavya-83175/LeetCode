class Solution {
public:
    int check(int i,int &n,vector<int>&prices,int k,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        else if(dp[i][k]!=-1){
            return dp[i][k];
        }
        else if(k!=0){
            int a=prices[i]+check(i+1,n,prices,0,dp);
            int b=check(i+1,n,prices,k,dp);
            return dp[i][k]=max(a,b);
        }
        else{
            int a=-prices[i]+check(i+1,n,prices,1,dp);
            int b=check(i+1,n,prices,k,dp);
            return dp[i][k]=max(a,b);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return check(0,n,prices,0,dp);
    }
};