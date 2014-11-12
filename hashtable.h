/**
 * \file hashtable.h
 * \brief Header du fichier liste.c
 * \author Yann Feunteun
 * \version 0.1
 * \date 31 octobre 2014
 *
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H


/**
 * \struct Information
 * \brief Objet Information
 *
 * Information est un petit objet de gestion de duet mot-nombre d'occurence du mot dans un texte.
 * C'est un quantum de liste chaînée.
 */
typedef struct element {
    char * mot; /*!< Un mot du texte. */
    int nbOcc;  /*!< Le nombre d'occurence de ce mot dans le texte. */
    struct element * suivant; /*!< Un pointeur sur l'élément suivant de la structure liste. */
}Information;

#define HTABLE_MAX_SIZE 1024

typedef struct {
    Information* Dico[HTABLE_MAX_SIZE];
}Hashtable;

typedef struct {
    int indice;
    Information* ptrInformation;
}PositionInsertion;

/**
 * \fn Information *remplir(Information* dico, FILE* flux)
 * \brief Remplir la structure avec les mots du fichier correspondant à flux.
 * \param dico Un pointeur sur l'index à remplir.
 * \param flux Un flux de données comprenant les mots à ajouter à l'index.
 * \return Un pointeur sur la structure remplie à partir de flux.
 * */
void remplir(Hashtable *ht, FILE* flux);

/**
 * \fn void afficher(Information* dico)
 * \brief Afficher le contenu de la structure sous la forme d'un duet <mot => nombre d'occurence>.
 * \param dico Un pointeur sur l'index à afficher.
 **/
void afficher(Hashtable ht);

/**
 * \fn Information* existe(Information* dico, char* mot)
 * \brief Tester si le mot mot est présent ou non dans la structure.
 * \param dico Un pointeur sur l'index à afficher.
 * \param mot Le le mot recherché.
 * \return Un pointeur sur l'élément de la structure contenant le mot recherché
 * ou NULL si le mot n'est pas encore dans la structure.
 * */
Information* existeInList(Information* dico, char* mot);



PositionInsertion existe(Hashtable ht, char* mot, int(*func_hashing)(char*));



/**
 * \fn int lireMot(FILE * fp, char * mot)
 * \brief Lit un mot dans flux de données et remplit le tableau mot.
 * La chaine est convertie en majuscule.
 * \param fp Un flux de données comprenant les mots à lire.
 * \param mot Une chaine de caractères qui sera ramplie avec le mot lu.
 * \return Retourne 1 si un mot a été lu, 0 sinon.
 * */
int lireMot(FILE * fp, char * mot);



/**
 * \fn Information* insererEnTete(Information* dico, char * mot)
 * \brief Ajoute un élément en tête de la structure liste.
 * \param dico Un pointeur sur la structure.
 * \param mot Le le mot à ajouter à la structure.
 * \return Un pointeur sur la structure mise à jour.
 * */
Information* insererEnTete(Information* dico, char * mot);



#endif // HASHTABLE_H
