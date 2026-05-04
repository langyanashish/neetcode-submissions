class MedianFinder {
    std::priority_queue<int> pqMax;
    std::priority_queue<int, vector<int>, greater<int> > pqMin;
public:
    MedianFinder() {
        pqMax = priority_queue<int>();
        pqMin = priority_queue<int, vector<int>, greater<int> >();
    }
    
    void addNum(int num) {
        pqMax.push(num);
        if(!pqMin.empty() && pqMax.top() > pqMin.top())
        {
            pqMin.push(pqMax.top());
            pqMax.pop();
        }
        if(pqMax.size() > pqMin.size() + 1)
        {
            pqMin.push(pqMax.top());
            pqMax.pop();
        }
        if(pqMin.size() > pqMax.size() + 1)
        {
            pqMax.push(pqMin.top());
            pqMin.pop();
        }
    }
    
    double findMedian() {
        if(pqMin.size() == pqMax.size())
            return (pqMin.top() + pqMax.top()) / 2.0;
        else if(pqMax.size() > pqMin.size())
            return pqMax.top();
        else
            return pqMin.top(); 
    }
};

//5 3 7 2


