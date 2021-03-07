class MyHashMap {
public:
    /** Initialize your data structure here. */
    list<pair<int, int>> table[16];
    MyHashMap() {
        for(int i=0;i<16;i++)
            table[i].clear();
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int index = key&15; //mod 16
        for(auto &p : table[index]) {
            if(p.first == key) {
                p.second = value;
                return;
            }                
        }
        table[index].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int index = key&15; //mod 16
        for(auto &p : table[index])
            if(p.first == key)
                return p.second; 
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int index = key&15; //mod 16
        list<pair<int, int>>::iterator it;
        for(it = table[index].begin(); it!=table[index].end(); ++it)
            if(it->first == key) {
                table[index].erase(it);
                return;
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */