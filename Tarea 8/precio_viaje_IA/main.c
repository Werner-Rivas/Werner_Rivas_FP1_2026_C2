#include <stdio.h>

int main() {
    int unidad;
    float consumo_ciudad, consumo_carretera;
    float km_ciudad, km_carretera;
    float precio_combustible;
    float combustible_necesario, costo_viaje_idayvuelta, costo_servicio, costo_total;
    float km_total_idayvuelta, costo_por_km;

    do {
        printf("Seleccione la unidad de medida:\n");
        printf("1. Litros\n");
        printf("2. Galones\n");
        printf("Opcion: ");
        scanf("%d", &unidad);

        if (unidad != 1 && unidad != 2) {
            printf("\nOpcion invalida. Debe elegir 1 (Litros) o 2 (Galones).\n\n");
        }
    } while (unidad != 1 && unidad != 2);

    if (unidad == 1) {
        printf("\nIngrese el consumo en ciudad (km/litro): ");
        scanf("%f", &consumo_ciudad);
        printf("Ingrese el consumo en carretera (km/litro): ");
        scanf("%f", &consumo_carretera);
    } else {
        printf("\nIngrese el consumo en ciudad (km/galon): ");
        scanf("%f", &consumo_ciudad);
        printf("Ingrese el consumo en carretera (km/galon): ");
        scanf("%f", &consumo_carretera);
    }

    printf("\nIngrese la cantidad de km en ciudad (km): ");
    scanf("%f", &km_ciudad);
    printf("Ingrese la cantidad de km en carretera (km): ");
    scanf("%f", &km_carretera);

    printf("\nIngrese el precio del combustible por ");
    if (unidad == 1) {
        printf("litro (pesos/litro): ");
    } else {
        printf("galon (pesos/galon): ");
    }
    scanf("%f", &precio_combustible);

    combustible_necesario = (km_ciudad / consumo_ciudad) + (km_carretera / consumo_carretera);

    costo_viaje_idayvuelta = combustible_necesario * precio_combustible * 2;

    printf("\nIngrese el costo del servicio (pesos): ");
    scanf("%f", &costo_servicio);

    costo_total = costo_viaje_idayvuelta + costo_servicio;

    km_total_idayvuelta = (km_ciudad + km_carretera) * 2;
    costo_por_km = costo_total / km_total_idayvuelta;

    printf("\n==============================\n");
    printf("Distancia total (ida y vuelta): %.2f km\n", km_total_idayvuelta);
    printf("Costo por km: %.2f pesos/km\n", costo_por_km);
    printf("------------------------------\n");
    printf("Costo del viaje (ida y vuelta): %.2f pesos\n", costo_viaje_idayvuelta);
    printf("Costo del servicio: %.2f pesos\n", costo_servicio);
    printf("COSTO TOTAL: %.2f pesos\n", costo_total);
    printf("==============================\n");

    return 0;
}
