/*
 * Recaudacion.h
 *
 *  Created on: 13 may. 2021
 *      Author:
 */

#ifndef RECAUDACION_H_
#define RECAUDACION_H_

#define TXT 20
typedef struct{
	int idTipo;
	char descripcion[TXT];
	int isEmpty;//1=libre 0=lleno

}Tipo;
typedef struct{
	int idRec;
	int mes;
	Tipo tipo;
	int importe;
	int isEmpty;//1=libre 0=lleno
	int idContribuyente;
	char status[TXT];
}Recaudacion;
#include "contribuyente.h"
int initRecauda(Recaudacion recauda[],int size);
/** \brief inicializa array con isEmpty
* \param recauda Recaudacion* Pointer to array of recaudacion
 * \param size int Array length
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int searchForSpaceRec(Recaudacion recauda[],int size,int* position);
/** \brief busca espacio en array de recaudaciones
* \param recauda Recaudacion* Pointer to array of recaudacion
 * \param size int Array length
 * \param position int puntero a la posicion en el array
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int altaRecaudacion(Recaudacion recauda[],int* nextIdRec, int size,Tipo tipos[],int sizeT,Contribuyente lista[], int sizeC);
/** \brief realiza alta de un contribuyente
* \param recauda[] Recaudacion array de recaudacion
 * \param nextIdRec int* puntero a id de recaudaciones
 * \param size int tamño de array de recaudaciones
 * \param tipos[] Tipo array de tipos de recaudacion
  * \param sizeT int tamño de array de tipos
  * \param lista[] Contribuyente array de contribuyentes
  *  \param sizeC int tamño de array de contribuyentes
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
void printRecaudacion(Recaudacion recauda, int size,Tipo tipos[],int sizeT);
/** \brief imprime una recaudacion
 * \param lista Contribuyente una estructura sola del array
 *  \param size int tamño de array
 * \param tipos[] Tipo array de tipos
 * \param sizeT int tamño de array de tipos
 *
 *
 */
int printRecaudaciones(Recaudacion recauda[], int size, Tipo tipos[],int sizeT);
/** \brief imprime todas la recaudaciones
* \param recauda[] Recaudacion array de recaudacion
 * \param size int tamño de array de recaudaciones
 * \param tipos[] Tipo array de tipos de recaudacion
  * \param size int tamño de array de tipos
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int getDescripcionTipo(Tipo tipos[],int sizeT, int buscar, char descripcion[]);
/** \brief busca el nombre
 * \param tipos[] Tipo array de tipos de recaudacion
 * \param size int tamño de array
 * \param buscar int id de la recaudacion
 * \param descripcion char retorna la descripcion
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
void printTipo(Tipo tipos,int sizeT);
/** \brief imprime una recaudacion
 * \param lista Contribuyente una estructura sola del array
 *  \param size int tamño de array
 * \param tipos[] Tipo array de tipos
 * \param sizeT int tamño de array de tipos
 *
 *
 */
int printTipos(Tipo tipos[],int sizeT);
/** \brief imprime todos los tipos
 * \param tipos[] Tipo array de tipos
 * \param sizeT int tamño de array de tipos
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int findRecaudacionById(Recaudacion* recauda, int size, int valor, int* position);
/** \brief busca contribuyente por id
* \param recauda Recaudacion* Pointer to array of recaudacion
 * \param size int tamño de array
 * \param valor int valor a buscar
 * \param position int puntero a la posicion en el array
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int refinanciar(Recaudacion recauda[],int size,Tipo tipos[],int sizeT,Contribuyente lista[], int sizeC);
/** \brief realiza la refinanciacion de una recaudacion
* \param recauda[] Recaudacion array de recaudacion
 * \param size int tamño de array de recaudaciones
 * \param tipos[] Tipo array de tipos de recaudacion
  * \param sizeT int tamño de array de tipos
  * \param lista[] Contribuyente array de contribuyentes
  *  \param sizeC int tamño de array de contribuyentes
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int saldar(Recaudacion recauda[],int size,Tipo tipos[],int sizeT,Contribuyente lista[], int sizeC);
/** \brief salda una recaudacion
* \param recauda[] Recaudacion array de recaudacion
 * \param size int tamño de array de recaudaciones
 * \param tipos[] Tipo array de tipos de recaudacion
  * \param sizeT int tamño de array de tipos
  * \param lista[] Contribuyente array de contribuyentes
  *  \param sizeC int tamño de array de contribuyentes
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int findRecaudacionByIdContrib(Recaudacion* recauda, int size, int valor, int* position);
/** \brief busca recaudacion por id del contribuyente
 * \param recauda Recaudacion* Pointer to array of recaudacion
 * \param size int tamño de array
 * \param valor int valor a buscar
 * \param position int puntero a la posicion en el array
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int printRecPlusCont(Recaudacion recauda[],int size,Tipo tipos[],int sizeT,Contribuyente lista[], int sizeC);
/** \brief imprime todas las recaudaciones saldadas con datos de la recaudacion mas los datos del contribuyente
* \param recauda[] Recaudacion array de recaudacion
 * \param size int tamño de array de recaudaciones
 * \param tipos[] Tipo array de tipos de recaudacion
  * \param sizeT int tamño de array de tipos
  * \param lista[] Contribuyente array de contribuyentes
  *  \param sizeC int tamño de array de contribuyentes
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
#endif /* RECAUDACION_H_ */
