class Solution {
public:
    void check(vector<int>&dig,vector<int>&vis,vector<int>&arr,string s){
        if(s.size()==3){
            if(stoi(s)%2==0)
            arr.push_back(stoi(s));
            return;
        }
        for(int i=0;i<dig.size();i++){
            if(vis[i]==true) continue;
            if(s.size()==0 && dig[i]==0) continue;
            vis[i]=true;
            check(dig,vis,arr,s+char(dig[i]+'0'));
            vis[i]=false;
        }
    }
    vector<int> findEvenNumbers(vector<int>& dig) {
        vector<int>vis(dig.size(),false);
        vector<int>arr;
        check(dig,vis,arr,"");
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        return arr;
    }
};