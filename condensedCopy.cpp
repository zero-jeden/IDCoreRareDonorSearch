/*
This is a utility that will sort phenotypes designated by ARDP as rare.
To use please do the following:
1. press ctrl-A to select all the text in this file
2. press ctrl-C to copy all the text in this file
3. open onlinegdb.com/online_c++_compiler#
4. delete all text in the main.cpp tab
5. press ctrl-V to paste the previously selected text into main.cpp
6. press ctrl-M to open a new tab; name it run.txt
7. open BIDs and go the completed run to be analyzed
8. select all the samples on the plate map, including controls and failed wells
9. press the csv button below the plate map and save to desired location. this will save three csv files
10. double click the phenotype file, it will open in excel
11. press ctrl-A to select all the cells in the file
12. press ctrl-C to copy every cell
13. go back to onlinegdb.com/online_c++_compiler#
14. in the run tab, press ctrl-V to paste the excel data
15. press the green Run button, this opens a window on the bottom half with sorted DINs
16. press the copy to clipboard icon that is on the input window
17. paste into text editor, such as notepad
18. print and begin searching for additional testing as required by ARDP



*/

#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include<vector>
#include<map>
using namespace std;

struct fileHeader{
    string _batchName;
    string _date;
    string _userName;
    string _softwareVersion;

};

class Sample{
    //DIN number and blood antigens
    string _din;
    string _C;
    string _E;
    string _c;
    string _e;
    string _CW;
    string _V;
    string _hrs;
    string _VS;
    string _hrB;
    string _K;
    string _k;
    string _Kpa;
    string _Kpb;
    string _Jsa;
    string _Jsb;
    string _Jka;
    string _Jkb;
    string _Fya;
    string _Fyb;
    string _M;
    string _N;
    string _S;
    string _s;
    string _U;
    string _Mia;
    string _Dia;
    string _Dib;
    string _Doa;
    string _Dob;
    string _Hy;
    string _Joa;
    string _Coa;
    string _Cob;
    string _Yta;
    string _Ytb;
    string _Lua;
    string _Lub;
    bool _printFlag = false;

public:

Sample(
    string  din ,
    string  C ,
    string  E ,
    string  c ,
    string  e ,
    string  CW ,
    string  V ,
    string  hrs ,
    string  VS ,
    string  hrB ,
    string  K ,
    string  k ,
    string  Kpa ,
    string  Kpb ,
    string  Jsa ,
    string  Jsb ,
    string  Jka ,
    string  Jkb ,
    string  Fya ,
    string  Fyb ,
    string  M ,
    string  N ,
    string  S ,
    string  s ,
    string  U ,
    string  Mia ,
    string  Dia ,
    string  Dib ,
    string  Doa ,
    string  Dob ,
    string  Hy ,
    string  Joa ,
    string  Coa ,
    string  Cob ,
    string  Yta ,
    string  Ytb ,
    string  Lua ,
    string  Lub
    ){
        _din = din;
      _C = C;
      _E = E;
      _c = c;
      _e = e;
      _CW = CW;
      _V = V;
      _hrs = hrs;
      _VS = VS;
      _hrB = hrB;
      _K = K;
      _k = k;
      _Kpa = Kpa;
      _Kpb = Kpb;
      _Jsa = Jsa;
      _Jsb = Jsb;
      _Jka = Jka;
      _Jkb = Jkb;
      _Fya = Fya;
      _Fyb = Fyb;
      _M = M;
      _N = N;
      _S = S;
      _s = s;
      _U = U;
      _Mia = Mia;
      _Dia = Dia;
      _Dib = Dib;
      _Doa = Doa;
      _Dob = Dob;
      _Hy = Hy;
      _Joa = Joa;
      _Coa = Coa;
      _Cob = Cob;
      _Yta = Yta;
      _Ytb = Ytb;
      _Lua = Lua;
      _Lub = Lub;

        
        
    };
    
    string printDIN(){
        return _din ;
    }
    
    string getJsbNeg(){
        return _Jsb;
        
        
        
    }
    
    string getUvars(){ return _U;}
    
    string getKpbNeg(){return _Kpb;}
    
    string getDoa(){return _Doa;}
    
    string getDob(){return _Dob;}
    
    string getJoa(){return _Joa;}
    
    string getk(){return _k;}
    
    string getJka(){return _Jka;}
    
    string getJkb(){return _Jkb;}
    
    string getYta(){return _Yta;}
    
    string getLub(){return _Lub;}
    
    string getC(){return _C;}
    
    string get_c(){return _c;}
    
    string getE(){return _E;}
    
    string getS(){return _S;}
    
    string get_s(){return _s;}
    
    string getK(){return _K;}
    
    string getFya(){return _Fya;}
    
    string getFyb(){return _Fyb;}
    
    string gete(){return _e;}
    
    void setPrintFlag(){_printFlag = true;}
    
    bool getPrintStatus(){return _printFlag;}
    
    
};





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
	cout << "U- and U variants" << endl;
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getUvars() != "+") {
			flag = false;
			target[i].setPrintFlag();
			//cout << endl;
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
	cout << "Do(a+b-) and Joa-" << endl;
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
		cout << "NOT FOUND" << endl;
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
		cout << endl << "NOT FOUND" << endl;
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
		cout << endl << "NOT FOUND" << endl;
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
		cout << endl << "NOT FOUND" << endl;
	}

}

void getCnegEnegKnegDuffyabneg(vector<Sample>& target) {
	bool flag = true;
	cout << "C- E- K- Fy(a-b-)   *****Needs to be RhD negative*****   Samples that are D+ and qualify for C -E- K- (Fya- or Fyb-) and (Jka- or Jkb-) and (S- or s-) will be indicated " << endl;
	for (int i = 0; i < target.size(); i ++) {
		if(!target[i].getPrintStatus() && target[i].getC() == "0" && target[i].getE() == "0" && target[i].getK() == "0" && target[i].getFya() == "0" && target[i].getFyb() == "0") {
			flag = false;
			target[i].setPrintFlag();
			cout << count << "." << setw(5);
			plateLocation(i+3);
			cout <<" " <<target[i].printDIN();
			if((target[i].getS() == "0" or target[i].get_s() == "0") && (target[i].getJka() == "0" or target[i].getJkb() == "0")){
			    cout << setw(10) << " Qualifies" << endl;
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



	bool startFlag = loadFiles("./run.txt");
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
