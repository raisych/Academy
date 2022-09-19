// Varnsdorf_method.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int chess[8][8] = { {0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0} };
int counter = 0; //счётчик заполненных полей

int full_or_not()
{
    int i, j;
    //bool fool;
    counter = 0;
    for (i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //cout << "cell[" << i << "," << j << "]: " << chess[i][j];
            if (chess[i][j] == 1)
            {
                counter += 1;
 
            }


        }
        
    }   
//    cout << "Ход № " << couner;
    return counter;
}

void show_next_move()
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //cout << "cell[" << i << "," << j << "]: " << chess[i][j];
            cout << chess[i][j] << " ";

        }
        cout << endl;
    }

    system("pause");
}

int test_next_step(int x, int y) // ВАРИАНТЫ ОБХОДА ПЕРВОЙ ЧЕТВЕРТИ
{
    int x1, y1, qc; // qc - количество возможных ходов
    qc = 0;
    x1 = x + 2; y1 = y + 1; //первая позиция первой четверти
    if (((x1 <= 7 && x1 >= 0) && (y1 <= 7 && y1 >= 0)) && (chess[x1][y1] == 0))
    {
        qc += 1;
    }
    x1 = x + 1; y1 = y + 2; //вторая позиция первой четверти
    if (((x1 <= 7 && x1 >= 0) && (y1 <= 7 && y1 >= 0)) && (chess[x1][y1] == 0))
    {
        qc += 1;
    }
    x1 = x - 1; y1 = y + 2; //первая позиция второй четверти
    if (((x1 <= 7 && x1 >= 0) && (y1 <= 7 && y1 >= 0)) && (chess[x1][y1] == 0))
    {
        qc += 1;
    }
    x1 = x - 2; y1 = y + 1; //вторая позиция второй четверти
    if (((x1 <= 7 && x1 >= 0) && (y1 <= 7 && y1 >= 0)) && (chess[x1][y1] == 0))
    {
        qc += 1;
    }
    x1 = x - 2; y1 = y - 1; //первая позиция третьей четверти
    if (((x1 <= 7 && x1 >= 0) && (y1 <= 7 && y1 >= 0)) && (chess[x1][y1] == 0))
    {
        qc += 1;
    }
    x1 = x - 1; y1 = y - 2; //вторая позиция третьей четверти
    if (((x1 <= 7 && x1 >= 0) && (y1 <= 7 && y1 >= 0)) && (chess[x1][y1] == 0))
    {
        qc += 1;
    }
    x1 = x + 1; y1 = y - 2; //первая позиция четвёртой четверти
    if (((x1 <= 7 && x1 >= 0) && (y1 <= 7 && y1 >= 0)) && (chess[x1][y1] == 0))
    {
        qc += 1;
    }
    x1 = x + 2; y1 = y - 1; //вторая позиция четвёртой четверти
    if (((x1 <= 7 && x1 >= 0) && (y1 <= 7 && y1 >= 0)) && (chess[x1][y1] == 0))
    {
        qc += 1;
    }



    return qc;

}

