class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> a;
        while(n > 0) {
            a.push_back(n%10);
            n /= 10;
        }
        
        reverse(a.begin(), a.end());
        
        int i;
        for(i = a.size() - 2; i >= 0; i--) {
            if(a[i] < a[i + 1])
                break;
        }
        
        if(i < 0) return -1;

        int j;
        for(j = a.size() - 1; j > i; j--) {
            if(a[j] > a[i]) break;
        }

        swap(a[i], a[j]);
        reverse(a.begin() + i + 1, a.end());
        
        long ans = 0;
        for(int i : a)
            ans = ans * 10 + i;
        
        return ans > INT_MAX ? -1 : ans;
    }
};