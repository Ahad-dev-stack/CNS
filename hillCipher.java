import java.util.Scanner;

public class HillCipher {
    static int[][] key = {{3, 3}, {2, 5}};
    static int[][] invKey = {{15, 17}, {20, 9}}; // Inverse of key mod 26

    static String process(String text, int[][] matrix) {
        text = text.toUpperCase().replaceAll(" ", "");
        if (text.length() % 2 != 0) text += "X";

        StringBuilder result = new StringBuilder();

        for (int i = 0; i < text.length(); i += 2) {
            int a = text.charAt(i) - 'A';
            int b = text.charAt(i + 1) - 'A';

            int x = (matrix[0][0] * a + matrix[0][1] * b) % 26;
            int y = (matrix[1][0] * a + matrix[1][1] * b) % 26;

            result.append((char) (x + 'A'));
            result.append((char) (y + 'A'));
        }
        return result.toString();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Plain Text: ");
        String text = sc.nextLine();

        String cipher = process(text, key);
        System.out.println("Encrypted: " + cipher);

        String plain = process(cipher, invKey);
        System.out.println("Decrypted: " + plain);

        sc.close();
    }
}
