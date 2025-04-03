#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char id [5][10];
    char nombre[5][30];
    int stock[5];
    float precio[5];
    int cont=0, opc1;
    float total_ganancias = 0, venta = 0;
    
    do{
        printf("seleccione una opción:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Ver detalles de producto\n");
        printf("5. Ver total de ganancias\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d", &opc1);
        switch (opc1)
        {
        case 1:
            if (cont<5){
                printf("Ingrese el ID del producto %d:\n", cont);
                scanf("%s", &id[cont]);
                printf("Ingrese el nombre del producto %d:\n", cont);
                fflush(stdin);
                fgets(nombre[cont], 30, stdin);
                printf("Ingrese el stock del producto %d:\n", cont);
                scanf("%d", &stock[cont]);
                printf("Ingrese el precio del producto %d:\n", cont);
                scanf("%f", &precio[cont]);
                cont++;
            }else{
                printf("No se puede ingresar más productos..\n");
            }
            break;
        case 2:
            int aux, cantidad;
            printf("Seleccione el número de producto a vender: \n");
            printf("#\t\tID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < 5; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n", i, id[i], nombre[i], stock[i], precio[i]);
            }
            printf(">> ");
            scanf("%d", &aux);
            printf("Ingrese la cantidad de producto con ID:%s a vender: ", id[aux]);
            scanf("%d", &cantidad);
            if(cantidad<=stock[aux])
            {
                venta = cantidad*precio[aux];
                printf("El valor de la venta es: %f\n", venta);
                stock[aux] -= cantidad;
                if(cantidad>20)
                {
                    venta*=0.9;
                    printf("Se aplica un descuento del 10 por ciento por venta superior a 20 unidades \n");
                    printf("El valor de la venta con descuento es: %.2f \n", venta);
                }
                total_ganancias+=venta;
            }
            break;
        
        default:
            break;
        }

    }while(opc1!=6);

    return 0;
}
