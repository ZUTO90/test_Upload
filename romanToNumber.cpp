#include <iostream>
using namespace std; 
class romanToNumber
{
	
	public:
		
		int romanToInteger(string romanNumber) {
			int countI = 0;
			int countX = 0;
			int countC = 0;
			int countM = 0;
			char nextElement;
			int size = int(romanNumber.length());
			if (0 == size) {
				return 0;
			}

			int result = 0;
			for (int index = 0; index < size; index++) {
				switch (romanNumber[index]) {
					case 'I':
						nextElement = (index + 1) < size ?  romanNumber[index + 1] :'\0';
						cout << endl << countI << endl;
						countI +=1;
						if (countI == 4)
						{
							cout << "Invalid Roman Number!!" << countI;
							exit(EXIT_SUCCESS);
						}

						
						result += 1;
						break;
					case 'V':
						result += 5;
						break;
					case 'X':
						result += 10;
						break;
					case 'L':
						result += 50;
						break;
					case 'C':
						result += 100;
						break;
					case 'D':
						result += 500;
						break;
					case 'M':
						countM += 1;
						if (countM ==4)
						{
							cout << "Invalid Roman Number!!";
							return 0;
						}
						result += 1000;
						break;
					default:
						cout << "Invalid Roman Number!!";
						exit(EXIT_SUCCESS);
				}
			}

			for (int index = 1; index < size; index++) 
			{
				if ((romanNumber[index] == 'V' || romanNumber[index] == 'X') && romanNumber[index - 1] == 'I') {
					result -= 1 + 1;
				}

				if ((romanNumber[index] == 'L' || romanNumber[index] == 'C') && romanNumber[index - 1] == 'X') {
					result -= 10 + 10;
				}

				if ((romanNumber[index] == 'D' || romanNumber[index] == 'M') && romanNumber[index - 1] == 'C') {
					result -= 100 + 100;
				}
			}
			return result;
		}
}; 


int main()  
{  
	romanToNumber Roman;
    string s = "";
	cout << "Roman " << s << " -> Integer " << Roman.romanToInteger(s) << endl;
    s = "XIX";
	cout << "Roman " << s << " -> Integer " << Roman.romanToInteger(s) << endl;  
    s = "DCCLXXXIX";
	cout << "Roman " << s << " -> Integer " << Roman.romanToInteger(s) << endl;   
    s = "MXCIX";
	cout << "Roman " << s << " -> Integer " << Roman.romanToInteger(s) << endl; 
    s = "MMMCDLVI";
	cout << "Roman " << s << " -> Integer " << Roman.romanToInteger(s) << endl;

    return 0;  
}  
