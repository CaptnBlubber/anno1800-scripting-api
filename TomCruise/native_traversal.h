#pragma once

#include <string>
#include "Q/structs.h"
#include "Q/comms.h"
#include "Q/autocomms.h"

std::string GetStringFromAnnoString(uint64_t stringAddress);
std::string GetStringFromNameComponent(uint64_t componentAddress);

bool GetIslandById(const uint64_t id, uint64_t* islandBaseAddress);
bool GetIslandIDsByName(const std::string& name, std::vector<uint64_t>* ids);
bool GetIslandResource(const IslandResourceRecordRequst& request, IslandResourceRecordResult* result);

bool GetShipById(const uint64_t id, uint64_t* shipBaseAddress);

bool GetIslandBuildings(const uint64_t islandID, std::vector<AutoComms::BuildingData>* buildings, BuildingCache* buildingCache);

bool GetBuildingAddress(const uint64_t islandID, const uint64_t buildingID, BuildingCache* buildingCache, uint64_t* address);
