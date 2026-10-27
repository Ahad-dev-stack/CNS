
import java.util.Scanner;

public class subsCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the Plain text: ");
        String s = sc.nextLine();

        String plain = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String cipher = "QWERTYUIOPASDFGHJKLZXCVBNM";

        StringBuilder enc = new StringBuilder();

        for (char ch : s.toCharArray()) {
            char upper = Character.toUpperCase(ch);
            int i = plain.indexOf(upper);

            if (i != -1) {
                char c = cipher.charAt(i);

                if (Character.isLowerCase(ch))
                    c = Character.toLowerCase(c);

                enc.append(c);
            } else {
                enc.append(ch);
            }
        }

        String encrypted = enc.toString();
        System.out.println("Cipher Text: " + encrypted);

        StringBuilder dec = new StringBuilder();

        for (char ch : encrypted.toCharArray()) {
            char upper = Character.toUpperCase(ch);
            int i = cipher.indexOf(upper);

            if (i != -1) {
                char c = plain.charAt(i);

                if (Character.isLowerCase(ch))
                    c = Character.toLowerCase(c);

                dec.append(c);
            } else {
                dec.append(ch);
            }
        }

        System.out.println("Decrypted Text: " + dec);

        sc.close();
    }
}
