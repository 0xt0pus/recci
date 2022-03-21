#include<iostream>
#include<fstream>
using namespace std;

int main()
{
bool country=true;
bool server=true;
bool set_cookie=true;
bool title=true;
bool lang=false;
bool html=true;
bool b = false;
bool script = true;
bool framework=true;
bool jquery=true;
bool content_type=true;
bool X1=true;
bool X2=true;
bool X3=true;
char enter;

string line;
 cout<<"\n\n\033[1;33m__________________"<<"\033[1;31mSERVER & COOKIES & LOCATION \033[0m"<<"\033[1;33m____________________\033[0m\n"<<endl<<endl;
  ifstream myfile ("file.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
    
    
    
      if(line[0] == 'T' && title == true)
      {
         if(line[2] == 't')
         {
            cout<<"\033[1;33m* \033[0m"<<line;
            cout<<endl;
            title = false;
         }
        
      }
      
    
    
      
      if(line[0] == 'C' && country == true)
      {
         if(line[2] == 'u')
         {
            cout<<"\033[1;33m* \033[0m"<<line;
            cout<<endl;
            country = false;
         }
        
      }
      
      
      if(line[0] == 'S' && server == true)
      {
         if(line[6] == ':')
         {
            cout<<"\033[1;33m* \033[0m";
            for(int i=0;i<6;i++)
            {
               cout<<line[i];
            }
            cout<<"    ";
            for(int i=6;line[i]!= '\0';i++)
            {
               cout<<line[i];
            }
            cout<<endl;
            server = false;
         }
        
      }
     
      
      
      if(line[0] == 'S' && set_cookie == true)
      {
         if(line[2] == 't')
         {
            
            cout<<"\033[1;33m* \033[0m"<<line;
            cout<<endl;

           
            
            lang = true;
         }
        
      }
      
      if(line[0] == 'c' || line[0] == 'C' && content_type == true)
      {
         if(line[8] == 't' || line[8] == 'T')
         {
            
            cout<<"\033[1;33m* \033[0m"<<line;
            cout<<endl;

           
            content_type= false;
            
         }
        
      }
      
      if(line[0] == 'X' && X1 == true)
      {
         if(line[2] == 'F' || line[8] == 'T')
         {
            
            cout<<"\033[1;33m* \033[0m"<<line;
            cout<<endl;

           
            X1= false;
            
         }
        
      }
      
      if(line[0] == 'X' && X2== true)
      {
         if(line[2] == 'X')
         {
            
            cout<<"\033[1;33m* \033[0m"<<line;
            cout<<endl;

           
            X2= false;
            
         }
        
      }
      
      if(line[0] == 'X' && X3== true)
      {
         if(line[12] == ':')
         {
            
            cout<<"\033[1;33m* \033[0m"<<line;
            cout<<endl;

           
            X3= false;
            
         }
        
      }
       
       
      
    }
    myfile.close();
  }
  
  
  cout<<"\n\033[1;33m--------------------------------------------------------------------------------------------------------------------------------------------\033[0m"<<endl<<endl;  
  cout<<"\n\n\033[1;33m___________________"<<"\033[1;31mlanguage & framework\033[0m"<<"\033[1;33m______________________\033[0m\n"<<endl<<endl;
  
  
  
  
    ifstream myfilee ("file.txt");
  if (myfilee.is_open())
  {
    while ( getline (myfilee,line) )
    {
    
      
	       if(line[0] == '[' && html == true )
	      {
		 if(line[4] == 'M')
		 {
		    
		    cout<<"\033[1;33m* \033[0m"<<"Language  : HTML5";
		    cout<<endl;

		   
		    html= false;
		 }
		
	      }
      
      
      
	       if(line[0] == '[' && script == true )
	       {
		 if(line[3] == 'c')
		 {
		    
		    cout<<"\033[1;33m* \033[0m"<<"Language  : text/javascript";
		    cout<<endl;

		   
		    script= false;
		 }
		
	      }
	      
	      
	       if(line[0] == '[' && script == true )
	       {
		 if(line[3] == 'c')
		 {
		    
		    cout<<"\033[1;33m* \033[0m"<<"Language  : text/javascript";
		    cout<<endl;

		   
		    script= false;
		 }
		
	      }
	      
	       if(line[0] == '[' && framework == true )
	       {
		 if(line[2] == 'B')
		 {
		    
		    cout<<"\033[1;33m* \033[0m"<<"ToolKit   : Boostrap";
		    cout<<endl;

		   
		    framework= false;
		 }
		
	      }
	      
	      if(line[0] == '[' && jquery == true )
	       {
		 if(line[2] == 'J')
		 {
		    
		    cout<<"\033[1;33m* \033[0m"<<"language  : JQuery";
		    cout<<endl;

		   
		    jquery= false;
		 }
		
	      }
    
    
    }
    
   }
  
cout<<"\n\033[1;33m--------------------------------------------------------------------------------------------------------------------------------------------\033[0m\n"<<endl<<endl;  



 return 0;
 
}