# include "Serializer.hpp" 

int main()
{
	Data data;
	data.num = 42;
	std::cout << "Data address: " << &data << std::endl;
	std::cout << "Data content: " << data.num << std::endl;

	uintptr_t dir;

	dir = Serializer::serialize(&data);
	std::cout << "Data addr number: " << dir << std::endl;

	Data *check;
	check = Serializer::deserialize(dir);
	std::cout << "Check ptr address: " << check << std::endl;
	std::cout << "Chech ptr contect: " << check->num << std::endl;
	
	return (0);
}