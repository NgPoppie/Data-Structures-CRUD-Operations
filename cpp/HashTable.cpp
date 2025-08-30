#include <iostream>
#include <list>
#include <utility>
#include <string>

constexpr int TABLE_SIZE = 7;

class HashTable {
private:
    std::list<std::pair<int, std::string>> tableList[TABLE_SIZE];
    int HashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {}
    void insert(int key, std::string value) {
        bool isKeyFound = false;
        int hashKey = HashFunction(key);
        for (auto &keyValue : tableList[hashKey]) {
            if (keyValue.first == key) {
                isKeyFound = true;
                keyValue.second = value;
            }
        }
        if (!isKeyFound)
            tableList[hashKey].emplace_back(key, value);
    }
    std::string Search(int key) {
        int hashKey = HashFunction(key);
        for (auto &keyValue : tableList[hashKey]) {
            if (keyValue.first == key) {
                return keyValue.second;
            }
        }
        return "";
    }
    void remove(int key) {
        int hashKey = HashFunction(key);
        auto &cell = tableList[hashKey];
        for (auto it = cell.begin(); it != cell.end(); ++it) {
            if (it->first == key) {
                cell.erase(it);
                break;
            }
        }
    }
    bool isEmpty() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!tableList[i].empty())
                return false;
        }
        return true;
    }
    ~HashTable() = default;
};

int main() {
    HashTable ht;
    
    // Test 1: Check if table is initially empty
    std::cout << "Test 1: Is table empty? " << (ht.isEmpty() ? "Pass" : "Fail") << std::endl;

    // Test 2: Insert key-value pairs
    ht.insert(1, "One");
    ht.insert(2, "Two");
    ht.insert(8, "Eight"); // Collides with key 1 (1 % 7 == 8 % 7 == 1)
    std::cout << "Test 2: Inserted keys 1, 2, 8. Is table empty? " 
              << (!ht.isEmpty() ? "Pass" : "Fail") << std::endl;

    // Test 3: Search for inserted keys
    std::cout << "Test 3a: Search key 1: " << ht.Search(1) 
              << (ht.Search(1) == "One" ? " (Pass)" : " (Fail)") << std::endl;
    std::cout << "Test 3b: Search key 2: " << ht.Search(2) 
              << (ht.Search(2) == "Two" ? " (Pass)" : " (Fail)") << std::endl;
    std::cout << "Test 3c: Search key 8: " << ht.Search(8) 
              << (ht.Search(8) == "Eight" ? " (Pass)" : " (Fail)") << std::endl;

    // Test 4: Search for non-existent key
    std::cout << "Test 4: Search non-existent key 3: " << ht.Search(3) 
              << (ht.Search(3) == "" ? " (Pass)" : " (Fail)") << std::endl;

    // Test 5: Update existing key
    ht.insert(1, "UpdatedOne");
    std::cout << "Test 5: Updated key 1: " << ht.Search(1) 
              << (ht.Search(1) == "UpdatedOne" ? " (Pass)" : " (Fail)") << std::endl;

    // Test 6: Remove a key and verify
    ht.remove(2);
    std::cout << "Test 6: Removed key 2. Search key 2: " << ht.Search(2) 
              << (ht.Search(2) == "" ? " (Pass)" : " (Fail)") << std::endl;

    // Test 7: Remove non-existent key
    ht.remove(3); // Should not crash
    std::cout << "Test 7: Remove non-existent key 3: " 
              << (ht.Search(3) == "" ? "Pass" : "Fail") << std::endl;

    // Test 8: Remove all keys and check if empty
    ht.remove(1);
    ht.remove(8);
    std::cout << "Test 8: Removed all keys. Is table empty? " 
              << (ht.isEmpty() ? "Pass" : "Fail") << std::endl;

    return 0;
}
