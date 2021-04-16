#include <iostream>
#include <string>
#include <vector>

template<typename T>
struct S {
     S(T i = 0) : val{ i } { }

    S& operator=(const T&);

    T& get();
    const T& get() const;
    //void set(T new_t) { val = new_t; }

private:
    T val;
};

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
    val = s;
    return *this;
}

template<typename T>
T& S<T>::get()
{
    return val;
}

template<typename T>
const T& S<T>::get() const
{
    return val;
}

template<typename T>
 std::ostream& operator<<(std::ostream& os, std::vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}
 
 template<typename T>
 std::istream& operator>>(std::istream& is, std::vector<T>& v)
 {
     char ch = 0;
     is >> ch;
     if (ch != '{') {
         is.unget();
         return is;
     }

     for (T val; is >> val; ) {
         v.push_back(val);
         is >> ch;
         if (ch != ',') break;
     }

     return is;
 }

 template <typename T>
 void read_val(T& v)
 {
     std::cin >> v;
 }

int main()
{
    S<int> s_int{ 10 };
    S<char> s_char{ 'z' };
    S<double> s_double{ 10.25 };
    S<std::string> s_string{ "IRON" };
    S<std::vector<int>> s_vi{ std::vector<int>{1, 1, 2, 3, 5, 8} };

    std::cout << "S<int> : " << s_int.get() << '\n'
        << "S<char> : " << s_char.get() << '\n'
        << "S<double> : " << s_double.get() << '\n'
        << "S<string> : " << s_string.get() << '\n'
        << "S<vector<int>> : " << s_vi.get() << '\n';
    
    //S<char> s_char{ 'g' }; Error override that's why we need set
    /*s_char.set('s');
    std::cout << "S<char> : " << s_char.get() << '\n'; */
    
    std::cout << "Integer: ";
    int ii;
    read_val(ii);
    S<int> s_int2{ ii };
    std::cout << "S<int> value: " << s_int2.get() << '\n';

    std::cout << "Char: ";
    char cc;
    read_val(cc);
    S<char> s_char2{ cc };
    std::cout << "S<char> value: " << s_char2.get() << '\n';

    std::cout << "Double: ";
    double dd;
    read_val(dd);
    S<double> s_double2{ dd };
    std::cout << "S<double> value: " << s_double2.get() << '\n';

    std::cout << "String: ";
    std::string ss;
    read_val(ss);
    S<std::string> s_string2{ ss };
    std::cout << "S<string> value: " << s_string2.get() << '\n';

    std::cout << "Vector<int>: (format: { val1, val2, val3 }) ";
    std::vector<int> vi2;
    read_val(vi2);
    S<std::vector<int>> svi2{ vi2 };
    std::cout << "S<vector<int>> read: " << svi2.get() << '\n';
   
    system("pause");
    }
