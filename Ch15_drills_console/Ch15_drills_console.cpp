#include "std_lib_facilities.h"

class Bad_name {};
class Bad_age {};
class Bad_number_of_arguments {};

vector <string> datas;

struct Person
{
private:
	string f_name, s_name;
	int age;
public:
	Person()
	{
		string f_n = "", s_n = "";
		int a = -1;
	}
	Person(string f_n, string s_n, int a)
	{
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
		output << "First name: " << datas[0] << " " << endl
			<< "Second name: " << datas[1] << endl
			<< "Age: " << datas[2] << endl;
		return output;
	}
	friend istream& operator>>(istream& input, Person& P) {
		string n = "", all = "";


		getline(cin, all);
		for (int i = 0; i < all.length(); i++)
		{
			if ((all[i] != ' '))
			{
				n += all[i];
			}
			if (all[i] == ' ')
			{
				datas.push_back(n);
				n = "";
			}
		}
		datas.push_back(n);
		string f_n = "", s_n = "";
		int a = -1;
		if (datas.size() == 3)
		{
			f_n = datas[0];
			s_n = datas[1];
			a = stoi(datas[2]);

		}
		else
		{
			throw Bad_number_of_arguments();
		}

		Person(f_n, s_n, a);
	}
};

int main()
{

	try {
		Person p;
		cin >> p;
		cout << p;
	}

	catch (Bad_age)
	{
		cout << endl;
		cout << "Invalid age! (0-150)" << endl;
	}
	catch (Bad_name)
	{
		cout << endl;
		cout << "Invalid name!" << endl;
	}
	catch (Bad_number_of_arguments)
	{
		cout << endl;
		cout << "Invalid number of arguments!" << endl;
	}

	system("pause");
}