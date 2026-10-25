
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
