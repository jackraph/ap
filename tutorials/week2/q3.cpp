#include <iostream>

void foo(double* pntry);

void foo2(double& refy);

int main (void) {

 //Question 3 ----------------------------
 int x = 1;
 int* pntrx = &x;
 x = 5;
 *pntrx = 10;

 double y = 1.5;

 foo(&y);
 std::cout << y << "\n";

 foo2(y);
 std::cout << y << "\n";
}

//Add 1 using a pointer.
void foo(double* pntry) {
  *pntry += 1;
}

//Add 1 using a reference.
void foo2(double& refy) {
  refy += 1;
}
