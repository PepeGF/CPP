# include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(Serializer const & copy)
{
	(void)copy;
}

Serializer::~Serializer()
{}

Serializer& Serializer::operator=(Serializer const & rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t aux;

	aux = reinterpret_cast<uintptr_t>(ptr);
	return aux;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}

