#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int randoRange(int min, int max)
{
	int num;
	num = (rand() % (max - min +1) + min);
	return num;
}

int main(int argc, char *argv[])
{
    const int min = 10, max = 99;
    int odczyt, i = 0, num[10];
    char bufor[50];
    if(argc != 2)
	{
        char nazwa_pliku[30];
        fprintf(stdout,"Podaj nazwe pliku: ");
        fscanf(stdin, "%s", nazwa_pliku);
        printf("Utworzono plik o nazwie: %s\n", nazwa_pliku);
        odczyt = open(nazwa_pliku, O_CREAT | O_RDWR, 0644);
        for(;i < 10; i++)
		{
            num[i] = randoRange(min, max);
            snprintf(bufor, 40, "%d", num[i]);
            write(odczyt,bufor,4);
            write(odczyt, "\n", 2);
        }
        
        close(odczyt);
    }
    if(argc == 2)
	{
        odczyt = open(argv[1], O_CREAT | O_RDWR, 0644);
        for(;i < 10; i++)
		{
            num[i] = randoRange(min, max);
            printf("%d\n", num[i]);
            snprintf(bufor, 40, "%d", num[i]);
            write(odczyt,bufor,4);
            write(odczyt, "\n", 2);
        }
        
    close(odczyt);
    }
}
