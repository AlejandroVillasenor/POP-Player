/*  - Villasenor Rivas Alejandro Rodrigo.
    - Ingenieria en Computacion.
    - Codigo: 218414783.
    - Materia: Estructura de Datos.
    - Profesor: Ramiro Lupercio Coronel.

    REPRODUCTOR MP3 CON C++ Y PLAY SOUND.

    POP PLAYER
*/
//Librerias
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include  "validation.hpp"
#include "interface.hpp"
using namespace std;
#define color SetConsoleTextAttribute
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
bool stop = false;
//Windows size: Height(50) and Width(120) = 120 x 50

string toUpper(string str){
    int longitud = str.length();
    for(int i = 0; i < longitud; i++){
        str[i] = toupper(str[i]);
    }
    return str;
}

//Class Song
class Song {
    private:
        int index;
        string name;
        string artist;
        string time;
        string album;
        string genre;
    public:
        void setIndex(int);
        int getIndex();
        void setName(string);
        string getName();
        void setTime(string);
        string getTime();
        void setArtist(string);
        string getArtist();
        void setAlbum(string);
        string getAlbum();
        void setGenre(string);
        string getGenre();
};
void Song::setIndex(int index){
    this->index = index;
}
int Song::getIndex(){
    return this->index;
}
void Song::setName(string name){
    this->name = name;
}
string Song::getName(){
    return this->name;
}
void Song::setTime(string time){
    this->time = time;
}
string Song::getTime(){
    return this->time;
}
void Song::setArtist(string artist){
    this->artist = artist;
}
string Song::getArtist(){
    return this->artist;
}
void Song::setAlbum(string album){
    this->album = album;
}
string Song::getAlbum(){
    return this->album;
}
void Song::setGenre(string genre){
    this->genre = genre;
}
string Song::getGenre(){
    return this->genre;
}

//Class Node
class Node {
    public:
        Node(int, string, string, string, string, string);
        int index;
        string name;
        string artist;
        string time;
        string album;
        string genre;
        Node *next;
        Node *back;
};
Node::Node(int index, string name, string artist, string time, string album, string genre){
    this->index = index;
    this->name = name;
    this->artist = artist;
    this->time = time;
    this->album = album;
    this->genre = genre;
    this->next = NULL;
    this->back = NULL;
}

