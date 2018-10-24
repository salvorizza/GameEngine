#ifndef MAP_H
#define MAP_H

#include<map>

#include"../platform/platform.h"


namespace GameEngine {
	template<typename T,typename T1>
	class Map : public std::map<T,T1> {

	};
}

#endif