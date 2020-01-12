#include "sequence_containers.hpp"

int main()
{
	//sequence containers
	std::cout<<"----------------------------array operations"<<std::endl;
	array_operations();
	std::cout<<std::endl<<"----------------------------vector operations"<<std::endl;
	vector_operations();
	std::cout<<std::endl<<"----------------------------double ended queue operations"<<std::endl;
	deque_operations();
	
	return 0;
}
