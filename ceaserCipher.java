import java.util.Scanner;

public class ceaserCipher
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter the Plain text: ");
		String s = sc.nextLine();
		
		System.out.println("Enter the key: ");
		int key = sc.nextInt();
		
		StringBuilder res = new StringBuilder();
		
		key = key%26;
		
		for(int i = 0;i<s.length();i++)
		{
			char ch = s.charAt(i);
			
			if(ch >= 'A' && ch<='Z')
				ch = (char)(((ch-'A'+key)%26)+'A');
			else if(ch >= 'a' && ch<='z')
				ch = (char)(((ch-'a'+key)%26)+'a');
				
			res.append(ch);
		}
		System.out.println("\nCipher Text : " + res);
		sc.close();
	}
}
