# include <iostream>
# include <vector>
# include <cstdlib>



void  binary_insertion(std::vector<int> &vect, int x, int idx_max, int idx_min)
{
	int mid = (idx_max + idx_min) / 2;

	if (vect.size() == 0)
	{
		vect.insert(vect.begin(), x);
		return;
	}
	if (idx_max <= idx_min)
	{
		if (x > vect[idx_min])
			vect.insert(vect.begin() + idx_min + 1, x);
		else
			vect.insert(vect.begin() + idx_min, x);
		return;
	}
	if (x > vect[mid])
		binary_insertion(vect, x, idx_max, mid + 1);
	else
		binary_insertion(vect, x, mid - 1, idx_min);
}

void print_vector(std::vector<int> vector)
{
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

int main()
{
	
	std::vector<int> vect = {1, 3};
	int x = 4; 
	
	std::cout << "Antes:" << std::endl;
	print_vector(vect);

	binary_insertion(vect, x, vect.size() - 1, 0);
		
	std::cout << "Después:" << std::endl;
	print_vector(vect);
	
	return (0);
}