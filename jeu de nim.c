#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int batonnets;
    int choix, tour;
    char rejouer;

    srand(time(NULL)); // Initialise le hasard

    do {
        // --- INITIALISATION ---
        batonnets = 20;
        tour = 0; // 0 = Joueur, 1 = IA

        printf("\n==================================\n");
        printf("      JEU DE NIM (BATONNETS)      \n");
        printf("==================================\n");
        printf("Regle : Ne prenez pas le dernier !\n\n");

        // --- BOUCLE DE LA PARTIE ---
        while (batonnets > 0) {
            // Affichage visuel des bâtonnets
            printf("\nStock : ");
            for (int i = 0; i < batonnets; i++) {
                printf("| ");
            }
            printf(" (%d restants)\n", batonnets);

            if (tour == 0) {
                // TOUR DU JOUEUR
                do {
                    printf("Combien de batonnets (1, 2 ou 3) ? ");
                    scanf("%d", &choix);
                    if (choix < 1 || choix > 3 || choix > batonnets) {
                        printf("Action impossible ! Reessaie.\n");
                    }
                } while (choix < 1 || choix > 3 || choix > batonnets);
                
                batonnets -= choix;
                if (batonnets <= 0) {
                    printf("\n--- Dommage ! Vous avez pris le dernier. L'IA gagne ! 🤖 ---\n");
                }
                tour = 1; // Au tour de l'IA
            } 
            else {
                // TOUR DE L'IA
                printf("L'IA reflechit...\n");
                
                // Calcul de l'IA pour essayer de gagner
                choix = (batonnets - 1) % 4;
                if (choix == 0) choix = 1; // Si elle ne peut pas gagner direct, elle prend 1
                
                printf("L'IA retire %d batonnet(s).\n", choix);
                batonnets -= choix;
                
                if (batonnets <= 0) {
                    printf("\n--- BRAVO ! L'IA a pris le dernier. GAGNE ! 🎉 ---\n");
                }
                tour = 0; // Au tour du joueur
            }
        }

        // --- OPTION REJOUER ---
        printf("\nVoulez-vous faire une autre partie ? (o/n) : ");
        scanf(" %c", &rejouer); 

    } while (rejouer == 'o' || rejouer == 'O');

    printf("\nMerci d'avoir joue ! A bientot. 👋\n");

    return 0;
}