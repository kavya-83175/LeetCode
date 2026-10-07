class Solution {
public:
    void check(string dig,map<char,string>&mp,vector<string>&ans,string dum,int j){
        if(dum.size()>=dig.size()){
            if(dum.size()==dig.size()){
                ans.push_back(dum);
            }
            return;
        }
        for(int i=j;i<dig.size();i++){
            for(char p:mp[dig[i]]){
                check(dig,mp,ans,dum+p,i+1);
            }
        }
        
    }
    vector<string> letterCombinations(string dig) {
        map<char,string>mp;
        mp['2']="abc",mp['3']="def",mp['4']="ghi",mp['5']="jkl",mp['6']="mno",mp['7']="pqrs",mp['8']="tuv",mp['9']="wxyz";
        string dum="";
        vector<string>ans;
        check(dig,mp,ans,dum,0);
        return ans;
    }
};