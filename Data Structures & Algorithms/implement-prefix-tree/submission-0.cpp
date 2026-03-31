struct Tracker {
    bool hasEnd = false;
    vector<Tracker*> children;

    Tracker() : children(26 , nullptr) {}; 

};




class PrefixTree {
public:
    Tracker* root;
    PrefixTree(){
        root = new Tracker();
    }
    
    void insert(string word) {
        Tracker* head = root;
        for(char c : word){
            int index = c - 'a';
            if(head->children[index] == nullptr){
                head->children[index] = new Tracker();
            }
            head = head->children[index];
        };

        head->hasEnd = true;    
    }
    
    bool search(string word) {
       Tracker* head = root;
       for(char c : word){
         int index = c - 'a';
         if(head->children[index] == nullptr) return false;
         head = head->children[index];
       }
       
       if(head->hasEnd){
         return true;    
       }
       return false; 
    }
    
    bool startsWith(string prefix) {
       Tracker* head = root;
       for(char c : prefix){
         int index = c - 'a';
         if(head->children[index] == nullptr) return false;
         head = head->children[index];
       }
       return true;   
    }
};
