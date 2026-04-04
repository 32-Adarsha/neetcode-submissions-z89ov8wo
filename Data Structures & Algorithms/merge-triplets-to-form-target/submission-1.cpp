
class Solution {
public:
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    // NOTE: Logic for every element in target
    // If i find the in sub array of triplets i will check if every is smaller
    // or equall to other

    int canExtract = 0;
    vector<bool> foundTarget(3, false);
    for (auto triplet : triplets) {
      canExtract += canFind(0, 1, 2, triplet, target, foundTarget);
      canExtract += canFind(1, 0, 2, triplet, target, foundTarget);
      canExtract += canFind(2, 0, 1, triplet, target, foundTarget);

      if (canExtract >= 3) {
        return true;
      }
    }

    return false;
  }
  int canFind(int x, int y, int z, const vector<int> &triplet,
              const vector<int> &target, vector<bool> &foundTarget) {
    if (triplet[x] == target[x] && triplet[y] <= target[y] &&
        triplet[z] <= target[z]) {
      if (!foundTarget[x]) {
        foundTarget[x] = true;
        return true;
      }
    }

    return false;
  }
};

