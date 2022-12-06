/*
 ============================================================================
 Name        : ExamenCFP.c
 Author      : Maggiori, Gianni
 Description : Examen de Acreditación de saberes CFP
 ============================================================================
 */

#include "EmpleadosEmpresa.h"

#define ARRAYEMPLEADOS 20
int main(void) {
	setbuf(stdout,NULL);
	int opcionMenu;
	Empleado listaEmpleados[ARRAYEMPLEADOS]={{"Gianni", "Maggiori", "Masculino",5, 31, 50000.10},
											 {"Pablo Gaston", "Maggiori", "Masculino",7, 37, 65000.25},
											 {"Mariana", "Maggiori", "Femenino",8, 39, 65000.50},
											 {"Angela", "Covati", "Femenino",15, 59, 210000.90},
											 {"Gustavo", "Discarlo", "Masculino",20, 41, 95000.25},
											 {"Mayra", "Maestu", "Femenino",9, 29, 180000.75},
											 {"Illidan", "Tempestira", "Masculino",2, 52, 71125.10},
											 {"Soap", "Mctravish", "Masculino",5,25, 45000},
											 {"Ghost", "Sullivan", "Masculino",6, 31, 120000.50},
											 {"Lars", "Ulrich", "Masculino", 59,11, 82225.50},
											 {"Simone", "Simons", "Femenino", 39,4, 372550.80},
											 {"Tarja", "Turunen", "Femenino", 49,7, 89999.99},
											 {"Valeria", "Maggiori", "Femenino",16, 42, 35000},
											 {"Sebastian", "Regiani", "Masculino",13, 43, 224500.20},
											 {"Darth", "Vader", "Masculino", 20,1, 100000},
											 {"Ivana", "Marastoni", "Femenino",3, 28, 35000.10},
											 {"Camila", "Mussi", "Femenino", 29,5, 110670.60},
											 {"Kylo", "Ren", "Masculino", 25,3, 150360.90},
											 {"Berman", "Scarabilo", "Masculino",2, 22, 162000.63},
											 {"Arthas", "Menethrill", "Masculino",22, 50, 35000}};
	do{
		Menu();
		opcionMenu=PedirNumeroEnRango("Ingrese una opcion: ",0,9);
		switch (opcionMenu) {
			case 1:
				ImprimirCantidadDeEmpleadosMasculinos(listaEmpleados, ARRAYEMPLEADOS);
			break;
			case 2:
				ImprimirPorcentajesEmpleados(listaEmpleados, ARRAYEMPLEADOS);
			break;
			case 3:
				MostrarAniosJubilatoriosEmpleados(listaEmpleados, ARRAYEMPLEADOS);
			break;
			case 4:
				MostrarSueldosTotal(listaEmpleados, ARRAYEMPLEADOS);
			break;
			case 5:
				MostrarTodosLosEmpleados(listaEmpleados, ARRAYEMPLEADOS);
				MostrarEmpleadoSeleccionado(listaEmpleados, ARRAYEMPLEADOS);
			break;
			case 6:
				OrdenarYMostrarListaEmpleados(listaEmpleados, ARRAYEMPLEADOS);
			break;
			case 7:
				MostrarEmpleadaConMayorSalario(listaEmpleados, ARRAYEMPLEADOS);
			break;
		}
	}while(opcionMenu != 8);

	return EXIT_SUCCESS;
}
