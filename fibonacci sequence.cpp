#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int i = 1;
	
	for (int i = 0; i < 10;  i++){
		double fibi = (pow(1.618, i) - pow(1 - 1.618, i)) / sqrt(5);
		cout << fibi << '\n';
	}
	return 0;
}

