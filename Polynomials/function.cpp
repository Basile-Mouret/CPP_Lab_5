#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Function{
  private:
    string name;
  public:
    Function(string name){
      this->name = name;
    }
    virtual float eval(float x0) = 0;
    virtual Function* derivative()=0;
    virtual void print()=0;
};

class Poly0 : public Function{
  private:
    float k0;
  public:
    Poly0(string name, float k0):Function(name){
      this->k0 = k0;
    }
    float eval(float x0){
      return k0;
    }
    Function* derivative(){
      return new Poly0("constant", 0);
    }

    void print(){
      cout << "This function is a Polynomial of degree 0" << "\np(x)=" << k0 << endl;
    }
};

class Poly1 : public Function{
  private:
    float k0;
    float k1;
  public:
    Poly1(string name, float k0, float k1):Function(name){
      this->k0 = k0;
      this->k1 = k1;
    }
    float eval(float x0){
      return k0+k1*x0;
    }
    Function* derivative(){
      return new Poly0("constant Polynomial", k1);
    }

    void print(){
      cout << "This function is a Polynomial of degree 1" << "\n p(x)=" << k0 << "+" << k1 << ".x"<< endl;
    }
};

class Poly2 : public Function{
  private:
    float k0;
    float k1;
    float k2;
  public:
    Poly2(string name, float k0, float k1, float k2):Function(name){
      this->k0 = k0;
      this->k1 = k1;
      this->k2 = k2;
    }
    float eval(float x0){
      return k0+k1*x0+k2*x0*x0;
    }
    Function* derivative(){
      return new Poly1("Polynomial of degree 1", k1, 2*k2);
    }

    void print(){
      cout << "This function is a Polynomial of degree 2" << "\n p(x)=" << k0 << "+" << k1 << ".x"<< "+" << k2 << ".x^2"<< endl;
    }
};

int main(){
  vector<Function *> polynomials = {new Poly0("constant Polynomial",6), new Poly1("Polynomial of degree 1",2, 5), new Poly2("Polynomial of degree 2", 10, 3, 2)};
  cout << "** content of the vector **" << endl;
  for (size_t i = 0; i<polynomials.size() ; i++){
    polynomials[i]->print();
    cout << "The value of its derivative at point x=1 is " << polynomials[i]->derivative()->eval(1) <<"." << endl;
  }

  return 0;
}

