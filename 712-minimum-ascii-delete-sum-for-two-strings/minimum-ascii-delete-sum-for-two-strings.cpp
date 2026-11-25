class Solution {
public:
    int check(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if((i>=s1.size() || j>=s2.size())){
            dp[i][j]=0;
            if(i>=s1.size() && j<s2.size()){
                for(int k=j;k<s2.size();k++){
                    dp[i][j]+=(int)s2[k];
                }
            }
            else if(j>=s2.size() && i<s1.size()){
                for(int k=i;k<s1.size();k++){
                    dp[i][j]+=(int)s1[k];
                }
            }
            return dp[i][j];
        }
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]!=s2[j]){
            int a=(int)s1[i]+check(s1,s2,i+1,j,dp);
            int b=(int)(s2[j])+check(s1,s2,i,j+1,dp);
            return dp[i][j]=min(a,b);
        }
        else{
            return dp[i][j]=check(s1,s2,i+1,j+1,dp);
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int mini=INT_MAX,n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return check(s1,s2,0,0,dp);
    }
};