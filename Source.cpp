#include <random>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
	//NUMERO RANDOM
	std::random_device rd;  
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> distrib(1, 100);

	//ESCRIBIR EN UN CSV PARA CREAR GRÁFICOS
	
	/*std::ofstream file;
	std::string nombre = "100D";
	std::string direccion = "C://Users//LENOVO//Documents//AJR//VI SEMESTRE//EDA//Gráficos//";
	direccion.append(nombre);
	direccion.append(".csv");
	file.open(direccion, std::ios::out);*/

	//INICIALIZAMOS PUNTOS
	int D = 100;  //Dimensión
	int cantidad = 20000;
	int** valor = new int* [cantidad];
	for (int i = 0; i < cantidad; i++) {
		valor[i] = new int[D];
		for (int j = 0; j < D; j++) {
			valor[i][j] = distrib(gen);
		}
	}

	//ARRAY DONDE SE GUARDARÁN RESULTADOS
	int* distancia=new int[570];
	for (int i = 0; i < 570; i++) {
		distancia[i] = 0;
	}

	//CALCULAMOS LA DISTANCIA DEL PUNTO 1 A TODOS LOS DEMÁS
	int suma = 0;
	for (int i = 1; i < cantidad; i++) {
		suma = 0;
		for (int j = 0; j < D; j++) {
			suma += pow(valor[0][j] - valor[i][j], 2);
		}
		suma = sqrt(suma);
		distancia[suma] += 1;
	}

	//ESCRIBIMOS EN EL FILE O EN CONSOLA
	for (int i = 0; i < 570; i++) {
		if (distancia[i] != 0) {
			//file << i << "," << distancia[i]<<",\n";
			std::cout << i << "," << distancia[i]<<",\n";
		}
	}
	//file.close();   //Se cierra el file

	return 0;
}