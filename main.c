/**
 * \file main.c
 * \brief Programme de tests.
 * \author Yann Feunteun
 * \version 0.1
 * \date 31 Octobre 2014
 *
 * Programme de test pour l'objet de gestion des informations avec une table de hachage.
 *
 */


#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(int argc, char* argv[])
{

    FILE *fp;
    Hashtable ht;
    int i = 0;

    if (argc < 2)
       return EXIT_FAILURE;

    if ((fp = fopen(argv[1], "r")) == NULL) {
       printf("\n Pb d'ouverture du fichier %s \n", argv[1]);
       return EXIT_FAILURE;
    }

    for(i = 0; i < HTABLE_MAX_SIZE; ++i){
        ht.Dico[i] = NULL;
    }

    remplir(&ht, fp);
    afficher(ht);

    return EXIT_SUCCESS;
}

