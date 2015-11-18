#include "ReadingFile.h"

using namespace std;

//x,x,x,x,o,o,x,o,o,positive to [1,1,1,1,0,0,1,0,0]
std::vector<double> lineToVectorA(string line){
	int count = 0;
	std::vector<double> returnVector(9);

	for (int i = 0; i < 18; i = i + 2)
	{
		if (line[i] == 'x'){
			returnVector[count] = 1;
		}
		else if (line[i] == 'o'){
			returnVector[count] = 0;
		}
		else{
			returnVector[count] = -1;
		}
		count++;
	}
	return returnVector;
}
//return matrix [num. lines][9]
math::Matrix  matrixExamplesA(int totalExamples)
{
	string strInput;
	int line = 0;
	std::vector<std::vector<double>> matrixPrinc(totalExamples);

	ifstream inf("TestFile.txt");

	if (!inf)
	{
		cout << "//could not be opened for reading!\\" << endl;
		exit(1);
	}

	while (getline(inf, strInput))
	{
		//for (int j = 0; j < 9; j++)
		//{
		matrixPrinc[line] = lineToVectorA(strInput);
		//cout << matrixPrinc[line][j] << " ";
		//}
		//cout << "--------------------------" << endl;
		line++;
	}

	math::Matrix C(matrixPrinc);
	return C;
}

math::Matrix  matrixDissimilarityA(math::Matrix m1, int totalLines){
	int auxLine = 0;
	math::Matrix m2 = m1;//auxiliar para comparacao
	math::Matrix result(totalLines, totalLines);

	while (auxLine < totalLines){
		for (int i = 0; i < totalLines; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (m2(auxLine, j) != m1(i, j)){
					result(auxLine, i) += 1;
				}
			}
			cout << " " << result(auxLine, i);
		}
		cout << endl;
		auxLine++;
	}
	return result;
}