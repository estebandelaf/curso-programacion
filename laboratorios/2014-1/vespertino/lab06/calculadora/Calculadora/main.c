#include <stdio.h>
#include <stdlib.h>

#define SALIDA -1

float getValor(int indice);
float suma(float a,float b);
float resta(float a, float b);
float multiplicacion(float a, float b);
float division(float a, float b);

int main()
{
    int opcion = 0;
    float numero1;
    float numero2;
    float resultado;
    int operacion = 0;
    printf("Ejemplo de calculadora\n");
    while(opcion != SALIDA){
        numero1 = 0;
        numero2 = 0;
        resultado = 0;
        operacion = 0;
        printf("¿Que desea hacer?\n");
        printf("1)Sumar\n");
        printf("2)Restar\n");
        printf("3)Multiplicar\n");
        printf("4)Dividir\n");
        printf("-1)Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                numero1 = getValor(1);
                numero2 = getValor(2);
                resultado = suma(numero1,numero2);
                operacion = 1;
                break;
            case 2:
                numero1 = getValor(1);
                numero2 = getValor(2);
                resultado = resta(numero1,numero2);
                operacion = 1;
                break;
            case 3:
                numero1 = getValor(1);
                numero2 = getValor(2);
                resultado = multiplicacion(numero1,numero2);
                operacion = 1;
                break;
            case 4:
                numero1 = getValor(1);
                numero2 = getValor(2);
                resultado = division(numero1,numero2);
                operacion = 1;
                break;
            default:
                break;
        }
        if(operacion)
        {
            printf("el resultado es %f\n",resultado);
        }
    }
    return EXIT_SUCCESS;
}

float getValor(int indice){
    float numero;
    printf("ingrese el numero %d\n",indice);
    scanf("%f",&numero);
    return numero;
}

float suma(float a,float b)
{
    return a + b;
}

float resta(float a, float b)
{
    return a - b;
}

float multiplicacion(float a, float b)
{
    return a * b;
}

float division(float a, float b)
{
    if(b == 0){
        return 0;
    }
    return a/b;
}
