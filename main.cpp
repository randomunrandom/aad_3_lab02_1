/*
 * created by Danil Kireev, PFUR NFI-201,12.09.18, 09:50/10:40
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

/*
 * № 17
 * Дана матрица размера M x N
 * В каждой ее строке найти количество элементов, меньших среднего арифметического всех элементов этой строки.
 */

int main() {
    int n, m, **A, *O, t;
    float sum, *S;
    cout << "вычисление количества элементов, меньших среднего арифметического всех элементов этой строки" << endl;
    cout << "Выберите тип ввода:\n-  1:заполнение вручную\n-  2:заполнение из файла" << endl;
    cin >> t;
    switch(t) {
	  	case 0: {
            srand((unsigned) (time(nullptr)));
            cout << "введите количество строк(N)" << endl;
            cin >> n;
            while (n<=0) {
                cout << "введите положительное кол-во строк(N)" << endl;;
                cin >> n;
            }
            cout << "введите количество столбцов(M)" << endl;
            cin >> m;
            while (m<=0) {
                cout << "введите положительное количество столбцов(M)";
                cin >> m;
            }
            A = new int*[n];
            for (int i = 0; i < n; ++i) A[i] = new int[m];
            O = new int[n];
            S = new float[n];
            cout << "полученная матрица: " << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    A[i][j]=rand()%100;
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            for (int i = 0; i < n; ++i) {
                sum=0;
                O[i]=0;
                for (int j = 0; j < m; ++j) sum+=A[i][j];
                sum/=m;
                S[i]=sum;
                for (int j = 0; j < m; ++j) if(A[i][j]<sum) O[i]++;
            }
            for (int i = 0; i < n; ++i) {
                cout << "строка: " << i << " количество элементов: " << O[i];
                cout << ", среднее арифметическое: " << S[i] << endl;
            }
            break;
        }
        case 1: {
            cout << "введите количество строк(N)" << endl;
            cin >> n;
            while (n<=0) {
                cout << "введите положительное кол-во строк(N)" << endl;;
                cin >> n;
            }
            cout << "введите количество столбцов(M)" << endl;
            cin >> m;
            while (m<=0) {
                cout << "введите положительное количество столбцов(M)";
                cin >> m;
            }
            A = new int*[n];
            for (int i = 0; i < n; ++i) A[i] = new int[m];
            O = new int[n];
            S = new float[n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << "введите элемент" << i << " " << j << endl;
                    cin >> A[i][j];
                }
                cout << endl;
            }
            for (int i = 0; i < n; ++i) {
                sum=0;
                O[i]=0;
                for (int j = 0; j < m; ++j) sum+=A[i][j];
                sum/=m;
                S[i]=sum;
                for (int j = 0; j < m; ++j) if(A[i][j]<sum) O[i]++;
            }
            for (int i = 0; i < n; ++i) {
                cout << "строка: " << i << " количество элементов: " << O[i];
                cout << ", среднее арифметическое: " << S[i] << endl;
            }
            break;
        }
        case 2: {
            string line;
            ifstream fin;
            fin.open( "/home/danai/Projects/c-cpp/aad_3_lab02_1/input", ios::in);
            ofstream fout;
            fout.open("/home/danai/Projects/c-cpp/aad_3_lab02_1/output", ios::out);
            getline(fin, line, ';');
            try {
                n = stoi(line);
            }
            catch(...) {
                cout << "Ошибка считывания" << endl;
                return 0;
            }
            cout << "количество строк(N): " << n << endl;
            getline(fin, line, ';');
            try {
                m = stoi(line);
            }
            catch(...) {
                cout << "Ошибка считывания" << endl;
                return 0;
            }
            cout << "количество столбцов(M): " << m << endl;
            A = new int*[n];
            for (int i = 0; i < n; ++i) A[i] = new int[m];
            O = new int[n];
            S = new float[n];
            cout << "полученная матрица: " << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    getline(fin, line, ',');
                    try {
                        A[i][j]=stoi(line);
                    }
                    catch(...) {
                        cout << "Ошибка считывания" << endl;
                        return 0;
                    }
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            for (int i = 0; i < n; ++i) {
                sum=0;
                O[i]=0;
                for (int j = 0; j < m; ++j) sum+=A[i][j];
                sum/=m;
                S[i]=sum;
                for (int j = 0; j < m; ++j) if(A[i][j]<sum) O[i]++;
            }
            for (int i = 0; i < n; ++i) {
                cout << "строка: " << i << " количество элементов: " << O[i] << ", среднее арифметическое: " << S[i] << endl;
                fout << "строка: " << i << " количество элементов: " << O[i] << ", среднее арифметическое: " << S[i] << endl;
            }
            break;
        }
        default:break;
    }
    return 0;
}
