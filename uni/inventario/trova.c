#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int criterio;
    do{
        printf("Benvenuto nel programma di ricerca di un prodotto\n");
        printf("Che criterio vuoi utilizzare per la ricerca?\n");
        printf("0 - ID\n");
        printf("1 - Nome\n");
        printf("2 - Numero\n");
        if (scanf("%d", &criterio) != 1)
        {
            printf("Carattere non valido, prego inserire un'opzione valida.\n");
            while (getchar() != '\n');
            criterio = 0;
        }
        else if (criterio < 0 || criterio > 2)
        {
            printf("Numero non valido, prego inserire un numero valido.\n");
        }
    } while (criterio < 0 || criterio > 2);
    
    
    // Apri il file in modalità lettura ("r")
    FILE *file = fopen("inventario.txt", "r");
    
    // Controlla se il file è stato aperto correttamente
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    // Variabile per memorizzare ogni riga letta
    char buffer[256];

    // Leggi il file riga per riga fino alla fine del file
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);  // Stampa la riga appena letta
    }

    // Chiudi il file
    fclose(file);

    switch (criterio)
    {
    case 0:
        int id, file;
        printf("Inserisci id da cercare: \n");
        scanf("%d",&id);
        file = leggiFile();
        break;
    
    default:
        break;
    }

    return 0;
}