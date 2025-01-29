#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
/*
FILE *fd;
/*
struct Mpuntuaciones{	
	char *nombre[]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	int puntuacion[10]; 
}ranking;

void Archivo(long int  puntuacion){
	char directorio[]="/home/debian/Documentos/AyP2/Battleship/Ranking.txt";
	char nombre[20]
	fd=fopen(directorio,"a+");	
	if (fd == NULL){
		printf("error al tratar de crear el archivo verifique el directorio en el codigo");
		return -1;
	}
	fflush(stdin);
	printf("\n\tTOP 10 Puntuaciones: ");
	fprintf(fd,"\n\tTOP 10 Puntuaciones: \n");
	printf("\tposicion \tpuntuacion \tnombre");
	fprintf(fd,"\tposicion \tpuntuacion \tnombre");
	if (ranking.nombre == ""){
		printf("ingrese su nombre: ");gets(ranking.nombre);
		printf("1)\t%d\t%s",puntuacion,ranking.nombre);
		fprintf(fd,"1)\t");
		fwrite(puntuacion,1,fd);
		fwrite(ranking.nombre,1,strlen(ranking.nombre),fd);
	}
	fclose(fd);
} */
//elegir computadora o usuario 
int jugador(){
int decision;
	printf("ingrese el numero 0 para que este terminal sea un CPU y cualquier otro numero para jugador\n");
	scanf("%d",&decision);
	if (!decision)
		return 0;
	printf("si su rival es un CPU introduzca 0 y cualquier otro numero para otro jugador ");
	scanf("%d",&decision);
	if (!decision)		
		return 1;
	return 2;  
} 

void intrucciones(){
	printf(" \tBattleship\n Este Modo tiene 2 modalidades:\n*Jugador :Donde la creacion del tablero y la direccion de los diparos son digitadas por el usuario \n*CPU:  La posiciones de las Flota se colocaran en automatico. // advertencia si utiliza este metodo sea paciente  a la hora de esperar el tablero \n Como se gana? dejando al usuario contrincante sin flotas. \n Como se juega? Decidiendo coordenadas de disparos para eliminar todas las flotas del contrincante, esta en la modalidad seguido que quiere decir que si acetaste sigues disparando hasta que falles o ganes. \n Gracias por Utilizar este programa.\n");
}
//inicializa una matriz
void CrearTablero(int x,int y,int tablero[x][y]){
	int j,i;
	for (i=0;i<x;i++){
		for(j=0;j<y;j++){
			tablero[i][j]=0;
		}
	}		
}

