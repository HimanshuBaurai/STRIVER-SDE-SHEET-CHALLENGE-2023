#include <bits/stdc++.h> 
class LRUCache
{
    int capacity;
    unordered_map<int,list<pair<int,int>>:: iterator>mpp;
    list<pair<int,int>>l;
public:
    LRUCache(int capacity)
    {
        this->capacity=capacity;
    }

    int get(int key)
    {
        if(mpp.find(key)==mpp.end()) return -1;

        int value=mpp[key]->second;
        l.erase(mpp[key]);
        l.push_front({key,value});
        mpp[key]=l.begin();

        return value;
    }

    void put(int key, int value)
    {
        if(mpp.find(key)!=mpp.end()){
            l.erase(mpp[key]);
            mpp.erase(key);
        }
        if(capacity==l.size()){
            pair<int,int> last=l.back();
            l.erase(mpp[last.first]);
            mpp.erase(last.first);
        }

        l.push_front({key,value});
        mpp[key]=l.begin();
    }
};
