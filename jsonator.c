/*******************************************************************************
* Copyright (c) 2014 IBM Corporation and other Contributors.
*
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*   Amit Mangalvedkar - Initial Contribution
*******************************************************************************/

/*
 * This function generates the json based on the events from Raspberry Pi
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "iot.h"

char * generateJSON(JsonMessage passedrpi ) {
	char * jsonReturned;

	// 2 braces, 4 colons, 3 commas, 10 double-quotes makes it 19
	jsonReturned = calloc(1, sizeof passedrpi + sizeof(char) * 225);

	strcat(jsonReturned, "{\"d\":");
	strcat(jsonReturned, "{");

	strcat(jsonReturned, "\"deviceId\":\"");
	strcat(jsonReturned, passedrpi.deviceId);
	strcat(jsonReturned, "\",");
	char buffer[10];

	strcat(jsonReturned, "\"temp\":");
	sprintf(buffer, "%.2f", passedrpi.locTemp);
	strcat(jsonReturned, buffer);
	strcat(jsonReturned, ",");

	strcat(jsonReturned, "\"motion\":");
	strcat(jsonReturned, passedrpi.motData);
// Concatenate the distance
	strcat(jsonReturned, ",");

	strcat(jsonReturned, "\"obstacle\":");
	strcat(jsonReturned, passedrpi.obstacle);
/*


	strcat(jsonReturned, "\"motion\":");
	sprintf(buffer, "%d", passedrpi.motData);
	strcat(jsonReturned, buffer);
	strcat(jsonReturned, ",");


	strcat(jsonReturned, "\"sine\":");
	sprintf(buffer, "%.2f", passedrpi.sine);
	strcat(jsonReturned, buffer);
	strcat(jsonReturned, ",");

	strcat(jsonReturned, "\"sensordata\":");
	sprintf(buffer, "%.2f", passedrpi.sensordata);
	strcat(jsonReturned, buffer);
*/
	strcat(jsonReturned, "}");
	strcat(jsonReturned, ",");
        strcat(jsonReturned, "\"ts\":");
	strcat(jsonReturned, passedrpi.tStamp);

	strcat(jsonReturned, "}");

	return jsonReturned;
}

