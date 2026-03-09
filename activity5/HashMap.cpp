#include <vector>
#include <list>
#include <string>
#include <iostream>
using namespace std;

class HashTable {
private:
    vector<list<pair<string, int>>> table;
    int currentSize;
    int capacity;
    int collisionCount;

    int hashFunction(const string& key) const;
    void rehash() {

        auto old_table = move(table);

        capacity *= 2; // Double the capacity

        // New table with twice the capacity than the old
        table.clear();
        table.resize(capacity);

        collisionCount = 0;
        currentSize = 0;

        // Reinserts elements in old table into the new table
        for (auto& bucket : old_table) {
            for (auto& link : bucket) {
                insert(link.first, link.second);
            }
        }

    };

public:
    HashTable(int size = 11) {
        currentSize = 0;
        capacity = size;
        collisionCount = 0;
        table.resize(capacity);
    }

    void insert(const string& key, int value) {

        // Generates hash of the key
        int hash = hashFunction(key);
        auto& bucket = table[hash];

        // Updates value if same key is being written
        for (auto& link : bucket) {
            if (link.first == key) {
                link.second = value;
                return;
            }
        }

        // Incrementing collision if inserting into an non-empty bucket
        if (bucket.size() > 0) {
            collisionCount++;
        }

        // Creates new value at a key if such key doesn't already exist
        bucket.push_back({key, value});
        currentSize++;

        if (loadFactor() >= 0.75) {
            rehash();
        }

    }

    // Removes selected element from the hash table
    bool remove(const string& key) {
        int hash = hashFunction(key);
        auto& bucket = table[hash];

        int remove_index = 0;
        for (auto it = bucket.begin(); it != bucket.end(); it++) {
            if (it->first == key) {
                bucket.erase(it);
                currentSize--;
                return true;
            }
        }

        return false;
    };

    // Gets the selected element from the hash table
    int search(const string& key) const {
        
        int hash = hashFunction(key);

        for (pair<string, int> link : table[hash]) {
            if (link.first == key) {
                return link.second;
            }
        }

        return 0;

    }

    
    double loadFactor() const {
        return (double)currentSize / capacity;
    }
    int size() const {
        return currentSize;
    }
    bool isEmpty() const {
        return currentSize == 0;
    }
    void printTable() const {
        cout << "HashTable " << this << ":" << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Number of elements: " << currentSize << endl;
        cout << "Load factor: " << loadFactor() << endl;
        cout << "Total collisions: " << collisionCount << endl;
        cout << endl;
    }
};

int HashTable::hashFunction(const string& key) const {
    const int prime = 31;
    long long hash = 0;

    for (char c : key) {
        hash = hash * prime + c;
    }

    return hash % capacity;
}