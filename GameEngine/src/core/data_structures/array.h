#ifndef ARRAY_H
#define ARRAY_H

#include<vector>

#include"../platform/platform.h"

namespace GameEngine {
	template<typename T>
	class ENGINE_API Array : public std::vector<T> {

	};
}

#endif