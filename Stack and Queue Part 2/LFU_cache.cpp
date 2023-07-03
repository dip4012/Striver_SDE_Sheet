#include <bits/stdc++.h>
using namespace std;

class LFUCache
{
    // key: frequency, value: listt of all key-value pairs with the same frequency. most recent accesed is at the end of the list.
    unordered_map<int, list<pair<int, int>>> frequencies;

    // key: key, value: frequency and the iterator to the corresponding key-value pair node in the frequency list
    unordered_map<int, pair<int, list<pair<int, int>>::iterator>> cache;

    int capacity;
    int minfreq;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        this->minfreq = 0;
    }

    int get(int key)
    {
        auto it = cache.find(key);

        if (it == cache.end())
            return -1;
        else
        {
            // delete the key from the current frequency list
            int f = it->second.first;
            auto iter = it->second.second;
            pair<int, int> kv = *iter;
            frequencies[f].erase(iter);

            // if frequency list is empty then remove the frequency value from the map and update the minimum frequency value
            if (frequencies[f].empty())
            {
                frequencies.erase(f);
                if (minfreq == f)
                    minfreq++;
            }

            // insert the {key,value} pair to the f+1 frequency list
            f++;
            frequencies[f].push_back(kv);
            cache[key] = {f, --frequencies[f].end()};
            return kv.second;
        }
    }

    void put(int key, int value)
    {
        auto it = cache.find(key);

        if (it == cache.end())
        {
            // if capacity of the cache is full remove the least referenced among the least frequent elements
            if (cache.size() == capacity)
            {
                pair<int, int> kv = frequencies[minfreq].front();
                frequencies[minfreq].pop_front();
                cache.erase(kv.first);

                if (frequencies[minfreq].empty())
                {
                    frequencies.erase(minfreq);
                    minfreq++;
                }
            }

            // insert the new {key,value} pair into the frequencies[1] list and reference it in the cache
            frequencies[1].push_back({key, value});
            cache[key] = {1, --frequencies[1].end()};
            minfreq = 1;
        }
        else
        {
            // get(key) places the existing {key, value} pair in the desired frequency list
            get(key);
            cache[key].second->second = value;
        }
    }
};