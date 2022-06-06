#include <string>

class Card {

public:
  Card(int num);
  int getDeckPos();
  int getNumber();
  int getColorNum();
  std::string getColor();
  std::string getRule();

private:
  int deckPos;
  int number;
  int colorNum;
  std::string color;
  std::string rule;
};
