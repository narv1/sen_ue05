/*******************************************************************************************/
/*                           Willkommen zur 4.Aufgabe                                      */
/*            Dieses Programm zielt darauf ab den Umgang mit fopen zu erlernen             */
/*******************************************************************************************/


/*******************************************************************************************/
/*                               Author: Stefan Hermeter                                   */
/*                                  Klasse:5/6 ABETI                                       */
/*                                 Datum:  07.03.2016                                      */
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
  // zähler für Fehler und Argumenteneingabe
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
      // Der intwert count wird um 1 erhöht um später eine ifabfrage zumachen
    case 'z':
      printf("Das Textdokument \'Readsource\' wird Zeilenweise ausgegeben.\nSie koennen die Ausgabe mit \'x\' abbrechen und mit enter wird jeweils die naechste Zeile ausgegeben.\n\n");
      count++;
      break;
    }
  }
  // Bei falscheingabe beendigung des Programms
  if (stderr == 1){
    return 0;
  }
  // File initialisierung
  FILE *fp;
  int c;

  // Zählerabfrage für Argumenteneingabe
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
      // EndofFile beendigung der Schleife
      if (feof(fp))
	{ 
	  break ;
	}
      // Ausgabe des Files
      printf("%c", c);
    }
    fclose(fp);
  }
  
  if (count == 1){
    // Initialisierung Zeihlenweise einlesen
    char line[N]={0};
    // Zähler der Eingelesenen Zeilen
    int i = 1;
    // Initialisierung des characters zur beendigung des Programms mit 'x' bei Argumenteneingabe
    char x;
    
    fp = fopen("ReadSource.c","r"); 
    // Überprüfung: Korrektes oeffnen der Textdatei
    if(fp == NULL)
      {
	printf("Fehler beim Öffnen");
	exit(0);
      }

    // Kontrolle ob die Datei geöffnet werden konnte
    while(fgets(line, N, fp))
      {
	// Zeilenweise Ausgabe über enter bzw. beendigung des Programms
	if (x = getchar() == 'x')break;
        printf("line %d: %s", i, line);
	i++;
	// Bei erreichen von EndofFile beendigung der Schleife
	if (feof(fp))
	{ 
	  break ;
	}
      }
  }
  return 0;
}
