#ifndef INTERFACES_H
#define INTERFACES_H

#include "../../platform/platform.h"

namespace GameEngine {
	
	class ENGINE_API INonCopyable {
	protected:
		INonCopyable() {

		}

		~INonCopyable(){

		}
	private:
		INonCopyable(const INonCopyable&) = delete;
		INonCopyable& operator=(const INonCopyable&) = delete;
	};

}

#endif // !INTERFACES_H
