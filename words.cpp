#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifndef USAGE
# define USAGE "USAGE\n\t./words\tletters['_'][...] [-imin length] [-imax length]"
#endif

size_t		iMin(1);
size_t		iMax(100);
int		maxParam[2] = {0, 0};
std::string	letters;

int					check_upper(char ***av)
{
	for (int i = 1; av[0][i]; i++) {
		if (((std::string)av[0][i]) == "-imin" or ((std::string)av[0][i]) == "-imax") {
			if ((((std::string)av[0][i]) == "-imin" and maxParam[0] == 1)
			    or (((std::string)av[0][i]) == "-imax" and maxParam[1] == 1)
			    or !av[0][i + 1])
				return 0;
			i++;
			for (int j = 0; av[0][i][j]; j++)
				if (av[0][i][j] < 48 or av[0][i][j] > 57)
					return 0;
			if (((std::string)av[0][i - 1]) == "-imin") {
				iMin = std::stoi(((std::string)av[0][i]));
				maxParam[0] = 1;
			} else if (((std::string)av[0][i - 1]) == "-imax") {
				iMax = std::stoi(((std::string)av[0][i]));
				maxParam[1] = 1;
			}
		} else if (((std::string)av[0][i]).length() > 1
			   or !((av[0][i][0] > 64 and av[0][i][0] < 91)
				or (av[0][i][0] > 96 and av[0][i][0] < 123)
				or (av[0][i][0] == '_')))
			return 0;
		else if (av[0][i][0] > 96 and av[0][i][0] < 123)
			av[0][i][0] -= 32;
		if ((av[0][i][0] > 64 and av[0][i][0] < 91)
		    or av[0][i][0] == '_')
			letters += av[0][i][0];
	}
	return 1;
}

int					check_forgot(int *forgot, int j)
{
	while (forgot[j])
		if (forgot[j] == 1)
			return 0;
	return 1;
}

int					check_word(std::string word)
{
	int	forgot[letters.length()] = {0};

	word.pop_back();
	for (unsigned int i = 0; i < word.length(); i++) {
		for (unsigned int j = 0; j < letters.length(); j++) {
			if ((word[i] == letters[j] or (letters[j] == '_' and i == j)) and check_forgot(forgot, j)) {
				forgot[j] = 1;
				break;
			}
			else if (j + 1 == letters.length())
				return 0;
		}
	}
	if (word.length() >= iMin and word.length() <= iMax) {
		if (letters.find('_') == std::string::npos)
			return std::cout << word << std::endl, 0;
		else if (word.length() == letters.length()) {
			for (unsigned int i = 0; i < word.length(); i++)
				if (word[i] != letters[i] and letters[i] != '_')
					return 0;
			return std::cout << word << std::endl, 0;
		}
	}
	return 0;
}

int					main(int ac, char **av)
{
	std::ifstream			dico("dico");

	if (ac > 1 and check_upper(&av))
		if (dico) {
			for (std::string line; getline(dico, line);)
				check_word(line);
			dico.close();
		} else
			std::cout << "Dico indisponible" << std::endl;
	else
		return std::cout << USAGE << std::endl, 0;
	return 0;
}
