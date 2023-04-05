#include<iostream>
#include<string>

std::string spaces_str(std::string str);
bool is_spam(std::string msg);

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// Задача 1. Пробелы в строке.
	/*std::cout << "Задача 1.\nВведите строку : ";
	std::string str1;
	std::getline(std::cin, str1);
	std::cout << spaces_str(str1) << "\n\n";*/

	// Задача 2. Проверка на спам.
	/*std::cout << "Задача 2.\nВведите строку : ";
	std::string str2;
	std::getline(std::cin, str2);
	if (is_spam(str2))
		std::cout << "Есть спам.\n";
	else
		std::cout << "Спама не обнаружено.\n";*/

		// Задача 3. Разбивка URL.
	std::string URL = "http://vk.com/super_user/photos";
	std::cout << "Задача 3.\nАдрес сайта :\n" << URL << "\n\n";
	int domen_index = URL.find("://") + 3;
	int path_index = URL.find('/', domen_index) + 1;
	std::string path = URL.substr(path_index);
	std::string domen = URL.substr(domen_index, path_index - 1 - domen_index);
	std::string protocol = URL.substr(0, domen_index - 3);
	std::cout << "Протокол : " << protocol << '\n';
	std::cout << "Домен :    " << domen << '\n';
	std::cout << "Путь :     " << path << "\n\n";



	return 0;
}


std::string spaces_str(std::string str) {
	std::string result;
	for (int i = 0; i < str.length(); i++) {
		result += str[i];
		result += " ";
		if (i == str.length() - 1)
			result += " ";
		//result = result + str[i] + " ";  Вот это тоже работает)))
	}
	return result;
}
bool is_spam(std::string msg) {
	for (int i = 0; i < msg.length(); i++)
		msg[i] = std::tolower(msg[i]);
	const int spams_number = 3;
	std::string spams[spams_number]{
		"100% free",
		"sales increase",
		"only today"
	};
	for (int i = 0; i < spams_number; i++)
		if (msg.find(spams[i]) < msg.length())
			return true;
	return false;
}