/* polinomio.cpp implementacion de la clase ppolinomio
  */
 #include <iostream>
 using namespace std;
  #include "polinomio.h"
  #include "myfecha.h"
  #define maximo(a,b) ((a>b)?a:b)
  Polinomio::Polinomio(int intGrado, Rac *RacPt):
                           grado(intGrado), A(RacPt){}
                           
/*Polinomio& Polinomio::operator+(Polinomio& PolObj){//stub

ostream& operator<<(ostream& ostreamOut,Rac& RacObj){
	ostreamOut<<" "<<RacObj.n<<" "<<endl;
	ostreamOut<<"----"<<endl;
	ostreamOut<<" "<<RacObj.d<<endl;
	return ostreamOut;	
}
*/
Polinomio& Polinomio::operator+(Polinomio& PolObj){
           int grad=maximo(grado,PolObj.grado);
       Polinomio ResPol(grad,new Rac[grad+1]);    
           if(grado==grad){
                           for(int i=0;i<grado+1;i++){
                                   (ResPol.A+i)->n=(A+i)->n;
                                   (ResPol.A+i)->n=(A+i)->d;
                                   }
                                   }
                                   else{
                                        for(int i=0;i<PolObj.grado+1;i++){
                                   (ResPol.A+i)->n=(PolObj.A+i)->n;
                                   (ResPol.A+i)->n=(PolObj.A+i)->d;
                                   }
                                   }
                                   if(grado<=grad){
                                                   for(int i=0;i<grado+1;i++){
                                                           *(ResPol.A+i)=*(ResPol.A+i)+*(A+i);
                                                           }
                                                           }
                                                           else{
                                                                for(int i=0;i<PolObj.grado+1;i++){
                                                           *(ResPol.A+i)=*(ResPol.A+i)+*(PolObj.A+i);
                                                           }
                                                                
                                                                }
                                        
return ResPol;
}

Polinomio& Polinomio::operator-(Polinomio& PolObj){
return PolObj;
}
Polinomio& Polinomio::operator*(Polinomio& PolObj){
return PolObj;
}
Polinomio& Polinomio::operator/(Polinomio& PolObj){
return PolObj;
}

ostream& operator<<(ostream& ostreamOut,Polinomio& Polinomio1){
         ostreamOut<<Polinomio1.A->n<<"/"<<Polinomio1.A->d<<"\t"<<(Polinomio1.A+1)->n<<"/"<<(Polinomio1.A+1)->d<<"\t"<<(Polinomio1.A+2)->n<<"/"<<(Polinomio1.A+2)->d;
         return ostreamOut;
}
