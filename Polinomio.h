/** Polinomio.h - Clase para realizar operaciones aritm�ticas
 *  con polinomios que tienen coeficientes racionales:
 *  suma de polinomios, resta de polinomios, multiplicaci�n 
 *  de polinomios y divisi�n de polinomios.
 *  @version 2017.09.15
 */
struct Rac;       /* declaraci�n anticipada */ 
struct Polinomio{
  int grado;     /* grado del polinomio */
  Rac *A;        /* coeficientes del polinomio */
  Polinomio& operator+(Polinomio& PolObj);
  Polinomio& operator-(Polinomio& PolObj);
  Polinomio& operator*(Polinomio& PolObj);
  Polinomio& operator/(Polinomio& PolObj);
  friend ostream& operator<<(ostream& ostreamOut,Polinomio& PolObj); 
  /* constructor(es) */
  /**
   * @param RacPt: debe apuntar a intGrado+1 objetos de 
   * clase Rac.
   * @param intGrado: debe ser el grado del polinomio.
   */
  Polinomio(int intGrado,Rac *RacPt);
};//end class Polinomio
