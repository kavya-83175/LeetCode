class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        vector<int>need,ans;
        for(int it:st){
            // cout<<it<<" ";
            need.push_back(it);
        }
        while(mp.size()>0){
            set<int>st2;
            for(int i=0;i<need.size();i++){
                if(mp.find(need[i])!=mp.end()){
                    st2.insert(need[i]);
                    mp[need[i]]--;
                    if(mp[need[i]]==0){
                        mp.erase(need[i]);
                    }
                }
            }
            for(int it:st2){
                ans.push_back(it);
            }
        }
        return ans;
    }
};