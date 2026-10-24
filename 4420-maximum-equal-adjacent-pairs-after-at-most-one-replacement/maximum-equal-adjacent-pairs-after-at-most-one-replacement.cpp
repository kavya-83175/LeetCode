class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int cnt=0,need=0;
        map<pair<int,int>,int>mp;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                cnt++;
            }
            else{
                int x=min(nums[i],nums[i+1]);
                int y=max(nums[i],nums[i+1]);
                mp[{x,y}]++;
                need=max(need,mp[{x,y}]);
            }
        }
        return need+cnt;
    }
};