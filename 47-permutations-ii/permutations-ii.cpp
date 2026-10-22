class Solution {
public:
    void check(int n,vector<int>&nums,vector<int>&ans,vector<vector<int>>&mat,vector<int>&vis,map<vector<int>,int>&mp){
        if(ans.size()==n && mp[ans]==0){
            mp[ans]++;
            mat.push_back(ans);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                ans.push_back(nums[i]);
                vis[i]=true;
                check(n,nums,ans,mat,vis,mp);
                ans.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        map<vector<int>,int>mp;
        vector<vector<int>>mat;
        vector<int>ans,vis(n,false);
        check(n,nums,ans,mat,vis,mp);
        return mat;
    }
};