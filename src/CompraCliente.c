/*
 * CompraCliente.c
 *
 *  Created on: 4 may. 2021
 *      Author: Luk
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compra.h"
#include "Cliente.h"
#include "utn.h"

int info_imprimirComprasDeClientes(Compra* aCompras,int limiteCompras,Cliente* aClientes,int limiteClientes,int auxiliarVenta)
{
	int retorno = -1;
	int i;
	int indiceArrayCliente;
	int idCliente;
	if(aCompras != NULL && limiteCompras > 0 && aClientes != NULL && limiteClientes > 0 )
	{
		for(i=0;i<limiteCompras;i++)
		{
			if(aCompras[i].isEmpty == 0 && aCompras[i].idCliente == auxiliarVenta)
			{
				retorno = 0;
				idCliente = aCompras[i].idCliente;
				indiceArrayCliente = cli_buscarId(aClientes,limiteClientes,idCliente);

				printf("\nID compra: %d - Direccion de entrega: %s - Cantidad: %d - Color: %s - ID cliente: %d",aCompras[i].idCompra,aCompras[i].direccionEntrega,aCompras[i].cantidadBarbijos,aCompras[i].ColorBarbijos,aCompras[i].idCliente);
				printf(" - %s - %s - %s \n",aClientes[indiceArrayCliente].nombre,aClientes[indiceArrayCliente].apellido,aClientes[indiceArrayCliente].cuit);
			}
		}
	}
	return retorno;
}

int info_DatosClientesConCantidadDeCompras(Compra* aCompras,int limiteCompras,Cliente* aClientes,int limiteClientes)
{
	int retorno=-1;
	int i;
	if(aCompras != NULL && limiteCompras > 0 && aClientes != NULL && limiteClientes > 0 )
	{
		retorno=0;
		for(i=0;i<limiteCompras;i++)
		{
			printf("ID cliente: %d | Nombre y apellido: %s %s | CUIT: %s | Cantidad de compras: %d\n",aClientes[i].idCliente,aClientes[i].nombre,aClientes[i].apellido,aClientes[i].cuit,aCompras[i].idCompra);
		}
	}
	return retorno;
}

int info_cantidadComprasPendientes(Compra* aCompras,int limiteCompras,int estadoCompra,int ComprasPendientes)
{
	int retorno=-1;
	int i;

	if(aCompras!=NULL && limiteCompras > 0 && estadoCompra == PENDIENTE)
	{
		retorno=0;
		for(i=0;i<limiteCompras;i++)
		{
			ComprasPendientes++;
		}
		printf("La cantidad de compras pendientes es: %d\n",ComprasPendientes);
	}

	return retorno;
}

int info_PrecioPorUnidadMinimo(Compra* array,int limite)
{
	int retorno=-1;
	float minimo;

	if(array != NULL && limite > 0 ){
		minimo=array[0].precioPorUnidad;
		for(int i=0;i<limite;i++)
		{
			if(array[i].precioPorUnidad<minimo)
			{
				minimo=array[i].precioPorUnidad;
			}
		}
		printf("La compra con menor precio por unidad es de: %d \n",minimo);
		retorno=0;
	}

	return retorno;
}








