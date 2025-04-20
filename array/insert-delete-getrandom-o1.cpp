class RandomizedSet {
public:
    RandomizedSet() {
    }
    std::vector<int> data; // 用于随机访问
    std::unordered_map<int, int> valToIndex; // 记录值到下标的映射
    bool insert(int val) {
        if (valToIndex.count(val)) return false;
        data.push_back(val);
        valToIndex[val] = data.size() - 1;
        return true;
    }

    // 删除元素
    bool remove(int val) {
        if (!valToIndex.count(val)) return false;

        // 把要删除的元素与最后一个交换，然后删除最后一个元素
        int idx = valToIndex[val];
        int lastVal = data.back();

        data[idx] = lastVal;
        valToIndex[lastVal] = idx;

        data.pop_back();
        valToIndex.erase(val);
        return true;
    }

    // 获取随机元素
    int getRandom() {
        int randIdx = rand() % data.size();
        return data[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */