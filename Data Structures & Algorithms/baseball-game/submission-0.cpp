class Solution {
public:
    int calPoints(vector<string>& operations) {
       stack<int> s; 
       for(auto value : operations){
           if(value == "+" || value == "D") {
              int first = s.top(); s.pop();
              int newOne = (value == "D") ? first * 2 : s.top() + first;
              s.push(first);
              s.push(newOne);
           } else if ( value == "C"){
              s.pop();
           } else {
              s.push(stoi(value));
           }
       }

       int total = 0;
       while(!s.empty()){
          total += s.top();
          s.pop();
       }

       return total;


    }
};