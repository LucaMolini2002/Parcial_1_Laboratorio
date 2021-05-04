/*
 * Compra.h
 *
 *  Created on: 29 abr. 2021
 *      Author: Luk
 */

#ifndef COMPRA_H_
#define COMPRA_H_

#define DIRECCION_QTY 64
#define COLORES_QTY 64

#define COBRADO 1
#define PENDIENTE 0
#define PRECIO 100

typedef struct{
	int idCliente;
	int cantidadBarbijos;
	char direccionEntrega[DIRECCION_QTY];
	char ColorBarbijos[COLORES_QTY];
	float precioPorUnidad;
	int estadoCompra;
	int idCompra;
	int isEmpty;
}Compra;

int com_imprimir(Compra* pElemento);
int com_imprimirArray(Compra* array,int limite);
int com_initArray(Compra aContratacion[],int limite);
int com_altaArray(Compra* array,int limite,int indice,int* idContratacion,int idPantalla, int* estadoCompra);
int com_modificarArray(Compra* array,int limite, int indice, int* estadoCompra);
int com_pagoDelProducto(Compra* array, int limite, int indice, int* estadoCompra , int* precio);
int com_bajaArray(Compra* array,int limite, int indice, int* estadoCompra);
int com_buscarId(Compra* array,int limite,int valorBuscado);
int com_getEmptyIndex(Compra* array,int limite);

#endif /* COMPRA_H_ */
