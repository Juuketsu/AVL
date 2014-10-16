#include <iostream>
#include <list>

#include "AVL.h"

using namespace std;

int main ()
{
	AVL test (12);
	test.insert(3);
	test.insert(1);
	test.insert(16);
	test.insert(8);
	test.insert(6);
	test.insert(9);
	test.insert(14);
	test.insert(20);
	test.insert(19);
	test.insert(23);
	test.insert(4);
	test.display ();
	cout << endl;	
	return 0;
}
