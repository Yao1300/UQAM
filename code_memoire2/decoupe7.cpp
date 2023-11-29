#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <ginac/ginac.h>
using namespace std;
using namespace GiNaC;
string EspSpp(string commande){
commande.erase(remove_if(commande.begin(),commande.end(),::isspace),commande.end());
return commande;
}
int Abs(int n){
    int r;
    if (n>=0)
    {
        r=n;
    }
    else{
        r=-n;
    }
    return r;
}
int minimum(int l1, int l2, int l3, int l4, int l5){
    int l,la1,la2,la3,la4,la5;
    la1=Abs(l1);
    la2= Abs(l2);
    la3= Abs(l3);
    la4= Abs(l4);
    la5= Abs(l5);
    l=min(la1,min(la2,min(la3,min(la4,la5))));
    return l;
}
//=========================================================================================
//=========================================================================================
double stod_p(string str){
    double coef;
    if (str.substr(0,1)=="x"|| str.substr(0,1)=="y"||str.substr(0,1)=="z"|| str.substr(0,1)=="w"|| str.substr(0,1)=="t")
    {
        coef=1;
    }
    else{
            coef=stod(str);
    }
    return coef;
}
//=========================================================================================
//=========================================================================================
bool est_y(string str){
    int lx, ly,lz,lw,lt;
    bool reponse=0;

            lx=str.find("x");
            ly=str.find("y");
            lz=str.find("z");
            lw=str.find("w");
            lt=str.find("t");
    if (lx<0 && lw<0 && lz<0 && lt<0 && ly>=0)
    {
        reponse=1;
    }
    return reponse;
}
//=========================================================================================
//=========================================================================================
double coef_y(string str){
    double coef=0;
    if (est_y(str)==1)
    {
        if(str=="y"){
            coef=1;
        }
        else{
            coef=stod_p(str);
        }
    }
    return coef;
}