//Class Circular List
class CircularList{
    private:
        Node *ptrHead;
        int numNodes;
    public:
        CircularList();
        void showHead();
        bool repeat(int);
        void chargeSongs();
        void insertSong(Song);
        bool empty();
        void print(int);
        void searchByIndex(int);
        void searchByName(string);
        void searchByArtist(string);
        void sortAsc();
        void sortDesc();
        void sortByName();
        void sortByArtist();
        Node *invert();
        void editSong(int);
        void editFile(int, string, string, string, string, string);
        void deleteSong(int);
        void deleteInFile(int);
        void deleteAll();
        void moveTo(int);
        void play();
};
CircularList::CircularList(){
    this->ptrHead = NULL;
    this->numNodes = 0;
}
void CircularList::showHead(){
    if(empty()){
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";

    }else{
        borrarBusqueda();
        mostrarBusqueda(ptrHead->index, ptrHead->name, ptrHead->artist, ptrHead->album, ptrHead->genre);
    }
}
bool CircularList::repeat(int idx){
    if(empty()){
        return false;
    }else{
        Node *temp = ptrHead;
        while(temp->next != ptrHead){
            if(temp->index == idx){
                return true;
            }
            temp = temp->next;
        }
        if(temp->index == idx){
            return true;
        }
        return false;
    }
}
void CircularList::insertSong(Song song){
    fstream file;
    file.open("playlist.txt", ios::app);
    file << song.getIndex() << endl;
    file << song.getName() << endl;
    file << song.getArtist() << endl;
    file << song.getTime() << endl;
    file << song.getAlbum() << endl;
    file << song.getGenre() << endl;
    file << "----" << endl;
    file.close();

    //Agregar el nuevo nodo a la lista
    Node *new_node = new Node(song.getIndex(), song.getName(), song.getArtist(), song.getTime(), song.getAlbum(), song.getGenre());
    if(empty()){
        ptrHead = new_node;
        ptrHead->next = ptrHead;
        ptrHead->back = ptrHead;
    } else {
        Node *temp = ptrHead;
        while(temp->next != ptrHead){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->back = temp;
        new_node->next = ptrHead;
        ptrHead->back = new_node;
    }
    numNodes++;
}
void CircularList::chargeSongs(){//Cargar las canciones del txt a la lista la primera vez que se ejecuta el programa
    //Validamos si el archivo no esta vacio
    fstream file;
    file.open("playlist.txt", ios::in);
    if(!file.fail()){
        //Identificador del seprador de nodos "----"
        string end = "----";
        //Variables para almacenar los datos del txt
        int index;
        string name;
        string artist;
        string time;
        string album;
        string genre;
        string cadena;
        Node *new_node = NULL;
        while(getline(file, cadena)){
            if(cadena == end){
                // Agregar el nuevo nodo a la lista solo si se han leído todos los datos necesarios
                if(new_node != NULL){
                    if(empty()){
                        ptrHead = new_node;
                        ptrHead->next = ptrHead;
                        ptrHead->back = ptrHead;
                    } else {
                        Node *temp = ptrHead;
                        while(temp->next != ptrHead){
                            temp = temp->next;
                        }
                        temp->next = new_node;
                        new_node->back = temp;
                        new_node->next = ptrHead;
                        ptrHead->back = new_node;
                    }
                }
                // Reiniciar el puntero al nuevo nodo
                new_node = NULL;//Puede ser NULL
            } else {
                // Leer los datos del archivo y asignarlos a las variables correspondientes
                index = atoi(cadena.c_str());
                getline(file, name);
                getline(file, artist);
                getline(file, time);
                getline(file, album);
                getline(file, genre);
                // Crear un nuevo nodo solo si aún no se ha creado uno en esta iteración
                if(new_node == NULL){
                    new_node = new Node(index, name, artist, time, album, genre);
                }
            }
        }
    }
    file.close();
}
bool CircularList::empty(){
    if(this->ptrHead == NULL){
        return true;
    } else {
        return false;
    }
}
void CircularList::print(int initialPosY){
    int posY = initialPosY;
    if(!empty()){
        Node *temp = ptrHead;
        do{
            if(posY == initialPosY){
                selection(temp->index, temp->name, temp->artist, temp->time);
            }else{
                gotoxy(8, posY);cout << temp->index;
                gotoxy(16, posY);cout << temp->name;
                gotoxy(58, posY);cout << temp->artist;
                gotoxy(86, posY);cout << temp->time;

            }
            posY = posY + 1;
            temp = temp->next;
        } while(temp != ptrHead);
    }
}
void CircularList::searchByIndex(int idx){
    if(!empty()){
        borrarBusqueda();
        Node *temp = ptrHead;
        bool found = false;
        do{
            if(temp->index == idx){
                mostrarBusqueda(temp->index, temp->name, temp->artist, temp->album, temp->genre);
                Sleep(5000);
                found = true;
                break;
            }
            temp = temp->next;
        } while(temp != ptrHead);
        if(!found){
            borrarBusqueda();
            gotoxy(54, 45);cout << "No se encontro la cancion...";
            Sleep(4000);
        }
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
    borrarBusqueda();
}
void CircularList::searchByName(string name){
    if(!empty()){
        borrarBusqueda();
        Node *temp = ptrHead;
        bool found = false;
        do{
            if(temp->name == name){
                mostrarBusqueda(temp->index, temp->name, temp->artist, temp->album, temp->genre);
                Sleep(5000);
                found = true;
                break;
            }
            temp = temp->next;
        } while(temp != ptrHead);
        if(!found){
            borrarBusqueda();
            gotoxy(54, 45);cout << "No se encontro la cancion...";
            Sleep(4000);
        }
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
    borrarBusqueda();
}
void CircularList::searchByArtist(string artist){
    if(!empty()){
        borrarBusqueda();
        Node *temp = ptrHead;
        bool found = false;
        do{
            if(temp->artist == artist){
                mostrarBusqueda(temp->index, temp->name, temp->artist, temp->album, temp->genre);
                Sleep(5000);
                found = true;
                break;
            }
            temp = temp->next;
        } while(temp != ptrHead);
        if(!found){
            borrarBusqueda();
            gotoxy(54, 45);cout << "No se encontro la cancion...";
            Sleep(4000);
        }
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
    borrarBusqueda();
}
void CircularList::sortAsc(){//Usando el indice
    if (!empty()) {
        Node *temp = ptrHead;
        Node *temp2 = ptrHead;
        int auxIndex;
        string auxName, auxArtist, auxTime, auxAlbum, auxGenre;
        do{
            do{
                if(temp->index > temp2->index){
                    auxIndex = temp->index;
                    auxName = temp->name;
                    auxArtist = temp->artist;
                    auxTime = temp->time;
                    auxAlbum = temp->album;
                    auxGenre = temp->genre;

                    temp->index = temp2->index;
                    temp->name = temp2->name;
                    temp->artist = temp2->artist;
                    temp->time = temp2->time;
                    temp->album = temp2->album;
                    temp->genre = temp2->genre;

                    temp2->index = auxIndex;
                    temp2->name = auxName;
                    temp2->artist = auxArtist;
                    temp2->time = auxTime;
                    temp2->album = auxAlbum;
                    temp2->genre = auxGenre;
                }
                temp2 = temp2->next;
            }while(temp2 != ptrHead);
            temp = temp->next;
            temp2 = temp;
        } while (temp != ptrHead);
        limpiarTabla();
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
}
void CircularList::sortDesc(){
    if (!empty()) {
        Node *temp = ptrHead;
        Node *temp2 = ptrHead;
        int auxIndex;
        string auxName, auxArtist, auxTime, auxAlbum, auxGenre;
        do{
            do{
                if(temp->index < temp2->index){
                    auxIndex = temp->index;
                    auxName = temp->name;
                    auxArtist = temp->artist;
                    auxTime = temp->time;
                    auxAlbum = temp->album;
                    auxGenre = temp->genre;

                    temp->index = temp2->index;
                    temp->name = temp2->name;
                    temp->artist = temp2->artist;
                    temp->time = temp2->time;
                    temp->album = temp2->album;
                    temp->genre = temp2->genre;

                    temp2->index = auxIndex;
                    temp2->name = auxName;
                    temp2->artist = auxArtist;
                    temp2->time = auxTime;
                    temp2->album = auxAlbum;
                    temp2->genre = auxGenre;
                }
                temp2 = temp2->next;
            }while(temp2 != ptrHead);
            temp = temp->next;
            temp2 = temp;
        } while (temp != ptrHead);
        limpiarTabla();
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
}
void CircularList::sortByName(){
    if(!empty()){
        Node *temp = ptrHead;
        Node *temp2 = ptrHead;
        int auxIndex;
        string auxName, auxArtist, auxTime, auxAlbum, auxGenre;
        do {
            do {
                if(temp->name > temp2->name){
                    auxIndex = temp->index;
                    auxName = temp->name;
                    auxArtist = temp->artist;
                    auxTime = temp->time;
                    auxAlbum = temp->album;
                    auxGenre = temp->genre;

                    temp->index = temp2->index;
                    temp->name = temp2->name;
                    temp->artist = temp2->artist;
                    temp->time = temp2->time;
                    temp->album = temp2->album;
                    temp->genre = temp2->genre;

                    temp2->index = auxIndex;
                    temp2->name = auxName;
                    temp2->artist = auxArtist;
                    temp2->time = auxTime;
                    temp2->album = auxAlbum;
                    temp2->genre = auxGenre;
                }
                temp2 = temp2->next;
            } while(temp2 != ptrHead);
            temp = temp->next;
            temp2 = temp;
        } while (temp != ptrHead);
        limpiarTabla();
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
}

void CircularList::sortByArtist(){
    if(!empty()){
        Node *temp = ptrHead;
        Node *temp2 = ptrHead;
        int auxIndex;
        string auxName, auxArtist, auxTime, auxAlbum, auxGenre;
        do {
            do {
                if(temp->artist > temp2->artist){
                    auxIndex = temp->index;
                    auxName = temp->name;
                    auxArtist = temp->artist;
                    auxTime = temp->time;
                    auxAlbum = temp->album;
                    auxGenre = temp->genre;

                    temp->index = temp2->index;
                    temp->name = temp2->name;
                    temp->artist = temp2->artist;
                    temp->time = temp2->time;
                    temp->album = temp2->album;
                    temp->genre = temp2->genre;

                    temp2->index = auxIndex;
                    temp2->name = auxName;
                    temp2->artist = auxArtist;
                    temp2->time = auxTime;
                    temp2->album = auxAlbum;
                    temp2->genre = auxGenre;
                }
                temp2 = temp2->next;
            } while (temp2 != ptrHead);
            temp = temp->next;
            temp2 = temp;
        } while (temp != ptrHead);
        limpiarTabla();
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
}
Node *CircularList::invert(){
    if(!empty()){
        Node *current_head = ptrHead;
        Node *temp = ptrHead;
        Node *aux = ptrHead->next;
        //Hacemos que la cabeza sea el ultimo nodo
        current_head->next = current_head->back;
        current_head->back = aux;
        //Invertimos los demas nodos
        while(aux != ptrHead){
            temp = aux->next;
            aux->next = aux->back;
            aux->back = temp;
            aux = temp;
        }
        //Actualizamos la cabeza
        ptrHead = aux->next;
        limpiarTabla();
/*         print(); */
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
    return ptrHead;
}
void CircularList::editSong(int idx){
    if(!empty()){
        //Comprobamos que existea la cancion
        Node *temp = ptrHead;
        bool found = false, ban = false;
        string validation;
        do{
            if(temp->index == idx){
                found = true;
                break;
            }
            temp = temp->next;
        } while(temp != ptrHead);
        if(!found){
            borrarBusqueda();
            gotoxy(54, 45);cout << "No se encontro la cancion...";
            Sleep(4000);
        }else{
            //Pedimos los datos
            fflush(stdin);
            string name, artist, time, album, genre;
            gotoxy(98, 36);cout << string(36, ' ');
            gotoxy(98, 36);cout << "Nuevo nombre: ";
            getline(cin, name);
            name = toUpper(name);
            gotoxy(98, 36);cout << string(36, ' ');
            gotoxy(98, 36);cout << "Nuevo artista: ";
            getline(cin, artist);
            artist = toUpper(artist);
            gotoxy(98, 36);cout << string(36, ' ');
            do{
            fflush(stdin);
            gotoxy(98, 36);cout << string(36, ' ');
            gotoxy(98, 36);cout << "Nueva duracion: ";
            getline(cin, validation);
            if(validtime(&validation)){
                time = validation;
                ban = true;
            } else {
                gotoxy(98, 36);cout << string(36, ' ');
                gotoxy(98, 36);cout << "Duracion no valida";
                Sleep(1000);
                ban = false;
            }
            }while(!ban);
            gotoxy(98, 36);cout << string(36, ' ');
            gotoxy(98, 36);cout << "Nuevo album: ";
            getline(cin, album);
            album = toUpper(album);
            gotoxy(98, 36);cout << string(36, ' ');
            gotoxy(98, 36);cout << "Nuevo genero: ";
            getline(cin, genre);
            genre = toUpper(genre);
            //Actualizamos los datos
            temp->name = name;
            temp->artist = artist;
            temp->time = time;
            temp->album = album;
            temp->genre = genre;
            limpiarTabla();
            //Editamos el archivo
            editFile(idx, name, artist, time, album, genre);
            borrarBusqueda();
            gotoxy(54, 45);cout << "Cancion editada con exito...";
        }
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
}
void CircularList::editFile(int indice, string name, string artist, string time, string album, string genre){
    //Eitamos el archivo usando uno auxiliar
    fstream file;
    file.open("playlist.txt", ios::in);
    ofstream temp("temp.txt");
    string line;
    string end = "----";
    if(file.fail()){
        borrarBusqueda();
        gotoxy(54, 45);cout << "No se pudo abrir el archivo...";
        Sleep(4000);
    }else{
        //Pasamos todos los archivos al auxiliar y editamos el que se necesita
        while(getline(file, line)){
            if(line == to_string(indice)){
                temp << line << endl;
                getline(file, line);
                temp << name << endl;
                getline(file, line);
                temp << artist << endl;
                getline(file, line);
                temp << time << endl;
                getline(file, line);
                temp << album << endl;
                getline(file, line);
                temp << genre << endl;
                getline(file, line);
                temp << end << endl;
            }else{
                temp << line << endl;
            }
        }
    }
    file.close();
    temp.close();
    //Eliminamos el archivo original y renombramos el auxiliar
    remove("playlist.txt");
    rename("temp.txt", "playlist.txt");
}
void CircularList::deleteSong(int idx){
    if(!empty()){
        //Comprobamos que existea la cancion
        Node *temp = ptrHead;
        bool found = false;
        do{
            if(temp->index == idx){
                found = true;
                break;
            }
            temp = temp->next;
        } while(temp != ptrHead);
        if(!found){
            borrarBusqueda();
            gotoxy(54, 45);cout << "No se encontro la cancion...";
            Sleep(4000);
        }else{
            //Eliminamos la cancion
            Node *aux = temp;
            Node *lastNode = ptrHead->back;
            //Si solo hay un nodo
            if(aux == ptrHead && aux == lastNode){
                ptrHead = NULL;
            }else{
                //Si hay mas de un nodo
                if(aux == ptrHead){
                    ptrHead = ptrHead->next;
                }
                if(aux == lastNode){
                    lastNode = lastNode->back;
                }
                aux->back->next = aux->next;
                aux->next->back = aux->back;
            }
            delete aux;
            limpiarTabla();
            //Editamos el archivo
            deleteInFile(idx);
            borrarBusqueda();
            gotoxy(54, 45);cout << "Cancion eliminada con exito...";
            numNodes--;
        }
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }


}
void CircularList::deleteInFile(int indice){
    //Eliminamos la cancion del archivo
    fstream file;
    file.open("playlist.txt", ios::in);
    ofstream temp("temp.txt");
    string line;
    string end = "----";
    if(file.fail()){
        borrarBusqueda();
        gotoxy(54, 45);cout << "No se pudo abrir el archivo...";
        Sleep(4000);
    }else{
        //Pasamos todos los archivos al auxiliar sin pasar el que se necesita eliminar
        while(getline(file, line)){
            if(line == to_string(indice)){
                getline(file, line);
                getline(file, line);
                getline(file, line);
                getline(file, line);
                getline(file, line);
                getline(file, line);
            }else{
                temp << line << endl;
            }
        }
    }
    file.close();
    temp.close();
    //Eliminamos el archivo original y renombramos el auxiliar
    remove("playlist.txt");
    rename("temp.txt", "playlist.txt");
}
void CircularList::deleteAll(){
    if(!empty()){
        //Eliminamos todas las canciones
        Node *temp = ptrHead;
        Node *aux;
        do{
            aux = temp;
            temp = temp->next;
            delete aux;
        }while(temp != ptrHead);
        ptrHead = NULL;
        limpiarTabla();
        //Eliminamos el archivo
        remove("playlist.txt");
        //Creamos un nuevo archivo
        ofstream file("playlist.txt");
        file.close();
        gotoxy(98, 37);cout << string(36, ' ');
        Sleep(4000);
        borrarBusqueda();
        gotoxy(54, 45);cout << "Todas las canciones han sido eliminadas...";
        numNodes = 0;
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
}
void CircularList::moveTo(int opc){
    if (!empty()) {
        Node *temp = ptrHead;
        if(opc==1){
            temp = temp->next;
            ptrHead=temp;
        }else if(opc==2){
            temp = temp->back;
            ptrHead=temp;
        }
        limpiarTabla();
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
}
void CircularList::play(){
    if(!empty()){
        //Reproducimos la cancion
        Node *temp = ptrHead;
        string duracion = temp->time;
        //Obtenemos los minutos y segundos de MM:SS
        float min = stof(duracion.substr(0, 2));
        float seg = stof(duracion.substr(3, 2));
        //Obtenemos el tiempo total en minutos
        float minutosTotal = min + (seg / 60.0);
        //convertimos los minutos a milisegundos
        float segtotal = (minutosTotal * 60);
        string archivo = temp->artist +  " - " + temp->name;
        reproducir(archivo);
        //Convertimos el archivo a LPCTSTR
        string archivo_completo = archivo + ".wav";
        PlaySoundA(archivo_completo.c_str(), NULL, SND_ASYNC | SND_FILENAME);
        int porcentaje, cont2 = 1;
        for(int i = 0; i < 82 && !stop; i++){
            if(kbhit()){
                stop = true;
            }
            gotoxy(10 + i, 37); cout << (char)219;
            porcentaje = (cont2 * 100) / 82;
            gotoxy(10, 39); cout << porcentaje << "%";
            cont2++;
            Sleep((segtotal * 1000 / 82));
        }
        borrarReproduccion();
        PlaySound(NULL, NULL, SND_ASYNC);
        stop = false;
    }else{
        borrarBusqueda();
        gotoxy(54, 45);cout << "No hay canciones en la lista...";
        Sleep(4000);
    }
}

//Funcion principal
int main(){
//Asignamos el tamanio fijo de la terminal
    system("mode con: cols=142 lines=50");
    //objetos
    Song song;
    CircularList *list = new CircularList();
    int index, initialPosY = 8;
    string name, artist, time, album, genre;
    bool ban = false, exit = false, ban2 = false, ban4 = false;
    system("color EB");
    pantallaInicial();
    system("color 0B");
    tablero();
    int option;
    string validation;
    list->chargeSongs();
    do{
        gotoxy(98, 36);
        list->print(initialPosY);
        list->showHead();
        do{
            gotoxy(98, 35);cout << string(36, ' ');
            gotoxy(98, 35);cout << "Selecciona una opcion: ";
            cin >> validation;
            if(validintP(&validation)){
                ban = true;
                option = stoi(validation);
                switch(option){
                    case 1:{
                        borrarRecuadro();
                        gotoxy(98, 35);cout << "Registrar cancion...";
                        do{
                            fflush(stdin);
                            gotoxy(98, 36);cout << "Indice: ";
                            cin >> validation;
                            if(validintP(&validation)){
                                index = stoi(validation);
                                if(!list->repeat(index)){
                                    song.setIndex(index);
                                    ban = true;
                                }else{
                                    gotoxy(98, 36);cout << string(36, ' ');
                                    gotoxy(98, 36);cout << "Indice repetido";
                                    Sleep(1000);
                                    gotoxy(98, 36);cout << string(36, ' ');
                                    ban = false;
                                }
                            } else {
                                gotoxy(98, 36);cout << string(36, ' ');
                                gotoxy(98, 36);cout << "Indice no valido";
                                Sleep(1000);
                                gotoxy(98, 36);cout << string(36, ' ');
                                ban = false;
                            }
                        }while(!ban);
                        fflush(stdin);
                        gotoxy(98, 36);cout << string(36, ' ');
                        gotoxy(98, 36);cout << "Nombre: ";
                        getline(cin, name);
                        name = toUpper(name);
                        song.setName(name);
                        fflush(stdin);
                        gotoxy(98, 36);cout << string(36, ' ');
                        gotoxy(98, 36);cout << "Artista: ";
                        getline(cin, artist);
                        artist = toUpper(artist);
                        song.setArtist(artist);
                        do{
                            fflush(stdin);
                            gotoxy(98, 36);cout << string(36, ' ');
                            gotoxy(98, 36);cout << "Duracion: ";
                            getline(cin, validation);
                            if(validtime(&validation)){
                                time = validation;
                                song.setTime(time);
                                ban = true;
                            } else {
                                gotoxy(98, 36);cout << string(36, ' ');
                                gotoxy(98, 36);cout << "Duracion no valida";
                                Sleep(1000);
                                ban = false;
                            }
                        }while(!ban);
                        fflush(stdin);
                        gotoxy(98, 36);cout << string(36, ' ');
                        gotoxy(98, 36);cout << "Album: ";
                        getline(cin, album);
                        album = toUpper(album);
                        song.setAlbum(album);
                        do{
                            fflush(stdin);
                            gotoxy(98, 36);cout << string(36, ' ');
                            gotoxy(98, 36);cout << "Genero: ";
                            getline(cin, validation);
                            if(validtitle(&validation)){
                                validation = toUpper(validation);
                                genre = validation;
                                song.setGenre(genre);
                                ban = true;
                            } else {
                                gotoxy(98, 36);cout << string(36, ' ');
                                gotoxy(98, 36);cout << "Genero no valido";
                                Sleep(1000);
                                ban = false;
                            }
                        }while(!ban);
                        if(ban){
                            gotoxy(98, 36);cout << string(36, ' ');
                            gotoxy(98, 36);cout << "Cancion registrada";
                            Sleep(1000);
                            borrarRecuadro();
                        }
                        list->insertSong(song);
                        Sleep(1000);
                        borrarRecuadro();
                        fflush(stdin);
                        break;
                    }
                    case 2:{
                        do{
                        borrarRecuadro();
                        gotoxy(98, 35);cout << "Buscar cancion..." << endl;
                        gotoxy(98, 36);cout << "Tipo de busqueda: ";
                        cin >> validation;
                        if(validintP(&validation)){
                            ban2 = true;
                            option = stoi(validation);
                            switch(option){
                                case 1:{
                                    do{
                                        borrarRecuadro();
                                        gotoxy(98, 35);cout << "Ingresa indice: ";
                                        cin >> validation;
                                        if(validintP(&validation)){
                                            index = stoi(validation);
                                            list->searchByIndex(index);
                                            ban4 = true;
                                        } else {
                                            gotoxy(98, 36);cout << string(36, ' ');
                                            gotoxy(98, 36);cout << "Indice no valido";
                                            Sleep(1000);
                                            gotoxy(98, 36);cout << string(36, ' ');
                                            ban4 = false;
                                        }
                                    }while(!ban4);
                                    borrarRecuadro();
                                    break;
                                }
                                case 2:{
                                    do{
                                        borrarRecuadro();
                                        gotoxy(98, 35);cout << "Ingresa nombre: ";
                                        fflush(stdin);
                                        getline(cin, validation);
                                        if(validtitle(&validation)){
                                            validation = toUpper(validation);
                                            name = validation;
                                            list->searchByName(name);
                                            ban4 = true;
                                        } else {
                                            gotoxy(98, 36);cout << string(36, ' ');
                                            gotoxy(98, 36);cout << "Nombre no valido";
                                            Sleep(1000);
                                            gotoxy(98, 36);cout << string(36, ' ');
                                            ban4 = false;
                                        }
                                    }while(!ban4);
                                    borrarRecuadro();
                                    break;
                                }
                                case 3:{
                                    do{
                                        borrarRecuadro();
                                        gotoxy(98, 35);cout << "Ingresa artista: ";
                                        fflush(stdin);
                                        getline(cin, validation);
                                        if(validtitle(&validation)){
                                            validation = toUpper(validation);
                                            artist = validation;
                                            list->searchByArtist(artist);
                                            ban4 = true;
                                        } else {
                                            gotoxy(98, 36);cout << string(36, ' ');
                                            gotoxy(98, 36);cout << "Artista no valido";
                                            Sleep(1000);
                                            gotoxy(98, 36);cout << string(36, ' ');
                                            ban4 = false;
                                        }
                                    }while(!ban4);
                                    borrarRecuadro();
                                    break;
                                }
                                default:{
                                    gotoxy(98, 36);cout << string(36, ' ');
                                    gotoxy(98, 36);cout << "Opcion no valida";
                                    Sleep(1000);
                                    ban2 = false;
                                    borrarRecuadro();
                                    break;
                                }
                            }
                        } else {
                            gotoxy(98, 36);cout << string(36, ' ');
                            gotoxy(98, 36);cout << "Opcion no valida";
                            Sleep(1000);
                            gotoxy(98, 36);cout << string(36, ' ');
                            ban2 = false;
                        }
                        borrarRecuadro();
                        }while(!ban2);
                        break;
                    }
                    case 3:{
                        do{
                            borrarRecuadro();
                            gotoxy(98, 35);cout << "Ordenar por..." << endl;
                            gotoxy(98, 36);cout << "Tipo de ordenamiento: ";
                            cin >> validation;
                            if(validintP(&validation)){
                                ban2 = true;
                                option = stoi(validation);
                                switch(option){
                                    case 1:{
                                        list->sortByName();
                                        ban4 = true;
                                        break;
                                    }
                                    case 2:{
                                        list->sortByArtist();
                                        ban4 = true;
                                        break;
                                    }
                                    case 3:{
                                        list->sortAsc();
                                        ban4 = true;
                                        break;
                                    }
                                    case 4:{
                                        list->sortDesc();
                                        ban4 = true;
                                        break;
                                    }
                                    default:{
                                        gotoxy(98, 36);cout << string(36, ' ');
                                        gotoxy(98, 36);cout << "Opcion no valida";
                                        Sleep(1000);
                                        ban4 = false;
                                        borrarRecuadro();
                                        break;
                                    }
                                }
                            } else {
                                gotoxy(98, 36);cout << string(36, ' ');
                                gotoxy(98, 36);cout << "Opcion no valida";
                                Sleep(1000);
                                gotoxy(98, 36);cout << string(36, ' ');
                                ban2 = false;
                            }
                        }while(!ban2);
                        borrarRecuadro();
                        break;
                    }
                    case 4:{
                        borrarRecuadro();
                        gotoxy(98, 35);cout << "Lista invertida" << endl;
                        Sleep(200);
                        list->invert();
                        borrarRecuadro();
                        break;
                    }
                    case 5:{
                        do{
                            borrarRecuadro();
                            gotoxy(98, 35);cout << "Editar cancion" << endl;
                            gotoxy(98, 36);cout << "Ingresa indice: ";
                            cin >> validation;
                            if(validintP(&validation)){
                                index = stoi(validation);
                                list->editSong(index);
                                ban2 = true;
                            } else {
                                gotoxy(98, 37);cout << string(36, ' ');
                                gotoxy(98, 37);cout << "Indice no valido";
                                Sleep(1000);
                                gotoxy(98, 37);cout << string(36, ' ');
                                ban2 = false;
                            }
                        }while(!ban2);
                        borrarRecuadro();
                        break;
                    }
                    case 6:{
                        do{
                            borrarRecuadro();
                            gotoxy(98, 35);cout << "Eliminar cancion" << endl;
                            gotoxy(98, 36);cout << "Ingresa indice: ";
                            cin >> validation;
                            if(validintP(&validation)){
                                index = stoi(validation);
                                list->deleteSong(index);
                                ban2 = true;
                            } else {
                                gotoxy(98, 37);cout << string(36, ' ');
                                gotoxy(98, 37);cout << "Indice no valido";
                                Sleep(1000);
                                gotoxy(98, 37);cout << string(36, ' ');
                                ban2 = false;
                            }
                        }while(!ban2);
                        borrarRecuadro();
                        break;
                    }
                    case 7:{
                        borrarRecuadro();
                        gotoxy(98, 35);cout << "Vaciando playlist..." << endl;
                        list->deleteAll();
                        Sleep(1000);
                        borrarRecuadro();
                        break;
                    }
                    case 8:{
                        borrarRecuadro();
                        gotoxy(98, 35);cout << "Reproduciendo cancion..." << endl;
                        list->play();
                        borrarRecuadro();
                        gotoxy(98, 35); cout << "Cancion terminada" << endl;
                        Sleep(1000);
                        borrarRecuadro();
                        break;
                    }
                    case 9:{//Mover a la izquierda
                        list->moveTo(2);
                        break;
                    }
                    case 0:{//Mover a la derecha
                        list->moveTo(1);
                        break;
                    }
                    case 10:{
                        borrarRecuadro();
                        gotoxy(98, 35);cout << "Saliendo.." << endl;
                        exit = true;
                        Sleep(1000);
                        borrarRecuadro();
                        break;
                    }
                }
            }else{
                //PREGUNTAR
                borrarRecuadro();
                gotoxy(98, 35);cout << "Opcion no valida" << endl;
                Sleep(1000);
                borrarRecuadro();
            }
        }while(!ban);
    }while(!exit);
    pantallaSalida();
    system("cls");
    return 0;
}
