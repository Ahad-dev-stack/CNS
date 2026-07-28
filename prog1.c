#include <stdio.h>

int main()
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("After XOR with 0: ");

    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c", str[i] ^ 0);
    }

    return 0;
}
