
using namespace std;

struct Node {
  int key;
  int value;
  int frequency = 1;
  Node *prev = nullptr;
  Node *next = nullptr;
  Node(int key, int value) : key(key), value(value) {}
};

class LFUCache {
private:
  Node *Head = new Node(-1, -1);
  Node *Tail = new Node(-1, -1);
  map<int, Node *> keyMap;
  int space = 0;

public:
  LFUCache(int capacity) : space(capacity) {
    Head->next = Tail;
    Tail->prev = Head;
  }

  int get(int key) {
    auto it = keyMap.find(key);
    if (it != keyMap.end()) {
      it->second->frequency += 1;
      updatePosition(it->second);
      return it->second->value;
    }
    return -1;
  }

  void put(int key, int value) {
    auto it = keyMap.find(key);
    if (it == keyMap.end()) {
      Node *newNode = new Node(key, value);
      if (space == 0) {
        Node *temp = Tail->prev;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        keyMap.erase(temp->key);
        delete temp;
        space += 1;
      }

      newNode->prev = Tail->prev;
      newNode->next = Tail;
      newNode->prev->next = newNode;
      Tail->prev = newNode;

      keyMap[key] = newNode;
      space -= 1;
      updatePosition(newNode);
    } else {
      Node *temp = it->second;
      temp->value = value;
      temp->frequency += 1;
      updatePosition(temp);
    }
  }

  void updatePosition(Node *node) {
    // Save predecessor before detaching
    Node *savedPrev = node->prev;

    // Detach node
    node->prev->next = node->next;
    node->next->prev = node->prev;

    // Walk backward from saved position to find insertion point
    Node *temp = savedPrev;
    while (temp != Head && temp->frequency <= node->frequency) {
      temp = temp->prev;
    }

    // Insert after temp
    node->next = temp->next;
    node->prev = temp;
    temp->next->prev = node; // ← also missing in original
    temp->next = node;
  }
};

