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
int minimum(int l1, int l2, int l3, int l4){
    int l,la1,la2,la3,la4;
    la1=Abs(l1);
    la2= Abs(l2);
    la3= Abs(l3);
    la4= Abs(l4);
    l=min(la1,min(la2,min(la3,la4)));
    return l;
}
double RetreiveParan(string polyini){

    double fin, dbl;
    string polyret,monome,polyfin,polyinter,monw,monx,mony,monz,coef,monomefin;
    polyret=EspSpp(polyini);
    int l1,lparen1,lparen2,lchap,lw,lx,lz,ly,lplus1, lplus2, lplus3,l,la, lplus4;
    l1=polyret.length();
    lplus4=(polyret.substr(1,l1-1)).find("+");
    //lplus1=polyret.find("+");
    polyfin=" ";
    fin=0;
    if (lplus4<0)
    {
        polyfin=polyret;
        double valeur_inter=stod(polyfin);
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
            la=minimum(lz,lw,lx,ly);
             if (la>=1)
            {
              //monomefin=monome.substr(0,la+1);
              dbl=stod(monome);
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
            la=minimum(lw,lx,lz,ly);
            if (la==0 && monome.length()>=3)
            {
                dbl=1;
            }
            else{
               //polyinter= polyinter.substr(0,la+1);
               dbl=stod(polyinter);
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
    //lcrochet1=commande.find("[");
    lcrochet2=commande.find("]");
    cout<<lcrochet2<<endl;
    cout<<lcrochet2+3<<endl;
    //lvirgule=commande.find(",");
    l=commande.length();
    cout<<l<<endl;
    // cout<<lvirgule<<endl;
     cout<<l-lcrochet2-3<<endl;
     ltemp=textr.length();
     //text1=textr.substr(0,lcrochet2);
    // text2=textr.substr(lcrochet2+3,ltemp-lcrochet2-3);
     //textr=text2;
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
        //matrice[0][0=]=text1.substr(0,lvirguleinter);
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
        int compteur=0;
        int compt=0;
    	for (int j = 14; j < m; ++j)
    	{
    		cout<<"M"<<"1"<<","<<j+1<<"= "<<RetreiveParan(matrice[0][j])<<endl;
            cout<<endl;
        if (j==14 ||j==20 ||  j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33 || j==34 || j==36)
            {
            compteur=compteur + RetreiveParan(matrice[0][j]);
            compt=compt+RetreiveParan(matrice[0][j]);
        }
        }
            cout<<"compteur1= "<<compt<<endl;
             compt=0;
            cout<<"======================3========================"<<endl;
        for (int j = 14; j < m; ++j){
            cout<<"M"<<"3"<<","<<j+1<<"= "<<RetreiveParan(matrice[2][j])<<endl;
            cout<<endl;
        if (j==14 ||j==20 ||  j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33 || j==34 || j==36)
            {
            compteur=compteur + RetreiveParan(matrice[2][j]);
             compt=compt+RetreiveParan(matrice[2][j]);
        }
         }
            cout<<"compteur3= "<<compt<<endl;
             compt=0;
             cout<<"======================5========================"<<endl;
         for (int j = 14; j < m; ++j){
            cout<<"M"<<"5"<<","<<j+1<<"= "<<RetreiveParan(matrice[4][j])<<endl;
            cout<<endl;
        if (j==14 ||j==20 ||  j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33 || j==34 || j==36)
            {
            compteur=compteur + RetreiveParan(matrice[4][j]);
             compt=compt+RetreiveParan(matrice[4][j]);
        }
          }
             cout<<"compteur5= "<<compt<<endl;
             compt=0;
             cout<<"======================7========================"<<endl;
          for (int j = 14; j < m; ++j){
            cout<<"M"<<"7"<<","<<j+1<<"= "<<RetreiveParan(matrice[6][j])<<endl;
            cout<<endl;
        if (j==14 ||j==20 ||  j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33 || j==34 || j==36)
            {
            compteur=compteur + RetreiveParan(matrice[6][j]);
             compt=compt+RetreiveParan(matrice[6][j]);
          }
      }
            cout<<"compteur7= "<<compt<<endl;
             compt=0;
             cout<<"======================11========================"<<endl;
           for (int j = 14; j < m; ++j){
            cout<<"M"<<"11"<<","<<j+1<<"= "<<RetreiveParan(matrice[10][j])<<endl;
            cout<<endl;
           if (j==14 ||j==20 ||  j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33 || j==34 || j==36)
            {
            compteur=compteur + RetreiveParan(matrice[10][j]);
             compt=compt+RetreiveParan(matrice[10][j]);
        }
    }
            cout<<"compteur11= "<<compt<<endl;
             compt=0;
          
             cout<<"=====================16========================="<<endl;
          for (int j = 14; j < m; ++j){
            
            cout<<"M"<<"16"<<","<<j+1<<"= "<<RetreiveParan(matrice[15][j])<<endl;
            cout<<endl;
            if (j==14 ||j==20 ||  j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33 || j==34 || j==36)
            {
            compteur=compteur + RetreiveParan(matrice[15][j]);
             compt=compt+RetreiveParan(matrice[15][j]);
           }
       }
             cout<<"compteur16= "<<compt<<endl;
             compt=0;
             cout<<"=====================20========================="<<endl;

        for (int j = 14; j < m; ++j){
            
            
                cout<<"M"<<"20"<<","<<j+1<<"= "<<RetreiveParan(matrice[19][j])<<endl;
                cout<<endl;
            if (j==14 ||j==20 ||  j==21 || j==22 || j==23 || j==24 || j==25 || j==26 || j==32 || j==33 || j==34 || j==36)
            {
                compteur=compteur + RetreiveParan(matrice[19][j]);
                 compt=compt+RetreiveParan(matrice[19][j]);
            }
        }
        cout<<"compteur20= "<<compt<<endl;
        cout<<"Total=  "<<compteur<<endl;
       /* for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <m; ++j)
            {
                cout<<"M("<<i+1<<","<<j+1<<"]="<<matrice[i][j]<<endl;
            }
        }*/
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