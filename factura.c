#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){

    char cedula[10];
    printf("Ingrese su numero de cedula: ");
    do{
        scanf("%s", cedula);
        if(validarCedula(cedula)==0){
            printf("Su numero de cedula no es valido. Ingrese de nuevo: ");
        }else{
            printf("Numero de cedula valido.");
        }
    }while(validarCedula(cedula)==0);
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
        /*printf("El numero de cedula debe tener 10 digitos. Ingrese nuevamente: ");*/
        return 0;
    }else{
        caracteres = 0;
        for(int i = 0; i < 10; i++){
          if(isdigit(cedula[i])==0){
           caracteres++;
          }
        }
        if (caracteres > 0){
          /*printf("El numero de cedula contiene caracteres. Ingrese de nuevo: ");*/
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
        /*printf("%d\n", suma);*/
    }

    verificador = suma + numeros[9];
    /*printf("%d\n", verificador);*/

    if(verificador % 10 == 0){
        /*printf("Su cedula es valida.\n");*/
        return 1;
    }else{
        /*printf("Su cedula no es valida.\n");*/
        return 0;
    }
    printf("Gracias.");

    return 0;
}