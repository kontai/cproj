#include<stdio.h>

void res(int a){
    long long int result=1;
    while(a){
        result*=a;
        a--;
    }
    printf("%d\n",result);
}

int main(){

res(9999);
return 0;

}