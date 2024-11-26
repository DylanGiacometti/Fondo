#include <stdio.h>
#include <unistd.h> // Include per usleep()
#include <stdlib.h>
#include <ctype.h>

/*
*    FFFFF  U   U  N   N  CCCC  TTTTT  III   OOO   N   N   SSS
*    F      U   U  NN  N  C       T     I   O   O  NN  N  S
*    FFFF   U   U  N N N  C       T     I   O   O  N N N   SSS
*    F      U   U  N  NN  C       T     I   O   O  N  NN      S
*    F       UUU   N   N  CCCC    T    III   OOO   N   N   SSS
*/

// Funzione che chiede i dati all'utente controllando che siano corretti
void askData(float *a, float *b, float *c) {
    int result;
    
    // Chiede il primo lato e verifica l'input
    do {
        printf("Inserisci il primo lato: ");
        result = scanf("%f", a);
        
        if (result == 0) {
            printf("Input non valido, riprova!\n");
            while (getchar() != '\n'); // Pulisce il buffer di input
        }
    } while (result == 0);

    // Chiede il secondo lato
    do {
        printf("Inserisci il secondo lato: ");
        result = scanf("%f", b);
        
        if (result == 0) {
            printf("Input non valido, riprova!\n");
            fflush(stdin); // Pulisce il buffer di input
        }
    } while (result == 0);

    // Chiede il terzo lato
    do {
        printf("Inserisci il terzo lato: ");
        result = scanf("%f", c);
        
        if (result == 0) {
            printf("Input non valido, riprova!\n");
            while (getchar() != '\n'); // Pulisce il buffer di input
        }
    } while (result == 0);
}

int main() {
    float a, b, c;

    printf("Benvenuto, o bentornato, nel programma che controlla automaticamente il tipo di triangolo dati i suoi 3 lati. Il programma controlla anche che i dati che inserisci quindi non fare il furbo.\n");

    // Chiama la funzione askData per ottenere i lati
    askData(&a, &b, &c);

    // Stampa i lati inseriti per conferma
    printf("Hai inserito i lati: %.2f, %.2f, %.2f\n", a, b, c);

    return 0;
}
