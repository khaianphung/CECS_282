//  Kyle Pamintuan
//  Prog6 - Memory Manager
//  Due Date:     December 8, 2016
//  Turn-In Date: December 8, 2016

//  MemoryManager.cpp

#include "MemoryManager.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

namespace MemoryManager
{
    // IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
    //
    // This is the only static memory that you may use, no other global variables
    // may be created, if you need to save data make it fit in MM_pool
    //
    // IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT
    
    static int usedMem;
    static int inUseMem;
    
    const int MM_POOL_SIZE = 65536;
    char MM_pool[MM_POOL_SIZE];
    
    // Displays Memory Pool
    void memView(int start, int end)
    {
        const unsigned int SHIFT = 8;
        const unsigned int MASK = 1 << SHIFT - 1;
        
        unsigned int value;    // Used to facilitate bit shifting and masking
        
        cout << "         Pool                     Unsignd  Unsigned " << endl;
        cout << "Mem Add  indx   bits   chr ASCII#  short      int    " << endl;
        cout << "-------- ---- -------- --- ------ ------- ------------" << endl;
        
        for (int i = start; i <= end; i++)
        {
            cout << (long*)(MM_pool + i) << ':';	// The actual address in hexadecimal
            cout << '[' << setw(2) << i << ']';		// The index into MM_pool
            
            value = MM_pool[i];
            cout << " ";
            for (int j = 1; j <= SHIFT; j++)	// The bit sequence for this byte (8 bits)
            {
                cout << ((value & MASK) ? '1' : '0');
                value <<= 1;
            }
            cout << " ";
            
            cout << '|' << *(char*)(MM_pool + i) << "| (";		// The ASCII character of the 8 bits (1 byte)
            cout << setw(4) << ((int)(*((unsigned char*)(MM_pool + i)))) << ")";	// The ASCII number of the character
            
            cout << " (" << setw(5) << (*(unsigned short*)(MM_pool + i)) << ")";	// The unsigned short value of 16 bits (2 bytes)
            cout << " (" << setw(10) << (*(unsigned int*)(MM_pool + i)) << ")";	// The unsigned int value of 32 bits (4 bytes)
            
            cout << endl;
        }
    }
    
    void initializeMemoryManager(void)
    {
        int freeHead = 0;	// Starting index of free memory
        int inUseHead = 2;	// Starting index of the most currently allocated memory (node)
        int usedHead = 4;	// Starting index of the most currently deallocated memory (node)
        
        int nextLink = 2;	// Offset index of the next link
        int prevLink = 4;	// Offset index for the prev link
        
        *(unsigned short*)(MM_pool + freeHead) = 6;			// Free memory starts at byte 6
        *(unsigned short*)(MM_pool + 6) = MM_POOL_SIZE - 6;	// We used 6 bytes to start with for Memory Manager
        *(unsigned short*)(MM_pool + inUseHead) = 0;		// Nothing allocated yet
        *(unsigned short*)(MM_pool + usedHead) = 0;			// Nothing deallocated yet
    }
    
