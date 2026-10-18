import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class subsCipher
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the Plain text: ");
		String s = sc.nextLine();
		
		String plain = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		String cipher = "QWERTYUIOPASDFGHJKLZXCVBNM";
		
		Map<Character, Character> encryptMap = new HashMap<>();
		
		for (int i = 0; i < 26; i++) 
		{
		    encryptMap.put(plain.charAt(i), cipher.charAt(i));
		}
		
		Map<Character, Character> decryptMap = new HashMap<>();

		for (int i = 0; i < 26; i++) 
		{
		    decryptMap.put(cipher.charAt(i), plain.charAt(i));
		}
		
		StringBuilder res = new StringBuilder();

		for (char ch : s.toCharArray()) {

		    if (Character.isLetter(ch)) {
		        res.append(encryptMap.get(ch));
		    } else {
		        res.append(ch);
		    }
		}

		System.out.println("\nCipher Text : " + res);

		sc.close();
	}
}


/*

import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class subsCipher {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the Plain text: ");
        String s = sc.nextLine();

        String plain = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String cipher = "QWERTYUIOPASDFGHJKLZXCVBNM";

        Map<Character, Character> encryptMap = new HashMap<>();
        Map<Character, Character> decryptMap = new HashMap<>();

        for (int i = 0; i < 26; i++) {
            encryptMap.put(plain.charAt(i), cipher.charAt(i));
            decryptMap.put(cipher.charAt(i), plain.charAt(i));
        }

        // Encryption
        StringBuilder res = new StringBuilder();

        for (char ch : s.toCharArray()) {
            if (Character.isUpperCase(ch)) {
                res.append(encryptMap.get(ch));
            } 
            else if (Character.isLowerCase(ch)) {
                res.append(Character.toLowerCase(encryptMap.get(Character.toUpperCase(ch))));
            } 
            else {
                res.append(ch);
            }
        }

        String cipherText = res.toString();
        System.out.println("\nCipher Text: " + cipherText);

        // Decryption
        res.setLength(0);

        for (char ch : cipherText.toCharArray()) {
            if (Character.isUpperCase(ch)) {
                res.append(decryptMap.get(ch));
            } 
            else if (Character.isLowerCase(ch)) {
                res.append(Character.toLowerCase(decryptMap.get(Character.toUpperCase(ch))));
            } 
            else {
                res.append(ch);
            }
        }

        System.out.println("Decrypted Text: " + res);

        sc.close();
    }
}

*/
