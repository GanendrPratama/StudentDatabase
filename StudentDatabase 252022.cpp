//Student Database Program 2.0 by Ganendra Pratama
#include <iostream>
#include <fstream>
#include <string>

class Student
{
//Data that would be saved
private:
    int studentID;
    std::string name;
    float subjectA;
    float subjectB;

public:
    Student() 
    {

    }

    Student(
        int studentID,
        std::string name,
        float subjectA,
        float subjectB
    )
    {
        this->studentID = studentID;
        this->name = name;
        this->subjectA = subjectA;
        this->subjectB = subjectB;
    }

	//The function to save the data into DATA.txt
    void SaveData()
    {	
		//Data is saved inside DATA.txt
        std::ofstream MyFile("DATA.txt",std::ios::ate | std::ios::in);

		//Newer data will be written underneath the older data

        MyFile << "Student ID: " << this->studentID << "\n";
        MyFile << "Student name: " << this->name << "\n";
        MyFile << "Subject A score: " << this->subjectA << "\n";
        MyFile << "Subject B score: " << this->subjectB << "\n";

        MyFile.close();
    }

	//function to show the data
    void showData()
    {
        std::ifstream ReadFile;

        std::string data;
		int length = 0;

        ReadFile.open("DATA.txt"); //Opening DATA.txt

        if(ReadFile.is_open())
        {   
            while (std::getline(ReadFile, data))
            {	
                std::cout << data << "\n";
				length++;
            }
			if (length < 1)
			{
				std::cout << "There is no data\n";
			}
        ReadFile.close();
        }
    }


    void GetData()
    {
        std::cout << "Student Number = " << studentID << "\n";
        std::cout << "Student Name = " << name << "\n";
        std::cout << "Subject A score = " << subjectA << "\n";
        std::cout << "Subject B score = " << subjectB << "\n";
    }
};

int main()
{
    Student students[50];//You can enter data of students up to 50 times

    int studentNumber = 0;

    int menuInput;

    do 
    {	//The main menu
        menuInput = 0;
        std::cout <<"Welcome to student database program\n";
        std::cout <<"Please enter 1 to insert data,\n"
                    "Please enter 2 to view data,\n"
                    "Please enter 3 to exit\n";
        std::cin >> menuInput;


        switch (menuInput)
        {
            case 1:

            while (menuInput = 1)
            {   
				//Registering the data
                std::cout << "Please enter the student's ID\n";
                int studentID = -1;
				if (studentID < 0)
				{
                	std::cin >> studentID;
				}
				else
				{
					break;
				}
                std::cout << "Please enter the student name\n";
                std::string name = "";
                std::cin.ignore();
                std::getline(std::cin, name);

                std::cout << "Please enter the student's score for subject A\n";
                float subjectA = -1;
				if (subjectA <= -1)
				{
                std::cin >> subjectA;
				}
				else 
				{
					break;
				}

                std::cout << "Please enter the student's score for subject B\n";
                float subjectB = -1;
				if (subjectB <= -1)
				{
                	std::cin >> subjectB;
				}
				else 
				{
					break;
				}


                Student s
                (
                    studentID,
                    name,
                    subjectA,
                    subjectB
                );

                students[studentNumber] = s;
                students[studentNumber].SaveData();

                std::cout << "Next? (Y/N; default: N)";
                std::string next = "N";
                std::cin >> next;

                if (next == "N")
                {
                    break;
            
                }
                else
                {
                    studentNumber++;
                }
            }

            case 2:
				//View Data choice
                std::cout << "\n==========Data============\n";
                students->showData();
                std::cout << "\n";
                break;
            

            case 3:
				//Exit choice
                return 0;
            
            default:
                std::cout << "Please try again\n";
                break;
            
        }
    }
    while (menuInput != 3);
}