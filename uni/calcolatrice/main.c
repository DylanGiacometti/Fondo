#include <stdio.h>

int main() {
    printf("! C A L C O L A T R I C E !\a\n");

    int azione;
    int num1, num2, risultato;
    
    // Ciclo che ripete finché l'utente non inserisce un'operazione valida
    do {
        // Chiede all'utente quale operazione vuole eseguire
        printf("Scegli quale operazione vorresti eseguire: \n");
        printf("1. Addizione\n");
        printf("2. Sottrazione\n");
        printf("3. Moltiplicazione\n");
        printf("4. Divisione\n");
        printf("5. Tutte (verrai fornito di una lista)\n");
        printf("Inserisci un numero (1-5): ");
        
        // Controlla se scanf legge un numero intero
        if (scanf("%d", &azione) != 1) {
            printf("\nInput non valido! Riprovare.\n\n");
            // Pulisci il buffer di input
            while (getchar() != '\n');  // Consuma fino alla fine della linea
            azione = 0; // Imposta azione a un valore non valido per continuare il ciclo
        }
        else if (azione < 1 || azione > 5) {
            printf("\nNumero non valido! Riprovare.\n\n");
        }

    } while (azione < 1 || azione > 5);  // Continua a chiedere finché il numero non è valido

    // Chiede i numeri solo se l'operazione è valida
    printf("Inserisci il primo numero: ");
    scanf("%d", &num1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &num2);

    // Esegue l'operazione in base alla scelta
    switch (azione) {
        case 1: // Addizione
            risultato = num1 + num2;
            printf("La somma è: %d\n", risultato);
            break;
        
        case 2: // Sottrazione
            risultato = num1 - num2;
            printf("La sottrazione è: %d\n", risultato);
            break;
        
        case 3: // Moltiplicazione
            risultato = num1 * num2;
            printf("La moltiplicazione è: %d\n", risultato);
            break;
        
        case 4: // Divisione
            if (num2 != 0) {
                float divisione = (float)num1 / num2;
                printf("La divisione è: %.2f\n", divisione);
            } else {
                printf("Errore: divisione per zero non permessa.\n");
            }
            break;
        
        case 5: // Tutte le operazioni
            printf("La somma è: %d\n", num1 + num2);
            printf("La sottrazione è: %d\n", num1 - num2);
            printf("La moltiplicazione è: %d\n", num1 * num2);
            if (num2 != 0) {
                printf("La divisione è: %.2f\n", (float)num1 / num2);
            } else {
                printf("Errore: divisione per zero non permesssa.\n");
            }
            break;
    }

    return 0;
}
