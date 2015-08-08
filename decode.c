#include <stdio.h>
#include <malloc.h>
#include <string.h>

char bittochar(int* a);
void inttobit(int x,int* a);
int bth(int x);
void decode_base64(char* unit,char* out);
void base64tab(char c, int* b);

void main(int argc, char* argv[]) {
    if (argc!=2)
    {
        printf ("Usage:%s string\n",argv[0]);
        return;
    }
    char* s = (char*)malloc(sizeof(char)*1000);
    char* tmp = (char*)malloc(sizeof(char)*4);
    int i = 0;
    int j = 0;
    int _length = 0;
    _length = strlen(argv[1]);
    i = _length / 4;
    for (;j<i;j++)
    {
        tmp[0] = argv[1][4*j];
        tmp[1] = argv[1][4*j+1];
        tmp[2] = argv[1][4*j+2];
        tmp[3] = argv[1][4*j+3];
        decode_base64(tmp,s+3*j);
    }
    if (argv[1][4*i-2]=='=') s[3*i-2] = '\0';
    if (argv[1][4*i-1]=='=') s[3*i-1] = '\0';
    printf("The original text is %s\n",s);
}

void decode_base64(char* unit,char* out)
{
    int* total = (int*)malloc(sizeof(int)*24);
    int i = 0;
    int j = 0;
    for (;i<4;i++)
    {
        base64tab(unit[i],total+6*i);
    }
    for (;j<3;j++)
    out[j] = bittochar(total+8*j);
}
void base64tab(char c, int* b)
{
    int tmp = 0;
    int* middle = (int*)malloc(sizeof(int)*8);
    if ((c>='A')&&(c<='Z'))
    tmp = (c - 'A');
    else if ((c>='a')&&(c<='z'))
    tmp = (c - 'a') + 26;
    else if ((c>='0')&&(c<='9'))
    tmp = (c - '0') + 52;
    else if (c=='+')
    tmp = 62;
    else if (c=='/')
    tmp = 63;
    else if (c=='=')
    tmp = 0;
    inttobit(tmp,middle);
    for (int j=0;j<6;j++)
    {
        b[j]=middle[j+2];
    }
}
int bth(int x)
{
    int sum = 1;
    int y;
    y = 7 - x;
    for (int i=0;i<y;i++)
    {
        sum *= 2;
    }
    return sum;
}
void inttobit(int x, int* a)
{
    a[0]=a[1]=a[2]=a[3]=a[4]=a[5]=a[6]=a[7]=0;
    int i = 0;
    while(x)
    {
        a[7-i]=x%2;
        x/=2;
        i++;
    }
}
char bittochar(int* a) //convert 8 bits int to char
{
    int sum0 = 0;
    char sum = '\0';
    for (int n=0;n<8;n++)
    {
        if(a[n])
        sum0 += bth(n);
    }
    sum = (sum0);
    return sum;
}
