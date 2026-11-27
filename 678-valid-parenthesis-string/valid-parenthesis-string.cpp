class Solution {
public:
    bool check(int i,string &s,int cnt,vector<vector<int>>&dp){
        if(i>=s.size() || cnt<0){
            if(cnt==0)
            return 1;
            else
            return 0;
        }
        else if(dp[i][cnt]!=-1){
            return dp[i][cnt];
        }
        else if(s[i]=='('){
            return dp[i][cnt]=check(i+1,s,cnt+1,dp);
        }
        else if(s[i]==')'){
            return dp[i][cnt]=check(i+1,s,cnt-1,dp);
        }
        else{
            return dp[i][cnt]=check(i+1,s,cnt,dp)|check(i+1,s,cnt+1,dp)|check(i+1,s,cnt-1,dp);
        }
    }
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return check(0,s,0,dp);
    }
};