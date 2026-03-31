class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(string data : strs){
            result += to_string(data.length()) + "#" + data;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int sLength = s.length();
        int counter = 0;
        while(counter < sLength ){
            string wordLength;
            while(s[counter] != '#'){
                wordLength += s[counter];
                counter++;
            }
            

            counter++;
            int len = stoi(wordLength);
            
            string word;
            for(int i = counter ; i < counter + len ; i++){
                word += s[i];
            }
            result.push_back(word);

            counter = counter + len;
        }

        return result;
    }
};
