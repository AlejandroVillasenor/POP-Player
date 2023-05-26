/*  - Villasenor Rivas Alejandro Rodrigo.
    - Ingenieria en Computacion.
    - Codigo: 218414783.
    - Materia: Estructura de Datos.
    - Profesor: Ramiro Lupercio Coronel.
*/
//Librerias
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/* Archivo de cabecera que incluye las funciones de validacion para las
diversos tipos de inputs */

bool validnum(string *num);
bool validnumP(string *numP);
bool validintP(string *intp);
bool validint(string *numint);
bool validbin(string *binN);
bool validoct(string *octN);
bool validhex(string *hexN);
bool validname(string *name);

/* VALIDACIONES NUMERICAS */
// Funcion para validar que la entrada sea un numero, que solo tenga un punto decimal y/o una sola barra de negacion (si es que lo tiene)
bool validnum(string *num){
    bool ban = false;
    int points = 0;//Para validar que solo tenga un punto decimal
    int neg = 0;//Para validar que solo tenga un signo negativo
    //Hacemos una validaacion para que no se ingresen numeros muy grandes y evitar desbordamientos
    int longitud = 0;
    longitud = (*num).length();
    if ((*num).length() > 6){
        ban = false;
        cout << "ERROR || Ingresa un numero menor a 6 digitos" << endl;
    }else{
        for (int n=0; n<longitud; n++){
            /* Validamos con ASCII */
            if ((((*num)[n] >= 48) && ((*num)[n] <= 57) ) || ((*num)[n] == 46) || ((*num)[n] == 45)){
                ban = true;
                if ((*num)[n] == 46){
                    points++;
                }
                if ((*num)[n] == 45){
                    neg++;
                }
                //Validamos en caso de que el ultimo miembro del string sea un punto decimal o un signo negativo
                if(((((*num)[n] == 46) && (n == longitud-1))) || (((*num)[n] == 45) && (n == longitud-1))){
                    ban = false;
                    break;
                }
                if ((points > 1) || (neg > 1) || (((neg == 1 && (*num)[0] == 45) || (points == 1 && (*num)[0] == 46)) && (longitud == 1))){
                    ban = false;
                    break;
                }
                if ((*num)[0] == 45 && (*num)[1] == 46){
                    ban = false;
                    break;
                }
            }else{
                ban = false;
                break;
            }
        }
    }
    return ban;
}

// Funcion para validar que la entrada sea un numero positivo, que solo tenga un punto decimal(si es que lo tiene)
bool validnumP(string *numP){
    bool ban = false;
    int points = 0;//Para validar que solo tenga un punto decimal
    int longitud = 0;
    longitud = (*numP).length();
    if (longitud > 6){
        ban = false;
        cout << "ERROR || Ingresa un numero menor a 6 digitos" << endl;
    }else{
        for (int np=0; np<longitud; np++){
            /* Validamos con ASCII */
            if ((((*numP)[np] >= 48) && ((*numP)[np] <= 57)) || ((*numP)[np] == 46)){
                ban = true;
                if ((*numP)[np] == 46){
                    points++;
                }
                //Validamos en caso de que el ultimo miembro del string sea un punto decimal
                if(((*numP)[np] == 46) && (np == longitud-1)){
                    ban = false;
                    break;
                }
                if ((points > 1) || ((points == 1 && (*numP)[0] == 46) && (longitud== 1))){
                    ban = false;
                    break;
                }
                if ((*numP)[0] == 46){
                    ban = false;
                    break;
                }
            }else{
                ban = false;
                break;
            }
        }
    }
    return ban;
}

// Funcion para validar que la entrada sea un numero entero positivo
bool validintP(string *intp){
    bool ban = false;
    int longit = 0;
    longit = (*intp).length();
    if ((*intp).length() > 6){
        ban = false;
    }else{
        for (int ip=0; ip<longit; ip++){
            /* Validamos con ASCII */
            if (((*intp)[ip] >= 48) && ((*intp)[ip] <= 57)){
                ban = true;
            }else{
                ban = false;
                break;
            }
        }
    }
    return ban;
}

// Funcion para validar que la entrada sea un numero entero ya sea positivo o negativo
bool validint(string *numint){
    bool ban = false;
    int neg = 0;//Para validar que solo tenga un signo negativo
    int longitu = 0;
    longitu = (*numint).length();
    if ((*numint).length() > 6){
        ban = false;
        cout << "ERROR || Ingresa un numero menor a 6 digitos" << endl;
    }else{
        for (int i=0; i<longitu; i++){
            /* Validamos con ASCII */
            if ((((*numint)[i] >= 48) && ((*numint)[i] <= 57)) || ((*numint)[i] == 45)){
                ban = true;
                if ((*numint)[i] == 45){
                    neg++;
                }
                //Validamos en caso de que el ultimo miembro del string sea un signo negativo
                if(((*numint)[i] == 45) && (i == longitu-1)){
                    ban = false;
                    break;
                }
                if (neg > 1 || (((neg == 1) && ((*numint)[0] == 45)) && (longitu == 1))){
                    ban = false;
                    break;
                }
            }else{
                ban = false;
                break;
            }
        }
    }
    return ban;
}

