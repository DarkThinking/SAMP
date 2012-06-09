ShowDialog:Accept(playerID)
{
	new missionList[2048];
	MySQLQuery("SELECT * FROM `missions` WHERE `jobId` = '%d' AND `acceptUserId` = '0' ORDER BY `name` ASC", PVar:playerID[JOBID]);
	mysql_store_result();
	while (FetchMySQLRow())
	{
		if (strlen(missionList))
		{
			Format:missionList("%s\n", missionList);
		}
		Format:missionList("%s%s: %s", missionList, GetMySQLField("id"), GetMySQLField("name"));
	}
	mysql_free_result();
	if (strlen(missionList))
	{
		CreateDialog(playerID, "Accept", DIALOG_STYLE_LIST, LanguageString(playerID, 163), missionList, LanguageString(playerID, 164), LanguageString(playerID, 165));
	}
	else
	{
		SendClientMessageEx(playerID, COLOR_ERROR, 134);
	}
}

DialogResponse:Accept(playerID, response, listItem, inputText[])
{
	if (response)
	{
		new missionID;
		new text[100];
		sscanf(inputText, "p:ds", missionID, text);
		if (strval(GetMySQLValue("missions", "acceptUserId", "id", val2str(missionID))))
		{
			SendClientMessageEx(playerID, COLOR_ERROR, 12);
		}
		else
		{
			MySQLQuery("UPDATE `missions` SET `acceptUserId` = '%d' WHERE `id` = '%d'", PVar:playerID[USERID], missionID);
			SendClientMessageEx(playerID, COLOR_INFO, 15);
			SendClientMessageEx(GetPlayerByUserID(strval(GetMySQLValue("missions", "creatorUserId", "id", val2str(missionID)))), COLOR_INFO, 1, playerID, missionID);
			MySQLQuery("SELECT * FROM `missiondata` WHERE `missionId` = '%d' AND `name` = 'VehicleModelID'", missionID);
			mysql_store_result();
			// TODO: Missing code?
			mysql_free_result();
		}
	}
}