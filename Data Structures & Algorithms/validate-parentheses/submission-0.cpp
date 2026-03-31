class Solution {
public:
    bool isValid(string s) {
        stack<char> s_stack;
        unordered_map<char , char> pairs = {{']' , '['} , {')' , '('} , {'}' , '{'}};

        for(char c : s){
            if(pairs.count(c) == 0){
                s_stack.push(c);
            } else {
                if(s_stack.empty() || pairs[c] != s_stack.top()) return false;
                s_stack.pop();
            }
        }

        return s_stack.empty() ? true : false;
    }
};
