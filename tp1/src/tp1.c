/*
 ============================================================================

Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:

1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir

• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.

• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)

• Deberán contemplarse los casos de error (división por cero, etc)

• Documentar todas las funciones
 ============================================================================
 */







<
#include <stdio.h>
#include <stdlib.h>

#include "Operaciones.h"

int main(void)
{
	int opcion;
	float primernumero;
	float segundonumero;
	float Resultadosuma;
	float Resultadoresta;
	float ResultadoMultiplicacion;
	float Resultadodivision;
	float Resultadoprimerfactorial;
	float Resultadosegundofactorial;
	int Flagprimernumero;
	int Flagsegundonumero;
	int controlador;

	Flagprimernumero=1;
	Flagsegundonumero=1;
	controlador=0;

	setbuf(stdout, NULL);
	do
	{
		if(Flagprimernumero==1)
		{
		  printf("\n1. Ingresar primer operando (A=x)\n");
		}else
		{
			printf("\n1. Ingresar primer operando (A=%.2f)\n", primernumero);
		}

		if(Flagsegundonumero==1)
		{
			printf("2. Ingresar segundo operando (B=y)\n");
		}else
		{
			printf("2. Ingresar segundo operando (B=%.2f)\n", segundonumero);
		}
		printf("3. Calcular todas las operaciones \n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		printf("> : ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				printf("Ingrese el primer operando: ");
				scanf("%f",&primernumero);
				Flagprimernumero=0;
				break;
			case 2:
				if(Flagprimernumero==1)
				{
					printf("Debe ingresar el primer operando para continuar...\n");
				}else
				{
					printf("Ingrese el segundo operando: ");
					scanf("%f",&segundonumero);
					Flagsegundonumero=0;
				}
				break;
			case 3:

				if(Flagprimernumero==1 || Flagsegundonumero==1)
				{
					printf("No hay operandos ingresados...\n");
				}else
				{
					Resultadosuma = AddOperation(primernumero, segundonumero);
					Resultadoresta = SubstractOperation(primernumero, segundonumero);
					ResultadoMultiplicacion = MultiplyOperation(primernumero, segundonumero);
					if(segundonumero != 0)
					{
						Resultadodivision = DivideOperation(primernumero, segundonumero);
					}
					Resultadoprimerfactorial = FactorialOperation(primernumero);
					Resultadosegundofactorial = FactorialOperation(segundonumero);
					controlador++;
				}
				break;
			case 4:
				if(controlador==0)
				{
					printf("Primero debe calcular las operaciones...\n");
				}else
				{
					printf("El resultado de A+B es: %.2f\n",Resultadosuma);
					printf("El resultado de A-B es: %.2f\n",Resultadoresta);
					printf("El resultado de A*B es: %.2f\n",ResultadoMultiplicacion);
					if(segundonumero!=0)
					{
						printf("El resultado de A/B es: %.2f\n",Resultadodivision);
					}else
					{
						printf("No es posible dividir por cero\n");
					}

					printf("El factorial de A es: %.0f y El factorial de B es: %.0f\n", Resultadoprimerfactorial, Resultadosegundofactorial);

					Flagprimernumero=1;
					Flagsegundonumero=1;
				}
				break;
			case 5:
				break;
			default:
				printf("Esa no es una opcion...");
				break;
		}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}
