#include <iostream>
#include <stdlib.h> // random
#include <time.h> // time
using namespace std;

class Customer
{
public:
	int timeEntered;
	int timeOrdered;
	int waitTime;
	int serviceTime;
	Customer *next;

	Customer()
	{
		timeEntered = 0;
		timeOrdered = 0;
		waitTime = 0;
		serviceTime = 1+ rand()%6;
		next = NULL;
	}
};

class Queue
{
public:
	Customer *currentCustomer;
	int length, remainingServiceTime, waitingTime, customersServed, customerCount, avgLength;
	int totalCustomers, currentCustomerWaitTime, totalCustomerWaitTime, totalCustomerServiceTime, totalServiceTime;
	float avgWaitTime, avgServiceTime;
	int minWaitTime, minServiceTime, minLength, maxWaitTime, maxServiceTime, maxLength, timeMaxLength, timeMinLength;
	int timeMaxWaitTime, timeMinWaitTime, timeMaxServiceTime, timeMinServiceTime;

	Queue()
	{
		currentCustomer=NULL;
		length = 0;
		remainingServiceTime =0;
		waitingTime = 0;
		customersServed = 0;
		customerCount = 0;
		avgLength = 0;
		totalCustomers=0;
		currentCustomerWaitTime=0;
		totalCustomerWaitTime=0;
		totalCustomerServiceTime = 0;
		totalServiceTime=0;
		avgServiceTime=0;
		avgWaitTime=0;
		minWaitTime=99999;
		minServiceTime=99999;
		minLength=99999;
		maxWaitTime=0;
		maxServiceTime=0;
		maxLength=0;
		timeMaxLength=0;
		timeMinLength=0;
		timeMaxWaitTime=0;
		timeMinWaitTime=0;
		timeMaxServiceTime=0;
		timeMinServiceTime=0;
	}
	void reduceTimeLeft()
	{
		if (length>0)
		{
			remainingServiceTime--;
		}
	}

	void increaseWaitTime()
	{
		Customer *temp = currentCustomer;
		if (length==0 || length==1)
		{
			//no one is waiting to order
		}
		else
		{	for (int i=0; i<length-1; i++)
			{
				temp->next->waitTime++;
			}
		}
	}

	void enQueue(int x)
	{
		Customer *temp = new Customer();
		temp->timeEntered = x;

		if (currentCustomer == NULL)
		{
			currentCustomer = temp;
			currentCustomer->timeOrdered=x;
			remainingServiceTime = currentCustomer->serviceTime;
		}
		else if (length == 1)
		{
			currentCustomer->next = temp;
		}
		else
		{
			Customer *temp2 = currentCustomer;
			for (int i=0; i<length-1; i++)
			{
				temp2 = temp2->next;
			}
				temp2->next = temp;
		}
		length++;
		customerCount++;
		if (length<=minLength)
		{
			minLength = length;
			timeMinLength = x;
		}
		if (length>=maxLength)
		{
			maxLength = length;
			timeMaxLength = x;
		}

	}

	void deQueue(int x)
	{
		if (currentCustomer == NULL)
		{
			//Nothing to delete
		}
		else
		{
			totalServiceTime=0;
			Customer *temp;
			temp = currentCustomer;

			currentCustomerWaitTime=currentCustomer->waitTime;

			totalCustomerWaitTime = totalCustomerWaitTime + currentCustomerWaitTime;
			remainingServiceTime = currentCustomer->serviceTime;

			currentCustomer = currentCustomer->next;
			totalCustomerServiceTime = totalCustomerServiceTime + remainingServiceTime;
			totalServiceTime = remainingServiceTime + currentCustomerWaitTime;

			if (currentCustomerWaitTime<=minWaitTime)
			{
				minWaitTime= currentCustomerWaitTime;
				timeMinWaitTime = x;
			}

			if(totalServiceTime<=minServiceTime)
			{
				minServiceTime = totalServiceTime;
				timeMinServiceTime = x;
			}

			if (currentCustomerWaitTime>=maxWaitTime)
			{
				maxWaitTime= currentCustomerWaitTime;
				timeMaxWaitTime = x;
			}

			if(totalServiceTime>=maxServiceTime)
			{
				maxServiceTime = totalServiceTime;
				timeMaxServiceTime = x;
			}

			delete temp;
			length --;
			customersServed++;
		}
		if (length == 0)
		{
			currentCustomer = NULL;
		}
	}

	void averageWaitTime()
	{
		avgWaitTime = (float)totalCustomerWaitTime/customerCount;
	}

	void avgCustomerServiceTime()
	{

		avgServiceTime = (float)(totalCustomerServiceTime+totalCustomerWaitTime)/customersServed;
	}

	void averageLength(){
		totalCustomers = totalCustomers + length;
		avgLength= (float)totalCustomers/1020;
	}

};

