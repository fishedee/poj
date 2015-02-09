#include <string>
#include <vector>
#include <sstream>
std::string var_dump(int a ){
	std::stringstream ss;
	ss<< a;
	return ss.str();
}
std::string var_dump(const std::string& a ){
	return a;
}
template< typename T >
std::string var_dump( const std::vector<T>& a ){
	std::stringstream ss;
	bool isFirst = true;
	ss<<'[';
	for( typename std::vector<T>::const_iterator i = a.begin();
		i != a.end() ; ++i ){
		if( isFirst == false )
			ss<<',';
		ss<<var_dump(*i);
		isFirst = false;
	}
	ss <<']';
	return ss.str();
}