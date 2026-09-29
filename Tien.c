#include <stdio.h>
#include<string.h>
#define MaxLength 100
typedef struct {
    char Data[MaxLength];
    int n;
} Line;
void initLine(Line *pL) {
    pL->n = 0;
}
void readLine(Line *pL)
{
   char st[MaxLength];
   initLine(pL);
 
   fgets(st, MaxLength, stdin);
   if (st[strlen(st)-1]=='\n')
 st[strlen(st)-1]='\0';
   
   int i = 0;
   while(st[i] != '\0') {
    
      pL->Data[i] = st[i];
      pL->n++;
      i++;
   }

}    

int main(){
    int i;
    Line L;
    readLine(&L);
    for(i=0;i<=L.n-1;i++)
      printf("%c", L.Data[i]);
    return 0;
}