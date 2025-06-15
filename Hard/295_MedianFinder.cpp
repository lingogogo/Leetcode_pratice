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
// method 2: TLE
// Explaination: The sort function is nlog(n), it spend too large time to solve the benchmarks.
class MedianFinder {
public:
    
    MedianFinder() {
        
    }
    
    void addNum(int n) {
        
        // cout << num.back() << endl;
        if(size_num != 0 && n < num.back()){
            // cout << "n: " << n << endl;
            this->num.push_back(n);
            sort(num.begin(),num.end());
            // for(int i = 0; i< num.size(); i++)
            // {
            //     cout << num[i] << endl;
            // }
            // cout << endl;
        }else{
            num.push_back(n);
        }
        size_num++;
    }
    
    double findMedian() {
        double output = 0;
        if(size_num % 2 == 0)
        {
            output = (double(num[size_num/2]) + double(num[size_num/2 - 1]))/2;
        }else{
            output = num[size_num/2];
        }

        return output;
    }
private:
    vector<int> num;
    int size_num = 0;
};
