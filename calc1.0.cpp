#include <iostream>
using namespace std;



int main(){
	
	double num1;	
	std::cout << "enter your first number: ";
	cin >> num1;
	
	double num2;
	std::cout << "enter your secound number: ";
	cin >> num2;
	
	bool running = true;
	
	while (running){
		string operators;
		std::cout << "enter your operator (+,-,*,/): ";
		 cin >> operators;
		
		if (operators == "+"){
			double finalsum = num1 + num2;
			std::cout << finalsum << '\n';
			running = false;
		}
//no point in using namespace because it takes up more effort 	
		else if (operators == "-"){
			double finalsum = num1 - num2;
			std::cout << finalsum << '\n';
			running = false;
		}
	
		else if (operators == "*"){
			double finalsum = num1 * num2;
			std::cout << finalsum << '\n';
			running = false;
		}
	
		else if (operators == "/"){
			if (num2 == 0){
				std::cout << "you cant divide by 0" << '\n';
			}

			else{
				double finalsum = num1 / num2;
				std::cout << finalsum<< '\n'; 
				running = false;
			}
		}
		
		else{
			std::cout << "invalid try again \n";
		}
	}
	
	return 0;
}
