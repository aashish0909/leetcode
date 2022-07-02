class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        for(int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
        }
        
        if(total < 0) return -1;
        
        int temp = 0;
        int start = 0;
        
        for(int i = 0; i < gas.size() - 1; i++) {
            temp += gas[i] - cost[i];
            if(temp < 0) {
                temp = 0;
                start = i + 1;
            }
        }
        
        return start;
    }
};