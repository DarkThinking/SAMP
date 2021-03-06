ShowDialog:NaviTarget_PropertyName(playerID)
{
	CreateDialog(playerID, "NaviTarget_PropertyName", DIALOG_STYLE_INPUT, LanguageString(playerID, StringID:417("Name of a property")), LanguageString(playerID, StringID:418("Enter the name of the target house.")), "OK", LanguageString(playerID, StringID:171("Back")));
}

DialogResponse:NaviTarget_PropertyName(playerID, response, listItem, inputText[])
{
	if (response)
	{
		MySQLQuery("SELECT * FROM `properties` LEFT JOIN `pickups` ON `properties`.`pickupId` = `pickups`.`id` WHERE `name` LIKE '%%%s%%'", MySQLEscapeString(inputText));
		mysql_store_result();
		new rows = mysql_num_rows();
		if (rows)
		{
			if (rows == 1)
			{
				if (CalculateRoute(playerID, floatstr(GetMySQLField("posX")), floatstr(GetMySQLField("posY")), floatstr(GetMySQLField("posZ"))))
				{
					SendClientMessageEx(playerID, COLOR_INFO, StringID:414("Calculating route"));
				}
				else
				{
					SendClientMessageEx(playerID, COLOR_ERROR, StringID:415("No GPS!"));
				}
			}
			else
			{
				ShowDialog:NaviTarget_PropertyList(playerID, inputText);
			}
		}
		mysql_free_result();
	}
	else
	{
		ShowDialog:NaviTarget(playerID);
	}
}