/* VALIDACIONES DE LOS SISTEMAS DE NUMERACION */
//Funcion que valida si se ingreso un numero binario valido
bool validbin(string *binN){
    bool ban = false;
    int longitud = 0;
    longitud = (*binN).length();
    if((*binN).length() > 15){
        ban = false;
        cout << "ERROR || Ingresa un numero menor a 15 digitos" << endl;
    }else{
        for(int b=0;b<longitud;b++){
            if(((*binN)[b] == 48) || ((*binN)[b] == 49)){
                ban = true;
            }else{
                ban = false;
                break;
            }
        }
    }
    return ban;
}

//Funcion que valida si se ingreso un numero octal valido
bool validoct(string *oct){
    bool ban = false;
    int longitud = 0;
    longitud = (*oct).length();
    if ((*oct).length() > 8){
        ban = false;
        cout << "ERROR || Ingresa un numero menor a 8 digitos" << endl;
    }else{
        for(int o=0;o<longitud;o++){
            if(((*oct)[o] >= 48) && ((*oct)[o] <= 55)){
                ban = true;
            }else{
                ban = false;
                break;
            }
        }
    }
    return ban;
}

//Funcion para validar los inputs de tipo hexadecimal
bool validhex(string *hex){
    bool ban = false;
    int longitud = 0;
    longitud = (*hex).length();
    if((*hex).length() > 8){
        ban = false;
        cout << "ERROR || Ingresa un numero menor a 8 digitos" << endl;
    }else{
    //Aplicamos upper para que no importe si el usuario ingresa en mayusculas o minusculas
        for(int h=0;h<longitud;h++){
            (*hex)[h] = toupper((*hex)[h]);
        }
        //Validamos que solo tenga caracteres validos en el sistema hexadecimal
        for(int h=0;h<longitud;h++){
            if(((((*hex)[h] >= 48) && ((*hex)[h] <= 57))) || ((*hex)[h] >= 65 && (*hex)[h] <= 70)){
                ban = true;
            }else{
                ban = false;
                break;
            }
        }
    }
    return ban;
}

/* FUNCIONES PARA VECTORES */
//Funcion para validar que el vector no este vacio
bool empty(vector <string> *vec){
    bool ban = false;
    if((*vec).size() == 0){
        ban = true;
    }else{
        ban = false;
    }
    return ban;
}

/* VALIDAMOS STRING */
//Funcion para validar que se ingreso un numbre sin numeros
bool validname(string *name){
    bool ban = false;
    int longitud = 0;
    longitud = (*name).length();
    if((*name).length() > 20){
        ban = false;
        cout << "ERROR || Ingresa un nombre menor a 20 caracteres" << endl;
    }else{
        for(int n=0;n<longitud;n++){
            if(((*name)[n] >= 65 && (*name)[n] <= 90) || ((*name)[n] >= 97 && (*name)[n] <= 122)){
                ban = true;
            }else{
                ban = false;
                break;
            }
        }
    }
    return ban;
}
//VALIDACION DE TIEMPO INGRESADO en formato MM:SS
bool validtime(string *time){
    bool ban = false;
    if((*time).length() > 5){
        ban = false;
    }else{
        if(((*time)[0] >= 48 && (*time)[0] <= 53) && ((*time)[1] >= 48 && (*time)[1] <= 57) && ((*time)[2] == 58) && ((*time)[3] >= 48 && (*time)[3] <= 53) && ((*time)[4] >= 48 && (*time)[4] <= 57)){
            ban = true;
        }else{
            ban = false;
        }
    }
    return ban;
}
//Validamos que el titulo de la cancion o artista sean letras puediendo tener espacios
bool validtitle(string *title){
    bool ban = false;
    int longitud = 0;
    longitud = (*title).length();
    if((*title).length() > 25){
        ban = false;
    }else{
        for(int t=0;t<longitud;t++){
            if(((*title)[t] >= 65 && (*title)[t] <= 90) || ((*title)[t] >= 97 && (*title)[t] <= 122) || ((*title)[t] == 32)){
                ban = true;
            }else{
                ban = false;
                break;
            }
        }
    }
    return ban;
}
