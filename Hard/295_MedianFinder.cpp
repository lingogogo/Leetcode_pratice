class MedianFinder {
public:
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>, greater<int>> minheap;
    MedianFinder() {
        
    }
    // Directed trace the median value.
    void addNum(int n) {
        if(maxheap.size() == 0 || n < maxheap.top())
        {
            maxheap.push(n);
        }else{ // n > maxheap.top()
            minheap.push(n);
        }
        // maxheap for median left and min heap for median right if the size of vector is even.
        if(maxheap.size() > minheap.size() + 1)
        {
            auto left_larger = maxheap.top();
            minheap.push(left_larger);
            maxheap.pop();
        }else if(maxheap.size() < minheap.size()){
            auto right_smaller = minheap.top();
            maxheap.push(right_smaller);
            minheap.pop();
        }
    }
    
    double findMedian() {
        double output = 0;
        int size = maxheap.size() + minheap.size();

        if(size % 2 == 0){
            return (maxheap.top() + minheap.top())/2.0;
        }else{
            return maxheap.top();
        }

        // return output;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
