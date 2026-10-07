class Solution {
public:
    int minRotations(int n, string s) {
        int idx=-1,to=0,maxi=INT_MIN;
        n--;
        for(int i=0;i<s.size();i++){
            int val=(int)(s[i]-'0');
            int val2=(int)(s[n]-'0');
            int a=min(abs(to-val),(min(to,val)+1+(9-max(to,val))));
            int b=min(abs(to-val2),(min(to,val2)+1+(9-max(to,val2))));
            if(maxi<(a-b)){
                // cout<<a<<" "<<b<<" ";
                idx=i;
                maxi=(a-b);
                // break;
            }
            to=val;
        }
        // cout<<idx;
        int k=0,ans=0;
        if(idx==-1){
            for(int i=0;i<s.size();i++){
                int val=(int)(s[i]-'0');
                ans+=min(abs(k-val),(min(k,val)+1+(9-max(k,val))));
                k=val;
            }
            return ans;
        }
        for(int i=0;i<idx;i++){
            int val=(int)(s[i]-'0');
            ans+=min(abs(k-val),(min(k,val)+1+(9-max(k,val))));
            k=val;
        }
        // cout<<" "<<ans;
        for(int i=s.size()-1;i>=idx;i--){
            int val=(int)(s[i]-'0');
            ans+=min(abs(k-val),(min(k,val)+1+(9-max(k,val))));
            // cout<<ans<<" ";
            k=val;
        }
        return ans;
    }
};