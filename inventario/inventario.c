#include <stdio.h>
#include <string.h>
#include "lecturas.h"
#include "inventario.h"

void agregarProducto(char nombres[][50], int cantidades[], float precios[], int *contador, int maxProductos) {
    if (*contador >= maxProductos) {
        printf("Inventario lleno. No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingresando un nuevo producto:\n");
    printf("Nombre del producto: ");
    scanf("%s", nombres[*contador]);

    cantidades[*contador] = leerEnteroPositivo("Cantidad del producto: ");
    precios[*contador] = leerFlotantePositivo("Precio del producto: ");
    
    (*contador)++;
    printf("Producto agregado exitosamente.\n");
}

void mostrarProductos(char nombres[][50], int cantidades[], float precios[], int contador) {
    if (contador == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    printf("\nLista de productos:\n");
    for (int i = 0; i < contador; i++) {
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", nombres[i]);
        printf("  Cantidad: %d\n", cantidades[i]);
        printf("  Precio: %.2f\n", precios[i]);
    }
}

void buscarProducto(char nombres[][50], int cantidades[], float precios[], int contador) {
    if (contador == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    char nombreBuscado[50];
    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%s", nombreBuscado);

    for (int i = 0; i < contador; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("Producto encontrado:\n");
            printf("  Nombre: %s\n", nombres[i]);
            printf("  Cantidad: %d\n", cantidades[i]);
            printf("  Precio: %.2f\n", precios[i]);
            return;
        }
    }

    printf("Producto no encontrado.\n");
}

void editarProducto(char nombres[][50], int cantidades[], float precios[], int contador) {
    if (contador == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    char nombreBuscado[50];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombreBuscado);

    for (int i = 0; i < contador; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("Producto encontrado. Ingrese los nuevos datos:\n");
            printf("Nombre del producto: ");
            scanf("%s", nombres[i]);

            cantidades[i] = leerEnteroPositivo("Cantidad del producto: ");
            precios[i] = leerFlotantePositivo("Precio del producto: ");
            printf("Producto editado exitosamente.\n");
            return;
        }
    }

    printf("Producto no encontrado.\n");
}
