//
// Excerpt from Utilities by camilo on 2025-09-17  <3ThomasBorregaardSorensen!!
//
#pragma once


/// Clamp function
template <class T> T CLAMP(const T &value, const T &min_value, const T &max_value) {
   return ((value < min_value) ? min_value : (value > max_value) ? max_value : value);
}


/// INPLACESWAP adopted from codeguru.com
template <class T> void INPLACESWAP(T& a, T& b) {
   a ^= b; b ^= a; a ^= b;
}



