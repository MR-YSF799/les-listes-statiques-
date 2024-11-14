#include <stdio.h>
#include <stdlib.h>
#define Max 40// constante taille max des tableaux
//liste chainee representation statique  (version tableau)
typedef struct
{
    int Ltab[Max];
    int NbE; // nombre d'element de la liste
}Tliste;

// les listes a l'aide de tableau
// 1 creer une liste statique
Tliste* cree_Tliste( )
{
    Tliste* Maliste;
    //allocation de la memoire pour la liste
    Maliste=(Tliste*)malloc(sizeof(Tliste));
    if(!Maliste)//memoire insiffusante
    {
        printf("erreur\n");
        exit(0);
    }
    return ((Tliste*)Maliste);
}
// 2 fonction d'initialisation
int initialiser_TList(Tliste Maliste)
{
    Maliste.NbE=0;
    return ((int)Maliste.NbE);
}
//3 fonction verification liste saturee
int Est_saturee_Tliste(Tliste Maliste)
{
    return Maliste.NbE==Max;//si vrai retourne 1
}
//4 fonction taille liste
int taille_Tliste(Tliste Maliste)
{
    return Maliste.NbE;
}
//5 insertion dans une liste (a la fin)
int inserer_fin_Tliste(Tliste *Maliste,int valeur)
{
    if(!Maliste) return ((int)-1);//liste n'existe pas
    if(Est_saturee_Tliste(*Maliste)) return((int)0);//liste plein
    Maliste->Ltab[Maliste->NbE++]=valeur;//insertion avec NbE+1
    return((int)1);
}
// 6 insertion dans une position donnee
int inserer_pos_tlise(Tliste *l,int val,int pos){
    int i; // pour parcourir la liste
    if(!l) return ((int)-1); // la liste n existe pas
    if(Est_saturee_Tliste(*l)) return -2; // la liste est plein
    if(pos<0 && pos>l->NbE) return 0; // position invalide
    else{
            for( i=l->NbE-1;i>=pos;i--){
                    l->Ltab[i+1]=l->Ltab[i];
            }
        l->Ltab[pos]=val; // insertion dans la position donnee
        l->NbE++; //mise a jour a nombre des elements

return  1;
}
// 7 position dun element
int pos_elem(Tliste *l, int v ){
    int k;
    if(!l) return -1 ;
    for(int i=0;i<=l->NbE;i++){
        if(l->Ltab[i]==v)
            return i; // retourne l indice de l element
    }return -1; // l element n existe pas
    }
// 8 supprime une position ds le tableau 
int supp_pos_tliste(Tliste *l,int pos){
    int i; // pour parcourir la liste
    if(!l) return -1; //la liste n existe pas
    if(pos<0 && pos >Max) return -2; // position invalide
    if(!l->NbE) return 0; // la liste est vide
    for( i=pos;i<l->NbE-1;i++){
            // decalage des elements
    l->Ltab[i]=l->Ltab[i+1];
}
l->NbE--; return 1 ; // mise a jour de nombres d elements
}
// 9 afficher toute la liste
int  afficher (Tliste *l){
    int i ; // pour parcourir la liste
if(!l) return ((int)-1); // la liste n existe pas
if(!l->NbE) return ((int)0);// la liste est vide
else {
    for( i=0;i<l->NbE;i++)
        printf(" tab[%d] = %d \n",i,l->Ltab[i]);
}
return ((int)1) ; // operation effectue
}

int main(){
}

