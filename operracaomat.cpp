#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

in main()
{
   int idade;
   double salario, altura;
   char genero;
   string nome;

   idade = 16;
   salario = 5.000;
   altura = 1,54;
   genero = "F";
   nome = "Nicole Beatriz Cascais Vídal";

    cout << fixed << setprecision (2);
    cout << "IDADE: " << idade  << endl;
    cout << "SALARIO: " << salario << endl;
    cout << "ALTURA: " << altura << endl;
    cout << "GENERO: " << genero << endl;
    cout << "NOME: " << nome << endl;
    
    return 0;
}