#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <thread>
#include <unistd.h> 
#include <vector>

using namespace std;

/*Compilacion y Ejecucion:
g++ -o contadorDeCaracteres ./contadorDeCaracteres.cpp
./contadorDeCaracteres rutaArchivo cantidadDeHilos*/

int total = 0;

void eliminarLineasVacias(const string& archivo_original, vector<string>& vector_lineas) 
{
    ifstream archivo_entrada(archivo_original);
    if (!archivo_entrada.is_open()) 
    {
        cerr << "Error al abrir el archivo de entrada." << endl;
        return;
    }
    string linea;
    while (getline(archivo_entrada, linea)) 
    {
        if (!linea.empty()) vector_lineas.push_back(linea);
    }
    archivo_entrada.close();
}

void contarCaracteresEnRango(vector<string>& vector_lineas, int inicio, int fin)
{
    sleep(10);
    int totalCaracteres = 0;
    if (inicio < 0) inicio = 0;
    if (fin >= vector_lineas.size()) fin = vector_lineas.size() - 1;
    for (int i = inicio; i <= fin; ++i)
    {
        totalCaracteres += vector_lineas[i].size(); 
    }
    cout << "Resultado Parcial: " + to_string(totalCaracteres) << endl;
    total += totalCaracteres;
    return;
}

void procesarArchivo(vector<string>& vector_lineas, int cantidad_de_hilos) 
{    
    int cantidad_lineas_por_archivo = vector_lineas.size() / cantidad_de_hilos;

    vector<thread> threads;

    for (int i = 0; i < cantidad_de_hilos;i++)
    {
        int indiceInferior = i*cantidad_lineas_por_archivo;
        int indiceSuperior = ((i+1)*cantidad_lineas_por_archivo) - 1;
        
        if(i == cantidad_de_hilos-1 && (vector_lineas.size() % cantidad_de_hilos != 0))
        {
            indiceSuperior += (vector_lineas.size() % cantidad_de_hilos);
        }
        threads.push_back(thread(contarCaracteresEnRango,ref(vector_lineas),indiceInferior,indiceSuperior));
    }

    for (auto& thread : threads)
    {
        thread.join();
    }
}

int main(int argc, char* argv[]) 
{
    cout << "PID: " << getpid() << endl;
    if (argc != 3) 
    {
        cerr << "Uso: " << argv[0] << " <archivo> <numero de threads>" << endl;
        return EXIT_FAILURE;
    }

    string nombre_archivo = argv[1];
    int cantidad_de_hilos = stoi(argv[2]);

    vector<string> vector_lineas;
    eliminarLineasVacias(nombre_archivo, vector_lineas);

    if(vector_lineas.size() < cantidad_de_hilos)
    {
        cout << "La cantidad de hilos supera la cantidad de lineas no vacias del archivo" << endl;
        return EXIT_FAILURE;
    } 

    auto start = chrono::high_resolution_clock::now();

    procesarArchivo(vector_lineas, cantidad_de_hilos);

    auto fin = chrono::high_resolution_clock::now();

    auto duracion = chrono::duration_cast<chrono::nanoseconds>(fin - start);

    cout << "Resultado Total: " + to_string(total) << endl;
    cout << "Tiempo de ejecución: " << (double)duracion.count()/1000000 << " ms" << endl;

    sleep(5);

    return EXIT_SUCCESS;
}
