/*
 * utn.h
 *
 *  Created on: 29 abr. 2021
 *      Author: Luk
 */

#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getString(char* pResultado,int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getNombre(char* pResultado,int longitud, char* mensaje, char* mensajeError, int reintentos);
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

#endif /* UTN_H_ */
