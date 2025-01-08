#include "Metaprogramming.h"
#include <vector>

using namespace std;

using int_t = int;																		// this is equivalent to typedef
template<typename X, typename Y> using pair_vector = std::vector<std::pair<X, Y>>;		// this is a template alias

// this is a variadic template. Args is called a parameter pack. It expands to a comma separated list.
template<typename... Args> struct variadic_example {};


int main()
{
	// constexpr tells the compiler that the function can be executed by the compiler and the result can be used at compile time.
	constexpr power<2, 8> result;		
	cout << result.value << endl;

	// constexpr double result2 = pow(2,8);		--> this is not valid because pow is not a constexpr function

	// using the template alias
	pair_vector<int, string> pv;
	std::pair temp = make_pair(1, "angelo");
	pv.push_back(temp);

	// using our tuple template class
	::tuple<bool, int> tuple1(false, 3);
	printf("tuple1.value = %s\r\n", tuple1.value ? "true" : "false");
	printf("tuple1.next.value = %d\r\n", tuple1.next.value);

	// tuple example #2
	::tuple<float,char,const char*> tuple2(3.14, '+', "foo");
	printf("tuple2.next.next.value = %s\r\n", tuple2.next.next.value);

	return 0;
}
