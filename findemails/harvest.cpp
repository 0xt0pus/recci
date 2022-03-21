#include<iostream>
#include<fstream>
using namespace std;


int main()
{
  string line;
  bool email=false;
  bool host=false;
  int i=0;
  int j=0;
  ofstream myfilee ("file4.txt");
  ifstream myfile ("file3.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      if(line[0] == '[')
      {
         if(line[4] == 'E')
         {
            email=true;
            i=1;
         }
      }
      
      if(line[0] == '[')
      {
         if(line[4] == 'H')
         {
            email=false;
            host = true;
            j=1;
         }
      }
      
      if(email == true)
      {
         if(i == 1 )
         {
             cout<<endl<<endl;
            cout<<"\033[1;31m*********************\033[0m";
            cout<<"\n\033[1;31m*                                                       *\033[0m";
            cout<<"\n\033[1;31m*                       EMAILS                          *\033[0m";
            cout<<"\n\033[1;31m*                                                       *\033[0m";
            cout<<"\n\033[1;31m*********************\033[0m";
            cout<<endl;
            cout<<endl;
             myfilee << "EMAIL\n";
            i=2;
         }
         
         if(line[4] != 'E' && line[0] != '-')
         {
           cout<<"                   "<<"\033[1;36m"<<line<<"\033[0m"<<endl;
            myfilee << line;
         }
      }
      
      if(host == true)
      {
          if(j == 1 )
         {
            cout<<endl<<endl;
            cout<<"\033[1;31m*********************\033[0m";
            cout<<"\n\033[1;31m*                                                       *\033[0m";
            cout<<"\n\033[1;31m*                       HOSTS                           *\033[0m";
            cout<<"\n\033[1;31m*                                                       *\033[0m";
            cout<<"\n\033[1;31m*********************\033[0m";
            cout<<endl;
            cout<<endl;
             myfilee << "\n\n";
              myfilee << "HOSTS\n";
            j=2;
         }
         if(line[4] != 'H' && line[0] != '-')
         {
           cout<<"             "<<"\033[1;36m"<<line<<"\033[0m"<<endl;
            myfilee << line;
         }
      }
      
      
         
    }
    myfile.close();
  }

}