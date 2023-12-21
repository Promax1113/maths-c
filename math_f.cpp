#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>

void printArgs(std::vector<std::string> _opt){
  for (int i = 0; i < _opt.size(); i++){
      std::cout << "    " << i + 1 << ". " << _opt[i] << "\n";
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
  std::string choice;


  if (argc == 1 || argv[1] == opt[0]){
    std::cout << "Available args: \n";
    printArgs(opt);
  }

  auto item = std::find(opt.begin(), opt.end(), argv[1]);
  if (item != opt.end()) {
      choice = argv[std::distance(opt.begin(), item)];
  }
  else {
    std::cout << "Invalid argument!\n";
    printArgs(opt);
  }
  
}
