/*  - Villasenor Rivas Alejandro Rodrigo.
    - Ingenieria en Computacion.
    - Codigo: 218414783.
    - Materia: Estructura de Datos.
    - Profesor: Ramiro Lupercio Coronel.

    REPRODUCTOR MP3 CON C++ Y PLAY SOUND(interfaz).
*/
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <cstring>
#include <cstdlib>
#include <conio.h>
using namespace std;
#define color SetConsoleTextAttribute
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int, int);
void tablero();

void gotoxy(int x, int y){
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
void pantallaInicial(){
    color(hcon, 181);
    //Pantalla de 120 x 50
    gotoxy(30,21);cout << " ________                                      ______                          ";
    gotoxy(30,22);cout << "___  __ \\_____________                ___________  /_____ _____  ______________";
    gotoxy(30,23);cout << "__  /_/ /  __ \\__  __ \\   ________    ___  __ \\_  /_  __ `/_  / / /  _ \\_  ___/";
    gotoxy(30,24);cout << "_  ____// /_/ /_  /_/ /   _/_____/    __  /_/ /  / / /_/ /_  /_/ //  __/  /    ";
    gotoxy(30,25);cout << "/_/     \\____/_  .___/                _  .___//_/  \\__,_/ _\\__, / \\___//_/     ";
    gotoxy(30,26);cout << "              /_/                     /_/                 /____/               ";
    color(hcon, 192);
    gotoxy(40,30);cout << "Presione cualquier tecla para continuar...";color(hcon, 11);
    getch();
    system("cls");
}
void pantallaSalida(){
    system("color EB");
    system("cls");
    color(hcon, 181);
    gotoxy(30,21);cout << " ______     ______     ______     ______     __     ______     ______    ";
    gotoxy(30,22);cout << "/\\  ___\\   /\\  == \\   /\\  __ \\   /\\  ___\\   /\\ \\   /\\  __ \\   /\\  ___\\   ";
    gotoxy(30,23);cout << "\\ \\ \\__ \\  \\ \\  __<   \\ \\  __ \\  \\ \\ \\____  \\ \\ \\  \\ \\  __ \\  \\ \\___  \\  ";
    gotoxy(30,24);cout << " \\ \\_____\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\  \\ \\_____\\  \\ \\_\\  \\ \\_\\ \\_\\  \\/\\_____\\ ";
    gotoxy(30,25);cout << "  \\/_____/   \\/_/ /_/   \\/_/\\/_/   \\/_____/   \\/_/   \\/_/\\/_/   \\/_____/ ";
    color(hcon, 192);gotoxy(40,30);cout << "Presione cualquier tecla para continuar...";color(hcon, 11);
    color(hcon, 192);gotoxy(40,32);cout << "   Gracias por usar mi nuestro programa  ";color(hcon, 11);
    color(hcon, 192);gotoxy(40,33);cout << "   Villasenor Rivas Alejandro Rodrigo    ";color(hcon, 11);
    color(hcon, 192);gotoxy(40,34);cout << "             218414783                   ";color(hcon, 11);
    getch();
}
void selection(int idx, string name, string artist, string duration){
    gotoxy(2,8);cout << "-->";gotoxy(5,8);cout << char(186);
    gotoxy(6,8);color(hcon,192); cout << string(8, ' ');
    gotoxy(8,8);cout << idx;
    gotoxy(14,8);color(hcon,11);cout << char(186);
    gotoxy(15,8);color(hcon,192); cout << string(40, ' ');
    gotoxy(16,8);cout << name;
    gotoxy(56,8);color(hcon,192); cout << string(26, ' ');
    gotoxy(58,8);cout << artist;
    gotoxy(83,8);color(hcon,192); cout << string(13, ' ');
    gotoxy(86,8);cout << duration;
    color(hcon,11);
}
void tablero(){
    //130x50
    gotoxy(5,1);cout << char(201)<< string(90, char(205)) << char(203) << string(37, char(205)) << char(187);
    gotoxy(5,2);cout << char(186); color(hcon, 176); cout << string( 90 , ' '); color(hcon, 11); cout << char(186); color(hcon, 96); cout << string (37, ' '); color(hcon, 11);cout<< char(186);
    string title = "POP - PLAYER", title2 = "Repoductor MP3";
    gotoxy(5,3);cout << char(186); color(hcon, 176); cout << string(40, ' ') << title << string(38, ' '); color(hcon, 11);cout << char(186);color(hcon, 96); cout << string(11, ' ') << title2 << " " << char(16) << string(10, ' '); color(hcon, 11); cout << char(186);
    gotoxy(5,4);cout << char(186); color(hcon, 176); cout << string( 90 , ' '); color(hcon, 11); cout << char(186); color(hcon, 96); cout << string (37, ' '); color(hcon, 11); cout << char(186);
    gotoxy(5,5);cout << char(204) << string(8, char(205)) << char(203) << string(40, char(205)) << char(203) << string(26, char(205)) << char(203) << string(13, char(205)) << char(206) << string(4,char(205)) << char(203) << string(32, char(205)) << char(185);
    gotoxy(5,6);cout << char(186) <<" "<< "Indice" << " "<< char(186) << " " << "Nombre de la cancion" << string(19, ' ') << char(186) << " " << "Artista" << string(18, ' ') << char(186) << " " << "Duracion" << string(4, ' ') << char(186);
    cout<< " 1  " <<char (186) << " Registrar nueva cancion        " << char(186);
    gotoxy(5,7);cout << char(204) << string(8, char(205)) << char(206) << string(40, char(205)) << char(206) << string(26, char(205)) << char(206) << string(13, char(205)) << char(206) << string(4,char(205)) << char(206) << string(32, char(205)) << char(185);
    //Busqueda
    gotoxy(5,8);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << " 2  " << char(186) << " Buscar por: " << string(19, ' ') << char(186);
    gotoxy(5,9);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << "    " << char(186) << "     1. Indice" << string(18, ' ') << char(186);
    gotoxy(5,10);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << "    " << char(186) << "     2. Nombre de la cancion" << string(4, ' ') << char(186);
    gotoxy(5,11);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << "    " << char(186) << "     3. Nombre del artista" << string(6, ' ') << char(186);
    //Ordenamiento
    gotoxy(5,12);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(204) << string(4, char(205)) << char(206) << string(32, char(205)) << char(185);
    gotoxy(5,13);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << " 3  " << char(186) << " Ordenar por: " << string(18, ' ') << char(186);
    gotoxy(5,14);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << "    " << char(186) << "     1. Nombre de la cancion" << string(4, ' ') << char(186);
    gotoxy(5,15);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << "    " << char(186) << "     2. Nombre del artista" << string(6, ' ') << char(186);
    gotoxy(5,16);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << "    " << char(186) << "     3. Ascendente" << string(14, ' ') << char(186);
    gotoxy(5,17);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << "    " << char(186) << "     4. Descendente" << string(13, ' ') << char(186);
    //Invertir lista
    gotoxy(5,18);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(204) << string(4, char(205)) << char(206) << string(32, char(205)) << char(185);
    gotoxy(5,19);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << " 4  " << char(186) << " Invertir lista" << string(17, ' ') << char(186);
    //Editar cancion
    gotoxy(5,20);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(204) << string(4, char(205)) << char(206) << string(32, char(205)) << char(185);
    gotoxy(5,21);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << " 5  " << char(186) << " Editar cancion" << string(17, ' ') << char(186);
    //Remover cancion
    gotoxy(5,22);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(204) << string(4, char(205)) << char(206) << string(32, char(205)) << char(185);
    gotoxy(5,23);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << " 6  " << char(186) << " Remover cancion" << string(16, ' ') << char(186);
    //Vaciar playlist
    gotoxy(5,24);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(204) << string(4, char(205)) << char(206) << string(32, char(205)) << char(185);
    gotoxy(5,25);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << " 7  " << char(186) << " Vaciar playlist" << string(16, ' ') << char(186);
    //Reproducir cancion
    gotoxy(5,26);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(204) << string(4, char(205)) << char(206) << string(32, char(205)) << char(185);
    gotoxy(5,27);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << " 8  " << char(186) << " Reproducir cancion" << string(13, ' ') << char(186);
    //Mover a la izquierda
    gotoxy(5,28);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(204) << string(4, char(205)) << char(206) << string(32, char(205)) << char(185);
    gotoxy(5,29);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << " 9  " << char(186) << " Anterior            " << string(11, ' ') << char(186);
    //Mover a la derecha
    gotoxy(5,30);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(204) << string(4, char(205)) << char(206) << string(32, char(205)) << char(185);
    gotoxy(5,31);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << " 0  " << char(186) << " Siguiente         " << string(13, ' ') << char(186);
    //salir
    gotoxy(5,32);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(204) << string(4, char(205)) << char(206) << string(32, char(205)) << char(185);
    gotoxy(5,33);cout << char(186) << string(8, ' ') << char(186) << string(40, ' ') << char(186) << string(26, ' ') << char(186) << string(13, ' ') << char(186) << " 10 " << char(186) << char (25) << " Salir" << string(25, ' ') << char(186);
    //Linea inferior
    gotoxy(5,34);cout << char(204) << string(8, char(205)) << char(202) << string(40, char(205)) << char(202) << string(26, char(205)) << char(202) << string(13, char(205)) << char(206) << string(4, char(205)) << char(202)<< string(32, char(205)) << char(185);
    // Epacio para input y progressbar
    gotoxy(5,35);cout << char(186) << string(90, ' ')  << char(186) << string(37, ' ') << char(186);
    gotoxy(5,36);cout << char(186) << string(90, ' ')  << char(186) << string(37, ' ') << char(186);
    gotoxy(5,37);cout << char(186) << string(90, ' ')  << char(186) << string(37, ' ') << char(186);
    gotoxy(5,38);cout << char(186) << string(90, ' ')  << char(186) << string(37, ' ') << char(186);
    gotoxy(5,39);cout << char(186) << string(90, ' ')  << char(186) << string(37, ' ') << char(186);
    gotoxy(5,40);cout << char(186) << string(90, ' ')  << char(186) << string(37, ' ') << char(186);
    gotoxy(5,41);cout << char(186) << string(90, ' ')  << char(186) << string(37, ' ') << char(186);
    //Cerramos la tabla para abrir otra con tres columnas
    gotoxy(5,42);cout << char(204) << string(90, char(205)) << char(202) << string(37, char(205)) << char(185);
    gotoxy(5,43);cout << char(186) << string(128, ' ') << char(186);//Columna 1
    gotoxy(5,44);cout << char(204) << string(128, char(205)) << char(185);
    gotoxy(5,45);cout << char(186) << string(128, ' ') << char(186);//Columna 2
    gotoxy(5,46);cout << char(204) << string(128, char(205)) << char(185);
    gotoxy(5,47);cout << char(186) << string(128, ' ') << char(186);//Columna 3
    //Fin de la tabla
    gotoxy(5,48);cout << char(200) << string(128, char(205)) << char(188);
}
 void limpiarTabla(){
    int posY = 8;
    gotoxy(2,posY);cout << string(3, ' ');
    for(int i = 0; i < 26; i++){
        gotoxy(6, posY);cout << string(8, ' ');gotoxy(15, posY);cout << string(40, ' ');gotoxy(56, posY);cout << string(26, ' ');gotoxy(83, posY);cout << string(13, ' ');
        posY ++;
    }
}
void borrarRecuadro(){
    gotoxy(98, 36);cout << string(36, ' ');
    gotoxy(98, 35);cout << string(36, ' ');
    gotoxy(98, 37);cout << string(36, ' ');
    gotoxy(98, 38);cout << string(36, ' ');
    gotoxy(98, 40);cout << string(36, ' ');
    gotoxy(98, 39);cout << string(36, ' ');
    gotoxy(98, 41);cout << string(36, ' ');
}
void mostrarBusqueda(int idx, string name, string artist, string album, string genre){
    gotoxy(7, 43);cout << "Indice: " << idx;
    gotoxy(7, 45);cout << "Nombre: " << name; gotoxy(73, 45);cout << "Album: " << album;
    gotoxy(7, 47);cout << "Artista: " << artist; gotoxy(73, 47);cout << "Genero: " << genre;
}
void borrarBusqueda(){
    gotoxy(7, 43);cout << string(120, ' ');
    gotoxy(7, 45);cout << string(120, ' ');
    gotoxy(7, 47);cout << string(120, ' ');
}
void reproducir(string archivo){
    gotoxy(28,35);color(hcon,32);cout << "PRESIONE UNA TECLA PARA DETENER LA REPRODUCCION";color(hcon,11);
    int mitad = 50 - (archivo.length() / 2);//Centrar
    gotoxy(mitad, 40);color(hcon,215);cout << archivo;color(hcon,11);
}
void borrarReproduccion(){
    gotoxy(7, 35);cout << string(89, ' ');
    gotoxy(7, 36);cout << string(89, ' ');
    gotoxy(7, 37);cout << string(89, ' ');
    gotoxy(7, 38);cout << string(89, ' ');
    gotoxy(7, 39);cout << string(89, ' ');
    gotoxy(7, 40);cout << string(89, ' ');
    gotoxy(7, 41);cout << string(89, ' ');
}
