class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mArea = 0;
        int l = 0;
        int r = heights.size()-1;

        while ( l < r){
            int area = (r - l) * min(heights[r] , heights[l]);
            cout<<heights[r]<<" "<<heights[l]<<" "<<area<<endl;
            mArea = max(area , mArea);

            if (heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }

        }

        return mArea;
    }
};