    // Allocate Memory
    void* allocate(int aSize)
    {
        // Memory Manager Variables
        int freeHead = 0;	// Starting index of free memory
        int inUseHead = 2;	// Starting index of the most currently allocated memory (node)
        int usedHead = 4;	// Starting index of the most currently deallocated memory (node)
        
        // If there is enough memory left...
        if (freeMemory() > aSize)
        {
            int size = aSize + 6;   // Offset index from the node start to the size of memory allocated
            
            int old_freeHead = *(unsigned short*)(MM_pool + freeHead);			// Previous node's freeHead
            int old_inUseHead = *(unsigned short*)(MM_pool + inUseHead);		// Previous node's inUseHead
            int next_freeHead = *(unsigned short*)(MM_pool + freeHead) + size;	// New nodes's next freeHead
            
            int old_prevLink = old_inUseHead + 4;       // Offset previous node's index from the node start of the previous link
            int current_nextLink = old_freeHead + 2;	// Offset current node's index from the node start of the next link
            int current_prevLink = old_freeHead + 4;	// Offset current node's index from the node start of the previous link
            
            int current_inUseHead = *(unsigned short*)(MM_pool + inUseHead); // New inUseHead
            
            // Refresh freeHead and inUseHead
            *(unsigned short*)(MM_pool + inUseHead) = old_freeHead;		// Current inUseHead
            *(unsigned short*)(MM_pool + freeHead) = next_freeHead;		// Current freeHead
            
            // prevLink of the previous node
            if (old_freeHead != 6)
            {
                *(unsigned short*)(MM_pool + old_prevLink) = old_freeHead;
            }
            
            // nextLink and prevLink of the newly added node
            *(unsigned short*)(MM_pool + current_nextLink) = old_inUseHead;	// Current nextLink
            *(unsigned short*)(MM_pool + current_prevLink) = 0;				// Current prevLink
            
            // Storing aSize into memory
            *(unsigned short*)(MM_pool + old_freeHead) = aSize;
            
            // Amount of free memory left
            *(unsigned short*)(MM_pool + next_freeHead) = MM_POOL_SIZE - next_freeHead;
            
            // Increase the size of inUseMemory
            inUseMem += size;
            
            // Return new memory address starting after size block
            return (void*)(MM_pool + *(unsigned short*)MM_pool - aSize);
            
        }
        else
        {
            // If no memory left, let the user know
            outOfMemory();
            
            return 0;
        }
    }
    
    // Deallocate Memory
    void deallocate(void* aPointer)
    {
        
        int size = MM_pool[((char*)aPointer - MM_pool) - 6] + 6;		// Parse aPointer address into a value at that address
        int index = (char*)aPointer - MM_pool - 6;                      // Parse aPointer address into an pool index
        
        // Current deallocated node
        int current_deallocNode = index;
        
        // Memory Manager Variables
        int freeHead = 0;	// Starting index of free memory
        int inUseHead = 2;	// Starting index of the most currently allocated memory (node)
        int usedHead = 4;	// Starting index of the most currently deallocated memory (node)
        
        int nextLink = 2;	// Offset index of the next link
        int prevLink = 4;	// Offset index for the prev link
        
        // Update prevNode and nextNode
        int prevNode = *(unsigned short*)(MM_pool + current_deallocNode + nextLink);
        int nextNode = *(unsigned short*)(MM_pool + current_deallocNode + prevLink);
        
        // Update the linked nodes
        *(unsigned short*)(MM_pool + prevNode + prevLink) = nextNode;
        *(unsigned short*)(MM_pool + nextNode + nextLink) = prevNode;
        
        // Old usedHead
        int old_usedHead = *(unsigned short*)(MM_pool + usedHead);
        
        // Unlink the deallocated node
        *(unsigned short*)(MM_pool + current_deallocNode + prevLink) = 0;               //previous node is always 0 for the head node
        *(unsigned short*)(MM_pool + current_deallocNode + nextLink) = old_usedHead;	//next node is the old usedHead
        
        // Previous deleted node's previous node should be currently delete node
        *(unsigned short*)(MM_pool + old_usedHead + prevLink) = current_deallocNode;
        
        // Set the usedHead to the most recent deallocated node
        *(unsigned short*)(MM_pool + usedHead) = current_deallocNode;
        
        // Increase the size of usedMemory
        usedMem += size;
    }
    
    // Will scan the memory pool and return the total free space remaining
    int freeMemory(void)
    {
        int freeHead = 0;	// Starting index of free memory
        return MM_POOL_SIZE - *(unsigned short*)(MM_pool + freeHead);
    }
    
    // Will scan the memory pool and return the total deallocated memory
    int usedMemory(void)
    {
        return usedMem;
    }
    
    // Will scan the memory pool and return the total in use memory
    int inUseMemory(void)
    {
        int totalUsedMemory = MM_POOL_SIZE - freeMemory() - 6;
        return totalUsedMemory - usedMem;
    }
    
    // Call if no space is left for the allocation request
    void outOfMemory(void)
    {
        cout << "Not Enough Memory!" << endl;
    }
    
}
