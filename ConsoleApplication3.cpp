//Пример 1.  Для произвольного значения m вычислить значение суммы заданного вида.
//Значения m, y0, y1, y2 вводятся с клавиатуры. Значение yi
//вычисляется по формуле y[i]=y[i-1] + y[i-3]^2, где i=3,4,...,m
#include <iostream>;
#include <locale.h>;
#include <math.h>;
using namespace std ;
double recur1(int m, double y0, double y1, double y2) ;
double recur2(int m, double y0, double y1, double y2) ;
double recur3(int m, double y0, double y1, double y2) ;
//main_begin_______________________________________________________________
int main()
{
 //setlocale(LC_ALL,"Russian") ;
 std:: system ("chcp 65001");

 int var, m ;
 double re1, re2, re3 ;		//результаты решения задачи
 double y0, y1, y2 ;		//исходнРые данные
for(;;)
 {//Выбор действия
  cout << "\n  Вид действия:" << endl ;
  cout << " 1 - вычисление суммы по рекуррентной формуле" << endl ;
  cout << " 2 - завершение задачи" << endl ;
  cout << " Введите вид действия -> " ;
  cin >> var ;
  switch(var)
      {case 1://Ввод исходных данных
	    cout << " Введите m -> " ;
	    cin >> m ;
	    cout << " Введите y0, y1, y2 -> " ;
	    cin >> y0 >> y1 >> y2 ;
	    re1 = recur1(m, y0, y1, y2) ;
	    re2 = recur2(m, y0, y1, y2) ;
	    re3 = recur3(m, y0, y1, y2) ;
//Вывод результата
	    cout.precision(5) ;//число знаков после запятой при выводе
	    cout << " Для цикла WHILE результат     = " << re1 << endl ;
	    cout << " Для цикла DO..WHILE результат = " << re2 << endl ;
	    cout << " Для цикла FOR результат       = " << re3 << endl ;
	    break ;
       default: return 0 ;
      }//switch
 }//for
}
//main_end_________________________________________________________________
//recur1_beg_______________________________________________________________
//вычисление значения суммы циклом while
double recur1(int m, double y0, double y1, double y2)
{int   i = 0 ;			//текущий номер слагаемого
 double y ,				//очередное значение y[i]
     sum = 0 ;			//начальное значение суммы
 sum += y0 * (i + 1.) / m ; i++ ;
 sum += y1 * (i + 1.) / m ; i++ ;
 sum += y2 * (i + 1.) / m ; i++ ;
 while(i <= m)
   {y = pow(sin(y2)+y0,2)+pow(cos(y0)-0.2*y1,2);
    sum += y + (5*i/6);
    y0 = y1 ;
    y1 = y2 ;
    y2 = y ;
    i++ ;
   }
 return(0.1 * (m + 5) * sum) ;
}
//recur1_end_______________________________________________________________
//recur2_beg_______________________________________________________________
//вычисление значения суммы циклом do..while
double recur2(int m, double y0, double y1, double y2)
{int   i = 0 ;			//текущий номер слагаемого
 double y ,				//очередное значение y[i]
     sum = 0 ;			//начальное значение суммы
 sum += y0 * (i + 1.) / m ; i++ ;
 sum += y1 * (i + 1.) / m ; i++ ;
 sum += y2 * (i + 1.) / m ; i++ ;
 do
  {y = pow(sin(y2)+y0,2)+pow(cos(y0)-0.2*y1,2);
    sum += y + (5*i/6);
   y0 = y1 ;
   y1 = y2 ;
   y2 = y ;
   i++ ;
  }
 while(i <= m) ;
 return(0.1 * (m + 5) * sum) ;
}
//recur2_end_______________________________________________________________
//recur3_beg_______________________________________________________________
//вычисление значения суммы циклом for
double recur3(int m, double y0, double y1, double y2)
{int   i = 0 ;			//текущий номер слагаемого
 double y ,				//очередное значение y[i]
     sum = 0 ;			//начальное значение суммы
 sum += y0 * (i + 1.) / m ; i++ ;
 sum += y1 * (i + 1.) / m ; i++ ;
 sum += y2 * (i + 1.) / m ; i++ ;
 for(; i <= m; i++)
    {y = pow(sin(y2)+y0,2)+pow(cos(y0)-0.2*y1,2);
    sum += y + (5*i/6);
     y0 = y1 ;
     y1 = y2 ;
     y2 = y ;
    }
 return(0.1 * (m + 5) * sum) ;
}
//recur3_end______________________________________________________________
