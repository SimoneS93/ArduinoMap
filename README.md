# ARDUINO MAP LIBRARY

This library implements a simple Map collection that let you store key/value pairs. It works with pointers, so you should feel comfortable working with them too to use the library.

## USAGE

The library first defines a Map interface, then implements it in one of the possible ways: using arrays. You can use it to store every kind of dynamic mapping you need.
A short example storing pins and their values follows:

```
#define ARRAYMAP_SIZE 20 // define max entries in the map
#include <ArrayMap.h>
#include <ArrayMap.cpp>
#define PIN_STATUS 13
#define PIN_LIGHT 12

ArrayMap<int, byte> map;

void setup() {
    byte statusValue = 0;
    byte lightValue = 255;
    
    map.put(PIN_STATUS, &statusValue);
    map.put(PIN_LIGHT, &lightValue);
}

void loop() {
    analogWrite(PIN_STATUS, *map[PIN_STATUS]);
    analogWrite(PIN_LIGHT, *map[PIN_LIGHT]);
    // update value in the map == toggle led
    map.put(PIN_STATUS, 255 - *map[PIN_STATUS]);
    delay(500);
}
```
