// AIDAPP Moneky Code
#include <iostream>
#include <stack>
#include <queue>
#define MAXINJ 1000000

using namespace std;

int main()
{
	int monkey;
	long int health=100, injuries=1;
	long int i, N, firstElemQueue, pos=1, count=0, maxCount=0;
	stack<long int> winningPositions;
	queue<long int> monkeyQueue;
	cin>>N;

	for(i=0; i<N; i++)
	{
		cin>>monkey;

		monkeyQueue.push(monkey);
		count++;

		health -= monkey;
		injuries *= monkey;

		while(health<1 || injuries>MAXINJ)
		{
			firstElemQueue = monkeyQueue.front();
			health += firstElemQueue;
			injuries /= firstElemQueue;

			cout<<"popped : "<<endl;
			monkeyQueue.pop();
			count--;
			pos++;
			
		}
		
		cout<<"C : "<<count<<"  max count : "<<maxCount<<endl;
		
		if(count == maxCount)
			winningPositions.push(pos);
		
		
		if(count>maxCount)
		{
			maxCount = count;
			while(!winningPositions.empty())
			{
				winningPositions.pop();
			}
			winningPositions.push(pos);
		}
		
		
	}
	
	while(!winningPositions.empty())
	{
		cout<<"Winning Position : "<<winningPositions.top()<<endl;
		winningPositions.pop();
	}
	return 0;

}
