class Solution {
public:
    bool canAliceWin(int n) {
        int cnt=0,p=10;
        while(n>=p){
            n-=p;
            cnt++;
            p--;
        }
        if(cnt%2!=0) return true;
        return false;
    }
};