import java.util.*;

public class GenericArray<T> {
    // Use Object[] to store generic elements
    private T[] data;

    // Constructor to initialize the array
    @SuppressWarnings("unchecked")
    public GenericArray(T[] initialData) {
        this.data = (T[]) new Object[initialData.length];
        System.arraycopy(initialData, 0, this.data, 0, initialData.length);
    }

    // Search method
    public void search(T value) {
        for (int i = 0; i < data.length; i++) {
            if (data[i] != null && data[i].equals(value)) {
                System.out.println("Found: " + value + " at index " + i);
                return;
            }
        }
        System.out.println("Not found: " + value);
    }

    // Delete method
    @SuppressWarnings("unchecked")
    public void delete(T value) {
        int indexToDelete = -1;
        // Find the first occurrence of the value
        for (int i = 0; i < data.length; i++) {
            if (data[i] != null && data[i].equals(value)) {
                indexToDelete = i;
                break;
            }
        }

        if (indexToDelete == -1) {
            System.out.println("Not found, cannot delete: " + value);
            return;
        }

        // Create a new array with one less element
        T[] newData = (T[]) new Object[data.length - 1];
        int newIndex = 0;
        for (int i = 0; i < data.length; i++) {
            if (i != indexToDelete) {
                newData[newIndex] = data[i];
                newIndex++;
            }
        }
        data = newData;
        System.out.println("Deleted: " + value);
    }

    // Get current data
    public T[] getData() {
        return data;
    }

    // Main method for testing
    public static void main(String[] args) {
        // Example with Integers
        Integer[] intData = {4, 7, 6, 8, 34, 43, 65, 34};
        GenericArray<Integer> intArray = new GenericArray<>(intData);
        System.out.println("Initial Integer Array: " + Arrays.toString(intArray.getData()));
        intArray.search(6);
        intArray.search(99);
        intArray.delete(34);
        System.out.println("After deleting 34: " + Arrays.toString(intArray.getData()));

        // Example with Strings
        String[] strData = {"apple", "banana", "cherry", "date"};
        GenericArray<String> strArray = new GenericArray<>(strData);
        System.out.println("\nInitial String Array: " + Arrays.toString(strArray.getData()));
        strArray.search("banana");
        strArray.search("grape");
        strArray.delete("cherry");
        System.out.println("After deleting cherry: " + Arrays.toString(strArray.getData()));

        // Example with Doubles
        Double[] doubleData = {4.5, 7.2, 6.1, 8.9};
        GenericArray<Double> doubleArray = new GenericArray<>(doubleData);
        System.out.println("\nInitial Double Array: " + Arrays.toString(doubleArray.getData()));
        doubleArray.search(6.1);
        doubleArray.delete(7.2);
        System.out.println("After deleting 7.2: " + Arrays.toString(doubleArray.getData()));
    }
}
