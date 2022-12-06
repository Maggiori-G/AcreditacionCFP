/*
 * EmpleadosEmpresa.h
 *
 *  Created on: 6 dic. 2022
 *      Author: tanii
 */

#ifndef EMPLEADOSEMPRESA_H_
#define EMPLEADOSEMPRESA_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct{
	char nombre[30];
	char apellido[30];
	char genero[20];
	int antiguedad;
	int edad;
	float salario;
}Empleado;

void Menu();
int PedirCadena(char cadena[], char mensaje[], char mensajeError[]);
int PedirNumeroEnRango(char mensaje[], int minimo, int maximo);
int CalcularCantidadEmpleadosMasculinos(Empleado lista[], int len);
void ImprimirCantidadDeEmpleadosMasculinos(Empleado lista[], int len);
float CalcularPorcentajeDeEmpleadosPorGenero(Empleado lista[], int len, char generoBuscar[]);
void ImprimirPorcentajesEmpleados(Empleado lista[], int len);
int CalcularDiferenciaDeAniosJubilatorios(Empleado empleado);
void MostrarAniosJubilatoriosEmpleados(Empleado lista[], int len);
float CalcularSueldosEmpleados(Empleado lista[], int len);
void MostrarSueldosTotal(Empleado lista[], int len);
void MostrarTodosLosEmpleados(Empleado lista[], int len);
void MostrarEmpleadoSeleccionado(Empleado lista[], int len);
void OrdenarYMostrarListaEmpleados(Empleado lista[], int len);
int CalcularJubilacion(Empleado empleado);
Empleado BuscarSueldoFemeninoMasAlto(Empleado lista[], int len);
void MostrarEmpleadaConMayorSalario(Empleado lista[], int len);
#endif /* EMPLEADOSEMPRESA_H_ */
