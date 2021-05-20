#define TXT 20
#define SIZE 5
#define SIZER 5
#define SIZET 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "Recaudacion.h"
#include "contribuyente.h"

int init(Contribuyente lista[],int size)
{
	int retorno =-1;
	if(lista != NULL && SIZE>0)
	{
	for(int i=0;i<SIZE;i++)
	{

		lista[i].isEmpty=1;
	}
	retorno =0;
	}

	return retorno;
}

int searchForSpace(Contribuyente lista[],int size,int* position)
{
	int retorno=-1;
		int i =0;
		if(lista!=NULL && SIZE >=0 && position!=NULL)
		{
			for(i=0;i<SIZE;i++)
			{
				if(lista[i].isEmpty==1)
				{
					retorno=0;
					*position=i;
					break;
				}
			}
		}
		return retorno;
}
int altaContribuyente(Contribuyente lista[],int* nextId, int size)
{
	int ret=-1;
	int position;
	if(lista!=NULL && SIZE>0)
	{

		if(searchForSpace(lista,SIZE,&position)==-1)
		{
			printf("NO HAY ESPACIO DISPONIBLE\n");
		}
		else
		{
			(*nextId)++;
			lista[position].id= *nextId;
			get_Entero(&lista[position].cuil,1,"\n ingrese cuil:","\n ERROR:ingrese cuil:",1,100000000);
			getName("\n ingrese nombre: ","\n Error: reingrese nombre: ",1,TXT,1,lista[position].nombre);
			getName("\n ingrese apellido: ","\n Error: reingrese apellido: ",1,TXT,1,lista[position].apellido);
			lista[position].isEmpty=0;
			printContribuyente(lista[position],SIZE);
		}
		ret=0;
	}
	return ret;
}
int findContribuyenteById(Contribuyente* lista, int size, int valor, int* position)
{
	int retorno = -1;
	int i;
	if(lista!= NULL && SIZE >=0)
	    {
	        for(i=0;i<SIZE;i++)
	        {
	            if(lista[i].isEmpty==1)
	                continue;
	            else if(lista[i].id==valor)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}
void printContribuyente(Contribuyente lista, int size)
{

	printf("%d     %-20s   %-20s %d   \n",lista.id, lista.nombre,lista.apellido, lista.cuil);
}
int printContribuyentes(Contribuyente lista[], int size)
{
	int ret=-1;
	int i;
	printf("***************************Lista de Contribuyentes***************************\n");
	printf("Id  Nombre  Apellido  Cuil\n");
	if(lista!=NULL && SIZE >0){
		for(i=0;i<SIZE;i++)
		{
			if(lista[i].isEmpty==0)
				{
				printContribuyente(lista[i],SIZE);
				ret=0;
				}
		}

	}
		return ret;
}
int modifContrib(Contribuyente* lista, int size)
{
    int retorno=-1;
	int position;
	int auxId;
	int opModif=0;
	char continuar='s';

	if(lista!=NULL && SIZE>0)
	  {
		printContribuyentes(lista, SIZE);
		get_Entero(&auxId,1,"\n id a modificar ","\n Error: reingrese id a modificar: ",1,9999);
	    		        if(findContribuyenteById(lista,SIZE, auxId, &position)==-1)
	    		        {
	    		            printf("ID inexistente\n");
	    		        }
	    		        else
	    		        {
	    do{
	    	printf("1-Cambiar nombre\n");
	    	printf("2-Cambiar apellido\n");
	    	printf("3-Cambiar cuil\n");
	    	get_Entero(&opModif,1,"Indique opcion a modificar ","\n Error: reingrese opcion a modificar: ",1,3);
	    	switch(opModif){
	    	case 1://nombre
	    		getName("\n ingrese nombre: ","\n Error: reingrese nombre: ",1,TXT,1,lista[position].nombre);
	    		break;
	    	case 2://apellido
	    		getName("\n ingrese apellido: ","\n Error: reingrese apellido: ",1,TXT,1,lista[position].apellido);
	    		break;
	    	case 3://cuil
	    		get_Entero(&lista[position].cuil,1,"Ingrese nuevo cuil\n","Error.Ingrese nuevo cuil valido\n",1,100000000);
	    		break;
	    	default:
	    		printf("No es una opcion valida\n");
	    	}
	    	printf("Desea volver al menu? s/n : \n");
	    				        fflush(stdin);
	    				        scanf("%c", &continuar);
	    }while(continuar=='s');
	    		        }
	    		        retorno=0;
	  }
	    return retorno;
}
int removeContribuyente(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT)
{
	int retorno =-1;
	//-1 if error 0 if ok
	int position;
	int auxId;
	char auxChar='s';
    if(lista!=NULL && SIZE>0 && recauda!=NULL && SIZER>0)
	    {
    	//ingresa id muestra recaudaciones contribuyente
    	printContribuyentes(lista, SIZER);
	       get_Entero(&auxId,1,"\n id a dar de baja ","\n Error: reingrese id a dar de baja: ",1,9999);

	        if(findRecaudacionByIdContrib(recauda,SIZER, auxId, &position)==-1)
	        {
	            printf("ID inexistente\n");
	        }
	        else
	        {
	        		printRecaudaciones(recauda,SIZER,tipos,SIZET);
	        		printf("Desea dar de baja al contribuyente y sus recaudaciones s/n?\n");

	        		fflush(stdin);

	        		scanf("%c",&auxChar);
	        		if(auxChar=='s'||auxChar=='S')
	        		{
	        			lista[position].isEmpty=1;
	        			recauda[position].isEmpty=1;
	        				        		retorno=0;
	        		}


	        }

	    }
	return retorno;
}
int printAllContrib(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT)
{
	int ret=-1;
	int auxId;
	int position;
	char descripcion[TXT];
	for(int i=0;i<SIZE;i++)
	{

			auxId=lista[i].id;
			if(findRecaudacionByIdContrib(recauda,SIZER,auxId, &position)==0&&recauda[i].isEmpty==0)
			{
				getDescripcionTipo(tipos,SIZET, recauda[position].tipo.idTipo,descripcion);
				printf("***************************Lista de Contribuyentes***************************\n");
				printf("Id contrib.  Nombre Apellido CuilID Rec. Mes Tipo\n ");
				printf("%d       %s     %s       %d   %d      %d  %s \n",lista[i].id,lista[i].nombre
						,lista[i].apellido, lista[i].cuil ,recauda[position].idRec,recauda[position].mes,descripcion);

			}else{
				if(lista[i].isEmpty==0){
				printContribSinSize(lista[i]);}
			}

	}
	return ret;
}
int getImya(Contribuyente lista[], int size, int buscar, char descripcion[])
{
	int ret=-1;
	int i;
	if(lista!=NULL&& SIZE >0 && descripcion!=NULL)
	{
		for(i=0;i<SIZE;i++)
			{
				if(lista[i].id==buscar)
				{
					strcpy(descripcion,lista[i].nombre);
					ret=0;
					break;
				}

			}
	}

	return ret;
}
int getFamiliya(Contribuyente lista[], int size, int buscar, char descripcion[])
{
	int ret=-1;
	int i;
	if(lista!=NULL&& SIZE >0 && descripcion!=NULL)
	{
		for(i=0;i<SIZE;i++)
			{
				if(lista[i].id==buscar)
				{
					strcpy(descripcion,lista[i].apellido);
					ret=0;
					break;
				}

			}
	}

	return ret;
}
void printContribSinSize(Contribuyente lista)
{

	printf("%d     %-20s   %-20s %d   \n",lista.id, lista.nombre,lista.apellido, lista.cuil);
}
int informea(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT)
{//contrb con mas estados refinanciar
	int ret=-1;
	int auxId;
	int position;
	char descripcion[TXT];
	char buffNombre[TXT];
	char buffApellido[TXT];
	for(int i=0;i<SIZER;i++)
		{
			if(strcmp(recauda[i].status,"Refinanciar")==0 && recauda[i].isEmpty==0)
			{
				auxId=recauda[i].idContribuyente;
				if(findContribuyenteById(lista,SIZE,auxId, &position)==0)
				{
					getDescripcionTipo(tipos,SIZET, recauda[i].tipo.idTipo,descripcion);
					getFamiliya(lista,SIZE, lista[position].id,buffApellido);
					getImya(lista,SIZE, lista[position].id,buffNombre);
					printf("***************************Lista de Contribuyentes***************************\n");
					printf("Id   Nombre Apellido Cuil ID Rec. Mes Tipo Importe Estado\n");
					printf("%d    %s   %s        %d     %d    %d  %s   %d   %s\n",lista[position].id, buffNombre,buffApellido ,lista[position].cuil,recauda[i].idRec,
							recauda[i].mes,descripcion, recauda[i].importe,recauda[i].status);

				}
			}
		}

	return ret;
}
int informeb(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT)
{//cantidad saldadas imorte mayor a 1k-imprimir saldados con 1k o mas
	int ret=-1;

	int contSaldados=0;

	for(int i=0;i<SIZER;i++)
	{
		if(strcmp(recauda[i].status,"Saldar")==0 && recauda[i].importe>=1000 && recauda[i].isEmpty==0)
		{
			contSaldados++;
			printRecaudacion(recauda[i],SIZER,tipos,SIZET);
		}
	}

	return ret;
}
int informec(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT)
{//print datos contribuyentes segun tipo recaudacion
	int ret=-1;
	int auxId;
		int position;
		char descripcion[TXT];
		char buffNombre[TXT];
			char buffApellido[TXT];
			char continuar='s';
			do{
			get_Entero(&auxId,1,"\nIngrese tipo de recaudacion a imprimir \n1-ARBA\n2-IIBB\n3-GANANCIAS ","\nIngrese tipo de recaudacion a imprimir \n1-ARBA\n2-IIBB\n3-GANANCIAS\n ",1,3);
			switch(auxId){
case 1:
			for(int i=0;i<SIZER;i++)
		{
			if(strcmp(recauda[i].tipo.descripcion,"ARBA")==0 && recauda[i].isEmpty==0)
			{
				auxId=recauda[i].idContribuyente;
								if(findContribuyenteById(lista,SIZE,auxId, &position)==0)
								{
									getDescripcionTipo(tipos,SIZET, recauda[i].tipo.idTipo,descripcion);
									getFamiliya(lista,SIZE, lista[position].id,buffApellido);
									getImya(lista,SIZE, lista[position].id,buffNombre);
									printf("***************************Lista de Contribuyentes***************************\n");
									printf("Id   Nombre Apellido Cuil ID Rec. Mes Tipo Importe Estado\n");
									printf("%d    %s   %s        %d     %d    %d  %s   %d   %s\n",lista[position].id, buffNombre,buffApellido ,lista[position].cuil,recauda[i].idRec,
											recauda[i].mes,descripcion, recauda[i].importe,recauda[i].status);

								}
			}

		}
			break;
		case 2:

		for(int i=0;i<SIZER;i++)
				{
			if(strcmp(recauda[i].tipo.descripcion,"IIBB")==0 && recauda[i].isEmpty==0)
						{
				auxId=recauda[i].idContribuyente;
												if(findContribuyenteById(lista,SIZE,auxId, &position)==0)
												{
													getDescripcionTipo(tipos,SIZET, recauda[i].tipo.idTipo,descripcion);
													getFamiliya(lista,SIZE, lista[position].id,buffApellido);
													getImya(lista,SIZE, lista[position].id,buffNombre);
													printf("***************************Lista de Contribuyentes***************************\n");
													printf("Id   Nombre Apellido Cuil ID Rec. Mes Tipo Importe Estado\n");
													printf("%d    %s   %s        %d     %d    %d  %s   %d   %s\n",lista[position].id, buffNombre,buffApellido ,lista[position].cuil,recauda[i].idRec,
															recauda[i].mes,descripcion, recauda[i].importe,recauda[i].status);

						}
				}
				}
		break;

		case 3:
			for(int i=0;i<SIZER;i++)
					{
			if(strcmp(recauda[i].tipo.descripcion,"GANANCIAS")==0 && recauda[i].isEmpty==0)
						{
				auxId=recauda[i].idContribuyente;
												if(findContribuyenteById(lista,SIZE,auxId, &position)==0)
												{
													getDescripcionTipo(tipos,SIZET, recauda[i].tipo.idTipo,descripcion);
													getFamiliya(lista,SIZE, lista[position].id,buffApellido);
													getImya(lista,SIZE, lista[position].id,buffNombre);
													printf("***************************Lista de Contribuyentes***************************\n");
													printf("Id   Nombre Apellido Cuil ID Rec. Mes Tipo Importe Estado\n");
													printf("%d    %s   %s        %d     %d    %d  %s   %d   %s\n",lista[position].id, buffNombre,buffApellido ,lista[position].cuil,recauda[i].idRec,
															recauda[i].mes,descripcion, recauda[i].importe,recauda[i].status);

						}ret=0;
		      }

		}
			break;
		default:
			    		printf("No es una opcion valida\n");
			    	}
			    	printf("Desea volver al menu? s/n : \n");
			    				        fflush(stdin);
			    				        scanf("%c", &continuar);
			    }while(continuar=='s');



			  return ret;
}
int informed(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT)
{//nombre y cuil contrib que pagaron en febrero
	int ret=-1;
	int auxId;
	int position;
	char buffNombre[TXT];
				char buffApellido[TXT];
	for(int i=0;i<SIZER;i++)
	{
		if(recauda[i].mes==2 &&  recauda[i].isEmpty==0)
		{
			auxId=recauda[i].idContribuyente;
			if(findContribuyenteById(lista,SIZE,auxId, &position)==0)
							{

								getFamiliya(lista,SIZE, lista[position].id,buffApellido);
								getImya(lista,SIZE, lista[position].id,buffNombre);
								printf("***************************Lista de Contribuyentes***************************\n");
								printf("Nombre Apellido Cuil Mes\n");
								printf("%s   %s        %d     %d  \n",buffNombre,buffApellido ,lista[position].cuil,recauda[i].mes);

							}
		}
		ret=0;
	}




	return ret;
}
int menuInf(Contribuyente lista[], int size, Recaudacion recauda[],int sizeR,Tipo tipos[],int sizeT)
{
	int ret=-1;
	int auxId;
	char continuar='s';
	do{
	get_Entero(&auxId,1,"\nIngrese informe\n1-Informe A\n2-Informe B\n3-Informe C \n4-Informe D\n",
			"\nIngrese informe\n1-Informe A\n2-Informe B\n3-Informe C \n4-Informe D\n",1,4);
	switch(auxId){
	case 1:
		informea(lista,SIZE,recauda,SIZER,tipos,SIZET);
		break;
	case 2:
		informeb(lista,SIZE,recauda,SIZER,tipos,SIZET);
		break;
	case 3:
		informec(lista,SIZE,recauda,SIZER,tipos,SIZET);
		break;

	case 4:
		informed(lista,SIZE,recauda,SIZER,tipos,SIZET);
		break;


	default:
				    		printf("No es una opcion valida\n");
				    	}
				    	printf("Desea volver al menu? s/n : \n");
				    				        fflush(stdin);
				    				        scanf("%c", &continuar);
				    				        ret=0;
	}while(continuar=='s');
	return ret;
}
