#include <iostream>
#include <list>

#include "AVL.h"

using namespace std;

int main ()
{
	AVL test (5);
	test.insert(3);
	test.insert(7);
	test.insert(2);
	test.insert(4);
	test.insert(1);
	test.display();	
	return 0;
}
