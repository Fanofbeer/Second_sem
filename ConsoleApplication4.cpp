
#include<iostream>
#include<stdlib.h>
#include<locale.h>
using namespace std ;
const int RAZ = 10 ;		//предельный размер массива
typedef int telem ;		//определение типа значений элементов массива
typedef telem tmas[RAZ] ;	//определение типа массива
int nomer_min(const tmas, int) ;
int nomer_otr(const tmas, int) ;
int product_otr(tmas,int,int);
void inputmas(tmas, int) ;
void outputmas(const tmas, int) ;
void obrabotka_mas(tmas, int, int ,int) ;
//main_begin_______________________________________________________________
int main()
{
    //setlocale(LC_ALL, "Russian");
    std:: system ("chcp 65001");
    tmas  a;		//массив
    int   m,		//половина размера массива
        i_otr,		//индекс первого отрицательного элемента <m
        i_min,		//индекс наименьшего неотрицательного элемента
          i,		//ответ в диалоге
        prod;
    //Ввод исходных данных
    cout << "\n Введете половину размера массива <= " << RAZ / 2 << " : ";
    cin >> m;
    //Контроль ввода размера массива
    if (2 * m > RAZ || m <= 0)
    {
        cout << " Введено недопустимое значение размера массива" << endl;
        cout << "\n Повторить-1, Выход-2: ";
        cin >> i;
        if (i == 1) main();
        return 0;
    }
    inputmas(a, 2 * m);
    //Вывод исходного массива
    cout << " Исходный массив:" << endl;
    outputmas(a, 2 * m);
    //Поиск индекса элемента с наименьшим неотрицательным значением
    i_min = nomer_min(a, 2 * m);
    if (i_min == -1)
    {
        cout << "\n Неотрицательных значений у элементов массива нет" << endl;
        //cout << " Массив не изменялся." << endl;
        cout << "\n Повторить-1, Выход-2: ";
        cin >> i;
        if (i == 1) main();
        return 0;
    }
    cout << "\n Индекс min неотр. элемента массива = " << i_min << endl;
    i_otr = nomer_otr(a, m);
    if (i_otr == -1)
    {
        cout << "\n Отрицательных значений у элементов массива";
        cout << " с индексами <" << m << " нет" << endl;
        //cout << " Массив не изменялся.";
        cout << "\n Повторить-1, Выход-2: ";
        cin >> i;
        if (i == 1) main();
        return 0;
    }
    cout << " Индекс первого отр. элемента >=" << m << " = " << i_otr << endl;
    prod=product_otr(a,i_otr,i_min);
    cout << " Произведение отрицательных элементов равна" << prod << endl;
    
    //obrabotka_mas(a, 2 * m, i_min, i_otr);
    //cout << " Измененный массив:" << endl;
    //outputmas(a, 2 * m);
    cout << "\n Повторить-1, Выход-2: ";
    cin >> i;
    if (i == 1) main();
    return 0;}
//main_end_________________________________________________________________
//nomer_min_begin__________________________________________________________
int nomer_min(const tmas a, int n)
{int imin ,		//индекс минимального неотр. Элемента
     i ;		//кущий номер элемента массива
     imin = -1 ;	//факт отсутствия неотрицательного элемента
//Ищем первый неотрицательный элемент
 for(i = 0 ; i < n ; i++)
    if(a[i] >= 0)
      {imin = i ;
       break ;
      }
 if(imin == i)
   {for(int i = imin + 1 ; i < n ; i++)
      if(a[i] >= 0 && a[i] < a[imin]) imin = i ;
   }
 return imin ;
}
//nomer_min_end____________________________________________________________
//nomer_otr_begin__________________________________________________________
int nomer_otr(const tmas a, int m)
{int iotr ;		//индекс первого отрицательного элемента
     iotr = -1 ;	//факт отсутствия отрицательного элемента
//Ищем первый отрицательный элемент с индексом <m
 for(int i = 0 ; i < m ; i++)
    if(a[i] < 0)
      {iotr = i ;
       break ;
      }
 return iotr ;
}
//nomer_otr_end____________________________________________________________
//inputmas_begin___________________________________________________________
void inputmas(tmas a, int n)
{cout << " Введите в одной строке элементы массива, состоящего из " << n ;
 cout << "\n чисел, и нажмите <Enter>" << endl ;
 for(int i = 0 ; i < n ; i++)
    cin >> a[i] ;
}
//inputmas_end_____________________________________________________________
//outputmas_begin__________________________________________________________
void outputmas(const tmas a, int n)
{for(int i = 0 ; i < n ; i++)
   {cout.width(4) ; 	//ширина поля для вывода значения элемента массива
    cout << a[i] << " " ;
   }
}
//outputmas_end____________________________________________________________
//obrabotka_mas_begin______________________________________________________
void obrabotka_mas(tmas a, int n, int i_min, int i_otr)
{int i_beg,		//начало интервала
     i_end,		//конец интервала
     i ;		//текущий номер элемента
 if(i_min < i_otr)
   {i_beg = i_min + 1 ;
    i_end = i_otr ;
   }
 else{i_beg = i_otr + 1 ;
      i_end = i_min ;
     }
 for(i = i_beg ; i < i_end ; i++)	//удваиваем значения внутри интервала
    a[i] *= 2 ;
 for(i = 0 ; i < i_beg ; i++)	//инвертируем знак у остальных
    a[i] = -a[i] ;
 for(i = i_end ; i < n ; i++)	//инвертируем знак у остальных
    a[i] = -a[i] ;
}

//obrabotka_mas_end_______________________________________________________
int product_otr(tmas a, int min_otr,int min_pos)
{int prod ;		//Произведение
     prod = 1 ;
if (min_otr<min_pos)
 {for(int i = min_otr ; i < min_pos ; i++)
    if(a[i] < 0)
      {prod *= a[i] ;
      }}
  else
 {for(int i = min_otr ; i < min_pos ; i++)
    if(a[i] < 0)
      {prod *= a[i] ;
      }}
 return prod ;
}