//ordena las Flota
int Flota(int x,int y,int tablero[x][y],int Modo){
	int p=0,b=0,l,j,i,k,m,aux,bandera,ver,vidas=0;
	int CantEspaciosTotales = x*y;
	int MaxP = (CantEspaciosTotales/5);
	do{
		if ((MaxP/2)>=2)
			do{
			printf("Introduzca la cantidad de portaviones (Max: %d) :",((MaxP/2)-1));	
				scanf("%d",&p);
				if (p>(MaxP/2)-1){
						system("clear");
					printf("Ingrese cantidad positiva menor o igual al Max \n");
				}
		}
			while (p>((MaxP/2)-1));
		vidas=p*5; 
		if (p)
			CantEspaciosTotales=(CantEspaciosTotales)-((MaxP/2)*5);
		int MaxB=(CantEspaciosTotales/3);
		if ((MaxB/2)>=1){
			do{
				printf("Introduzca la cantidad de buques (Max: %d)",((MaxB/2)-1));
				scanf("%d",&b);
				if (b>(MaxB/2)-1){
					system("clear");
					printf("Ingrese cantidad positiva menor o igual al Max \n");
				}
			}
			while (b>((MaxB/2)-1));
		}
		vidas+=b*3;
		if (b)
			CantEspaciosTotales-=(MaxB/2)*3;
		do {
			printf("Introduzca la cantidad de lanchas (Max: %d)",(CantEspaciosTotales/2));
			scanf("%d",&l);
			if (l>(CantEspaciosTotales/2)){
					system("clear");
					printf("Ingrese cantidad positiva menor o igual al Max \n");
			}
		}	
			while(l>=(CantEspaciosTotales/2));
		vidas+=l;
		if (!Modo){
			printf("\n\tespere pacientemente a que se cree el tablero\n");
			sleep(3);
			}
	}
	while(vidas<1);
	//ordenar portaviones
	if (p>0){	
	for (k=0;k<p;k++){
		ver=1;
		if (Modo)
			system("clear");
		while(ver==1){
			bandera=6;
			if (Modo){
				printf("Introduzca la coordenada donde quiere el portaviones \n");
				printf("x: ");
				scanf("%d",&j);
				printf("y: ");
				scanf("%d",&i);
				printf("introduzca un 0(horizontal) o un 1(vertical) para la posicion del "); 			printf("portavion\n");
			}
			else {
				srand(time(NULL));
				i = rand()%x;
				j = rand()%y;
			}
			while((bandera<-1)||(bandera>2))
				if (Modo)
					scanf("%d",&bandera);
				else 	{
					srand(time(NULL));
					bandera = rand()%2;}
			if(!bandera){
				aux=j;
				ver=0;
				for(m=0;m<5;m++){			
					if(tablero[i][aux]){
						ver=1;
					}				
					if (aux>=y)
						ver=1;
					aux++;
				}
				if(ver==1 && Modo )
					printf("El lugar esta ocupado \n\n");
				if(ver==0 && aux<=x){
					for(m=0;m<5;m++){
						tablero[i][j]=5;
						j++;
					}
				}
			}
			if(bandera==1){
				aux=i;
				ver=0;
				for(m=0;m<5;m++){		
					if(tablero[aux][j]){
						ver=1;
					}		
					if (aux>=x)
						ver=1;
					aux++;			
				}
				if(ver==1 && Modo )
					printf("El lugar esta ocupado \n\n");
				if(ver==0){
					for(m=0;m<5;m++){
						tablero[i][j]=5;
						i++;
					}
				}
			}
			if (Modo){
				for (i=0;i<x;i++){
					printf("\n");
					for(j=0;j<y;j++){
						printf("|%d|",tablero[i][j]);
					}
				}
			}
			printf("\n\n");
		}
		////getchar();
		////getchar();
	}
	}

	//Ordenar buques

	if(b>0){ //1
	for (k=0;k<b;k++){ //2	
		ver=1;
		if (Modo)
			system("clear");
		while(ver==1){ //3 
			bandera=6;
			if (Modo){ //4
				printf("Introduzca la coordenada donde quiere el buque \n");
				printf("x: ");
				scanf("%d",&j);
				printf("y: ");
				scanf("%d",&i);
				printf("introduzca un 0(horizontal) o un 1(vertical) para la posicion del "); 			printf("buque\n");
			} //-4
			else { //5
				srand(time(NULL));
				i = rand()%x;
				j = rand()%y;
			}//-5
			while((bandera<-1)||(bandera>2)){//6
				if (Modo)
					scanf("%d",&bandera);
				else 	{ //7
					srand(time(NULL));
					bandera = rand()%2;} //-7
			}	//-6
			if(!bandera){ //8
				aux=j;
				ver=0;
				for(m=0;m<3;m++){ //9			
					if(tablero[i][aux])
						ver=1;
					
					if (aux>=y)
						ver=1;
					aux++;
				} //-9
				if(ver==1 && Modo )
					printf("El lugar esta ocupado \n\n");
				if(ver==0){ //10
					for(m=0;m<3;m++){//a
						tablero[i][j]=3;
						j++;
					}//-a
				}//-10
			}//-8
			if(bandera==1){//11
				aux=i;
				ver=0;
				for(m=0;m<3;m++){//12		
					if(tablero[aux][j]){//13
						ver=1;
					}//-13
					if (aux>=x)
						ver=1;
					aux++;				
				}//-12
				if(ver==1 && Modo )
					printf("El lugar esta ocupado \n\n");
				if(ver==0){//14
					for(m=0;m<3;m++){//15
						tablero[i][j]=3;
						i++;
					}//-15
				}//-14
			}//-11

			// imprimir carton a jugador
			if (Modo){//16
				for (i=0;i<x;i++){//17
					printf("\n");
					for(j=0;j<y;j++){//18
						printf("|%d|",tablero[i][j]);
					}//-18
				}//-17
			}//-16
		}//-3
		//getchar();
		//getchar();
		
	}//-2
	}//-1
	
	//Ordenar lanchas

	if(l>0){//1
	for (k=0;k<l;k++){//2	
		ver=1;
		if (Modo)
			system("clear");
		while(ver==1){//3
			if (Modo){//4
				printf("Introduzca la coordenada donde quiere el portaviones \n");
				printf("x: ");
				scanf("%d",&j);
				printf("y: ");
				scanf("%d",&i);
				printf("introduzca un 0(horizontal) o un 1(vertical) para la posicion del "); 			printf("portavion\n");
			}//-4
			else {//5
				srand(time(NULL));
				i = rand()%x;
				j = rand()%y;
			}//-5
			if(!tablero[i][j] || i>=x || j>=y){//6
				tablero[i][j]=1;
				ver=0;
			}//-6
			if(ver==1 && Modo )
				printf("El lugar esta ocupado \n\n");
			if (Modo){//7
				for (i=0;i<x;i++){//8
					printf("\n");
					for(j=0;j<y;j++){//9
						printf("|%d|",tablero[i][j]);
					}//-9
				}//-8
			}//-7
		}//-3
	}//-2
		//getchar();
		//getchar();
	}//-1
	return vidas;
	
}
int Comprobar(int x ,int y, int i , int j,int marca[i][j]){
	int A,B,D,I;
	A =((j-1>=0)&&(marca[i][j-1]==0));
	B =((j+1<=y)&&(marca[i][j+1]==0));
	D =((i+1<=x)&&(marca[i+1][j]==0));
	I =((i-1>=0)&&(marca[i-1][j]==0));
	if (A || B || D || I )
		return 1;
return 0;
}

