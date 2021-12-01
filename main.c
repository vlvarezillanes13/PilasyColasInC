#include <stdio.h>
#include "stdlib.h"
#include "string.h"
struct nodo{
    char rut[20];
    struct nodo * enlace;
};
int ejemploNodos(){
    struct nodo * rutsDeLosCabros, * inicioRuts, * finRuts;
    int cantidadCabros;
    char rutdv[20];

    printf("\nIngresa la cantidad de cabros a registrar RUTs: ");
    scanf("%i", &cantidadCabros);


    //enlazamos cada nodo
    for (int i = 0; i < cantidadCabros; ++i) {

        printf("\nIngresa el rut:");
        scanf("%s", rutdv);
        //scanf("%c", rutsDeLosCabros->digitoVerificador);

        rutsDeLosCabros = malloc(sizeof(struct nodo));              //creamos nuevo nodo para agregar a la lista
        if (rutsDeLosCabros == NULL) {                              //si da NULL es por que no hay memoria disponible
            printf("ERROR EN ASIGNAR MEMORIA!!");
            return -1;
        }
        strcpy(rutsDeLosCabros->rut, rutdv);
        rutsDeLosCabros->enlace = NULL;

        if(i==0) {
            inicioRuts = rutsDeLosCabros;                      //enlace de nodo inicial, inicio y término quedan al inicio.
            finRuts = inicioRuts;
        }else{
            finRuts->enlace = rutsDeLosCabros;                  //el último nodo apuntará al nuevo nodo creado
            finRuts = rutsDeLosCabros;                          //movemos el nodo final al término de la fila.
        }

    }
    //mostrando los nodos
    rutsDeLosCabros = inicioRuts;
    while(rutsDeLosCabros!= NULL){
        if (strcmp(rutsDeLosCabros->rut,"rutingresado")==0)
            //aca se actualizan los campos de esa estructura
            printf("\nrut %s",rutsDeLosCabros->rut );
        printf("\nsiguiente Nodo: %x", rutsDeLosCabros->enlace);
        rutsDeLosCabros = rutsDeLosCabros->enlace;
    }
    //liberando memoria de los nodos
    rutsDeLosCabros = inicioRuts;
    while(rutsDeLosCabros!= NULL){
        inicioRuts = rutsDeLosCabros->enlace;
        printf("\nrut %s LIBERADO!",rutsDeLosCabros->rut );
        free(rutsDeLosCabros);
        rutsDeLosCabros = inicioRuts;
    }

}


struct nodo * encolar(struct nodo * finCola){
    /*
     * Función que recibe el final de una cola, y agrega un nodo nuevo en ella
     * Devuelve el último nodo creado
     */
    struct nodo * nuevo_nodo;
    nuevo_nodo = malloc(sizeof(struct nodo));
    if (nuevo_nodo ==NULL){
        printf("\n ERROR EN ASIGNAR MEMORIA, SALIENDO DEL PROGRAMA");
        return NULL;
    }
    printf("\ninsertando un nodo (ENCOLAR)");
    printf("\nIngresa el RUT: ");
    scanf("%s", nuevo_nodo->rut );
    nuevo_nodo->enlace = NULL;

    if (finCola == NULL) //Quiere decir que no existen nodos
        finCola = nuevo_nodo;
    else{
        nuevo_nodo->enlace = finCola;
        finCola = nuevo_nodo;
    }
    return finCola;
}
struct nodo * desencolar(struct nodo * finCola, struct nodo * inicioCola){
    struct nodo * nuevoInicio;

