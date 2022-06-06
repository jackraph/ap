class Card {

enum class Color {Red, Orange, Yellow, Green, Blue, Indigo, Violet};

public:
  Card(int number);
  int getNumber();
  int getColorID();
  Color getColor();

private:
  int number;
  int colorID;
  Color color;
};
