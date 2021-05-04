/*
 * Cliente.h
 *
 *  Created on: 29 abr. 2021
 *      Author: Luk
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define NOMBRE_QTY 30
#define APELLIDO_QTY 30
#define CUIT_QTY 20

typedef struct{
	char nombre[NOMBRE_QTY];
	char apellido[APELLIDO_QTY];
	char cuit[CUIT_QTY];
	int idCliente;
	int isEmpty;
}Cliente;

int cli_imprimir(Cliente* pElemento);
int cli_imprimirArray(Cliente* array,int limite);
int cli_initArray(Cliente aPantallas[],int limite);
int cli_altaArray(Cliente* array,int limite,int indice,int* id);
int cli_modificarArray(Cliente* array,int limite, int indice);
int cli_bajaArray(Cliente* array,int limite, int indice);
int cli_buscarId(Cliente* array,int limite,int valorBuscado);
int cli_getEmptyIndex(Cliente* array,int limite);
int cli_ordenarPorDireccion(Cliente* array,int limite);
#endif /* CLIENTE_H_ */
