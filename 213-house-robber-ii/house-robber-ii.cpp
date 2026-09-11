#include <vector>
#include <algorithm>
class Solution {
    int solve(std::vector<int>& nums,int start,int end) {
        int p2=0;
        int p1=0;
        for (int i=start;i<=end;++i) {
            int curr=std::max(p1,p2+nums[i]);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
public:
    int rob(std::vector<int>& nums) {
        int n=nums.size();
        if (n==0)return 0;
        if (n==1)return nums[0];
        return std::max(solve(nums,0,n-2),solve(nums,1,n-1));
    }
};
