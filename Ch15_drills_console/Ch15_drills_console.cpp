#include "std_lib_facilities.h"

class Bad_name {};
class Bad_age {};

struct Person
{
private:
	//string name;
	string f_name, s_name;
	int age;
public:
	Person()
	{
		//name = "";
		f_name = s_name = "";
		age = 0;
	}
	Person(string f_n, string s_n, int a)
	{
		vector<char> v{ ';', ':', '"', '\'', '[', ']', '*', '&', '^', '%', '$', '#', '@', '!' };
		/*name = n;
		for ( auto i : name)
		{
			if (!isalpha(i)) //ékezetes karaktereket nem kezel
			{
				throw Bad_name{};
			}
		}*/
		f_name = f_n;
		for (auto i : f_name)
		{
			if (!isalpha(i)) //ékezetes karaktereket nem kezel
			{
				throw Bad_name{};
			}
		}
		s_name = s_n;
		for (auto i : s_name)
		{
			if (!isalpha(i)) //ékezetes karaktereket nem kezel
			{
				throw Bad_name{};
			}
		}
		age = a;
		if ((a < 0) || (a > 150))
		{
			throw Bad_age{};
		}
	}
	friend ostream& operator<<(ostream& output, const Person& P) {
		//output << "Name: " << P.name << " Age: " << P.age << endl;
		output << "First name: " << P.f_name << endl
			<< "Second name: " << P.s_name << endl
			<< "Age: " << P.age << endl;
		return output;
	}
	friend istream& operator>>(istream& input, Person& P) {
		//string n;
		string f_n, s_n;
		int a;
		input >> P.f_name >> P.s_name >> P.age;
		//n = P.name;
		f_n = P.f_name;
		s_n = P.s_name;
		a = P.age;
		//Person p(n, a);
		Person(f_n, s_n, a);
		return input;
	}

};

int main()
{

	try {
		/*
			Person Person1;
			Person1.Name="Goofy";
			Person1.Age=63;
			cout<<Person1.Name<<" "<<Person1.Age<<endl;

			Person Person2;
			cin >> Person2.Name>>Person2.Age;
			cout << Person2.Name << " " << Person2.Age << endl;
		*/

		Person p;
		cin >> p;
		cout << p;


		/*	vector<Person> people;
			for (int i = 0; i < 5;i++)
			{
				cin >> p;
				people.push_back(p);
			}

			for (int i = 0; i < 5;i++)
			{
				cout << people[i];
			}
		*/
	}

	catch (Bad_age)
	{
		cout << "Invalid age! (0-150)" << endl;
	}
	catch (Bad_name)
	{
		cout << "Invalid name!" << endl;
	}


	system("pause");
}
