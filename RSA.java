import java.math.*;
import java.util.*;

public class Task7 {
    static Scanner s = new Scanner(System.in);
    static BigInteger p, q, N, phi, e, d;
    static int bitlength = 1024;
    static Random r;

    static void Setter() {
        r = new Random();

        p = BigInteger.probablePrime(bitlength, r);
        q = BigInteger.probablePrime(bitlength, r);

        N = p.multiply(q);

        phi = p.subtract(BigInteger.ONE)
               .multiply(q.subtract(BigInteger.ONE));

        e = BigInteger.probablePrime(bitlength / 2, r);

        while (phi.gcd(e).compareTo(BigInteger.ONE) > 0)
            e = e.add(BigInteger.ONE);

        d = e.modInverse(phi);
    }

    static byte[] encrypt(String data) {
        BigInteger message = new BigInteger(1, data.getBytes());
        return message.modPow(e, N).toByteArray();
    }

    static byte[] decrypt(byte[] data) {
        BigInteger encrypted = new BigInteger(1, data);
        return encrypted.modPow(d, N).toByteArray();
    }

    public static void main(String[] args) {
        String data = s.nextLine();

        Setter();

        byte[] encrypted = encrypt(data);

        System.out.println("Encryption: " + new BigInteger(1, encrypted));
        System.out.println("Decryption: " + new String(decrypt(encrypted)));
    }
}
