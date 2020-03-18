#include<stdio.h>
#include<string.h> 

int main(){
	int tipoCabina;
	char destino [20],origen[20];
	char username[20];
	int compania,opcion,fecha1,fecha2, longitud=0;
	
	printf("Bienvenido al buscador de vuelos DREAM - TRIP\n");
	do{
	printf("Introduce un nombre de usuario sin espacios y un maximo de 10 caracteres\n");
	scanf("%s",username); 

	longitud=strlen(username); 

} while(longitud>10);
printf("Bienvenido o bienvenida %s\n",username); 
	
	printf("Introduzca un destino de Europa\n");
	scanf("%s",&destino);
	
	printf("Introduzca una opcion\n");
	printf("1-Comprar billete ida y vuelta\n");
	printf("2-Comprar billete solo de ida\n");
	printf("3-Salir del programa\n");
	scanf("%d",&opcion);

	switch(opcion){
		case 1:printf("Fecha de ida\n");
		scanf("%d",&fecha1);
		printf("Fecha de vuelta\n");
		scanf("%d",&fecha2);
		break;
		
		case 2: printf("Fecha de ida\n");
		scanf("%d",&fecha1);
		printf("Introduzca lugar de origen\n");
		scanf("%s",&origen);
		break;
		
		default: 
		printf("Opcion incorrecta\n");
}
printf("\nElija la compania con la que desea viajar\n");
printf("1-Iberia\t  2-Air Europa\t  3-Rayaner\t  4-Vueling\t  5-Airlines\t  6-Emirates\t  7-British AirWays\n");
scanf("%d",&compania);
if (compania<=7){
	printf("Seleccione el tipo de cabina\n");
	printf("1- Clase turista\n");
	printf("2- Business\n");
	scanf("%d",&tipoCabina);


} else 
printf("El numero introducido no pertenece a ninguna compania\n");
  
   
return 0;
	


}
	
	
		

		

	

