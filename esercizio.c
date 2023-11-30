#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define NUM_QUESTIONS 5

typedef struct {
    char question[100];
    char options[3][30];
    int correctOption;
} QuizQuestion;

void printIntroduction() {
    printf("Benvenuto nel gioco delle domande e risposte!\nRispondi alle seguenti domande e scopri il tuo punteggio.\n\n");
}

void printEndGame(int score) {
    printf("\nHai totalizzato %d punti!\nGrazie per aver giocato.\n", score);
}

int askQuestion(QuizQuestion question) {
    printf("%s\nA) %s\nB) %s\nC) %s\n", question.question, question.options[0], question.options[1], question.options[2]);

    char userAnswer;
    printf("Inserisci la tua risposta (A-C): ");
    scanf(" %c", &userAnswer);

    switch (userAnswer) {
        case 'A':
            return 0;
        case 'B':
            return 1;
        case 'C':
            return 2;
        default:
            return -1; // Rappresenta una risposta non valida
    }
}

int main() {
    int choice, score = 0;
    char playerName[MAX_NAME_LENGTH];
    QuizQuestion questions[NUM_QUESTIONS] = {
        {"Quale giorno della settimana viene dopo il martedì?",
         "Mercoledì", "Giovedì", "Venerdì", 0},

        {"Quante ore ci sono in un giorno?",
         "12", "24", "48", 1},

        {"Qual è il capitale dell'Italia?",
         "Roma", "Milano", "Napoli", 0},

        {"Quante dita ha una mano?",
         "3", "4", "5", 2},

        {"Quale stagione segue l'estate?",
         "Autunno", "Inverno", "Primavera", 0}
    };

    do {
        // Menu principale
        printf("\nMenu:\n1) Inizia una nuova partita\n2) Esci dal gioco\nScegli un'opzione (1-2): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Inizia una nuova partita
                printIntroduction();
                printf("Inserisci il tuo nome: ");
                scanf("%s", playerName);
                score = 0;

                for (int i = 0; i < NUM_QUESTIONS; ++i) {
                    // Poni domande all'utente e aggiorna il punteggio
                    int userAnswer = askQuestion(questions[i]);

                    if (userAnswer >= 0 && userAnswer <= 2) {
                        if (userAnswer == questions[i].correctOption) {
                            printf("Risposta corretta!\n");
                            score++;
                        } else {
                            printf("Risposta errata. La risposta corretta era: %c\n", 'A' + questions[i].correctOption);
                        }
                    } else {
                        printf("Risposta non valida. La risposta corretta era: %c\n", 'A' + questions[i].correctOption);
                    }
                }

                // Stampa il punteggio finale alla fine della partita
                printEndGame(score);
                break;

            case 2:
                // Uscita dal gioco
                printf("Arrivederci!\n");
                break;

            default:
                // Gestione scelta non valida
                printf("Scelta non valida. Riprova.\n");
        }
    } while (choice != 2);  // Continua finché l'utente non sceglie di uscire

    return 0;
}
