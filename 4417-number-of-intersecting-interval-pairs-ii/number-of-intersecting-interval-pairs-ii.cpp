class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& mat) {
        sort(mat.begin(),mat.end());
        long long cnt=0;
        for(int i=0;i<mat.size();i++){
           int left=i+1;
           int right=mat.size()-1;
           long long res=i;
           while(left<=right){
               int mid=(left)+(right-left)/2;
               if(mat[mid][0]<=mat[i][1]){
                    left=mid+1;
                    res=mid;
               }
               else{
                    right=mid-1;
               }
           }
           cnt+=res-i;
        }
        return cnt;
    }
};