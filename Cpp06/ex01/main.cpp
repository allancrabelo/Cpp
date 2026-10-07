#include "Serializer.hpp"

int main(void)
{
    Data data;
    data.num = 42;
    data.str = "Hello, World!";

    std::cout << "Data Pointer: " << &data << std::endl;

    uintptr_t ptr = Serializer::serialize(&data);

    std::cout << "Serialized value: " << ptr << std::endl;

    Data *deserialized = Serializer::deserialize(ptr);

    if (deserialized == &data)
    {
		std::cout << "Serialization working properly!" << std::endl;
    }
	else
    {
		std::cout << "Serialization failed!" << std::endl;
    }

	std::cout << "Number: " << deserialized->num << ", String: " << deserialized->str << std::endl;
    return (0);
}