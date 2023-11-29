#include <iostream>
#include <string>
#include <stdexcept>
#include <ginac/ginac.h>
using namespace std;
using namespace GiNaC;
string EspSpp(string commande){
commande.erase(remove_if(commande.begin(),commande.end(),::isspace),commande.end());
return commande;
}
string RetreiveParan(string polyini){

	string polyret, polyfin,monome,polyinter,monw,monx,mony,monz,coef,monomefin;
    polyret=EspSpp(polyini);
    int l1,lparen1,lparen2,lchap,lw,lx,lz,ly,lplus1, lplus2, lplus3,l;
    l1=polyret.length();
    //lplus1=polyret.find("+");
    polyfin=" ";
    int compt=0;
    for (int i = 0; i < l1; ++i)
    {
        lplus1=polyret.find("+");
    	if (lplus1>=0)
        {
            compt++;
            l=l1;
            polyinter=polyret.substr(lplus1+1,l-lplus1-1);
            monome=polyret.substr(0,lplus1);
            polyret=polyinter;
            l=polyret.length();
            lw=monome.find("w");
            lx=monome.find("x");
            ly=monome.find("y");
            lz=monome.find("z");
            lparen1=monome.find("(");
            lparen2=monome.find(")");
           // cout<<lz<<","<<lw<<","<<lx<<","<<ly<<endl;
            if(lx-lw>2){
                  monw="pow(w,"+monome.substr(lw+2,lx-lw-3)+")";

            }
            else{
                monw="w";
            }
            if(ly-lx>2){
                  monx="pow(x,"+monome.substr(lx+2,ly-lx-3) +")";

            }
            else{
                monx="x";
            }
            if(monome.length()-ly>1){
                  mony="pow(y,"+monome.substr(ly+2,monome.length()-ly-2) +")";

            }
            else{
                mony="y";
            }
            if (lz<0)
            {
                   monz=" ";
            }
            if (lw-lz==2)
            {
                monz="z";
            }
            if(lw-lz>2 && lparen1>=0){
                monz="pow(z,"+monome.substr(lparen1+2,lparen2-lparen1-2)+")";
            }
            else{
                if(lw-lz>2 && lparen1<0){
                   monz="pow(z,"+monome.substr(lz+2,lw-lz-3)+")";
                  }
            }
            if (lz>0)
            {
              coef=monome.substr(0,lz-1);
            }
             if (lz<0 && lw>0)
            {
              coef=monome.substr(0,lw-1);
            }
            if(lz==0||lw==0){
                 coef=" ";
            }
             if (coef==" " && monz==" ")
            {
              monomefin=monw+"*"+monx+"*"+mony;
            }
            else{
                 if (coef==" " && monz !=" ")
                {
                     monomefin= monw+"*"+monx+"*"+mony+"*"+monz;
                }
                else{
                     if (coef !=" " && monz==" ")
                      {
                         monomefin=coef+"*"+monw+"*"+monx+"*"+mony;
                      }
                      else{
                           if (coef !=" " && monz!=" ")
                           {
                            
                         
                                         monomefin=coef+"*"+monw+"*"+monx+"*"+mony+"*"+monz;
                           } 
                      }
              }
         }

             polyfin=polyfin+"+"+monomefin;
            // cout<<monz<<endl;
             cout<<"monw="<<monw<<" monx= "<<monx<<"  mony= "<<mony<<" monz= "<<monz<<" coef= "<<coef<<endl;
        }
        if (compt<i)
        {
           // monome=polyret;

            break;
        }
        
      

    }
    polyfin=polyfin+"+"+polyinter;
    return polyfin;
}

int main(int argc, char const *argv[])
{
    symbol w("w"), x("x"), y("y"), z("z");
    string polyini;
    cin>>polyini;
   // cout<<polyini<<endl;
    cout<<RetreiveParan(polyini)<<endl;
    return 0;

}