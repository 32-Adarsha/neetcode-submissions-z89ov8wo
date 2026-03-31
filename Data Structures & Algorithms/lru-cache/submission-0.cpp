
struct Link {
  int val;
  int key;
  Link *prev;
  Link *next;

  Link(int key, int val) : val(val), key(key) {
    prev = nullptr;
    next = nullptr;
  }
};  

class LRUCache {
  int capacity = 0;
  Link *head = nullptr;
  Link *tail = nullptr;
  std::unordered_map<int, Link *> hash;

public:
  LRUCache(int capacity) : capacity(capacity) {
    head = new Link(0, 0);
    tail = new Link(0, 0);
    head->next = tail;  // Connect head and tail
    tail->prev = head;
  }

  void insert(Link *l) {
    l->next = head->next;
    l->prev = head;
    head->next->prev = l;
    head->next = l;
  }

  void remove(Link *l) {
    l->prev->next = l->next;
    l->next->prev = l->prev;
  }

  int get(int key) {
    if (hash.find(key) != hash.end()) {
      remove(hash[key]);
      insert(hash[key]);
      return hash[key]->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (hash.find(key) != hash.end()) {
      remove(hash[key]);
      hash[key]->val = value;
      insert(hash[key]);
    } else {
      if (hash.size() >= capacity) {  // Cache is full
        Link *lru = tail->prev;
        hash.erase(lru->key);
        remove(lru);
        delete lru;  // Free memory
      }
      Link *l = new Link(key, value);
      hash[key] = l;
      insert(l);
    }
  }
};