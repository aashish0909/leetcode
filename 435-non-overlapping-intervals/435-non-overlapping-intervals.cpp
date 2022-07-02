class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        
        int count = 1;
        int prev = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= prev) {
                prev = intervals[i][1];
                ++count;
            }
        }
        
        return intervals.size() - count;
    }
    
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }
};