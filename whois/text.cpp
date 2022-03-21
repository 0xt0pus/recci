#include<iostream>
#include<fstream>
using namespace std;
int main()
{

	// cout<<"hello world"<<endl;


	fstream File;

	File.open("data");

string myText;

string total="";

while (getline (File, myText)) {



	total=total+myText+"\n";


	if(myText[0]=='>')
	{

		while(getline (File,myText))
		{

			if(myText[0]=='D' && myText[1]=='o' && myText[5]=='n' && myText[7]=='N')
			{

				total=total+myText+"\n";

				while(getline(File,myText))
				{
					total=total+myText+"\n";

					if(myText[0]=='>')
					{
						while(getline(File,myText))
						{

						}
					}


				}


			}





		}

	}




}

	
File.close();



ofstream F;

F.open("WhoisData");

F<<total;
}