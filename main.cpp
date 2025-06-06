
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "ExtraDINFile.h"
#include<vector>
#include<map>
using namespace std;


int count = 1;
vector<Sample> samples;

void plateLocation(int index) {
	map<int, char> myMap;


	char row;
	int col;

	myMap[0] = 'A';
	myMap[1] = 'B';
	myMap[2] = 'C';
	myMap[3] = 'D';
	myMap[4] = 'E';
	myMap[5] = 'F';
	myMap[6] = 'G';
	myMap[7] = 'H';

	row = myMap[(index % 8) ];
	col = (index / 8) ;
	//cout << col;
	//cout << endl;
	cout << row << col + 1;


}

bool loadFiles(string file) {
	ifstream fileToOpen;
	fileToOpen.open(file);
	if (!fileToOpen.is_open()) {

		cout << "Error opening file " << endl;
		return false;
	}

	string singleLine;
	getline(fileToOpen, singleLine);   //takes out headers
	//cout << singleLine << endl;
	getline(fileToOpen, singleLine);   //this block prints date, user, and analysis software version.
	//cout << singleLine << endl;
	getline(fileToOpen, singleLine);
	//cout << singleLine << endl;
	getline(fileToOpen, singleLine);
	//cout << singleLine << endl;

	getline(fileToOpen, singleLine);
	//cout << singleLine << endl;
	getline(fileToOpen, singleLine);
	// << singleLine << endl;
	getline(fileToOpen, singleLine);
	// << singleLine << endl;
	getline(fileToOpen, singleLine);
	//cout << singleLine << endl


	//getline(fileToOpen, singleLine);
	//cout << singleLine << endl;





	for (int i = 0; i < 93; i++) {
		getline(fileToOpen, singleLine);
		//string singleLine;
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
		//cout << din << endl;


		getline(stream, C, ';');
		//cout << C << endl;

		getline(stream, E, ';');
		//cout << E << endl;

		getline(stream, c, ';');
		//cout << c<< endl;

		getline(stream, e, ';');
		//cout << e << endl;

		getline(stream, CW, ';');
		// << CW << endl;

		getline(stream, V, ';');
		//cout << V << endl;

		getline(stream, hrs, ';');
		//cout << hrs << endl;

		getline(stream, VS, ';');
		//cout << VS << endl;

		getline(stream, hrB, ';');
		//cout << hrB << endl;

		getline(stream, K, ';');
		//cout << K << endl;

		getline(stream, k, ';');
		//cout << k<< endl;

		getline(stream, Kpa, ';');
		//cout << Kpa << endl;

		getline(stream, Kpb, ';');
		//cout << Kpb << endl;

		getline(stream, Jsa, ';');
		//cout << Jsa << endl;

		getline(stream, Jsb, ';');
		//cout << Jsb << endl;

		getline(stream, Jka, ';');
		//cout << Jka << endl;

		getline(stream, Jkb, ';');
		//cout << Jkb << endl;

		getline(stream, Fya, ';');
		//cout << Fya << endl;

		getline(stream, Fyb, ';');
		//cout << Fyb<< endl;

		getline(stream, M, ';');
		//cout << M << endl;

		getline(stream, N, ';');
		//cout << N<< endl;

		getline(stream, S, ';');
		//cout << S << endl;

		getline(stream, s, ';');
		//cout << s << endl;

		getline(stream, U, ';');
		//cout << U << endl;

		getline(stream, Mia, ';');
		//cout << Mia << endl;

		getline(stream, Dia, ';');
		//cout << Dia << endl;

		getline(stream, Dib, ';');
		//cout << Dib << endl;

		getline(stream, Doa, ';');
		//cout << Doa << endl;

		getline(stream, Dob, ';');
		//cout <<Dob<< endl;

		getline(stream,Hy, ';');
		//cout <<Hy << endl;

		getline(stream, Joa, ';');
		//cout << Joa<< endl;

		getline(stream, Coa, ';');
		//cout << Coa << endl;

		getline(stream, Cob, ';');
		//cout << Cob << endl;

		getline(stream, Yta, ';');
		//cout << Yta << endl;

		getline(stream, Ytb, ';');
		//cout << Ytb << endl;

		getline(stream, Lua, ';');
		//cout << Lua << endl;

		getline(stream, Lub, '\n' );
		//cout << Lub << endl;

		Sample sample(
		    din,
		    C,
		    E,
		    c,
		    e,
		    CW,
		    V,
		    hrs,
		    VS,
		    hrB,
		    K,
		    k,
		    Kpa,
		    Kpb,
		    Jsa,
		    Jsb,
		    Jka,
		    Jkb,
		    Fya,
		    Fyb,
		    M,
		    N,
		    S,
		    s,
		    U,
		    Mia,
		    Dia,
		    Dib,
		    Doa,
		    Dob,
		    Hy,
		    Joa,
		    Coa,
		    Cob,
		    Yta,
		    Ytb,
		    Lua,
		    Lub
		);

		samples.push_back(sample);
		//cout << "Count " << count << endl;
		//count++;

	}
	return true;
}

