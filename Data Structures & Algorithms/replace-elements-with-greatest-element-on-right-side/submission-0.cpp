class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxElm = -1;
        for (int i = arr.size()-1 ; i >=0 ; i--){
            int temp = arr[i];
            arr[i] = maxElm;
            maxElm = max(temp , maxElm);
        }

        return arr;
    }
};