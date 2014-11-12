/**
 * \file liste.c
 * \brief Fonctions permettant de manipuler une liste chainée
 * \author Yann Feunteun
 * \version 0.1
 * \date 31 octobre 2014
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "hashtable.h"
#include "hashing.h"

void remplir(Hashtable *ht, FILE* flux)
{
    char buffer[512];
    PositionInsertion pos_insert = {-1, NULL}; /* element d'insertion */

    while (lireMot(flux, &buffer[0])) {
        pos_insert = existe(*ht, buffer, &hash1);
        if(pos_insert.indice >= 0 && pos_insert.indice < HTABLE_MAX_SIZE){
            if(pos_insert.ptrInformation == NULL) /* le mot n'est pas présent dans le tableau */
            {
                ht->Dico[(pos_insert.indice)] = insererEnTete(ht->Dico[(pos_insert.indice)], buffer);
            } else {                    /* Le mot est déjà présent dans le tableau */
                ++((pos_insert.ptrInformation)->nbOcc);
            }
        }
    }
}

void afficher(Hashtable ht)
{
    int i = 0;

    for(i = 0; i < HTABLE_MAX_SIZE; ++i) {
        Information *local_cpy = ht.Dico[i];  /* copie de l'index pour éviter de modifier le pointeur */
        while(local_cpy != NULL)
        {
            printf("[%d] %s => %d\n",i, local_cpy->mot, local_cpy->nbOcc);
            local_cpy = local_cpy->suivant;
        }
    }
}


PositionInsertion existe(Hashtable ht, char* mot, int(*func_hashing)(char*))
{
    PositionInsertion pos_insert = {-1, NULL}; /* element d'insertion */

    pos_insert.indice = func_hashing(mot);
    pos_insert.ptrInformation = existeInList(ht.Dico[pos_insert.indice], mot);
    return pos_insert;
}



Information* existeInList(Information* dico, char* mot)
{
    Information *local_cpy = dico;  /* copie de l'index pour éviter de modifier le pointeur */
    while(local_cpy != NULL)
    {
        if(strcmp(mot, local_cpy->mot) == 0) {
            return local_cpy;
        }
        local_cpy = local_cpy->suivant;
    }
    return NULL;
}

int lireMot(FILE * fp, char * mot) {
    int i;
    char c;
    while ( ! (isalpha (c = fgetc(fp)))) {
        if  (c == EOF) {
            mot[0] = '\0';
            return 0;
        }
    }
    mot[0] = c & 0xdf;
    i = 1;
    while ( isalpha (c = fgetc(fp))) {
        mot[i] = c & 0xdf;
        i++;
    }
    mot[i] = '\0';
    return 1;
}

Information* insererEnTete(Information* dico, char * mot)
{

    Information * elem = malloc(sizeof(Information));

    if(elem!=NULL)
    {
        elem->mot = (char *)malloc(strlen(mot) + 1 * sizeof(char));
        // Affecter les bonnes valeurs dans chacun de ses champs
        strcpy(elem->mot, mot);
        elem->nbOcc = 1;
        elem->suivant = dico;

        // Le nouvel élément devant se situer en tête de la liste, son adresse est la nouvelle adresse de la structure.
        dico=elem;
    }
    else
        exit(EXIT_FAILURE);

    return dico;

}
