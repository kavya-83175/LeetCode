class Solution {
public:
    string reverseWords(string s) {
        vector<string>str;
        int t=0;
        string dum="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                t=1;
                dum+=s[i];
            }
            else{
                if(t==1){
                    str.push_back(dum);
                    dum="";
                    t=0;
                }
            }
        }
        if(t==1) str.push_back(dum);
        string ans="";
        for(int i=str.size()-1;i>=0;i--){
            ans+=str[i]+" ";
        }
        ans.pop_back();
        return ans;
    }
};