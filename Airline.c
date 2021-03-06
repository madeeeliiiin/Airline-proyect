/*Airline ticket reservation
    Emily Soto 
    Madeline Salguero
*/
 
//librerias
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
//macros
#define rows 32
#define cols 6

//definiciones
char nuevoasig[3] = "";

//Prototipo de funciones
void clearscreen(){
    system("@cls||clear");
}

//Variables globales
 char vuelo[5];
 char asiento[4];
 int length;
 int seleccion;
 int  matrix[rows][cols]={{0,0,0,0,0,0}};
int numcol;
int numrow;
char letracol;
char rowchar[2];

//funciones propuestas
int seatscol(char numero[3]){
if (numero[0]== 'a'){
  numcol=0;}
  if (numero[0]== 'b'){
  numcol=1;}
   if (numero[0]== 'c'){
  numcol=2;}
   if (numero[0]== 'd'){
  numcol=3;}
   if (numero[0]== 'e'){
  numcol=4;}
   if (numero[0]== 'f'){
  numcol=5;}
  return 0;
}

int seatsrow(char numero[3]){
  int numrow1;
  int numrow2;
  char primer=numero[1]; 
  char segundo=numero[2]; 
if (strlen(numero)<3){
   if ((primer >= '0') && (primer <= '9')){ 
numrow= ((primer- '0')-1); 
}
}
if (strlen(numero)>=3){
   if ((primer >= '0') && (primer <= '9')){ 
numrow1= ((primer- '0'))*10; 
}
 if ((segundo >= '0') && (segundo <= '9')){ 
numrow2= ((segundo- '0')-1); 
}
numrow=numrow1+numrow2;
}
	return 0;
}
int sugerencia( int f, int let){
    char numeros[2];
    sprintf(numeros, "%d", f);
    char letra[2];
    if(let == 0)
    {letra[0] = 'A';}
    if(let == 1)
    { letra[0] = 'B';}
    if(let == 2)
    {letra[0] = 'C';}
    if(let== 3)
    {letra[0] = 'D';}
    if(let== 4)
    { letra[0] = 'E';}
    if(let== 5)
    { letra[0] = 'F';}
    strcat(nuevoasig, letra);
    strcat(nuevoasig, numeros);
    printf("\n*Le sugerimos el asiento '%s'\n Presione '0' para asignarlo\n", nuevoasig);
return 0;
}

//menu
int main(void){
    menu_entrada:
        clearscreen();
        printf("Ingrese el numero de vuelo:\n");
        scanf("%s", vuelo);
        length = strlen (vuelo) ;

        if (length!=5){
          goto menu_entrada;
        }

      if(length==5){
        goto menu_principal;
    menu_principal:
    clearscreen();                                     
      printf("\033[01;36m");
 
                                             
    printf("                              _|_\n");                                            
    printf("                             |___| \n");                                          
    printf("                            |_____| \n ");                                          
    printf("                          |oo   oo| \n ");                                         
 printf("|_________________________|       |__________________________| \n");             
  printf("  `---------|------|--------|_____|--------|------|---------' \n");              
  printf("           ( )    ( )     |OOo|oOO|O     ( )    ( ) \n"); 
  printf("\033[0m");      
    printf("\n                  Bienvenido vuelo: %s\n", vuelo);
   printf("\033[01;31m");

    printf("===========================================================");
      printf("\033[0m");      
    printf("\n¿Que desea realizar?\n\n 1: Para reservar asiento \n 2: Para ver disponibilidad de asientos \n 3: Para ver resumen\n 4: Para salir \n");
        printf("\033[01;31m");
    printf("===========================================================");  
     printf("\033[0m");      
    printf("\n Ingrese su seleccion:  ");
    scanf("%d",&seleccion);
    

    if(seleccion==4){
        clearscreen();
        exit(0);
    }

    if(seleccion==1){
      asignar:
      clearscreen();  
      printf("\033[01;36m");

    printf("\n                 Reserva de asientos vuelo: %s\n", vuelo);
         printf("\033[0m");      

    printf("  *Los asientos están numerados con letras (A-F) y números (1-32)\n");
    printf("\nIngrese el asiento que desea reservar:\n"); 
    scanf("%s", asiento);
      if (strcmp(asiento,"menu")==0){
       goto menu_principal;
      }
    if (strlen(asiento)<=3){
    seatscol(asiento);
    seatsrow(asiento);
    if ((numrow<=rows)&&(numcol<=cols)){
      if (matrix[numrow][numcol]==0){
          matrix[numrow][numcol]=1;
          printf("\nAsiento '%s' reservado exitosamente\n", asiento);
      }
      else if (matrix[numrow][numcol]==1){
        printf("\nAsiento '%s' ya esta reservado\n", asiento);
       int contador_cols=0;
       int contador_rows=0;
       int contador_sugerido=0;
         for(int r=0; r<rows; r++ ){
        for(int o =0; o<cols; o++){ 
          if(matrix[r][o]==0){
            contador_sugerido=1;
            contador_rows=r+1;
            contador_cols=o;
            break;
          }
        }
        if(contador_sugerido==1){
          break;
        }
         }
         sugerencia(contador_rows,contador_cols);
         scanf("%s", asiento);
        if (strcmp(asiento,"menu")==0){
          goto menu_principal;
      }
         if (*asiento=='0'){
            goto asignar;
         }
  
      //Puntos extra sugerir lugar
      /*while(matrix[numrow][numcol]==1){
      int contador_sug=0
      for(int c =0; c<rows; c++ ){
        for(int e=0; e<cols; e++){
      
        }
      }
      }
      */
    }
    }
    else{
    printf("\n***Numeracion de asiento invalido\n");
    }
    }

    else {
      printf("\n***Numeracion de asiento invalido\n");
    }
    }

  if (seleccion==2){
    clearscreen();
          printf("\033[01;36m");
   printf("      Disponibilidad de asientos\n\n");
 printf("\033[0m");   
 int contador=0;
 int contad_filas=1;
  printf("\033[01;33m");
  printf("\n\n      | A || B || C || D || E || F |\n");
    printf("------------------------------------\n");    printf("\033[0m");    

    for(int i =0 ;i <  rows; i++){
       if (contad_filas<10){
      printf("\033[01;33m");
       printf("| %i  |",contad_filas);
       printf("\033[0m");    

      }
      else if (contad_filas>=10){
              printf("\033[01;33m");
       printf("| %i |",contad_filas);
              printf("\033[0m");    
      }
        for (int y=0; y< cols ;y++){
            printf("| %i |", matrix[i][y]);
        }
        contad_filas=contad_filas+1;
        printf("\n");
    }

  }
  if (seleccion==3){
    clearscreen();
    float ocupados=0;
    for (int m = 0; m < rows; m++) {
      for (int z = 0; z < cols; z++) {
         ocupados = ocupados + matrix[m][z];
      }
   }
   float disponibles = (rows*cols) - ocupados;           printf("\033[01;36m");

   printf("\n        Resumen de disponibilidad de asientos\n\n");
    printf("\033[0m"); 
   printf("\nReservados: %.0f/%d [%.2f %%]", ocupados,(rows*cols),((ocupados/(rows*cols))*100));
   printf("\nDisponibles: %.0f/%d [%.2f %%]", disponibles,(rows*cols),((disponibles/(rows*cols))*100));

  }

    }
 printf("\033[01;31m");

 printf("\nPara regresar al menu principal seleccione 'ENTER'\n");
 printf("\033[0m");    
 char noimporta[3];
 fgets(noimporta, 3, stdin);
 fgets(noimporta, 3, stdin);
 clearscreen();
 goto menu_principal;
}
