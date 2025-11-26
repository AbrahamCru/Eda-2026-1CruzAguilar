#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *arr = NULL;   
    int *arr2 = NULL;  
    int i;

    printf("=== PRACTICA 4: Almacenamiento en tiempo de ejecucion (lista_simple) ===\n\n");

    printf("Paso 1: Reserva con malloc\n");
    printf("¿Cuantos enteros quieres almacenar? n = ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error: no se pudo reservar memoria con malloc.\n");
        return 1;
    }

    printf("\nValores iniciales de arr (malloc) (basura):\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]); 
    }

    printf("\nPaso 2: Reserva con calloc\n");
    arr2 = (int *)calloc(n, sizeof(int));
    if (arr2 == NULL) {
        printf("Error: no se pudo reservar memoria con calloc.\n");
        free(arr);
        return 1;
    }

    printf("\nValores iniciales de arr2 (calloc) (deben ser 0):\n");
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]); 
    }

    printf("\nPaso 3: Llenar arr2 con n valores\n");
    for (i = 0; i < n; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    printf("\nPaso 4: Redimensionar arr2 con realloc\n");
    printf("Ingresa el nuevo tamaño m: ");
    scanf("%d", &m);

    int *temp = (int *)realloc(arr2, m * sizeof(int));
    if (temp == NULL) {
        printf("Error: no se pudo redimensionar con realloc.\n");
        free(arr);
        free(arr2);
        return 1;
    }
    arr2 = temp;

    if (m > n) {
        printf("\nEl nuevo tamaño es mayor (%d > %d).\n", m, n);
        printf("Ingresa los valores adicionales:\n");
        for (i = n; i < m; i++) {
            printf("Valor para arr2[%d]: ", i);
            scanf("%d", &arr2[i]);
        }
    } else if (m < n) {
        printf("\nEl nuevo tamaño es menor (%d < %d).\n", m, n);
        printf("Los elementos a partir de arr2[%d] se pierden.\n", m);
    } else {
        printf("\nEl tamaño nuevo es igual al anterior (%d).\n", m);
    }

    printf("\nPaso 5: Valores finales de arr2 (tamanio m = %d)\n", m);
    for (i = 0; i < m; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    free(arr);
    free(arr2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
