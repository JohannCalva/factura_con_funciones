#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

    char nombre[20];
    char cedula[10];
    char fecha[14];
    char ciudad[20];
    char telefono[10];

    int opcion_menu;
    int opcion_producto;

    printf("Nombre: ");
    fgets(nombre, sizeof(nombre), stdin);
    printf("Numero de cedula: ");
    do{
        scanf("%s", cedula);
        if(validarCedula(cedula)==0){
            printf("Su numero de cedula no es valido. Ingrese de nuevo: ");
        }else{
            printf("Numero de cedula valido.\n");
        }
    }while(validarCedula(cedula)==0);
    printf("Fecha: ");
    scanf("%s", fecha);
    printf("Ciudad: ");
    scanf("%s", ciudad);
    printf("Numero de telefono: ");
    scanf("%s", telefono);
    
    int p_llantas = 150;
    int p_frenos = 55;
    int p_embrague = 180;
    int p_faros = 70;
    int p_radiador = 120;

    int llantas = 0;
    int frenos = 0;
    int embrague = 0;
    int faros = 0;
    int radiadores = 0;
    
    do{
        printf("__________________MENU__________________\n");
        printf("1. Facturar productos.\n");
        printf("2. Imprimir factura.\n");
        printf("3. Salir.\n");
        printf("Seleccione la opcion que desea realizar: ");
        scanf("%d", &opcion_menu);
        
        switch(opcion_menu){
            
            case 1:
                
                do{
                    printf("\nSeleccione el producto que desea comprar\n");
                    printf("1. Llantas\n");
                    printf("2. Kit Pastillas de freno\n");
                    printf("3. Kit de embrague\n");
                    printf("4. Faro\n");
                    printf("5. Radiador\n");
                    printf("6. Salir del menu e imprimir factura\n");
                    printf("Opcion: ");
                    scanf("%d", &opcion_producto);

                    int cantidad = 0;

                    switch(opcion_producto){
                        case 1:
                            printf("Cantidad de llantas que desea comprar: ");
                            scanf("%d", &cantidad);
                            llantas+=cantidad;
                            break;
                        case 2:
                            printf("Cantidad de pastillas de freno que desea comprar: ");
                            scanf("%d", &cantidad);
                            frenos+=cantidad;
                            break;
                        case 3:
                            printf("Cantidad de kits de embrague que desea comprar: ");
                            scanf("%d", &cantidad);
                            embrague+=cantidad;
                            break;
                        case 4:
                            printf("Cantidad de faros que desea comprar: ");
                            scanf("%d", &cantidad);
                            faros+=cantidad;
                            break;
                        case 5:
                            printf("Cantidad de radiadores que desea comprar: ");
                            scanf("%d", &cantidad);
                            radiadores+=cantidad;
                            break;
                        case 6:
                            printf("Gracias por su compra.\n");
                            break;
                        default:
                            printf("Incorrecto, vuelva a ingresar\n");
                            break;
                    }

                }while(opcion_producto!=6);
                
                break;
            case 2:
                int t_llantas = llantas*p_llantas;
                int t_frenos = frenos*p_frenos;
                int t_embrague = embrague*p_embrague;
                int t_faros = faros*p_faros;
                int t_radiador = radiadores*p_radiador;

                int subtotal = t_llantas + t_frenos + t_embrague + t_faros + t_radiador;
                int descuento;
                int des_total;
                int iva;
                int total;

                printf("___________________FACTURA__________________\n");
                printf("Nombre y Apellido: %s\n", nombre);
                printf("C.I.: %s\n", cedula);
                printf("Fecha: %s\n", fecha);
                printf("Direccion: %s\n", ciudad);
                printf("Telf.: %s\n", telefono);
                printf("DETALLE\n");
                printf("Cant.\t Cod.\t Detalle\t p/u\t p/t\n");

                if (llantas >= 1) {
                    printf("%d\t LLNT\t Llantas\t $%d\t $%d\n", llantas, p_llantas, t_llantas);
                }
                if (frenos >= 1) {
                    printf("%d\t KFRN\t Kit freno\t $%d\t $%d\n", frenos, p_frenos, t_frenos);
                }
                if (embrague >= 1) {
                    printf("%d\t KEMB\t Kit embrague\t $%d\t $%d\n", embrague, p_embrague, t_embrague);
                }
                if (faros >= 1){
                    printf("%d\t FARO\t Faro\t\t $%d\t $%d\n", faros, p_faros, t_faros);
                }
                if (radiadores >= 1) {
                    printf("%d\t RDDR\t Radiador\t $%d\t $%d\n", radiadores, p_radiador, t_radiador);
                }
                printf("\nSubtotal:\t\t $%d\n", subtotal);
                
                if (subtotal < 501) {
                    if (subtotal < 101) {
                        descuento = 0;
                        printf("Descuento 0:\t\t -$%d\n", descuento);
                    }else{
                        descuento = subtotal * 0.05;
                        printf("Descuento 5:\t\t -$%d\n", descuento);
                    }
                }else{
                    if (subtotal < 1000) {
                        descuento = subtotal * 0.07;
                        printf("Descuento 7:\t\t -$%d\n", descuento);
                    }else{
                        descuento = subtotal * 0.1;
                        printf("Descuento 10:\t\t -$%d\n", descuento);
                    }
                }
                des_total = subtotal - descuento;
                printf("Subtotal con descuento:\t $%d\n", des_total);
                iva = subtotal * 0.12;
                printf("Total iva 12:\t\t +$%d\n", iva);
                total = subtotal - descuento + iva;
                printf("Total: \t\t\t $%d\n", total);
                printf("_____________________________________________\n");
                break;
            case 3:
                printf("Gracias por usar.\n");
                break;
            default:
                printf("Opcion no valida. Ingrese de nuevo.\n");
                break;
        }
    
    }while(opcion_menu != 3);
    
    return 0;
}

int validarCedula(const char* cedula){
    int longitud;
    int caracteres = 0;
    int numeros[10];
    int suma = 0;
    int verificador;

    longitud = strlen(cedula);

    if(longitud != 10){
        return 0;
    }else{
        caracteres = 0;
        for(int i = 0; i < 10; i++){
          if(isdigit(cedula[i])==0){
           caracteres++;
          }
        }
        if (caracteres > 0){
          return 0;
        }
    }

    for(int i = 0; i < 10; i++){
        numeros[i] = cedula[i] - '0';
    }

    for(int i = 0; i < 9; i++){
        if(i % 2 == 0){
            if(numeros[i]*2 > 9){
                suma += (numeros[i]*2) - 9;
            }else{
                suma += (numeros[i]*2);
            }
        }else{
            suma += numeros[i];
        }   
    }

    verificador = suma + numeros[9];

    if(verificador % 10 == 0){
        return 1;
    }else{
        return 0;
    }
}