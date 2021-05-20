
#define SIZE 5
#define SIZER 5
#define SIZET 3
#define TXT 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "utn.h"
#include "contribuyente.h"
#include "Recaudacion.h"

int main(void) {
	setbuf(stdout,NULL);
		char continuar = 's';
		int opcion;
		int nextId=1000;
		int nextIdRec=100;
		int flagC=0;
		int flagR=0;
		Contribuyente lista[SIZE];
		Recaudacion recauda[SIZER];
		Tipo tipos[SIZET]={
				{1,"ARBA",0},
				{2,"IIBB",0},
				{3,"GANANCIAS",0}
		};
		init(lista,SIZE);
		initRecauda(recauda,SIZER);
		do
			    {
			        get_Entero(&opcion,1,"1-Alta Contribuyente\n2-Modificar Contribuyente\n3-Baja Contribuyente\n4-Recaudacion\n5-Refinanciar recaudacion\n6-Saldar recaudacion\n7-Imprimir contribuyentes\n8-Imprimir recaudacion\n9-Salir\n\nIndique opcion:","\n Error: Ingrese opcion valida:1-Alta Contribuyente\n2-Modificar Contribuyente\n3-Baja Contribuyente\n4-Recaudacion5-Refinanciar recaudacion\n6-Saldar recaudacion\n7-Imprimir contribuyentes\n8-Imprimir recaudacion\n9-Salir\n",1,9);
			        switch(opcion)
			        {
			        case 1:
			        	if(altaContribuyente(lista,&nextId,SIZE)==0){
			        		flagC=1;
			        	}
			        	break;
			        case 2:
			        	if(flagC>0){
			        	modifContrib(lista, SIZE);}
			        	else{
			        		printf("Para modificar un contribuyente debe ingresar uno");
			        	}
			        	break;
			        case 3:
			        	if(flagC>0){
			        	removeContribuyente(lista,SIZE,recauda,SIZER,tipos,SIZET);}
			        	else{
			        		printf("Para modificar un contribuyente debe ingresar uno");
			        		}
			        	break;
			        case 4:
			        	if(altaRecaudacion(recauda,&nextIdRec,SIZER,tipos,SIZET,lista,SIZE)==0)
			        	{
			        		flagR=1;
			        	}
			        	break;
			        case 5:
			        	if(flagR>0){
			        	refinanciar(recauda,SIZER,tipos,SIZET,lista, SIZE);
			        	}
			        	else{
			        		printf("Para refinanciar una recaudacion debe ingresar una");
			        	}
			        	break;
			        case 6:
			        	if(flagR>0){
			        	saldar(recauda,SIZER,tipos,SIZET,lista, SIZE);}
			        	else{
			        		printf("Para saldar una recaudacion debe ingresar una");
			        	}
			            break;
			        case 7:
			        	if(flagR>0&&flagC>0){
			        	printAllContrib(lista, SIZE,recauda,SIZER,tipos,SIZET);}
			        	else{
			        		printf("Para listar contribuyentes debe ingresar alguno");
			        	}
			        	break;
			        case 8:
			        	if(flagR>0&&flagC>0){
			        	printRecPlusCont(recauda,SIZE, tipos,SIZET, lista,SIZE);
			        	}else{
			        		printf("Para listar recaudaciones debe ingresar alguna");
			        	}
			        	break;
			        case 9:
			        	if(flagR>0&&flagC>0){
			        		menuInf(lista,SIZE,recauda,SIZE, tipos,SIZET );
			        	}
			        	break;
			        default:
			            printf("No es una opcion valida\n");
			        }
			        printf("Desea volver al menu? s/n : \n");
			        fflush(stdin);
			        scanf("%c", &continuar);
			       	    }
			    while(continuar =='s');
			    return opcion;
}
