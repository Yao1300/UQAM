#include <iostream>
#include <string>
#include <stdexcept>
#include <ginac/ginac.h>
using namespace std;
using namespace GiNaC;
int main(){
   symbol w("w"), x("x"), y("y"), z("z"),t("t");
matrix N={
{ 1,    -x, -x,     0, -x,     0,  0, -x,  0,     0,  0,     0, -x,  0,     0, -x,  0,  0,     0,  0, -x,  0,  0,  0,  0,  0,     0,    -x, -x,     0, -x,     0, -x,  0,  0,     0,    -x, -x,     0,    -x},
{ 0, 1 - x, -x,     0, -x,     0,  0, -x,  0,     0,  0,     0, -x,  0,     0, -x,  0,  0,     0,  0, -x,  0,  0,  0,  0,  0,     0,    -x, -x,     0, -x,     0, -x,  0,  0,     0,    -x, -x,     0,    -x},
{-x,     0,  1,    -x, -x,     0,  0,  0, -x,     0, -x,     0,  0,  0,     0,  0, -x,  0,     0,  0,  0,  0,  0, -x,  0,  0,     0,    -x,  0,     0,  0,     0,  0,  0,  0,     0,     0,  0,     0,     0},
{-x,     0,  0, 1 - x, -x,     0,  0,  0, -x,     0, -x,     0,  0,  0,     0,  0, -x,  0,     0,  0,  0,  0,  0, -x,  0,  0,     0,    -x,  0,     0,  0,     0,  0,  0,  0,     0,     0,  0,     0,     0},
{-x,     0, -x,     0,  1,    -x, -x,  0,  0,     0,  0,     0,  0, -x,     0,  0,  0, -x,     0,  0,  0, -x,  0,  0,  0,  0,     0,    -x, -x,     0, -x,     0, -x,  0,  0,     0,    -x, -x,     0,    -x},
{-x,     0, -x,     0,  0, 1 - x, -x,  0,  0,     0,  0,     0,  0, -x,     0,  0,  0, -x,     0,  0,  0, -x,  0,  0,  0,  0,     0,    -x, -x,     0, -x,     0, -x,  0,  0,     0,    -x, -x,     0,    -x},
{ 0,    -x,  0,    -x, -x,     0,  1,  0,  0,    -x,  0,     0, -x,  0,     0,  0, -x,  0,     0,  0,  0,  0,  0,  0, -x,  0,     0,    -x,  0,    -x, -x,     0,  0, -x,  0,     0,    -x, -x,     0,    -x},
{ 0,    -x,  0,    -x, -x,     0,  0,  1,  0,    -x,  0,     0, -x,  0,     0,  0, -x,  0,     0,  0,  0,  0,  0,  0, -x,  0,     0,    -x,  0,    -x, -x,     0,  0, -x,  0,     0,    -x, -x,     0,    -x},
{ 0,    -x,  0,    -x, -x,     0,  0,  0,  1,    -x,  0,     0, -x,  0,     0,  0, -x,  0,     0,  0,  0,  0,  0,  0, -x,  0,     0,    -x,  0,    -x, -x,     0,  0, -x,  0,     0,    -x, -x,     0,    -x},
{ 0,    -x,  0,    -x, -x,     0,  0,  0,  0, 1 - x,  0,     0, -x,  0,     0,  0, -x,  0,     0,  0,  0,  0,  0,  0, -x,  0,     0,    -x,  0,    -x, -x,     0,  0, -x,  0,     0,    -x, -x,     0,    -x},
{ 0,    -x, -x,     0,  0,    -x,  0, -x,  0,     0,  1,    -x,  0,  0,     0,  0,  0, -x,     0,  0,  0,  0, -x,  0,  0,  0,     0,    -x, -x,    -x, -x,    -x,  0, -x, -x,     0,  -2*x, -x,  -2*x,  -3*x},
{ 0,    -x, -x,     0,  0,    -x,  0, -x,  0,     0,  0, 1 - x,  0,  0,     0,  0,  0, -x,     0,  0,  0,  0, -x,  0,  0,  0,     0,    -x, -x,    -x, -x,    -x,  0, -x, -x,     0,  -2*x, -x,  -2*x,  -3*x},
{ 0,    -x, -x,     0,  0,    -x,  0, -x,  0,     0,  0,    -x,  1,  0,     0,  0,  0, -x,     0,  0,  0,  0, -x,  0,  0,  0,     0,    -x, -x,    -x, -x,    -x,  0, -x, -x,     0,  -2*x, -x,  -2*x,  -3*x},
{ 0,    -x, -x,     0,  0,    -x,  0, -x,  0,     0,  0,    -x,  0,  1,     0,  0,  0, -x,     0,  0,  0,  0, -x,  0,  0,  0,     0,    -x, -x,    -x, -x,    -x,  0, -x, -x,     0,  -2*x, -x,  -2*x,  -3*x},
{ 0,    -x, -x,     0,  0,    -x,  0, -x,  0,     0,  0,     0,  0,  0, 1 - x,  0,  0, -x,     0,  0,  0,  0, -x,  0,  0,  0,     0,    -x, -x,    -x, -x,    -x,  0, -x, -x,     0,  -2*x, -x,  -2*x,  -3*x},
{-x,     0,  0,    -x,  0,    -x,  0,  0, -x,     0,  0,     0,  0, -x,     0,  1,  0,  0,    -x,  0,  0,  0,  0,  0,  0, -x,     0,    -x, -x,     0,  0,    -x,  0,  0, -x,     0,    -x, -x,     0,    -x},
{-x,     0,  0,    -x,  0,    -x,  0,  0, -x,     0,  0,     0,  0, -x,     0,  0,  1,  0,    -x,  0,  0,  0,  0,  0,  0, -x,     0,    -x, -x,     0,  0,    -x,  0,  0, -x,     0,    -x, -x,     0,    -x},
{-x,     0,  0,    -x,  0,    -x,  0,  0, -x,     0,  0,     0,  0, -x,     0,  0,  0,  1,    -x,  0,  0,  0,  0,  0,  0, -x,     0,    -x, -x,     0,  0,    -x,  0,  0, -x,     0,    -x, -x,     0,    -x},
{-x,     0,  0,    -x,  0,    -x,  0,  0, -x,     0,  0,     0,  0, -x,     0,  0,  0,  0, 1 - x,  0,  0,  0,  0,  0,  0, -x,     0,    -x, -x,     0,  0,    -x,  0,  0, -x,     0,    -x, -x,     0,    -x},
{ 0,    -x,  0,    -x,  0,    -x,  0,  0,  0,    -x,  0,     0,  0,  0,    -x,  0,  0,  0,    -x,  1,  0,  0,  0,  0,  0,  0,    -x,    -x,  0,  -2*x,  0,  -2*x,  0,  0,  0,  -2*x,  -2*x,  0,  -3*x,  -3*x},
{ 0,    -x,  0,    -x,  0,    -x,  0,  0,  0,    -x,  0,     0,  0,  0,    -x,  0,  0,  0,    -x,  0,  1,  0,  0,  0,  0,  0,    -x,    -x,  0,  -2*x,  0,  -2*x,  0,  0,  0,  -2*x,  -2*x,  0,  -3*x,  -3*x},
{ 0,    -x,  0,    -x,  0,    -x,  0,  0,  0,    -x,  0,     0,  0,  0,    -x,  0,  0,  0,    -x,  0,  0,  1,  0,  0,  0,  0,    -x,    -x,  0,  -2*x,  0,  -2*x,  0,  0,  0,  -2*x,  -2*x,  0,  -3*x,  -3*x},
{ 0,    -x,  0,    -x,  0,    -x,  0,  0,  0,    -x,  0,     0,  0,  0,    -x,  0,  0,  0,    -x,  0,  0,  0,  1,  0,  0,  0,    -x,    -x,  0,  -2*x,  0,  -2*x,  0,  0,  0,  -2*x,  -2*x,  0,  -3*x,  -3*x},
{ 0,    -x,  0,    -x,  0,    -x,  0,  0,  0,    -x,  0,     0,  0,  0,    -x,  0,  0,  0,    -x,  0,  0,  0,  0,  1,  0,  0,    -x,    -x,  0,  -2*x,  0,  -2*x,  0,  0,  0,  -2*x,  -2*x,  0,  -3*x,  -3*x},
{ 0,    -x,  0,    -x,  0,    -x,  0,  0,  0,    -x,  0,     0,  0,  0,    -x,  0,  0,  0,    -x,  0,  0,  0,  0,  0,  1,  0,    -x,    -x,  0,  -2*x,  0,  -2*x,  0,  0,  0,  -2*x,  -2*x,  0,  -3*x,  -3*x},
{ 0,    -x,  0,    -x,  0,    -x,  0,  0,  0,    -x,  0,     0,  0,  0,    -x,  0,  0,  0,    -x,  0,  0,  0,  0,  0,  0,  1,    -x,    -x,  0,  -2*x,  0,  -2*x,  0,  0,  0,  -2*x,  -2*x,  0,  -3*x,  -3*x},
{ 0,    -x,  0,    -x,  0,    -x,  0,  0,  0,    -x,  0,     0,  0,  0,    -x,  0,  0,  0,    -x,  0,  0,  0,  0,  0,  0,  0, 1 - x,    -x,  0,  -2*x,  0,  -2*x,  0,  0,  0,  -2*x,  -2*x,  0,  -3*x,  -3*x},
{-x,     0, -x,     0, -x,     0, -x,  0,  0,     0, -x,     0,  0,  0,     0, -x,  0,  0,     0, -x,  0,  0,  0,  0,  0,  0,     0, 1 - x,  0,     0,  0,     0,  0,  0,  0,     0,     0,  0,     0,     0},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0,  1,    -x, -x,     0,  0, -x,  0,     0,    -x,  0,     0,     0},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0,  0, 1 - x, -x,     0,  0, -x,  0,     0,    -x,  0,     0,     0},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0, -x,     0,  1,    -x,  0,  0, -x,     0,    -x,  0,     0,     0},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0, -x,     0,  0, 1 - x,  0,  0, -x,     0,    -x,  0,     0,     0},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0,  0,    -x,  0,    -x,  1,  0,  0,    -x,    -x,  0,  -2*x,  -2*x},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0,  0,    -x,  0,    -x,  0,  1,  0,    -x,    -x,  0,  -2*x,  -2*x},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0,  0,    -x,  0,    -x,  0,  0,  1,    -x,    -x,  0,  -2*x,  -2*x},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0,  0,    -x,  0,    -x,  0,  0,  0, 1 - x,    -x,  0,  -2*x,  -2*x},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0, -x,     0, -x,     0, -x,  0,  0,     0, 1 - x,  0,     0,     0},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0,  0,     0,  0,     0,  0,  0,  0,     0,     0,  1,    -x,    -x},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0,  0,     0,  0,     0,  0,  0,  0,     0,     0,  0, 1 - x,    -x},
{ 0,     0,  0,     0,  0,     0,  0,  0,  0,     0,  0,     0,  0,  0,     0,  0,  0,  0,     0,  0,  0,  0,  0,  0,  0,  0,     0,     0,  0,     0,  0,     0,  0,  0,  0,     0,     0, -x,     0, 1 - x}};
matrix G =inverse(N);
ex RatParEtatInitial=0;
ex Fx=0;
cout<<"=================================================================================================================="<<endl;
cout<<"1"<<endl;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<endl;
for (int j=10; j< 39;++j){
    if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38){

           RatParEtatInitial= RatParEtatInitial+ G(0,j);
           Fx=Fx +G(0,j);
   }
}
cout<<"S1= "<<expand(RatParEtatInitial)<<endl;
RatParEtatInitial=0;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<"3"<<endl;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<endl;
for (int j=10; j< 39;++j){
    if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38){

           RatParEtatInitial= RatParEtatInitial+ G(2,j);
           Fx=Fx +G(2,j);
   }
}
cout<<"S3= "<<expand(RatParEtatInitial)<<endl;
RatParEtatInitial=0;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<"5"<<endl;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<endl;
for (int j=10; j< 39;++j){
    if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38){

           RatParEtatInitial= RatParEtatInitial+ G(4,j);
           Fx=Fx +G(4,j);
   }
}
cout<<"S5= "<<expand(RatParEtatInitial)<<endl;
RatParEtatInitial=0;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<"7"<<endl;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<endl;
for (int j=10; j< 39;++j){
    if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38){

           RatParEtatInitial= RatParEtatInitial+ G(6,j);
           Fx=Fx +G(6,j);
   }
}
cout<<"S7= "<<expand(RatParEtatInitial)<<endl;
RatParEtatInitial=0;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<"11"<<endl;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<endl;
for (int j=10; j< 39;++j){
    if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38){

           RatParEtatInitial= RatParEtatInitial+ G(10,j);
           Fx=Fx +G(10,j);
   }
}
cout<<"S11= "<<expand(RatParEtatInitial)<<endl;
RatParEtatInitial=0;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<"16"<<endl;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<endl;
for (int j=10; j< 39;++j){
    if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38){

           RatParEtatInitial= RatParEtatInitial+ G(15,j);
           Fx=Fx +G(15,j);
   }
}
cout<<"S16= "<<expand(RatParEtatInitial)<<endl;
RatParEtatInitial=0;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<"20"<<endl;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<endl;
for (int j=10; j< 39;++j){
    if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38){

           RatParEtatInitial= RatParEtatInitial+ G(19,j);
           Fx=Fx +G(19,j);
   }
}
cout<<"S20= "<<expand(RatParEtatInitial)<<endl;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
//cout<<"Fx"<<endl;
cout<<endl;
cout<<"=================================================================================================================="<<endl;
cout<<endl;
cout<<"Fx= "<<expand(Fx)<<endl;

}
