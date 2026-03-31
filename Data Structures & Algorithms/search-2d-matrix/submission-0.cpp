
class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int width = matrix[0].size();
    int height = matrix.size() - 1;

    // NOTE: Finding the row first
    int top = 0;
    while (top <= height) {
      int mid = (top + height) / 2;
      if (target < matrix[mid][0]) {
        height = mid - 1;
      } else if (target > matrix[mid][width - 1]) {
        top = mid + 1;
      } else {
        // NOTE: The searched value is in this row ( mid )
        int left = 0;
        int right = width - 1;
        while (left <= right) {
          int rowMid = (left + right) / 2;
          if (matrix[mid][rowMid] == target) {
            return true;
          } else if (matrix[mid][rowMid] > target) {
            right = rowMid - 1;
          } else {
            left = rowMid + 1;
          }
        }

        return false;
      }
    }
    return false;
  }
};
