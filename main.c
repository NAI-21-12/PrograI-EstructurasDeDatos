#include <stdio.h>
#include <stdlib.h>

struct país{
    struct país* sigt;
    char* nombre;
    char* problema1;
    char* problema2;
    struct país* ant;
};

struct lista{
    struct país* inicio;
    struct país* final;
};

struct país* crearPaís(char* nombre, char* problema1, char* problema2){
    struct país* nuevoPaís = calloc(1,sizeof(struct país));
    if (nuevoPaís != NULL){
        nuevoPaís->nombre = nombre;
        nuevoPaís->problema1 = problema1;
        nuevoPaís->problema2 = problema2;
        nuevoPaís->sigt = NULL;
        nuevoPaís->ant = NULL;
    }
    return nuevoPaís;
};

int imprimirPaíses(struct lista* lista){
    struct país* actual = lista->inicio;
    while (actual != NULL){
        printf("País: %s, Problema 1: %s, Problema2: %s\n",actual->nombre,actual->problema1,actual->problema2);
        actual = actual->sigt;
    }
    return 0;
}


int insertarFinal(struct lista* lista, char* nombre, char* problema1, char* problema2){
    struct país* nuevoPaís = crearPaís(nombre,problema1,problema2);
    struct país* actual = lista-> inicio;

    if (lista->inicio == NULL){
        lista->inicio = nuevoPaís;
        lista->final = nuevoPaís;
        return 0;
    }

    lista->final->sigt = nuevoPaís;
    nuevoPaís->ant = lista->final;
    lista->final = nuevoPaís;
    
    return 0;
}


//Función main que corre el programa
int main(){
    struct lista países = {NULL,NULL};
    insertarFinal(&países,"Costa Rica","Corrupción","Muerte");
    imprimirPaíses(&países);
    return 0;
}
