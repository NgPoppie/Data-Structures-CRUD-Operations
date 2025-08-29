import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class WordCount {
    public static void main(String[] args) {
        Map<String, Integer> freq = new HashMap<>();
        Scanner doc = new Scanner(System.in).useDelimiter("[^a-zA-Z]+");

        // Count word frequencies
        while (doc.hasNext()) {
            String word = doc.next().toLowerCase();
            Integer count = freq.get(word);
            if (count == null) {
                count = 0;
            }
            freq.put(word, 1 + count);
        }

        // Find the most frequent word
        int maxCount = 0;
        String maxWord = "no honey in the jar";
        for (Map.Entry<String, Integer> ent : freq.entrySet()) {
            if (ent.getValue() > maxCount) {
                maxWord = ent.getKey();
                maxCount = ent.getValue();
            }
        }

        // Output the result
        System.out.println("The most frequent word is " + maxWord);
        System.out.println(" with " + maxCount + " occurrences");
        
        // Close the scanner
        doc.close();
    }
}
