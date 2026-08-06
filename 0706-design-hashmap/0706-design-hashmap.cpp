#include <vector>
#include <list>
#include <utility>

class MyHashMap {
private:
    // Large prime size minimizes collision patterns
    int capacity = 20011; 
    
    // Array of linked lists storing {key, value} pairs
    std::vector<std::list<std::pair<int, int>>> buckets;

    // Maps any integer key to a valid array index
    int hash(int key) {
        return key % capacity;
    }

public:
    // Initialize array with empty buckets
    MyHashMap() {
        buckets.resize(capacity);
    }
    
    // Inserts or updates a key-value pair
    void put(int key, int value) {
        int idx = hash(key);
        
        // Scan bucket: if key exists, update value and exit
        for (auto& pair : buckets[idx]) {
            if (pair.first == key) {
                pair.second = value;
                return;
            }
        }
        // Key is new: append it to the bucket chain
        buckets[idx].emplace_back(key, value);
    }
    
    // Retrieves value for a given key
    int get(int key) {
        int idx = hash(key);
        
        // Scan bucket: return value if key is found
        for (const auto& pair : buckets[idx]) {
            if (pair.first == key) {
                return pair.second;
            }
        }
        // Key does not exist in the map
        return -1;
    }
    
    // Deletes a key and its value
    void remove(int key) {
        int idx = hash(key);
        auto& cell = buckets[idx]; // Reference to target bucket
        
        // Scan bucket using iterator to allow safe deletion
        for (auto it = cell.begin(); it != cell.end(); ++it) {
            if (it->first == key) {
                cell.erase(it); // Erase node from linked list
                return;
            }
        }
    }
};
