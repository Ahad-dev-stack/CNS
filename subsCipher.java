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
