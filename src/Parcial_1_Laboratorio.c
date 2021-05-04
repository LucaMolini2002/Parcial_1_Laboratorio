/*
 ============================================================================
 Name        : Parcial_1_Laboratorio.c
 Author      : Luca
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Cliente.h"
#include "Compra.h"
#include "CompraCliente.h"

#define QTY_CLIENTES 100
#define QTY_COMPRAS 1000

int main(void) {
	setbuf(stdout,NULL);
	Cliente clientes[QTY_CLIENTES];
	Compra compras[QTY_COMPRAS];

	int opcion;
	int opcionB;

	int idClientes=1;
	int auxIndexClientes;
	int auxIdClientes;

	int idCompras=1;
	int auxIndexCompras;
	int auxIdCompras;

	int auxIdVenta;
	int precioProducto;

	int cantComprasPendientes;

	int estadoDeCompra;

	if(cli_initArray(clientes,QTY_CLIENTES)==0)
	{
		printf("Inicio el array de clientes, ");
	}
	if(com_initArray(compras, QTY_COMPRAS)==0)
	{
		printf("Inicio el array de compras\n\n");
	}

	do{
		if(utn_getNumero(&opcion,
			"\nElija una opcion: \n\n"
			"1-Dar de alta un cliente: \n"
			"2-Modificar datos de un cliente: \n"
			"3-Dar de baja un cliente: \n\n"
			"4-Realizar una compra: \n"
			"5-Pagar una compra: \n"
			"6-Cancelar una compra: \n\n"
			"7-Imprimir lista con clientes: \n"
			"8-Informar: \n"
			"9-Salir. \n",
		    "\nError, ingrese una opcion valida.\n"
		    ,1,11,2)==0)
		{
			switch(opcion)
			{
			case 1:
				auxIndexClientes = cli_getEmptyIndex(clientes, QTY_CLIENTES);
				if(auxIndexClientes >= 0)
				{
					cli_altaArray(clientes, QTY_CLIENTES, auxIndexClientes, &idClientes);
					printf("Los datos se cargaron correctamente.\n");
				}
				else
				{
					printf("No quedan mas espacios disponibles.\n");
				}

				break;
			case 2:
				if(utn_getNumero(&auxIdClientes, "Ingrese ID del cliente a modificar: \n", "ID no valido, vuelva a intentarlo.\n", 0, 100000, 3)==0)
				{
					auxIndexClientes = cli_buscarId(clientes, QTY_CLIENTES, auxIdClientes);
					if(auxIndexClientes >= 0 && cli_modificarArray(clientes, QTY_CLIENTES, auxIndexClientes)==0)
					{
						printf("Modificacion realizada con exito. \n");
					}
				}
				break;
			case 3:
				if(utn_getNumero(&auxIdClientes, "Ingrese ID del cliente a dar de baja: \n", "ID no valido, vuelva a intentarlo.\n", 0, 100000, 3)==0)
				{
					info_imprimirComprasDeClientes(compras, QTY_COMPRAS, clientes, QTY_CLIENTES, auxIdClientes);
					auxIndexClientes = cli_buscarId(clientes, QTY_CLIENTES, auxIdClientes);
					if(auxIndexClientes >= 0 && cli_bajaArray(clientes, QTY_CLIENTES, auxIndexClientes)==0)
					{
						printf("Se dio de baja al cliente. \n");
					}
				}
				break;
			case 4:
				auxIndexCompras = com_getEmptyIndex(compras, QTY_COMPRAS);
				if(auxIndexCompras >= 0)
				{
					if(utn_getNumero(&auxIdClientes,"\nID del cliente?","\nError",0,10000,2)==0 &&
						cli_buscarId(clientes, QTY_CLIENTES, auxIdCompras)>=0)
					{
						if(com_altaArray(compras, QTY_COMPRAS, auxIndexCompras, &idCompras, idClientes, &estadoDeCompra)==0)
						{
							printf("La compra se realizo con exito.\n");
							printf("El ID de esta compra es: %d\n\n",idCompras);
						}
					}
					else
					{
						printf("El ID introducido no existe\n");
					}
				}
				break;
			case 5:
				if(utn_getNumero(&auxIdVenta,"\nID de la venta?","\nError",0,10000,2)==0 &&
					com_buscarId(compras, QTY_COMPRAS, auxIdVenta)>=0 &&
					info_imprimirComprasDeClientes(compras, QTY_COMPRAS, clientes, QTY_CLIENTES, auxIdVenta)==0)
				{
					if(com_pagoDelProducto(compras, QTY_COMPRAS, auxIndexCompras, &estadoDeCompra, &precioProducto)==0);
				}
				else
				{
					printf("El ID introducido no existe\n");
				}
				break;
			case 6:
				if(utn_getNumero(&auxIdCompras,"\nID de la venta?","\nError",0,10000,2)==0 &&
					com_buscarId(compras, QTY_COMPRAS, auxIdCompras)>=0 &&
					cli_imprimirArray(clientes, QTY_CLIENTES)==0 )
				{
					if(com_bajaArray(compras, QTY_COMPRAS, auxIndexCompras, &estadoDeCompra)==0)
					{
						printf("Se cancelo la compra con exito.\n");
					}
				}
				else
				{
					printf("El ID introducido no existe\n");
				}
				break;
			case 7:
				info_DatosClientesConCantidadDeCompras(compras, QTY_COMPRAS, clientes, QTY_CLIENTES);
				break;
			case 8:
				if(utn_getNumero(&opcionB,
							"\nElija una opcion: \n\n"
							"1-Informar color de barbijo que se compro mas veces: \n"
							"2-Informar cantidad de compras pendientes: \n"
							"3-Informar compra con precio por unidad mas bajo: \n\n",
						    "\nError, ingrese una opcion valida.\n"
						    ,1,3,2)==0)
						{
					switch(opcionB)
					{
					case 1:

						break;
					case 2:
						info_cantidadComprasPendientes(compras, QTY_COMPRAS, estadoDeCompra, cantComprasPendientes);
						break;
					case 3:
						info_PrecioPorUnidadMinimo(compras, QTY_COMPRAS, precioProducto);
						break;

					}
						}

				break;
			}

		}


	}while(opcion!=9);




	return EXIT_SUCCESS;
}
