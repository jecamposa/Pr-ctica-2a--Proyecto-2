/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ESTADO_H
#define	ESTADO_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation


void READ_STATE();

#define ESTADO1 1
#define ESTADO2 2
#define ESTADO3 3
#define ESTADO4 4
struct recepcion{
char estados;// estados
char digito1;// temporal de caracter1
char digito2;// temporal de caracter2
int8_t numconvertido;// lo dejo num no porque se necesite 8 o 16 bits para operar sino para que les sea mAs facil entender que es un nUmero
char bandera;
char error;//bandera opcional para mostrar si hay error en la trama
};
typedef struct recepcion recepcion;
void PalabraRecepcion(char datorx,recepcion* rec);// se llama cada que llegue un dato en el serial OJO usar la version no bloqueante es decir preguntar si en el serial Rx hay un caracter listo, y si hay ahI si pedirlo y pasarlo a la funciOn
char tengocambiodefdM(recepcion* rec);//Dice si tengo cambio de frecuencia de muestreo se llama en el loop de polling
void inicializarRecepcion(recepcion* rec);//inicializa la estructura que crearon en el espacio de memoria del main
int8_t retorneNumero(recepcion* rec);//se llama si tengo cambio de Frec de Muestreo para saber cual es el cambio

#endif	/* XC_HEADER_TEMPLATE_H */

/*Esto va en recepcion.h no olvidar poner los prototipos y la protecciOn de sobre-inclusiOn al encabezado*/
