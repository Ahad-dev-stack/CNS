#include <stdio.h>

int main()
{
    char str[100];
    char encrypted[100];
    char decrypted[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("\nOriginal String: %s", str);

    printf("\nEncrypted String (XOR with 0): ");

    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        encrypted[i] = str[i] ^ 0;
        printf("%c", encrypted[i]);
    }

    encrypted[i] = '\0';

    printf("\nDecrypted String: ");

    for (i = 0; encrypted[i] != '\0'; i++)
    {
        decrypted[i] = encrypted[i] ^ 0;
        printf("%c", decrypted[i]);
    }

    decrypted[i] = '\0';

    return 0;
}



#include <stdio.h>

int main()
{
    char str[100];
    char encrypted[100];
    char decrypted[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("\nOriginal String: %s", str);

    printf("\nAND with 127: ");
    for(int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i] & 127);
    }

    printf("\nOR with 127: ");
    for(int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i] | 127);
    }

    printf("\n\nEncrypted String (XOR with 127): ");
    int i;
    for(i = 0; str[i] != '\0'; i++)
    {
        encrypted[i] = str[i] ^ 127;
        printf("%c", encrypted[i]);
    }
    encrypted[i] = '\0';

    printf("\nDecrypted String: ");
    for(i = 0; encrypted[i] != '\0'; i++)
    {
        decrypted[i] = encrypted[i] ^ 127;
        printf("%c", decrypted[i]);
    }
    decrypted[i] = '\0';

    return 0;
}



import java.util.Scanner;

public class ceaserCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the Plain text: ");
        String s = sc.nextLine();

        System.out.println("Enter the key: ");
        int key = sc.nextInt();

        StringBuilder res = new StringBuilder();

        key = key % 26;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (ch >= 'A' && ch <= 'Z')
                ch = (char) (((ch - 'A' + key) % 26) + 'A');
            else if (ch >= 'a' && ch <= 'z')
                ch = (char) (((ch - 'a' + key) % 26) + 'a');

            res.append(ch);
        }

        String cipherText = res.toString();
        System.out.println("\nCipher Text: " + cipherText);

        res.setLength(0);

        for (int i = 0; i < cipherText.length(); i++) {
            char ch = cipherText.charAt(i);

            if (ch >= 'A' && ch <= 'Z')
                ch = (char) (((ch - 'A' - key + 26) % 26) + 'A');
            else if (ch >= 'a' && ch <= 'z')
                ch = (char) (((ch - 'a' - key + 26) % 26) + 'a');

            res.append(ch);
        }

        System.out.println("Decrypted Text: " + res);

        sc.close();
    }
}



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


import java.util.*;
import javax.crypto.*;
import java.util.Base64;

public class Task3 {
    static Scanner sc = new Scanner(System.in);
    static Cipher cipher;

    private static byte[] encrypt(String data) throws Exception {
        byte[] encrypted = cipher.doFinal(data.getBytes());
        System.out.println("Encrypted: " +
        Base64.getEncoder().encodeToString(encrypted));
        return encrypted;
    }

    private static byte[] decrypt(byte[] data) throws Exception {
        byte[] decrypted = cipher.doFinal(data);
        System.out.println("Decrypted: " + new String(decrypted));
        return decrypted;
    }