void findUvariants(vector<Sample>& target) {
	bool flag = true;
	cout << "U-  and U variants";
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getUvars() != "+") {
			flag = false;
			target[i].setPrintFlag();
			cout << endl;
			plateLocation(i+3);
			cout <<"  " <<target[i].printDIN() << endl;
		}

	}
	if (flag == true) {
		cout << endl << "NOT FOUND" << endl;
	}

}

void getJsbNeg(vector<Sample>& target) {
	bool flag = true;
	cout << "Jsb-";
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getJsbNeg() == "0") {
			flag = false;
			target[i].setPrintFlag();
			cout<<endl;
			plateLocation(i+3);
			cout <<"  " <<target[i].printDIN() << endl;
		}

	}
	if (flag == true) {
		cout << endl << "NOT FOUND" << endl;
	}

}

void getKpbNeg(vector<Sample>& target) {
	bool flag = true;
	cout << "Kpb-" ;
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getKpbNeg() == "0") {
			flag = false;
			target[i].setPrintFlag();
			cout << endl;
			plateLocation(i+3);
			cout << "    " <<target[i].printDIN() << endl;
		}

	}
	if (flag == true) {
		cout << endl << "NOT FOUND" << endl;
	}

}

void getDaposbnegJoaneg(vector<Sample>& target) {
	bool flag = true;
	cout << "Do(a+b-) and Joa-";
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getDoa() == "+" && target[i].getDob() == "0" && target[i].getJoa() == "0") {
			flag = false;
			target[i].setPrintFlag();
			cout << endl;
			plateLocation(i+3);
			cout << "    " <<target[i].printDIN() << endl;
		}

	}
	if (flag == true) {
		cout << " NOT FOUND" << endl;
	}

}

void getkNeg(vector<Sample>& target) {
	bool flag = true;
	cout << "k-";
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getk() == "0") {
			flag = false;
			target[i].setPrintFlag();
			plateLocation(i+3);
			cout << endl << "    " <<target[i].printDIN() << endl;
		}

	}
	if (flag == true) {
		cout << endl << " NOT FOUND" << endl;
	}

}

void getJkaNegJkbNeg(vector<Sample>& target) {
	bool flag = true;
	cout << "Jka-  and Jkb- ";
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getJka() == "0" && target[i].getJkb() == "0" ) {
			flag = false;
			target[i].setPrintFlag();
			plateLocation(i+3);
			cout <<endl << "    " <<target[i].printDIN() << endl;
		}

	}
	if (flag == true) {
		cout << endl << "NOT FOUND" << endl;
	}

}

void getYtaNeg(vector<Sample>& target) {
	bool flag = true;
	cout << "Yta-";
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getYta() == "0" ) {
			flag = false;
			target[i].setPrintFlag();
			plateLocation(i+3);
			cout <<endl << "    " <<target[i].printDIN() << endl;
		}

	}
	if (flag == true) {
		cout << endl << " NOT FOUND" << endl;
	}

}

void getLubNeg(vector<Sample>& target) {
	bool flag = true;
	cout << "Lub-";
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getLub() == "0" ) {
			flag = false;
			target[i].setPrintFlag();
			plateLocation(i+3);
			cout << "    " <<target[i].printDIN() << endl;
		}

	}
	if (flag == true) {
		cout << " NOT FOUND" << endl;
	}

}

void getCnegEnegKnegDuffyabneg(vector<Sample>& target) {
	bool flag = true;
	cout << "C- E- K- Fy(a-b-)   *****Needs to be RhD negative*****" << endl;
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getC() == "0" && target[i].getE() == "0" && target[i].getK() == "0" && target[i].getFya() == "0" && target[i].getFyb() == "0") {
			flag = false;
			target[i].setPrintFlag();
			cout << count << ".  ";
			plateLocation(i+3);
			cout <<" " <<target[i].printDIN();
			if((target[i].getS() == "0" or target[i].get_s() == "0") && (target[i].getJka() == "0" or target[i].getJkb() == "0")){
			    cout << " If D+ qualifies for C -E- K- (Fya- or Fyb-) and (Jka- or Jkb-) and (S- or s-)" << endl;
			}
			else{cout << endl;}
			
			count++;
		}

	}
	if (flag == true) {
		cout << " NOT FOUND" << endl;
	}

}

