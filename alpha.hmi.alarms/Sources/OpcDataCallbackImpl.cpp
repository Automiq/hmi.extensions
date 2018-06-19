#include "stdafx.h"


namespace Alpha {
namespace Hmi {
namespace Opc {


OpcDataCallbackImpl::OpcDataCallbackImpl(OpcConnection &connection)
	:	connection_(connection)
{
	AddRef();
#ifdef ALPHA_HMI_OPC_DEBUG_CONNECTION
	Alpha::Console::Out << "OpcDataCallbackImpl()\n";
#endif
}


OpcDataCallbackImpl::~OpcDataCallbackImpl()
{
#ifdef ALPHA_HMI_OPC_DEBUG_CONNECTION
	Alpha::Console::Out << "~OpcDataCallbackImpl()\n";
#endif
}


void OpcDataCallbackImpl::setup(const IOPCItemMgtPtr &opcItemMgt)
{
	IConnectionPointContainerPtr connectionPointContainer;
	_com_util::CheckError(opcItemMgt->QueryInterface(__uuidof(IConnectionPointContainer), reinterpret_cast<void **>(&connectionPointContainer)));
	_com_util::CheckError(connectionPointContainer->FindConnectionPoint(IID_IOPCDataCallback, &connectionPointForDataCallback_));
	_com_util::CheckError(connectionPointForDataCallback_->Advise(static_cast<IUnknown *>(this), &cookieForDataCallback_));
}

void OpcDataCallbackImpl::release()
{
	if (connectionPointForDataCallback_ != nullptr)
	{
		// Отписываемся от колбека
		// NB: наличие ошибок здесь нас абсолютно не интересует, так как данный метод
		// вызывается только при отключении, то есть либо при завершении приложения,
		// либо при потере связи.
		connectionPointForDataCallback_->Unadvise(cookieForDataCallback_);

		// Обнуляем внутренние структуры
		connectionPointForDataCallback_ = nullptr;
		cookieForDataCallback_ = 0;
	}
}


//////////////////////////////////////////////////////////////////////////
//
//    IOPCDataCallback
//
//////////////////////////////////////////////////////////////////////////
HRESULT STDMETHODCALLTYPE OpcDataCallbackImpl::OnDataChange(
	/* [in] */ DWORD dwTransid,
	/* [in] */ OPCHANDLE hGroup,
	/* [in] */ HRESULT hrMasterquality,
	/* [in] */ HRESULT hrMastererror,
	/* [in] */ DWORD dwCount,
	/* [size_is][in] */ OPCHANDLE __RPC_FAR *phClientItems,
	/* [size_is][in] */ VARIANT __RPC_FAR *pvValues,
	/* [size_is][in] */ WORD __RPC_FAR *pwQualities,
	/* [size_is][in] */ FILETIME __RPC_FAR *pftTimeStamps,
	/* [size_is][in] */ HRESULT __RPC_FAR *pErrors)
{
	try
	{
		return connection_.onDataChange(hGroup, dwCount, phClientItems, pvValues, pwQualities, pftTimeStamps, pErrors);
	}
	catch (...)
	{
		return S_OK;
	}
}

HRESULT STDMETHODCALLTYPE OpcDataCallbackImpl::OnReadComplete(
    /* [in] */ DWORD dwTransId,
    /* [in] */ OPCHANDLE hGroup,
    /* [in] */ HRESULT hrMasterquality,
    /* [in] */ HRESULT hrMastererror,
    /* [in] */ DWORD dwCount,
    /* [size_is][in] */ OPCHANDLE __RPC_FAR *phClientItems,
    /* [size_is][in] */ VARIANT __RPC_FAR *pvValues,
    /* [size_is][in] */ WORD __RPC_FAR *pwQualities,
    /* [size_is][in] */ FILETIME __RPC_FAR *pftTimeStamps,
    /* [size_is][in] */ HRESULT __RPC_FAR *pErrors)
{
#ifdef ALPHA_HMI_OPC_DEBUG_CONNECTION
	std::cout << "-> OnReadComplete() thread: " << this_thread_id() << "\n";
#endif
	try
	{
		return connection_.onReadComplete(dwTransId, hGroup, dwCount, phClientItems, pvValues, pwQualities, pftTimeStamps, pErrors);
	}
	catch (...)
	{
		return S_OK;
	}
}

HRESULT STDMETHODCALLTYPE OpcDataCallbackImpl::OnWriteComplete(
    /* [in] */ DWORD dwTransId,
    /* [in] */ OPCHANDLE hGroup,
    /* [in] */ HRESULT hrMastererr,
    /* [in] */ DWORD dwCount,
    /* [size_is][in] */ OPCHANDLE __RPC_FAR *pClienthandles,
    /* [size_is][in] */ HRESULT __RPC_FAR *pErrors)
{
#ifdef ALPHA_HMI_OPC_DEBUG_CONNECTION
	std::cout << "-> OnWriteComplete() thread: " << this_thread_id() << "\n";
#endif
	try
	{
		return connection_.onWriteComplete(dwTransId, hGroup, dwCount, pClienthandles, pErrors);
	}
	catch (...)
	{
		return S_OK;
	}
}

HRESULT STDMETHODCALLTYPE OpcDataCallbackImpl::OnCancelComplete(
    /* [in] */ DWORD dwTransid,
    /* [in] */ OPCHANDLE hGroup)
{
#ifdef ALPHA_HMI_OPC_DEBUG_CONNECTION
	std::cout << "-> OnCancelComplete() thread: " << this_thread_id() << "\n";
#endif
	return S_OK;
}


} // namespace Opc
} // namespace Hmi
} // namespace Alpha
