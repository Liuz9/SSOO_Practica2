#include<stdio.h>
struct address
{
 char name[20];
 char place[20];
 long int pin;
};
int main()
{
 FILE *p;
 struct address x;
 p=fopen("address","rb");
 printf("Rcords of file:\n");
 while(1)
 {
  fread(&x,sizeof(x),1,p);
  if(feof(p)!=0)
    break;
  printf("\n\nName:%s\nPlace:%s\nPin code:%ld",x.name,x.place,x.pin);
 }
 fclose(p);
 return 0;
}