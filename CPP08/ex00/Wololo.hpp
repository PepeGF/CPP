# include <iostream>

class Wololo
{
private:
	int num;
	std::string texto;
	int array[5];

public:
	int *patata;
	Wololo(int x);
	Wololo(int x, std::string frase);
	Wololo (Wololo const &ref);
	~Wololo();

	Wololo& operator=(Wololo const &rhs);

	void print();
};

Wololo::Wololo(int x)
{
	std::cout << "Constructor solo un entero" << std::endl;
	patata = new int[5];
	std::cout << "Malloc en constructor int" << std::endl;
	num = x;
	texto = "qué pasa!";
	for (int i = 0; i < 5; i++)
	{
		array[i] = 2*i*x - 2;
		patata[i] = array[i];
	}

}

Wololo::Wololo(Wololo const &ref)
{
	std::cout << "Constructor copia" << std::endl;
	*this = ref;
}

Wololo::Wololo(int x, std::string frase) : num(x), texto(frase)
{
	std::cout << "Constructor parametros" << std::endl;
	patata = new int[5];
	std::cout << "Malloc en constructor parametros" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		array[i] = -3 * i*x * 5;
		patata[i] = array[i];
	}
	
}

Wololo& Wololo::operator=(Wololo const &rhs)
{
    std::cout << "Operador de asignación" << std::endl;
    if (this != &rhs)
    {
        num = rhs.num;
        texto = rhs.texto;


        patata = new int[5];
	std::cout << "Malloc en operador=" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			array[i] = rhs.patata[i];
			patata[i] = rhs.patata[i];
		}
    }
    return *this;
}


Wololo::~Wololo()
{
	std::cout << "Destructor" << std::endl;
	delete[] patata;
}

void Wololo::print()
{
	std::cout << "num: " << num << " -> " << &num << std::endl;
	std::cout << "texto: " << texto << " -> " << &texto << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << i << ": " << array[i] << " -> " << &array[i] << "\n"; 
	}
	std::cout << "Patata: " << patata << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << patata[i] << ", ";
	}
	std::cout << std::endl;
}
