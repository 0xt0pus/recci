#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main()
{
char enter;
string line;
  ifstream myfile ("file");
  ofstream myfilee;
  int i=0;
  bool b = false;
  bool r = 0;
  cout<<endl<<endl;
  
  string result="";
  
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      if( line[1] == '-' || b == true)
      {
	 
	      b=true;
	      if(line[0] == '1')
	      {
	           if(line[36]==' ')
	           {
	              char c = line[37];
	              result.push_back(c);
	              
	              
	              int myint1 = stoi(result);
	              if(myint1 > 50)
	              {
	              cout<<"\033[1;31m**THE SITE IS DOWN**\033[0m"<<endl;
	     
			  myfilee.open ("PingResult");
			  myfilee << "0";
			  myfilee.close();
	              return 0;
	              }
	              else
	              {
	                cout<<"\033[1;34m**THE SITE IS UP**\033[0m"<<endl;
	                 myfilee.open ("PingResult");
			 myfilee << "1";
			 myfilee.close();
	                return 0;
	              }
	           }
	           else
	           {
	           char c;
	              c=line[36];
	              result.push_back(c);
	              c=line[37];
	              result.push_back(c);
	              
	              if( line[38] != '%')
	              {
	                 c=line[38];
	              result.push_back(c);
	              }
	              
	              int myint1 = stoi(result);
	              if(myint1 > 50)
	              {
	              cout<<"\033[1;31m**THE SITE IS DOWN**\033[0m"<<endl;
	               myfilee.open ("PingResult");
		       myfilee<< "0";
		       myfilee.close();
	              return 0;
	              }
	              else
	              {
	                cout<<"\033[1;34m**The SITE IS UP**\033[0m"<<endl;
	                 myfilee.open ("PingResult");
			  myfilee << "1";
			  myfilee.close();
	                return 0;
	              }
	           }
	      }
	    
      }
        i++;
    }
    myfile.close();
  }

 return 0;



}