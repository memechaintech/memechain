#ifndef _CA_H
#define _CA_H

#include <iostream>
#include <thread>
#include <shared_mutex>

#include "proto/transaction.pb.h"

extern bool bStopTx;
extern bool bIsCreateTx;




void RegisterCallback();
void TestCreateTx(const std::vector<std::string> & addrs, const int & sleepTime);

/**
 * @brief       CA initialization
 * 
 * @return      true success
 * @return      false failure
 */
bool CaInit();

/**
 * @brief       CA cleanup function
 */
void CaCleanup();

/**
 * @brief       Related implementation functions used in the main menu
 */
void PrintBasicInfo();

/**
 * @brief       
 */
void HandleTransaction();

/**
 * @brief       
 */
void HandleStake();

/**
 * @brief       
 */
void HandleUnstake();

/**
 * @brief       
 */
void HandleInvest();

/**
 * @brief       
 */
void HandleDisinvest();

/**
 * @brief       
 */
void HandleBonus();

/**
 * @brief       
 */
void HandleAccountManger();

/**
 * @brief       
 */
void HandleSetdefaultAccount();

/**
 * @brief       
 */
void DeployContract();

/**
 * @brief       
 */
void CallContract();

/**
 * @brief       
 */
void HandleExportPrivateKey();

/**
 * @brief       NTPcheckout
 * 
 * @return      int 
 */
int CheckNtpTime();

/**
 * @brief       Get the Chain Height object
 * 
 * @param       chainHeight: 
 * @return      int 
 */
int GetChainHeight(unsigned int & chainHeight);


/**
 * @brief       
 * 
 * @param       arg: 
 * @param       ack: 
 * @return      std::string 
 */
std::string RpcCallContract(void * arg,void *ack);

/**
 * @brief       
 * 
 * @param       arg: 
 * @param       ack: 
 * @return      std::string 
 */
std::string RpcDeployContract(void * arg,void *ack);

/**
 * @brief       
 * 
 * @param       tx: 
 * @param       addr: 
 * @return      int 
 */
int SigTx(CTransaction &tx,const std::string & addr);
/**
 * @brief   Deploy multiple contracts with one click   
 * 
 */
void CreateAutomaticDeployContract();
/**
 * @brief   Processing contract transactions   
 * 
 */
void HandleMultiDeployContract(const std::string &strFromAddr);
/**
 * @brief   The contract data is exported to json
 * 
 */
void printJson();

std::string remove0xPrefix(std::string str);

std::vector<uint8_t> hexStringToBytes(const std::string& hexString);

std::string seedToHexString(const uint8_t seed[], size_t length);

std::string addHexPrefix(std::string hexStr);

void otherpayGas(const std::string assetType,std::string &_isGastrade,std::pair<std::string,std::string> &gasTrade);
void otherpayGas(const std::string assetType,std::pair<std::string,std::string> &gasTrade,bool &_isGastrade);
            
void HandleLock();            
            
void HandleUnLock();          

void HandleProposal();        

void HandleRevokeProposal();  
                  
void HandleVote();    

void HandleTresury();

int discoverTransactionHeight(uint64_t &height);

#endif
