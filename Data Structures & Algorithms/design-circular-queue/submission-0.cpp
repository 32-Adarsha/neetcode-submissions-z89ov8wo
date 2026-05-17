
struct Link {
  int value;
  std::shared_ptr<Link> next;
  std::weak_ptr<Link> prev;
  Link(int value) : value(value), next(nullptr) {}
};

class MyCircularQueue {
private:
  std::shared_ptr<Link> Head;
  std::shared_ptr<Link> Tail;
  int buffer_size = 0;
  int size = 0;

public:
  MyCircularQueue(int k) : buffer_size(k) {}

  bool enQueue(int value) {
    if (size >= buffer_size)
      return false;

    auto newNode = std::make_shared<Link>(value);

    if (!Head) {
      Head = newNode;
      Tail = newNode;
      Head->next = Head;
      Head->prev = Head;
    } else {
      Tail->next = newNode;
      newNode->prev = Tail;
      newNode->next = Head;
      Head->prev = newNode;
      Tail = newNode;
    }
    size++;
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;

    if (size == 1) {
      Head = nullptr;
      Tail = nullptr;
    } else {
      Head = Head->next;
      Head->prev = Tail;
      Tail->next = Head;
    }
    size--;
    return true;
  }

  int Front() { return isEmpty() ? -1 : Head->value; }
  int Rear() { return isEmpty() ? -1 : Tail->value; }
  bool isEmpty() { return size == 0; }
  bool isFull() { return size == buffer_size; }
};