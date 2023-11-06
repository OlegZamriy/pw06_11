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
T** addRowToBeginning(T** arr, int& rows, size_t*& array_rows_size, size_t new_row_size, const T* new_row) {
    size_t* new_array_rows_size = new size_t[rows + 1];
    new_array_rows_size[0] = new_row_size;

    for (int i = 0; i < rows; i++) {
        new_array_rows_size[i + 1] = array_rows_size[i];
    }

    T** new_arr = new T * [rows + 1];
    new_arr[0] = new T[new_row_size];

    for (size_t i = 0; i < new_row_size; i++) {
        new_arr[0][i] = new_row[i];
    }

    for (int i = 0; i < rows; i++) {
        new_arr[i + 1] = arr[i];
    }

    delete[] arr;
    delete[] array_rows_size;

    array_rows_size = new_array_rows_size;
    arr = new_arr;
    rows++;

    return arr;
}

int main() {
    srand(time(0));

    int items, rows;
    cout << "rows item = ";
    cin >> rows;
    size_t* array_rows_size = new size_t[rows];
    int** arr_d = new int* [rows];

    for (size_t i = 0; i < rows; i++) {
        cout << "items[" << i << "] = ";
        cin >> items;
        array_rows_size[i] = items;
        arr_d[i] = new int[items];

        for (size_t j = 0; j < items; j++) {
            arr_d[i][j] = rand() % 10;
        }
    }

    showArray(arr_d, rows, array_rows_size);
    cout << endl << endl;

    size_t new_size = 10;
    int new_row[] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    arr_d = addRowToBeginning<int>(arr_d, rows, array_rows_size, new_size, new_row);
    showArray(arr_d, rows, array_rows_size);

    return 0;
}
