class LRUCache {
private:
    int _capacity;
    list<pair<int, int>> _cacheList;
    unordered_map<int, list<pair<int, int>>::iterator> _cacheMap;

public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        if (_cacheMap.find(key) == _cacheMap.end()) {
            // Key not found in cache
            return -1;
        }
        // Move the key-value pair to the front of the cache list
        _cacheList.splice(_cacheList.begin(), _cacheList, _cacheMap[key]);
        // Return the value associated with the key
        return _cacheMap[key]->second;
    }

    void put(int key, int value) {
        if (_cacheMap.find(key) != _cacheMap.end()) {
            // Key already exists in cache
            // Update the value and move the key-value pair to the front of the cache list
            _cacheMap[key]->second = value;
            _cacheList.splice(_cacheList.begin(), _cacheList, _cacheMap[key]);
        } else {
            // Key does not exist in cache
            if (_cacheList.size() == _capacity) {
                // Remove the least recently used key-value pair from the cache
                int lastKey = _cacheList.back().first;
                _cacheMap.erase(lastKey);
                _cacheList.pop_back();
            }
            // Add the new key-value pair to the front of the cache list
            _cacheList.push_front({key, value});
            _cacheMap[key] = _cacheList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */