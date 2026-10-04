import java.util.*;
import javax.crypto.*;
import java.util.Base64;

public class Task2 {
    static Scanner sc = new Scanner(System.in);
    static Cipher cipher;

    static byte[] encrypt(String data) throws Exception {
        byte[] encrypted = cipher.doFinal(data.getBytes());
        System.out.println("Encrypted: " + Base64.getEncoder().encodeToString(encrypted));
        return encrypted;
    }

    static byte[] decrypt(byte[] data) throws Exception {
        byte[] decrypted = cipher.doFinal(data);
        System.out.println("Decrypted: " + new String(decrypted));
        return decrypted;
    }

    public static void main(String[] args) {
        try {
            String data = sc.nextLine();

            KeyGenerator kg = KeyGenerator.getInstance("DES");
            SecretKey key = kg.generateKey();

            cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");

            cipher.init(Cipher.ENCRYPT_MODE, key);
            byte[] encrypted = encrypt(data);

            cipher.init(Cipher.DECRYPT_MODE, key);
            decrypt(encrypted);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
