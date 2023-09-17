#include<stdio.h>
#include"funciones.h"

int main()
{
    ptrNodo ptrInicial = NULL;
    ptrNodo ptrFinal = NULL;
    int variable;

    do{
        printf("\n1)Ingresar datos en forma ordenada.\n2)Eliminar nodo especifico.\n3)Insertar nodo en el inicio."
               "\n4)Insertar nodo en la cola.\n5)Eliminar el primero.\n6)Eliminar el ultimo.\n7)Borrar todo.\n8)Mostrar lista."
               "\n9)SALIR.\n");

        scanf("%i", &variable);

        switch(variable)
        {
            case 1: ingresar_lista(&ptrInicial);   break;
            case 2: eliminar_nodo(&ptrInicial);   break;
            case 3: ingresa_pila(&ptrInicial); break;
            case 4: ingresar_cola(&ptrInicial, &ptrFinal);   break;
            case 5: eliminar_pila(&ptrInicial); break;
            case 6: eliminar_cola(&ptrInicial, &ptrFinal);   break;
            case 7: eliminar_lista(&ptrInicial);    break;
            case 8: mostrar(ptrInicial);          break;
            case 9: break;
            default: printf("\nEliga uno de los numeros inndicados:\n");
        }

    }while(variable != 9);

    printf("\n");


    return 0;
}
