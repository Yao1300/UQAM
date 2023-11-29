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
  //cout<<expand(M)<<endl;
  //for (int i = 0; i <37; ++i)
  //{
  	  //int i1=i+1;
  	 //for (int j = 0; j <37; ++j)
  	 //{
  	 	//int j1=j+1;
  //cout<<"$M3,3("<<i1<<","<<j1<<")="<<expand(M)[i,j]<<"$\\\\"<<endl;
  	// }
 // }
  cout<<expand(M)<<endl;
  
}
int main(){
	symbol w("w"), x("x"), y("y"), z("z");
	int n;
	cin>>n;
	matrix B={{0,pow(w,1)*pow(x,2)*y*pow(z,2),0,0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,0,pow(w,2)*pow(x,6)*y*pow(z,2),0,0,0,0,0,0,0,pow(w,3)*pow(x,6)*y*pow(z,2),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0,pow(w,2)*pow(x,6)*y*pow(z,0),0,0,0,0,0,0,0,pow(w,3)*pow(x,6)*y*pow(z,0),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,pow(w,1)*pow(x,2)*y*pow(z,2),0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,0,0,0,pow(w,3)*pow(x,6)*y*pow(z,3),0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0,0,0,pow(w,3)*pow(x,6)*y*pow(z,1),0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,2),0,0,0,0,0,0,0,pow(w,2)*pow(x,6)*y*pow(z,2),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,pow(w,3)*pow(x,6)*y*pow(z,2),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,0,0,0,0,pow(w,2)*pow(x,6)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,pow(w,3)*pow(x,6)*y*pow(z,0),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-2),0,0,pow(w,2)*pow(x,6)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,-1),0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0},
{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,pow(w,2)*pow(x,6)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,0),0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0},
{0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,pow(w,2)*pow(x,6)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,0),0,0,0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0,0},
{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,0,pow(w,2)*pow(x,6)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,1),0,0,0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,4),0,0,0,0,0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,2),0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0,0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,-2),0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,0,0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,1),0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,0,0,0,0,0,0,0,pow(w,3)*pow(x,4)*pow(y,1),0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,-2),0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,2)*pow(x,4)*y*pow(z,0),pow(w,2)*pow(x,4)*y*pow(z,0),0,0,2*pow(w,1)*pow(x,2)*y*pow(z,0)},
{0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0,pow(w,2)*pow(x,6)*y*pow(z,0),0,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-2),0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,-1),0,0,0,0,w*pow(x,2)*y,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0},
{0,0,0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0,0,pow(w,2)*pow(x,6)*y*pow(z,0),0,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,0),0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0},
{0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0,pow(w,2)*pow(x,6)*y*pow(z,1),0,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,0),0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0},
{0,0,0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0,0,pow(w,2)*pow(x,6)*y*pow(z,1),0,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,0,0,0,0,0,pow(w,3)*pow(x,4)*y*pow(z,1),0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0},
{0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,0,0,0,0,0,pow(w,3)*pow(x,2)*y*pow(z,-2),0,pow(w,1)*pow(x,2)*pow(y,1)+pow(w,1)*pow(x,2)*pow(y,1)*pow(z,1),0,pow(w,1)*pow(x,2)*pow(y,1)+pow(w,1)*pow(x,2)*pow(y,1)*pow(z,1),0,0,0,2*pow(w,2)*pow(x,2)*y*pow(z,-1),0,2*pow(w,2)*pow(x,2)*pow(y,1)+pow(w,2)*pow(x,2)*pow(y,1)*pow(z,-1)},
{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,0,0,0,0,0,pow(w,3)*pow(x,2)*y*pow(z,-1),0,2*pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y+pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y+pow(w,2)*pow(x,2)*y*pow(z,-1),0,2*pow(w,1)*pow(x,2)*y*pow(z,1)+pow(w,1)*pow(x,2)*y},
{0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,0,0,0,0,0,0,pow(w,3)*pow(x,2)*y*pow(z,-1),0,pow(w,1)*pow(x,2)*y+pow(w,1)*pow(x,2)*y*z,0,2*pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1)+pow(w,2)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,0)+2*pow(w,1)*pow(x,2)*y*pow(z,1)},
{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,0,0,0,0,0,0,pow(w,3)*pow(x,2)*y*pow(z,0),0,2*pow(w,1)*pow(x,2)*y*pow(z,1),0,2*pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,2*pow(w,2)*pow(x,2)*y*pow(z,0),0,3*pow(w,1)*pow(x,2)*y*pow(z,1)},
{0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,0,0,0,0,0,pow(w,3)*pow(x,2)*y*pow(z,-2),0,w*pow(x,2)*y*z+w*pow(x,2)*y,0,w*pow(x,2)*y*z+w*pow(x,2)*y,0,0,0,2*pow(w,2)*pow(x,2)*y*pow(z,-1),0,2*pow(w,1)*pow(x,2)*y*pow(z,0)+pow(w,1)*pow(x,2)*y*pow(z,1)},
{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,0,0,0,0,0,pow(w,3)*pow(x,2)*y*pow(z,-1),0,2*pow(w,1)*pow(x,2)*y*pow(z,1),0,w*pow(x,2)*y*z+w*pow(x,2)*y,0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0)+pow(w,2)*pow(x,2)*y*pow(z,-1),0,pow(w,1)*pow(x,2)*y*pow(z,0)+2*pow(w,1)*pow(x,2)*y*pow(z,1)},
{0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,0,0,0,0,0,0,pow(w,3)*pow(x,2)*y*pow(z,-1),0,w*pow(x,2)*y*z+w*pow(x,2)*y,0,2*pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0)+pow(w,2)*pow(x,2)*y*pow(z,-1),0,pow(w,1)*pow(x,2)*y*pow(z,0)+2*pow(w,1)*pow(x,2)*y*pow(z,1)},
{0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,0,0,0,0,0,0,pow(w,3)*pow(x,2)*y*pow(z,0),0,2*pow(w,1)*pow(x,2)*y*pow(z,1),0,2*pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,2*pow(w,2)*pow(x,2)*y*pow(z,0),0,3*pow(w,1)*pow(x,2)*y*pow(z,1)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,2),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,2),0,0,pow(w,2)*pow(x,4)*y*pow(z,2),0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,pow(w,2)*pow(x,4)*y*pow(z,0),0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-2),0,2*pow(w,1)*pow(x,2)*y*pow(z,0)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,0),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,pow(w,1)*pow(x,2)*y*pow(z,0)+pow(w,1)*pow(x,2)*y*pow(z,1)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,-1),0,pow(w,1)*pow(x,2)*y+pow(w,1)*pow(x,2)*y*z},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,1),0,pow(w,1)*pow(x,2)*y*pow(z,1),0,0,0,pow(w,2)*pow(x,2)*y*pow(z,0),0,2*pow(w,1)*pow(x,2)*y*pow(z,1)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,2)},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,pow(w,1)*pow(x,2)*y*pow(z,0)}};
//cout<<B[36,36]<<endl;
Puiss(B,n);
 return 0;
}