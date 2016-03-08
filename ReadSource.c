/*******************************************************************************************/
/*                           Willkommen zum ersten Projekt!                                */
/*            Dieses Programm zielt darauf ab den Umgang mit fopen zu erlernen             */
/*******************************************************************************************/


/*******************************************************************************************/
/*                               Author: Stefan Hermeter                                   */
/*                                  Klasse:5/6 ABETI                                       */
/*                                 Datum:  14.11.2015                                      */
/*******************************************************************************************/


/*****************************************/
/*      Die verwendeten Libaries         */
/* bzw. die maximale Anzahl der Vektoren */
/*****************************************/
#include <stdlib.h>
#include <stdio.h>
#define N 300

/*****************************************/
/*         Das Hauptprogramm             */
/*****************************************/
int main(int argc, char *argv[])
{
  int stderr = 0, count = 0;
  int opt;
  //  extern char *optarg;
  extern int optopt;
  
  while ((opt = getopt(argc, argv, "hz")) != -1) {
    switch (opt) {

      // Aufruf der Hilfe mit '-h'
    case 'h':
      printf("Dies ist die Hilfe des Programmes \'ReadSource\'.\n\n\t-h\t...\tzeigt die Hilfe des Programms an.\n\t-z\t...\tgibt die Sourcequelle \'ReadSource.c\' zeilenweise aus.\n\nOhne Argument wird \'ReadSource\'komplett auf einmal ausgegeben.\n");
      return 0;

      // Wenn ein Falsches Argument aufgerufen wurde
      case'?':
      if (isprint (optopt)){
	printf ("Please Type %s, -h for more information.\n", argv[0]);
      }
      stderr++;
      break;

      // Bei Argument -z: Zeilenweise Ausgabe des Dokuments
    case 'z':
      printf("Das Textdokument \'Readsource\' wird Zeilenweise ausgegeben.\nSie koennen die Ausgabe mit \'x\' abbrechen.\n\n");
      count++;
      break;
    }
  }
  // Bei falscheingabe beendigung des Programms
  if (stderr == 1){
    return 0;
  }

  FILE *fp;
  int c;
  
  if (count == 0){
        
    fp = fopen("ReadSource.c","r");
    // Kontrolle ob die Datei geöffnet werden konnte
    if(fp == NULL)
      {
	printf("Fehler beim Öffnen");
	exit(0);
      }
    // einlesen und Ausgabe von ReadSource.c
    while(1){
      c = fgetc(fp);
      if (feof(fp))
	{ 
	  break ;
	}
      printf("%c", c);
    }
    fclose(fp);
  }
  
  if (count == 1){
    char line[N]={0};
    int i = 1;
    char x;
    
    fp = fopen("ReadSource.c","r"); 
    if(fp == NULL)
      {
	printf("Fehler beim Öffnen");
	exit(0);
      }

    // Kontrolle ob die Datei geöffnet werden konnte
    while(fgets(line, N, fp))
      {
	if (x = getchar() == 'x')break;
        printf("line %d: %s", i, line);
	i++;
	if (feof(fp))
	{ 
	  break ;
	}
      }
    
    /*    for (i = 0; i < N; i++){
      printf("%c",line);
      }*/
  }

  
  return 0;
}
