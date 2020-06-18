#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	//Zmienne
	pid_t proces;
    int statystyki;
    
    proces = fork();
    
    if(proces==0) //proces dziecka
    {
      execlp("ls","ls","-l",NULL);
      exit(0);
    }
    else //proces rodzica
    {
        wait(&statystyki);
    }
    
    if(WIFEXITED(statystyki))
    {
        printf("Status: %d. Program zakonczyl swoja prace\n",WEXITSTATUS(statystyki));
    }
    return 0;
}
