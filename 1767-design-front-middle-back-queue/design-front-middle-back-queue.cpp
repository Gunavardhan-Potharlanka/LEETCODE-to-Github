class FrontMiddleBackQueue {
public:
    vector<int> v;
    int n=0;
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        v.insert(v.begin(), val);
        n++;
    }
    
    void pushMiddle(int val) {
        v.insert(v.begin()+n/2, val);
        n++;
    }
    
    void pushBack(int val) {
        v.push_back(val);
        n++;
    }
    
    int popFront() {
        if(n==0) return -1;
        int x=v[0];
        v.erase(v.begin(), v.begin()+1);
        n--;
        return x;
    }
    
    int popMiddle() {
        if(n==0) return -1;
        if(n%2==0){
            int x=v[(n/2)-1];
            v.erase(v.begin()+(n/2)-1, v.begin()+(n/2));
            n--;
            return x;
        }
        int x=v[n/2];
        v.erase(v.begin()+(n/2), v.begin()+(n/2)+1);
        n--;
        return x;
    }
    
    int popBack() {
        if(n==0) return -1;
        int x=v[n-1];
        v.pop_back();
        n--;
        return x;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */