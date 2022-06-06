#include <string>

class Card {

public:
  Card(int num);
  int getNumber();
  int getColorID();
  Color getColor();
  std::string getRule();

private:
  int number;
  int colorID;
  Color color;
  std::string rule;
};

enum class Color {Red, Orange, Yellow, Green, Blue, Indigo, Violet};