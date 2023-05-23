#include <fstream> 
#include <filesystem>
#include <iostream>
#include "user.hpp"
#include "message.hpp"
namespace fs = std::filesystem;

int main() {

	fstream user_file = fstream("status.txt", ios::in | ios::out);
	if (!user_file)
	{
		user_file = fstream("status.txt", ios::in | ios::out | ios::trunc);
		fs::permissions("status.txt",
			fs::perms::group_all | fs::perms::others_all,
			fs::perm_options::remove);
	}
	if (user_file) {
		User obj1("Alex", "alex_0", "qwerty");
		User obj2("Max", "max_1", "asdfgh");
		User obj3("Anthony", "anton_2", "zxcvbn");

		Message mes1("Hello", "Alex", "Max");
		Message mes2("Hi", "Max", "Alex");
		Message mes3("How are you?", "Anthony", "Alex");

		user_file << obj1 << endl;
		user_file << obj2 << endl;
		user_file << obj3 << endl;

		user_file << mes1 << endl;
		user_file << mes2 << endl;
		user_file << mes3 << endl;

		user_file.seekg(0, ios_base::beg);

		user_file >> obj1;
		user_file >> obj2;
		user_file >> obj3;

		user_file >> mes1;
		user_file >> mes2;
		user_file >> mes3;

		cout << obj1 << " : " << mes1 << endl;
		cout << obj2 << " : " << mes2 << endl;
		cout << obj3 << " : " << mes3 << endl;

	}
	else
	{
		cout << "Could not open file status.txt !" << '\n';
		return 0;

	}
}