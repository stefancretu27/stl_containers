#include "sequence_containers.hpp"

void deque_operations()
{
	/*
	 * Template class that implements a double ended queue that allows for fast insertion and deletions of elements at both of its ends.
	 * The deque's size (storage) is enlarged or shrinked as needed. Expansions is cheaper when compared to std::vector as the elements are not copied in the newly allocated memory.
	 * The deque's elements are not stored contiguously as in array and vector. 
	 * Instead, it uses fixed size arrays whose starting pointers are bookkept (array of pointers to arrays) which implies double dereference for element access.
	 */
	 
	//uniform initialization
	std::deque<float> fdeq{0.0, 1.1, -2.34567, 99.01};
	//copy initialization
	std::deque<int> ideq = {0,1,2,3,4,5,6};
	
	//print deque using interator
	std::cout<<"print deque using interator"<<std::endl;
	for(std::deque<float>::iterator it = fdeq.begin(), end = fdeq.end(); it !=end; ++it)
		std::cout<<*it<<" ";
		
	//print elements using front,back, at and indexing operator
	std::cout<<std::endl<<"print elements using front,back, at and indexing operator"<<std::endl;
	std::cout<<"front: "<<fdeq.front()<<" back: "<<fdeq.back()<<" fdeq.at: "<<fdeq.at(2)<<" [] "<<fdeq[1]<<std::endl;
	
	//size, empty
	std::cout<<" is empty: "<<fdeq.empty()<<std::endl;
	std::cout<<" size: "<<fdeq.size()<<std::endl;
	
	fdeq.clear();
	std::cout<<"AFter clear(): is empty: "<<fdeq.empty()<<" size: "<<fdeq.size()<<std::endl;
	
	fdeq.push_front(-23.3);
	fdeq.emplace_front(16.7);
	fdeq.push_back(2);
	fdeq.emplace_back(99.9);
	fdeq.emplace(fdeq.begin()+2, -127);
	std::cout<<" push front, emplace front, push back, emplace back, emplace(2)"<<std::endl;
	std::copy(fdeq.begin(), fdeq.end(), std::ostream_iterator<float>(std::cout, " "));
	std::cout<<"\n";
	std::cout<<" size: "<<fdeq.size()<<std::endl;
	
	fdeq.erase(fdeq.begin()+2);
	fdeq.pop_back();
	fdeq.pop_front();
	std::cout<<"erase(it+2), pop back, pop front"<<std::endl;
	std::copy(fdeq.begin(), fdeq.end(), std::ostream_iterator<float>(std::cout, " "));
	std::cout<<"\n";
	std::cout<<" size: "<<fdeq.size()<<std::endl;
	//even if a larger iterator is provided, the newly element is allocated on the next position
	fdeq.insert(fdeq.begin()+7, 2);
	std::cout<<"insert(it+7)"<<std::endl;
	std::copy(fdeq.begin(), fdeq.end(), std::ostream_iterator<float>(std::cout, " "));
	std::cout<<"\n";
	std::cout<<"at(2) "<<fdeq.at(2)<<" size: "<<fdeq.size()<<std::endl;
	
}
