#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > A(n);
    for (int i = 0; i < n; i++)
        A[i].resize(n);
    int i = 1, j, k, p = n / 2;
    for (k = 1; k <= p; k++) {  /*Цикл по номеру витка*/
        for (j = k - 1; j < n - k + 1; j++)
            A[k - 1][j] = i++;  /*Определение значений верхнего гор столбца*/
        for (j = k; j < n - k + 1; j++)
            A[j][n - k] = i++;  /* --//-- По правому вертикальному столбцу*/
        for (j = n - k - 1; j >= k - 1; --j)
            A[n - k][j] = i++;  /* --//-- по нижнему горизонтальному столбцу*/
        for (j = n - k - 1; j >= k; j--)
            A[j][k - 1] = i++;  /* --//-- по левому вертикальному столбцу*/
    }
    if (n % 2 == 1) A[p][p] = n * n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            cout << setw(8) << A[i][j];
            if (j == n - 1) cout << endl;
        }
    return 0;
}