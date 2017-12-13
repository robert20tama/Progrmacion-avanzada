/** Polinomio.cpp - Implementaci�n de la clase Polinomio
 */
#include <iostream>
using namespace std;	/* cout, ostream */
#include "Polinomio.h"
#include "myfecha.h"
#define maximo(a,b)	((a>b)?a:b)
Polinomio::Polinomio(int intGrado,Rac *RacPt):
grado(intGrado),A(RacPt){ }

Polinomio& Polinomio::operator+(Polinomio& PolObj){
	Polinomio ResPol(grado,new Rac[grado+1]);
	for(int i=0;i<grado+1;i++){
			(ResPol.A+i)->n=(A+i)->n;
			(ResPol.A+i)->d=(A+i)->d;
		}
    if(grado>PolObj.grado){/*si el obj implicito es el de mayor grado*/
			for(int i=0;i<PolObj.grado+1;i++){
			*(ResPol.A+i)=*(ResPol.A+i)+*(PolObj.A+i);
		}return ResPol;}
    if(grado<PolObj.grado){/*si el segundo operando es el de mayor grado*/
		    for(int i=0;i<grado+1;i++){
			*(PolObj.A+i)=*(ResPol.A+i)+*(PolObj.A+i);
		}return PolObj;}
    if(grado==PolObj.grado){/*si son iguales*/
			for(int i=0;i<grado+1;i++){
			*(ResPol.A+i)=*(ResPol.A+i)+*(PolObj.A+i);
		}return ResPol;}
}

Polinomio& Polinomio::operator-(Polinomio& PolObj){
	Polinomio ResPol(grado,new Rac[grado+1]);
	for(int i=0;i<grado+1;i++){
			(ResPol.A+i)->n=(A+i)->n;
			(ResPol.A+i)->d=(A+i)->d;
		}
    if(grado>PolObj.grado){/*si el obj implicito es el de mayor grado*/
			for(int i=0;i<PolObj.grado+1;i++){
			*(ResPol.A+i)=*(ResPol.A+i)-*(PolObj.A+i);
	    }return ResPol;}
    if(grado<PolObj.grado){/*si el segundo operando es el de mayor grado*/
		    for(int i=0;i<grado+1;i++){
			*(PolObj.A+i)=*(ResPol.A+i)-*(PolObj.A+i);
		}return PolObj;}
	 if(grado==PolObj.grado){/*si son iguales*/
			for(int i=0;i<grado+1;i++){
			*(ResPol.A+i)=*(ResPol.A+i)-*(PolObj.A+i);
		}return ResPol;}
}

Polinomio& Polinomio::operator*(Polinomio& PolObj){
	int grad=grado+PolObj.grado;
	Polinomio ResPol(grad,new Rac[grad+1]);		/* ResultPolynomial */
	Rac factor1,factor2,factor1porfactor2,sumaparcial;
	for(int i=0;i<ResPol.grado+1;i++){
		*(ResPol.A+i)=Rac(0,1);	/* All coeffs of ResPol must be initialized  to \frac{0}{1} */
	}
	for(int k=0;k<grad+1;k++){
		for(int i=0;i<grado+1;i++){
			for(int j=0;j<PolObj.grado+1;j++){
				if((grado-i+PolObj.grado-j)==grad-k){
					factor1=*(A+i);
					factor2=*(new Rac((PolObj.A+j)->n,(PolObj.A+j)->d));
					factor1porfactor2=factor1*factor2;
					sumaparcial=*(ResPol.A+k)+factor1porfactor2;
					*(ResPol.A+k)=sumaparcial;
				}
			}
		}
	}
	return ResPol;
}
Polinomio& Polinomio::operator/(Polinomio& PolObj){//Stub
	return PolObj;
}
ostream& operator<<(ostream& ostreamOut,Polinomio& Polinomio1){
  for(int i=0;i<Polinomio1.grado+1;i++){
  	ostreamOut<<"\t"<<(Polinomio1.A+i)->n<<"/"<<(Polinomio1.A+i)->d;
  }
  return ostreamOut;
}
