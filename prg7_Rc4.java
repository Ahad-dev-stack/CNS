import java.util.Scanner;

public class RC4 {

    static byte[] process(byte[] data, String key) {
        int[] S = new int[256];
        byte[] k = key.getBytes();
        byte[] result = new byte[data.length];

        for (int i = 0; i < 256; i++)
            S[i] = i;

        int j = 0;
        for (int i = 0; i < 256; i++) {
            j = (j + S[i] + (k[i % k.length] & 255)) % 256;

            int temp = S[i];
            S[i] = S[j];
            S[j] = temp;
        }

        int i = 0;
        j = 0;

        for (int x = 0; x < data.length; x++) {
            i = (i + 1) % 256;
            j = (j + S[i]) % 256;

            int temp = S[i];
            S[i] = S[j];
            S[j] = temp;

            int index = (S[i] + S[j]) % 256;
            result[x] = (byte)(data[x] ^ S[index]);
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter plaintext: ");
        String text = sc.nextLine();

        System.out.print("Enter key: ");
        String key = sc.nextLine();

        if (key.isEmpty()) {
            System.out.println("Key cannot be empty.");
            sc.close();
            return;
        }

        byte[] encrypted = process(text.getBytes(), key);
        byte[] decrypted = process(encrypted, key);

        System.out.println("Original Text: " + text);

        System.out.print("Encrypted Text (Hex): ");
        for (byte b : encrypted)
            System.out.printf("%02X", b & 255);

        System.out.println();
        System.out.println("Decrypted Text: " + new String(decrypted));

        sc.close();
    }
}
