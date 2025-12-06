#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

int main ()
{
   ofstream outfile;
   outfile.open("country");
   
   outfile<<"united states\n";
   outfile<<"united kingdom\n";
   outfile<<"south korea\n";
   outfile.close();

   outfile.open("capital");
   outfile<<"washington\n";
   outfile<<"london\n";
   outfile<<"seoul\n";
   outfile.close();

   const int N = 80;
   char line [N];
   ifstream fin;
   fin.open("country");
   cout<<"content of country\n";
   while(fin)
   {
      fin.getline(line,N);
      cout<<line<<"\n";
   }
  fin.close();

  fin.open("capital");
  cout<<"content of capital\n";
   while(fin)
   {
      fin.getline(line,N);
      cout<<line<<"\n";
   }
   fin.close();

   return 0;
}