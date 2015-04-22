#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti

#define NumeroStudenti 3
#define MAX_STRLEN 30

// Definisci il tipo di dato struct s_studente
struct s_studente {
	char nome[MAX_STRLEN+1];
	char cognome[MAX_STRLEN+1];
        int eta;
	char classe[MAX_STRLEN+1];
}studenti[NumeroStudenti];
// Definisci studente come struct s_studente
typedef struct s_studente studente;


int main(int argc, char** argv) {
    // Dichiara le variabili locali
    FILE *puntafile;
    int i;
    
    
    // Codice per l'inserimento, da parte dell'utente, dei dati e del salvataggio
    //nel file
    puntafile = fopen("elenco.dat","wb");
    if(puntafile){
    for (i=0;i<NumeroStudenti;i++) {
		
	printf("Inserisci il nome del %d studente: \n", i+1);
	    scanf("%s", studenti[i].nome);
		
        printf("Inserisci il cognome del %d studente: \n",i+1);
		scanf("%s", studenti[i].cognome);
		
        printf("Inserisci l eta' del %d studente: \n",i+1);
		scanf("%d", &studenti[i].eta);
		
        printf("Inserisci la classe del %d studente: \n",i+1);
		scanf("%s", studenti[i].classe);
                
                fwrite(&studenti,sizeof(studente),1,puntafile);
	}
   
    fclose(puntafile);
    
    puntafile=fopen("elenco.dat","rb");
    
    for (i=0;i<NumeroStudenti;i++) {
        fread(&studenti, sizeof(studente), 1, puntafile);
		printf("%s; %s; %d; %s\n", studenti[i].nome, studenti[i].cognome, studenti[i].eta, studenti[i].classe);
	}
    fclose(puntafile);
}    
    return (EXIT_SUCCESS);
}