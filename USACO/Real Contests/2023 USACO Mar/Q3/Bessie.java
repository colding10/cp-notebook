
import java.util.Scanner; // Import the Scanner class

public class Bessie {

    public static int bessieSum(String t) {
        int sum = 0;
        for (int i = 0; i < t.length(); i++) {
            for (int j = i + 1; j <= t.length(); j++) {
                String s = t.substring(i, j);
                int b = bessieHelper(s);
                sum += b;
            }
        }
        return sum;
    }

    private static int bessieHelper(String s) {
        int maxBessie = 0;
        String bessie = "bessie";
        int i = 0;
        while (i < s.length()) {
            int j = 0;
            while (j < bessie.length() && i < s.length() && s.charAt(i) == bessie.charAt(j)) {
                i++;
                j++;
            }
            if (j == bessie.length()) {
                maxBessie++;
            }
        }
        return maxBessie;
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        String t = myObj.nextLine();
        int sum = bessieSum(t);
        System.out.println(sum);
    }
}