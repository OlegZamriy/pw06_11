#include <iostream>
#include <ctime>

using namespace std;

template<typename T>
void showArray(T** arr, size_t col, size_t * array_rows_size)
{
    cout << "Array dynamic: "<< endl;
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
T** removeRow(T** arr, int &col, size_t* &array_rows_size, int row_to_remove)
{
    if (row_to_remove < 0 || row_to_remove >= col) {
        cout << "Invalid row number to remove." << endl;
        return arr;
    }

    size_t* new_array_rows_size = new size_t[col - 1];
    T** new_arr = new T*[col - 1];
    int new_arr_index = 0;

    for (int i = 0; i < col; i++)
    {
        if (i != row_to_remove) {
            new_array_rows_size[new_arr_index] = array_rows_size[i];
            new_arr[new_arr_index] = new T[array_rows_size[i]];

            for (size_t j = 0; j < array_rows_size[i]; j++) {
                new_arr[new_arr_index][j] = arr[i][j];
            }
            new_arr_index++;
        }
    }

    delete[] arr[row_to_remove];
    delete[] arr;
    delete[] array_rows_size;
    array_rows_size = new_array_rows_size;
    arr = new_arr;
    col--;

    return arr;
}

int main()
{
    srand(time(0));

    int items, rows;
    cout << "rows item = ";
    cin >> rows;
    size_t* array_rows_size = new size_t[rows];
    int ** arr_d = new int*[rows];

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

    int row_to_remove;
    cout << "Enter the row number to remove: ";
    cin >> row_to_remove;

    arr_d = removeRow<int>(arr_d, rows, array_rows_size, row_to_remove);
    showArray(arr_d, rows, array_rows_size);

    return 0;
}
