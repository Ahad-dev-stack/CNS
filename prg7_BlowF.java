
import javax.crypto.*;
import javax.crypto.spec.*;
import java.io.*;
import java.util.*;

public class BlowfishDemo {
    public static void main(String[] args) throws Exception {

        KeyStore ks = KeyStore.getInstance("JCEKS");
        ks.load(new FileInputStream("mykeys.jceks"),
                "changeit".toCharArray());

        SecretKey key = (SecretKey) ks.getKey(
                "mykey", "changeit".toCharArray());

        Cipher c = Cipher.getInstance("Blowfish/CBC/PKCS5Padding");

        byte[] iv = new byte[8];
        new java.security.SecureRandom().nextBytes(iv);
        IvParameterSpec ivs = new IvParameterSpec(iv);

        c.init(Cipher.ENCRYPT_MODE, key, ivs);
        byte[] encrypted = c.doFinal("Hello world".getBytes());

        c.init(Cipher.DECRYPT_MODE, key, ivs);
        byte[] decrypted = c.doFinal(encrypted);

        System.out.println("Encrypted: " +
                Base64.getEncoder().encodeToString(encrypted));
        System.out.println("Decrypted: " + new String(decrypted));
    }

    // keytool -genseckey -alias mykey -keyalg Blowfish -keysize 128 -storetype JCEKS -keystore mykeys.jceks -storepass changeit -keypass changeit
}
