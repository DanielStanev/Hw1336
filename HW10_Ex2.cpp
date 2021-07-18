/************************************

   Author:         Daniel Stanev
   Course:         CS 1336.501
   Date:           30 Nov 2020
   Assignment:     Homework #10 Exercise #2
   Compiler:       MinGW-w64

   Description:

 *************************************/

#include <iostream>
#include <fstream>

void getkey(std::ifstream& answers, char array[])
{
   char x;
   int i = 0;
   while(answers >> x)
   {
      array[i] = x;
      i++;
   }
}

void getStudentArray(std::ifstream& answers, char array[])
{
   char x;
   int i = 0;
   while(answers >> x && i < 20)
   {
      array[i] = x;
      i++;
   }

}

void printReport(int student, int correct, const char wrong[], const char key[])
{
   int i = 0;

   std::cout << "Report for Student " << student << ":" << std::endl;
   std::cout << "---------------------" << std::endl;
   std::cout << "Missed " << (20-correct) << " out of 20 questions for " << (correct * 5) << "% correct." << std::endl;
   std::cout << "Questions missed:" << std::endl << "   ";

   while (i < 20)
   {
      if (wrong[i] != 'T')
      {
         std::cout << (i + 1) << "(" << wrong[i] << "/" << key[i] << ")";
      }
      i++;
   }
   std::cout << std::endl;

   if (correct >= 14)
      std::cout << "This student passed the exam!";
   else
      std::cout << "This student failed the exam.";
   std::cout << std::endl << std::endl;
}

int main()
{
   int correct, maxScore, minScore, maxStudent, minStudent;
   int i = 0, j = 0, k = 1, studentNum = 0;
   char key[20];
   char studentAnswers[300];
   char wrongAnswers [20];
   std::ifstream answers;
   std::ifstream studentFile;

   answers.open("CorrectAnswers.txt");

   // if CorrectAnswers.txt cannot be opened
   if (!(answers.is_open()))
   {
      std::cout << "The File CorrectAnswers.txt could not be opened.";
      return 1;
   } // end if statement

   studentFile.open("StudentAnswers.txt");

   // if StudentAnswers.txt cannot be opened
   if (!(studentFile.is_open()))
   {
      std::cout << "The File StudentAnswers.txt could not be opened.";
      answers.close();
      return 1;
   } // end if statement

   while (i < 300)
   {
      studentAnswers[i] = 'Z';
      i++;
   }

   getkey(answers, key);
   getStudentArray(studentFile, studentAnswers);

   // closes the files since they are no longer necessary
   answers.close();
   studentFile.close();

   i = 0;


   while (studentAnswers[i] != 'Z' && i < 300)
   {
      std::cout << studentNum;
      if (i == 20)
      {
         maxScore = correct;
         minScore = correct;
         maxStudent = 1;
         minStudent = 1;
      }
      if (i != 0 && k % 20 == 0)
      {
         printReport(studentNum, correct, wrongAnswers, key);
         if (correct > maxScore)
         {
            maxStudent = studentNum;
            maxScore = correct;
         }
         if (correct < minScore)
         {
            minStudent = studentNum;
            minScore = correct;
         }

      }
      if (k % 20 == 1)
      {
         studentNum++;
         correct = 20;
         while (j < 20)
         {
            wrongAnswers[j] = 'T';
            j++;
         }
       j = 0;
      }
      if (studentAnswers[i] != key[(i%20)])
      {
         wrongAnswers[(i%20)] = studentAnswers[i];
         correct--;
      }
      i++;
      k++;
   }

   std::cout << "Student " << maxStudent << " had the best grade with " << (maxScore * 5) << "%." << std::endl;
   std::cout << "Student " << minStudent << " had the worst grade with " << (minScore * 5) << "%." << std::endl;

   for (int b = 0; b < 30; b++)
   {
      std::cout << studentAnswers[b];
   }

   return 0;
}