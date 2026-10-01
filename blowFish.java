import java.util.*;
import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import java.util.Base64;

public class BlowFish {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter message: ");
        String message = sc.nextLine();

        // Generate 128-bit Blowfish key
        KeyGenerator keyGenerator = KeyGenerator.getInstance("Blowfish");
        keyGenerator.init(128);

        SecretKey key = keyGenerator.generateKey();

        // Create Blowfish cipher
        Cipher cipher = Cipher.getInstance("Blowfish/CFB/NoPadding");

        // Encryption
        cipher.init(Cipher.ENCRYPT_MODE, key);

        byte[] iv = cipher.getIV();

        System.out.println("Initialization Vector: "
                + Base64.getEncoder().encodeToString(iv));

        byte[] encrypted = cipher.doFinal(message.getBytes());

        System.out.println("Encrypted text: "
                + Base64.getEncoder().encodeToString(encrypted));

        // Decryption
        cipher.init(
                Cipher.DECRYPT_MODE,
                key,
                new IvParameterSpec(iv)
        );

        byte[] decrypted = cipher.doFinal(encrypted);

        System.out.println("Decrypted text: "
                + new String(decrypted));

        sc.close();
    }
}
