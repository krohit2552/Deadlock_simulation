// Deadlock simulation
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{	
	cout<<"How many sequence check for safe or not"<<endl;
	int num_of_sequence;cin>>num_of_sequence;
	 for(int p=1;p<=num_of_sequence;p++){
		
		int n, m, i, j, k;
		cout<<"sequence number="<<p<<endl;
		cout<<"Number of processes"<<endl;
		cin>>n;		//  Number of processes;
		cout<<"Number of resources"<<endl;
		cin>>m;		//  Number of resources;
		
		ofstream f1("Alloc_resource.txt");
		cout<<"Allocation of resource Matrix"<<endl;
		int alloc[n][m];   //Allocation  Matrix
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>alloc[i][j];
				f1<<alloc[i][j]<<" ";
			}
			f1<<endl;
		}					
		
		ofstream f2("max_Need_resource.txt");
		cout<<"Max resource need Matrix"<<endl;
		int max[n][m]; // MAX Matrix
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>max[i][j];
				f2<<max[i][j]<<" ";
			}
			f2<<endl;
		}
		
		ofstream f4("need_resourse.txt");
			int need[n][m];
			cout<<"Needs of Resource for each process"<<endl;
			f4<<"Needs of Resource"<<endl;
			for (int i = 0; i<n; i++) {
				for (int j = 0; j<m; j++){
				need[i][j] = max[i][j] - alloc[i][j];
				cout<<need[i][j]<<" ";
				f4<<need[i][j]<<" ";
				}
				cout<<endl;
				f4<<endl;
			}
			
		cout<<"How many Available Resource check for above Sequence"<<endl;
		int avail_Resource;
		ofstream f3("avail_resource.txt");
	    cin>>avail_Resource;
	    for(int i=1;i<=avail_Resource;i++){
			int avail[m];                  // Available Resources
			cout<<"check Available Resources:"<<" "<<i<<endl;
			f3<<"Available Resource"<<" "<<i<<endl;
			for(int j=0;j<m;j++){
				cin>>avail[j];
				f3<<avail[j]<<" ";
			}
			f3<<endl;
			
			int f[n], ans[n], ind = 0;
			for (k = 0; k < n; k++) {
				f[k] = 0;
			}
			
			
			int y = 0;
			for (k = 0; k < 5; k++) {
				for (int i = 0; i < n; i++) {
				if (f[i] == 0) {
			
					int flag = 0;
					for (int j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
					}
			
					if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
					}
				}
				}
			}
			
			int flag = 1;
			cout<<"\n";
			// To check if sequence is safe or not
			cout<<"<- - - - - - - - - - - - - - -RESULT- - - - - - - - - - - - -  - - - -  ->"<<endl;
			cout<<"\n";
			for(int i = 0;i<n;i++)
			{
					if(f[i]==0)
				{
					flag = 0;
					cout << "The given sequence is "<<endl;
					cout<<"     "<<"* * * *not safe * * * *"<<endl;
					break;
				}
			}
			
			if(flag==1)
			{
				cout << "The given sequence is "<<endl;
				cout << "* * * * *SAFE Sequence* * * * *" << endl;
				for (int i = 0; i < n - 1; i++)
					cout << " P" << ans[i] << " ->";
				cout << " P" << ans[n - 1] <<endl;
			}
			cout<<endl;
		}
		f1.close();
		f2.close();
		f3.close();
		//f4.close();
	}
	return (0);
}

