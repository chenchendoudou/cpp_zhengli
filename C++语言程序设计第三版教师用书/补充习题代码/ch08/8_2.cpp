//8_2.cpp
#include <iostream>  
#include <cassert>  
class zrf_Ratio
{ 
    friend std::ostream& operator<<(std::ostream&, const zrf_Ratio&);
    friend std::istream& operator>>(std::istream&, zrf_Ratio&);
    friend zrf_Ratio operator-(const zrf_Ratio&);
    friend zrf_Ratio operator+(const zrf_Ratio&, const zrf_Ratio&);
    friend zrf_Ratio operator-(const zrf_Ratio&, const zrf_Ratio&);
    friend zrf_Ratio operator*(const zrf_Ratio&, const zrf_Ratio&);
    friend zrf_Ratio operator/(const zrf_Ratio&, const zrf_Ratio&);
  public:
    zrf_Ratio(int=0,int=1);
    zrf_Ratio(const zrf_Ratio&);
    int numerator() const;
    int denominator() const;
    zrf_Ratio reciprocal() const;
    void invert();
    operator double() const;
    void print() const;
  private:
    int num;
    int den;
    void reduce();
};
std::ostream& operator<<(std::ostream& ostr, const zrf_Ratio& r)
{ return ostr << r.num << "/" << r.den;}

std::istream& operator>>(std::istream& istr, zrf_Ratio& r)
{ istr >> r.num;  istr.ignore(1);  istr >> r.den;
  r.reduce();  return istr;
}

zrf_Ratio operator-(const zrf_Ratio& x){ zrf_Ratio y(-x.num, x.den);  return y;}

zrf_Ratio operator-(const zrf_Ratio& r1, const zrf_Ratio& r2)
{ zrf_Ratio r(r1.num*r2.den-r2.num*r1.den,r1.den*r2.den);  return r;}

zrf_Ratio operator+(const zrf_Ratio& r1, const zrf_Ratio& r2)
{ zrf_Ratio r(r1.num*r2.den+r2.num*r1.den,r1.den*r2.den);  return r;}

zrf_Ratio operator*(const zrf_Ratio& r1, const zrf_Ratio& r2)
{ zrf_Ratio r(r1.num*r2.num,r1.den*r2.den);  return r;}

zrf_Ratio operator/(const zrf_Ratio& r1, const zrf_Ratio& r2)
{ zrf_Ratio r(r1.num*r2.den,r1.den*r2.num);  return r;}

//公有成员函数:
zrf_Ratio::zrf_Ratio(int num, int den) : num(num), den(den){ reduce();}

zrf_Ratio::zrf_Ratio(const zrf_Ratio& r) : num(r.num), den(r.den){}

int zrf_Ratio::numerator() const{ return num;}

int zrf_Ratio::denominator() const{ return den;}

zrf_Ratio zrf_Ratio::reciprocal() const{ zrf_Ratio r(den,num);  r.reduce();  return r;}

void zrf_Ratio::invert(){ int temp = num;  num = den;  den = temp;  reduce();}

zrf_Ratio::operator double() const{ return double(num)/den;}

void zrf_Ratio::print() const{ std::cout << num << '/' << den;}

//私有成员函数:
void swap(int &m, int &n){	int t;  t=m;  m=n;  n=t;}

int zrf_Gcd(int m, int n)
{ if (m<n) swap(m,n);
  assert(n>=0);
  while (n>0)  { int r=m%n;  m = n;  n = r;  }
  return m;
}

void zrf_Ratio::reduce()
{ if (num == 0 || den == 0)  { num = 0;  den = 1;  return;  }
  if (den < 0)  { den *= -1;  num *= -1;  }
  if (num == 1) return;
  int sgn = (num<0?-1:1);
  int g = zrf_Gcd(sgn*num,den);
  num /= g;  den /= g;
}

int main()
{
	zrf_Ratio zrf(1,7),ssh(26,65);
	std::cout<<"zrf is:"<<zrf<<"; ssh is:"<<ssh<<'\n' ;
	std::cout<<"-zrf is:"<<-zrf;
	std::cout<<"\n(zrf-ssh) is:"<<(zrf-ssh);
	std::cout<<"\n(zrf+ssh) is:"<<(zrf+ssh) ;
	std::cout<<"\n(zrf*ssh) is:"<<(zrf*ssh) ;
	std::cout<<"\n(zrf/ssh) is:"<<(zrf/ssh) ;
	return 0;
}

/*
运行结果：
zrf is:1/7; ssh is:2/5
-zrf is:-1/7
(zrf-ssh) is:-9/35
(zrf+ssh) is:19/35
(zrf*ssh) is:2/35
(zrf/ssh) is:5/14
*/