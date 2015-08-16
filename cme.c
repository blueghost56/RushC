#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
FILE *f;
int tmp;
pid_t pid;
int flag=-1;
 while((tmp=getchar())!='q')
 {
   if(tmp=='e')
  {

     f=fopen("tmp.c","w");
       fputs("#include<stdio.h>\nint main(){\n",f);
    
     while((tmp=getchar())!='k'){
      if(f!=NULL)
     {
       fputc(tmp,f);

      }
     }//end while
       
fputs("\n return 0;\n}",f);
fclose(f);
 flag=0;
}

if(flag==0){
 if(fork()==0)
 {
   execl("/usr/bin/gcc","gcc","-o","tmp","tmp.c",NULL); 
    exit(0);
  }else{
   wait(NULL);
  }
  if(tmp=='\n')
   {
     if(fork()==0)
     {
      execl("./tmp","tmp",NULL);
     }else{
    wait(NULL);
     flag=-1;

    }
   }
 }
}  
remove("./tmp.c");
remove("./tmp");
return 0;
}
