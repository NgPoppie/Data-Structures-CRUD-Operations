#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

template<typename T>
class GenericList {
private:
    std::list<T> data; // std::list for dynamic sizing

public:
    // Constructor to initialize the list from an array
    GenericList(const T* initialData, size_t initialSize) {
        data.assign(initialData, initialData + initialSize);
    }

    // Create: Add a value to the end
    void add(const T& value) {
        data.push_back(value);
        std::cout << "Added: " << value << std::endl;
    }

    // Read: Search for a value
    void search(const T& value) const {
        auto it = std::find(data.begin(), data.end(), value);
        if (it != data.end()) {
            size_t index = std::distance(data.begin(), it);
            std::cout << "Found: " << value << " at index " << index << std::endl;
        } else {
            std::cout << "Not found: " << value << std::endl;
        }
    }

    // Update: Replace first occurrence of oldValue with newValue
    void update(const T& oldValue, const T& newValue) {
        auto it = std::find(data.begin(), data.end(), oldValue);
        if (it != data.end()) {
            *it = newValue;
            std::cout << "Updated: " << oldValue << " to " << newValue << std::endl;
        } else {
            std::cout << "Not found, cannot update: " << oldValue << std::endl;
        }
    }

    // Delete: Remove first occurrence of value
    void deleteValue(const T& value) {
        auto it = std::find(data.begin(), data.end(), value);
        if (it != data.end()) {
            data.erase(it);
            std::cout << "Deleted: " << value << std::endl;
        } else {
            std::cout << "Not found, cannot delete: " << value << std::endl;
        }
    }

    // Print list contents
    void print() const {
        std::cout << "[";
        for (auto it = data.begin(); it != data.end(); ++it) {
            std::cout << *it;
            if (std::next(it) != data.end()) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    // Example with integers
    int intData[] = {4, 7, 6, 8, 34, 43, 65, 34};
    size_t intSize = sizeof(intData) / sizeof(intData[0]);
    GenericList<int> intList(intData, intSize);
    std::cout << "Initial Integer List: ";
    intList.print();
    intList.search(6);
    intList.add(99);
    std::cout << "After adding 99: ";
    intList.print();
    intList.update(34, 100);
    std::cout << "After updating 34 to 100: ";
    intList.print();
    intList.deleteValue(8);
    std::cout << "After deleting 8: ";
    intList.print();

    // Example with doubles
    double doubleData[] = {4.5, 7.2, 6.1, 8.9};
    size_t doubleSize = sizeof(doubleData) / sizeof(doubleData[0]);
    GenericList<double> doubleList(doubleData, doubleSize);
    std::cout << "\nInitial Double List: ";
    doubleList.print();
    doubleList.search(6.1);
    doubleList.add(10.5);
    std::cout << "After adding 10.5: ";
    doubleList.print();
    doubleList.update(7.2, 9.3);
    std::cout << "After updating 7.2 to 9.3: ";
    doubleList.print();
    doubleList.deleteValue(8.9);
    std::cout << "After deleting 8.9: ";
    doubleList.print();

    // Example with strings
    std::string strData[] = {"apple", "banana", "cherry", "date"};
    size_t strSize = sizeof(strData) / sizeof(strData[0]);
    GenericList<std::string> strList(strData, strSize);
    std::cout << "\nInitial String List: ";
    strList.print();
    strList.search("banana");
    strList.add("grape");
    std::cout << "After adding grape: ";
    strList.print();
    strList.update("cherry", "fig");
    std::cout << "After updating cherry to fig: ";
    strList.print();
    strList.deleteValue("date");
    std::cout << "After deleting date: ";
    strList.print();

    return 0;
}
