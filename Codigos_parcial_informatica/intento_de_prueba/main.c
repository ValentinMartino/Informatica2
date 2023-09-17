#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"

int main()
{
    ptrNodo ptrInicial = NULL;
    int variable;

    do{
        printf("\n1)Ingresar una vaca\n2)Mostrar vacas.\n3)Eliminar una vaca de la lista.\n4)salir.\n---->");

        scanf("%i", &variable);

        getchar(); //para el '\n' que queda en el buffer cuando se elije una opcion/

        switch(variable)
        {
            case 1: insertar_vaca(&ptrInicial);   break;
            case 2: mostrar_vaca(ptrInicial);        break;
            case 3: eliminar_vaca(&ptrInicial);   break;
            case 4: break;
            default: printf("\nEliga uno de los numeros inndicados:\n");
        }

    }while(variable != 4);

    printf("\n");


    return 0;
}