//=========================================================================================
//=========================================================================================
double RetreiveParan(string polyini){

    double fin, dbl;
    string polyret,monome,polyfin,polyinter,monw,monx,mony,monz,coef,monomefin;
    polyret=EspSpp(polyini);
    int l1,lparen1,lparen2,lchap,lw,lx,lz,ly,lt,lplus1, lplus2, lplus3,l,la, lplus4;
    l1=polyret.length();
    lplus4=(polyret.substr(1,l1-1)).find("+");
    //lplus1=polyret.find("+");
    polyfin=" ";
    fin=0;
    if (lplus4<0)
    {
        polyfin=polyret;
        double valeur_inter;
        if (est_y(polyfin)==1)
        {
            valeur_inter=coef_y(polyfin);
        }
        else{
            valeur_inter=stod_p(polyfin);
        }
        if (valeur_inter==0 && polyfin.length()>=4)
        {
            fin=1;
        }
        else{
             if (valeur_inter>=1)
             {
                 fin= valeur_inter;
             }
        }
    }
    else{
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
            lt=monome.find("t");
            lparen1=monome.find("(");
            lparen2=monome.find(")");
            la=minimum(lz,lw,lx,ly,lt);
             if (la>=1)
            {
              //monomefin=monome.substr(0,la+1);
              dbl=stod_p(monome);
            }
            if(la==0 && monome.length()>=3){
                 dbl=1;
            }
             
           
             fin=fin+dbl;
            // cout<<monz<<endl;
            // cout<<"monw="<<monw<<" monx= "<<monx<<"  mony= "<<mony<<" monz= "<<monz<<" coef= "<<coef<<endl;
        }
        if (compt<i)
        {
           // monome=polyret;

            break;
        }
        
      

    }
            lx=polyinter.find("x");
            ly=polyinter.find("y");
            lz=polyinter.find("z");
            lw=polyinter.find("w");
            lt=monome.find("t");
            la=minimum(lw,lx,lz,ly,lt);
            if (la==0 && monome.length()>=3)
            {
                dbl=1;
            }
            else{
               //polyinter= polyinter.substr(0,la+1);
               dbl=stod_p(polyinter);
            }
    fin=fin+dbl;
}
    return fin;
}
void decoupage(string commande,int n,int m){
    //vector<pair<string, string> >graphe;
    string matrice[n][m], text1, textr, text2,textr1;
    int lcrochet1, lcrochet2, lvirgule,lvirguleinter,ltemp,l1,l;
    textr=commande;
    lcrochet2=commande.find("]");
    l=commande.length();
     ltemp=textr.length();
     lvirguleinter=text1.find(",");
     int i=0;
    while (lcrochet2>=0)
    {  
        if (lcrochet2>0)
        {
        ltemp=textr.length();
        text1=textr.substr(0,lcrochet2);
        text2=textr.substr(lcrochet2+3,ltemp-lcrochet2-3);
        textr=text2;
        lcrochet2=textr.find("]");
        }
        else{
            text1=textr;
        }
       // lvirguleinter=text1.find(",");
        int j=0;
        lvirguleinter=text1.find(",");
        while (lvirguleinter>=0)
        {
            l1=text1.length();
            matrice[i][j]=text1.substr(0,lvirguleinter);
            textr1=text1.substr(lvirguleinter+1,l1-lvirguleinter-1);
            text1=textr1;
             lvirguleinter=text1.find(",");
            j++;
            
        }
        matrice[i][m-1]=text1;
        
      i++;
  }
  text1=textr;
  lvirguleinter=text1.find(",");
  int j=0;
  while (lvirguleinter>=0)
        {
            l1=text1.length();
            matrice[i][j]=text1.substr(0,lvirguleinter);
            textr1=text1.substr(lvirguleinter+1,l1-lvirguleinter-1);
            text1=textr1;
             lvirguleinter=text1.find(",");
            j++;
            
        }
        matrice[n-1][m-1]=text1;
        double compteur=0;
        double compt=0;
        for (int j = 10; j < m; ++j)
        {
            
        if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38)
        {    compteur=compteur + RetreiveParan(matrice[0][j]);
            compt=compt+RetreiveParan(matrice[0][j]);
           // cout<<"M("<<0<<","<<j<<")="<<(matrice[0][j])<<endl;
        }
        }
            cout<<"compteur1= "<<compt<<endl;
             compt=0;
            cout<<"======================3========================"<<endl;
        for (int j = 10; j < m; ++j)
        {
            
        if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38)
            {
            compteur=compteur + RetreiveParan(matrice[2][j]);
             compt=compt+RetreiveParan(matrice[2][j]);
          //   cout<<"M("<<2<<","<<j<<")="<<(matrice[2][j])<<endl;
        }
         }
            cout<<"compteur3= "<<compt<<endl;
             compt=0;
             cout<<"======================5========================"<<endl;
        for (int j = 10; j < m; ++j)
        {
            
        if (j==10 || j==11|| j==12 || j==13  || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38)
            {
            compteur=compteur + RetreiveParan(matrice[4][j]);
             compt=compt+RetreiveParan(matrice[4][j]);
             //cout<<"M("<<4<<","<<j<<")="<<(matrice[4][j])<<endl;
        }
          }
             cout<<"compteur5= "<<compt<<endl;
             compt=0;
             cout<<"======================7========================"<<endl;
          for (int j = 10; j < m; ++j)
        {
            
        if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38)
            {
            compteur=compteur + RetreiveParan(matrice[6][j]);
             compt=compt+RetreiveParan(matrice[6][j]);
            // cout<<"M("<<6<<","<<j<<")="<<(matrice[6][j])<<endl;
          }
      }
            cout<<"compteur7= "<<compt<<endl;
             compt=0;
             cout<<"======================11========================"<<endl;
          for (int j = 10; j < m; ++j)
        {
            
        if (j==10 || j==11|| j==12 || j==13 || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38)
            {
            compteur=compteur + RetreiveParan(matrice[10][j]);
             compt=compt+RetreiveParan(matrice[10][j]);
            // cout<<"M("<<10<<","<<j<<")="<<(matrice[10][j])<<endl;
        }
    }
            cout<<"compteur11= "<<compt<<endl;
             compt=0;
          
             cout<<"=====================16========================="<<endl;
          for (int j = 10; j < m; ++j)
        {
            
        if (j==10 || j==11|| j==12 || j==13  || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38)
            {
            compteur=compteur + RetreiveParan(matrice[15][j]);
             compt=compt+RetreiveParan(matrice[15][j]);
            // cout<<"M("<<15<<","<<j<<")="<<(matrice[15][j])<<endl;
           }
       }
             cout<<"compteur16= "<<compt<<endl;
             compt=0;
             cout<<"=====================20========================="<<endl;

        for (int j = 10; j < m; ++j)
        {
            
        if (j==10 || j==11|| j==12 || j==13  || j==14 || j==19 || j==20 || j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33|| j==34|| j==35|| j==37|| j==38)
            {
                compteur=compteur + RetreiveParan(matrice[19][j]);
                 compt=compt+RetreiveParan(matrice[19][j]);
                // cout<<"M("<<19<<","<<j<<")="<<(matrice[19][j])<<endl;
            }
        }
        cout<<"compteur20= "<<compt<<endl;
        cout<<"Total=  "<<compteur<<endl;
}
        
int main(int argc, char const *argv[])
{
 string line;
 int n,m;
 cin>>n;
 cin>>m;
 cin>>line;
decoupage(line,n,m);
return 0;
}