/*
 * Compra.c
 *
 *  Created on: 29 abr. 2021
 *      Author: Luk
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compra.h"
#include "utn.h"

/* brief IMPRIMO EL ARRAY DE PANTALLAS
 * param array Puntero al array de alumnos
 * param limite define el tamaño del array
 * return retorna 0(EXITO) y -1(ERROR)
 */
int com_imprimir(Compra* pElemento)
{
	int retorno=-1;
		if(pElemento != NULL && pElemento->isEmpty == 0)
		{
			retorno=0;
			printf("\nID:%d\n"
				   "Cantidad de barbijos:%d\n"
				   "Direccion de entrega y color: %s-%s\n ",pElemento->idCliente,pElemento->cantidadBarbijos,pElemento->direccionEntrega,pElemento->ColorBarbijos);
		}
	return retorno;
}
int com_imprimirArray(Compra* array,int limite)
{
	int i;
	int retorno=-1;
	if(array != NULL && limite > 0 )
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			com_imprimir(&array[i]);
		}
	}
	return retorno;
}
/* brief INICIALIZO EL ARRAY DE CONTRATACIONES
 * param array Puntero al array de pantallas
 * param limite define el tamaño del array
 * return retorna 0(EXITO) y -1(ERROR)
 */
int com_initArray(Compra aCompras[],int limite)
{
	int retorno=-1;
	if(aCompras!=NULL&&limite<0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)
		{
			aCompras[i].isEmpty=1;
		}
	}
	return retorno;
}
/* \brief Da de alta un contrataciones en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array pantallas
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la pantalla
 * return retorno 0(exito) y -1(error)
 * */
int com_altaArray(Compra* array,int limite,int indice,int* idCompra,int idCliente, int* estadoCompra)
{
	int retorno=-1;
	Compra bufferCompra;
	if(array!=NULL && limite>0 && indice<limite&&indice>=0 && array[indice].isEmpty==1)
	{
		if(utn_getNumero(&bufferCompra.cantidadBarbijos,"\nCantidad de barbijos:\n", "\nError\n",0,10000, 2)==0 &&
		   utn_getString(bufferCompra.direccionEntrega,DIRECCION_QTY, "Direccion de entrega:\n", "\nError\n", 2)==0 &&
		   utn_getString(bufferCompra.ColorBarbijos, COLORES_QTY, "Color del barbijo:\n", "\nError\n", 2)==0)
		{
			retorno=0;
			bufferCompra.idCompra= *idCompra;
			bufferCompra.idCliente= idCliente;
			bufferCompra.isEmpty=0;
			array[indice]=bufferCompra;
			(*idCompra)++;
			estadoCompra=PENDIENTE;
		}
	}
	return retorno;
}
/* \brief actualiza los datos de una contrataciones en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array pantallas
 * \param indice Posicion a ser actualizada
 * return retorno 0(exito) y -1(error)
 * */
int com_modificarArray(Compra* array,int limite, int indice, int* estadoCompra)
{
	int respuesta = -1;
	int  dias;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		if(	!utn_getNumero(&dias,"\n Cuantos dias desea que dure el contrato? ", "\nError",1,365,2))
		{
			respuesta = 0;
			//estadoCompra=COBRADO;
		}
	}
	return respuesta;
}
/* \brief Efectua el pago de la compra y cambia el estado de compra a cobrado
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array pantallas
 * \param indice Posicion a ser actualizada
 * \param estadoCompra indica si la compra esta pendiente o cobrada
 * return retorno 0(exito) y -1(error)
 * */
int com_pagoDelProducto(Compra* array, int limite, int indice, int* estadoCompra , int* precio)
{
	int retorno=-1;
	Compra bufferPrecio;
	int respuesta;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && estadoCompra == PENDIENTE)
	{
		if(utn_getNumeroFloat(&bufferPrecio.precioPorUnidad, "Ingrese importe a pagar:", "Error, ingrese un importe valido.", 0.0, 1000000.0, 2)==0 &&
		   utn_getNumero(&respuesta, "Quiere cambiar el estado a 'cobrado'?"
				                    "1-Si"
				                    "2-No", "Error, ingrese una opcion valida", 1, 2, 2)==0 && respuesta==1)
		{
			array[indice].precioPorUnidad=bufferPrecio.precioPorUnidad;
			printf("Se realizo la conpra, el precio pagado es: %f.2\n", array[indice].precioPorUnidad);
			estadoCompra=COBRADO;
		}
	}
	return retorno;
}
/* \brief da de baja una pantalla en una posicion del array
 * \param array Array de pantallas a ser actualizado
 * \param limite Limite del array pantallas
 * \param indice Posicion a ser actualizada
 * return retorno 0(exito) y -1(error)
 * */
int com_bajaArray(Compra* array,int limite, int indice, int* estadoCompra)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(estadoCompra==PENDIENTE)
		{
			array[indice].isEmpty = 1;
			respuesta = 0;
		}else
		{
			printf("No se puede dar de baja, la compra ya se realizo. \n");
		}

	}
	return respuesta;
}
/* \brief busca un id en un array y devuelve la posicion en la que se encuentra
 * \param array Array de pantallas
 * \param limite Limite del array pantallas
 * \param valorBuscado puntero a la posicion del array donde se encuentra el valor buscado
 * return retorno 0(exito) y -1(error)
 * */
int com_buscarId(Compra* array,int limite,int valorBuscado)
{
	int retorno=-1;
	int i;
	if(array!=NULL&&limite>0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].idCompra==valorBuscado)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/* \brief busca una posicion vacia
 * \param array Array de pantallas
 * \param limite Limite del array pantallas
 * return retorno 0(exito) y -1(error)
 * */
int com_getEmptyIndex(Compra* array,int limite)
{
	int retorno=-1;
	int i;
		if(array!=NULL&&limite>0)
		{
			retorno=0;
			for(i=0;i<limite;i++)
			{
				if(array[i].isEmpty==1)
				{
					retorno=i;
					break;
				}
			}
		}
	return retorno;
}

int com_ordenarPorDireccion(Compra* array,int limite)
{
	int retorno=-1;
	int flagSwap;
	int i;
	Compra buffer;
	if(array!=NULL&&limite>0)
	{
		do{
			flagSwap=0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].direccionEntrega,array[i+1].direccionEntrega,50)>0)
				{
					flagSwap=1;
					buffer=array[i];
					array[i]=array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return retorno;
}
