#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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
    );
    
    void printSample();
    string getUvars();
    string getJsbNeg();
    string getKpbNeg();
   
    string getDoa();
    string getDob();
    string getJoa();
    string getk();
    string getJka();
    string getJkb();
    
    string getYta();
    string getLub();
    string getK();
    
    
    string getC();
    string get_c();
    string getE();
    string gete();
    string getS();
    string get_s();
    string getFyb();
    string getFya();
    
    
    string printDIN();
    bool getPrintStatus();
    void setPrintFlag();
    
    
    
};
