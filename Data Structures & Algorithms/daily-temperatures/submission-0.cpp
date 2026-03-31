class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        std::stack<pair<int ,int>> s;
        // NOTE: so that the last remain the minnimum
        t.push_back(0);
        std::vector<int> result(t.size()-1 , 0);
        for(int i = 0 ; i < t.size()-1; ++i){
            if(t[i+1] > t[i]){
                result[i] = 1;
            }else {
                s.push({t[i] , i});
            }

            if(!s.empty()){
                cout<<s.top().first<<" "<<t[i+1]<<endl;
            }  
            while(!s.empty() && s.top().first < t[i+1]){
                int days = (i+1) - s.top().second;
                result[s.top().second] = days; 
                cout<<"Here"<<endl;
                s.pop();
            }
        }


        return result;
            
    }
};
