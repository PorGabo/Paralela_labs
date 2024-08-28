
//Implementar en C/C++ la multiplicación de matrices clásica, la versión de tres bucles anidados
//y evaluar su desempeño considerando diferentes tamaños de matriz.

#include <iostream>
#include <vector>
#include <chrono>


using namespace std;
using namespace std::chrono;

void multiplyMatrices(int n, vector<vector<double>>& A, vector<vector<double>>& B, vector<vector<double>>& C)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j) 
        {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    const int sizes[] = {400};

    for (int n : sizes)
    {
        vector<vector<double>> A(n, vector<double>(n, 1.0));
        vector<vector<double>> B(n, vector<double>(n, 1.0));
        vector<vector<double>> C(n, vector<double>(n, 0.0));

        auto start = high_resolution_clock::now();
        multiplyMatrices(n, A, B, C);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);

        cout << "Ejecucion clasica " << n << "x" << n << ": " << duration.count() << " ms" << endl;
    }
    cout << endl;

    return 0;
}
