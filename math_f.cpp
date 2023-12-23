#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>

double calculateVector(float x, float y){
  return sqrt(pow(x, 2) + pow(y, 2));
}

double calculatePythagorean(){
  std::string stemp;
  int _choice;
  float ccath;
  float bcath;
  float hypot;
  double res;
  std::cout << "1 for solving cathetus, 2 for solving hypotenuse: ";
  std::cin >> stemp;
  _choice = stoi(stemp);

  if (_choice == 1){
    std::cout << "Select a number for the hypotenuse: ";
    std::cin >> stemp;
    hypot = stof(stemp);
    std::cout << "Select a number for a cathetus: ";
    std::cin >> stemp;
    ccath = stof(stemp);
    res = sqrt(pow(ccath, 2) + pow(hypot, 2));
    return res;
  }
  return NULL;

}

void printArgs(std::vector<std::string> _opt, std::vector<std::string> _optDesc){
  for (int i = 0; i < _opt.size(); i++){
      std::cout << "    " << i + 1 << ". " << _opt[i] << " -> " << _optDesc[i] << "\n";
    }
}

int main(int argc, char *argv[]) {

  std::vector<std::string> opt{
    "-h",
    "-v", 
    "-p", 
    "-vs", 
    "-si"
  };
  std::vector<std::string> optDesc{
        "Shows this message.", 
        "Calculate vector magnitude given x and y.", 
        "Pythagorean theorem.", 
        "Sum of vectors given two vectors in x1 y1 x2 y2 format.", 
        "Calculates gain in simple interest."
    };
  std::string choice;
  double result;

  if (argc == 1 || std::string(argv[1]) == opt[0]){
    std::cout << "Available args: \n";
    printArgs(opt, optDesc);
    exit(0);
  }
  // This checks if the arg provided is in the args list.
  std::vector<std::string>::iterator item = std::find(opt.begin(), opt.end(), argv[1]);
  if (item != opt.end()) {
      choice = argv[std::distance(opt.begin(), item)];
  }
  else {
    std::cout << "Invalid argument!\n";
    printArgs(opt, optDesc);
    exit(0);
  }
  // Now any arg provided must be in the args option
  if (choice == opt[1]){
    if (argc < 3){std::cout << "Invalid args!" << "\n"; exit(0);}
    result = calculateVector(std::stof(argv[2]), std::stof(argv[3]));
  }
  
  else if (choice == opt[2]){
    result = calculatePythagorean();
  }

  std::cout << "The result to that calculation is " << result << "\n";

  return 0;
}
