#include <iostream>
#include <string>
#include <stdexcept>
#include <ginac/ginac.h>
using namespace std;
using namespace GiNaC;
void Puiss(matrix A, int n){
   matrix M =A;
  for (int i = 0; i < n-1; ++i)
  {
     	M=M.mul(A);
  }
   cout<<expand(M)<<endl;
  //for (int i = 0; i <10; ++i)
  //{
  	  //int i1=i+1;
  	 //or (int j = 0; j <10; ++j)
  	 //{
  	 	//int j1=j+1;
  //cout<<"$M2,2("<<<<","<<j1<<")="<<expand(M)[i,j]<<"$\\\\"<<endl;
  	 //}
 // }

  
}
int main(){
	symbol w("w"), x("x"), y("y"), z("z");
	int n;
	cin>>n;
	matrix B={{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,0},
{0,pow(w,1)*pow(x,2)*y,0,0,0,pow(w,2)*pow(x,4)*y,0,0,0,0},
{0,0,0,pow(w,1)*pow(x,2)*y*pow(z,2),0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0},
{0,0,0,pow(w,1)*pow(x,2)*y,0,0,pow(w,2)*pow(x,4)*y,0,0,0},
{0,pow(w,1)*pow(x,2)*y,0,pow(w,1)*pow(x,2)*y,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-2),2*pow(w,1)*pow(x,2)*y,0},
{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),pow(w,1)*pow(x,2)*y*pow(z,1)+pow(w,1)*pow(x,2)*y,0},
{0,pow(w,1)*pow(x,2)*y,0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),pow(w,1)*pow(x,2)*y+pow(w,1)*pow(x,2)*y*pow(z,1),0},
{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y,2*pow(w,1)*pow(x,2)*y*pow(z,1),0},
{0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y,0},
{0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,2),0}};
Puiss(B,n);
 return 0;
}