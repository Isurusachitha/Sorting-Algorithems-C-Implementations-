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

void NearlySort(int Min,const int Range,vector<int>& VecN,int ksort);
void FileWrite(const vector<int>& VecN);

//Main funtion

int main(){

   std::vector<int> VecNum;
   int K,Min,Range;


   Val1:std::cout << "How many Nearly sorted Random numbers needed  :" ;
   cin>>Range;
   if (0>=Range) {
	   cout << "<!>  Invalid Range <!> :"<<endl;
	   goto Val1;
   }
   Val2:std::cout << "Minimum value of a random number:" ;
   cin>>Min;
   if (0 > Min) {
	   cout << "<!>  Invalid Minimum <!> :" << endl;
	   goto Val2;
   }
   Val3:std::cout << "K values of Nearly sorted list:"  ;
   cin>>K;
   if (0 > K) {
	   cout << "<!>  Invalid Maximum <!> :" << endl;
	   goto Val3;
   }
  // add validation to above line

   std::cout << "------------------------------\n"  ;
   std::cout << "Generated  Random numbers are :\n"  ;
   std::cout << "------------------------------\n"  ;
   NearlySort(Min,Range,VecNum,K);
   FileWrite(VecNum);

   std::cout << "-------------------------------------------\n"  ;
   std::cout << "Random numbers are saved to ‘SetD.txt’ file \n"  ;

  // return statement
  return 0;
}

void NearlySort(int Min,const int Range,vector<int>& VecN,int ksort){


    srand((unsigned)time(0));
    int random_integer;


     for (int i = 0,k=ksort; i < Range; ){

          for (int j  = 0; j < ksort; ) {

						random_integer = (rand()%(k+1)) ;

						if(random_integer>=Min){

							 std::cout <<  random_integer <<'\n';
							 VecN.push_back(random_integer);

							 j++;

							 i++;

						}
          	/* code */
          }

					k+=10;
					Min+=10;


     }



}

void FileWrite(const vector<int>& VecN){


              ofstream outfile;  // creating output stream object
	            outfile.open("SetD.txt"); // creating output file



	           for (int i = 0; i < VecN.size(); i++) {

		         outfile << VecN[i]<< endl;

					   }

						 outfile.close();  // clsing output stream


}
