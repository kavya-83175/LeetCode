class Solution {
public:
    // int check(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    //     if((i>=s1.size() || j>=s2.size())){
    //         dp[i][j]=0;
    //         if(i>=s1.size() && j<s2.size()){
    //             for(int k=j;k<s2.size();k++){
    //                 dp[i][j]+=(int)s2[k];
    //             }
    //         }
    //         else if(j>=s2.size() && i<s1.size()){
    //             for(int k=i;k<s1.size();k++){
    //                 dp[i][j]+=(int)s1[k];
    //             }
    //         }
    //         return dp[i][j];
    //     }
    //     else if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s1[i]!=s2[j]){
    //         int a=(int)s1[i]+check(s1,s2,i+1,j,dp);
    //         int b=(int)(s2[j])+check(s1,s2,i,j+1,dp);
    //         return dp[i][j]=min(a,b);
    //     }
    //     else{
    //         return dp[i][j]=check(s1,s2,i+1,j+1,dp);
    //     }
    // }
    int minimumDeleteSum(string s1, string s2) {
        int mini=INT_MAX,n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return check(s1,s2,0,0,dp);
        for(int j=m-1;j>=0;j--){
            dp[n][j]=dp[n][j+1]+(int)s2[j];
        }
        for(int i=n-1;i>=0;i--){
            dp[i][m]=dp[i+1][m]+(int)s1[i];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j]+=dp[i+1][j+1];
                }
                else{
                    int a=(int)(s1[i])+dp[i+1][j];
                    int b=(int)(s2[j])+dp[i][j+1];
                    dp[i][j]=min(a,b);
                }
            }
        }
        return dp[0][0];
    }
};