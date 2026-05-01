class Solution {
public:
    int maxArea(vector<int>& heights) {
        int size = heights.size();
        int left = 0 , right = size - 1;
        int maxArea = INT_MIN;
        while(left < right)
        {   
            int curArea = min(heights[left], heights[right]) * (right-left);
            maxArea = max(curArea, maxArea);
            if(heights[left] >= heights[right])
                right--;
            else
                left++;
        }
        return maxArea;
    }
};
