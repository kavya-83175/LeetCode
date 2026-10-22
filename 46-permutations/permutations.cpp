class Solution {
public:
    void check(vector<int>&nums,vector<vector<int>>&mat,vector<int>&vis,vector<int>&ans){
        if(ans.size()==nums.size()){
            mat.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(vis[i]==false){
                ans.push_back(nums[i]);
                vis[i]=true;
                check(nums,mat,vis,ans);
                ans.pop_back();
                vis[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>vis(n,false),ans;
        vector<vector<int>>mat;
        check(nums,mat,vis,ans);
        return mat;
    }
};