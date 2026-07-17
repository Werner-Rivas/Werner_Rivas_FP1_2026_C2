#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numapostados[99];
    int cantapostada[99];
    int premio[99];

    int opcion = 0;
    int cantjugadas = 1;
    int numganador;
    int i;

    srand(time(NULL));

    do{
        printf("\n:::::::: LOTERIA ::::::::");
        printf("\n\n1. Jugar Sorteo");
        printf("\n2. Elegir cantidad de jugadas (actualmente %d)", cantjugadas);
        printf("\n3. Salir\n");
        printf("\nSeleccione una opcion: ");

        if(scanf("%d", &opcion) != 1)
        {
            printf("\nError: Por favor, introduce un numero valido.");
            while(getchar() != '\n');
            continue;
        }


        switch(opcion)
        {
            case 1:
                numganador = (rand() % 40) + 1;

                printf("\n:::: REGISTRANDO JUGADAS ::::\n");

                for (i = 0; i < cantjugadas; i++)
                {
                    printf("\nJugada #%d: ", i + 1);

                    do{
                        printf("\nIntroduce un numero (1-40): ");
                        if(scanf("%d", &numapostados[i]) != 1)
                        {
                            printf("\nError: No se permiten letras.");
                            while(getchar() != '\n');
                            numapostados[i] = 0;
                        }
                        else if(numapostados[i] < 1 || numapostados[i] > 40) {
                            printf(" \nError: El numero debe estar entre 1 y 40.");
                        }
                    } while(numapostados[i] < 1 || numapostados[i] > 40);

                    do{
                        printf("\nIntroduce la cantidad a apostar: $");
                        if(scanf("%d", &cantapostada[i]) != 1)
                        {
                            printf("\nError: No se permiten letras. ");
                            while (getchar() != '\n');
                            cantapostada[i] = 0;
                        }
                        else if(cantapostada[i] <= 0)
                        {
                            printf("\nError: La apuesta debe ser mayor a $0.");
                        }
                    }
                    while(cantapostada[i] <= 0);

                    if (numapostados[i] == numganador)
                    {
                        premio[i] = cantapostada[i] * 1000;
                    }
                    else{
                        premio[i] = 0;
                    }
                }

                printf("\n======================================================");
                printf("\n :::::: EL NUMERO GANADOR FUE:  %d  ::::::", numganador);
                printf("\n======================================================");
                printf("\nNo. Jugada\tNum. Apostado\tCantidad Apostada\tCantidad Ganada");
                printf("\n------------------------------------------------------\n");

                for(i = 0; i < cantjugadas; i++)
                {
                    printf("%d\t\t%d\t\t$%d\t\t\t$%d\n",
                           i + 1,
                           numapostados[i],
                           cantapostada[i],
                           premio[i]);
                }
                printf("======================================================\n");
                break;

            case 2:
                do {
                    printf("\nSeleccione la cantidad de Jugadas (1-99): ");
                    if (scanf("%d", &cantjugadas) != 1)
                    {
                        printf("\nError: Introduce un numero valido.\n");
                        while (getchar() != '\n');
                        cantjugadas = 0;
                    }
                    else if (cantjugadas < 1 || cantjugadas > 99) {
                        printf("\nError: La cantidad debe ser entre 1 y 99. ");
                    }
                } while (cantjugadas < 1 || cantjugadas > 99);

                printf("\n Cantidad de jugadas actualizada correctamente.\n");
                break;

            case 3:
                printf("\nSaliendo del programa.");
                break;

            default:
                printf("\nOpción invalida. Seleccione una de las opciones indicadas.\n");
                break;
        }

    } while (opcion != 3);

    return 0;
}
