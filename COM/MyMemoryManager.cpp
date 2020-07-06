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
//это просто замена ADDIN_IPI на __stdcall если определена константа _WINDOWS
{
	bool result = true;

	int* p = 0;
	p = new int[ulCountByte];
	*pMemory = p; //!!!!!!!!!!!!!!!!!!!ВОТ ПРАВИЛЬНОЕ единственно возможное присваивание!!!!!!!!!!!!!!!!

	return result;
}
//----------------------------------------------------------------------------



/// Releases memory
/**
* @param pMemory - The double pointer to the memory block being released
*/
void ADDIN_API MyMemoryManager::FreeMemory(void** pMemory)
{

	delete pMemory;
}