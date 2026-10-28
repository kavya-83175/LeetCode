class Solution {
public:
    void check(string dum,string &s,vector<string>&str,int i,int &n){
        if(i>=n){
            str.push_back(dum);
            return;
        }
        check(dum+s[i],s,str,i+1,n);
        if(s[i]>='A' && s[i]<='z'){
            if(s[i]>='a' && s[i]<='z')
            check(dum+(char)(s[i]-32),s,str,i+1,n);
            else
            check(dum+(char)(s[i]+32),s,str,i+1,n);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>str;
        int n=s.size();
        check("",s,str,0,n);
        return str;
    }
};