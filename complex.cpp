#include<iostream>
using namespace std;

class complex{
  public:
  double re,im;

   complex(double r=0,double i=0):re(r),im(i){}//构造函数
  /*complex(double r=0,double i=0){
    re=r;
    im=i;
  }*/

  //complex(double r): re(r),im(0){}

   complex& operator+=(complex a){//虚数加法赋值的成员函数写法
    re+=a.re;
    im+=a.im;
    return *this;
   }

   complex& operator+=(double a){//虚数只有实部
    re+=a;
    return *this;
   }
   
   complex& operator-=(complex a){//虚数减法赋值的成员函数写法
    re-=a.re;
    im-=a.im;
    return *this;
   }

   complex& operator*=(complex a){//不可写成complex& operator* 在语义上是生成一个新的复数结果
     double r = re * a.re - im * a.im;
     double i = re * a.im + im * a.re;
     re = r; im = i;
     return *this; 
   }

   complex conj()const{//共轭
      return complex(re,-im);
   }
   
   double norm()const{//求模 应该返回整数！！！
    return re*re+im*im;
   }

   complex& operator/=(complex a){//call by value
      complex a1=a.conj();
      re= re*a1.re - im*a1.im;
      im= re*a1.im + im*a1.re;
      re=re/a.norm();
      im=im/a.norm();
      return *this; 
   }
   
   complex operator+(complex a)const{
    return complex(re+a.re,im+a.im);
   }

   complex operator+(double x)const{//注意有没有&！！
    return complex(re+x,im);
   }
  
   complex operator-()const{//一元负号 作为成员函数不需要传参
     return complex(-re,-im);
   }
   
   complex operator-(complex a)const{//二元减法
    return complex(re-a.re,im-a.im);
   }
};

complex operator+(double a,complex& b){
  return complex(a+b.re,b.im);
}

ostream& operator<<(ostream& os, const complex& c){
  os << "(" << c.re << "+" << c.im << "i)";
  return os;
}

int main(){
   complex a(1, 2), b = 3;        // 3 + 0i
    complex c = a + 2.3;           // complex + double
    complex d = 2 + b;             // double + complex
    complex e = -b - c;            // 一元- 与 二元-

    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "c = " << c << "\n";
    cout << "d = " << d << "\n";
    cout << "e = " << e << "\n";
}