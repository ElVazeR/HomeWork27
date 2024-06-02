#include <iostream>
#include <string>

struct Movie {
	std::string title = "Заклятие";
	int year = 2013;
	std::string genre = "Ужасы/Детектив";
	unsigned int duration = 112;
	unsigned int price = 0;
};
//Задача 1.
void print_movie(const Movie& M) {
	std::cout << "1. Название фильма: " << M.title << std::endl;
	std::cout << "2. Год выхода фильма: " << M.year << std::endl;
	std::cout << "3. Жанр фильма: " << M.genre << std::endl;
	std::cout << "4. Продолжительность фильма: " << M.duration << " минуты" << std::endl;
	std::cout << "5. Цена за диск: " << M.price << " рублей" << std::endl;
}
//Задача 2.
Movie expensive(Movie arr[], const int length) {
	int numb = 0;
	int max = arr[0].price;
	for (int i = 0; i < length; i++)
		if (arr[i].price > max) {
			max = arr[i].price;
			numb = i;
		}
	return arr[numb];
}
//Задача 3.
void update_info(Movie& M) {
	int select = 0;
	std::cout << "Что вы хотите изменить? -> ";
	std::cin >> select;
	std::cin.ignore();
	switch (select) {
	case 1: std::cout << "Новое название -> ";
		std::getline(std::cin, M.title); break;
	case 2: std::cout << "Новая дата выхода -> ";
		std::cin >> M.year; break;
	case 3: std::cout << "Новый жанр -> ";
		std::getline(std::cin, M.genre); break;
	case 4: std::cout << "Новое время -> ";
		std::cin >> M.duration; break;
	case 5: std::cout << "Новая цена -> ";
		std::cin >> M.price; break;
	}
	std::cout << "Изменения внесены!\n";
}
void movie_name(Movie arr[], const int length) {
	std::cout << "Ваши фильмы:\n";
	for (int i = 0; i < length; i++)
		std::cout << i + 1 << '.' << arr[i].title << std::endl;
}

int main() {
	setlocale(LC_ALL, "Russian");
	//Задача 1.
	std::cout << "\nЗадача 1." << std::endl;
	Movie M1;
	print_movie(M1);

	//Задача 2.
	std::cout << "\nЗадача 2." << std::endl;
	// Кристиан Бейл и Хью Джекман. Что еще надо?
	Movie M2{
		"Престиж",
		2006,
		"Триллер/Фантастика/Детектив",
		130,
		500
	};

	Movie M3{
		"Очень страшное кино 2",
		2001,
		"Ужасы/Комедия",
		83,
		300
	};

	Movie M4{
		"Не грози Южному Централу, попивая сок у себя в квартале",
		1995,
		"Комедия/Криминал",
		89,
		280
	};
	// Шикарный фильм с Кевином Спейси.
	Movie M5{
		"Планета Ка-Пэкс",
		2001,
		"Фантастика/Драма/Детектив",
		120,
		600
	};

	const int size1 = 4;
	Movie Base[size1]{ M2, M3, M4, M5 };
	print_movie(expensive(Base, size1));
	//Задача 3.
	std::cout << "\nЗадача 3." << std::endl;
	movie_name(Base, size1);
	std::cout << "Выбирете фильм -> ";
	int num;
	std::cin >> num;
	std::cin.ignore();
	switch (num) {
	case 1:print_movie(M2);
		update_info(M2); break;
	case 2:print_movie(M3);
		update_info(M3); break;
	case 3:print_movie(M4);
		update_info(M4); break;
	case 4:print_movie(M5);
		update_info(M5); break;
	};





	return 0;
}