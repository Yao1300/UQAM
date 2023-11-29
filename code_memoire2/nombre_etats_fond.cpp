#include<iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <ginac/ginac.h>
using namespace std;
using namespace GiNaC;
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
double factoriel(int n){
	double nbre=1;
	for (int i = 1; i < n+1; ++i)
	{
		nbre=i*nbre;
	}
	    
	    	return nbre;
	    
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
vector<string> Binaire(int longueur){
vector<string> V;
if(longueur==1){

	V.push_back("0");
	V.push_back("1");
}
if (longueur>=2)
{
	  vector<string>V2;
	  V2= Binaire(longueur-1);
	  for (int i = 0; i < V2.size(); ++i)
	  {
	  	V.push_back("0"+V2[i]);
	  	V.push_back("1"+V2[i]);
	  }
	  
}
return V;

}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
bool etat_nul(string bin){
	bool reponse=0;
	int compt=0;
	for (int j = 0; j < bin.length(); ++j)
	     {
		    if (bin.substr(j,1)=="0")
		    {
		    	compt++;
		    }
	     }
	     if (compt==bin.length())
	     {
	     	reponse=1;
	     }
	     return reponse;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int nombre_part(string bin){
	int ncp;
	   if (bin.substr(0,1)=="1")
	   {
	   	 ncp=1;
       for (int j = 0; j < bin.length(); ++j)
	     {
		    if (bin.substr(j,1)=="0" &&  bin.substr(j+1,1)=="1")
		    {
		    	ncp++;
		    }
	     }
	 }
	     if (bin.substr(0,1)=="0"){
	     	ncp=0;
	     	for (int j = 0; j < bin.length(); ++j)
	     {
		    if (bin.substr(j,1)=="0" &&  bin.substr(j+1,1)=="1")
		    {
		    	ncp++;
		    }
	       }
	    }
	return ncp;
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int catalan(int n){
	int cat=(factoriel(2*n))/(factoriel(n)*factoriel(n+1));
	return cat;
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
void Etat(int n){
for (int i = 1; i < n+1; ++i)
{
	for (int j = 0; j < Binaire(i).size(); ++j)
	{
		cout<<Binaire(i)[j]<<endl;
	}
}
}
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
 int nombre_etat_fond(int n){
 	int nombre=0;
 	int m;
    for (int i = 1; i < n+1; ++i)
{
	for (int j = 0; j < Binaire(i).size(); ++j)
	{
		if (etat_nul(Binaire(i)[j])==0)
		{
			m=nombre_part(Binaire(i)[j]);
			//cout<<Binaire(i)[j]<<endl;
			//cout<<"m="<<m<<endl;
			nombre= nombre+catalan(m);
		}
	}
}
 	return nombre;
 }
//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;

     
     	cout<<nombre_etat_fond(n)<<endl;
     
}