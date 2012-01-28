CMD:about(playerid, params[])
{
	SendClientMessage(playerid, COLOR_INFO, "Created by Aerox_Tobi (aerox@grgserver.de) and Programie (programie@selfcoders.com)");
	return COMMAND_OK;
}

CMD:makeadmin(playerid, params[])
{
	new playerName[MAX_PLAYER_NAME];
	new level;
	if (GetPVarInt(playerid, "AdminLevel") >= ADMINLEVEL_SERVERADMIN)
	{
		if (!sscanf(params, "sd", playerName, level))
		{
			SendClientMessage(playerid, COLOR_USAGE, "Verwendung: /makeadmin [Spielername] [level(1-1337)]");
		}
		new targetPlayerID = getPlayerByName(playerName);
		if (targetPlayerID == INVALID_PLAYERID)
		{
			SendClientMessage(playerid, COLOR_ERROR, "Spieler nicht gefunden!");
		}
		else
		{
			if (level >= 1 && level <= 1337)
			{
				new string[256];
				new adminPlayerName[MAX_PLAYER_NAME];
				new targetPlayerName[MAX_PLAYER_NAME];
				GetPlayerName(playerid, adminPlayerName, sizeof(adminPlayerName));
				GetPlayerName(targetPlayerID, targetPlayerName, sizeof(targetPlayerName));
				SetPVarInt(targetPlayerID, "AdminLevel", level);
				format(string, sizeof(string), "Du hast Admin Level %d von %s bekommen!", level, adminPlayerName);
				SendClientMessage(targetPlayerID, COLOR_INFO, string);
				format(string, sizeof(string), "Du hast Admin Level %d an %s gegeben!", level, targetPlayerName);
				SendClientMessage(playerid, COLOR_INFO, string);
				printf("%s got admin level %d by %s", targetPlayerName, level, adminPlayerName);
			}
			else
			{
				SendClientMessage(playerid, COLOR_ERROR, "Level muss zwischen 1 und 1337 sein!");
			}
		}
	}
	else
	{
		return COMMAND_ACCESS_DENIED;
	}
	return COMMAND_OK;
}

CMD:gotobsn(playerid, params[])
{
	if (GetPVarInt(playerid, "AdminLevel") >= ADMINLEVEL_SERVERADMIN)
	{
		if (GetPlayerState(playerid) == 2)
		{
			new tmpcar = GetPlayerVehicleID(playerid);
			SetVehiclePos(tmpcar, 1204.7445,-881.0291,43.0703);
			TelePos[playerid][0] = 0.0;TelePos[playerid][1] = 0.0;
		}
		else
		{
			SetPlayerPos(playerid, 1199.4624,-914.1083,48.0625);
		}
		SendClientMessage(playerid, COLOR_GRAD, "Du hast dich Teleportiert !");
		SetPlayerInterior(playerid,0);
	}
	return COMMAND_OK;
}
CMD:gotols(playerid, params[])
{
	if (GetPVarInt(playerid, "AdminLevel") >= ADMINLEVEL_SERVERADMIN)
	{
		if (GetPlayerState(playerid) == 2)
		{
			new tmpcar = GetPlayerVehicleID(playerid);
			SetVehiclePos(tmpcar, 1529.6,-1691.2,13.3);
			TelePos[playerid][0] = 0.0;TelePos[playerid][1] = 0.0;
		}
		else
		{
			SetPlayerPos(playerid, 1529.6,-1691.2,13.3);
		}
		SendClientMessage(playerid, COLOR_GRAD, "Du hast dich Teleportiert !");
		SetPlayerInterior(playerid,0);
	}
	return COMMAND_OK;
}
CMD:gotolv(playerid, params[])
{
	if (GetPVarInt(playerid, "AdminLevel") >= ADMINLEVEL_SERVERADMIN)
	{
		if (GetPlayerState(playerid) == 2)
		{
			new tmpcar = GetPlayerVehicleID(playerid);
			SetVehiclePos(tmpcar, 1699.2, 1435.1, 10.7);
			TelePos[playerid][0] = 0.0;TelePos[playerid][1] = 0.0;
		}
		else
		{
			SetPlayerPos(playerid, 1699.2,1435.1, 10.7);
		}
		SendClientMessage(playerid, COLOR_GRAD, "Du hast dich Teleportiert");
		SetPlayerInterior(playerid,0);
	}
	return COMMAND_OK;
}
CMD:gotosf(playerid, params[])
{
	if (GetPVarInt(playerid, "AdminLevel") >= ADMINLEVEL_SERVERADMIN)
	{
		if (GetPlayerState(playerid) == 2)
		{
			new tmpcar = GetPlayerVehicleID(playerid);
			SetVehiclePos(tmpcar, -1417.0,-295.8,14.1);
			TelePos[playerid][0] = 0.0;TelePos[playerid][1] = 0.0;
		}
		else
		{
			SetPlayerPos(playerid, -1417.0,-295.8,14.1);
		}
		SendClientMessage(playerid, COLOR_GRAD, "Du hast dich Teleportiert");
		SetPlayerInterior(playerid,0);
	}
	return COMMAND_OK;
}