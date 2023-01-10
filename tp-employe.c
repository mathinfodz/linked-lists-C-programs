
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employeur{
    int identifiant;
    char nom_emp[40];
    char prenom_emp[40];
    char situation_f[40];
    int grade;
    struct employeur *suiv;
};

typedef struct employeur empl;
/*----------------------fonctions---------------------------------------------------*/
void inserer(empl **tete, int identifiant, char nom_emp[40], char prenom_emp[40],char situation_f[40], int grade)
{
    
    empl * employeur = malloc(sizeof(empl));
    employeur->identifiant = identifiant;
    strcpy(employeur->nom_emp, nom_emp);
    strcpy(employeur->prenom_emp, prenom_emp);
    strcpy(employeur->situation_f, situation_f);
    employeur->grade = grade;
    employeur->suiv = NULL;
    
    if(*tete==NULL)
    {
        /* if head is NULL, set employeur as the new head */
        *tete = employeur;
    }
    else{
        /* if list is not empty
         insert employeur in beginning of head */
        employeur->suiv = *tete;
        *tete = employeur;
    }
    
}
void rechercher(empl *tete, int identifiant)
{
    empl * temp = tete;
    while(temp!=NULL){
        if(temp->identifiant==identifiant){
            printf("ID: %d\n", temp->identifiant);
            printf("nom_emp: %s\n", temp->nom_emp);
            printf("prenom_emp: %s\n", temp->prenom_emp);
            printf("situation familiale: %s\n", temp->situation_f);
            printf("Grade: %d\n", temp->grade);
            return;
        }
        temp = temp->suiv;
    }
    printf("employeur avec ID %d n'existe pas !!!\n", identifiant);
}
void modifier(empl **tete, int identifiant)
{
    
    empl * temp = *tete;
    while(temp!=NULL){
        
        if(temp->identifiant==identifiant){
            printf("employeur avec ID %d existe !!!\n", identifiant);
            printf("Entrer nom_emp: ");
            scanf("%s", temp->nom_emp);
            printf("Entrer penom: ");
            scanf("%s", temp->prenom_emp);
            printf("situation familiale:");
            scanf("%s", temp->situation_f);
            printf("Entrer grade: ");
            scanf("%d",&temp->grade);
            printf("modification avec succes!!!\n");
            return;
        }
        temp = temp->suiv;
        
    }
    printf("employeur avec ID %d n'existe pas !!!\n", identifiant);  
}

void supprimer(empl **tete, int identifiant)
{
    empl * temp1 = *tete;
    empl * temp2 = *tete; 
    while(temp1!=NULL){    
        if(temp1->identifiant==identifiant){
            if(temp1==temp2){
                /* this condition will run if
                the record that we need to delete is the first node
                of the linked list */
                *tete = (*tete)->suiv;
                free(temp1);
            }
            else{
                /* temp1 is the node we need to delete
                 temp2 is the node previous to temp1 */
                temp2->suiv = temp1->suiv;
                free(temp1); 
            } 
            
        }
        temp2 = temp1;
        temp1 = temp1->suiv;       
    } 
    
}

void afficher(empl *tete)
{
    empl * temp = tete;
    
    if(temp == NULL){
        printf("\nLA LISTE EST VIDE\n");
    	return;
	}
	
    while(temp!=NULL){
        
        printf("ID: %d\n", temp->identifiant);
        printf("nom_emp: %s\n", temp->nom_emp);
        printf("prenom_emp: %s\n", temp->prenom_emp);
        printf("situation familiale: %s\n", temp->situation_f);
        printf("Grade: %d\n\n", temp->grade);
        temp = temp->suiv;
        
    }
}

void trier(empl **tete){
    
    empl *temp = NULL;
    empl *p1;
    empl *p2;
    while(*tete!=NULL){
        
        p1 = *tete;
        p2 = *tete;
        while(p1!=NULL){
            if(p1->identifiant > p2->identifiant){
                p2 = p1;
            }
            p1 = p1->suiv;
        }
        inserer(&temp, p2->identifiant, p2->nom_emp, p2->prenom_emp,p2->situation_f, p2->grade);
        supprimer(tete, p2->identifiant);
    }
    *tete = temp; 
}

/*----------------------programme principale -----------------------------------*/
int main()
{
    empl *tete = NULL;
    int choice;
    char nom_emp[100];
    char prenom_emp[100];
    char situation_f[40];
    int identifiant;
    int grade;
    menu:
    printf("   ** menu principale **\n1: inserer employeur\n2: afficher employeurs \n3: supprimer employeur\n4: modifier employeur\n5: rechercher employeur\n6: trier employeurs");
    do
    {
        printf("\nentrer choix: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("\nEntrer ID: ");
                scanf("%d", &identifiant);
                printf("Entrer nom_emp: ");
                scanf("%s", nom_emp);
                printf("Entrer prenom_emp: ");
                scanf("%s", prenom_emp);
                printf("situation familiale: ");
                scanf("%s", situation_f);
                printf("Entrer grade: ");
                scanf("%d", &grade);
                inserer(&tete,identifiant, nom_emp, prenom_emp, situation_f, grade);
                printf("ajout avec succes!!\n\n");
                goto menu;
                break;
            case 2:
                afficher(tete);
                printf("\n");
                goto menu;
                break;
            case 3:
                printf("Entrer identifiant employeur a supprimer: ");
                scanf("%d", &identifiant);
                supprimer(&tete, identifiant);
                printf("suppression avec succes!!\n\n");
                goto menu;
                break;
            case 4:
                printf("Entrer identifiant employeur a modifier: ");
                scanf("%d", &identifiant);
                modifier(&tete, identifiant);
                printf("modification avec succes!!\n\n");
                goto menu;
                break;
            case 5:
                printf("Entrer identifiant employeur: ");
                scanf("%d", &identifiant);
                rechercher(tete,identifiant);
                printf("\n\n");
                goto menu;
                break;
            case 6:
                trier(&tete);
                printf("la liste est triee!!\n\n");
                goto menu;
                break;
        }
        
    } while (choice != 0);
}
