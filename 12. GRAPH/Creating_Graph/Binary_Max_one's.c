#include<stdio.h>
void main(){
    int dec,count=0,maxVal=-1;
    printf("Enter the Number in Decimal\n");
    scanf("%d",&dec);
    while(dec){
        int rem = dec%2;
        if(rem == 1)
        count++;
        else
        count = 0;
        maxVal = count > maxVal ? count : maxVal;
        dec/=2;
    }

    printf("output: %d",maxVal);

}