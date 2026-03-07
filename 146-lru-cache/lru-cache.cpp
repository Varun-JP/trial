class LRUCache {
    int cap;

    list<pair<int,int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {

        auto it = mp.find(key);
        if(it == mp.end()) return -1;

        int value = it->second->second;

        cache.erase(it->second);
        cache.push_front({key,value});

        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {

        auto it = mp.find(key);

        if(it != mp.end()){
            cache.erase(it->second);
        }
        else if(cache.size() == cap){
            auto last = cache.back();
            mp.erase(last.first);
            cache.pop_back();
        }

        cache.push_front({key,value});
        mp[key] = cache.begin();
    }
};