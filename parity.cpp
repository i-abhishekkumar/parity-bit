// C++ code to get a char and convert it to binary equivalent with parity bit (even parity 1):

#include <iostream>
#include <string>

using namespace std;

int get_parity(int number) {

  int count = 0;
  // Brain Kernigam Algorithm 
  while (number > 0) {
    number = number & (number-1);
    count++;
  }
  return count % 2;
}

string get_binary_equivalent(char character) {
  string binary_equivalent = "";
  for (int i = 7; i >= 0; i--) {
    int bit = (character >> i) & 1;
    binary_equivalent += to_string(bit);
  }
  return binary_equivalent;
}

int main() {
  char character;
  cout << "Enter a character: ";
  cin >> character;

  string binary_equivalent = get_binary_equivalent(character);

  int parity_bit = get_parity(stoi(binary_equivalent,0,2));

  if (parity_bit == 1) {
    binary_equivalent += "1";
  } else {
    binary_equivalent += "0";
  }

  cout << "Binary equivalent with parity bit (even parity 1): " << binary_equivalent << endl;

  return 0;
}
