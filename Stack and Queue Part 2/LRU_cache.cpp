#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
    int capacity;
    list<pair<int, int>> lruList;
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        auto it = cache.find(key);

        if (it == cache.end())
            return -1;

        lruList.splice(lruList.begin(), lruList, it->second);
        return it->second->second;
    }

    void put(int key, int value)
    {
        auto it = cache.find(key);
        if (it != cache.end())
        {
            it->second->second = value;
            lruList.splice(lruList.begin(), lruList, it->second);
        }
        else
        {
            if (cache.size() == capacity)
            {
                int keyToRemove = lruList.back().first;
                cache.erase(keyToRemove);
                lruList.pop_back();
            }

            lruList.push_front({key, value});
            cache[key] = lruList.begin();
        }
    }
};