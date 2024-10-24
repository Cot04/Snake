#pragma once
#include <iostream>
using namespace std;

class Foco
{
private:
    bool encendido;
public:
    Foco() {}
    ~Foco() {}
    void Encender (){
        this -> encendido = true;
    }
    void Apagar (){
        this -> encendido = false;
    }
    void Inprimir(){
        if (this->encendido){
            cout<<"O";    
        }
        else{
            cout<<".";
        }
        
    }
};