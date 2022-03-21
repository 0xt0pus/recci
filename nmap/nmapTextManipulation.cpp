#include<iostream>
#include<fstream>
using namespace std;
int main()
{

string myText;
int openPortsCount=0;

ifstream File;
File.open("nmap/nmapRead");
while (getline (File, myText)) {

  if(myText[0]>'0' && myText[0]<'9')
  {

  	  // cout << mycout<<"the number of open ports are "<<openPortsCount<<endl;Text<<endl;
      openPortsCount++;

  }

}



File.close();

cout<<"the number of open ports are "<<openPortsCount<<endl;

int *ports=new int[openPortsCount];//contains all the open ports

string *services=new string[openPortsCount];


// cout<<endl;
// cout<<endl;

File.open("nmap/nmapRead");

int j=0; //for which port to store

ofstream OpenP;
OpenP.open("nmap/OpenPorts");//for writing al open ports in file//writing open ports in fil

ofstream SerAndVer;
SerAndVer.open("nmap/ServicesAndVersions");//for writing al open ports in file//writing open ports in fil

ofstream ver;
ver.open("nmap/Versions");//for writing al open ports in file//writing open ports in fil



while (getline (File, myText)) 
{
 // cout<<"the text is "<<myText<<endl;
 string serviceAndversion="";
string version="";

  string name="";


  if(myText[0]>'0' && myText[0]<'9')
  {
    int i=0;
      for(;myText[i]!=' ';i++)
      {
        name=name+myText[i];
      }



      for(;myText[i]==' ';i++)
      {

      }

      for(;myText[i]!=' ';i++)
      {

      }

      for(;myText[i]==' ';i++)
      {

      }

      int flag=i;

      for(;myText[i]!='\0';i++)
      {

        serviceAndversion=serviceAndversion+myText[i];

      }


      for(i=flag;myText[i]!=' ';i++)
      {

      }


      for(;myText[i]==' ';i++)
      {

      }

      int h=0;

      for(;myText[i]!='\0';i++)
      {

        
        if(h==2)
        {
          continue;
        }


        if(myText[i]==' ')
        {
          h++;
        }

        version=version+myText[i];

      }

  ports[j]=stoi(name);
  OpenP<<ports[j]<<endl;//writing open ports in fil
  SerAndVer<<serviceAndversion<<endl;
  ver<<version<<endl;
  // cout<<serviceAndversion<<endl;

  j++;



  }

}






File.close();
OpenP.close();
SerAndVer.close();
ver.close();



for(int i=0;i<openPortsCount;i++)
{
  // cout<<ports[i]<<" ";
}



}