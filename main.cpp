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
T** addRowToPosition(T** arr, int& col, size_t*& array_rows_size, size_t new_line_size, const T* new_row, int position)
{
    if (position < 0 || position > col) {
        cout << "Invalid position." << endl;
        return arr;
    }

    size_t* new_array_rows_size = new size_t[col + 1];
    for (size_t i = 0; i < position; i++)
    {
        new_array_rows_size[i] = array_rows_size[i];
    }

    new_array_rows_size[position] = new_line_size;

    for (size_t i = position; i < col; i++)
    {
        new_array_rows_size[i + 1] = array_rows_size[i];
    }

    col++;
    T** new_arr = new T * [col];
    for (size_t i = 0; i < position; i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[position] = new T[new_line_size];
    for (size_t i = 0; i < new_line_size; i++)
    {
        new_arr[position][i] = new_row[i];
    }
    for (size_t i = position + 1; i < col; i++)
    {
        new_arr[i] = arr[i - 1];
    }
    delete[] arr;
    delete[] array_rows_size;
    array_rows_size = new_array_rows_size;
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

    size_t new_size = 10;
    int new_row[] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

    int position;
    cout << "Enter the position to add the new row: ";
    cin >> position;

    arr_d = addRowToPosition<int>(arr_d, rows, array_rows_size, new_size, new_row, position);
    showArray(arr_d, rows, array_rows_size);

    return 0;
}
