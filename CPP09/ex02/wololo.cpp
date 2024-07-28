#include <iostream>
#include <vector>
#include <algorithm>

int  binary_insertion(std::vector<int> &bigger_sort, int to_insert, int idx_max, int idx_min)
{
	int mid = (idx_max + idx_min) / 2;

	if (bigger_sort.size() == 0)
	{
		bigger_sort.insert(bigger_sort.begin(), to_insert);
		return (0);
	}
	if (idx_max <= idx_min)
	{
		if (to_insert > bigger_sort[idx_min])
		{
			bigger_sort.insert(bigger_sort.begin() + idx_min + 1, to_insert);
			return (idx_min + 1);
		}
		else
		{
			bigger_sort.insert(bigger_sort.begin() + idx_min, to_insert);
			return (idx_min);
		}
	}
	if (to_insert > bigger_sort[mid])
		return binary_insertion(bigger_sort, to_insert, idx_max, mid + 1);
	else
		return binary_insertion(bigger_sort, to_insert, mid - 1, idx_min);
}

int main() {
    std::vector<int> sq;
    int check;
    for (int i = 1; i < 3; i++)
    {
        sq.push_back(i*i);
    }
    check = binary_insertion(sq, 20000, static_cast<int>(sq.size() - 1), 0);
    std::cout << check << std::endl;
    for (size_t i = 0; i < sq.size(); i++)
    {std::cout << sq[i] << " ";}
    std::cout << std::endl;
    return 0;
}
