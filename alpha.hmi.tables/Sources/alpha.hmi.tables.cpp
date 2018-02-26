// alpha.hmi.tables.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#include <Link/Alpha/Frontend/Hmi/Core>

#include "Module.h"

#ifdef _WIN32
#ifdef LIBRARY_EXPORTS
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API __declspec(dllimport)  // зачем  не понял
#endif
#else
#define LIBRARY_API
#endif //_WIN32

#ifdef __cplusplus                     // где?
extern "C"
{
#endif

	LIBRARY_API Alpha::Binbo::i_error_info *DLL_CALL_CONVENTION get_module_instance(Alpha::Binbo::i_module **pRet)
	{
		*pRet = nullptr;

		try
		{
			auto module = new TablesModule();
			module->add_ref();
			*pRet = module;
		}
		catch (...)
		{
			return BINBO_ERROR(Alpha::Binbo::ET_FAIL, "Tables module initialization failed");
		}

		return nullptr;
	}

#ifdef __cplusplus
}
#endif