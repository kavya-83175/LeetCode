class Solution {
public:
    bool check(int n,long long sum,long long a,long long b,long long c){
        // int cnt=0;
        while(sum<n){
            sum=a+b+c;
            // cnt++;
            a=b;
            b=c;
            c=a+b;
        }
         // cout<<cnt<<" ";
        if(sum==n) return 1;
        return 0;
    }
    bool threeFibonacciSum(int n) {
        long long sum=0,a=0,b=1,c=1;
        return check(n,sum,a,b,c);
    }
};