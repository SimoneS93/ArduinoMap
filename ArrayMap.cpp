#ifndef _MAP_ARRAYMAP_CPP_
#define _MAP_ARRAYMAP_CPP_

#include "ArrayMap.h"


/**
 *
 */
template<typename K, typename V>    
bool ArrayMap<K, V>::put(K key, V* value) {
    MapItem<K, V> item;
    uint8_t index = has(key) ? find(key) - 1 : it++;

    if (index > ARRAYMAP_SIZE) {
        return false;
    }
    
    item.key = key;
    item.value = value;
    items[index] = item;

    return true;
}


/**
 *
 */
template<typename K, typename V>   
V* ArrayMap<K, V>::get(K key) {
    if (has(key)) {
        return items[find(key) - 1].value;
      }

      return NULL;
}

/**
 *
 */
template<typename K, typename V>   
bool ArrayMap<K, V>::has(K key) {
    return find(key) > 0;
}

/**
 *
 */
template<typename K, typename V>   
uint8_t ArrayMap<K, V>::find(K key) {
    for (uint8_t i = 0; i < it; i++) {
        if (items[i].key == key)
            return i+1;
        }

    return 0;
}

#endif