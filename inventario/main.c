#include <stdio.h>
#include "lecturas.h"
#include "inventario.h"

#define MAX_PRODUCTOS 100

int main() {
    char nombres[MAX_PRODUCTOS][50];
    int cantidades[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int contador = 0;
    char opcion;

    printf("Bienvenido al sistema de inventario del supermercado\n");

    do {
        printf("\nOpciones:\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Mostrar cantidad total de productos\n");
        printf("4. Buscar producto\n");
        printf("5. Editar producto\n");
        printf("6. Salir\n");
        opcion = leerCaracter("Elija una opción: ");

        switch (opcion) {
            case '1':
                agregarProducto(nombres, cantidades, precios, &contador, MAX_PRODUCTOS);
                break;
            case '2':
                mostrarProductos(nombres, cantidades, precios, contador);
                break;
            case '3':
                printf("Total de productos ingresados: %d\n", contador);
                break;
            case '4':
                buscarProducto(nombres, cantidades, precios, contador);
                break;
            case '5':
                editarProducto(nombres, cantidades, precios, contador);
                break;
            case '6':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida, intente nuevamente.\n");
        }
    } while (opcion != '6');

    return 0;
}
