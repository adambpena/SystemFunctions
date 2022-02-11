#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

char ipConfig[] = "C:\\Windows\\System32\\ipconfig"; 

void TimedShutdown(int time){
    if(time < 0){
        time = 0;
    }

    string timeArg = to_string(time);
    string commandString = "C:\\Windows\\System32\\shutdown /s /t " + timeArg; 
    char* command = &commandString[0];

    system(command);
}

void TimedRestart(int time){
    if(time < 0){
        time = 0;
    }

    string timeArg = to_string(time);
    string commandString = "C:\\Windows\\System32\\shutdown /r /t " + timeArg; 
    char* command = &commandString[0];

    system(command);
}

int printMenu(){
    cout << "What would you like to do? \n 1. Timed Shutdown \n 2. Timed Restart \n 3. See Ip Information \n 4. Exit \n";
    int choice = 0;
    while(choice <= 0 || choice > 4){
        cout << "Enter your choice: ";
        cin >> choice;
    }
    return choice;
}

int main(){
    int pick; 
    while(pick != 4){
        pick = printMenu();

        switch(pick){
            case 1 :
                cout << "Would you like your timed shutdown to occur in seconds or hours? (Enter anything but 's' for seconds, 'm' for minutes, or 'h' for hours to cancel)";
                char timeUnit;
                cin >> timeUnit;
                cout << timeUnit << "\n";
                if(timeUnit != 's' && timeUnit != 'm' && timeUnit != 'h'){
                    cout << "Action cancelled. \n";
                    break;
                }

                if(timeUnit == 's'){
                    cout << "How many seconds until shutdown? (Enter a number 0-86400, anything greater or otherwise will cancel)";
                    int seconds;
                    cin >> seconds;
                    if(seconds < 0 || seconds > 86400){
                        cout << "Action cancelled. \n";
                        break;
                    }
                    else{
                        TimedShutdown(seconds);
                    }
                }

                if(timeUnit == 'm'){
                    cout << "How many minutes until shutdown? (Enter a number 0-1440, anything greater or otherwise will cancel)";
                    int minutes;
                    cin >> minutes;
                    if(minutes  < 0 || minutes > 1440){
                        cout << "Action cancelled. \n";
                        break;
                    }
                    else{
                        minutes = minutes * 60;
                        TimedShutdown(minutes);
                    }
                }

                if(timeUnit == 'h'){
                    cout << "How many hours until shutdown? (Enter a number 0-24, anything greater or otherwise will cancel)";
                    int hours;
                    cin >> hours;
                    if(hours < 0 || hours > 24){
                        cout << "Action cancelled. \n";
                        break;
                    }
                    else{
                        hours = hours * 60;
                        TimedShutdown(hours);
                    }
                }
                
                break;

            case 2 : 
                cout << "Would you like your timed restart to occur in seconds or hours? (Enter anything but 's' for seconds, 'm' for minutes, or 'h' for hours to cancel)";
                cin >> timeUnit;
                cout << timeUnit << "\n";
                if(timeUnit != 's' && timeUnit != 'm' && timeUnit != 'h'){
                    cout << "Action cancelled. \n";
                    break;
                }

                if(timeUnit == 's'){
                    cout << "How many seconds until restart? (Enter a number 0-86400, anything greater or otherwise will cancel)";
                    int seconds;
                    cin >> seconds;
                    if(seconds < 0 || seconds > 86400){
                        cout << "Action cancelled. \n";
                        break;
                    }
                    else{
                        TimedRestart(seconds);
                    }
                }

                if(timeUnit == 'm'){
                    cout << "How many minutes until restart? (Enter a number 0-1440, anything greater or otherwise will cancel)";
                    int minutes;
                    cin >> minutes;
                    if(minutes  < 0 || minutes > 1440){
                        cout << "Action cancelled. \n";
                        break;
                    }
                    else{
                        minutes = minutes * 60;
                        TimedRestart(minutes);
                    }
                }

                if(timeUnit == 'h'){
                    cout << "How many hours until restart? (Enter a number 0-24, anything greater or otherwise will cancel)";
                    int hours;
                    cin >> hours;
                    if(hours < 0 || hours > 24){
                        cout << "Action cancelled. \n";
                        break;
                    }
                    else{
                        hours = hours * 60;
                        TimedRestart(hours);
                    }
                }
                
                break;

            case 3 :
                system(ipConfig);
                break;
            case 4 :
                cout << "Goodbye!";
                return 0;
        }
    }
}