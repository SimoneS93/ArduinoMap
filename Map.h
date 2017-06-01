#ifndef _MAP_H_
#define _MAP_H_ 1

#include <Arduino.h>


/**
 * Helper struct for storing items in the Map 
 */
template<typename K, typename V>
struct MapItem {
  K key;
  V *value;
};


/**
 * Map interface
 */
template<typename K, typename V>
class MapInterface {
    public:

        /**
         * Put item into the Map.
         * Returns true on success, false on failure.
         */
        virtual bool put(const K key, V* value) = 0;

        /**
         * Read item from the Map
         */
        virtual V* get(const K key) = 0;

        /**
         * Check if key exists in the Map
         */
        virtual bool has(const K key) = 0;

        /**
         * Just syntactic sugar for the get method
         */
        virtual V* operator[] (const K key) = 0;
};


#endif