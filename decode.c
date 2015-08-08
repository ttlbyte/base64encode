#include <stdio.h>
#include <malloc.h>
#include <string.h>

char inttochar(int* a);
void chartoint(char x,int* a);
int bth(int x);
void decode_base64(char* unit,char* out);

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
void chartoint(char x, int* a)
{
    a[0]=a[1]=a[2]=a[3]=a[4]=a[5]=a[6]=a[7]=0;
    int m;
    int i = 0;
    m = (x);
    while(m)
    {
        a[7-i]=m%2;
        m/=2;
        i++;
    }
}
char inttochar(int* a) //convert 8 bits int to char
{
    int sum0 = 0;
    char sum = '\0';
    for (int n=0;n<8;n++)
    {
        if(a[n])
        sum0 += bth(n);
    }
    if(sum0 <= 25)
    sum = (sum0 + 'A');
    else if (sum0 <= 51)
    sum = (sum0 - 26 + 'a');
    else if (sum0 <= 61)
    sum = (sum0 -52 +'0');
    else if (sum0 == 62)
    sum = '+';
    else sum = '/';
    return sum;
}
