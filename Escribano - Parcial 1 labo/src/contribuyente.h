

#ifndef CONTRIBUYENTE_H_
#define CONTRIBUYENTE_H_


#define TXT 20
typedef struct{
	int id;
	int cuil;
	char nombre[TXT];
	char apellido[TXT];
	int isEmpty;//1=libre 0=lleno
}Contribuyente;
#include "Recaudacion.h"



int init(Contribuyente lista[], int size);
/** \brief inicializar array
 * pone (isEmpty) en libre=1
 * \param lista Contribuyente* Pointer to array of contribuyente
 * \param size int Array tamaño
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int searchForSpace(Contribuyente lista[],int size,int* position);
/** \brief busca espacio en array de contribuyentes
 * \param lista Contribuyente* Pointer to array of Contribuyentes
 * \param size int Array length
 * \param position int puntero a la posicion en el array
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int altaContribuyente(Contribuyente lista[],int* nextId, int size);
/** \brief realiza alta de un contribuyente
 * \param lista Contribuyente* Pointer to array of Contribuyentes
 * \param nextId int* puntero a id
 * \param size int tamño de array
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int findContribuyenteById(Contribuyente* lista, int size, int valor, int* position);
/** \brief busca contribuyente por id
 * \param lista Contribuyente* Pointer to array of Contribuyentes
 * \param size int tamño de array
 * \param valor int valor a buscar
 * \param position int puntero a la posicion en el array
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int modifContrib(Contribuyente* lista, int size);
/** \brief modifica parametros de un contribuyente
 * \param lista Contribuyente* Pointer to array of Contribuyentes
 * \param size int tamño de array
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
void printContribuyente(Contribuyente lista, int size);
/** \brief imprime un contribuyente
 * \param lista Contribuyente una estructura sola del array
 * \param size int tamño de array
 *
 *
 */
int printContribuyentes(Contribuyente lista[], int size);
/** \brief imprime contribuyentes
 * \param lista Contribuyente* Pointer to array of Contribuyentes
 * \param size int tamño de array
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int removeContribuyente(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT);
/** \brief modifica parametros de un empleado
 * \param lista Contribuyente* Pointer to array of Contribuyentes
 * \param size int tamño de array
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int printAllContrib(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT);
/** \brief modifica parametros de un empleado
 * \param lista Contribuyente[] array de Contribuyentes
 * \param size int tamño de array
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int getImya(Contribuyente lista[], int size, int buscar, char descripcion[]);
/** \brief busca el nombre
 * \param lista Contribuyente[] array de Contribuyentes
 * \param size int tamño de array
 * \param buscar int id del contribuyente
 * \param descripcion char retorna el nombre
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
int getFamiliya(Contribuyente lista[], int size, int buscar, char descripcion[]);
/** \brief busca el apellido
 * \param lista Contribuyente array de Contribuyentes
 * \param size int tamño de array
 * \param buscar int id del contribuyente
 * \param descripcion char retorna el nombre
 * \return int Retorna (-1) si hay Error [Invalid length or NULL pointer] - y (0) si esta Ok
 *
 */
void printContribSinSize(Contribuyente lista);
/** \brief imprime un contribuyente(sin usar el tamaño)
 * \param lista Contribuyente una estructura del array de contribuyentes
 *
 *
 *
 */
int informea(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT);
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
int informeb(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT);
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
int informec(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT);
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

int informed(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT);
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
int menuInf(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT);
/** \brief realiza alta de uncontribuyente
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
#endif /* CONTRIBUYENTE_H_ */
