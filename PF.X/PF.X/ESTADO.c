/*
 * File:   ESTADO.c
 * Author: 57304
 *
 * Created on March 24, 2022, 9:59 PM
 */


#include "ESTADO.h"
#include "mcc_generated_files/mcc.h"
void inicializarRecepcion(recepcion* rec){
    rec->estados=ESTADO1;
    rec->bandera=0;
    rec->error=0;
}
void PalabraRecepcion(char datorx,recepcion* rec){
    switch(rec->estados){
    case ESTADO1: 
        if (datorx=='#')
            rec->estados=ESTADO2;
        else{
            rec->estados=ESTADO1;
            rec->error=1;
        }
        break;
    case ESTADO2: 
        if ((datorx<48)||(datorx>57)){
            rec->error=1;
            rec->estados=ESTADO1;

        }
        else{
            rec->estados=ESTADO3;
            rec->digito1=datorx;
        }
        break;
    case ESTADO3:
        if ((datorx<48)||(datorx>57))
        {
            rec->error=1;
            rec->estados=ESTADO1;

        }
        else{
            rec->estados=ESTADO4;
            rec->digito2=datorx;
        }
        break;
    case ESTADO4: 
        if (datorx=='*'){// si llega esto y estoy en el estado 4 es porque se copleta la palabra de configuraciOn. 
            rec->numconvertido=(rec->digito1-48)*10+(rec->digito2-48);
            rec->estados=ESTADO1;
            rec->bandera=1;
            rec->error=0;//for if the flies
        }
        else{
            rec->estados=ESTADO1;
            rec->error=1;
        }
        break;

    default: //nunca deberia llegar acA se pone por culpa de los rashos cosmicos
        rec->estados=ESTADO1;
    }
}

char tengocambiodefdM(recepcion* rec){
    if (rec->bandera){
        rec->bandera=0;
        return 1;
    }
    return 0;
}
int8_t retorneNumero(recepcion* rec){
    return rec->numconvertido;
}
//int M=0;
//char read;
//char N;
//int C=0;
//int XX;
//
//void READ_STATE( int count){
//    switch(XX){
//        case 0:
//          if (EUSART1_Read()==42){
//              XX=1;
//              count=0;
//          }
//              else{
//                XX=0;  
//              }
//            break;
//        case 1:
//            if(EUSART1_Read()==0){
//                count=0;
//                XX=2;
//            }
//            else if(EUSART1_Read()==1){
//                    count=10;
//                    XX=2;
//                 
//            }
//            else if(EUSART1_Read()==2){
//                    count=20;
//                    XX=2;
//                
//            }
//            else if(EUSART1_Read()==3){
//                    count=30;
//                    XX=2; 
//            }
//              else if(EUSART1_Read()==4){
//                    count=40;
//                    XX=2; 
//            }
//              else if(EUSART1_Read()==5){
//                    count=50;
//                    XX=2;
//            }
//              else if(EUSART1_Read()==6){
//                    count=60;
//                    XX=2; 
//            }
//              else if(EUSART1_Read()==7){
//                    count=70;
//                    XX=2;  
//            }
//              else if(EUSART1_Read()==8){
//                    count=80;
//                    XX=2;  
//            }
//              else if(EUSART1_Read()==9){
//                    count=90;
//                    XX=2;
//              }
//              else{
//                  count=0;
//                  XX=0;
//              }
//            break;
//        case 2:
//            if(EUSART1_Read()==0){
//                count=count;
//                XX=3;
//            }
//            else if(EUSART1_Read()==1){
//                    count=count+1;
//                    XX=3 ;  
//            }
//            else if(EUSART1_Read()==2){
//                    count=count+2;
//                    XX=3 ;
//            }
//            else if(EUSART1_Read()==3){
//                    count=count+3;
//                    XX=3;
//            }
//              else if(EUSART1_Read()==4){
//                    count=count+4;
//                    XX=3 ;
//            }
//              else if(EUSART1_Read()==5){
//                    count=count+5;
//                    XX=3;
//            }
//              else if(EUSART1_Read()==6){
//                    count=count+6;
//                    XX=3 ;
//            }
//              else if(EUSART1_Read()==7){
//                    count=count+7;
//                    XX=3 ;
//            }
//              else if(EUSART1_Read()==8){
//                    count=count+8;
//                    XX=3;
//            }
//              else if(EUSART1_Read()==9){
//                    count=count+9;
//                    XX=3;
//              }
//              else{
//                  count=0;
//                  XX=0;
//              }
//            break;
//        case 3:
//            if(EUSART1_Read()==35){
//               XX=0;
//          }
//              else{
//                XX=0;  
//              }
//            break;
//       
//                
//            
//    
//    }
//
//}
