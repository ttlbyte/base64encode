# include <stdio.h>
# include <string.h>
# include <math.h>
# include <malloc.h>

void encode_base64(char* unit, char* out);
char inttochar(int* a);
void chartoint(char x,int* a);
int bth(int x);
void main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf ("Usage:%s string\n",argv[0]);
        return;
    }
    int _length = 0;
    char* s = (char*)malloc(sizeof(char)*1000);
    char* tmp = (char*)malloc(sizeof(char)*3);
    _length = strlen(argv[1]);
    int i,j;
    i = _length / 3;
    j = _length % 3;           //split the origin string into 3*i substring
    for (int k = 0;k < i;k++) //every substring has 3 char,convert it into 4 chars
    {
        tmp[0] = argv[1][3*k];
        tmp[1] = argv[1][3*k+1];
        tmp[2] = argv[1][3*k+2];
        encode_base64(tmp,s+4*k);
    }
    tmp[2] = '\0';
    if (j!=0) tmp[0] = argv[1][3*i];
    else tmp[0] = '\0';
    if (j==2)     tmp[1] = argv[1][3*i+1];
    else tmp[1] = '\0';
    encode_base64(tmp,s+4*i);
    if (j!=0)  s[4*(i+1)-1] = '=';
    if (j==1)  s[4*(i+1)-2] = '=';
    printf("%s\n", s);
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
void encode_base64(char* unit, char* out)//encode 3 chars into char4
{
    if(unit[0]!='\0')
    {
        char* tmp = (char*)malloc(sizeof(char)*3);
        int tmp1[8]={0,0,0,0,0,0,0,0};
        int* total = (int*)malloc(sizeof(int)*24);
        int i = 0;
        int j = 0;
        for (;i<3;i++)
        chartoint(unit[i],total+8*i);
        for(i=0;i<4;i++)
            {
                for(j=7;j>1;j--)
                {
                    tmp1[j]=total[6*i+j-2];
                }
                out[i]=inttochar(tmp1);
            }
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
