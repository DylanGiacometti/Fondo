#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *formatText(const char *text, const int arg)
{
    static char resultMess[256]; // Buffer statico per il risultato
    static char resultKey[256];
    int j = 0;
    int k = 0;

    if (arg == 1)
    {
        // Processa ogni carattere del testo di input
        for (int i = 0; text[i] != '\0'; i++)
        {
            char ch = tolower(text[i]);
            if (ch >= 97 && ch <= 122)
            {
                resultMess[j++] = ch;
            }
        }
        resultMess[j] = '\0'; // Termina la stringa

        return resultMess;
    }
    else
    {
        // Processa ogni carattere del testo di input
        for (int i = 0; text[i] != '\0'; i++)
        {
            char ch = tolower(text[i]);
            if (ch >= 97 && ch <= 122)
            {
                resultKey[k++] = ch;
            }
        }
        resultKey[k] = '\0'; // Termina la stringa

        return resultKey;
    }
}

void encrypt()
{
    char messageIn[256];
    printf("Inserisci il messaggio da cifrare (verranno eliminati eventuali spazi, numeri e carattei speciali)\n");
    fgets(messageIn, sizeof(messageIn), stdin);

    char keyIn[256];
    printf("Inserisci la chiave da usare per cifrare\n");
    fgets(keyIn, sizeof(keyIn), stdin);

    // Rimuove il carattere di nuova linea '\n' se presente
    messageIn[strcspn(messageIn, "\n")] = 0;
    keyIn[strcspn(keyIn, "\n")] = 0;

    const char *message = formatText(messageIn, 1);
    const char *key = formatText(keyIn, 0);
    if (strlen(key) == 0)
    {
        printf("Chiave invalida, deve contenere almeno un carattere alfabetico\n");
        return;
    }
    char encryptedMess[256];
    int encryptedIndex = 0;
    int keyLen = strlen(key);

    for (int i = 0; i < strlen(message); i++)
    {
        const int mCharCode = message[i] - 97; // prendo il valore ascii del carattere di "message"
        const int kCharCode = key[i % keyLen] - 97;
        const char encryptedChar = (mCharCode + kCharCode) % 26 +97;
        encryptedMess[encryptedIndex++] = encryptedChar;
    }

    encryptedMess[encryptedIndex] = '\0'; // Termina la stringa

    printf("Messaggio cifrato: %s\n", encryptedMess);
}

void decrypt()
{
}

int main()
{
    int option;
    char bfr[10];
    printf("Programma per la cifratura e decifratura di un messaggio utilizzando il cifrario di Vigenere.\n");
    printf("Cosa vuoi fare?\n");
    printf("1 - Cifrare;\n");
    printf("2 - Decifrare;\n");
    printf("3 - Esci dal programma;\n");
    fgets(bfr, sizeof(bfr), stdin);
    option = atoi(bfr);
    switch (option)
    {
    case 1:
        encrypt();
        break;

    case 2:
        decrypt();
        break;

    case 3:
        exit(0);
        break;

    default:
        printf("Devi scegliere un opzione!");
        break;
    }

    return 0;
}