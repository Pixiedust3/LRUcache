class LRUCache {
    int capacity_;
    std::list<std::pair<int, int>> cache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end()) {
            return -1;
        }
        cache.splice(cache.begin(),cache,it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = map.find(key);

        if(it!=map.end())
        {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return ;
        }
        if(cache.size()>=capacity_)
        {
            auto last = cache.back();
            map.erase(last.first);
            cache.pop_back();
        }
        cache.emplace_front(key,value);
        map[key]=cache.begin();
    }
};