void quarters_first_steps(int x, int y) // ПЕРВИЧНАЯ ПРОВЕРКА ВАРИАНТОВ ВОКРУГ
{
    int x11, y11, x12, y12, x21, y21, x22, y22, x31, y31, x32, y32, x41, y41, x42, y42, min, minn, i,xf,yf;
    int variant[8];
    bool can_move=false;
    xf = x; yf = y;
    //ХОДЫ ПЕРВОГО КВАДРАНТА
    x11 = x + 2; y11 = y + 1;
    if ((x11 <= 7 && x11 >= 0) && (y11 <= 7 && y11 >= 0) && (chess[x11][y11] == 0))  //если не вывалился за поле и не занято, проверяем вокруг
    {
        variant[0] = test_next_step(x11, y11);
        can_move = true;
    }
    else variant[0] = 0;
    x12 = x + 1; y12 = y + 2;
    if ((x12 <= 7 && x12 >= 0) && (y12 <= 7 && y12 >= 0) && (chess[x12][y12] == 0))  //если не вывалился за поле и не занято, проверяем вокруг
    {
        variant[1] = test_next_step(x12, y12);
        can_move = true;
    }
    else variant[1] = 0;
    //ХОДЫ ВТОРОГО КВАДРАНТА
    x21 = x - 1; y21 = y + 2;
    if ((x21 <= 7 && x21 >= 0) && (y21 <= 7 && y21 >= 0) && (chess[x21][y21] == 0))  //если не вывалился за поле и не занято, проверяем вокруг
    {
        variant[2] = test_next_step(x21, y21);
        can_move = true;
    }
    else variant[2] = 0;
    x22 = x - 2; y22 = y + 1;
    if ((x22 <= 7 && x22 >= 0) && (y22 <= 7 && y22 >= 0) && (chess[x22][y22] == 0))  //если не вывалился за поле и не занято, проверяем вокруг
    {
        variant[3] = test_next_step(x22, y22);
        can_move = true;
    }
    else variant[3] = 0;
    //ХОДЫ ТРЕТЬЕГО КВАДРАНТА
    x31 = x - 2; y31 = y - 1;
    if ((x31 <= 7 && x31 >= 0) && (y31 <= 7 && y31 >= 0) && (chess[x31][y31] == 0))  //если не вывалился за поле и не занято, проверяем вокруг
    {
        variant[4] = test_next_step(x31, y31);
        can_move = true;
    }
    else variant[4] = 0;
    x32 = x - 1; y32 = y - 2;
    if ((x32 <= 7 && x32 >= 0) && (y32 <= 7 && y32 >= 0) && (chess[x32][y32] == 0))  //если не вывалился за поле и не занято, проверяем вокруг
    {
        variant[5] = test_next_step(x32, y32);
        can_move = true;
    }
    else variant[5] = 0;
    //ХОДЫ ЧЕТВЁРТОГО КВАДРАНТА
    x41 = x + 1; y41 = y - 2;
    if ((x41 <= 7 && x41 >= 0) && (y41 <= 7 && y41 >= 0) && (chess[x41][y41] == 0))  //если не вывалился за поле и не занято, проверяем вокруг
    {
        variant[6] = test_next_step(x41, y41);
        can_move = true;
    }
    else variant[6] = 0;
    x42 = x + 2; y42 = y - 1;
    if ((x42 <= 7 && x42 >= 0) && (y42 <= 7 && y42 >= 0) && (chess[x42][y42] == 0))  //если не вывалился за поле и не занято, проверяем вокруг
    {
        variant[7] = test_next_step(x42, y42);
        can_move = true;
    }
    else variant[7] = 0;

    //variant[0] = tes_tnext_step(x11, y11);
    //variant[1] = tes_tnext_step(x12, y12);
    //variant[2] = tes_tnext_step(x21, y21);
    //variant[3] = tes_tnext_step(x22, y22);
    //variant[4] = tes_tnext_step(x31, y31);
    //variant[5] = tes_tnext_step(x32, y32);
    //variant[6] = tes_tnext_step(x41, y41);
    //variant[7] = tes_tnext_step(x42, y42);

    if ((can_move = true))//&&(full_or_not()<63))
    {
        min = variant[0];
        minn = 0;
        for (i = 0; i < 8; i++) //сначала поиск максимума и определение его местоположения
        {
            if (variant[i] > min) // && (variant[i] != 0))
            {
                min = variant[i];
                minn = i;
            }
        }
        for (i = 0; i < 8; i++)
        {
            if ((variant[i] < min) && (variant[i] != 0))
            {
                min = variant[i];
                minn = i;
            }
        }
        if ((minn == 0) && (full_or_not() < 63)) //если ещё не все ячкйки пройдены
        {
            chess[x11][y11] = 1;
            show_next_move();
            quarters_first_steps(x11, y11);
        }
            else
            {
                chess[xf][yf] = 1;
                show_next_move();
                cout << "Маршрут пройден\n\n";
            }

        if ((minn == 1) && (full_or_not() < 63)) //если ещё не все ячкйки пройдены
        {
            chess[x12][y12] = 1;
            show_next_move();
            quarters_first_steps(x12, y12);
        }
            else
            {
                chess[xf][yf] = 1;
                show_next_move();
                cout << "Маршрут пройден\n\n";
            }

        if ((minn == 2) && (full_or_not() < 63)) //если ещё не все ячкйки пройдены
        {
            chess[x21][y21] = 1;
            show_next_move();
            quarters_first_steps(x21, y21);
        }
            else
            {
                chess[xf][yf] = 1;
                show_next_move();
                cout << "Маршрут пройден\n\n";
            }


        if ((minn == 3) && (full_or_not() < 63)) //если ещё не все ячкйки пройдены
        {
            chess[x22][y22] = 1;
            show_next_move();
            quarters_first_steps(x22, y22);
        }
            else
            {
                chess[xf][yf] = 1;
                show_next_move();
                cout << "Маршрут пройден\n\n";
            }
        if ((minn == 4) && (full_or_not() < 63)) //если ещё не все ячкйки пройдены
        {
            chess[x31][y31] = 1;
            show_next_move();
            quarters_first_steps(x31, y31);
        }
            else
            {
                chess[xf][yf] = 1;
                show_next_move();
                cout << "Маршрут пройден\n\n";
            }
        if ((minn == 5) && (full_or_not() < 63)) //если ещё не все ячкйки пройдены
        {
            chess[x32][y32] = 1;
            show_next_move();
            quarters_first_steps(x32, y32);
        }
            else
            {
                chess[xf][yf] = 1;
                show_next_move();
                cout << "Маршрут пройден\n\n";
            }
        if ((minn == 6) && (full_or_not() < 63)) //если ещё не все ячкйки пройдены
        {
            chess[x41][y41] = 1;
            show_next_move();
            quarters_first_steps(x41, y41);
        }
            else
            {
                chess[xf][yf] = 1;
                show_next_move();
                cout << "Маршрут пройден\n\n";
            }
        if ((minn == 7) && (full_or_not() < 63)) //если ещё не все ячкйки пройдены
        {
            chess[x42][y42] = 1;
            show_next_move();
            quarters_first_steps(x42, y42);
        }
            else
            {
                chess[xf][yf] = 1;
                show_next_move();
                cout << "Маршрут пройден\n\n";
            }
    }
    else
    {
    cout << "Вариант выбранного маршрута был неудачен";
    }
    
}





int main()
{
    int x, y;
    setlocale(LC_ALL, "Russian");
    do
    {
        cout << "Введите первоначальное положение фигуры от 1 до 8:\n"; // 0,0 - первый элемент массива, а не А1 на шахматной доске
        cin >> x >> y;
    } 
    while (!((x <= 8 && x >= 1) && (y <= 8 && y >= 1)));
    x -= 1; y -= 1;
    chess[x][y] = 1;
    quarters_first_steps(x, y);










}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
