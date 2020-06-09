//
// Created by Grace Romane Panzu on 22/04/2020.
//

#ifndef UNTITLED3_FUNCTIONS_H
#define UNTITLED3_FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void lecture_resultats (int resultats[], int nb_eleves);
float moyenne (int resultats[], int nb_eleves);
float ecart_type(int tableau[], int nb_eleves);
int max(int tableau [], int nb_eleves);
int min(int tableau [], int nb_eleves);
void resultatsOrdonnes(int tableau [], int nb_eleves, int resultats_ordonnes[21]);
int mode( int resultats_ordonnes[21]);
void histogramme (int resultats_ordonnes[21]);


//--------------------------------- LECTURE RÉSULTATS ---------------------------------

/* lecture des résultats directement entrés par l’utilisateur.
Le nombre total des résultat est lu dans le main avant l’appel de cette fonction.
*/

/*
Spécification

*Précondition :  nb_eleves  est initialisé et  ≤  n_max
                           ∀i : 0 ≤ i <  nb_eleves ⇒ resultats[i] est initialisée

*Postcondition : résultats est un tableau qui reprend les résultats des élèves
                           nb_eleves est le nombre de résultats entrés

*/

void lecture_resultats (int resultats[], int nb_eleves)
{
    char notes[50];
    char * note_invalide;

    for (int i = 0; i < nb_eleves; i++)
    {
        printf("Entrez la note de l'élève %d \n", i + 1);
        scanf("%s", notes);
        resultats[i] = strtol( notes, &note_invalide, 10 );

        while (note_invalide == notes || resultats[i]< 0 || resultats[i]>20 )
        {
            printf( "Erreur, entrez une note comprise entre 0 et 20\n");
            scanf("%s", notes);
            resultats[i] = strtol( notes, &note_invalide, 10 );
        }
    }

}

// ---------------------------------  MOYENNE ---------------------------------

// Calcul de la moyenne à partir du tableau des résultats et du nombre d’élèves.

/*

Spécification

*Précondition :  nb_eleves  est initialisé et  compris entre 1 et  n_max
                           ∀i : 0 ≤ i <  nb_eleves ⇒ resultats[i] est initialisée

*Postcondition : renvoie la moyenne des résultats

*/


float moyenne (int resultats[], int nb_eleves)
{
    float moyenne;
    int somme = 0;
    for (int i=0; i < nb_eleves; i++)
    {
        somme = somme + resultats[i];
    }

    moyenne = somme / nb_eleves;
    return moyenne;
}

// --------------------------------- ECART-TYPE ---------------------------------

//  Calcul de l’écart-type à partir du tableau des résultats et du nombre d’élèves.


/*
Spécification

*Précondition  nb_eleves  est initialisé et  compris entre 1 et n_max
                           ∀i : 0 ≤ i <  nb_eleves ⇒ resultats[i] est initialisée

*Postcondition : la fonction renvoie l'écart-type des résultats

*/


float ecart_type(int tableau[], int nb_eleves)
{
    float somme = 0.0, moyenne, ecart_type = 0.0;
    int i;
    for (i = 0; i < nb_eleves; i++)
    {
        somme += tableau[i];
    }
    moyenne = somme / nb_eleves;
    for (i = 0; i < nb_eleves; ++i)
        ecart_type += pow(tableau[i] - moyenne, 2);
    return sqrt(ecart_type / nb_eleves);
}
// --------------------------------- MAXIMUM ---------------------------------

// Calcul du maximum à partir du tableau des résultats et du nombre d’élèves.

/*
Spécification

*Précondition :  nb_eleves  est initialisé et  compris entre 1 et  n_max
                           ∀i : 0 ≤ i <  nb_eleves ⇒ resultats[i] est initialisée

*Postcondition : la fonction renvoie le maximum des résultats

*/


int max(int tableau [], int nb_eleves)
{
    int maximum = 0;
    for (int i=0; i < nb_eleves; i++)
    {
        if (tableau[i] > maximum)
        {
            maximum = tableau[i];
        }
    }
    return maximum;
}
// --------------------------------- MINIMUM ---------------------------------

// Calcul du minimum à partir du tableau des résultats et du nombre d’élèves

/*
Spécification

*Précondition :  nb_eleves  est initialisé et compris entre 1 et   n_max
                           ∀i : 0 ≤ i <  nb_eleves ⇒ resultats[i] est initialisée

*Postcondition : la fonction renvoie le minimum des résultats

*/


int min(int tableau [], int nb_eleves)
{
    int minimum = 20;
    for (int i=0; i < nb_eleves; i++)
    {
        if (tableau[i] < minimum)
        {
            minimum = tableau[i];
        }
    }
    return minimum;
}
//--------------------------------- CRÉATION TABLEAU ORDONNÉ ---------------------------------

/* Création d’un tableau ordonné des résultats (tableau des fréquences) à partir du tableau des résultats et du nombre d’élèves.
Utilisé pour calculer le mode ou afficher l'histogramme
*/

/*

Spécification

*Précondition : nb_eleves  est initialisé et  compris entre 1 et  n_max
                           ∀i : 0 ≤ i <  nb_eleves ⇒ resultats[i] est initialisée
                          résultats_ordonnes est déclaré

*Postcondition : résultats_ordonnes[]  contient les fréquences de chaque note
                            ∀i : 0 ≤ i ≤ 20 ⇒ résultats_ordonnes[i] est initialisée
*/



void resultatsOrdonnes(int tableau [], int nb_eleves, int resultats_ordonnes[21])
{
    for ( int i = 0; i <= 20; i++)
    {
        resultats_ordonnes[i] = 0;
    }

    for ( int i = 0; i <= 20; i++)
        for(int j=0; j< nb_eleves ; j++ )
        {
            if (tableau[j] == i)
                resultats_ordonnes[i]++;
        }
}
// --------------------------------- MODE ---------------------------------

/* Calcul du mode à partir du tableau des résultats ordonnés
Remarque : s’il y a un “mode”, il est unique (distribution unimodale)
*/

/*
Spécification

*Précondition :  resultats_ordonnes est initialisé


*Postcondition : la fonction renvoie le mode des résultats

*/


int mode(int resultats_ordonnes[21])
{
    int mode = 0;
    for (int i = 0; i <= 20; i++)
        if (resultats_ordonnes[i] > resultats_ordonnes[mode])
            mode = i;
    return mode;
}
// --------------------------------- HISTOGRAMME ---------------------------------

// Création d’un histogramme à partir du tableau des résultats ordonnés

/*

Spécification

*Précondition :  resultats_ordonnes est initialisé.

*Postcondition : l’histogramme des résultats est affiché à l’écran

*/


void histogramme (int resultats_ordonnes[21])
{
    for (int i = 20; i >= 0; i--) {
        printf("%d | ", i);
        for (int j = 1; j <= resultats_ordonnes[i]; j++)
            printf("=");
        printf("\n");
    }
}

#endif //UNTITLED3_FUNCTIONS_H
