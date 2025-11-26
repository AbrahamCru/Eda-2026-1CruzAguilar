#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

void inicializarColaCircular(ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada.\n");
}

int isEmpty(ColaCircular *c) {
    return c->size == 0;
}

int isFull(ColaCircular *c) {
    return c->size == MAX;
}

void printQueue(ColaCircular *c) {
    int i, idx;

    printf("\nEstado\n");
    printf("frente = %d, final = %d, size = %d\n", c->frente, c->final, c->size);

    if (isEmpty(c)) {
        printf("[Cola vacia]\n");
        printf(":)\n\n");
        return;
    }

    printf("Contenido: ");
    idx = c->frente;
    for (i = 0; i < c->size; i++) {
        printf("%d ", c->datos[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
    printf("...\n\n");
}

int enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("No se puede encolar %d: la cola esta llena.\n", valor);
        return 0;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->size++;
    printf("Se encolo: %d\n", valor);
    printQueue(c);
    return 1;
}

int dequeue(ColaCircular *c) {
    int valor;
    if (isEmpty(c)) {
        printf("No se puede desencolar: la cola esta vacia.\n");
        return -1;
    }
    valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;
    printf("Se desencolo: %d\n", valor);
    printQueue(c);
    return valor;
}

int peek(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("No hay frente: la cola esta vacia.\n");
        return -1;
    }
    printf("Frente actual: %d\n", c->datos[c->frente]);
    return c->datos[c->frente];
}

int main() {
    ColaCircular cola;

    printf("COLA CIRCULAR\n\n");
    inicializarColaCircular(&cola);


    enqueue(&cola, 5);
    enqueue(&cola, 10);
    enqueue(&cola, 15);

    dequeue(&cola);

    enqueue(&cola, 20);
    enqueue(&cola, 25);
    enqueue(&cola, 30);  
  
    peek(&cola);

    return 0;
}
