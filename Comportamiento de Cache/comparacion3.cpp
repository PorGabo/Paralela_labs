
//Implementar la versión por bloques (investigar en internet), 
//seis bucles anidados, evaluar su desempeño y compararlo con la multiplicación de matrices clásica.

#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void blockMultiplyMatrices(int n, vector<vector<double>>& A, vector<vector<double>>& B, vector<vector<double>>& C, int blockSize)
{
    for (int i0 = 0; i0 < n; i0 += blockSize)
    {
        for (int j0 = 0; j0 < n; j0 += blockSize)
        {
            for (int k0 = 0; k0 < n; k0 += blockSize)
            {
                for (int i = i0; i < min(i0 + blockSize, n); ++i)
                {
                    for (int j = j0; j < min(j0 + blockSize, n); ++j)
                    {
                        for (int k = k0; k < min(k0 + blockSize, n); ++k)
                        {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    const int sizes[] = {50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int blockSize = 64;  // Tamaño del bloque, ajustable según la arquitectura de la caché

    for (int n : sizes)
    {
        vector<vector<double>> A(n, vector<double>(n, 1.0));
        vector<vector<double>> B(n, vector<double>(n, 1.0));
        vector<vector<double>> C(n, vector<double>(n, 0.0));

        auto start = high_resolution_clock::now();
        blockMultiplyMatrices(n, A, B, C, blockSize);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);

        cout << "Ejecucion por bloques " << n << "x" << n << ": " << duration.count() << " ms" << endl;
    }
    cout << endl;
    return 0;
}