    if(inicioCola == NULL){//no hay nodos
        printf("\nNo existen nodos por procesar.");
        return NULL;
    }else if(inicioCola == finCola){ //ese el único y último nodo
        printf("\nEliminando el último nodo (DESENCOLAR)");
        printf("\nRUT: %s", inicioCola->rut );
        printf("\nEnlace: %x", inicioCola->enlace);
        free(inicioCola);
        return NULL;
    } else{//hay mas de un nodo
        //buscamos el nodo anterior al inicio
        nuevoInicio = finCola; //recorremos del final hasta llegar al nodo anterior al inicio
        while (nuevoInicio->enlace != inicioCola)
            nuevoInicio = nuevoInicio->enlace; //avanzamos un nodo
        printf("\nEliminando un nodo (DESENCOLAR)");
        printf("\nRUT: %s", inicioCola->rut );
        printf("\nEnlace: %x", inicioCola->enlace);

        free(inicioCola); //LIBERAMOS EL INICIO DE LA COLA ( SE ATIENDE A LA PERSONA y se va)
        nuevoInicio->enlace = NULL; //el enlace de nuevo inicio debe apuntar a null ahora
        printf("\nNUEVO INICIO AHORA ES:");
        printf("\nRUT: %s", nuevoInicio->rut );
        printf("\nEnlace: %x", nuevoInicio->enlace);



        return nuevoInicio;
    }

}
int mostrarCola(struct nodo * inicioCola){
    struct nodo * ptr_recorre = inicioCola;
    if (ptr_recorre == NULL){
        printf("\nNo existen datos en la COLA!");
        return 0;
    }
    else{
        printf("\n\tMOSTRANDO LOS DATOS DE LA COLA");
        while (ptr_recorre != NULL){
            if (inicioCola == ptr_recorre)
                printf("\nFIN!");

            printf("\nRUT: %s", ptr_recorre->rut);
            printf("\nENLACE: %X", ptr_recorre->enlace);

            if (ptr_recorre->enlace == NULL)
                printf("\nINICIO!");
            ptr_recorre = ptr_recorre->enlace;
        }
    }
}

struct nodo * pop( struct nodo * finPila){
    struct nodo * nodo_eliminar = finPila;
    if (finPila == NULL){//no existen nodos por eliminar
        printf("\nNo existen nodos por eliminar!");
        return NULL;
    } else if(finPila->enlace == NULL){//es el último nodo
        printf("\nEliminando el último nodo (PUSH)");
        printf("\nRUT: %s", nodo_eliminar->rut );
        printf("\nEnlace: %x", nodo_eliminar->enlace);
        free(nodo_eliminar);
        return NULL;
    }else{
        printf("\nEliminando un nodo (PUSH)");
        printf("\nRUT: %s", nodo_eliminar->rut );
        printf("\nEnlace: %x", nodo_eliminar->enlace);

        finPila = finPila->enlace;                      //avanzamoe el final de la pila al siguiente nodo. (y eliminamos el anterior)
        free(nodo_eliminar);
        return finPila;
    }
}
struct nodo * push( struct nodo * finPila){
    struct nodo * ptr_nuevoNodo;
    ptr_nuevoNodo = malloc(sizeof(struct nodo));
    if (ptr_nuevoNodo ==NULL){
        printf("\n ERROR EN ASIGNAR MEMORIA, SALIENDO DEL PROGRAMA");
        return NULL;
    }
    printf("\ninsertando un nodo (PUSH)");
    printf("\nIngresa el RUT: ");
    scanf("%s", ptr_nuevoNodo->rut );
    ptr_nuevoNodo->enlace = NULL;

    if (finPila == NULL) //Quiere decir que no existen nodos, por lo tanto, el nuevo nodo, será el fin y también el inicio de la pila!
        finPila = ptr_nuevoNodo;
    else{
        ptr_nuevoNodo->enlace = finPila;
        finPila = ptr_nuevoNodo;
    }
    return finPila;
}

int mostrarPila(struct nodo * finPila){
    struct nodo * ptr_recorre = finPila;
    if (ptr_recorre == NULL){
        printf("\nNo existen datos en la PILA!");
        return 0;
    }
    else{
        printf("\n\tMOSTRANDO LOS DATOS DE LA PILA");
        while (ptr_recorre != NULL){
            if (finPila == ptr_recorre)
                printf("\nFIN!");

            printf("\nRUT: %s", ptr_recorre->rut);
            printf("\nENLACE: %X", ptr_recorre->enlace);

            if (ptr_recorre->enlace == NULL)
                printf("\nINICIO!");
            ptr_recorre = ptr_recorre->enlace;
        }
    }
}

