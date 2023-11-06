#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void showArray(T** arr, int rows, size_t* array_rows_size) {
    cout << "Array dynamic:" << endl;
    for (int i = 0; i < rows; i++) {
        for (size_t j = 0; j < array_rows_size[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
T** addRowTo2DArray(T** arr, int& rows, size_t*& array_rows_size, size_t new_row_size, const T* new_row) {
    size_t* new_array_rows_size = new size_t[rows + 1];
    for (int i = 0; i < rows; i++) {
        new_array_rows_size[i] = array_rows_size[i];
    }

    new_array_rows_size[rows] = new_row_size;
    rows++;
    T** new_arr = new T * [rows];
    for (int i = 0; i < rows - 1; i++) {
        new_arr[i] = arr[i];
    }
    new_arr[rows - 1] = new T[new_row_size];
    for (size_t i = 0; i < new_row_size; i++) {
        new_arr[rows - 1][i] = new_row[i];
    }
    delete[] arr;
    delete[] array_rows_size;
    array_rows_size = new_array_rows_size;
    arr = new_arr;
    return arr;
}

int main() {
    srand(time(0));

    int rows, items;
    cout << "Number of rows: ";
    cin >> rows;
    size_t* array_rows_size = new size_t[rows];
    int** arr_d = new int* [rows];

    for (int i = 0; i < rows; i++) {
        cout << "Number of items in row " << i << ": ";
        cin >> items;
        array_rows_size[i] = items;
        arr_d[i] = new int[items];
        for (size_t j = 0; j < items; j++) {
            arr_d[i][j] = rand() % 10;
        }
    }

    showArray(arr_d, rows, array_rows_size);

    cout << endl << "Adding a new row:" << endl;
    size_t new_size = 5;
    int new_row[] = { 7, 8, 9, 10, 11 };
    arr_d = addRowTo2DArray(arr_d, rows, array_rows_size, new_size, new_row);

    showArray(arr_d, rows, array_rows_size);

    return 0;
}
