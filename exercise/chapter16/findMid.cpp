#include "findMid.h"
#include <algorithm>

template <typename T>
typename T::iterator findMid(const T& container) {
   T data(container.begin(), container.end()); 
   sort(data.begin(), data.end());
   return data.begin() + data.size() / 2;
}

