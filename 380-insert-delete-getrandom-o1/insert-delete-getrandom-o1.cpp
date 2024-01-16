class RandomizedSet {
public:
    vector<int> s;
    RandomizedSet() {
        set<int> s;
    }
    
    bool insert(int val) {
        vector<int>::iterator it=find(s.begin(), s.end(), val);
        if(it==s.end()){
            s.push_back(val);
            return true;    
        }
        return false;
    }
    
    bool remove(int val) {
        vector<int>::iterator it=find(s.begin(), s.end(), val);
        if(it!=s.end()){
            s.erase(it, it+1);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return s[rand()%s.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */