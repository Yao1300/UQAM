#include <iostream>
#include <string>
#include <stdexcept>
#include <ginac/ginac.h>
using namespace std;
using namespace GiNaC;
void Puiss(matrix A, int n){
   matrix M =A;
   //cout<<A[4,8]<<endl;
   if (n==1){
            
            cout<<expand(A);
  
    cout<<endl;
  }
   
   else{
  for (int i = 0; i < n-1; ++i)
  {
     	M=M.mul(A);
  }
   cout<<expand(M);
   //cout<<"   "<<endl;
  //cout<<expand(M)[1,2]<<endl;
  }

}
int main(){
	symbol w("w"), x("x"), y("y"), z("z");
	int n;
	cin>>n;
	matrix B={{0,pow(w,1)*pow(x,2)*y*pow(z,2),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,0},
{0,pow(w,1)*pow(x,2)*y,0,0,0,pow(w,2)*pow(x,4)*y,0,0,0,0},
{0,0,0,pow(w,1)*pow(x,2)*y*pow(z,2),0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0},
{0,0,0,pow(w,1)*pow(x,2)*y,0,0,pow(w,2)*pow(x,4)*y,0,0,0},
{0,pow(w,1)*pow(x,2)*y,0,pow(w,1)*pow(x,2)*y,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-2),2*pow(w,1)*pow(x,2)*y,0},
{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),pow(w,1)*pow(x,2)*y*pow(z,1)+pow(w,1)*pow(x,2)*y,0},
{0,pow(w,1)*pow(x,2)*y,0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),pow(w,1)*pow(x,2)*y+pow(w,1)*pow(x,2)*y*pow(z,1),0},
{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y,2*pow(w,1)*pow(x,2)*y*pow(z,1),0},
{0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y,0},
{0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,2),0}};
//cout<<expand(B)<<endl;
Puiss(B,n);
 return 0;
}