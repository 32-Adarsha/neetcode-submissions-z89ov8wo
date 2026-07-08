class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int result = 0;
        set<string> uniqueEmail;
        for(string email : emails){
            // Getting the local Name
            string dirtyEmail = "";
            int i = 0;
            while(i < email.length()){
                if(email[i] == '@'){
                    i++;
                    break;
                }
                dirtyEmail += email[i];
                i++;
            }

            string localName = cleanLocalName(dirtyEmail);
            string domainName = "";
            while(i < email.length()){
                domainName += email[i];
                i++;
            }

            string clean_email = localName + "@" + domainName;
            uniqueEmail.insert(clean_email);
        }

        return uniqueEmail.size();
    }

    string cleanLocalName(string email){
        string clean_email = "";
        for(char c : email){
            if(c == '.') continue;
            if(c == '+') return clean_email;
            clean_email += c;
        }
        return clean_email;
    }  
};