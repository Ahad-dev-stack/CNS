import javax.crypto.*;
import javax.crypto.spec.IvParameterSpec;
import java.security.*;
import java.io.*;
import java.util.*;

public class BlowfishDemo {
    public static void main(String[] args) throws Exception {

        KeyStore ks = KeyStore.getInstance("JCEKS");
        ks.load(new FileInputStream("mykeys.jceks"),
                "changeit".toCharArray());

        SecretKey key = (SecretKey) ks.getKey(
                "mykey", "changeit".toCharArray());

        String text = "Hello world";

        byte[] iv = new byte[8];
        new SecureRandom().nextBytes(iv);
        IvParameterSpec ivSpec = new IvParameterSpec(iv);

        Cipher c = Cipher.getInstance("Blowfish/CBC/PKCS5Padding");
        c.init(Cipher.ENCRYPT_MODE, key, ivSpec);

        byte[] encrypted = c.doFinal(text.getBytes("UTF-8"));

        c.init(Cipher.DECRYPT_MODE, key, ivSpec);
        byte[] decrypted = c.doFinal(encrypted);

        System.out.println("Original Text: " + text);
        System.out.println("Encrypted Text: " +
                Base64.getEncoder().encodeToString(encrypted));
        System.out.println("Decrypted Text: " +
                new String(decrypted, "UTF-8"));
    }
}
