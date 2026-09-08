#include <stdio.h>

int P[18];

void keygen(int key[], int n)
{
    int i;

    for(i = 0; i < 18; i++)
        P[i] = key[i % n];
}

int F(int x, int key)
{
    return (x + key) ^ key;
}

void round(int *l, int *r, int key)
{
    int temp;

    *l = *l ^ key;
    *r = *r ^ F(*l, key);

    temp = *l;
    *l = *r;
    *r = temp;
}

void print(int x)
{
    printf("%08X", x);
}

int main()
{
    int left, right;
    int key[8];
    int i;

    printf("Enter left half (8 hex digits): ");
    scanf("%x", &left);

    printf("Enter right half (8 hex digits): ");
    scanf("%x", &right);

    printf("Enter 8 bit key values (0/1): ");
    for(i = 0; i < 8; i++)
        scanf("%1d", &key[i]);

    keygen(key, 8);

    printf("\nP-array generated.");

    for(i = 0; i < 16; i++)
    {
        round(&left, &right, P[i]);

        printf("\nRound %d: L = ", i + 1);
        print(left);

        printf("  R = ");
        print(right);
    }

    {
        int temp = left;
        left = right;
        right = temp;
    }

    printf("\n\nCiphertext = ");
    print(left);
    print(right);

    return 0;
}

Enter left half (8 hex digits): 12345678
Enter right half (8 hex digits): 9ABCDEF0
Enter 8 bit key values (0/1): 10101010
