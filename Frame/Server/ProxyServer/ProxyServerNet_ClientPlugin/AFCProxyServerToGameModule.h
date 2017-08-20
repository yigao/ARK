// -------------------------------------------------------------------------
//    @FileName			:    AFCProxyServerToGameModule.h
//    @Author           :    Ark Game Tech
//    @Date             :    2013-05-06
//    @Module           :    AFCProxyServerToGameModule
//
//     @Changed         : AFCProxyConnectObject Add HeartBeat by hahaya 2013-11-1
// -------------------------------------------------------------------------

#ifndef AFC_PROXYSERVER_TO_GAME_MODULE_H
#define AFC_PROXYSERVER_TO_GAME_MODULE_H

#include <string>
#include "SDK/Proto/AFMsgDefine.h"
#include "SDK/Core/AFCHeartBeatManager.h"
#include "SDK/Interface/AFIProxyServerToGameModule.h"
#include "SDK/Interface/AFIProxyServerNet_ServerModule.h"
#include "SDK/Interface/AFIKernelModule.h"
#include "SDK/Interface/AFIProxyLogicModule.h"
#include "SDK/Interface/AFINetServerModule.h"
#include "SDK/Interface/AFIElementModule.h"
#include "SDK/Interface/AFILogModule.h"
#include "SDK/Interface/AFIClassModule.h"
#include "SDK/Interface/AFINetClientModule.hpp"


class AFCProxyServerToGameModule : public AFIProxyServerToGameModule
{
public:

    AFCProxyServerToGameModule(AFIPluginManager* p)
    {
        pPluginManager = p;
    }

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();

    virtual bool AfterInit();
	virtual AFINetClientModule* GetClusterModule();

protected:

    void OnSocketGSEvent(  const NetEventType eEvent, const AFGUID& xClientID, const int nServerID);

    void Register(const int nServerID);

    void OnAckEnterGame(  const int nMsgID, const char* msg, const uint32_t nLen, const AFGUID& xClientID);
    void LogServerInfo(const std::string& strServerInfo);

	void Transpond(  const int nMsgID, const char* msg, const uint32_t nLen, const AFGUID& xClientID);

private:

    AFILogModule* m_pLogModule;
    AFIProxyLogicModule* m_pProxyLogicModule;
    AFIKernelModule* m_pKernelModule;
    AFIProxyServerNet_ServerModule* m_pProxyServerNet_ServerModule;
    AFIElementModule* m_pElementModule;
    AFIClassModule* m_pClassModule;
	AFINetClientModule* m_pNetClientModule;
};

#endif