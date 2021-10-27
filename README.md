# cLinkedList - A simple linked list manager for C/C++ 
This is a simple linked list manager for C that I've been using for a long while now. It may not be as optimized as Boost's libraries for linked lists, but it is very simple to use and has been tested rigorously.

This library allows you to dynamically create and manage doubly linked lists of elements that already exist in memory using pointers. This means that the actual data is untouched by this library which essentially manages a linked list of pointers to data.

## Supported platforms and binaries
In addition to the source, you can download `cLinkedList` as a precompiled library. It's currently *only available as a static library for Windows (WIN32, x86)*, but I will soon make a DLL available too.

At some point, I will also build shared and static libraries for 64-bit PC Linux.

## Supported functions
### 1. Linked list creation functions
- Create and ***initialize*** a linked list in dynamic memory.
- ***Insert a data item AFTER*** an existing linked list element.
- ***Insert a data item BEFORE*** an existing linked list element.
- ***Append a data item*** to the end of a linked list.
- ***Prepend a data item*** to the start of the linked list.

### 2. Linked list reading functions
- Get the ***first list element/data item*** of a linked list.
- Get the ***last list element/data item*** of a linked list.
- Find the ***next list element/data item*** to a specific element of a linked list.
- Find the ***previous list element/data item*** to a specific element of a linked list.
- ***Find the list element*** associated with a particular data item (if linked).
- ***Find the data item*** in a list if it has been linked.

### 3. Linked list status functions
- ***Get the length*** of the linked list.
- Is the linked list ***empty?***

### 4. Linked list unlinking functions
- ***Unlink a particular list element*** in a linked list.
- ***Unlink a list element pointing to specific data item*** in a linked list.
- ***Unlink all list elements*** from a linked list.

## Documentation
TBD - Doxygen auto-generated documents to be added soon.

## Licensing
This library and its source code is distributed under the [Mozilla Public License v2.0](https://choosealicense.com/licenses/mpl-2.0/).
