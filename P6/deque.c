#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;

void inicializarDeque(Deque *d) {
    d->front = 0;
    d->size = 0;
    printf("Deque inicializado.\n");
}

    int isEmptyDeque(Deque *d) {
    return d->size == 0;
}

int isFullDeque(Deque *d) {
    return d->size == MAX;
}

    int getRearIndex(Deque *d) {
    if (isEmptyDeque(d)) return -1;
    return (d->front + d->size - 1) % MAX;
}

void printDeque(Deque *d) {
    int i, idx;

    printf("\n--- Estado del deque ---\n");
     printf("front = %d, size = %d", d->front, d->size);
    if (!isEmptyDeque(d)) {
        printf(", rear = %d", getRearIndex(d));
    }
    printf("\n");

    if (isEmptyDeque(d)) {
        printf("[Deque vacio]\n");
        printf("------------------------\n\n");
        return;
    }

    printf("Contenido (de front a rear): ");
    idx = d->front;
      for (i = 0; i < d->size; i++) {
        printf("%d ", d->datos[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
    printf("------------------------\n\n");
}

int insert_front(Deque *d, int valor) {
    if (isFullDeque(d)) {
            printf("No se puede insertar %d al frente: deque lleno.\n", valor);
        return 0;
    }
    d->front = (d->front - 1 + MAX) % MAX;
    d->datos[d->front] = valor;
      d->size++;
    printf("insert_front(%d)\n", valor);
    printDeque(d);
      return 1;
}

int insert_rear(Deque *d, int valor) {
     int rear;
    if (isFullDeque(d)) {
        printf("No se puede insertar %d al final: deque lleno.\n", valor);
        return 0;
    }
    if (isEmptyDeque(d)) {
        d->datos[d->front] = valor;
    } else {
        rear = getRearIndex(d);
        rear = (rear + 1) % MAX;
          d->datos[rear] = valor;
    }
    d->size++;
         printf("insert_rear(%d)\n", valor);
    printDeque(d);
    return 1;
}

int delete_front(Deque *d) {
    int valor;
    if (isEmptyDeque(d)) {
        printf("No se puede borrar del frente: deque vacio.\n");
             return -1;
    }
    valor = d->datos[d->front];
    d->front = (d->front + 1) % MAX;
    d->size--;
    printf("delete_front() -> %d\n", valor);
    printDeque(d);
    return valor;
}

int  delete_rear(Deque *d) {
    int valor, rear;
           if (isEmptyDeque(d)) {
        printf("No se puede borrar del final: deque vacio.\n");
        return -1;
    }
    rear = getRearIndex(d);
    valor = d->datos[rear];
    d->size--;
    printf("delete_rear() -> %d\n", valor);
    printDeque(d);
         return valor;
}

int peek_front(Deque *d) {
    if (isEmptyDeque(d)) {
        printf("No hay frente: deque vacio.\n");
        return -1;
    }
    printf("peek_front() -> %d\n", d->datos[d->front]);
         return d->datos[d->front];
}

int peek_rear(Deque *d) {
    int rear;
    if (isEmptyDeque(d)) {
            printf("No hay final: deque vacio.\n");
        return -1;
    }
    rear = getRearIndex(d);
    printf("peek_rear() -> %d\n", d->datos[rear]);
    return d->datos[rear];
}

int main() {
     Deque d;
    
    printf("=== PRACTICA 6: DEQUE (COLA DOBLE) ===\n\n");
    inicializarDeque(&d);

    
    insert_front(&d, 10);

    insert_rear(&d, 15);
    insert_rear(&d, 20);

    insert_front(&d, 30);

    insert_rear(&d, 40);

    delete_front(&d);
    delete_rear(&d);

    insert_front(&d, 50);
    insert_rear(&d, 60);

    peek_front(&d);
    peek_rear(&d);

    return 0;
}
