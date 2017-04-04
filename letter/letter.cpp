#include "../std_lib_facilities.h"

int main() {
  // data entering
  string from;
  cout << "Enter your name: ";
  cin >> from;

  string to;
  cout << "Enter the name of the person you want to write to: ";
  cin >> to;

  string friend_name;
  cout << "Enter a friend name: ";
  cin >> friend_name;

  char friend_sex{0};
  cout << "Is your friend male(m) or female(f)?: ";
  cin >> friend_sex;

  int age;
  cout << "Enter the age of the recipient: ";
  cin >> age;

  if (age <= 0) {
    simple_error("you're kidding!");
  }
  // letter
  cout << "Dear " << to << ", \n"
       << "  How are you? I am fine. I miss you.\n"
       << "Have you seen " << friend_name << " lately?\n";
  if (friend_sex == 'm') {
    cout << "If you see " << friend_name << ", please ask him to call me.\n";
  }
  if (friend_sex == 'f') {
    cout << "If you see " << friend_name << ", please ask her to call me.\n";
  }
  cout << "I hear you just had a birthday and you are " << age << " years old.\n";

  if (age < 12) {
    cout << "Next year you will be " << age + 1 << "\n";
  }
  if (age == 17) {
    cout << "Next year you will be able to vote.\n";
  }
  if (age > 70) {
    cout << "I hope you are enjoying retirement.\n";
  }
  cout << "Yours sincerely,\n\n" << from << "\n";

  return 0;
}
