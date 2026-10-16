
import java.util.Scanner;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;

public class AES {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter message: ");
        String message = sc.nextLine();

        // Generate AES key
        KeyGenerator kg = KeyGenerator.getInstance("AES");
        kg.init(128);
        SecretKey key = kg.generateKey();

        // Create cipher
        Cipher cipher = Cipher.getInstance("AES");

        // Encryption
        cipher.init(Cipher.ENCRYPT_MODE, key);
        byte[] encrypted = cipher.doFinal(message.getBytes());

        System.out.print("Encrypted text: ");
        for (byte b : encrypted)
            System.out.printf("%02X", b);
        System.out.println();

        // Decryption
        cipher.init(Cipher.DECRYPT_MODE, key);
        byte[] decrypted = cipher.doFinal(encrypted);

        System.out.println("Decrypted text: " +
                           new String(decrypted));

        sc.close();
    }
}
