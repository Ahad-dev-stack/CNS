
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