void ImprimirTablero(int x,int y,int marca[x][y],int tablero[x][y]){
int i,j,k=0;
// tablero de marca 
	printf("\nx->\t");
	for (i=0;i<x;i++)
		printf(" %d ",i);
		printf("/y ");
	for (i=0;i<x;i++){
		printf("\n\t");
		for(j=0;j<y;j++){
			switch(marca[i][j]){
				case 0://_________________
					printf("| |");
					//________________
					break;
				case 1:
					printf("|X|");
					break;
				case -1:
					printf("|O|");
					break;
			}
		}
		printf(" %d",k);
		k++;
	}
	printf("\n\n");
	k=0;
//tablero de barcos 
	printf("x->\t");
	for (i=0;i<x;i++)
		printf(" %d ",i);
	printf("/y");
	for (i=0;i<x;i++){
		printf("\n\t");
		for(j=0;j<y;j++){
			switch(tablero[i][j]){
				case 0:
					printf("| |");
					break;
				case 1:
					printf("|L|");
					break;
				case 3:
					printf("|B|");
					break;
				case 5:			
					printf("|P|");
					break;
				case -1: 
					printf("|X|");
					break;				
			}
		}
		printf(" %d",k);
		k++;
	}	
	printf("\n\n");	

}

int BatallaNaval(int x,int y,int tablero[x][y],int marca[x][y],int Modo,int vidas,int *balas,int *tiempo){
	clock_t start = clock();
	int turno,i,j;
	int cpu=0;
	int IniX=0,IniY=0;
	int AntX=0,AntY=0;
	int vidaOponente=vidas;
	int respuesta;
	ImprimirTablero(x,y,marca,tablero);
	printf("Como comienza la partida? 1 para disparando y 0 para recibiendo: ");
	scanf("%d",&turno);
	system("clear");
	
	while((vidas>0) && (vidaOponente>0)){//1
		ImprimirTablero(x,y,marca,tablero);
		if (turno==1){//2
			if (Modo){//3
				*balas+=1;
				printf("posicion x del disparo: ");
				scanf("%d",&j);
				printf("posicion y del disparo: ");
				scanf("%d",&i);	
				printf("\n el disparo fue acertado? (ingrese 1 o 0 1=si/0=no)");
				scanf("%d",&respuesta);
				if(respuesta==1){ //4
					marca[i][j]=1;
					vidaOponente-=1;
				}//-4
				else {//5
					turno=0;
					marca[i][j]=-1;
				}//-5
			}	//-3
			else{	//6
				switch(cpu){//7
					 case 0:srand(time(NULL));
				 		i=rand()%x;
						j=rand()%y;
						//*balas+=1;
						break;
					 case 1: if (Comprobar(x,y,i,j,marca)){//8
							int disparo=0;
							do {//9
								srand(time(NULL));
								int direccion=rand()%4;
								switch(direccion){//10 11
								case 0: if((j-1>=0)&&(!marca[i][j-1])) {
									j-=1;
									disparo=1;
									}break;//-11 12
								case 1:if((j+1==y)&&(!marca[i][j+1])){
									j+=1;disparo=1;
									}break;//-12 13
								case 2:if((i+1==x)&&(!marca[i+1][j])){
									i+=1;disparo=1;
									}break; //-13 14
								case 3:if((i-1>=0)&&(!marca[i-1][j])){
									i-=1;disparo=1;
									}break;//-14
								}//-10
							}while(disparo=0);//-9
						//*balas+=1;
						}//-8
						else{//15
						srand(time(NULL));
				 		i=rand()%x;
						j=rand()%y;
						cpu=0;
						}//-15
					case 2://*balas+=1;
						if (AntX=IniX){//16
							if ((j+1<x)&&!(marca[i][j+1])&&(respuesta==1))
								j+=1;
							else {//17
								if ((IniX-1<0)&& !(marca[i][IniX-1]))
									j=IniX-1;
								else{//18
									srand(time(NULL));
							 		i=rand()%x;
									j=rand()%y;
									cpu=0;
								}//-18
									
							}//-17
						}//-16
						else {//19
							if ((i+1<y)&&!(marca[i+1][j])&&(respuesta==1))
								i=IniY+1;
							else{//20
								if ((IniY-1<0)&& !(marca[IniY-1][j]))
									i=IniY-1;
								else{//21
									srand(time(NULL));
							 		i=rand()%x;
									j=rand()%y;
									cpu=0;
								}//-21
							}//-20
						}
						}	//7? //-19
				printf("\n el disparo fue a x:%d,y:%d",j,i);
				printf("\n el disparo fue acertado? (ingrese 1 o 0 1=si/0=no): ");
				scanf("%d",&respuesta);
				if(respuesta==1){//22
					marca[i][j]=1;
					vidaOponente-=1;
					AntX=i;
					AntY=j;
					if (cpu<2)
						cpu+=1;
					if(cpu!=2){//23
						IniX=AntX;
						IniY=AntY;
					}//-23
				}//-22
				else {//24
					turno=0;
					marca[i][j]=-1;
					if (cpu==1 && !Comprobar(x,y,i,j,marca))
						cpu=0;	
				}	//-24	
			}//6> 	//-7
				
		}//2?	
		else {//25
			printf("ingrese donde recibio el disparo\n");
			printf("X: ");
			scanf("%d",&j);
			printf("Y: ");
			scanf("%d",&i);
			if (tablero[i][j]){ //26
				tablero[i][j]=-1;
				printf("\n te ha dado ");
				vidas-=1;
				}//-26
			else {//27
				printf("\n ha fallado");
				turno=1;
			}//-27
		}//-25
		sleep(2);
		system("clear");
	} //-2
	*tiempo=((int)clock()/CLOCKS_PER_SEC);
	if (vidas==0)
		return 0;
	return 1;	
} 

