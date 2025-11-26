#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = nuevo;
    } else {
        nuevo->siguiente = *cabeza;
        (*ultimo)->siguiente = nuevo;
        *cabeza = nuevo;
    }
}

void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacia\n");
        return;
    }

    struct Nodo *temp = cabeza;
    printf("Lista circular: ");

    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != cabeza);

    printf("(vuelve a la cabeza)\n");
}

void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacia\n");
        return;
    }

    struct Nodo *temp = *cabeza;
    struct Nodo *prev = *ultimo;

    do {
        if (temp->dato == valor) {

            if (temp == *cabeza && temp == *ultimo) {
                *cabeza = NULL;
                *ultimo = NULL;
            }
            else if (temp == *cabeza) {
                *cabeza = temp->siguiente;
                (*ultimo)->siguiente = *cabeza;
            }
            else if (temp == *ultimo) {
                *ultimo = prev;
                (*ultimo)->siguiente = *cabeza;
            }
            else {
                prev->siguiente = temp->siguiente;
            }

            free(temp);
            printf("Se elimino %d correctamente.\n", valor);
            return;
        }

        prev = temp;
        temp = temp->siguiente;

    } while (temp != *cabeza);

    printf("Valor no encontrado.\n");
}

int main() {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int opcion, n, valor;

    do {
        printf("LISTA CIRCULAR\n");
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
                    insertarCircular(&cabeza, &ultimo, valor);
                    recorrerCircular(cabeza);
                }
                break;

            case 2:
                recorrerCircular(cabeza);
                break;

            case 3:
                printf("Ingresa el valor a eliminar: ");
                scanf("%d", &valor);
                eliminarCircular(&cabeza, &ultimo, valor);
                recorrerCircular(cabeza);
                break;
        }
    } while (opcion != 0);

    return 0;
}
