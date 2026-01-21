#pragma once
//---------------------------------------------------------------------------
// Менеджер памяти для передачи в native.
#include "types.h"
#include "IMemoryManager.h"

class MyMemoryManager : public IMemoryManager
{
private:
public:
	MyMemoryManager(){};
	~MyMemoryManager(){};
	/// Allocates memory of specified size
	/**
	* @param pMemory - the double pointer to variable, that will hold newly
	* allocated block of memory of NULL if allocation fails.
	* @param ulCountByte - memory size
	* @return the result of
	*/
	bool ADDIN_API AllocMemory(void** pMemory, unsigned long ulCountByte); //��� ������ ������ ADDIN_IPI �� __stdcall ���� ���������� ��������� _WINDOWS
	/// Releases memory
	/**
	* @param pMemory - The double pointer to the memory block being released
	*/
	void ADDIN_API FreeMemory(void** pMemory);

};