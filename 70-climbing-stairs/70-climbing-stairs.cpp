class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int onestep = 1, twostep = 2;
        int ans = 0;
        
        for(int i = 3; i <= n; i++) {
            ans = onestep + twostep;
            onestep = twostep;
            twostep = ans;
        }
        
        return ans;
    }
};