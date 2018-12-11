#include <iostream>

using namespace std;

int main()
{
	int floor = 0;
	int a[1000] = {0};
	cin>> floor;
	int temp = floor;
	int i =0;
	while (temp--){
		cin>>a[i++];
	}
	int min = 100000000;
	for(int x = 0; x<floor;x++)
	{
		int sum  =0;
		for( int j = 0; j<floor;j++)
		{
			if(x >=j){
				sum +=4*x*a[j];
			}
			else{
				sum+=4*j*a[j];
			}

		}
		min = min<sum?min:sum;

	}

    cout<<min<<endl;

    return 0;
}
