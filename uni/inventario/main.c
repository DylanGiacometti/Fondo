#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Ciao! Benvenuto nel programma dedicato all'inventario!\n");
    printf("Qui poi cercare, trovare e modificare l'inventario di bordo!\n");

    int azione;

    do
    {
        // cHIEDI ALL'UTENTE QUALE AZIONE ESEGUIRE
        printf("Quale zione vuoi eseguire?\n");
        printf("0 - Trova un elemento\n");
        printf("1 - Modifica un elemento\n");
        printf("2 - Aggiungi un elemento\n");
        printf("3 - ottieni la lista di tutti gli elementi\n");
        printf("Seleziona un numero da 0 a 3:\n ");

        if (scanf("%d", &azione) != 1)
        {
            printf("Carattere non valido, prego inserire un'opzione valida.\n");
            while (getchar() != '\n');
            azione = 0;
        }
        else if (azione < 0 || azione > 3)
        {
            printf("Numero non valido, prego inserire un numero valido.\n");
        }
    } while (azione < 0 || azione > 3);

    switch (azione)
    {
    case 0:
        // Comando da eseguire, in questo caso, un semplice comando 'ls' per elencare i file in una directory
        const char *comando = "./trova"; // Puoi sostituire "ls -l" con qualsiasi comando o programma che desideri eseguire

        // Chiama il comando usando system()
        int risultato = system(comando);

        // Verifica il risultato dell'esecuzione del comando
        if (risultato == -1)
        {
            perror("Errore nell'esecuzione del comando");
        }
        break;

    default:
        break;
    }
}