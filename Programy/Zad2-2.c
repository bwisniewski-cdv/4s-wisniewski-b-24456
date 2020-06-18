#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[]){

    int odczyt, liczba;
    char bufor[60];


    if(argc != 2)
	{
        perror("Nie podano nazwy pliku!");
        return 1;
    }
    
    odczyt = open(argv[1], O_RDONLY);
    
    for(int i = 1; i < 11; i++)
	{
        read(odczyt, &bufor, 2);
        lseek(odczyt, 4, SEEK_CUR);
        liczba = atoi(bufor) * 3;
        printf("%d\n", liczba);
    }
    return 0;
}
