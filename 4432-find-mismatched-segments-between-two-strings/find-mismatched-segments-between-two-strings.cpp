class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        string str1="",str2="";
        vector<vector<string>>ans;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]){
                vector<string>dum;
                if(str1.size()>0){
                    dum.push_back(str1);
                }
                if(str2.size()>0){
                    dum.push_back(str2);
                }
                if(dum.size()>0)
                ans.push_back(dum);
                str1="",str2="";
            }
            else{
                str1+=s1[i];
                str2+=s2[i];
            }
        }
        vector<string>dum;
        if(str1.size()>0){
            dum.push_back(str1);
        }
        if(str2.size()>0){
            dum.push_back(str2);
        }
        if(dum.size()>0) ans.push_back(dum);
        return ans;
    }
};