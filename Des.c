#include <stdio.h>

int P10[]={3,5,2,7,4,10,1,9,8,6};
int P8[]={6,3,7,4,8,5,10,9};
int IP[]={2,6,3,1,4,8,5,7};
int IP1[]={4,1,3,5,7,2,8,6};
int EP[]={4,1,2,3,2,3,4,1};
int P4[]={2,4,3,1};

int S0[4][4]={
    {1,0,3,2},
    {3,2,1,0},
    {0,2,1,3},
    {3,1,3,2}
};

int S1[4][4]={
    {0,1,2,3},
    {2,0,1,3},
    {3,0,1,0},
    {2,1,0,3}
};

void perm(int a[],int b[],int p[],int n)
{
    int i;
    for(i=0;i<n;i++)
        b[i]=a[p[i]-1];
}

void shift(int a[],int b[])
{
    int i;
    for(i=0;i<5;i++)
        b[i]=a[(i+1)%5];
}

void keygen(int key[],int k1[],int k2[])
{
    int a[10],l[5],r[5],x[10],t[10];
    int i;

    perm(key,a,P10,10);

    for(i=0;i<5;i++){
        l[i]=a[i];
        r[i]=a[i+5];
    }

    shift(l,t);
    shift(r,x);

    for(i=0;i<5;i++){
        a[i]=t[i];
        a[i+5]=x[i];
    }

    perm(a,k1,P8,8);

    shift(t,x);
    shift(x,t);

    for(i=0;i<5;i++)
        a[i]=t[i];

    shift(l,t);
    shift(r,x);

    for(i=0;i<5;i++){
        a[i]=t[i];
        a[i+5]=x[i];
    }

    perm(a,k2,P8,8);
}

void round1(int a[],int key[],int out[])
{
    int e[8],x[8],s[4],p[4];
    int i,row,col;

    perm(a,e,EP,8);

    for(i=0;i<8;i++)
        x[i]=e[i]^key[i];

    row=x[0]*2+x[3];
    col=x[1]*2+x[2];
    s[0]=S0[row][col];

    row=x[4]*2+x[7];
    col=x[5]*2+x[6];
    s[1]=S1[row][col];

    s[2]=(s[0]>>1)&1;
    s[3]=s[1]&1;
    s[0]=s[0]&1;
    s[1]=(s[1]>>1)&1;

    perm(s,p,P4,4);

    for(i=0;i<4;i++)
        out[i]=a[i]^p[i];

    for(i=0;i<4;i++)
        out[i+4]=a[i+4];
}

void swap(int a[],int b[])
{
    int i;
    for(i=0;i<4;i++){
        b[i]=a[i+4];
        b[i+4]=a[i];
    }
}

void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d",a[i]);
}

int main()
{
    int key[10],plain[8];
    int k1[8],k2[8];
    int a[8],b[8],c[8],cipher[8];
    int i;

    printf("Enter 10 bit key: ");
    for(i=0;i<10;i++)
        scanf("%1d",&key[i]);

    printf("Enter 8 bit plaintext: ");
    for(i=0;i<8;i++)
        scanf("%1d",&plain[i]);

    keygen(key,k1,k2);

    printf("\nK1 = ");
    print(k1,8);

    printf("\nK2 = ");
    print(k2,8);

    perm(plain,a,IP,8);

    round1(a,k1,b);

    swap(b,c);

    round1(c,k2,b);

    perm(b,c,IP1,8);

    printf("\nCiphertext = ");
    print(c,8);

    return 0;
}

