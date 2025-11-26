#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *arr = NULL;   
    int *arr2 = NULL;  
    int i;

    int inicio = 0;    
    int fin = 0;      
    int opcion;
    int valor;

    printf("lista_circular\n\n");

    
    printf(" Reserva con malloc\n");
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

    printf("\n Reserva con calloc\n");
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

    printf("\nLlenar arr2 con n valores (modo circular)\n");
    inicio = 0;
    fin = 0;

    for (i = 0; i < n; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%d", &valor);

          arr2[fin] = valor;
        fin = (fin + 1) % n;   
    }

    printf("\nContenido de la lista circular arr2 (tamanio n = %d):\n", n);
    int indice = inicio;
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", indice, arr2[indice]);
        indice = (indice + 1) % n;
    }

    printf("\n Redimensionar arr2 con realloc\n");
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
        printf("Como la lista es circular, agregaremos elementos al final logico.\n");

        
        fin = n % m;

        for (i = n; i < m; i++) {
            printf("Valor extra para arr2[%d]: ", fin);
            scanf("%d", &valor);
            arr2[fin] = valor;
            fin = (fin + 1) % m;
        }

    } else if (m < n) {
        printf("\nEl nuevo tamaño es menor (%d < %d).\n", m, n);
        printf("Los elementos que queden fuera del nuevo tamaño se pierden.\n");

            inicio = inicio % m;
        fin = (inicio + m) % m;

    } else {
        printf("\nEl tamaño nuevo es igual al anterior (%d).\n", m);
    }

    printf("\nValores finales de la lista circular arr2 (tamanio m = %d):\n", m);
    indice = inicio;
    for (i = 0; i < m; i++) {
        printf("arr2[%d] = %d\n", indice, arr2[indice]);
        indice = (indice + 1) % m;
    }

    free(arr);
    free(arr2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
