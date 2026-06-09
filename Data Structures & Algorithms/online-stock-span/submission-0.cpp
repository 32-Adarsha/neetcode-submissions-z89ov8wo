
class StockSpanner {
private:
  stack<pair<int, int>> SpannerStack;

public:
  StockSpanner() {}

  int next(int price) {
    if (SpannerStack.size() == 0) {
      SpannerStack.push({price, 1});
      return 1;
    }

    pair<int, int> temp = {price, 1};
    while (!SpannerStack.empty() && SpannerStack.top().first <= price) {
      temp.second += SpannerStack.top().second;
      SpannerStack.pop();
    }

    SpannerStack.push(temp);

    return temp.second;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */