#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#if 0
int main(int argc, char const *argv[])
{

    /*
        fget 
    */

    char ch[1024]="";
    fgets(ch,sizeof(ch),stdin);
    ch[strlen(ch)-1]=0;
    printf("%s\n",ch);
    // system("pause");

    return 0;
}


int main(void) {

  char str1[128] = "hello";
  char str2[128] = "123456";
  short index = strlen(str1) ;
  printf("%hd\n",index);
  for (int i = 0; i < strlen(str2); i++) {
    str1[index] = str2[i];
    index++;
  }
  printf("%s\n",str1);
}

#endif

int main(void){

  int t=time(NULL);
  srand(t);
  for(int i=0;i<10;i++){
    printf("%d\n",rand()%100);
  }


}