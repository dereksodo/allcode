#include <iostream>
using namespace std;
// #define _FILE
int main(int argc, char const *argv[])
{
	#ifdef _FILE
		freopen("history.in","r",stdin);
		freopen("history.out","w",stdout);	
	#endif

	return 0;
}