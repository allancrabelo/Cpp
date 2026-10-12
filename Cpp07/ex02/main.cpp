#include "Array.hpp"

int main()
{
	// 1. Empty array
	std::cout << "--- Empty ---" << std::endl;
	Array<int> empty;
	std::cout << "size: " << empty.size() << std::endl;
	try
	{
		empty[0] = 1;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// 2. Constructor with size (all zeros)
	std::cout << "\n--- Size 5 ---" << std::endl;
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	// 3. Writing
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = (i + 1) * 10;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	// 4. Copy constructor
	std::cout << "\n--- Copy (constructor) ---" << std::endl;
	Array<int> b(a);
	b[0] = 999;
	std::cout << "a[0] = " << a[0] << " | b[0] = " << b[0] << std::endl;

	// 5. Copy assignment
	std::cout << "\n--- Copy (assignment) ---" << std::endl;
	Array<int> c;
	c = a;
	c[1] = 777;
	std::cout << "a[1] = " << a[1] << " | c[1] = " << c[1] << std::endl;

	// 6. Invalid indexes
	std::cout << "\n--- Out of bounds ---" << std::endl;
	try
	{
		a[5] = 1;
	}
	catch (std::exception &e)
	{
		std::cout << "a[5]: " << e.what() << std::endl;
	}
	try
	{
		a[-1] = 1;
	}
	catch (std::exception &e)
	{
		std::cout << "a[-1]: " << e.what() << std::endl;
	}

	// 7. Const array (needs the const operator[])
	std::cout << "\n--- Const ---" << std::endl;
	const Array<int> k(a);
	std::cout << "k[2] = " << k[2] << std::endl;

	// 8. Other types
	std::cout << "\n--- String and char ---" << std::endl;
	Array<std::string> s(3);
	s[0] = "hello";
	std::cout << "s[0] = " << s[0] << " | s[1] = '" << s[1] << "'" << std::endl;

	Array<char> ch(3);
	ch[0] = 'x';
	std::cout << "ch[0] = " << ch[0] << " | ch[1] = " << (int)ch[1] << std::endl;

	// 9. Self-assignment
	std::cout << "\n--- Self-assignment ---" << std::endl;
	a = a;
	std::cout << "a[2] = " << a[2] << std::endl;

	std::cout << "\n--- End (destructors) ---" << std::endl;
	return (0);
}