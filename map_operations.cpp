#include "associative_containers.hpp"

void map_operations()
{
	/*
	 * Associative container storing pairs <key, value> sorted by key, where the keys are unique.
	 * Implemented as red-black trees.
	 * Search, insertion and deletion of node has O(log(n)) complexity.
	 */ 
	 
	std::map<char, float> fmap;
	
	std::pair<std::map<char,float>::iterator, bool> result = fmap.insert(std::make_pair<char, float>('e',-1.19));
	std::cout<<"element with key: "<<result.first->first<<" and value "<<result.first->second<<" inserted: "<<result.second<<std::endl;
	std::map<char, float>::iterator pos = fmap.insert(--fmap.end(), std::make_pair('p',3.14));
	std::cout<<" key "<<pos->first<<" value: "<< pos->second<<std::endl;
	
	std::cout<<"indexing using char as index with at(): "<<fmap.at('e')<<" and with []: "<<fmap['p']<<std::endl; 
	
	std::cout<<"print map values once map was declared using uniform initialization"<<std::endl;
	for(std::map<char, float>::iterator it=fmap.begin(), end = fmap.end(); it!=end; ++it)
		std::cout<<" key "<<it->first<<" value: "<<it->second<<"  ";
	std::cout<<"\n";
	
	
	
	//define map using uniform initialization
	std::map<int, std::string> imap{std::make_pair<int, std::string>(0, "str0"), std::make_pair<int, std::string>(1, "str1")};
	std::cout<<"map size: "<<imap.size()<< " empty map "<<imap.empty()<<std::endl;
	//try insert another element with existing key
	std::pair<std::map<int, std::string>::iterator, bool> res = imap.emplace(1, "str11");
	std::cout<<"emplace element with an existing key succeeded: "<<res.second<<std::endl;
	if(!res.second)
		std::cout<<"existing value: "<<res.first->second<<" existing key: "<<res.first->first<<std::endl;
	else
		std::cout<<"inserted value: "<<res.first->second<<" inserted key: "<<res.first->first<<std::endl;
		
	std::map<int, std::string>::iterator pos2 = imap.emplace_hint(imap.begin(), std::make_pair<int, std::string>(7, "str7"));
	std::cout<<"inserted value: "<<pos2->second<<" inserted key: "<<pos2->first<<std::endl;
	
	
	
	std::map<int, char> icmap{{100, 'a'}};
	std::cout<<"map created using uniform initialization and without using std::pair: "<<icmap[100]<<std::endl;
	icmap.insert({{12,'s'}, {8, 'd'}});
	for(std::map<int,char>::iterator it = icmap.begin(), end = icmap.end(); it!=end; ++it)
		std::cout<<"key: "<<it->first<<" value: "<<it->second<<std::endl;
	std::cout<<"\n";
	
	std::map<int, char>::iterator it_eh = icmap.emplace_hint(++icmap.begin(), std::make_pair<int, char>(7, 'p'));
	std::cout<<"inserted key: "<<it_eh->first<<" value: "<<it_eh->second<<std::endl;
	
	std::map<int, char>::iterator it = icmap.find(100);
	std::cout<<" value with key 100: "<<it->second<<std::endl;
	
	std::pair<std::map<int, char>::iterator, std::map<int, char>::iterator > rng = icmap.equal_range(12);
	std::cout<<"lower bound: "<<rng.first->first<<" "<<rng.first->second<<" upper bound: "<<rng.second->first<<" "<<rng.second->second<<std::endl;
	
	//erase 2nd element
	icmap.erase(++icmap.begin());
	//erase element with key=100
	icmap.erase(100);
	
	for(std::map<int,char>::iterator it = icmap.begin(), end = icmap.end(); it!=end; ++it)
		std::cout<<"key: "<<it->first<<" value: "<<it->second<<std::endl;
	std::cout<<"\n";
	
	
}	
