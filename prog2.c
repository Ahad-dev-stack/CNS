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
