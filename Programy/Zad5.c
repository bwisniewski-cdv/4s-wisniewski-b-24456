#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	//Zmienna
    FILE *plik;
    char nazwa[60] = "";
    int statystyki;
    pid_t proces;
  	
	//Nowy proces
    proces = fork(); 
    
    if(argc==1)
    {
      	perror("Nie podanu argumentu!");
      	return 1;
    }
    else
    {
    	if (proces==0) //proces dziecka
    	{
            strcat(nazwa, argv[1]);
            plik = fopen(nazwa, "w"); //otwieramy plik albo tworzymy
            
            for (int i = 9; i<=99; i++)
            {
                if(i%3==0)
                {
                	fprintf(plik,"%d\n", i);
				}
            }
            fclose(plik);
            exit(0);
    	}
    	else //proces rodzica
    	{
   			wait(&statystyki);
    	}
      
    if (WIFEXITED(statystyki))
    {
        printf("Status: %d. Koniec Programu\n",WEXITSTATUS(statystyki));
    }
    return 0;
    }
}
