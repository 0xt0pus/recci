#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	// [-] Total
// cout<<"hello";
	ifstream File;
	File.open("resultoOfSublist3r.txt");
string myText;


while (getline (File, myText)) 
{

  	// cout<<"YahooNoooo ";
  if(myText[4]=='T' && myText[5]=='o')
  {

  	// cout<<"Yahoo";

  	ofstream Final;
  	Final.open("finalresultoOfSublist3r.txt");

  	while (getline (File, myText)) 
	{
		Final<<myText<<endl;	
	}

  }

}



}