/*
 * Clientes.c
 *
 *  Created on: 29 abr. 2021
 *      Author: Luk
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "utn.h"

/* brief IMPRIMO EL ARRAY DE CLIENTES
 * param array Puntero al array de clientes
 * param limite define el tamaño del array
 * return retorna 0(EXITO) y -1(ERROR)
 */
int cli_imprimir(Cliente* pElemento)
{
	int retorno=-1;
		if(pElemento != NULL && pElemento->isEmpty == 0)
		{
			retorno=0;
			printf("\nID: %d | Nombre: %s | Apellido: %s | Cuit: %s \n",pElemento->idCliente,pElemento->nombre,pElemento->apellido,pElemento->cuit);
		}
	return retorno;
}
int cli_imprimirArray(Cliente* array,int limite)
{
	int i;
	int retorno=-1;
	if(array != NULL && limite > 0 )
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{

			cli_imprimir(&array[i]);
		}
	}
	return retorno;
}
/* brief INICIALIZO EL ARRAY DE CLIENTES
 * param array Puntero al array de clientes
 * param limite define el tamaño del array
 * return retorna 0(EXITO) y -1(ERROR)
 */
int cli_initArray(Cliente* aClientes,int limite)
{
	int retorno=-1;
	if(aClientes!=NULL && limite>0)
	{
		retorno=0;
		for(int i=0;i<limite;i++)
		{
			aClientes[i].isEmpty=1;
		}
	}
	return retorno;
}
/* \brief Da de alta un clientes en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array clientes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a al cliente
 * return retorno 0(exito) y -1(error)
 * */
int cli_altaArray(Cliente* array,int limite,int indice,int* id)
{
	int retorno=-1;
	Cliente bufferClientes;
	if(array!=NULL && limite>0 && indice<limite && indice>=0 && array[indice].isEmpty==1)
	{
		if(utn_getNombre(bufferClientes.nombre, NOMBRE_QTY, "\nNombre:\n", "\nError\n", 2)==0 &&
		   utn_getNombre(bufferClientes.apellido, APELLIDO_QTY,"\nApellido:\n", "\nError\n", 2)==0 &&
		   utn_getCuit(bufferClientes.cuit, CUIT_QTY,"\nCuit:\n", "\nError\n", 2)==0)

		{
			retorno=0;
			bufferClientes.idCliente= *id;
			bufferClientes.isEmpty=0;
			array[indice]=bufferClientes;
			(*id)++;
		}
	}
	return retorno;
}
/* \brief actualiza los datos de una clientes en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array clientes
 * \param indice Posicion a ser actualizada
 * return retorno 0(exito) y -1(error)
 * */
int cli_modificarArray(Cliente* array,int limite, int indice)
{
	int retorno=-1;
	Cliente bufferClientes;
	if(array!=NULL&&limite>0&&indice<limite&&indice>=0&&array[indice].isEmpty==0)
	{
		if(utn_getNombre(bufferClientes.nombre, NOMBRE_QTY, "\nNombre:\n", "\nError\n", 2)==0 &&
		   utn_getNombre(bufferClientes.apellido, APELLIDO_QTY,"\nApellido:\n", "\nError\n", 2)==0 &&
		   utn_getCuit(bufferClientes.cuit,CUIT_QTY,"\nCuit:\n", "\nError\n", 2)==0)
		{
			retorno=0;
			bufferClientes.idCliente=array[indice].idCliente;
			bufferClientes.isEmpty=0;
			array[indice]=bufferClientes;
		}
	}
	return retorno;
}
/* \brief da de baja una clientes en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array pantallas
 * \param indice Posicion a ser actualizada
 * return retorno 0(exito) y -1(error)
 * */
int cli_bajaArray(Cliente* array,int limite, int indice)
{
	int retorno=-1;
	Cliente bufferEntidad;
	if(array!=NULL&&limite>0&&indice<limite&&indice>=0&&array[indice].isEmpty==0)
	{
		retorno=0;
		bufferEntidad.isEmpty=1;
		array[indice] = bufferEntidad;
	}
	return retorno;
}
/* \brief busca un id en un array y devuelve la posicion en la que se encuentra
 * \param array Array de clientes
 * \param limite Limite del array clientes
 * \param valorBuscado puntero a la posicion del array donde se encuentra el valor buscado
 * return retorno 0(exito) y -1(error)
 * */
int cli_buscarId(Cliente* array,int limite,int valorBuscado)
{
	int retorno=-1;
	int i;
	if(array!=NULL&&limite>0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].idCliente==valorBuscado)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/* \brief busca una posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array clientes
 * return retorno 0(exito) y -1(error)
 * */
int cli_getEmptyIndex(Cliente* array,int limite)
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

int cli_ordenarPorDireccion(Cliente* array,int limite)
{
	int retorno=-1;
	int flagSwap;
	int i;
	Cliente bufferEntidad;
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
				if(strncmp(array[i].cuit,array[i+1].cuit,50)>0)
				{
					flagSwap=1;
					bufferEntidad=array[i];
					array[i]=array[i+1];
					array[i+1]=bufferEntidad;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return retorno;
}