    public static void main(String[] args) {
        try {
            String data = sc.nextLine();

            KeyGenerator kg = KeyGenerator.getInstance("Blowfish");
            SecretKey key = kg.generateKey();

            cipher = Cipher.getInstance("Blowfish");

            cipher.init(Cipher.ENCRYPT_MODE, key);
            byte[] encrypted = encrypt(data);

            cipher.init(Cipher.DECRYPT_MODE, key);
            decrypt(encrypted);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}



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




import java.util.*;

public class RC4 {
    static byte[] process(byte[] data, String key) {
        int[] S = new int[256];

        for (int i = 0; i < 256; i++)
            S[i] = i;

        int j = 0;

        // KSA
        for (int i = 0; i < 256; i++) {
            j = (j + S[i] + key.charAt(i % key.length())) % 256;

            int temp = S[i];
            S[i] = S[j];
            S[j] = temp;
        }

        byte[] result = new byte[data.length];
        int i = 0;
        j = 0;

        // PRGA
        for (int x = 0; x < data.length; x++) {
            i = (i + 1) % 256;
            j = (j + S[i]) % 256;

            int temp = S[i];
            S[i] = S[j];
            S[j] = temp;

            int k = S[(S[i] + S[j]) % 256];
            result[x] = (byte) (data[x] ^ k);
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter plaintext: ");
        String text = sc.nextLine();

        System.out.print("Enter key: ");
        String key = sc.nextLine();

        byte[] encrypted = process(text.getBytes(), key);

        System.out.print("Encrypted (Hex): ");
        for (byte b : encrypted)
            System.out.printf("%02X", b & 0xFF);

        byte[] decrypted = process(encrypted, key);

        System.out.println("\nDecrypted: " + new String(decrypted));

        sc.close();
    }
}




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

    // keytool -genseckey -alias mykey -keyalg Blowfish -keystore mykeys.jceks -storetype JCEKS
}



import java.math.BigInteger;
import java.util.*;

public class Task7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random r = new Random();

        System.out.print("Enter message: ");
        String data = sc.nextLine();

        BigInteger p = BigInteger.probablePrime(1024, r);
        BigInteger q = BigInteger.probablePrime(1024, r);

        BigInteger n = p.multiply(q);
        BigInteger phi = p.subtract(BigInteger.ONE)
                          .multiply(q.subtract(BigInteger.ONE));

        BigInteger e = BigInteger.probablePrime(512, r);

        while (!e.gcd(phi).equals(BigInteger.ONE))
            e = e.add(BigInteger.ONE);

        BigInteger d = e.modInverse(phi);

        BigInteger message = new BigInteger(1, data.getBytes());
        BigInteger encrypted = message.modPow(e, n);
        BigInteger decrypted = encrypted.modPow(d, n);

        System.out.println("Encryption: " + encrypted);
        System.out.println("Decryption: " +
                           new String(decrypted.toByteArray()));

        sc.close();
    }
}




<!DOCTYPE html>
<html>
<head>
    <title>Diffie-Hellman Key Exchange</title>
</head>

<body>
    <h2>Diffie-Hellman Key Exchange</h2>

    <label>Prime Number (p): </label>
    <input type="number" id="p" value="23"><br><br>

    <label>Primitive root (g): </label>
    <input type="number" id="g" value="5"><br><br>

    <label>Alice's Private Key (a): </label>
    <input type="number" id="a" value="6"><br><br>

    <label>Bob's Private Key (b): </label>
    <input type="number" id="b" value="15"><br><br>

    <button onclick="calculate()">Generate Shared Key</button>

    <h3>Results</h3>
    <p id="result"></p>

    <script>
        function powerMod(base, exp, p) {
            let res = 1;

            while (exp > 0) {
                res = (res * base) % p;
                exp--;
            }

            return res;
        }

        function calculate() {
            let p = Number(document.getElementById("p").value);
            let g = Number(document.getElementById("g").value);
            let a = Number(document.getElementById("a").value);
            let b = Number(document.getElementById("b").value);

            let A = powerMod(g, a, p);
            let B = powerMod(g, b, p);

            let KeyA = powerMod(B, a, p);
            let KeyB = powerMod(A, b, p);

            document.getElementById("result").innerHTML =
                "Alice's Public Key: " + A + "<br>" +
                "Bob's Public Key: " + B + "<br>" +
                "Alice's Shared Key: " + KeyA + "<br>" +
                "Bob's Shared Key: " + KeyB + "<br>" +
                "Keys Match: " + (KeyA === KeyB);
        }
    </script>
</body>
</html>


import java.util.Scanner;
import java.security.MessageDigest;

public class SHA1 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String text = sc.nextLine();

        MessageDigest md = MessageDigest.getInstance("SHA-1");

        byte[] digest = md.digest(text.getBytes("UTF-8"));

        System.out.print("SHA-1 Digest: ");
        for (byte b : digest) {
            System.out.printf("%02x", b & 0xff);
        }

        System.out.println();
        sc.close();
    }
}


