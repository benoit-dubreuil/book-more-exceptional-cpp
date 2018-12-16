#include <iostream>
#include <iterator>
#include <vector>

#include "RemoveNth.h"

int main()
{
	using ContainerType = std::vector<int>;
	ContainerType data = {1, 2, 3, 2, 3, 1, 1, 3, 3, 2, 1, 1};

	std::copy(data.begin(), data.end(), std::ostream_iterator<ContainerType::value_type>(std::cout, " "));
	std::cout << std::endl;

	ContainerType::iterator removedBegin = removeNth(data.begin(), data.end(), 3);
	data.resize(std::distance(data.begin(), removedBegin));

	std::copy(data.begin(), data.end(), std::ostream_iterator<ContainerType::value_type>(std::cout, " "));

	return 0;
}