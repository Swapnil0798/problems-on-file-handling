#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

# define FILESIZE 1024

void fileconcat(char source[],char Destination[])
{
  int fdsrc=0;
  int fddes=0;
  int iret=0;
  char Buffer[FILESIZE];

  fdsrc=open(source,O_RDONLY);
  if(fdsrc==-1)
  {
     printf("Unable to open source file\n");
     return;
  }

  fddes=open(Destination,O_RDWR|O_APPEND);
  
  if(fddes==-1)
  {
    printf("Unable to OPEN destination\n");
    return;
  }
 while((iret=read(fdsrc,Buffer,FILESIZE))!=0)
 {
    write(fddes,Buffer,iret);
 }
 close(fdsrc);
 close(fddes);
}
///////////////////////////////////////////////////////
//copy the file in the another file 
////////////////////////////////////////////////
int main()
{
  char Fname1[20];
  char Fname2[20];
  
  printf("Enter file name if contains a data:\n");
  scanf("%s",Fname1);

  printf("Enter file name if contains a data:\n");;
  scanf("%s",Fname2);

  fileconcat(Fname1,Fname2);
   return 0;
}