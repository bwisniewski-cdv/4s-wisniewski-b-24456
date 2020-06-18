#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
//zmienne
pid_t proces;
pid_t proces_rodzica;
int tworzenie_katalogu, i, wstatus;
struct stat statystyki;

	if(argc <= 1) // >1 - wywoalnie programu i piku
	{
		perror("Za malo argumentow");
	}
	
	proces=fork(); //Nowy proces identyczny do rodzica


	if(proces==0) // proces dziecka
	{
		FILE *plik; //otwwarcie pliku
		
		tworzenie_katalogu = mkdir("Zaliczenie", 0755);
		//Blad z tworzeniem katalogu
		if(tworzenie_katalogu == -1)
		{
			perror("Nie mozna utworzyc katalogu zaliczenie lub juz istnieje.\n");
		}
		
		//Operacje na pliku
		plik = fopen("Zaliczenie/lista.txt", "w");
		
		for(i = 1; i<argc; i++)
		{	
			if(lstat(argv[i], &statystyki) == -1)
			{
				fprintf(plik, "Blad pliku %s - nie istnieje  \n", argv[i]);
				continue;
			}
			else if(S_ISREG(statystyki.st_mode)) //sprawdzanie czy plik jest tekstowy lub binarny
			{
				fprintf(plik, "Plik %s - Rozmiar: %d\n", argv[i], (int)statystyki.st_size);
				continue;
			}
			else
			{
				fprintf(plik, "Plik %s: - plik nieregularny \n", argv[i]);
				continue;
			}		
	}
	
	fclose(plik); //zamkniecie pliku
	
	}
	else if(proces > 0) //proces rodzica
	{
		
		proces_rodzica = wait(&wstatus);
		printf("PID rodzica: %d\n", (int) getpid());
		printf("PID dziecka: %d\n", (int) proces_rodzica);
		
		
		//Zakonczenie programu
		if(WIFEXITED(wstatus))
        {
            printf("Status: %d. Program zakonczyl swoje dzialanie.\n", WEXITSTATUS(wstatus) );
        }
	}
	
	return 0;
}
