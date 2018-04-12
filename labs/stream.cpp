#include <fstream>
using std::ifstream;
using std::ofstream;
using std::endl;

int main()
{
	ifstream inStream;
	ofstream outStream;

	inStream.open("/home/dakagahnsr/Desktop/test.txt");
	outStream.open("outfile.txt");

	int first, second, third;
	inStream >> first >> second >> third;
	outStream << "This sum of the first 3\n"
	<< "numbers in /home/dakagahnsr/Desktop/test.txt\n"
	<< "is "<< (first+second+third) << endl;

	inStream.close();
	outStream.close();






	return 0;
}