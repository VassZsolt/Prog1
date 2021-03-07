// Ch14_drills.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>

using namespace std;

class B1 {
public:
	virtual void vf() const { cout << "B1::vf\n"; } //származtatott osztály konstruktora felüldefiniálja
	void f() const { cout << "B1::f\n"; }
	virtual void pvf() = 0;

};

class D1 : public B1 {
	void vf() const override { cout << "D1::f\n"; }
	void f() { cout << "D1::g\n"; }
	virtual void pvf() { cout << "D1::pvf\n"; }
};

class D2 : public D1 {
	virtual void pvf() override { cout << "D2::pvf\n"; }
};

class B2 {
public:
	virtual void pvf() = 0;
	void f() { cout << "B2::f\n"; }
};
class D21 : public B2 {
	string output = "D21::pvf";
	virtual void pvf() override { cout << output << endl; }
};
class D22 : public B2 {
	int output2 = 10;
	virtual void pvf() override { cout << output2 << endl; }
	void f() { cout << "D22::f\n"; }

};

void call(B1& b)
{
	b.vf();
	b.f();
	b.pvf();
}
void call2(B2& b)
{
	b.pvf();
	b.pvf();
}
int main()
{
	//B1 b; Absztrakt osztálynak nem lehet objektuma
	D1 d1;
	D2 d2;

	//call(b);
	call(d1);
	call(d2);

	cout << "Call end\n";

	D21 d21;
	D22 d22;

	call2(d21);
	call2(d22);
	system("Pause");
}