void getCnegenegKnegDuffyabneg(vector<Sample>& target) {
	bool flag = true;
	cout << "C- e- K- Fy(a-b-)" << endl;
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getC() == "0" && target[i].gete() == "0" && target[i].getK() == "0" && target[i].getFya() == "0" && target[i].getFyb() == "0") {
			flag = false;
			target[i].setPrintFlag();
			cout << count << ".  ";
			plateLocation(i+3);
			cout << " " << target[i].printDIN() << endl;
			count++;
		}

	}
	if (flag == true) {
		cout << " NOT FOUND" << endl;
	}
}

void getCnegEnegKnegDuffyaorbnegJkaorbnegandSors(vector<Sample>& target) {
	bool flag = true;
	cout << "C -E- K- (Fya- or Fyb-) and (Jka- or Jkb-) and (S- or s-) " << endl;
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getC() == "0" && target[i].getE() == "0" && target[i].getK() == "0" && (target[i].getFya() == "0" or target[i].getFyb() == "0") && (target[i].getJka() == "0" or target[i].getJkb() == "0") && (target[i].getS() == "0" or target[i].get_s()== "0")) {
			flag = false;
			//target[i].setPrintFlag(); not needed..if allowed will call all printouts as repeats
			cout << count << ".  ";
			plateLocation(i+3);
			cout <<" " <<target[i].printDIN();
			if(target[i].getPrintStatus()) {
				cout <<"    repeat" << endl;
			}
			else {
				cout<< endl;
			}
			count++;
		}

	}
	if (flag == true) {
		cout << " NOT FOUND" << endl;
	}


}

void getCnegcposEposeneg(vector<Sample>& target) {
	bool flag = true;
	cout << "C- c+ E+ e-    *****Needs to be RhD negative*****" << endl;
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getC() == "0" && target[i].get_c() == "+" && target[i].getE() == "+" && target[i].gete() == "0" ) {
			flag = false;
			target[i].setPrintFlag();
			cout << count << ".  ";
			plateLocation(i+3);
			cout <<" " <<target[i].printDIN() << endl;
			count++;
		}

	}
	if (flag == true) {
		cout << " NOT FOUND" << endl;
	}


}

void getCposcnegEnegepos(vector<Sample>& target) {
	bool flag = true;
	cout << "C+ c- E- e+    *****Needs to be RhD negative*****" << endl;
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getC() == "+" && target[i].get_c() == "0" && target[i].getE() == "0" && target[i].gete() == "+" ) {
			flag = false;
			target[i].setPrintFlag();
			cout << count << ".  ";
			plateLocation(i+3);
			cout <<" " <<target[i].printDIN() << endl;
			count++;
		}

	}
	if (flag == true) {
		cout << " NOT FOUND" << endl;
	}


}

void getCposcnegEposeneg(vector<Sample>& target) {
	bool flag = true;
	cout << "C+ c- E+ e-" << endl;
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getC() == "+" && target[i].get_c() == "0" && target[i].getE() == "+" && target[i].gete() == "0" ) {
			flag = false;
			target[i].setPrintFlag();
			cout << count << ".  ";
			plateLocation(i+3);
			cout <<" " <<target[i].printDIN() << endl;
			count++;
		}

	}
	if (flag == true) {
		cout << " NOT FOUND" << endl;
	}


}





int main()
{

	cout << "Rare Donor Search\n" << endl;



	bool startFlag = loadFiles("./060525A.txt");
	if(startFlag == false){return 1;}
	findUvariants(samples);
	cout<<endl;
	getJsbNeg(samples);
	cout<<endl;
	getKpbNeg(samples);
	cout<<endl;
	getDaposbnegJoaneg(samples);
	cout<<endl;
	getkNeg(samples);
	cout<<endl;
	getJkaNegJkbNeg(samples);
	cout<<endl;
	getYtaNeg(samples);
	cout<<endl;
	getLubNeg(samples);
	cout<<endl;
	getCnegEnegKnegDuffyabneg(samples);
	cout<<endl;
	getCnegenegKnegDuffyabneg(samples);
	cout<<endl;
	getCnegEnegKnegDuffyaorbnegJkaorbnegandSors(samples);
	cout<<endl;
	getCnegcposEposeneg(samples);
	cout<<endl;
	getCposcnegEnegepos(samples);
	cout<<endl;
	getCposcnegEposeneg(samples);


	return 0;
}
