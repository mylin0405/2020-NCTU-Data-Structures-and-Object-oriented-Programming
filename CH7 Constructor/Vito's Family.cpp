#include<iostream>
#include<vector>         //v.clear
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> v;

int main(){
	int n, num , x, backup_num, mid;
	cin >> n;
	while(n--){
		cin >> num;
		backup_num =num;
		v.clear();
		while(num--){
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		mid = v[num/2];
		int sum; sum =0;
		for(int i=0;i<backup_num;i++){
			sum += abs(v[i]-mid);
		}
		cout << sum << endl;
	}
}
