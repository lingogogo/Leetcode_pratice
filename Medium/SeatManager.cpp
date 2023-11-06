/*class SeatManager {
public:
    set<int> number;
    SeatManager(int n) {
        for(int i =0; i <n; i++)
        {
            number.insert(i+1);
        }
    }
    
    int reserve() {
        int val = *number.begin();
        //number.erase(number.begin());
        number.erase(val);
        return val;
    }
    
    void unreserve(int seatNumber) {
        number.insert(seatNumber);
    }
};*/

class SeatManager {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    SeatManager(int n) {
        for(int i =0; i <n; i++)
        {
            minHeap.push(i+1);
        }
    }
    
    int reserve() {
        int val = minHeap.top();
        //number.erase(number.begin());
        minHeap.pop();
        return val;
    }
    
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
