class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int , vector<int> , greater<int>> minHeap; 
public:
    MedianFinder() {
       
    }
    
    void addNum(int num) {
      if(maxHeap.size() == 0) { maxHeap.push(num); return;}
      if(maxHeap.top() >= num) {
        maxHeap.push(num);
        
        if(maxHeap.size() > ( minHeap.size() + 1)){
            int temp = maxHeap.top();maxHeap.pop();
            minHeap.push(temp);
        }
      } else {
            minHeap.push(num);
            if(minHeap.size() > maxHeap.size()){
                int temp = minHeap.top(); minHeap.pop();
                maxHeap.push(temp);
            }
      }
    }
    
    double findMedian() {
       if(maxHeap.size() > minHeap.size())  { 
        return (double)maxHeap.top(); }
        else {
            return ((double)maxHeap.top() + (double)minHeap.top() )/ 2 ; 
        } 
    }
};
