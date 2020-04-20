#include<stdio.h>
#include<string.h> 
#include<windows.h>

struct TPais {
	int numero;
	char pais[80];
	char capital[80];
	char aeropuerto [100];
	char abreviatura[10];
};
struct TPersona{
	char nombre [50];
	char apellidos [80];
	char edad [5];
	char dni [9];
};
int main(){
struct TPais destino [100];
struct TPersona pasajero[10];
	
	FILE * pfichero;
	FILE * pfichero1;
	int tipoCabina,numero,maniana,tarde,noche,nDestinos=0;
	char origen[20],username[20];
	int i,k,j,l,nbilletes,compania,opcion,eleccion,dia1,mes1,anio1,dia2,mes2,anio2,hora, longitud=0,edad;
	int numeroTarjeta, cvc, diacaducidad, mescaducidad,aniocaducidad,equipaje,bultos;
	char nombreTitular[50], apellidosTitular[80],tarifa,destino1, tarifa1;
	float peso;

	do{
	printf("                                                          \n");
	printf("  \\         \\  \\                                       \n");
	printf("   \\         \\  \\                                      \n");	
	printf("    \\_________\\  \\___________________  *               \n");
	printf(" \\                                        *              \n");
	printf("  \\    ____    ____    ____     _____      *             \n");
	printf("      |____|  |____|  |____|   |     |     *              \n");
	printf("  /                            |_____|    *               \n");
	printf(" /                                       *                \n");
	printf("    ________   _____________________  *                   \n");
	printf("   /       /  /                                           \n");
	printf("  /       /  /                                            \n");
	printf(" /       /  /                                             \n");

	
	printf("\nBienvenido al buscador de vuelos DREAM - TRIP\n");
	system ("COLOR 71");
	printf("\nAQUI EMPIEZA SU VIAJE\n");
	system ("PAUSE");
	
	do{
	printf("\nIntroduce un nombre de usuario sin espacios y un maximo de 10 caracteres\n");
	scanf("%s",username); 

	longitud=strlen(username); 

} while(longitud>10);
printf("\nBienvenido o bienvenida %s\n",username); 

    pfichero = fopen("destinos.txt", "r");
    
    if (pfichero == NULL) {
		printf("Error en la apertura del fichero\n");
		return 0;
	} 
	
	printf("\nAqui tiene una lista de los paises a los que puede viajar\n");
	
	while (fscanf(pfichero, "%c", &destino1) != EOF) {
		printf("%c",destino1);
	}
	
	fscanf(pfichero, "%c", destino);

	fclose(pfichero); 
	
	do{
	    printf("\nIntroduzca un numero que corresponda a un pais de la lista anterior:\n");
	    scanf("%d",&numero);
	    if (numero>=1 && numero<=47){
	    	
	    	for(numero=0;numero<47;numero++){
	    		if(destino1==numero){
	    			printf("%c\n",destino); //No nos sale por pantalla
					
				}
			}
	    	
		}
			} while(numero<1 || numero>47);
		
	
	do{
	printf("\nIntroduzca su preferencia horaria para volar\n");
	printf("1-Vuelo maniana\n");
	printf("2-Vuelo tarde\n");
	printf("3-Vuelo noche\n");
	printf("4-Vuelo de madrugada\n");
	scanf("%d",&eleccion);
	}while(eleccion<1 || eleccion>4);
	
	switch(eleccion){
		case 1:printf("Horarios de vuelos durante la maniana, escoja su horario de vuelo\n");
		printf("1-9:50\n");
		printf("2-10:10\n");
		printf("3-11:40\n");
		printf("4-12:25\n");
		scanf("%d", &hora);
		if(hora==1){
			printf("Ha seleccionado el vuelo de las 9:50\n");
		} else if(hora==2){
			printf("Ha seleccionado el vuelo de las 10:10\n");
		} else if(hora==3){
			printf("Ha seleccionado el vuelo de las 11:40\n");
		} else{
			printf("Ha seleccionado el vuelo de las 12:25\n");
		}
		
		break;
		
		case 2:printf("Horarios de vuelos durante la tarde,escoja su horario de vuelo\n");
		printf("1-14:10\n");
		printf("2-16:00\n");
		printf("3-18:25\n");
		printf("4-20:45\n");
		scanf("%d", &hora);
		if(hora==1){
			printf("Ha seleccionado el vuelo de las 14:10\n");
		} else if(hora==2){
			printf("Ha seleccionado el vuelo de las 16:00\n");
		} else if(hora==3){
			printf("Ha seleccionado el vuelo de las 18:25\n");
		} else{
			printf("Ha seleccionado el vuelo de las 20:45\n");
		}
		
		break;
		
		case 3 :printf("Horarios de vuelos durante la noche,escoja su horario de vuelo\n");
		printf("1-21:05\n");
		printf("2-22:15\n");
		printf("3-23:00\n");
		printf("4-00:30\n");
		scanf("%d", &hora);
		if(hora==1){
			printf("Ha seleccionado el vuelo de las 21:05\n");
		} else if(hora==2){
			printf("Ha seleccionado el vuelo de las 22:15\n");
		} else if(hora==3){
			printf("Ha seleccionado el vuelo de las 23:00\n");
		} else{
			printf("Ha seleccionado el vuelo de las 00:30\n");
		}
		break;
		
		case 4 :printf("Horarios de vuelos durante la madrugada,escoja su horario de vuelo\n");
		printf("1-2:25\n");
		printf("2-4:00\n");
		printf("3-5:20\n");
		printf("4-6:45\n");
		scanf("%d", &hora);
		if(hora==1){
			printf("Ha seleccionado el vuelo de las 2:25\n");
		} else if(hora==2){
			printf("Ha seleccionado el vuelo de las 4:00\n");
		} else if(hora==3){
			printf("Ha seleccionado el vuelo de las 5:20\n");
		} else{
			printf("Ha seleccionado el vuelo de las 6:45\n");
		}
		
	}	
	do{
		
	
	printf("\nIntroduzca una opcion\n");
	printf("1-Comprar billete ida y vuelta\n");
	printf("2-Comprar billete solo de ida\n");
	printf("3-Salir del programa\n");
	scanf("%d",&opcion);
} while(opcion<1||opcion>3);
	if(opcion==3){
		printf("Cerrando programa...\n");
		break;	
	} 
	
	switch(opcion){
		case 1:printf("\nIntroduzca el numero de billetes que desea comprar\n");
	    scanf("%d",&nbilletes);
	
	    for(i=0;i<nbilletes;i++){
		printf("\nFecha de ida dd mm aaaa del billete %d\n",i+1);
		scanf("%d %d %d",&dia1, &mes1, &anio1);
		printf("\nFecha de vuelta dd mm aaaa del billete %d\n",i+1);
		scanf("%d %d %d",&dia2,&mes2,&anio2);
		printf("\nIntroduzca lugar de origen del billete %d\n",i+1);
		scanf("%s",&origen);	
	   
        do{
	   	
	   	pfichero1 = fopen("equipaje.txt", "r");
      
      if (pfichero1 == NULL) {
       printf("Error en la apertura. Es posible que el fichero no exista\n");
	  return 0;
	  } 
	
      printf("\nLista de los precios de los bultos a facturar\n");
      
	  while (fscanf(pfichero1, "%c", &tarifa1) != EOF) {
      printf("%c",tarifa1);
      }
     
    fscanf(pfichero1, "%c", tarifa);
    fclose(pfichero1); 
    fflush(stdin);
    
	   	
	   do{
	   	printf("Desea facturar el equipaje del billete %d? Pulse 1- Si, 2- No\n",i+1);
	    scanf("%d",&equipaje);
	    }while(equipaje!=1&&equipaje!=2);
	    
	    if(equipaje==1){
	    
		
		    do{
	    	printf("Introduzca el numero de bultos que desea facturar\n");
	    	
	    	scanf("%d",&bultos);
	    	if(bultos>3){
	    		printf("No es posible facturar más de tres bultos por persona\n");
			}
	    	}while(bultos>3);
	    
		  

	    	for(k=0;k<bultos;k++){
	    		printf("Introduzca el peso en kg del bulto %d: ",k+1);
	    		scanf("%f",&peso);
	    	if(peso>32)
	    		printf("Lo sentimos, el bulto %d no puede ser transpotado por sobrepeso\n",k+1);
	    	else 
	    	printf("El bulto %d sera transportado\n",k+1);
	     	}
		
	   
			
	
		}else if(equipaje==2){
			printf("\nUsted ha elegido no facturar\n");
		} else{
			printf ("\nError. La opcion no es correcta\n");
		}
} while(equipaje>=3);
}
	    
		break;
		
		case 2: printf("\nIntroduzca el numero de billetes que desea comprar\n");
	    scanf("%d",&nbilletes);
	    for(i=0;i<nbilletes;i++){
		printf("\nFecha de ida dd mm aaaa del billete %d\n",i+1);
		scanf("%d %d %d",&dia1, &mes1, &anio1);
		printf("\nIntroduzca lugar de origen del billete %d\n",i+1);
		scanf("%s",&origen);
		 do{
		 	
	   	
	   	pfichero1 = fopen("equipaje.txt", "r");
      
      if (pfichero1 == NULL) {
       printf("Error en la apertura. Es posible que el fichero no exista\n");
	  return 0;
	  } 
	
      printf("\nLista de los precios de los bultos a facturar\n");
      
	  while (fscanf(pfichero1, "%c", &tarifa1) != EOF) {
      printf("%c",tarifa1);
      }
     
    fscanf(pfichero1, "%c", tarifa);
    fclose(pfichero1); 
    fflush(stdin);
    
	   	
	    do{
		printf("Desea facturar el equipaje del billete %d? Pulse 1- Si, 2- No\n",i+1);
	    scanf("%d",&equipaje);
	} while(equipaje!=1&&equipaje!=2);
	
	    if(equipaje==1){
	    	
	    	
	    	do{
	    	printf("Introduzca el numero de bultos que desea facturar\n");
	    	scanf("%d",&bultos);
	    	if(bultos>3){
	    		printf("No es posible facturar mas de tres bultos por persona\n");
			}
	    	}while(bultos>3);
	    
	    	
		
	    	for(k=0;k<bultos;k++){
	    		printf("Introduzca el peso en kg del bulto %d: ",k+1);
	    		scanf("%f",&peso);
	    	if(peso>32)
	    		printf("Lo sentimos, el bulto %d no puede ser transpotado por sobrepeso\n",k+1);
	    	else 
	    	printf("El bulto %d sera transportado\n",k+1);
	       
		}
			
		} else if(equipaje==2){
			printf("\nUsted ha elegido no facturar su equipaje\n");
		} else{
			printf ("\nError. La opcion no es correcta\n");
		}
    } while(equipaje>=3);
		
	}
		break;
		
		default: 
		printf("\nOpcion incorrecta\n");
		break;
}
    

printf("\nElija la compania con la que desea viajar\n");
printf("1-Iberia\t  2-Air Europa\t  3-Rayaner\t  4-Vueling\t  5-Airlines\t  6-Emirates\t  7-British AirWays\t  8-EasyJet\t  9-KLM\t  10-Alitalia\n");
scanf("%d",&compania);
if (compania<=10){
	for(i=0;i<nbilletes;i++){
	
	printf("\nSeleccione el tipo de cabina para el billete %d\n",i+1);
	printf("1- Clase turista\n");
	printf("2- Business\n");
	scanf("%d",&tipoCabina);

}

} else 
printf("El numero introducido no pertenece a ninguna compania\n");
fflush(stdin); 

if (tipoCabina==1||tipoCabina==2){
	
for(j=0;j<nbilletes;j++){

	printf("\nIntroduzca el nombre del pasajero %d: ",j+1);
 	scanf("%s",&pasajero[j].nombre);
 	fflush(stdin);
 	
 	printf("\nIntroduzca los apellidos del pasajero %d: ",j+1);
 	gets(pasajero[j].apellidos);
 	fflush(stdin);
 
 	printf("\nIntroduzca la edad del pasajero %d: ",j+1);
 	scanf("%s",&pasajero[j].edad);
 
 	printf("\nIntroduzca el dni del pasajero %d: ",j+1);
 	scanf("%s",&pasajero[j].dni);
 	fflush(stdin);
 	
 }
 
    pfichero = fopen("pasajeros.txt", "w");
    
    if (pfichero == NULL) {
		printf("No se ha podido crear el fichero\n");
		return 0;
	}
	
    for (j=0; j<nbilletes; j++) {
       	
       	fprintf(pfichero, "%s %s %s %s\n", &pasajero[j].nombre,&pasajero[j].apellidos ,&pasajero[j].edad,&pasajero[j].dni);
	}
	

	fclose(pfichero);
	//En el fichero se ecnuentran sus billetes 

        printf("\nLos datos introducido a continuacion son personales e intransferibles\n");
        printf("\nIntroduzca el nombre del titular de la tarjeta de credito:" );
		scanf("%s",&nombreTitular);
		fflush(stdin);
		printf("\nIntroduzca los apellidos del titular de la tarjeta de credito: ");
		gets(apellidosTitular);
		printf("\nIntroduzca el numero de la tarjeta de credito: ");
		scanf("%d", &numeroTarjeta);
		printf("\nIntroduzca el CVC (codigo de verificacion) de la tarjeta: ");
		scanf("%d",&cvc);
		printf("\nIntroduzca la fecha de caducidad dd mm aaaa de la tarjeta: ");
		scanf("%d %d %d",&diacaducidad, &mescaducidad, &aniocaducidad);
	
}
	else {
	printf("La opcion que usted ha elegido no es una opcion valida\n");
}
} while(opcion==1||opcion==2);

return 0;
	


}
	
