#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void showArray(T** arr, size_t col, size_t* array_rows_size)
{
    cout << "Array dynamic: " << endl;
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < array_rows_size[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template<typename T>
T** addColumnToPosition(T** arr, int& col, size_t*& array_rows_size, size_t new_col_size, const T* new_column, int position)
{
    if (position < 0 || position > new_col_size) {
        cout << "Invalid position for adding a new column." << endl;
        return arr;
    }

    size_t* new_array_rows_size = new size_t[col];
    T** new_arr = new T * [col];

    for (size_t i = 0; i < col; i++)
    {
        new_array_rows_size[i] = array_rows_size[i] + 1;
        new_arr[i] = new T[new_array_rows_size[i]];

        for (size_t j = 0; j < position; j++)
        {
            new_arr[i][j] = arr[i][j];
        }

        new_arr[i][position] = new_column[i];

        for (size_t j = position + 1; j < new_array_rows_size[i]; j++)
        {
            new_arr[i][j] = arr[i][j - 1];
        }
    }

    delete[] array_rows_size;
    array_rows_size = new_array_rows_size;

    for (int i = 0; i < col; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    arr = new_arr;

    return arr;
}

int main()
{
    srand(time(0));

    int items, rows;
    cout << "rows item = ";
    cin >> rows;
    size_t* array_rows_size = new size_t[rows];
    int** arr_d = new int* [rows];

    for (size_t i = 0; i < rows; i++)
    {
        cout << "items[" << i << "] = ";
        cin >> items;
        array_rows_size[i] = items;
        arr_d[i] = new int[items];

        for (size_t j = 0; j < items; j++)
        {
            arr_d[i][j] = rand() % 10;
        }
    }

    showArray(arr_d, rows, array_rows_size);
    cout << endl << endl;

    int new_col_size = 10;
    int new_column[] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    int position;

    cout << "Enter the position to add the new column: ";
    cin >> position;

    arr_d = addColumnToPosition<int>(arr_d, rows, array_rows_size, new_col_size, new_column, position);
    showArray(arr_d, rows, array_rows_size);

    return 0;
}
