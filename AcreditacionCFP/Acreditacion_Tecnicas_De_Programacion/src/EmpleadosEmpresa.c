/*
 * EmpleadosEmpresa.c
 *
 *  Created on: 6 dic. 2022
 *      Author: tanii
 */
#include "EmpleadosEmpresa.h"
#define JUBILACION 60
#define ARRAYEMPLEADOS 20


void Menu(){

	printf("\n");
	printf("1- Cantidad de Empleados Masculinos\n");
	printf("2- Calcular Porcentaje De Empleado Por Genero\n");
	printf("3- Calcular Jubilacion\n");
	printf("4- Calcular Total de Suelos\n");
	printf("5- Mostrar Datos Empleado\n");
	printf("6- Listado De Empleados Ordenado\n");
	printf("7- Sueldo Femenino Mas Alto\n");
	printf("8- Salir\n\n");
}


int PedirCadena(char cadena[], char mensaje[], char mensajeError[])
{
	int retorno=0;
	int largo;
	int bandera=0;
	do{
		if(bandera==1){
			printf(mensajeError);
		}
		else{
			printf(mensaje);
		}
		fflush(stdin);
		gets(cadena);
		largo=strlen(cadena);
		for(int i=0;i<largo;i++){
			if(isdigit(cadena[i])==1&&cadena[i]!=32){
				bandera=1;
				break;
			}
			else{
				bandera=0;
			}
		}
	}while(bandera==1);
	retorno=1;
	return retorno;
}

int PedirNumeroEnRango(char mensaje[], int minimo, int maximo){

	int numeroIngresado;
	do{
		printf(mensaje);
		scanf("%d",&numeroIngresado);
	}while(!(numeroIngresado > minimo && numeroIngresado < maximo));
	return numeroIngresado;
}


int CalcularCantidadEmpleadosMasculinos(Empleado lista[], int len){
	int retorno=0;
	if(lista!=NULL){
		for(int i=0;i<len;i++){
			if(strcmp(lista[i].genero,"Masculino")==0){
				retorno++;
			}
		}
	}
	return retorno;
}

void ImprimirCantidadDeEmpleadosMasculinos(Empleado lista[], int len){
	printf("\nLa Cantidad De Empleados De Genero Masculino Es De: %d\n\n", CalcularCantidadEmpleadosMasculinos(lista, len));
}


float CalcularPorcentajeDeEmpleadosPorGenero(Empleado lista[], int len, char generoBuscar[]){
	int contadorGenero=0;
	float porcentaje;
	if(lista!=NULL){
		for(int i=0;i<len;i++){
			if(strcmp(lista[i].genero, generoBuscar)==0){
				contadorGenero++;
			}
		}
	}
	porcentaje=(contadorGenero*100)/len;
	return porcentaje;
}


void ImprimirPorcentajesEmpleados(Empleado lista[], int len){
	printf("\nPorcentaje De Empleados Por Genero");
	printf("\nPorcentaje Masculino: %.2f", CalcularPorcentajeDeEmpleadosPorGenero(lista, ARRAYEMPLEADOS, "Masculino"));
	printf("\nPorcentaje Femenino: %.2f\n", CalcularPorcentajeDeEmpleadosPorGenero(lista, ARRAYEMPLEADOS, "Femenino"));
}


int CalcularDiferenciaDeAniosJubilatorios(Empleado empleado){
	return JUBILACION-empleado.edad;
}


void MostrarAniosJubilatoriosEmpleados(Empleado lista[], int len){
	if(lista!=NULL){
		printf("\nNOMBRE\t\tAPELLIDO\tCantidad De Años Para Jubilarse\n");
		for(int i=0;i<len;i++){
			printf("\n%-15s %-20s %10d",lista[i].nombre,lista[i].apellido, CalcularDiferenciaDeAniosJubilatorios(lista[i]));
		}
	}
}


float CalcularSueldosEmpleados(Empleado lista[], int len){
	float retorno=0;
	if(lista != NULL){
		for(int i=0;i<len;i++){
			retorno+=lista[i].salario;
		}
	}
	return retorno;
}


void MostrarSueldosTotal(Empleado lista[], int len){
	printf("\n\nLa empresa debe pagar un total de %.2f en concepto de salarios\n",CalcularSueldosEmpleados(lista, len));
}


void MostrarTodosLosEmpleados(Empleado lista[], int len){
	printf("\nNOMBRE\t\tAPELLIDO\n");
	for(int i=0;i<len;i++){
		printf("\n%-15s %-20s",lista[i].nombre,lista[i].apellido);
	}
}


int CalcularJubilacion(Empleado empleado){
	int jubilacion;
	int fechaJubilacion;
	jubilacion=60-empleado.edad;
	fechaJubilacion=jubilacion+2022;
	return fechaJubilacion;
}


void MostrarEmpleadoSeleccionado(Empleado lista[], int len){
	char apellidoIngresado[30];
	PedirCadena(apellidoIngresado, "\n\nIngrese el apellido que desea buscar: ", "\nError, Reintente\n");
	printf("\nNOMBRE\t\tAPELLIDO\tGENERO\t\tANTIGUEDAD\tEDAD\tSALARIO\t\tSE JUBILA EN\n\n");
	for(int i=0;i<len;i++){
		if(strcmp(lista[i].apellido, apellidoIngresado)==0){
			printf("%-14s  %-14s  %-14s  %-14d  %-6d  %-15.2f %d\n",lista[i].nombre,lista[i].apellido, lista[i].genero, lista[i].antiguedad, lista[i].edad, lista[i].salario, CalcularJubilacion(lista[i]));
		}
	}
}


void OrdenarYMostrarListaEmpleados(Empleado lista[], int len){
	Empleado aux;
	for(int i=0;i<len-1;i++){
		for(int j=i+1;j<len;j++){
			if(strcmp(lista[i].apellido,lista[j].apellido)>0){
				aux=lista[i];
				lista[i]=lista[j];
				lista[j]=aux;
			}
		}
	}
	MostrarTodosLosEmpleados(lista, len);
}


Empleado BuscarSueldoFemeninoMasAlto(Empleado lista[], int len){
	Empleado aux;
	int flagPrimerRegistro=0;
	for(int i=0;i<len;i++){
		if(strcmp(lista[i].genero,"Femenino")==0){
			if(!flagPrimerRegistro){
				flagPrimerRegistro=1;
				aux=lista[i];
			}
			else{
				if(aux.salario<lista[i].salario){
					aux=lista[i];
				}
			}
		}
	}
	return aux;
}


void MostrarEmpleadaConMayorSalario(Empleado lista[], int len){
	Empleado empleada;
	empleada=BuscarSueldoFemeninoMasAlto(lista, len);
	printf("\nLa empleada con mayor sueldo es: %s %s con un total de: %.2f\n",empleada.nombre, empleada.apellido, empleada.salario);
}

