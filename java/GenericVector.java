import java.util.*;

public class GenericVector<T> {
    // Use ArrayList<T> as a dynamic array (vector equivalent)
    private ArrayList<T> data;

    // Constructor to initialize the vector from an array
    public GenericVector(T[] initialData) {
        this.data = new ArrayList<>(Arrays.asList(initialData));
    }

    // Create: Add a value to the end
    public void add(T value) {
        data.add(value);
        System.out.println("Added: " + value);
    }

    // Read: Search for a value
    public void search(T value) {
        int index = data.indexOf(value);
        if (index != -1) {
            System.out.println("Found: " + value + " at index " + index);
        } else {
            System.out.println("Not found: " + value);
        }
    }

    // Update: Replace first occurrence of oldValue with newValue
    public void update(T oldValue, T newValue) {
        int index = data.indexOf(oldValue);
        if (index != -1) {
            data.set(index, newValue);
            System.out.println("Updated: " + oldValue + " to " + newValue);
        } else {
            System.out.println("Not found, cannot update: " + oldValue);
        }
    }

    // Delete: Remove first occurrence of value
    public void delete(T value) {
        if (data.remove(value)) {
            System.out.println("Deleted: " + value);
        } else {
            System.out.println("Not found, cannot delete: " + value);
        }
    }

    // Get current data
    public List<T> getData() {
        return new ArrayList<>(data); // Return a copy
    }

    // Main method for testing
    public static void main(String[] args) {
        // Example with Integers
        Integer[] intData = {4, 7, 6, 8, 34, 43, 65, 34};
        GenericVector<Integer> intVector = new GenericVector<>(intData);
        System.out.println("Initial Integer Vector: " + intVector.getData());
        intVector.search(6);
        intVector.add(99);
        System.out.println("After adding 99: " + intVector.getData());
        intVector.update(34, 100);
        System.out.println("After updating 34 to 100: " + intVector.getData());
        intVector.delete(8);
        System.out.println("After deleting 8: " + intVector.getData());

        // Example with Strings
        String[] strData = {"apple", "banana", "cherry", "date"};
        GenericVector<String> strVector = new GenericVector<>(strData);
        System.out.println("\nInitial String Vector: " + strVector.getData());
        strVector.search("banana");
        strVector.add("grape");
        System.out.println("After adding grape: " + strVector.getData());
        strVector.update("cherry", "fig");
        System.out.println("After updating cherry to fig: " + strVector.getData());
        strVector.delete("date");
        System.out.println("After deleting date: " + strVector.getData());

        // Example with Doubles
        Double[] doubleData = {4.5, 7.2, 6.1, 8.9};
        GenericVector<Double> doubleVector = new GenericVector<>(doubleData);
        System.out.println("\nInitial Double Vector: " + doubleVector.getData());
        doubleVector.search(6.1);
        doubleVector.add(10.5);
        System.out.println("After adding 10.5: " + doubleVector.getData());
        doubleVector.update(7.2, 9.3);
        System.out.println("After updating 7.2 to 9.3: " + doubleVector.getData());
        doubleVector.delete(8.9);
        System.out.println("After deleting 8.9: " + doubleVector.getData());
    }
}
