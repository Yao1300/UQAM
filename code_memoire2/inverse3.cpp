#include <iostream>
#include <string>
#include <stdexcept>
#include <ginac/ginac.h>
using namespace std;
using namespace GiNaC;
void Inverse(matrix A,int m){
   matrix M = inverse(A);
  // ex val=0;
  for (int j = 0; j < 5; ++j)
      {
         //cout<<"M"<<"1"<<","<<j+1<<"= "<<RetreiveParan(matrice[0][j])<<endl;
            //cout<<endl;
        if (j==0 ||j==2 ||  j==4)
            {
           cout<<"M("<<6<<","<<j+1<<")= "<<M(5,j)<<endl;
           cout<<endl;
           //val= val + expand(M(0,j));
        }
        }
         //cout<<"1-"<<expand(val)<<endl;
         //val=0;
            cout<<"======================3========================"<<endl;
        for (int j = 0; j < 5; ++j){
        if (j==0 ||j==2 ||  j==4)
            {
            cout<<"M("<<7<<","<<j+1<<")= "<<M(6,j)<<endl;
            cout<<endl;
           // val= val + expand(M(2,j));
        }
       //cout<<"3-"<< val<<endl;
       // val=0;
         }

             cout<<"======================5========================"<<endl;
         for (int j = 0; j < 5; ++j){
        if (j==0 ||j==2 ||  j==4)
            {
            cout<<"M("<<8<<","<<j+1<<")="<<M(7,j)<<endl;

            cout<<endl;
           // val= val + expand(M(4,j));
        }
          }
        for (int j = 0; j < 5; ++j){
        if (j==0 ||j==2 ||  j==4)
            {
            cout<<"M("<<9<<","<<j+1<<")="<<M(8,j)<<endl;

            cout<<endl;
           // val= val + expand(M(4,j));
        }
          }
          //cout<<"5-"<< val<<endl;
}
int main(){
   symbol w("w"), x("x"), y("y"), z("z"),t("t");
  // int n;
   //cin>>n;
   matrix B={{1,-x,0,0,0,-x,0,0,0,0},
{0,1-x,0,0,0,-x,0,0,0,0},
{0,0,1,-x,0,0,-x,0,0,0},
{0,0,0,1-x,0,0,-x,0,0,0},
{0,-x,0,-x,1,0,0,-x,-2*x,0},
{0,-x,0,-x,0,1,0,-x,-2*x,0},
{0,-x,0,-x,0,0,1,-x,-2*x,0},
{0,-x,0,-x,0,0,0,1-x,-2*x,0},
{0,0,0,0,0,0,0,0,1-x,0},
{0,0,0,0,0,0,0,0,-x,1}};
Inverse(B,10);
 return 0;
}