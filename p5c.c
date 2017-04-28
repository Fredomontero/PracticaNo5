#include "timer.h"
#define BYTE unsigned char

/*Pototipos de funciones*/
void UpdateClock(void);
void DisplayClock(void);
void setClock( BYTE horas, BYTE minutos, BYTE segundos);
void PrintDec2d(BYTE);
void delay(BYTE);
extern void pokeB(unsigned int segment,unsigned int offset, unsigned int data);
extern void pokeW(unsigned int segment,unsigned int offset, unsigned char data);
extern void putchar( char X );

BYTE segundos = 0;                        /*Para el manejo de los segundos*/
BYTE minutos = 0;                         /*Para el manejo de los minutos*/
BYTE horas = 0;                           /*Para el manejo de los horas*/

void main(){
  Timer_Ini();                            /*Inicializa timer de 1 seg*/
  setClock(00,00,50);
  while(1){
    /*Verificacion para actualizar el reloj*/
    if(TimerSecFlag()){
      UpdateClock();
      DisplayClock();
      /*Indicar el puerto*/
      pokeB(0x0000,0x0ffff,segundos);
    }
    /*Otras cosas por hacer*/
    delay(100);
  }
}

void UpdateClock( void ){
  segundos = (++segundos%60);
  if(!segundos){
    minutos = (++minutos%60);
    if(!minutos){
      horas = (++horas%24);
    }
  }
}

void DisplayClock(void){
  /*Imprimir el reloj en formato "HH:MM:SS"*/
  PrintDec2d(horas);
  putchar(':');
  PrintDec2d(minutos);
  putchar(':');
  PrintDec2d(segundos);
  putchar(13);
}

void setClock( BYTE horasP, BYTE minutosP, BYTE segundosP){
  horas = horasP;
  minutos = minutosP;
  segundos = segundosP;
}

void delay(BYTE i){
  while(--i);
}

void PrintDec2d(BYTE dato){
  putchar(dato/10+'0');                   /*Imprime deceas*/
  putchar(dato%10+'0');                   /*Imprime unidades*/
}
