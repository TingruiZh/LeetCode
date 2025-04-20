#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache; // 双向链表 {key, value}
    unordered_map<int, list<pair<int, int>>::iterator> mp; // key -> list 的迭代器

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        // 将该节点移动到链表前端（表示最近使用）
        cache.splice(cache.begin(), cache, mp[key]);
        return mp[key]->second;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // 更新值并移动到前端
            mp[key]->second = value;
            cache.splice(cache.begin(), cache, mp[key]);
        } else {
            // 超出容量，删除尾部最久未使用元素
            if (cache.size() == cap) {
                int old_key = cache.back().first;
                cache.pop_back();
                mp.erase(old_key);
            }
            // 插入新元素到前端
            cache.emplace_front(key, value);
            mp[key] = cache.begin();
        }
    }
};
