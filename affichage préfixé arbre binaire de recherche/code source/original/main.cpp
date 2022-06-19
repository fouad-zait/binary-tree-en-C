#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include<time.h>



typedef struct elt
{int info ; struct elt *succ_gauche ; struct elt *succ_droit ;} *noeud ;

void insere(noeud a,int val,noeud pere );
int Vide(noeud a);
void prefixe(noeud a);
int Feuille (noeud a);

using namespace std;
int main()
{

noeud racine;
noeud pere;
int y,n,x;
  do{
       srand( time( NULL ) );
        printf("Donner le nombre de valeurs \n");
        scanf("%d",&n);}
        while(n<0);
        printf("********************CREATION DE L'ARBRE BINAIRE DE RECHERCHE******************** \n");
        printf(" premiere valeur \n");
        x=rand();
        printf("%d\n",x);

racine=(noeud)malloc(sizeof(struct elt));
racine->info=x;
racine->succ_gauche=NULL;
racine->succ_droit=NULL;
for(int i=2;i<=n;i++){
        printf("autre valeur \n");
        y=rand();
        printf("%d \n",y);
        pere=NULL;
        insere(racine,y,pere);
        }
/*affichage préfixé de l'arbre*/
printf("******************** AFFICHAGE PREFIXE DE L'ARBRE BINAIRE DE RECHERCHE ******************** \n");
auto debut=chrono::steady_clock::now();
prefixe(racine);
auto fin=chrono::steady_clock::now();
printf("******************** TEMPS D'EXECUTION EN NANOSECONDES ******************** \n");
cout << "temps d'execution en nanosecondes:"<<chrono::duration_cast<chrono::nanoseconds>(fin-debut).count()<<"ns"<<endl;
return 0;
}
void insere(noeud a,int val,noeud pere ){
noeud p;

    if(Vide(a)==0){
        if(a->info == val){
            printf("La valeur existe deja");
        }
        else{
            pere=a;
            if(a->info > val){
                insere(a->succ_gauche,val,pere);
            }
            else{
                insere(a->succ_droit,val,pere);
  }
        }
    }
    else{
        p=(noeud)malloc(sizeof(struct elt));
        p->info=val;
        p->succ_gauche=NULL;
        p->succ_droit=NULL;
        if(pere->info > val){
            pere->succ_gauche=p;
        }
        else{
           pere->succ_droit=p;

        }
    }


}
int Vide(noeud a){
if (a == NULL) return(1) ;
else return(0);
}
void prefixe(noeud a)
{ if ( Vide(a)== 0)
{ printf(" %d \n", a->info) ;
if ( Feuille(a)==0)
{ prefixe (a->succ_gauche) ;
prefixe (a->succ_droit) ; }
}
}
int Feuille (noeud a)
{ if (a->succ_gauche == NULL && a->succ_droit==NULL)
return(1) ;
else return(0) ; }

