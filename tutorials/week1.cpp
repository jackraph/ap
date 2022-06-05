#include <iostream>
#include <string>
int main ( void ) {

  //Question 1 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // std::cout << "Hello World !" << std::endl;

  //Question 2 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // std::cout <<"Enter your name:" << std::endl;
  // std::string name = "";
  // std::cin >> name;
  //
  // std::cout <<"Enter your age:" << std::endl;
  // std::string age = "";
  // std::cin >> age;
  //
  // std::cout <<"Enter your height:" << std::endl;
  // std::string height = "";
  // std::cin >> height;
  //
  // std::cout <<"Your name is: " + name << std::endl;
  // std::cout <<"Your age is: " + age << std::endl;
  // std::cout <<"Your height is: " + height << std::endl;

  //Question 3 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //a)
  for(int i = 1; i <= 6; i++) {

    for(int j = 1; j <= i; j++) {

      std::cout << "*";
    }

    std::cout <<"\n";
  }
  std::cout <<"-------------------" << std::endl;

  //b)
  for(int i = 1; i <= 6; i++) {

    for(int j = 6; j >= 1; j--) {

      if(j <= i) {

        std::cout << "*";
      } else {

        std::cout << " ";
      }
    }

    std::cout <<"\n";
  }
  std::cout <<"-------------------" << std::endl;

  //c)


  return EXIT_SUCCESS ;
}
