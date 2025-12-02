# include<string.h>
# include<iostream>
# include <memory>
# include<vector>

class Function{
 private:
    std::string name;
 public:
 Function(std::string n):name(n){}
 virtual double eval(double x0)const=0;
 virtual std::unique_ptr<Function> derivative() const=0;
 virtual void print()const{
 std::cout<<"Function name :"<<name<<std::endl;
 }
  }; 

class Poly0 : public Function{
 private:
  double k0;
 public:
 Poly0(double coef):Function("Polynomial of degree 0"),k0(coef){}
 double eval(double x0)const override{
    return k0;
 }
 std::unique_ptr<Function> derivative() const override{
    return std :: make_unique<Poly0>(0);
 }
 void print()const override{
    Function::print();
    std::cout<<"p(x) = "<<k0<<std::endl;
 }
 };

class Poly1 : public Function{
    private:
     double k0,k1;
    public:
  Poly1(double coef0,double coef1):Function("Polynomial of degree 1"),k0(coef0),k1(coef1){}
  double eval(double x0)const override{
    return k0 + k1*x0;
 }
 std::unique_ptr<Function> derivative() const override{
    return std :: make_unique<Poly1>(k1);
 }
 void print()const override{
    Function::print();
    std::cout<<"p(x) = "<< k0 <<" + "<< k1 <<"*x "<<std::endl;
 }
 };
class Poly2 : public Function{
    private:
     double k0,k1,k2;
    public:
  Poly2(double coef0,double coef1,double coef2):Function("Polynomial of degree 1"),k0(coef0),k1(coef1),k2(coef2){}
  double eval(double x0)const override{
    return k0 + k1*x0 +k2*x0*x0;
 }
 std::unique_ptr<Function> derivative() const override{
    return std :: make_unique<Poly2>(k1 + 2*k2);
 }
 void print()const override{
    Function::print();
    std::cout<<"p(x) = "<< k0 <<" + "<< k1 <<"*x "<< "+"<<k2<<" *x^2"<<std::endl;
 }
  };
int main(){
 std::vector<std::unique_ptr<Function>>functions;

 functions.push_back(std::make_unique<Poly0>(6.0));
 functions.push_back(std::make_unique<Poly1>(2.0,5.0));
 functions.push_back(std::make_unique<Poly2>(10.0,3.0,2.0));

 std::cout<<"++ Content of the vector ++"<<std::endl;
 for(const auto& func:functions){
    func->print();
    std::cout<<"The value of its derivative at point x=1 is "<<func->derivative()->eval(1)<<std::endl<<std::endl;

 }
 return 0;
  }

