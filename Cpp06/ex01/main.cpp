#include "Data.hpp"

int main(void)
{
    Data data;
    data.str = "Hello, World!";
    data.num = 42;

    std::cout << "Original Data: " << data.str << " | " << data.num << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data: " << deserializedData->str << " | " << deserializedData->num << std::endl;

    if (deserializedData == &data) {
        std::cout << "Deserialization successful: The deserialized pointer matches the original." << std::endl;
    } 
    else {
        std::cout << "Deserialization failed: The deserialized pointer does not match the original." << std::endl;
    }

    return (0);
}