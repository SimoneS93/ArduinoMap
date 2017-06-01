#ifndef _MAP_ARRAYMAP_H_
#define _MAP_ARRAYMAP_H_

#include "Map.h"

/**
 * Defines the max number of items of the map
 */
#ifndef ARRAYMAP_SIZE
    #define ARRAYMAP_SIZE 20
#endif


/**
 * A Map implemented using a fixed-size array
 */
template<typename K, typename V>
class ArrayMap : public MapInterface<K, V> {
    public:

        bool has(const K key);

        bool put(const K key, V* value);

        V* get(const K key);

        V* operator[] (const K key);

    private:
        /**
         * Track next available position in the array
         */
        uint8_t it = 0;

        /**
         * Array of items in the map
         */
        MapItem<K, V> items[ARRAYMAP_SIZE];

        /**
         * Get index of key in the array
         */
        uint8_t find(const K key);
};

#endif