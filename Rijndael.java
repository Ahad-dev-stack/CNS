import java.util.*;
import javax.crypto.*;
import javax.crypto.spec.SecretKeySpec;

public class AES {

    public static String asHex(byte[] buf) {
        StringBuffer strbuf = new StringBuffer(buf.length * 2);

        for (int i = 0; i < buf.length; i++) {
            if ((buf[i] & 0xff) < 0x10)
                strbuf.append("0");

            strbuf.append(Integer.toHexString(buf[i] & 0xff));
        }

        return strbuf.toString();
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter message: ");
        String message = sc.nextLine();

        // Generate 128-bit AES key
        KeyGenerator kgen = KeyGenerator.getInstance("AES");
        kgen.init(128);

        SecretKey secretKey = kgen.generateKey();

        // Get key bytes
        byte[] raw = secretKey.getEncoded();

        SecretKeySpec keySpec = new SecretKeySpec(raw, "AES");

        // Create AES cipher
        Cipher cipher = Cipher.getInstance("AES");

        // Encryption
        cipher.init(Cipher.ENCRYPT_MODE, keySpec);

        byte[] encrypted = cipher.doFinal(message.getBytes());

        System.out.println("\nEncrypted text: "
                           + asHex(encrypted));

        // Decryption
        cipher.init(Cipher.DECRYPT_MODE, keySpec);

        byte[] original = cipher.doFinal(encrypted);

        String originalString = new String(original);

        System.out.println("Decrypted text: "
                           + originalString);

        sc.close();
    }
}
