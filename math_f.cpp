#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <typeinfo>

template <typename T>
void sinp(const char message[], T& saveLoc){
  std::string stemp;

  std::cout << message;
  std::cin >> stemp;


  if (typeid(saveLoc) == typeid(double)){
    saveLoc = std::stod(stemp);
  }
  else if (typeid(saveLoc) == typeid(float)){
    saveLoc = std::stof(stemp);
  }
  else if (typeid(saveLoc) == typeid(int)){
    saveLoc = std::stoi(stemp);
  }
  else{
     throw std::runtime_error("Invalid var-type passed!");
  }


  
}

double calculateVector(float x, float y){
  return sqrt(pow(x, 2) + pow(y, 2));
}
double simpleInterest(float bal, double perc, float yrs){
  return bal * perc * yrs;
}

double calculatePythagorean(){
  std::string stemp;
  int _choice;
  float ccath;
  float bcath;
  float hypot;
  double res;
  sinp("1 for solving cathetus, 2 for solving hypotenuse: ", _choice);

  if (_choice == 1){
    sinp("Select a number for the hypotenuse: ", hypot);
    sinp("Select a number for a cathetus: ", ccath);
    res = sqrt(pow(ccath, 2) + pow(hypot, 2));
    return res;
  }
  else if (_choice == 2){
    sinp("Select a number for one cathetus: ", ccath);
    sinp("select another number for the other cathetus: ", bcath);
    res = sqrt(pow(ccath, 2) + pow(bcath, 2));
    return res;
  }
  throw std::runtime_error("Invalid choice!!");

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
    "-si"
  };
  std::vector<std::string> optDesc{
        "Shows this message.", 
        "Calculate vector magnitude given x and y.", 
        "Pythagorean theorem.", 
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
      choice = opt[std::distance(opt.begin(), item)];
  }
  else {
    std::cout << "Invalid argument!\n";
    printArgs(opt, optDesc);
    exit(0);
  }
  // Now any arg provided must be in the args option
  if (choice == opt[1]){
    if (argc < 3){std::cout << "Invalid args!" << "\n"; exit(0);}
    std::cout << "That vector is equal to " << calculateVector(std::stof(argv[2]), std::stof(argv[3])) << "\n";
  }
  else if (choice == opt[2]){
    std::cout << "The result to that operation is " << calculatePythagorean() << "\n";
  }
  else if (choice == opt[3]) {
    float _bal;
    double _perc;
    float _yrs;
    sinp("Input your balance: ", _bal);
    sinp("Input your percentage: ", _perc);
    sinp("Input the years: ", _yrs);
    std::cout << "The resultant interest is " << simpleInterest(_bal, _perc, _yrs) << "€\n";
  }
  


  return 0;
}
