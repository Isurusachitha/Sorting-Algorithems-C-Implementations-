/***********************************************************************************************************************************************
Courese      :    CO2201 Data Structures and Algorithms
Year         :    2018
Name         :    HERATH HMMISB
Index No     :    16_ENG_029
Lab No       :    3
Date         :   02-05-2018

**********************************************************************************************************************************************************/

//Header Files
#include <iostream>
#include <math.h>
#include<fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

//Declare namespace
using namespace std;

//Declaring Functions

void RandomNumers(const int Max,const int Min,const int Range,vector<int>& VecN);
void FileWrite(const vector<int>& VecN);

//Main funtion

int main(){

   std::vector<int> VecNum;
   int Max,Min,Range;


   Val1:std::cout << "How many random numbers needed  :" ;
   cin>>Range;
   if (0>=Range) {
	   cout << "<!>  Invalid Range <!> :"<<endl;
	   goto Val1;
   }
   Val2:std::cout << "Minimum value of a random number:" ;
   cin>>Min;
   if (0 >= Min) {
	   cout << "<!>  Invalid Minimum <!> :" << endl;
	   goto Val2;
   }
   Val3:std::cout << "Maximum value of a random number:"  ;
   cin>>Max;
   if (0 >= Max) {
	   cout << "<!>  Invalid Maximum <!> :" << endl;
	   goto Val3;
   }
  // add validation to above line

   std::cout << "------------------------------\n"  ;
   std::cout << "Generated unique(x 100) Random numbers are :\n"  ;
   std::cout << "------------------------------\n"  ;
   RandomNumers(Max,Min,Range,VecNum);
   FileWrite(VecNum);

   std::cout << "-------------------------------------------\n"  ;
   std::cout << "Random numbers are saved to ‘ran.txt’ file \n"  ;

  // return statement
  return 0;
}

void RandomNumers(const int Max,const int Min,const int Range,vector<int>& VecN){


    srand((unsigned)time(0));
    int random_integer;

     for (int i = 0; i < Range; ) {

           random_integer = (rand()%(Max+1)) ;

           if(random_integer>=Min){

              std::cout <<  random_integer <<'\n';
              VecN.push_back(random_integer*100);
              i++;

           }

     }



}

void FileWrite(const vector<int>& VecN){


              ofstream outfile;  // creating output stream object
	            outfile.open("SetE.txt"); // creating output file



	           for (int i = 0; i < VecN.size(); i++) {

		         outfile << VecN[i]<< endl;

					   }

						 outfile.close();  // clsing output stream


}
