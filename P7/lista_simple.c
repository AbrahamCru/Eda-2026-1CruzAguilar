#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
}

void recorrer(struct Nodo *cabeza) {
    struct Nodo *temp = cabeza;
    printf("Lista: ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *temp = *cabeza;
    struct Nodo *prev = NULL;

    if (temp != NULL && temp->dato == valor) {
        *cabeza = temp->siguiente;
        free(temp);
        printf("Se eliminó el valor %d (estaba en la cabeza)\n", valor);
        return;
    }

    while (temp != NULL && temp->dato != valor) {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("Valor no encontrado\n");
        return;
    }

    prev->siguiente = temp->siguiente;
    free(temp);
    printf("Valor %d eliminado correctamente\n", valor);
}

void liberar(struct Nodo *cabeza) {
    struct Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    int opcion, n, valor;

    do {
        printf("\nLISTA SIMPLE\n");
        printf("1. Insertar valores\n");
        printf("2. Mostrar lista\n");
        printf("3. Eliminar un valor\n");
        printf("0. Salir\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("¿Cuantos valores deseas insertar? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Ingresa valor %d: ", i+1);
                    scanf("%d", &valor);
                    insertarInicio(&cabeza, valor);
                    recorrer(cabeza);
                }
                break;

            case 2:
                recorrer(cabeza);
                break;

            case 3:
                printf("Ingresa el valor a eliminar: ");
                scanf("%d", &valor);
                eliminar(&cabeza, valor);
                recorrer(cabeza);
                break;
        }

    } while (opcion != 0);

    liberar(cabeza);
    return 0;
}

