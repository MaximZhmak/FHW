#ifndef CACHE_H
#define CACHE_H


#include <unordered_map>
#include <stdexcept>
#include <list>


template<typename K, typename V>
class LRUCache
{
public:
    typedef typename std::pair<K, V> pair;
    typedef typename std::list<pair>::iterator iterator;

    LRUCache(size_t capacity): m_capacity(capacity)
    {

    }


    // put value by key
    void Put(const K& key, const V& value)
    {
        auto it = m_map.find(key);
        m_list.push_front(pair(key, value));

        if (it!=m_map.end())
        {
            m_list.erase(it->second);
            m_map.erase(it);
        }
        m_map[key] = m_list.begin();

        if (m_map.size()>m_capacity)
        {
            auto last = m_list.end();
            last--;
            m_map.erase(last->first);
            m_list.pop_back();
        }
    }

    // Retrieves an entry from the cache that has been cached before
    // using put(). Returns the cached entry. Throws exception,
    // if there is no entry with the key K
    const V& Get(const K& key)
    {
        auto it = m_map.find(key);
        if(it==m_map.end())
        {
            throw std::range_error("There is no such key in cache!");
        }
        else
        {
            m_list.splice(m_list.begin(), m_list, it->second);
            return it->second->second;
        }
    }

    // Checks presence of the value by the given key
    bool Exists(const K& key)
    {
        return m_map.find(key)!=m_map.end();
    }

    // Clears all the entries in the cache
    void Clear()
    {
        m_list.clear();
        m_map.clear();
    }

    // Returns size
    size_t Size() const
    {
        return m_map.size();
    }



private:
    std::list<pair> m_list;
    std::unordered_map <K, iterator> m_map;
    size_t m_capacity;


};






#endif // CACHE_H
