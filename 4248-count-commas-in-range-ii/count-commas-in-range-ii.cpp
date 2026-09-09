class Solution {
public:
    long long countCommas(long long n){
        long long totalCommas=0;
        for(long long x=1000;x<=n;x*=1000){
            totalCommas += (n - x + 1);
            if(x > LLONG_MAX / 1000){
                break;
            }
        }
        return totalCommas;
    }
};
