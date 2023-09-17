//arbol binario

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct ARBOL{

int dato;
struct ARBOL *ptrizq;
struct ARBOL *ptrder;

};

typedef struct ARBOL arbol;
typedef arbol *ptrarbol;

void ingresar(ptrarbol *, int);
void preorden(ptrRaiz);
void enorden(ptrRaiz);
void postorden(ptrRaiz);

int main()
{
int valor;
ptrarbol ptrRaiz = NULL;

srand(time(NULL));

printf("\nLos valores colocados en el arbol son\n");
for(int i=0;i<6;i++)
{
 valor = rand()%20;
 ingresar(&ptrRaiz,valor);
 printf("%3i",valor);
}
printf("\n");

//printf("\nAlgoritmo de arbol binario. Apretar 0 para dejar de ingresar numeros\n\n");

/*do{
printf("\nIngrese el numero que desee:  ");
scanf("%i",&valor);

if(valor!=0)
 ingresar(&ptrRaiz, valor);
 
}while(valor != 0);
*/
printf("\nLos valores ordenados en preorden (raiz;izq;der) son\n");
preorden(ptrRaiz);

printf("\nLos valores ordenados enorden (izq;raiz;der) son\n");
enorden(ptrRaiz);

printf("\nLos valores ordenados en postorden (izq;der;raiz) son\n");
postorden(ptrRaiz);

printf("\n");


return 0;
}

void ingresar(ptrarbol *ptrRaiz, int valor)
{
 if(*ptrRaiz == NULL)//si es el primer nodo
 {
  *ptrRaiz = malloc(sizeof(arbol));
  
   if(*ptrRaiz != NULL)//si hay memoria
    {
     (*ptrRaiz)->dato = valor;
     (*ptrRaiz)->ptrizq = NULL;
     (*ptrRaiz)->ptrder = NULL;
    }
   else
    printf("\nNo se pudo crear el nodo por falta de espacio\n"); 
 }
 
 else
 {
  if((*ptrRaiz)->dato > valor)
   {
    ingresar(&(*ptrRaiz)->ptrizq, valor);
   } 
  
  else 
   if(valor > (*ptrRaiz)->dato)
    {
     ingresar(&(*ptrRaiz)->ptrder, valor);
    }
   else
    printf(" %idup ",valor); 
 }
}

void preorden(ptrarbol ptrRaiz)
{

 if(ptrRaiz != NULL)
 {
  printf(" %i ",ptrRaiz->dato);
  preorden(ptrRaiz->ptrizq);
  preorden(ptrRaiz->ptrder);
 }
}

void enorden(ptrarbol ptrRaiz)
{

 if(ptrRaiz != NULL)
 {
  enorden(ptrRaiz->ptrizq);
  printf(" %i ",ptrRaiz->dato);
  enorden(ptrRaiz->ptrder);
  
 }
}

void postorden(ptrarbol ptrRaiz)
{

 if(ptrRaiz != NULL)
 {
  postorden(ptrRaiz->ptrizq);
  postorden(ptrRaiz->ptrder);
  printf(" %i ",ptrRaiz->dato);
 }
}




























