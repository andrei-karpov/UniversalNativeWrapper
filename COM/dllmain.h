// dllmain.h : Declaration of module class.

class CAddInModule : public CAtlDllModuleT< CAddInModule >
{
public :
    DECLARE_LIBID(LIBID_AddInLib)
    DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ADDIN, "{6403D397-B009-4E53-8130-B9DB73FC9080}")
};

extern class CAddInModule _AtlModule;
