// AIDAPP Moneky Code
#include <iostream>
#include <stack>
#include <queue>
#define MAXINJ 1000000

using namespace std;

int main()
{
	int monkey;
	long int health=2000, injuries=1;
	long int i, N, firstElemQueue, pos=1, count=0, maxCount=0;
	stack<long int> winningPositions;
	queue<long int> monkeyQueue;
	cin>>N;

	for(i=0; i<N; i++)
	{
		cin>>monkey;

		monkeyQueue.push(monkey);								//Queue of monkeys that contain the all the monkeys that can be defeated by us starting from position 'pos'.
		count++;												// 'count' - number of monkeys in the queue at a time.

		health -= monkey;
		injuries *= monkey;

		while(health<1 || injuries>MAXINJ)						//In case if the health has gone down below 1 or injuries have exceeded the maximum injuries, we pop the elements until conditions are met again and maintain the max count.
		{
			firstElemQueue = monkeyQueue.front();
			health += firstElemQueue;
			injuries /= firstElemQueue;

			cout<<"Popped : "<<endl;							
			monkeyQueue.pop();
			count--;
			pos++;
			
		}
		
		cout<<"C : "<<count<<"  max count : "<<maxCount<<endl;
		
		if(count == maxCount)									//Stack that maintains all the winning positions.
			winningPositions.push(pos);
		
		
		if(count>maxCount)										//In case the count has exceeded max count starting from position 'pos', we empty the stack and fill it with the current pos.
		{		
			maxCount = count;								
			while(!winningPositions.empty())
			{
				winningPositions.pop();
			}
			winningPositions.push(pos);
		}
		
		
	}
	
	while(!winningPositions.empty())							//All the winning positions.
	{
		cout<<"Winning Position : "<<winningPositions.top()<<endl;
		winningPositions.pop();
	}
	return 0;

}


//The time complexity is O(n)
