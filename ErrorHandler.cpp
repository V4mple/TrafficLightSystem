#include "ErrorHandler.h"

ErrorHandler::ErrorHandler()
{
    error = false;
    errorCode = "No Error Detected\n";
}

// Function to determine if an error is detected. Will create a random number using rand() from the seed generated in generateError(). Returns true 10% of the time currently.
void ErrorHandler::errorDetected()
{
    int errorChance = rand() % 10;
    error = (errorChance < 1) ? true : false; // Change conditional to edit percentage chance of an error.
}

// If errorDetected returns true, use rand() to decide on an error code to give.
void ErrorHandler::generateError()
{
    errorDetected();

    std::string errorCode = "No Error Detected\n";
    if (error == true)
    {
        int errorGenerated = rand() % 13; // Add to the number for each error case
        switch (errorGenerated)
        {
            case 0:
                errorCode = "1001 North Sensor\n"; break;
            case 1:
                errorCode = "1002 East Sensor\n"; break;
            case 2:
                errorCode = "1003 West Sensor\n"; break;
            case 3:
                errorCode = "1004 South Sensor\n"; break;
            case 4:
                errorCode = "2001 North Camera\n"; break;
            case 5:
                errorCode = "2002 East Camera\n"; break;
            case 6:
                errorCode = "2003 West Camera\n"; break;
            case 7:
                errorCode = "2004 South Camera\n"; break;
            case 8:
                errorCode = "3001 North Pedestrian Button"; break;
            case 9:
                errorCode = "3002 East Pedestrian Button"; break;
            case 10:
                errorCode = "3003 West Pedestrian Button"; break;
            case 11:
                errorCode = "3004 South Pedestrian Button"; break;
            case 12:
                errorCode = "9999 Power Supply"; break;
            default:
                errorCode = "Unknown Error\n"; break;
        }
    }
    std::cout << errorCode;
}

bool ErrorHandler::getErrorStatus()
{
    return error;
}
