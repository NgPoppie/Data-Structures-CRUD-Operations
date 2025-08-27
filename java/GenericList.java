import java.util.*;

public class GenericList<T> {
    // Use LinkedList<T> for dynamic sizing and generics
    private LinkedList<T> data;

    // Constructor to initialize the list from an array
    public GenericList(T[] initialData) {
        this.data = new LinkedList<>(Arrays.asList(initialData));
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
        return new LinkedList<>(data); // Return a copy
    }

    // Main method for testing
    public static void main(String[] args) {
        // Example with Integers
        Integer[] intData = {4, 7, 6, 8, 34, 43, 65, 34};
        GenericList<Integer> intList = new GenericList<>(intData);
        System.out.println("Initial Integer List: " + intList.getData());
        intList.search(6);
        intList.add(99);
        System.out.println("After adding 99: " + intList.getData());
        intList.update(34, 100);
        System.out.println("After updating 34 to 100: " + intList.getData());
        intList.delete(8);
        System.out.println("After deleting 8: " + intList.getData());

        // Example with Strings
        String[] strData = {"apple", "banana", "cherry", "date"};
        GenericList<String> strList = new GenericList<>(strData);
        System.out.println("\nInitial String List: " + strList.getData());
        strList.search("banana");
        strList.add("grape");
        System.out.println("After adding grape: " + strList.getData());
        strList.update("cherry", "fig");
        System.out.println("After updating cherry to fig: " + strList.getData());
        strList.delete("date");
        System.out.println("After deleting date: " + strList.getData());

        // Example with Doubles
        Double[] doubleData = {4.5, 7.2, 6.1, 8.9};
        GenericList<Double> doubleList = new GenericList<>(doubleData);
        System.out.println("\nInitial Double List: " + doubleList.getData());
        doubleList.search(6.1);
        doubleList.add(10.5);
        System.out.println("After adding 10.5: " + doubleList.getData());
        doubleList.update(7.2, 9.3);
        System.out.println("After updating 7.2 to 9.3: " + doubleList.getData());
        doubleList.delete(8.9);
        System.out.println("After deleting 8.9: " + doubleList.getData());
    }
}
