#include<iostream>
#include<vector>
#include<map>
#include<cmath>

using namespace std;

// int primediv(int num){    // prime DIV is happening in O(sqrt(n))

// 	map<int,int> prime;
// 	//vector<int> prime;
// 	//cout<<"num "<<num;

// 	for(int i=2; i*i<=num;i++){
// 		int flg = 0;
// 		while(num%i==0){
// 			flg++;
// 			num = num /i;
// 		}

// 		if(flg>0){
// 			prime.insert({i,1});
// 		}
// 	}

// 	if(num>1){
// 		prime.insert({num,1});
// 	}

// 	int cnt = prime.size();
// 	//cout<<" cnt "<<cnt <<endl;

// 	return cnt;
// }

const int N = 1500;
vector<bool> prime(N,1);
vector<int> primeNums;

void computePrime(){

	prime[0]=prime[1]=0;

	for(int i=2;i<N;i++){   // N * log log n
		if(prime[i]==1){
			primeNums.push_back(i);
			for(int j = 2*i;j<N;j+=i)
				prime[j]=0;
		}
	}

	// for(int i=2; i<N;i++){
	// 	if(prime[i]==1){

}

int primediv(int num){

	int cnt = 0;

	//cout<<"num "<<num;

	//cout<< "size"<<primeNums.size()<<endl;

	for(auto i : primeNums){
		//cout<<i<<" i"<<endl;
		// num>=i && 
		
		if(num % i == 0){
			cnt++;
			while(num%i==0)
				num = num/i;
		}
		if(sqrt(num)+1 < i)
			break;
	}

	// if(cnt == 0)
	// 	cnt = 1;

	if(num>1)
		cnt++;


	return cnt;
}

int main(){
	int t;
	int n,m;
	computePrime();

	cin>>t;

	//map<long long int, int> mp;
	vector<int> mp(2111111,0);



		for(int i=2;i<=2e6+1;i++){
			mp[i] = primediv(i);
			//mp[i] = count;
			//mp.insert({i,count});
		}

	while(t>0){
		cin>>n;
		cin>>m;	


		long long int sum=0;

		for(int i=2; i<=m+1;i++){
			sum = sum + mp[i];
		}

		long long int fsum = sum;

		for(int i=2; i<=n;i++){
			sum = sum + mp[m+i]-mp[i];
			fsum = fsum + sum;
		}

		cout<<fsum<<endl;

		t--;
	}

	return 0;
}
