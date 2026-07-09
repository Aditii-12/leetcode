class MedianFinder {
public:
    priority_queue<int>maxh;
    priority_queue<int,vector<int>,greater<>>minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minh.push(num);
        maxh.push(minh.top());
        minh.pop();
        if(maxh.size()-minh.size()>1){
            minh.push(maxh.top());
            maxh.pop();
        }
    }
    
    double findMedian() {
        if(minh.size()==maxh.size()){
            return ((minh.top()+maxh.top())/2.0);
        }
        return maxh.top()/1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */