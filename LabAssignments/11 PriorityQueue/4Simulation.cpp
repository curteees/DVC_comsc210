// Programmer: Curtis Lee
// Programmer's ID: 1489029

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <queue>
using namespace std;

#include <cmath>
#include <cstdlib>

#include "MyDynamicArray.h"
#include "MyPriorityQueue.h"

struct Customer
{
  char ID; // A B  ... Z
  int arrivalT;
};

struct ServerInfo
{
  bool status;
  Customer cust;
};

struct ServiceEvent
{
  int serverIndex;
  int endT;
};

int getRandomNumberOfArrivals(double);
char genID(char&);

bool operator<(const ServiceEvent& a, const ServiceEvent& b)
{
  return a.endT >= b.endT;
}

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;
  
  srand(time(0));
  rand();

  int numServers = 0;
  double avgArrivalRate = 0.0;
  int waitMaxLength = 0;
  int minServTime = 0;
  int maxServTime = 0;
  int clockStopTime = 0;
  char curAlpha = 'A';
  
  ifstream fin;
  fin.open("simulation.txt");
  
  fin >> numServers;
  fin >> avgArrivalRate;
  fin >> waitMaxLength;
  fin >> minServTime;
  fin >> maxServTime;
  fin >> clockStopTime;
  cout << "number of servers:     " << numServers << endl;
  cout << "customer arrival rate: " << avgArrivalRate << " per minute, for " << clockStopTime << " minutes" << endl;
  cout << "maximum queue length:  " << waitMaxLength << endl;
  cout << "minimum service time:  " << minServTime << " minutes" << endl;
  cout << "maximum service time:  " << maxServTime << " minutes" << endl;
  
  queue<Customer> customerQ;
  MyDynamicArray<ServerInfo> servers;
  MyPriorityQueue<ServiceEvent> serviceInfo;
  
  for(int time = 0; ;time++)
  {
    // handle all services scheduled to complete at this clock time
    while ((serviceInfo.top().endT == time) && !serviceInfo.empty())
    {
      servers[serviceInfo.top().serverIndex].status = false;
      serviceInfo.pop();
    }
    // handle new arrivals -- can be turned away if wait queue is at maximum length!
    if(time < clockStopTime)
    {
      int numArrive = getRandomNumberOfArrivals(avgArrivalRate);
      for(int i = 0; i < numArrive; i++)
      {
        if(customerQ.size() < waitMaxLength)
        {
          Customer c;
          c.ID = genID(curAlpha);
          c.arrivalT = time;
          customerQ.push(c);
        }
      }
    }
    //for idle servers, move customer from wait queue and begin
    for(int i = 0; i < numServers; i++)
    {
      if(!servers[i].status && !customerQ.empty())
      {
        servers[i].cust = customerQ.front();
        customerQ.pop();
        servers[i].status = true;
        ServiceEvent temp = {i, time + minServTime + rand() % (maxServTime - minServTime + 1)};
        serviceInfo.push(temp);
      }
    }
    
    // output event list
    cout << "server | time for end-of-service\n" << "------ + -----------------------\n";
    for (MyPriorityQueue<ServiceEvent> temp = serviceInfo; !temp.empty(); temp.pop()){
      cout.width(4);
      cout << temp.top().serverIndex << "   |";
      cout.width(12);
      cout << temp.top().endT << endl;
    }
    
    //output the summary
    int numIdle = 0;
    if(numIdle == numServers)
      cout << "\nTime: " << time << ", no scheduled end-of-service events at this time\n";
    else
      cout << "\nTime: " << time << endl;
    cout << "---------------------------" << endl;
    cout << "server now serving wait queue" << endl;
    cout << "------ ----------- ----------" << endl;
    for (int i = 0; i < numServers; i++)
    {
      string show = " ";
      if (servers[i].status)
      {
        show = servers[i].cust.ID;
      }
      cout << setw(2) << i << setw(10) << show;
      if (i == 0)
      {
        queue<Customer> tempQ = customerQ;
        cout << setw(10);
        while (!tempQ.empty())
        {
          cout << tempQ.front().ID;
          tempQ.pop();
        }
      }
      cout << endl;
    }
    
    for (int i = 0; i < numServers; i++){
      if (!servers[i].status) {
        numIdle++;
      }
    }
    
    if(numIdle == numServers && time >= clockStopTime)
    {
      cout << "--------------------------";
      cout << "\nDone!\n\n";
      break;
    }
    do{
      cout << "--------------------------";
      cout << "\nPress ENTER to continue...";
    }while (cin.get() != '\n');
  }
}

int getRandomNumberOfArrivals(double averageArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX;
    (randomValue -= probOfnArrivals) > 0.0;
    probOfnArrivals *= averageArrivalRate / static_cast<double>(++arrivals));
  return arrivals;
}
  
char genID(char& curAlpha)
{
  if(curAlpha == 'Z')
  {
    curAlpha = 'A';
    return 'Z';
  }
  return curAlpha++;
}
