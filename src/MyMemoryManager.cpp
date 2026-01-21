#include "stdafx.h"
#include "MyMemoryManager.h"
//---------------------------------------------------------------------------

/// Allocates memory of specified size
/**
* @param pMemory - the double pointer to variable, that will hold newly
* allocated block of memory of NULL if allocation fails.
* @param ulCountByte - memory size
* @return the result of
*/
bool ADDIN_API MyMemoryManager::AllocMemory(void** pMemory, unsigned long ulCountByte)
// ВАЖНО: память должна освобождаться тем же менеджером.
{
	if (!pMemory || ulCountByte == 0)
		return false;

	unsigned char* buffer = new unsigned char[ulCountByte];
	if (!buffer)
		return false;

	*pMemory = buffer;
	return true;
}
//----------------------------------------------------------------------------



/// Releases memory
/**
* @param pMemory - The double pointer to the memory block being released
*/
void ADDIN_API MyMemoryManager::FreeMemory(void** pMemory)
{
	if (!pMemory || !*pMemory)
		return;

	unsigned char* buffer = (unsigned char*)(*pMemory);
	delete[] buffer;
	*pMemory = 0;
}