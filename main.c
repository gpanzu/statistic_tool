#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define n_max 100 // nombre maximum d’élèves fixé à 100

int main(int argc, char** argv)
{
    char eleves[4];
    int nb_eleves;
    int resultats[n_max];
    int resultats_ordonnes[21];
    int choix = 1;
    char stat [2];
    int choix_stat;

    // Lecture des résultats

    printf("Combien d'élèves avez-vous (maximum 100)?\n");
    scanf("%s", eleves);
    nb_eleves = atoi(eleves);
    while (nb_eleves < 1 || nb_eleves > n_max)
    {
        printf("Erreur ! Entrez une valeur comprise entre 1 et 100.\n");
        scanf("%s", eleves);
        nb_eleves = atoi(eleves);
    }

    lecture_resultats (resultats, nb_eleves);

    // Menu des données statistiques à calculer

    while (choix !=2)       /* Pour 2 eme menu (ci dessous) tant que l'utilisateur ne demande pas à sortir du programme,
                               choix de consulter une autre donnée stat. */
    {
        printf("Quelle donnée statistique voulez-vous consulter ? \n");
        printf("1. Moyenne \n");
        printf("2. L’écart-type \n");
        printf("3. Le mode \n");
        printf("4. Le minimum \n");
        printf("5. Le maximum \n");
        printf("6. Histogramme \n");
        scanf("%s", stat);
        choix_stat = atoi(stat);
        while (choix_stat < 1 || choix_stat > 6)
        {
            printf("Erreur ! Choississez une donnée statistique en idiquant son numéro.\n");
            scanf("%s", stat);
            choix_stat = atoi(stat);
        }
        switch (choix_stat)
        {
            case 1 :
                printf("La moyenne est : %.2f \n", moyenne( resultats, nb_eleves));
                break;
            case 2 :
                printf("L’écart-type est : %.2f \n", ecart_type(resultats, nb_eleves));
                break;
            case 3 :
                resultatsOrdonnes(resultats, nb_eleves, resultats_ordonnes);
                printf("Le mode est : %d \n", mode(resultats_ordonnes));
                break;

            case 4 :
                printf("Le minimum est : %d \n", min(resultats, nb_eleves));
                break;
            case 5 :
                printf("Le maximum est : %d \n", max( resultats, nb_eleves));
                break;
            case 6 :
                printf("Histogramme horizontale : \n");
                resultatsOrdonnes( resultats, nb_eleves, resultats_ordonnes);
                histogramme (resultats_ordonnes); //à vérifier et tester....
                break;
            default:
                printf("Erreur\n");
                break;
        }

        // Menu “autre donnée ou sortie du programme”

        printf("1. Voulez-vous consulter une autre donnée ?\n");
        printf("2. Quitter le programme \n");
        scanf("%s", stat);
        choix = atoi(stat);
        while (choix != 2 && choix != 1)
        {
            printf("Erreur ! Tapez 1 pour consulter une autre donnée.\n");
            printf("Tapez 2 pour quitter le programme.\n");
            scanf("%s", stat);
            choix = atoi(stat);
        }
    }
    return 0;
}