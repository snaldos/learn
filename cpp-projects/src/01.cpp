// Copyright 2024 Arnaldo Lopes. All Rights Reserved.
#include <cmath>
#include <iostream>
#include <map>
#include <string>

void printGrades(std::map<std::string, int> grades) {
  for (auto element : grades) {
    // element.first represents key
    std::cout << element.first << ": ";

    // element.second represents value
    std::cout << element.second << std::endl;
  }
}

int getFinalGrade(std::map<std::string, int>* const grades) {
  bool wishToContinue = true;
  float finalGrade = 0;
  int classesNum = 0;
  std::string answer;

  while (wishToContinue) {
    std::string className;
    int classScoresNum;
    int classScore;
    float classAverage = 0;

    printGrades(*grades);

    std::cout << "Class: ";
    std::cin >> answer;
    std::cout << "Number of tests: ";
    std::cin >> classScoresNum;

    for (int i = 0; i < classScoresNum; i++) {
      std::cout << "Score " << i + 1 << ": ";
      std::cin >> classScore;

      classAverage += classScore;
    }

    classAverage = (classAverage) / classScoresNum;
    classAverage = round(classAverage);

    // insert does basically this: grades[answer] = classAverage;
    grades->insert({answer, static_cast<int>(classAverage)});

    std::cout << "----------------------------------\n";
    std::cout << "Wish to continue? (y/n)\n";
    std::cout << "----------------------------------\n";
    std::cin >> answer;

    // Works on linux terminal
    system("clear");

    if (answer.compare("y") != 0) {
      wishToContinue = false;
    }

    finalGrade += classAverage;
    classesNum++;
  }

  finalGrade = (finalGrade) / classesNum;
  finalGrade = round(finalGrade);

  return finalGrade;
}

int main() {
  std::map<std::string, int> grades;
  int finalGrade = getFinalGrade(&grades);

  std::cout << "----------------------------------\n";

  printGrades(grades);

  std::cout << "----------------------------------\n";
  std::cout << "Final Grade: " << finalGrade << "\n";
  std::cout << "----------------------------------\n";

  return 0;
}
