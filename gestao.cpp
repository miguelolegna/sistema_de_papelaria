#include <iostream>
#include <string>
using namespace std;

class produtos {       // The class
  public:             // Access specifier
    int quantidade;
    double preco;
};

int main() {
  produtos lapis;  // Create an object of MyClass

  // Access attributes and set values
  lapis.quantidade = 15;
  lapis.preco = 0.50;

  // Print values
  cout << "quantidade comprada: " << lapis.quantidade << "\n"; 
  cout << "preco individual: " << lapis.preco << "\n"; 
   cout << "preço total: " << lapis.quantidade * lapis.preco;

    if ()


  return 0;
}