//I really dont know what the hell this question is even really asking. Not wasting more time on it.
#include <iostream>

bool getCharacter(char* cpntr);

int main (void) {

  char chars[101] = {0};
  std::string charsStr = "";
  for(int i = 1; i<100; i++) {
    getCharacter(&chars[i];
    charsStr += chars[i];
  }
  std::cout <<  charsStr<< '\n';
}

bool getCharacter(char* cpntr) {
  std::cout << "Enter a line of characters." << '\n';
  if(std::cin.eof())
  {
    return false;
  }
  std::cin >> *cpntr;
  return true;
}
