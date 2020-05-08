/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache {
public:
    int capacity;
    unordered_map<int,int> m;
    unordered_map<int,int> timeStamp; 
    LRUCache(int cp) {
        capacity = cp;
    }
    
    int get(int key) {
        if((*this).m.find(key) != (*this).m.end()){
            timeStamp[key]++;
            return m[key];
        }
        else return -1;        
    }
    
    void put(int key, int value) {
        if((*this).m.find(key) != (*this).m.end())
            m[key] = value;
        else{
            if(m.size() < capacity) m[key] = value;

        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

