/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start

struct Val{
    int value;
    list<int>::iterator it;
    Val(int a, list<int>::iterator iter) : value(a), it(iter){}
};
class LRUCache {
private:
    int capacity;
    unordered_map<int,Val> m; // 哈希表存放指向双向链表的指针
    list<int> l;  // 双向链表, 存key
public:
    LRUCache(int cp) {
        capacity = cp;
    }
    int get(int key) {
        auto it = m.find(key);
        if(it != m.end()){ // 要找的key在缓存中
            l.splice(l.begin(), l, it->second.it);
            return it->second.value;
        }
        else return -1;        
    }
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()){ // 要找的key在缓存中
            l.splice(l.begin(), l, it->second.it);
            it->second.value = value;
        }
        else{ // 没找到
            if(m.size() == capacity){ // 缓存满了
                m.erase(l.back());
                l.pop_back();
            }
            l.push_front(key);
            Val v(value, l.begin());
            m.insert(std::pair<int,Val>(key,v));
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

