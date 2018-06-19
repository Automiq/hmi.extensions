#pragma once

#include <OpcFoundation\opc_ae.h>
#include <alpha.hmi.opc\Sources\alpha.hmi.opc\Interface.h>
#include <wtypes.h>
#include <boost/thread/mutex.hpp>
#include <string>
#include <memory>
#include <boost\core\noncopyable.hpp>

class OpcAEConnection
	: public std::enable_shared_from_this<OpcAEConnection>,
	boost::noncopyable
{
	mutable boost::mutex mtx_;
	static const LPCWSTR OpcClientName;

public:

	void connection(const std::string &host, const std::string &identifier)
	{
		Alpha::Hmi::Opc::OpcDestination(host, identifier);
		boost::mutex::scoped_lock lock(mtx_);

		//auto it = connections_.find(dst);

		//if (it != connections_.end())
		//{
		//	auto connectionPtr = it->second.lock();

		//	// —оединение с такими целевыми данными уже существует
		//	if (connectionPtr)
		//		return connectionPtr;
		//}

		// Ќет такого соединени€, добавим
		//auto connectionPtr = std::make_shared<OpcAEConnection>(shared_from_this(), dst);
		////connections_.emplace(dst, connectionPtr);
		//return connectionPtr;
		//return std::shared_ptr<OpcAEConnection>();
	}
};
