/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _WORLDDATABASE_H
#define _WORLDDATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class WorldDatabaseConnection : public MySQLConnection
{
    public:
        //- Constructors for sync and async connections
        WorldDatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo) {}
        WorldDatabaseConnection(ACE_Activation_Queue* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo) {}

        //- Loads database type specific prepared statements
        void DoPrepareStatements();
};

typedef DatabaseWorkerPool<WorldDatabaseConnection> WorldDatabaseWorkerPool;

enum WorldDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SET/DEL/ADD/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    WORLD_LOAD_QUEST_POOLS,
    WORLD_DELETE_CRELINKED_RESPAWN,
    WORLD_REPLACE_CRELINKED_RESPAWN,
    WORLD_LOAD_CRETEXT,
    WORLD_LOAD_SMART_SCRIPTS,
    WORLD_LOAD_SMARTAI_WP,
    WORLD_DELETE_GAMEOBJECT,
    WORLD_DELETE_EVENT_GAMEOBJECT,
    WORLD_INSERT_GRAVEYARD_ZONE,
    WORLD_DELETE_GRAVEYARD_ZONE,
    WORLD_INSERT_GAME_TELE,
    WORLD_DELETE_GAME_TELE,
    WORLD_INSERT_NPC_VENODR,
    WORLD_DELETE_NPC_VENDOR,
    WORLD_SELECT_NPC_VENDOR_REF,
    WORLD_UPDATE_CREATURE_MOVEMENT_TYPE,
    WORLD_UPDATE_CREATURE_FACTION,
    WORLD_UPDATE_CREATURE_NPCFLAG,
    WORLD_UPDATE_CREATURE_POSITION,
    WORLD_UPDATE_CREATURE_SPAWN_DISTANCE,
    WORLD_UPDATE_CREATURE_SPAWN_TIME_SECS,
    WORLD_INSERT_CREATURE_FORMATION,
    WORLD_INSERT_WAYPOINT_DATA,
    WORLD_DELETE_WAYPOINT_DATA,
    WORLD_UPDATE_WAYPOINT_DATA_POINT,
    WORLD_UPDATE_WAYPOINT_DATA_POSITION,
    WORLD_UPDATE_WAYPOINT_DATA_WPGUID,
    WORLD_UPDATE_WAYPOINT_DATA_ALL_WPGUID,
    WORLD_SELECT_WAYPOINT_DATA_MAX_ID,
    WORLD_SELECT_WAYPOINT_DATA_BY_ID,
    WORLD_SELECT_WAYPOINT_DATA_POS_BY_ID,
    WORLD_SELECT_WAYPOINT_DATA_POS_FIRST_BY_ID,
    WORLD_SELECT_WAYPOINT_DATA_POS_LAST_BY_ID,
    WORLD_SELECT_WAYPOINT_DATA_BY_WPGUID,
    WORLD_SELECT_WAYPOINT_DATA_ALL_BY_WPGUID,
    WORLD_SELECT_WAYPOINT_DATA_MAX_POINT,
    WORLD_SELECT_WAYPOINT_DATA_BY_POS,
    WORLD_SELECT_WAYPOINT_DATA_WPGUID_BY_ID,
    WORLD_SELECT_WAYPOINT_DATA_ACTION,
    WORLD_SELECT_WAYPOINT_SCRIPTS_MAX_ID,
    WORLD_UPDATE_CREATURE_ADDON_PATH,
    WORLD_INSERT_CREATURE_ADDON,
    WORLD_SELECT_CREATURE_ADDON_BY_GUID,
    WORLD_DELETE_CREATURE_ADDON,
    WORLD_INSERT_WAYPOINT_SCRIPT,
    WORLD_DELETE_WAYPOINT_SCRIPT,
    WORLD_UPDATE_WAYPOINT_SCRIPT_ID,
    WORLD_UPDATE_WAYPOINT_SCRIPT_X,
    WORLD_UPDATE_WAYPOINT_SCRIPT_Y,
    WORLD_UPDATE_WAYPOINT_SCRIPT_Z,
    WORLD_UPDATE_WAYPOINT_SCRIPT_O,
    WORLD_SELECT_WAYPOINT_SCRIPT_ID_BY_GUID,
    WORLD_DELETE_CREATURE,
    WORLD_SELECT_GAMEOBJECT_NEAREST,
    WORLD_SELECT_GAMEOBJECT_TARGET,
    WORLD_SELECT_COMMANDS,
    WORLD_INSERT_CREATURE_TRANSPORT,
    WORLD_UPDATE_CREATURE_TRANSPORT_EMOTE,
    WORLD_SELECT_CREATURE_TEMPLATE,
    WORLD_SELECT_WAYPOINT_SCRIPT_BY_ID,
    //WORLD_SELECT_IP2NATION_COUNTRY,
    WORLD_SELECT_ITEM_TEMPLATE_BY_NAME,
    WORLD_SELECT_CREATURE_BY_ID,
    WORLD_SELECT_DISABLES,
    WORLD_INSERT_DISABLES,

    MAX_WORLDDATABASE_STATEMENTS,
};

#endif
