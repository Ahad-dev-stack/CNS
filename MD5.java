import java.util.Scanner;
import java.security.MessageDigest;

public class MD5 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String text = sc.nextLine();

        // Create MD5 message digest
        MessageDigest md = MessageDigest.getInstance("MD5");

        // Calculate digest
        byte[] digest = md.digest(text.getBytes("UTF-8"));

        // Convert digest to hexadecimal
        System.out.print("MD5 Digest: ");
        for (byte b : digest) {
            System.out.printf("%02x", b & 0xff);
        }

        System.out.println();
        sc.close();
    }
}
