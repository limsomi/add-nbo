#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>


int main(int argc,char**argv)
{
    FILE* fp1;
    FILE* fp2;
    uint32_t num1,num2;
    uint32_t result;

    fp1=fopen(argv[1],"rb");
    fp2=fopen(argv[2],"rb");

    fread(&num1,sizeof(int),1,fp1);
    fread(&num2,sizeof(int),1,fp2);

    uint32_t num1_v2=htonl(num1);
    uint32_t num2_v2=htonl(num2);
    result=num1_v2+num2_v2;
    if(result < num1_v2 | result < num2_v2)
        result=UINT32_MAX;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n",num1_v2,num1_v2,num2_v2,num2_v2,result,result);
}   