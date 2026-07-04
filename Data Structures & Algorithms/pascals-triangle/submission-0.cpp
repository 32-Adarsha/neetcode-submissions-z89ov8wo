
class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    if (numRows == 1)
      return {{1}};
    if (numRows == 2)
      return {{1}, {1, 1}};
    vector<vector<int>> result = {{1}, {1, 1}};

    for (int i = 2; i < numRows; ++i) {
      vector<int> LastRow = result[i - 1];
      vector<int> newRow = {1};
      for (int j = 1; j < LastRow.size(); ++j) {
        newRow.push_back(LastRow[j - 1] + LastRow[j]);
      }
      newRow.push_back(1);
      result.push_back(newRow);
    }

    return result;
  }
};

