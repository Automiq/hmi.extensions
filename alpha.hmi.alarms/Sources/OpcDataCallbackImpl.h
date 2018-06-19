#pragma once


#include <boost/noncopyable.hpp>

#include "OpcPtrs.h"
#include "OpcItem.h"


namespace Alpha {
namespace Hmi {
namespace Opc {


	class OpcConnection;


	class OpcDataCallbackImpl :
		public Alpha::Com::Object,
		public IOPCDataCallback,
		boost::noncopyable
	{
	public:
		OpcDataCallbackImpl(OpcConnection &connection);
		~OpcDataCallbackImpl();

		void setup(const IOPCItemMgtPtr &opcItemMgt);
		void release();

		//////////////////////////////////////////////////////////////////////////
		//
		//	IUnknown
		//
		//////////////////////////////////////////////////////////////////////////
		ALPHA_COM_IMPLEMENT_IUNKNOWN


		//////////////////////////////////////////////////////////////////////////
		//
		//	IOPCDataCallback
		//
		//////////////////////////////////////////////////////////////////////////
		virtual HRESULT STDMETHODCALLTYPE OnDataChange(
			/* [in] */ DWORD dwTransid,
			/* [in] */ OPCHANDLE hGroup,
			/* [in] */ HRESULT hrMasterquality,
			/* [in] */ HRESULT hrMastererror,
			/* [in] */ DWORD dwCount,
			/* [size_is][in] */ OPCHANDLE __RPC_FAR *phClientItems,
			/* [size_is][in] */ VARIANT __RPC_FAR *pvValues,
			/* [size_is][in] */ WORD __RPC_FAR *pwQualities,
			/* [size_is][in] */ FILETIME __RPC_FAR *pftTimeStamps,
			/* [size_is][in] */ HRESULT __RPC_FAR *pErrors) override;

		virtual HRESULT STDMETHODCALLTYPE OnReadComplete(
			/* [in] */ DWORD dwTransid,
			/* [in] */ OPCHANDLE hGroup,
			/* [in] */ HRESULT hrMasterquality,
			/* [in] */ HRESULT hrMastererror,
			/* [in] */ DWORD dwCount,
			/* [size_is][in] */ OPCHANDLE __RPC_FAR *phClientItems,
			/* [size_is][in] */ VARIANT __RPC_FAR *pvValues,
			/* [size_is][in] */ WORD __RPC_FAR *pwQualities,
			/* [size_is][in] */ FILETIME __RPC_FAR *pftTimeStamps,
			/* [size_is][in] */ HRESULT __RPC_FAR *pErrors) override;

		virtual HRESULT STDMETHODCALLTYPE OnWriteComplete(
			/* [in] */ DWORD dwTransid,
			/* [in] */ OPCHANDLE hGroup,
			/* [in] */ HRESULT hrMastererr,
			/* [in] */ DWORD dwCount,
			/* [size_is][in] */ OPCHANDLE __RPC_FAR *pClienthandles,
			/* [size_is][in] */ HRESULT __RPC_FAR *pErrors) override;

		virtual HRESULT STDMETHODCALLTYPE OnCancelComplete(
			/* [in] */ DWORD dwTransid,
			/* [in] */ OPCHANDLE hGroup) override;

	protected:
		//virtual void OnReconnected( )
		//{
		//	Alpha::Console::Out << "OpcConnection::OnReconnected()\n";
		//}
		//
		//virtual void OnDisconnected( )
		//{
		//	Alpha::Console::Out << "OpcConnection::OnDisconnected()\n";
		//}
		//
		//virtual void OnReleaseReferences( )
		//{
		//	Alpha::Console::Out << "OpcConnection::OnReleaseReferences()\n";
		//}

		// Карта поддерживаемых интерфейсов
		ALPHA_COM_BEGIN_INTERFACE_MAP
			ALPHA_COM_PUBLISH_INTERFACE(IUnknown)
			ALPHA_COM_PUBLISH_INTERFACE(IOPCDataCallback)
		ALPHA_COM_END_INTERFACE_MAP

	private:
		// Объект соединения с OPC DA сервером
		OpcConnection &connection_;

		// Интерфейс для подписки колбека
		IConnectionPointPtr connectionPointForDataCallback_;

		// Cookie подписки
		DWORD cookieForDataCallback_;
	};


} // namespace Opc
} // namespace Hmi
} // namespace Alpha
