#ifndef SINGLETON_H
#define SINGLETON_H

#include "interfaces.h"
#include"../../platform/platform.h"

namespace GameEngine {

	template <typename T>
	class ENGINE_API Singleton : INonCopyable {
	public:
		static T& Instance() {
			static T _instance;
			return _instance;
		}

	protected:
		explicit Singleton<T>() { }
	};

}

#endif // !SINGLETON_H
