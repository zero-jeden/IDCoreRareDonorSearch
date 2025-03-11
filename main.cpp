#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "ExtraDINFile.h"
using namespace std;






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

    
    /*
   istringstream stream(singleLine);
   getline(stream, idNumber, ',');
   idNumberName = idNumber;
   getline(stream, theme, ',');
   getline(stream, name, ',');

   getline(stream, token, ',');
   numMinis = stoi(token);
   getline(stream, token, ',');
   pieces = stoi(token);
   getline(stream, token, ',');
   price = stod(token);
   */


  

	//}
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
