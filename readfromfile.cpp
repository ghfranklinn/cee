#include <iostream>
#include <fstream>
#include <string>



using namespace std;

// Student Struct definition
struct Student {
	string Name;
	int Score1, Score2, Score3, Score4;
	float AvgScore;
};

Student students[3];

void ReadStudentInfo(Student *);
void CalcAverage(Student *);
void WriteAvgScore(Student *);

int main(){

	ReadStudentInfo(students);
	CalcAverage(students);
	WriteAvgScore(students);

	system("pause>0");
	return 0;
}

void ReadStudentInfo(Student *studentArray){
	string file = "StudentInfo.txt"; 

	string fname, lname; 
	int score1, score2, score3, score4, count=0; 

	fstream fileObject(file, ios::in);

	if (fileObject.is_open()){
		while(fileObject >> fname >> lname >> score1 >> score2 >> score3 >> score4){
			studentArray[count].Name = fname + " " + lname;
			studentArray[count].Score1 = score1;
			studentArray[count].Score2 = score2;
			studentArray[count].Score3 = score3;
			studentArray[count++].Score4 = score4;
		}
	} else {
		cout << "Unable to open file '" << file << "'" << endl;
	}
	fileObject.close();
	
}


void CalcAverage(Student *studentArray){
	for (int index=0; index<3; index++){
		float avg = (float) (studentArray[index].Score1 + studentArray[index].Score2 + studentArray[index].Score3 + studentArray[index].Score4) / 4;
		studentArray[index].AvgScore = avg;
	}
}


void WriteAvgScore(Student *studentArray){
	string outputFile = "AvgScoreFile.txt";
	fstream fileObject(outputFile, ios::out);
	if (fileObject.is_open()){
		for (int index=0; index < 3; index++){
				fileObject << studentArray[index].Name << " " << studentArray[index].AvgScore << "\n";
		}
	} else {
		cout << "Unable to load file '" << outputFile << "'" << endl;
	}
	fileObject.close();
}