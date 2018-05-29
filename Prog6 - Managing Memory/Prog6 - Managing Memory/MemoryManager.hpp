//  Kyle Pamintuan
//  Prog6 - Memory Manager
//  Due Date:     December 8, 2016
//  Turn-In Date: December 8, 2016

//  MemoryManager.hpp

#ifndef MemoryManager_hpp
#define MemoryManager_hpp

#include <stdio.h>

// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
//
// DO NOT CHANGE THIS HEADER FILE
//
// IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT


namespace MemoryManager
{
    void memView(int start, int end);
    
    //---
    //--- CORE Functions, these will need to be completed by the applicant
    //---
    
    // Initialize any data needed to manage the memory pool
    void initializeMemoryManager(void);
    
    // return a pointer inside the memory pool
    // If no chunk can accommodate aSize call onOutOfMemory
    void* allocate(int aSize);
    
    // Free up a chunk previously allocated
    void deallocate(void* aPointer);
    
    //---
    //--- support routines
    //---
    
    // Will scan the memory pool and return the total free space remaining
    int freeMemory(void);
    
    // Will scan the memory pool and return the total used memory - memory that has been deallocated
    int usedMemory(void);
    
    // Will scan the memory pool and return the total in use memory - memory being curretnly used
    int inUseMemory(void);
    
    // Call if no space is left for the allocation request
    void outOfMemory(void);
    
};

#endif /* MemoryManager_hpp */
