class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& small = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        vector<int>& big   = (nums1.size() <= nums2.size()) ? nums2 : nums1;

        int total = small.size() + big.size();
        int half  = (total + 1) / 2;
        bool even = (total % 2 == 0);

        int l = 0, r = small.size();

        while (l <= r) {
            int i = (l + r) / 2;       // cut in small (# of elements from small on left)
            int j = half - i;          // cut in big   (# of elements from big on left)

            int Aleft  = (i > 0)             ? small[i - 1] : INT_MIN;
            int Aright = (i < (int)small.size()) ? small[i]     : INT_MAX;
            int Bleft  = (j > 0)             ? big[j - 1]   : INT_MIN;
            int Bright = (j < (int)big.size())   ? big[j]       : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {
                if (even)
                    return ((double)max(Aleft, Bleft) + (double)min(Aright, Bright)) / 2;
                else
                    return (double)max(Aleft, Bleft);
            } else if (Aleft > Bright) {
                r = i - 1;  // move cut left in small
            } else {
                l = i + 1;  // move cut right in small
            }
        }
        return -1;
    }
};