#include <iostream>
#include <string>
#include <algorithm>

template<typename T>
class GenericArray {
private:
    T* data; // Dynamic array to store elements
    size_t size; // Current size of the array

public:
    // Constructor to initialize the array
    GenericArray(const T* initialData, size_t initialSize) {
        size = initialSize;
        data = new T[size];
        std::copy(initialData, initialData + size, data);
    }

    // Destructor to free memory
    ~GenericArray() {
        delete[] data;
    }

    // Search method
    void search(const T& value) const {
        for (size_t i = 0; i < size; ++i) {
            if (data[i] == value) {
                std::cout << "Found: " << value << " at index " << i << std::endl;
                return;
            }
        }
        std::cout << "Not found: " << value << std::endl;
    }

    // Delete method
    void deleteValue(const T& value) {
        int indexToDelete = -1;
        // Find the first occurrence of the value
        for (size_t i = 0; i < size; ++i) {
            if (data[i] == value) {
                indexToDelete = i;
                break;
            }
        }

        if (indexToDelete == -1) {
            std::cout << "Not found, cannot delete: " << value << std::endl;
            return;
        }

        // Create a new array with one less element
        T* newData = new T[size - 1];
        size_t newIndex = 0;
        for (size_t i = 0; i < size; ++i) {
            if (i != static_cast<size_t>(indexToDelete)) {
                newData[newIndex] = data[i];
                ++newIndex;
            }
        }

        // Free old array and update to new array
        delete[] data;
        data = newData;
        --size;
        std::cout << "Deleted: " << value << std::endl;
    }

    // Print array contents
    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i];
            if (i < size - 1) {
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
    GenericArray<int> intArray(intData, intSize);
    std::cout << "Initial Integer Array: ";
    intArray.print();
    intArray.search(6);
    intArray.search(99);
    intArray.deleteValue(34);
    std::cout << "After deleting 34: ";
    intArray.print();

    // Example with doubles
    double doubleData[] = {4.5, 7.2, 6.1, 8.9};
    size_t doubleSize = sizeof(doubleData) / sizeof(doubleData[0]);
    GenericArray<double> doubleArray(doubleData, doubleSize);
    std::cout << "\nInitial Double Array: ";
    doubleArray.print();
    doubleArray.search(6.1);
    doubleArray.deleteValue(7.2);
    std::cout << "After deleting 7.2: ";
    doubleArray.print();

    // Example with strings
    std::string strData[] = {"apple", "banana", "cherry", "date"};
    size_t strSize = sizeof(strData) / sizeof(strData[0]);
    GenericArray<std::string> strArray(strData, strSize);
    std::cout << "\nInitial String Array: ";
    strArray.print();
    strArray.search("banana");
    strArray.search("grape");
    strArray.deleteValue("cherry");
    std::cout << "After deleting cherry: ";
    strArray.print();

    return 0;
}
