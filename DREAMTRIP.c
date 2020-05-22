#include<stdio.h>
#include<string.h>
#include<windows.h>

struct TPersona{
 char nombre [50];
 char apellidos [80];
 int dni;
 char letra;
 char correo[50];
};

//Inicialización de las funciones.

int horarioManiana();
int horarioTarde();
int horarioNoche ();
int horarioMadrugada();
float costeBilletes(int paisElegido,int nnbilletes);
float companiadeVuelo(int empresa,int numbilletes);
int eliminarCaracteres(char str[]);
char letraDNI(int dni);


int main(){
struct TPersona pasajero[10];
 
 FILE * pfichero;
 FILE * pfichero1;
 FILE * pfichero2;
 int tipoCabina,numero,maniana,tarde,noche,A,B,longitudCorreo, metodopago, tipoTarjeta, telefono,numero1,contador=1,nnbilletes,paisElegido;
 char origen[20],username[20],usernameOriginal[20], correo[30], direccion[100], clave[20],clave1[20],regreso,letraPiso[3],localidad[50],pais[50];
 int i,k,j,l,m,n,s,p,nbilletes,compania,opcion,eleccion,dia1,mes1,anio1,dia2,mes2,anio2,hora, longitud=0,edad,factura;
 int cvc, mescaducidad,aniocaducidad,equipaje,bultos,portal,codigoPostal;
 char nombreTitular[50], apellidosTitular[80],tarifa,destino1, tarifa1, pasajeros1;
 float peso,precio,coste,descuento,precioOriginal,precioRegreso;
 long numeroTarjeta;
 
 do{
 printf("\n             BIENVENIDO AL BUSCADOR DE VUELOS DREAM - TRIP\n");
 printf("                                                                          \n");
 printf("             \\              \\  \\                                       \n");
 printf("              \\              \\  \\                                      \n"); 
 printf("               \\______________\\  \\____________ *   *                   \n");
 printf("            \\                                          *                 \n");
 printf("             \\    ____    ____    ____        _____      *               \n");
 printf("                 |____|  |____|  |____|      |     |      *               \n");
 printf("             /                               |_____|     *                \n");
 printf("            /                                          *                  \n");
 printf("               _______________   ________________ *  *                    \n");
 printf("              /              /  /                                         \n");
 printf("             /              /  /                                          \n");
 printf("            /              /  /                                           \n");
 
 
 

 system ("COLOR 71");
 printf("\n                          AQUI EMPIEZA SU VIAJE\n");
 
 
 //Menú de la aplicación.
 
 do{ 
 printf("\n\nMENU DE OPCIONES\n");
 printf("1-Comprar billete ida y vuelta\n");
 printf("2-Comprar billete solo de ida\n");
 printf("3-Salir del programa\n");
 scanf("%d",&opcion);
 if(opcion==1){
 	printf("\nHa seleccionado la opcion comprar billete de ida y vuelta\n");
 } else if(opcion==2){
 	printf("\nHa seleccionado la opcion comprar billete solo de ida\n");
 }
} while(opcion<1||opcion>3);

 if(opcion==3){
  printf("\nCerrando programa...\n");
  break; 
 }
 
 do{
 printf("\nIntroduce un nombre de usuario sin espacios y un maximo de 10 caracteres\n");
 scanf("%s",username);
 longitud=strlen(username);
  } while(longitud>10);

strcpy(usernameOriginal,username);
if(eliminarCaracteres(username)==1){
    printf("\nNombre de usuario %s incorecto\n",usernameOriginal);
    printf("\nSolo se permite un nombre de usuario con letras, se cambia a %s\n",username);
    printf("\nBienvenid@ %s\n",username);
    }else{
	printf("\nBienvenid@ %s, nombre de usuario correcto\n",usernameOriginal);
    }    


 
 pfichero2 = fopen("pasajeros.txt", "a");
 if(opcion==1||opcion==2){
  printf("\nIntroduzca el lugar de origen del vuelo: ");
  scanf("%s",origen);
  fprintf(pfichero2,"BILLETE/S DE IDA\n");
  fprintf(pfichero2,"----------------\n");
  fprintf(pfichero2, "ORIGEN: %s\n",origen);
  fclose(pfichero2);
  do{
  printf("\nIntroduzca el numero de billetes que desea comprar: ");
  scanf("%d",&nbilletes);
  if(nbilletes>10){
  	printf("\nNo se permiten comprar mas de 10 billetes en el mismo proceso de compra\n");
  }
}while(nbilletes>10);

//Apertura del fichero con nuestra lista de destinos.

  pfichero = fopen("destinos.txt", "r");
   
    if (pfichero == NULL) {
  printf("Error en la apertura del fichero\n");
  return 0;
    }
 printf("\nLista de los paises a los que puede viajar a la IDA\n");
 
 while (fscanf(pfichero, "%c", &destino1) != EOF) {
  printf("%c",destino1);
  }
 fclose(pfichero);
 
 do{
     printf("\nIntroduzca un numero que corresponda a un pais de la lista anterior: ");
     scanf("%d",&numero);
     precio+=costeBilletes(numero,nbilletes);
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
   } while(numero<1 || numero>47);
   
   
 pfichero2 = fopen("pasajeros.txt", "a");
     if(numero==1){
     fprintf(pfichero2, "DESTINO: Albania,Tirana\n");	
     fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional Madre Teresa (TIA)\n");
	 } else if(numero==2){
	 	fprintf(pfichero2, "DESTINO: Alemania, Berlin\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Berlin-Tegel (TXL)\n");
	 } else if(numero==3){
	 	fprintf(pfichero2, "DESTINO: Andorra, Andorra la Vieja\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Andorra-La Seu (LEU)\n");
	 } else if(numero==4){
	 	fprintf(pfichero2, "DESTINO: Armenia, Erevan\n");
	 	fprintf(pfichero2,"AATERRIZAJE EN: Aeropuerto Internacional El Eden (AXM)\n");
	 } else if (numero==5){
	 	fprintf(pfichero2, "DESTINO: Austria, Viena\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Viena (VIE)\n");
	 } else if(numero==6){
	 	fprintf(pfichero2, "DESTINO: Azerbaiyan, Baku\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional Heydar Aliyev (GYD)\n");
	 } else if(numero==7){
	 	fprintf(pfichero2, "DESTINO: Belgica, Bruselas\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Bruselas-Zaventem (BRU)\n");
	 } else if(numero==8){
	 	fprintf(pfichero2, "DESTINO: Bielorrusia, Minsk\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Minsk (MSQ)\n");
	 } else if(numero==9){
	 	fprintf(pfichero2, "DESTINO: Bosnia, Sarajevo\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Banja Luka-Zaluzani (LQBZ)\n");
	 } else if(numero==10){
	 	fprintf(pfichero2, "DESTINO: Bulgaria, Sofia\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Sofia (SOF)\n");
	 } else if(numero==11){
	    fprintf(pfichero2, "DESTINO: Chipre, Nicosia\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Larnaca (LCA)\n");
	 } else if(numero==12){
	 	fprintf(pfichero2, "DESTINO: Ciudad del Vaticano, Ciudad del Vaticano\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional Leonardo da Vinci (FCO)\n");
	 } else if(numero==13){
	 	fprintf(pfichero2, "DESTINO: Croacia, Zagreb\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Zagreb (ZAG)\n");
	 } else if(numero==14){
	 	fprintf(pfichero2, "DESTINO: Dinamarca, Copenhague\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Copenhague-Kastrup (CPH)\n");
	 } else if(numero==15){
	 	fprintf(pfichero2, "DESTINO: Eslovaquia, Bratislava\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Milan Rastislav Stefanik (BTS)\n");
	 } else if(numero==16){
	 	fprintf(pfichero2, "DESTINO: Eslovenia, Liubliana\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Liubliana (LJU)\n");
	 } else if(numero==17){
	 	fprintf(pfichero2, "DESTINO: Espanya, Madrid\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Adolfo Suarez Madrid-Barajas (MAD)\n");
	 } else if(numero==18){
	 	fprintf(pfichero2, "DESTINO: Estonia, Tallin\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Tallin (TLL)\n");
	 } else if(numero==19){
	 	fprintf(pfichero2, "DESTINO: Rusia, Moscu\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Moscu-Domodedovo (DME)\n");
	 } else if(numero==20){
	 	fprintf(pfichero2, "DESTINO: Finlandia, Helsinkin\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Helsinki-Vantaa (HEL)\n");
	 } else if(numero==21){
	 	fprintf(pfichero2, "DESTINO: Francia, Paris\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Paris-Orly (ORY)\n");
	 } else if(numero==22){
	 	fprintf(pfichero2, "DESTINO: Georgia, Tiflis\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Tiflis (TBS)\n");
	 } else if(numero==23){
	 	fprintf(pfichero2, "DESTINO: Grecia, Atenas\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional Eleftherios Venizelos (ATH) \n");
	 } else if(numero==24){
	 	fprintf(pfichero2, "DESTINO: Hungria, Budapest\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Budapest-Ferihegy (BUD)\n");
	 } else if(numero==25){
	 	fprintf(pfichero2, "DESTINO: Irlanda, Dublin\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Dublin (DUB)\n");
	 } else if(numero==26){
	 	fprintf(pfichero2, "DESTINO: Islandia, Reikiavik\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Keflavik (KEF)\n");
	 } else if(numero==27){
	 	fprintf(pfichero2, "DESTINO: Italia, Roma\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Roma-Fiumicino (FCO)\n");
	 } else if (numero==28){
	 	fprintf(pfichero2, "DESTINO: Kazajistan, Astana\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Almaty (ALA)\n");
	 } else if(numero==29){
	 	fprintf(pfichero2, "DESTINO: Letonia, Riga\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Riga (RIX)\n");
	 } else if(numero==30){
	 	fprintf(pfichero2, "DESTINO: Lituania, Vilna\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Vilna (VNO)\n");
	 } else if(numero==31){
	 	fprintf(pfichero2, "DESTINO: Luxemburgo, Luxemburgo\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Luxemburgo (LUX)\n");
	 } else if(numero==32){
	 	fprintf(pfichero2, "DESTINO: Macedonia del Norte, Skopie\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Skopje (SKP)\n");
	 } else if(numero==33){
	 	fprintf(pfichero2, "DESTINO: Malta, La Valeta\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Malta (MLA)\n");
	 } else if(numero==34){
	 	fprintf(pfichero2, "DESTINO: Moldova, Chisinau\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Chisinau (KIV)\n");
	 } else if(numero==35){
	    fprintf(pfichero2, "DESTINO: Montenegro, Podgorica\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Podgorica (TGD)\n");	
	 } else if(numero==36){
	 	fprintf(pfichero2, "DESTINO: Noruega, Oslo\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Oslo-Gardermoen (OSL)\n");
	 } else if(numero==37){
	 	fprintf(pfichero2, "DESTINO: Paises Bajos, Amsterdam\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Schiphol (AMS)\n");
	 } else if(numero==38){
	 	fprintf(pfichero2, "DESTINO: Polonia, Varsovia\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Breslavia-Copernico (WRO)\n");
	 } else if(numero==39){
	 	fprintf(pfichero2, "DESTINO: Portugal, Lisboa\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Portela (LIS)\n");
	 } else if(numero==40){
	 	fprintf(pfichero2, "DESTINO: Reino Unido, Londres\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Londres-Heathrow (LHR)\n");
	 } else if(numero==41){
	 	fprintf(pfichero2, "DESTINO: Republica Checa, Praga\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Praga (PRG)\n");
	 } else if(numero==42){
	 	fprintf(pfichero2, "DESTINO: Rumania, Bucarest\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional Henri Coanda (OTP)\n");
	 } else if(numero==43){
	 	fprintf(pfichero2, "DESTINO: San Marino, San Marino\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional Federico Fellini (RMI)\n");
	 } else if(numero==44){
	 	fprintf(pfichero2, "DESTINO: Serbia, Belgrado\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Belgrado-Nikola Tesla (BEG)\n");
	 } else if(numero==45){
	 	fprintf(pfichero2, "DESTINO: Suecia, Estocolmo\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto de Estocolmo-Arlanda (ARN)\n");
	 } else if(numero==46){
	 	fprintf(pfichero2, "DESTINO: Suiza, Berna\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Ginebra (GVA)\n");
	 } else if(numero==47){
	 	fprintf(pfichero2, "DESTINO: Ucrania, Kiev\n");
	 	fprintf(pfichero2,"ATERRIZAJE EN: Aeropuerto Internacional de Boryspil (KBP)\n");
	 }
	 
	fclose(pfichero2);
 	precioOriginal=precio;
 	
//Tarifas segun la edad de los pasajeros.
 	
    for(n=0;n<nbilletes;n++){
  	printf("\nEdad del pasajero %d:\t",n+1);
  	scanf("%d",&edad);
  
  if (edad>=0 &&edad <=3){
  	printf("\nSe aplica la Tarifa Baby\n");
  	printf("\nSe aplica un descuento del 50 por ciento\n");
  	descuento=(precioOriginal/nbilletes)*0.5;
  	precio -= descuento;
  	 printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }else if (edad>=4 && edad<=12){
  	printf("\nSe aplica la Tarifa Children\n");
  	printf("\nSe aplica un descuento del 20 por ciento\n");
  	descuento=(precioOriginal/nbilletes)*0.2;
  	precio-= descuento;
  	printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }else if(edad>=13 && edad<=65){
  	printf("\nNo se aplican descuentos\n");
  	printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }else{
  	printf("\nSe aplica la Tarifa Senior\n");
  	printf("\nSe aplica un descuento del 30 por ciento\n");
  	descuento=(precioOriginal/nbilletes)*0.3;
  	precio -= descuento;
  	printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }
}
 
 //Seleccion de horarios.
 
 do{ 
 printf("\nIntroduzca su preferencia horaria para su vuelo de ida\n");
 printf("1-Vuelo maniana\n");
 printf("2-Vuelo tarde\n");
 printf("3-Vuelo noche\n");
 printf("4-Vuelo de madrugada\n");
 scanf("%d",&eleccion);
 printf("\nUsted ha elegido la opcion %d\n",eleccion);
} while(eleccion<1 ||eleccion>4);
 
 switch(eleccion){
  do{ 
  case 1:printf("\nHorarios de vuelos durante la maniana, escoja su horario de vuelo\n");
  
  hora=horarioManiana();
  
  if(hora==1){
   precio+=(16*nbilletes);
   printf("\nHa seleccionado el vuelo de las 8:50, suplemento de 16 euros por billete\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  } else if(hora==2){
   precio+=(10*nbilletes);
   printf("\nHa seleccionado el vuelo de las 10:35, suplemento de 10 euros por billete\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  } else if(hora==3){
   precio+=(3*nbilletes);
   printf("\nHa seleccionado el vuelo de las 11:40, suplemento de 8 euros por billete\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  } else if (hora==4){
   printf("\nHa seleccionado el vuelo de las 12:25, no supone ningun suplemento\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }
  else{
   printf("\nOpcion no disponible\n");
  }
 }while(hora<1||hora>4);
  
  break;
  
  do{
  	
  case 2:printf("\nHorarios de vuelos durante la tarde,escoja su horario de vuelo\n");
  
  hora=horarioTarde();
  
  if(hora==1){
   printf("\nHa seleccionado el vuelo de las 14:10, no supone ningun suplemento\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  } else if(hora==2){
   precio+=(7*nbilletes);
   printf("\nHa seleccionado el vuelo de las 16:00, suplemento de 7 euros por billete\n\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  } else if(hora==3){
   precio+=(5*nbilletes);
   printf("\nHa seleccionado el vuelo de las 18:25, suplemento de 5 euros por billete\n\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  } else if(hora==4){
   printf("\nHa seleccionado el vuelo de las 20:45, no supone ningun suplemento\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }
  else{
   printf("\nOpcion no disponible\n");
  }
 }while(hora<1||hora>4);
  break;
  
  do{
  	
  case 3:printf("\nHorarios de vuelos durante la noche,escoja su horario de vuelo\n");
  hora=horarioNoche();
  
  if(hora==1){
   printf("\nHa seleccionado el vuelo de las 21:05, no supone ningun suplemento\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }else if(hora==2){
   printf("\nHa seleccionado el vuelo de las 22:15, no supone ningun suplemento\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }else if(hora==3){
   precio+=(4*nbilletes);
   printf("\nHa seleccionado el vuelo de las 23:00, suplemento de 4 euros por billete\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }else if(hora==4){
   precio+=(3*nbilletes);
   printf("\nHa seleccionado el vuelo de las 00:30, suplemento de 3 euros por billete\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }
  else{
   printf("\nOpcion no disponible\n");
  }
 } while(hora<1||hora>4);
  break;
  
  do{
  case 4 :printf("\nHorarios de vuelos durante la madrugada,escoja su horario de vuelo\n");
  
  hora=horarioMadrugada();
  
  if(hora==1){
   printf("\nHa seleccionado el vuelo de las 2:25, no supone ningun suplemento\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  } else if(hora==2){
   precio+=(10*nbilletes);
   printf("\nHa seleccionado el vuelo de las 4:00, suplemento de 10 euros por billete\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  } else if(hora==3){
   precio+=(20*nbilletes);
   printf("\nHa seleccionado el vuelo de las 5:20, suplemento de 20 euros por billete\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  } else if(hora==4){
   precio+=(26*nbilletes);
   printf("\nHa seleccionado el vuelo de las 6:45, suplemento de 26 euros por billete\n");
   printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
  }
  else{
   printf("\nOpcion no disponible\n");
  }
  }while(hora<1||hora>4);
 }
 
 }
 
 
  switch(opcion){
  	
  case 1:
  do{
  printf("\nFecha de ida dd mm aaaa\n");
  scanf("%d %d %d",&dia1, &mes1, &anio1);
  if(anio1<2020){
  	printf("\nFecha introducida incorrecta\n");
  }
  }while(anio1<2020);
  pfichero2 = fopen("pasajeros.txt", "a");
  fprintf(pfichero2,"FECHA DE IDA: %d %d %d\n",dia1,mes1,anio1);
  fclose(pfichero2);
  
//Equipaje y sus tarifas.
  
    for(i=0;i<nbilletes;i++){
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
   
     printf("\nSolo se efectua el cobro del equipaje a la IDA\n");
     
    do{
    printf("\nDesea facturar el equipaje del billete %d? Pulse 1- Si, 2- No\n",i+1);
    scanf("%d",&equipaje);
    }while(equipaje!=1&&equipaje!=2);
    
    if(equipaje==1){
      
      do{
      printf("\nIntroduzca el numero de bultos que desea facturar\n");
      scanf("%d",&bultos);
      
       if(bultos>3){
       printf("\nLe recordamos que no es posible facturar mas de 3 bultos por persona\n");
        }
    }while(bultos>3);
    
         printf("\nPor seguridad la siguiente informacion debe coincidir con el peso de su equipaje antes del embarque\n");
    
      for(k=0;k<bultos;k++){
       printf("Introduzca el peso en kg del bulto %d: ",k+1);
       scanf("%f",&peso);
       if(peso>=10&&peso<15){
       precio+=20; 
        }
       if(peso>=15&&peso<20){
       precio+=25;
        }
       if(peso>=20&&peso<=30){
       precio+=30; 
        }
       printf("\nBillete de ida: %.2f euros actualmente\n",precio);
      if(peso>30)
       printf("\nLo sentimos, el bulto %d no puede ser transpotado por sobrepeso\n",k+1);
      else
      printf("\nEl bulto %d sera transportado\n",k+1);
    
        }
    }else if(equipaje==2){
     printf("\nUsted ha elegido no facturar\n");
    }else{
    printf ("\nError. La opcion no es correcta\n");
    }
    }while(equipaje>=3);
}

//Viaje de regreso.
   do{
  printf("\nFecha de vuelta dd mm aaaa\n");
  scanf("%d %d %d",&dia2,&mes2,&anio2); 
  if(anio2<2020 ||anio2>2021){
  	printf("\nFecha no disponible\n");
  }
}while(anio2<2020 ||anio2>2021);
  pfichero2 = fopen("pasajeros.txt", "a");
  fprintf(pfichero2,"\nBILLETE/S DE VUELTA\n");
  fprintf(pfichero2,"----------------\n");
  fprintf(pfichero2, "DESTINO: %s\n",origen);
  fprintf(pfichero2,"FECHA DE VUELTA: %d %d %d\n",dia2,mes2,anio2);
  fclose(pfichero2);
   do{
  printf("\nOpciones disponibles para su REGRESO a %s el %d %d %d, escoja una\n",origen,dia2,mes2,anio2);
  printf("A- Iberia, 8:35h\n");
  printf("B- Rayaner, 11:20h\n");
  printf("C- KLM, 13:15h\n");
  printf("D- Vueling, 16:55h\n");
  printf("E- Air Europa, 18:17h\n");
  printf("F- Iberia, 20:50h\n");
  printf("G- easyJet, 21:30h\n");
  printf("H- KLM, 22:22h\n");
  printf("I- Rayaner, 00:41h\n");
  printf("J- Air Europa, 02:36h\n");
  printf("K- Emirates, 04:07h\n");
  printf("L- easyJet, 06:19h\n");
  printf("M- British Airways 07:00h\n");
  printf("N- Alitalia, 07:49h\n");
  fflush(stdin);
  scanf("%c",&regreso);
  printf("\nUsted ha escogido de la opcion %c\n",regreso);
  
  if(regreso>='A' && regreso<='E'){
  	precioRegreso+=nbilletes*65;
  	printf("\nEl vuelo a %s el %d %d %d tiene un coste de 65 euros por persona\n",origen,dia2,mes2,anio2);
  	printf("\nBillete/s de vuelta: %.2f euros\n",precioRegreso);
  }else if(regreso>'E' && regreso<='I'){
  	precioRegreso+=nbilletes*77;
  	printf("\nEl vuelo a %s el %d %d %d tiene un coste de 77 euros por persona\n",origen,dia2,mes2,anio2);
  	printf("\nBillete/s de vuelta: %.2f euros\n",precioRegreso);
  }else if(regreso>'I' && regreso<='N'){
  	precioRegreso+=nbilletes*88;
  	printf("\nEl vuelo a %s el %d %d %d tiene un coste de 88 euros por persona\n",origen,dia2,mes2,anio2);
  	printf("\nBillete/s de vuelta: %.2f euros\n",precioRegreso);
  }else{
  	printf("\nOpcion no valida, vuelva a seleccionar una opcion\n");
    }
}while(regreso<'A'||regreso>'N');

for(i=0;i<nbilletes;i++){
 
 printf("\nSeleccione el tipo de cabina para el REGRESO del billete %d\n",i+1);
 printf("1- Clase turista\n");
 printf("2- Business\n");
 scanf("%d",&tipoCabina);
 if(tipoCabina==1){
  printf("\nVuelo en clase turista, no supone ningun suplemento\n");
  printf("\nBillete/s de vuelta: %.2f euros actualmente\n",precioRegreso);
 } else if(tipoCabina==2){
  precioRegreso+=60;
  printf("\nVuelo en business, suplemento de 60 euros\n");
  printf("\nBillete/s de vuelta: %.2f euros actualmente\n",precioRegreso);
 }
} 

  break;

//Seleccion de fecha para solo ida.

  case 2: 
  do{
  printf("\nFecha de ida dd mm aaaa\n");
  scanf("%d %d %d",&dia1, &mes1, &anio1);
  if(anio1<2020){
  	printf("\nFecha introducida incorrecta\n");
  }
  }while(anio1<2020);
  pfichero2 = fopen("pasajeros.txt", "a");
  fprintf(pfichero2,"FECHA DE IDA: %d %d %d\n",dia1,mes1,anio1);
  fclose(pfichero2);
  for(i=0;i<nbilletes;i++){
   do{
    
     
     pfichero1 = fopen("equipaje.txt", "r");
     
      if (pfichero1 == NULL) {
       printf("\nError en la apertura. Es posible que el fichero no exista\n");
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
     printf("\nDesea facturar el equipaje del billete %d? Pulse 1- Si, 2- No\n",i+1);
     scanf("%d",&equipaje);
     }while(equipaje!=1&&equipaje!=2);
   
     if(equipaje==1){
      do{
      printf("\nIntroduzca el numero de bultos que desea facturar\n");
      scanf("%d",&bultos);
       if(bultos>3){
       printf("\nLe recordamos que no es posible facturar mas de 3 bultos por persona\n");
       }
       }while(bultos>3);
    
         printf("\nPor seguridad la siguiente informacion debe coincidir con el peso de su equipaje antes del embarque\n");
      for(k=0;k<bultos;k++){
       printf("\nIntroduzca el peso en kg del bulto %d: ",k+1);
       scanf("%f",&peso);
       if(peso>=10&&peso<15){
       precio+=20; 
        }
       if(peso>=15&&peso<20){
       precio+=25;
        }
       if(peso>=20&&peso<=30){
       precio+=30; 
        }
       printf("\nBilletes de ida: %.2f euros actualmente\n",precio);
      if(peso>30)
       printf("\nLo sentimos, el bulto %d no puede ser transpotado por sobrepeso\n",k+1);
      else
      printf("\nEl bulto %d sera transportado\n",k+1);
    }   
   
   
    }else if(equipaje==2){
   printf("\nUsted ha elegido no facturar su equipaje\n");
    }else{
   printf ("\nError. La opcion no es correcta\n");
    }
    }while(equipaje>=3);
  }
  break;
  
  default:
  printf("\nOpcion incorrecta\n");
  break;
}
   
do{
printf("\nElija la compania aerea con la que desea viajar a la IDA\n");
printf("1-Iberia\t 2-Air Europa\t 3-Rayaner\t 4-Vueling\n 5-American Airlines\t 6-Emirates\t 7-British AirWays\t 8-easyJet\t 9-KLM\t 10-Alitalia\n");
scanf("%d",&compania);
precio+=companiadeVuelo(compania,nbilletes);
printf("\nBillete/s de ida: %.2f euros actualmente\n", precio);

} while(compania<1||compania>10);
if (compania<=10){
 for(i=0;i<nbilletes;i++){
 
 printf("\nSeleccione el tipo de cabina para la IDA del billete %d\n",i+1);
 printf("1- Clase turista\n");
 printf("2- Business\n");
 scanf("%d",&tipoCabina);
 if(tipoCabina==1){
  printf("\nVuelo en clase turista, no supone ningun suplemento\n");
  printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
 }else if(tipoCabina==2){
  precio+=60;
  printf("\nVuelo en business, suplemento de 60 euros\n");
  printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
 }
 }  
 
//Precio total.
 
    if(opcion==1){
	printf("\n                       Resumen de su compra\n");
	printf("\n                       --------------------\n");
	printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
	printf("\nBillete/s de vuelta: %.2f euros actualmente\n",precioRegreso);
	printf("\nEl precio total a pagar es de %.2f euros\n",precio+precioRegreso);
    } else if(opcion==2){
    printf("\n                       Resumen de su compra\n");
    printf("\n                       --------------------\n");
	printf("\nBillete/s de ida: %.2f euros actualmente\n",precio);
	printf("\nEl precio total a pagar es de %.2f euros\n",precio);
    }
	
}else
printf("El numero introducido no pertenece a ninguna compania\n");
fflush(stdin);
if (tipoCabina==1||tipoCabina==2){
 
 //Datos de los pasajeros.
 printf("\n                            Datos\n");
 printf("\n                            -----\n");
  for(j=0;j<nbilletes;j++){
  printf("\nIntroduzca el nombre del pasajero %d: ",j+1);
  scanf("%s",pasajero[j].nombre);
  fflush(stdin);
  
  printf("\nIntroduzca los apellidos del pasajero %d: ",j+1);
  gets(pasajero[j].apellidos);
  fflush(stdin);
  
  printf("\nIntroduzca el DNI sin letra del pasajero %d: ",j+1);
  scanf("%d",&pasajero[j].dni);
  fflush(stdin);
  if(pasajero[j].dni>0&&pasajero[j].dni<99999999){
  	pasajero[j].letra=letraDNI(pasajero[j].dni);
  	printf("\nSu DNI es %d y la letra que le corresponde es la %c\n",pasajero[j].dni,letraDNI(pasajero[j].dni));
    } else{
  	printf ("El DNI no es correcto\n");
    }
  
 }
 
//Guardamos los datos de los pasajeros en un fichero. 
 
    pfichero = fopen("pasajeros.txt", "a");
   
    if (pfichero == NULL) {
    printf("\nNo se ha podido crear el fichero\n");
    return 0;
 }
 
    fprintf(pfichero,"\nPASAJEROS\n");
	fprintf(pfichero,"----------------\n");
    for (j=0; j<nbilletes; j++) {
        fprintf(pfichero, "Pasajero %d: ",contador++);
        fprintf(pfichero,"%s %s ", pasajero[j].nombre, pasajero[j].apellidos);
        fprintf(pfichero,"con DNI: %d %c\n",pasajero[j].dni,pasajero[j].letra);
    }
   fclose(pfichero);
     
 //Pago de los billetes.     
 
    do{  
  printf("\nSeleccione el metodo de pago:\n");
  printf("1-Tarjeta\n");
  printf("2-Paypal\n");
  scanf("%d", &metodopago);
    }while(metodopago<1 ||metodopago>2);
 
  if(metodopago==1){
  printf("\nPago con tarjeta\n");
  do{
  printf("\nPor favor seleccione el tipo de tarjeta: \n");
  printf("1-Visa\n");
  printf("2-American express\n");
  printf("3-Mastercard\n");
  scanf("%d", &tipoTarjeta);
  }while (tipoTarjeta<1 || tipoTarjeta>3);
  
  if(tipoTarjeta==1){
   printf("\nHa seleccionado el pago mediante Visa\n");
  } else if(tipoTarjeta==2){
   printf("\nHa seleccionado el pago mediante American express\n");
  } else if(tipoTarjeta==3){
   printf("\nHa seleccionado el pago mediante Mastercard\n");
  }
  else{
   printf("\nOpcion no disponible\n");
   }
  
 
  printf("\n    Los datos introducido a continuacion son personales e intransferibles\n");
  printf("\n    ---------------------------------------------------------------------\n");
  printf("\nIntroduzca el nombre del titular de la tarjeta de credito: ");
  scanf("%s",nombreTitular);
  fflush(stdin);
  printf("\nIntroduzca los apellidos del titular de la tarjeta de credito: ");
  gets(apellidosTitular);
  printf("\nIntroduzca el numero de la tarjeta de credito: ");
  scanf("%ld", &numeroTarjeta);
  fflush(stdin);
  printf("\nIntroduzca el CVC (codigo de verificacion) de la tarjeta: ");
  scanf("%d",&cvc);
  printf("\nIntroduzca la fecha de caducidad mm aa de la tarjeta: ");
  scanf("%d %d", &mescaducidad, &aniocaducidad);
  if(opcion==1){
  	printf("\nSe ha realizado correctamente el cargo de %.2f euros en su tarjeta\n", precio+precioRegreso); 
  	printf("\nPuede descargar sus billetes\n");
    }else if(opcion==2){
  	printf("\nSe ha realizado correctamente el cargo de %.2f euros en su tarjeta\n", precio);
  	printf("\nPuede descargar sus billetes\n");
    }
   //En el fichero "pasajeros.txt" se encuentran sus billetes
 
    }else if (metodopago==2){
     
     
  printf("Pago con Paypal\n");
  
  printf("\n    Los datos introducido a continuacion son personales e intransferibles\n");
  printf("\n    ---------------------------------------------------------------------\n");
  printf("\nIntroduzca su numero de telefono movil: ");
  scanf("%d", &telefono);
  fflush(stdin);
  printf("\nIntroduzca la direccion de facturacion\n ");
  printf("\nCalle: ");
  scanf("%s",direccion);
  fflush(stdin);
  printf("\nCodigo postal: ");
  scanf("%d",&codigoPostal);
  printf("\nLocalidad pais: ");
  scanf("%s %s",localidad,pais);
  fflush(stdin);
  printf("\nPortal: ");
  scanf("%d",&portal);
  printf("\nPiso con la letra: ");
  scanf("%s",letraPiso);
  do{
  printf("\nIntroduzca su clave: ");
  scanf("%s", clave);
  printf("\nVuelva a introducir su clave por favor: ");
  scanf("%s",clave1);
   if (strcmp(clave,clave1)==0){
  	printf("\nSe ha realizado correctamente el cargo de %.2f euros\n", precio);
	printf("\nPuede descargar sus billetes\n");
  } else{
  	printf("\nLas claves no coincicen, introduzcalas de nuevo\n");
  }
 }while(strcmp(clave,clave1)!=0);
    }else{
    printf("\nOpcion no disponible\n");
    }

 printf ("\nExiste la posibilidad de enviar el justificante de compra por correo electronico\n");
 printf("1-Deseo recibir justificante de compra\n");
 printf("2-No deseo recibir justificante de compra\n");
 scanf("%d", &factura);

 
  if (factura==1) {
  do{
  fflush(stdin);
  printf("\nPor favor introduzca su direccion de correo electronico:\n");
  gets(pasajero[j].correo);
  
  longitudCorreo = strlen(pasajero[j].correo);
  
  A=0;
  B=0;
  for(m=0;m<longitudCorreo;m++){
  
   if(pasajero[j].correo[m]=='@'){
   A=A+1;
  }
   if(pasajero[j].correo[m]=='.'){
   B=B+1;
    } 
   } 
   
  }while(A!=1 || B!=1);
 
 printf("\nSe ha enviado el justificante de compra a la direccion de correo facilitada\n");
 printf("\nGracias por confiar en DREAMTRIP, buen viaje\n"); 
 } else if (factura==2) {
  printf("\nHa elegido no recibir justificante de compra\n");
  
  printf("\nGracias por confiar en DREAMTRIP, buen viaje\n");
 } else if (factura!=1 && factura!=2) {
  printf("\nOpcion no valida\n");
   }
  } else {
 printf("La opcion que usted ha elegido no es una opcion valida\n");
  }
 

} while(opcion==1||opcion==2);



return 0;
}

//Funciones.


int horarioManiana(){
 int hora;
        printf("1-8:50\n");
  printf("2-10:35\n");
  printf("3-11:40\n");
  printf("4-12:25\n");
  scanf("%d", &hora);
  return hora;
 }

int horarioTarde(){
 int hora;
  printf("1-14:10\n");
  printf("2-16:00\n");
  printf("3-18:25\n");
  printf("4-20:45\n");
  scanf("%d", &hora);
  return hora;
}
int horarioNoche (){
 int hora;
  printf("1-21:05\n");
  printf("2-22:15\n");
  printf("3-23:00\n");
  printf("4-00:30\n");
  scanf("%d", &hora);
  return hora;
}
int horarioMadrugada(){
 int hora;
  printf("1-2:25\n");
  printf("2-4:00\n");
  printf("3-5:20\n");
  printf("4-6:45\n");
  scanf("%d", &hora);
  return hora;
 }

float costeBilletes(int paisElegido,int nnbilletes){
    float coste;
    
    if(paisElegido>=1&&paisElegido<=12){
      coste+=(40*nnbilletes);
      printf("\nEl vuelo tiene un coste de 40 euros por billete\n");
      
   }else if(paisElegido>=13 && paisElegido<=23){
   coste+=(70*nnbilletes);
   printf("\nEl vuelo el tiene un coste de 70 euros por billete\n");
   
   }else if (paisElegido>23&&paisElegido<=30){
   coste+=(100*nnbilletes);
   printf("\nEl vuelo el tiene un coste de 100 euros por billete\n");
   
   }else if (paisElegido>30 && paisElegido<=37){
   coste+=(120*nnbilletes);
   printf("\nEl vuelo el tiene un coste de 120 euros por billete\n");
  
   }else if (paisElegido>37&&paisElegido<=44){
   coste+=(145*nnbilletes);
   printf("\nEl vuelo el tiene un coste de 145 euros por billete\n");
   
  }else if(paisElegido>44&&paisElegido<=47){
   coste+=(160*nnbilletes);
   printf("\nEl vuelo el tiene un coste de 160 euros por billete\n");
   }
   
 return coste; 
}

float companiadeVuelo(int empresa,int numbilletes){
float precio;
 if(empresa==1){
 printf("\nVuelo con Iberia, suplemento de 16 euros por billete\n");
 precio+=(16*numbilletes);
} else if(empresa==2){
 printf("\nVuelo con Air Europa, no supone ningun suplemento\n");
} else if (empresa==3){
 printf("\nVuelo con Rayaner, no supone ningun suplemento\n");
} else if(empresa==4){
 printf("\nVuelo con Vueling, suplemento de 8 euros por billete\n");
 precio+=(8*numbilletes);
} else if(empresa==5){
 printf("\nVuelo con American Airlines, suplemento de 20 euros por billete\n");
 precio+=(20*numbilletes);
 
} else if(empresa==6){
 printf("\nVuelo con Emirates, suplemento de 25 euros por billete\n");
 precio+=(25*numbilletes);
 
} else if(empresa==7){
 printf("\nVuelo con British AirWays, suplemento de 16 euros por billete\n");
 
} else if(empresa==8){
 printf("\nVuelo con easyJet, suplemento de 10 euros por billete\n");
 precio+=(10*numbilletes);
 
} else if(empresa==9){
 printf("\nVuelo con KLM, no supone ningun suplemento\n");
} else if(empresa==10){
 printf("\nVuelo con Alitalia, suplemento de 12 euros por billete\n");
 precio+=(12*numbilletes);
 
}
  return precio;
}

int eliminarCaracteres(char str[]) {
    int s, p, encontrado=0;
    for(s=0; str[s]!='\0'; s++) {
    if ((str[s]<65 || str[s]>90)&&(str[s]<97 || str[s]>122) && str[s]!='\0') {
    	encontrado=1;
      for(p=s; str[p]!='\0'; p++) {
        str[p]=str[p+1];
      }
      s--;
    }
}
  return encontrado;
}

char letraDNI(int dni){
	char letra[23]={"TRWAGMYFPDXBNJZSQVHLCKE"};

  return letra[dni%23];
}
