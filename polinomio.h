/*polinomio.h- ]Clase para realizar operaciones aritmeticas
con polinomios que tienen coeficientes racionales
suma de polinomios, resta de polinomios, multiplicacion

*/
//#include "myfecha.h"
struct Rac;
struct Polinomio{
       int grado;    //grado del polinomio
       Rac *A; //coeficientes del polinomio
       
       Polinomio& operator+(Polinomio& PolObj);
	   Polinomio& operator-(Polinomio& PolObj);
	   Polinomio& operator*(Polinomio& PolObj);
	   Polinomio& operator/(Polinomio& PolObj);
	   
	  friend ostream& operator<<(ostream& ostreamOut, Polinomio& PolObj);
         // constructor
       //@param RacPt: debe apuntar a intGrado+1 objetos de clase Rac.
       //@param intGrado: debe ser el grado del polinomio
       
       Polinomio(int intGrado, Rac *RacPt);
       };//end class polinomio
       
