#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*inicio == NULL) {
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        *inicio = nuevo;
        return;
    }

    struct Nodo *ultimo = (*inicio)->anterior;

    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;
    ultimo->siguiente = nuevo;
    (*inicio)->anterior = nuevo;
}

void recorrerCircular(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    struct Nodo *temp = inicio;
    printf("Recorrido circular:\n");

    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != inicio);

    printf("(vuelve al inicio)\n");
}

void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL)
        return;

    struct Nodo *temp = *inicio;
    struct Nodo *anteriorNodo;
    
    do {
        if (temp->dato == valor) break;
        temp = temp->siguiente;
    } while (temp != *inicio);

    if (temp->dato != valor) {
        printf("Valor no encontrado.\n");
        return;
    }

    if (temp->siguiente == temp) {
        free(temp);
        *inicio = NULL;
        return;
    }

    anteriorNodo = temp->anterior;
    anteriorNodo->siguiente = temp->siguiente;
    temp->siguiente->anterior = anteriorNodo;

    if (temp == *inicio)
        *inicio = temp->siguiente;

    free(temp);
    printf("Nodo eliminado correctamente.\n");
}

void liberarCircular(struct Nodo *inicio) {
    if (inicio == NULL) return;

    struct Nodo *temp = inicio->siguiente;
    
    while (temp != inicio) {
        struct Nodo *aux = temp;
        temp = temp->siguiente;
        free(aux);
    }

    free(inicio);
    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar en lista circular? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
        recorrerCircular(inicio);
    }

    printf("Valor a eliminar: ");
    scanf("%d", &eliminarValor);

    eliminarCircular(&inicio, eliminarValor);
    recorrerCircular(inicio);

    liberarCircular(inicio);

    return 0;
}
