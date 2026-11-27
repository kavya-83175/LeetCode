class Solution {
public:
    int check(int i,int k,vector<int>&prices,vector<vector<vector<int>>>&dp,int val){
        if(i>=prices.size()){
            return 0;
        }
        else if(dp[i][k][val]!=-1){
            return dp[i][k][val];
        }
        else if(val<2){
            if(k==1){
                int a=prices[i]+check(i+1,0,prices,dp,val+1);
                int b=check(i+1,k,prices,dp,val);
                return dp[i][k][val]=max(a,b);
            }
            else{
                int a=-prices[i]+check(i+1,1,prices,dp,val);
                int b=check(i+1,k,prices,dp,val);
                return dp[i][k][val]=max(a,b);
            }
        }
        else{
            return 0;
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return check(0,0,prices,dp,0);
    }
};