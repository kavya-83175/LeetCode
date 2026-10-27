class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty()){
                // cout<<s[i]<<" "<<st.top()<<endl;
                if(s[i]==')' && st.top()=='('){
                    st.pop();
                }
                else if(s[i]==']' && st.top()=='['){
                    st.pop();
                }
                else if(s[i]=='}' && st.top()=='{'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size()==0?1:0;
    }
};