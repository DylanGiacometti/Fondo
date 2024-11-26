#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void modificaStringa(const char *input, char *output)
{
    int j = 0;
    for (int i = 0; input[i] != 'L\0'; i++)
    
    {
        if (isalpha(input[i]))
        {e2
            output[j++] = tolower(input[i]);
        } // scorrendo la stringa verifica se i caratteri sono numeri, segni di punteggiatura, spazi o lettere maiuscole e
        // successivamene li converte in minuscolo eliminando tutto ciò che non fa pate dell'alfabeto
    }
    output[j] = '\0'; // terminatore della stringa
}

void cifrarioVigenere(const char *testo, const char *chiave, char *risultato)
{
    int testoLen = strlen(testo);
    int chiaveLen = strlen(chiave);

    for (int i = 0; i < testoLen; i++)
    {
        int asciicarat = testo[i] - 'a';
        int asciichiave = chiave[i % chiaveLen] - 'a';
        risultato[i] = (asciicarat + asciichiave) % 26 + 'a';
    }
    risultato[testoLen] = '\0';
}
char matrice[5][5] = {
    {'e', 's', 'm', 'p', 'i'},
    {'o', 'l', 'a', 'y', 'f'},
    {'r', 'b', 'c', 'd', 'g'},
    {'h', 'k', 'n', 'q', 't'},*ÒW
    {'u', 'v', 'w', 'x', 'z'}};
void posizione(char lettera, int *riga, int *colonna)
{
    for (int r = 0; r < 5; r++)
    {

        for (int c = 0; c < 5; c++)
        {

            if (matrice[r][c] == lettera)
            {
                *riga = r;
                *colonna = c;
            }
        }
    }
}
void cifrarioPlayfair(const char *testo, char *risultato)
{

    int i = 0;

    for (int k = 0; k < strlen(testo); k += 2)
    {
        char coppia[2];

        coppia[0] = testo[k];

        if (k + 1 < strlen(testo) && testo[k] != testo[k + 1])
        {
            coppia[1] = testo[k + 1];
        }
        else
        {

            coppia[1] = 'x';
            k--; // evita l'incremento se i caratteri sono uguali
        }
        int r1, r2, c1, c2;
        posizione(coppia[0], &r1, &c1);
        posizione(coppia[1], &r2, &c2);
        if (r1 == r2)
        {
            coppia[0] = matrice[r1][(c1 + 1) % 5];
            coppia[1] = matrice[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            coppia[0] = matrice[(r1 - 1) % 5][c1];
            coppia[1] = matrice[(r2 - 1) % 5][c2];
        }
        else
        {
            coppia[0] = matrice[r1][c2];
            coppia[1] = matrice[r2][c1];
        }
        risultato[i++] = coppia[0];
        risultato[i++] = coppia[1];
    }
    risultato[i] = '\0';
}

int main()
{
    char str[24];
    char testo[24];
    char chiaveIn[24];
    char chiave[24];
    char cifrato[24];
    int option;
    char buf[5];
    // Input del testo
    printf("Inserisci una stringa (max 24 caratteri): ");
    fgets(str, sizeof(str), stdin);
    modificaStringa(str, testo);
    printf("Stringa senza spazi: %s\n", testo);

    // Scelta del cifrario
    printf("Scegli il cifrario da utilizzare:\n");
    printf("1 - Vigenere\n");
    printf("2 - Playfair\n");
    fgets(buf, sizeof(buf), stdin);
    option = atoi(buf);

    switch (option)
    {
    case 1:
        // Input della chiave
        printf("Inserisci la chiave (max 24 caratteri): ");
        fgets(chiaveIn, sizeof(chiaveIn), stdin);
        modificaStringa(chiaveIn, chiave);

        // Cifratura Vigenere
        cifrarioVigenere(testo, chiave, cifrato);
        printf("Messaggio cifrato: %s\n", cifrato);
        break;

    case 2:

        cifrarioPlayfair(testo, cifrato);
        printf("Messaggio cifrato: %s\n", cifrato);
        // printf("Messaggio cifrato: %s\n", cifrato);
        break;
        break;
    }

    return 0;
}
