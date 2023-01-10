#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct cellule {

   int valeur;

   struct cellule * succ;

         // pointeur vers la cellule suivante

};

typedef struct cellule T_cellule;

   // definition de type, permet d'eviter

   // d'avoir a ecrire a chaque fois "struct cellule"

   // les prototypes des fonctions

char bon_choix(char *s);

int affiche_menu_et_saisie_choix(void);

void afficher_cellule(T_cellule * c);

void affiche_liste(T_cellule * c);

T_cellule * detruire_liste(T_cellule * c);

T_cellule * ajouter(T_cellule * c);

void rechercher(T_cellule * c);

// la fonction principale

int main(void) {

   char choix;

   T_cellule * tete;

   tete = NULL;

   do {

         switch (choix = affiche_menu_et_saisie_choix())

         {

               case 'A' : tete = ajouter(tete); break;

               case 'V' : affiche_liste(tete); break;

               case 'S' : tete = detruire_liste(tete); break;

               case 'R' : rechercher(tete); break;

               case 'Q' : { tete = detruire_liste(tete);

                                   // desallouer toujours proprement avant de sortir

                                   printf("\n\nAu revoir\n");

                                }

          }

      } while (choix !='Q');

   printf("\n");

}

// les declarations completes des fonctions

char bon_choix(char *s) {

/* cette fonction teste si le premier caractère d'une chaîne correspond à un caractère parmi ‘A','a', ‘V', ‘v', ‘S', ‘s', ‘R', ‘r', ‘Q', ‘q', elle retourne un unique caractère majuscule dans ce cas et le caractère ‘\0' sinon. */

char r;

switch (s[0])

{

   case 'A' :;

   case 'a' : r = 'A';break;

   case 'V' :;

   case 'v' :r = 'V';break;

   case 'S' :;

   case 's' :r = 'S';break;

   case 'R' :;

   case 'r' :r = 'R';break;

   case 'Q' :;

   case 'q' : r = 'Q';break;

   default: r='\0';

}

return r;

}

int affiche_menu_et_saisie_choix(void)

{

/* Permet d'afficher un menu, de lire une chaîne et de vérifier si le premier caractère de cette chaîne correspond à un des choix possibles du menu.*/

// Elle affiche un message d'erreur si le choix n'est pas bon et ré-affiche ensuite le menu.

char s_choix[2];

do {

   printf("\n ajouter -> A");

   printf("\n voir liste -> V");

   printf("\n supprimer liste -> S");

   printf("\n rechercher -> R");

   printf("\n quitter -> Q");

   printf("\n");

   printf("\n votre choix : ");

   scanf("%s",s_choix);

   printf("\n");

   if (!bon_choix(s_choix))

      {

         printf("\n\nVotre choix n'est pas bon ,recommencez SVP\n");

      }

} while (!bon_choix(s_choix));

return (bon_choix(s_choix));

}

void afficher_cellule(T_cellule * c) {

// Fonction qui affiche le contenu d'une cellule

if (c==NULL)

{

   printf("\rien a afficher, cellule vide\n");

}

else

{

   printf("\nla cellule rangee a l'adresse %p contient la valeur %d ",c,c->valeur);

   printf("\nla cellule qui suit est rangee a l'adresse %p ",c->succ);

   printf("\n");

}

}

void affiche_liste(T_cellule * c) {

// Fonction qui affiche le contenu d'une liste cellule par cellule

if (c==NULL)

{

   printf("\nrien a afficher, liste vide\n");

}

else {

   do {

         afficher_cellule(c);

         c = c -> succ;

        } while (c!=NULL);

  }

}

T_cellule * detruire_liste(T_cellule * c) {

// Fonction qui libère toute la place mémoire occupée par une liste que l'on veut détruire

//initialement c contient la valeur du pointeur vers la cellule de tête de liste à détruire

T_cellule * inter;

if (c==NULL)

{

   printf("\nrien a detruire, liste vide\n");

}

else

{

   do {

         inter = c -> succ; //inter pointe sur la prochaine cellule a détruire

         printf("\nrecuperation de la memoire de la cellule a l'adresse %p",c);

         free(c);

         c = inter;

        } while (c!=NULL);

}

return NULL; //puisque toute la liste a été détruite on renvoie NULL

}

T_cellule * ajouter(T_cellule * c) {

// Fonction qui crée une cellule (allocation dynamique avec « malloc »).

T_cellule * nouvelle;

nouvelle = ( T_cellule *)malloc(sizeof( T_cellule));

printf("\nun entier SVP ");

scanf("%d",&(nouvelle->valeur));

nouvelle -> succ = c; return nouvelle;

}

void rechercher(T_cellule * c) {

// Fonction qui recherche une valeur particulière dans une liste.

// Affiche l'adresse de la cellule qui contient la valeur si cette dernière est dans la liste et un message

// disant que la valeur n'est pas dans la liste sinon.

int val,trouve;

trouve = 0;

if (c==NULL)

{

   printf("\nrien a rechercher, liste vide\n");

}

else {

   printf("\nl'entier recherche SVP ");

   scanf("%d",&val);

   do {

         if (c->valeur == val)

        {

          printf("\n\nl'entier recherche %d",val);

           printf("\nse trouve dans la cellule a l'adresse %p",c);

           c = NULL;

// pour stopper la boucle do while

          trouve = 1;

// pour memorise le fait que l'on a trouve

      }

        else

      {

         printf("\npanparcours cellule a l'adresse %p, valeur %d",c,c->valeur);

         c = c-> succ;

      }

} while ((c!=NULL)&& (trouve !=1));

if (trouve ==0)

{

   printf("\n\nrecherche entier %d ",val);

   printf("ne se trouve pas dans la liste");

   printf("\n");

}

}

}
