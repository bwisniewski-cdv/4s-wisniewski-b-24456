#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
  //Zmienne
  ssize_t test;
  int odczyt, zapis, i=0;
  char plik[255] = "";
  char bufor[1];
 
  if(argc != 2)
  {
    perror("Nieprawidlowa ilosc arguemntow lub ich brak");
    return 1;
  }
  
  //Odczyt pliku
  odczyt = open(argv[1], O_RDONLY);
  
  strcpy(plik, argv[1]);
  strcat(plik, ".red"); 
  
  //Utworzenie pliku
  zapis = open(plik, O_CREAT | O_TRUNC | O_WRONLY, 0644);
  
  while (read(odczyt, &bufor, 1) == 1) 
    {
	  if( (i % 3) == 0) 
    	{
		  write(zapis, &bufor, 1);
	    }
	  	i++;
    }
  close (zapis);
  close (odczyt);

  return 0;
}

