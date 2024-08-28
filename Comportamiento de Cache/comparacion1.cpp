
//hecho y explicado en clase

//Implementar y comparar los 2-bucles anidados FOR presentados en el cap. 2 del libro, pag 22.
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define max 9999

double A[max][max], x[max], y[max];

int main()
{
    for (int tam = 1000; tam <= 10000; tam += 1000)
    {
        fill(y, y + tam, 0.0);
        //(I,J)
        auto start1 = high_resolution_clock::now();
        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                y[i] += A[i][j] * x[j];
            }
        }
        auto end1 = high_resolution_clock::now();
        auto duration1 = duration_cast<milliseconds>(end1 - start1);

        fill(y, y + tam, 0.0); //reinicio

        auto start2 = high_resolution_clock::now();
        //(J,I)
        for (int j = 0; j < tam; j++)
        {
            for (int i = 0; i < tam; i++)
            {
                y[i] += A[i][j] * x[j];
            }
        }
        auto end2 = high_resolution_clock::now();
        auto duration2 = duration_cast<milliseconds>(end2 - start2);

        cout << "Tamaño: " << tam << "x" << tam << endl;
        cout << "Primer Bucle: " << duration1.count() << " ms" << endl;
        cout << "Segundo Bucle: " << duration2.count() << " ms" << endl << endl;
    }

    return 0;
}
