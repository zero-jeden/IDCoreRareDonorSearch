#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "ExtraDINFile.h"
#include<vector>
using namespace std;



vector<Sample> samples;


void loadFiles(string file){
ifstream fileToOpen;
   fileToOpen.open(file);
   if (fileToOpen.is_open()){
        cout << "Opened file "<< endl ;
   }
   else{
   cout << "Error opening file " << endl;
   }

   string singleLine;
   getline(fileToOpen, singleLine);   //takes out headers
   cout << singleLine << endl;
   getline(fileToOpen, singleLine);
   cout << singleLine << endl;
   getline(fileToOpen, singleLine);
   cout << singleLine << endl;
    getline(fileToOpen, singleLine);
   cout << singleLine << endl;
   getline(fileToOpen, singleLine);
   cout << singleLine << endl;
   getline(fileToOpen, singleLine);
   cout << singleLine << endl;
    getline(fileToOpen, singleLine);
   cout << singleLine << endl;
   getline(fileToOpen, singleLine);
   cout << singleLine << endl;
   
  getline(fileToOpen, singleLine);
   cout << singleLine << endl;
    


   

   //while (getline(fileToOpen,singleLine)){

    string  din;
    string  C;
    string  E;
    string  c;
    string  e;
    string  CW;
    string  V;
    string  hrs;
    string  VS;
    string  hrB;
    string  K;
    string  k;
    string  Kpa;
    string  Kpb;
    string  Jsa;
    string  Jsb;
    string  Jka;
    string  Jkb;
    string  Fya;
    string  Fyb;
    string  M;
    string  N;
    string  S;
    string  s;
    string  U;
    string  Mia;
    string  Dia;
    string  Dib;
    string  Doa;
    string  Dob;
    string  Hy;
    string  Joa;
    string  Coa;
    string  Cob;
    string  Yta;
    string  Ytb;
    string  Lua;
    string  Lub;

    
    
   istringstream stream(singleLine);
   getline(stream, din, ';');
   cout << din << endl;
   
  
   getline(stream, C, ';');
   cout << C << endl;
   
   getline(stream, C, ';');
   cout << C << endl;

    getline(stream, E, ';');
   cout << E << endl;

    getline(stream, c, ';');
   cout << c<< endl;

    getline(stream, e, ';');
   cout << e << endl;

    getline(stream, CW, ';');
   cout << CW << endl;

    getline(stream, V, ';');
   cout << V << endl;

    getline(stream, hrs, ';');
   cout << hrs << endl;

    getline(stream, VS, ';');
   cout << VS << endl;
   
   getline(stream, hrB, ';');
   cout << hrB << endl;

    getline(stream, K, ';');
   cout << K << endl;

    getline(stream, k, ';');
   cout << k<< endl;

    getline(stream, Kpa, ';');
   cout << Kpa << endl;

    getline(stream, Kpb, ';');
   cout << Kpb << endl;

    getline(stream, Jsa, ';');
   cout << Jsa << endl;

    getline(stream, Jsb, ';');
   cout << Jsb << endl;

    getline(stream, Jka, ';');
   cout << Jka << endl;

    getline(stream, Jkb, ';');
   cout << Jkb << endl;

    getline(stream, Fya, ';');
   cout << Fya << endl;
   
   getline(stream, Fyb, ';');
   cout << Fyb<< endl;

    getline(stream, M, ';');
   cout << M << endl;

    getline(stream, N, ';');
   cout << N<< endl;

    getline(stream, S, ';');
   cout << S << endl;

    getline(stream, s, ';');
   cout << s << endl;

    getline(stream, U, ';');
   cout << U << endl;

    getline(stream, Mia, ';');
   cout << Mia << endl;

    getline(stream, Dia, ';');
   cout << Dia << endl;
   
       getline(stream, Dib, ';');
   cout << Dib << endl;

    getline(stream, Doa, ';');
   cout << Doa << endl;
   
   getline(stream, Dob, ';');
   cout <<Dob<< endl;

    getline(stream,Hy, ';');
   cout <<Hy << endl;

    getline(stream, Joa, ';');
   cout << Joa<< endl;

    getline(stream, Coa, ';');
   cout << Coa << endl;

    getline(stream, Cob, ';');
   cout << Cob << endl;

    getline(stream, Yta, ';');
   cout << Yta << endl;

    getline(stream, Ytb, ';');
   cout << Ytb << endl;

    getline(stream, Lua, ';');
   cout << Lua << endl;
   
   getline(stream, Lub, ';');
   cout << Lub << endl;
   
   Sample sample(
       din ,
       C ,
       E ,
       c ,
       e ,
       CW ,
       V ,
       hrs ,
       VS ,
       hrB ,
       K ,
       k ,
       Kpa ,
       Kpb ,
       Jsa ,
       Jsb ,
       Jka ,
       Jkb ,
       Fya ,
       Fyb ,
       M ,
       N ,
       S ,
       s ,
       U ,
       Mia ,
       Dia ,
       Dib ,
       Doa ,
       Dob ,
       Hy ,
       Joa ,
       Coa ,
       Cob ,
       Yta ,
       Ytb ,
       Lua ,
       Lub
);

    samples.push_back(sample);




   
   


  

	//}// whiule loop
}


int main()
{
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. Run One" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;

	if (option == 1){
	loadFiles("./022825_Phenotype.txt");
	return 0;
	}
	else if (option == 2){
	loadFiles("./lego2.csv");
	}
	else if (option == 3){
	loadFiles("./lego3.csv");
	}
	else if (option == 4){
	loadFiles("./lego1.csv");
	loadFiles("./lego2.csv");
	loadFiles("./lego3.csv");
	}


   /*======= Load data from file(s) =======*/


    cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;
   
	int choice;
	cin >> choice;
   cin.get();  // Clear newline character for any later input
   
   /*======= Print out how many sets were loaded =======*/
 

   /*======= Based on the choice, execute the appropriate task and show the results =======*/
   if (choice == 1){
   
   }
   if (choice == 2){
   
   }
   if (choice == 3){
   string target;
   //cout << "Enter a name: " << endl;
   
   }
   if (choice == 4){
   
   }
   if (choice == 5){
   
   }
   if (choice == 6){
   
   }
   if (choice == 7){
  
   }
   if (choice == 8){
   
   }

   if (choice == 0){
   return 0;
   }
	return 0;
}
