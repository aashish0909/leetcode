//Solution 1

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMin(n), rightMin(n);
        stack<int> st;


        //Left Minimum
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty()) leftMin[i] = 0;
            else leftMin[i] = st.top() + 1;

            st.push(i);
        }

        //Empty the stack
        while (!st.empty()) st.pop();

        //Right Minimum
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();

            if (st.empty()) rightMin[i] = n - 1;
            else rightMin[i] = st.top() - 1;

            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int currArea = heights[i] * (rightMin[i] - leftMin[i] + 1);
            ans = max(ans, currArea);
        }

        return ans;
    }
};