#include <iostream>

using namespace std;

class Complex
{
private:
	float real;
	float imaginary;

	float Magnitude2()
	{
		return real*real + imaginary*imaginary;
	}

	Complex()
	{
		real=0;
		imaginary=0;
	}

public:
	Complex(int real, int imaginary)
	{
		this->real = real;
		this->imaginary = imaginary;
	}

	Complex operator+(Complex& rhs)
	{
		Complex temp = *new Complex;
		temp.real = this->real + rhs.real;
		temp.imaginary = this->imaginary + rhs.imaginary;
		return temp;
	}

	Complex operator-(Complex& rhs)
	{
		Complex temp = *new Complex;
		temp.real = this->real - rhs.real;
		temp.imaginary = this->imaginary - rhs.imaginary;
		return temp;		
	}

	Complex operator*(Complex& rhs)
	{
		Complex temp = *new Complex;
		temp.real = this->real*rhs.real - this->imaginary*rhs.imaginary;
		temp.imaginary = this->real*rhs.imaginary + this->imaginary*rhs.real;
		return temp;
	}

	Complex operator/(Complex& rhs)
	{
		Complex temp = *new Complex;
		temp.real = this->real*rhs.real + this->imaginary*rhs.imaginary;
		temp.imaginary = -this->real*rhs.imaginary + this->imaginary*rhs.real;
		float mag= rhs.Magnitude2();
		temp.real = temp.real/mag;
		temp.imaginary = temp.imaginary/mag;
		return temp;
	}


	void Print()
	{
		cout << this->real <<"+";
		cout << this->imaginary << "i" << endl;
	}
};


int main()
{
	Complex a(4,5);
	Complex b(8,1);
	Complex c=a+b;
	c.Print();
	c=a-b;
	c.Print();
	c=a*b;
	c.Print();
	c=a/b;
	c.Print();
	return 0;
}