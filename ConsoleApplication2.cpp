#include<iostream>
#include<math.h>
#include<locale.h>
#include<limits.h>
using namespace std ;
int main()
{int i = 0 ;			//номер области на рисунке
 float x, y,			//координаты точки
 s1, s2, s3, s4, s5 ;		//площади областей
 //setlocale(LC_ALL,"Russian") ;
std:: system ("chcp 65001");
 cout << "\nВведите координаты точки: x, y " ;
 cin >> x >> y ;
 if(y > 0 && y < 2 && x > 1 && x < 2 && (x - 1) * (x - 1) + y * y >1)
 {cout << "Точка в области M1. " ; i = 1 ;
 }
 else if(x > -2 && y < 1 && x < -1 && y > 0 &&
        (x + 1) * (x + 1) + y * y > 1)
      {cout << "Точка в области М2. " ; i = 2 ;
      }
      else if((x+1) * (x+1) + y * y < 1 && x * x + y * y < 1 && y > 0)
	      {cout << "Точка в области М3. " ; i = 3 ;
	      }
	   else if(x * x + y * y > 1 && (x - 1) * (x - 1) + y * y < 1 &&
		      x * x + (y + 1) * (y + 1) < 1)
		   {cout << "Точка в области М4. " ; i = 4 ;
		   }
		else if(y < -1 && y > -2 && x < 0 && x > -1 &&
			   x * x + (y + 1) * (y + 1) > 1)
		     {cout << "Точка в области М5. " ; i = 5 ;
		     }
		     else cout << "Точка вне выделенных областей" ;
 cout.precision(4);		//число знаков после дес. точки
 switch(i)
    {case 1: cout << "S1 = " << (s1 = 2 - M_PI / 4) ;
	        break ;
     case 2: cout << "S2 = " << (s2 = 1 - M_PI / 4) ;
	        break ;
     case 3: cout << "S3 = " << (s3 = M_PI/3 - sqrt(3)/4) ;
	        break ;
     case 4: cout << "S4 = " << (s4 = sqrt(3)/2 + M_PI/3 - M_PI/4-1) ;
	        break ;
     case 5: cout << "S5 = " << (s5 = 1 - M_PI / 4) ;
    }
 cout << "\n Повторить-1, Выход-2: " ;
 cin >> i ;
 if (i == 1) main() ;
return 0 ;
}
