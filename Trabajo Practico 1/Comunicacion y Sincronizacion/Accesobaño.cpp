#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <sstream>
#include <string>
#include <semaphore>

using namespace std;

/*Compilacion y Ejecucion:
g++ -o accesoBaño ./accesoBaño.cpp
./accesoBaño */

// Declarar dos mutex globales

mutex acceso;
counting_semaphore<3> turno(3);

int cantidadMujeres = 0;
int cantidadHombres = 0;
int MujerEspera = 0;
int HombreEspera = 0;
char actual='N';

void mujeres() 
{
    turno.acquire(); 
    if( actual == 'H')
    {
      turno.release();
      while(actual=='H')
      {
        cout << "Mujer: esperando" << endl;
        this_thread::sleep_for(chrono::seconds(1));
      }
    }
    if(HombreEspera==0){
        acceso.lock();
        cantidadMujeres++;
        if(cantidadMujeres==1)
        {
            actual='M';
        }
        //cout << "Mujer esta ocupando el baño -CantidadHombres" + to_string(cantidadHombres) + "-CantidadMujeres" + to_string(cantidadMujeres) << endl;
        cout << "-CantidadHombres" + to_string(cantidadHombres) + "-CantidadMujeres" + to_string(cantidadMujeres) << endl;
        acceso.unlock();
        this_thread::sleep_for(chrono::seconds(2));
        acceso.lock();
        cantidadMujeres--;
        if(cantidadMujeres==0)
        {
            actual='N';
        }
        acceso.unlock();
        turno.release();
    }
}

void hombres() 
{
    turno.acquire(); 
    if( actual == 'M')
    {
      turno.release();
      while(actual=='M')
      {
        cout << "Hombre: esperando" << endl;
        this_thread::sleep_for(chrono::seconds(1));
      }
    }    
    if(MujerEspera==0){

        acceso.lock();
        cantidadHombres++;
        if(cantidadHombres==1)
        {
            actual='H';
        }
        //cout << "Hombre esta ocupando el baño -CantidadHombres" + to_string(cantidadHombres) + "-CantidadMujeres" + to_string(cantidadMujeres) << endl;
        cout << "-CantidadHombres" + to_string(cantidadHombres) + "-CantidadMujeres" + to_string(cantidadMujeres) << endl;
        acceso.unlock();
        this_thread::sleep_for(chrono::seconds(2));
acceso.lock();
        cantidadHombres--;
        if(cantidadHombres==0)
        {
            actual='N';
        }
        acceso.unlock();
        turno.release();
    }
}

int main(int argc, char* argv[]) 
{
    vector<thread> grupo1;
    vector<thread> grupo2;

    if (stoi(argv[1]) < 0)
    {
        cout << "Ingrese cantidad de hombres y mujeres mayor a 0 " << endl;
        return 0;
    }

    for (int i = 0; i < stoi(argv[1]) ;i++)
    {
        grupo1.push_back(thread(hombres));
    }

       for (int i = 0; i < stoi(argv[1]);i++)
    {
        grupo2.push_back(thread(mujeres));
    }

    for (auto& hilo : grupo1) {
        if (hilo.joinable()) {
            hilo.join();
        }
    }

    for (auto& hilo : grupo2) {
        if (hilo.joinable()) {
            hilo.join();
        }
    }
    return EXIT_SUCCESS;
}