int main()
{
	Queue Queue, QueueA;
	srand (time(NULL));

	for (int i=0; i<1020; i++)
	{
		if (i<120)
		{
			int probCustomer = 1+rand()%10;
			if (probCustomer <=3)
			{
				Queue.enQueue(i);
			}
		}
		if (i>=120 && i<210 || i>=330 && i<570 || i>=900 && i<1020)
		{
			int probCustomer = 1+rand()%10;
			if (probCustomer ==1)
			{
				Queue.enQueue(i);
			}
		}
		if (i>=210 && i<330)
		{
			int probCustomer = 1+rand()%10;
			if (probCustomer <=4)
			{
				Queue.enQueue(i);
			}
		}
		if (i>=570 && i<720)
		{
			int probCustomer = 1+ rand()%100;
			if (probCustomer <=25)
			{
				Queue.enQueue(i);
			}
		}
		if (i>=720 && i<900)
		{
			int probCustomer = 1+ rand()%10;
			if (probCustomer <=2)
			{
				Queue.enQueue(i);
			}
		}
		Queue.averageLength();
		Queue.reduceTimeLeft();
		Queue.increaseWaitTime();
		if (Queue.remainingServiceTime==0)
		{
			Queue.deQueue(i);
		}
	}
	int count=1020;
	while (Queue.length >0)
	{
		Queue.averageLength();
		Queue.reduceTimeLeft();
		Queue.increaseWaitTime();
		if (Queue.remainingServiceTime==0)
		{
			Queue.deQueue(count);
		}
		count++;
	}
	Queue.averageWaitTime();
	Queue.avgCustomerServiceTime();

  cout << "2.1 - Part 1 Current system" << '\n';
  cout << "The average queue length for the today was: " << Queue.avgLength << " parties" << endl;
  cout << "The average customer wait time was: " << Queue.avgWaitTime << " minutes" << endl;
  cout << "The average customer service time was: " << Queue.avgServiceTime << " minutes" << endl;

  cout << "The best (shortest) customer wait time was: " << Queue.minWaitTime << " and it occurred at minute: " << Queue.timeMinWaitTime << endl;
  cout << "The best (shortest) customer service time was: " << Queue.minServiceTime << " and it occurred at minute: " << Queue.timeMinServiceTime << endl;
  cout << "The best (shortest) queue length was: " << Queue.minLength << " and it occurred at minute: " << Queue.timeMinLength << endl;
  cout << "The worst (longest) customer wait time was: " << Queue.maxWaitTime << " and it occurred at minute: " << Queue.timeMaxWaitTime << endl;
  cout << "The worst (longest) queue length was: " << Queue.maxLength << " and it occurred at minute: " << Queue.timeMaxLength << endl;
  cout << "The worst (longest) customer service time was: " << Queue.maxServiceTime << " and it occurred at minute: " << Queue.timeMaxServiceTime << endl;
  cout << "--------------------------------------------------------------" << '\n';
  cout << endl;
  cout << "2.2 - Optomization" << '\n';

  cout << endl;

  srand (time(NULL));

  for (int i=0; i<1020; i++)
  {
    if (i<120)
    {
      int probCustomer = 1+rand()%10;
      if (probCustomer <=3)
      {
        QueueA.enQueue(i);
      }
    }
    if (i>=120 && i<210 || i>=330 && i<570 || i>=900 && i<1020)
    {
      int probCustomer = 1+rand()%10;
      if (probCustomer ==1)
      {
        QueueA.enQueue(i);
      }
    }
    if (i>=210 && i<330)
    {
      int probCustomer = 1+rand()%10;
      if (probCustomer <=4)
      {
        QueueA.enQueue(i);
      }
    }
    if (i>=570 && i<720)
    {
      int probCustomer = 1+ rand()%100;
      if (probCustomer <=25)
      {
        QueueA.enQueue(i);
      }
    }
    if (i>=720 && i<900)
    {
      int probCustomer = 1+ rand()%10;
      if (probCustomer <=2)
      {
        QueueA.enQueue(i);
      }
    }
    QueueA.averageLength();
    QueueA.reduceTimeLeft();
    QueueA.increaseWaitTime();
    if (QueueA.remainingServiceTime==0)
    {
      QueueA.deQueue(i);
    }
  }
  int cunt=1020;
  while (Queue.length >0)
  {
    QueueA.averageLength();
    QueueA.reduceTimeLeft();
    QueueA.increaseWaitTime();
    if (QueueA.remainingServiceTime==0)
    {
      QueueA.deQueue(count);
    }
    cunt++;
  }
  QueueA.averageWaitTime();
  QueueA.avgCustomerServiceTime();
  cout << "First option" << endl;
  cout << "The average queue length for the today was: " << QueueA.avgLength << " parties" << endl;
  cout << "The average customer wait time was: " << QueueA.avgWaitTime << " minutes" << endl;
  cout << "The average customer service time was: " << QueueA.avgServiceTime << " minutes" << endl;

  cout << endl;
  cout << "Second option" << endl;
  cout << "The average queue length for the today was: " << Queue.avgLength << " parties" << endl;
  cout << "The average customer wait time was: " << Queue.avgWaitTime << " minutes" << endl;
  cout << "The average customer service time was: " << Queue.avgServiceTime << " minutes" << endl;

  return 0;
}
