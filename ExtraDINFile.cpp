#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#include "ExtraDINFile.h"

Sample::Sample(
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

        
        
    }
    
  string Sample::printDIN(){
        return _din ;
    }
    
    string Sample::getJsbNeg(){
        return _Jsb;
        
        
        
    }
    
    string Sample::getUvars(){ return _U;}
    
    string Sample::getKpbNeg(){return _Kpb;}
    
    string Sample::getDoa(){return _Doa;}
    
    string Sample::getDob(){return _Dob;}
    
    string Sample::getJoa(){return _Joa;}
    
    string Sample::getk(){return _k;}
    
    string Sample::getJka(){return _Jka;}
    
    string Sample::getJkb(){return _Jkb;}
    
    string Sample::getYta(){return _Yta;}
    
    string Sample::getLub(){return _Lub;}
    
    string Sample::getC(){return _C;}
    
    string Sample::get_c(){return _c;}
    
    string Sample::getE(){return _E;}
    
    string Sample::getS(){return _S;}
    
    string Sample::get_s(){return _s;}
    
    string Sample::getK(){return _K;}
    
    string Sample::getFya(){return _Fya;}
    
    string Sample::getFyb(){return _Fyb;}
    
    string Sample::gete(){return _e;}
    
    void Sample::setPrintFlag(){_printFlag = true;}
    
    bool Sample::getPrintStatus(){return _printFlag;}