int main (){
	int menu,Modo,partida,balas=0,tiempo;
	do{  
		printf("Introduzca una opcion\n\t1) Jugar \n\t2)intrucciones \n\t3)salir\n\tOpcion:");
		scanf("%d",&menu);
		system("clear");
		switch(menu){
		case 1:Modo=jugador();break;
		case 2:intrucciones();break;
		case 3:return 0;	
		}
	}
	while(menu!=1 && menu<4 );
	int x,y,j,i;system("clear");
	do{ 
		printf("Introduzca la cantidad de filas: ");
		scanf("%d",&x);
		printf("Introduzca la cantidad de columnas: ");
		scanf("%d",&y);
		if (x<2||y<2){
			system("clear");
			printf("la cantidad minima de filas y columnas permitidas es 2 ");
		}
			
	}
	while(x<2 || y<2);
	int tablero[x][y];
	CrearTablero(x,y,tablero);
	int vidas=Flota(x,y,tablero,Modo);
	system("clear");
	int marca[x][y];
	CrearTablero(x,y,marca);
// tablero de marca 
	for (i=0;i<x;i++){
		printf("\n");
		for(j=0;j<y;j++){
			if (!marca[i][j])
				printf("| |");
		}
	}
	printf("\n\n");
//tablero de barcos 

	for (i=0;i<x;i++){
		printf("\n");
		for(j=0;j<y;j++){
			switch(tablero[i][j]){
				case 0:
					printf("| |");
					break;
				case 1:
					printf("|L|");
					break;
				case 3:
					printf("|B|");
					break;
				case 5:			
					printf("|P|");
					break;				
			}
		}
	}	
	printf("\n\n presione cualquier tecla para empezar el Modo"); getchar();getchar();	
	system("clear");
	partida=BatallaNaval(x,y,tablero,marca,Modo,vidas,&balas,&tiempo);
	if (partida)
		printf("\n\n       felicidades ha ganado!!!!!!!!!!!!!!!!!!!!");
	else 
		printf("\n\n      Suerte para la proxima, has perdido");
	printf("\n tiempo de partida: %d , numero de balas: %d ",tiempo,balas);
	//Archivo(1000000/(balas*tiempo));
	return 0;
}
