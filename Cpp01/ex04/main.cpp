// Includes:
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

// Defines:
# define EXIT_SUCCESS 			0
# define EXIT_FAILURE 			1
# define NOTHING_TO_REPLACE		""

// Color:

# define GREEN					"\033[38;5;76m"
# define RESET					"\033[0m"

// Define Errors:

# define ERR_INPUT_FAILED 		"[ERROR 100] Input Error: Input failed."
# define ERR_INPUT_EOF 			"[ERROR 101] Input Error: EOF detected."
# define ERR_INPUT_EMPTY 		"[ERROR 102] Input Error: Imput can't be empty."

# define ERR_ARCHIVE_OPEN		"[ERROR 200] Open Error: Failed to open '"
# define ERR_ARCHIVE_EMPTY		"[ERROR 201] Open Error: File is empty."

# define ERR_REPLACE_NOT_FOUND	"[ERROR 300] Replace Error: Nothing to be replaced found."
# define ERR_REPLACE_EMPTY		"[ERROR 301] Replace Error: Replace Contant was empty."

# define ERR_CREATION_FAILED	"[Error 400] Creation Error: Failed to create a new archive."

static int	getInput(std::string& input)
{
	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.fail())
		{
			std::cerr << std::endl;
			std::cerr << ERR_INPUT_FAILED << std::endl;
			return (EXIT_FAILURE);
		}
		else if (std::cin.eof())
		{
			std::cerr << std::endl;
			std::cerr << ERR_INPUT_EOF << std::endl;
			return (EXIT_FAILURE);
		}
		else if (input.empty())
		{
			std::cerr << std::endl;
			std::cerr << ERR_INPUT_EMPTY << std::endl;				
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
}

std::string	getContent(std::ifstream *archive)
{
	std::stringstream content;

	content << archive->rdbuf();
	return (content.str());
}

std::string replaceContent(std::string fileContent, std::string s1, std::string s2)
{
	std::string	content = fileContent;
	std::size_t	index = content.find(s1);

	if (index == std::string::npos)
	{
		std::cerr << ERR_REPLACE_NOT_FOUND << std::endl;
		return (NOTHING_TO_REPLACE);
	}
	while (index != std::string::npos)
	{
		content.erase(index, s1.size());
		content.insert(index, s2);
		index = content.find(s1, index + s2.size());
	}
	return (content);
}

void	outFileCreator(std::string fileContent, std::string fileName)
{
	std::ofstream	outFile;
	std::string 	replaceFileName = fileName + "_replace";

	outFile.open(replaceFileName.c_str());
	if (outFile.fail())
	{
		std::cerr << ERR_CREATION_FAILED << std::endl;
		return ;
	}
	outFile << fileContent;
	outFile.close();
	std::cout << GREEN << replaceFileName << " was created!" << RESET << std::endl;
	return ;
}

int	main(void)
{
	std::string		fileName, s1, s2, fileContent;
	std::ifstream	inFile;

	std::cout << "======== REPLACER PROGRAM =========" << std::endl;
	std::cout << "File name: ";
	if (getInput(fileName))
		return (EXIT_FAILURE);
	std::cout << "String to be replaced: ";
	if (getInput(s1))
		return (EXIT_FAILURE);
	std::cout << "String that will replace: ";
	if (getInput(s2))
		return (EXIT_FAILURE);
	inFile.open(fileName.c_str());
	if (inFile.fail())
	{
		std::cerr << ERR_ARCHIVE_OPEN << fileName << "'." << std::endl;
		return (EXIT_FAILURE);
	}
	fileContent = getContent(&inFile);
	if (fileContent.empty())
	{
		std::cerr << ERR_ARCHIVE_EMPTY << std::endl;
		return (EXIT_FAILURE);
	}
	fileContent = replaceContent(fileContent, s1, s2);
	if (fileContent.empty())
	{
		std::cerr << ERR_REPLACE_EMPTY << std::endl;
		return (EXIT_FAILURE);
	}
	outFileCreator(fileContent, fileName);
	inFile.close();
	return (EXIT_SUCCESS);
}
