#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    if (*inicio != NULL)
        (*inicio)->anterior = nuevo;

    *inicio = nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;

    if (*inicio == NULL) {
        *inicio = nuevo;
        return;
    }

    struct Nodo *temp = *inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    temp->siguiente = nuevo;
    nuevo->anterior = temp;
}

void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *temp = inicio;
    printf("Recorrido hacia adelante:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        if (temp->siguiente == NULL) break;
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void recorrerAtras(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    struct Nodo *temp = inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    printf("Recorrido hacia atrás:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->anterior;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *temp = *inicio;

    while (temp != NULL && temp->dato != valor)
        temp = temp->siguiente;

    if (temp == NULL) {
        printf("Valor no encontrado.\n");
        return;
    }

    if (temp->anterior == NULL) { 
        *inicio = temp->siguiente;
        if (*inicio != NULL)
            (*inicio)->anterior = NULL;
    }
    else if (temp->siguiente == NULL) {
        temp->anterior->siguiente = NULL;
    }
    else {
        temp->anterior->siguiente = temp->siguiente;
        temp->siguiente->anterior = temp->anterior;
    }

    free(temp);
    printf("Nodo eliminado correctamente.\n");
}

void liberar(struct Nodo *inicio) {
    struct Nodo *temp;

    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }

    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar al inicio? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("¿Cuántos valores deseas insertar al final? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("Valor a eliminar: ");
    scanf("%d", &eliminarValor);
    eliminar(&inicio, eliminarValor);

    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    liberar(inicio);
    return 0;
}