int menuPilas(){
    int opcion;
    system("clear");
    printf("\n\t\tBIENVENIDOS AL MENÚ de PILAS!!");
    printf("\n\t1) para ingresar (PUSH)");
    printf("\n\t2) para Eliminar (POP)");
    printf("\n\t3) para listar la pila completa");
    printf("\n\t4) para volver al menú principal");
    printf("\n\tIngresa tu opción: ");
    scanf("%d", &opcion);
    return opcion;
}
int menuColas(){
    int opcion;
    system("clear");
    printf("\n\t\tBIENVENIDOS AL MENÚ de COLAS!");
    printf("\n\t1) para ingresar (ENCOLAR)");
    printf("\n\t2) para Eliminar (DESENCOLAR)");
    printf("\n\t3) para listar todo");
    printf("\n\t4) para volver al menú principal");
    printf("\n\tIngresa tu opción: ");
    scanf("%d", &opcion);
    return opcion;
}
int menuPrincipal(){
    int opcion;
    system("clear");
    printf("\n\t\tBIENVENIDOS AL MENÚ PRINCIPAL!");
    printf("\n\t1) para ingresar al menú de COLAS");
    printf("\n\t2) para ingresar al menú de PILAS");
    printf("\n\t3) para salir del programa");
    printf("\n\tIngresa tu opción: ");
    scanf("%d", &opcion);
    return opcion;
}
int main() {
    int op_menu1, op_menu2;
    struct nodo * inicioCola, *finCola;
    struct nodo * inicioPila, *finPila;
    //inicializamos los punteros en NULL para determinar que no existen nodos en las pilas/colas
    inicioPila = NULL;
    finPila = NULL;
    inicioCola = NULL;
    finCola = NULL;
    do{
        op_menu1 = menuPrincipal();
        switch (op_menu1) {
            case 1:
                //menú de colas
                printf("\n ingresamos al menú COLAS");
                do {

                    op_menu2 = menuColas();
                    switch (op_menu2) {
                        case 1://encolar
                            if (inicioCola == NULL) {
                                inicioCola = encolar(finCola);
                                finCola = inicioCola;
                            }else
                                finCola = encolar(finCola);
                            break;
                        case 2://desencolar
                            inicioCola = desencolar(finCola, inicioCola);
                            break;
                        case 3://listar toda la cola
                            mostrarCola(finCola);
                            break;
                        case 4://salir
                            printf("\n SALIENDO DEL menú COLAS!");
                            break;
                        default:
                            printf("Opción inválida, intenta nuevamente.");

                    }
                } while (op_menu2!=4);
                getchar();
                break;
            case 2:
                //menú pilas
                printf("\n ingresamos al menú PILAS");
                do {

                    op_menu2 = menuPilas();
                    switch (op_menu2) {
                        case 1://PUSH
                            if (inicioPila == NULL) {
                                inicioPila = push(finPila);
                                finPila = inicioPila;
                            }else
                                finPila = push(finPila);
                            break;
                        case 2://POP
                            finPila = pop(finPila);
                            break;
                        case 3://listar toda la cola
                            mostrarPila(finPila);
                            break;
                        case 4://salir
                            printf("\n SALIENDO DEL menú PILAS!");
                            break;
                        default:
                            printf("Opción inválida, intenta nuevamente.");

                    }
                } while (op_menu2!=4);
                break;
            case 3:
                //salir del programa
                printf("\n SALIENDO DEL PROGRAMA!");
                break;
            default:
                printf("Opción inválida, intenta nuevamente.");

        }
    }while (op_menu1!=3);
    return 0;
}