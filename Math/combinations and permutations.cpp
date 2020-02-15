#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 1000;
long long C[MAX][MAX] = {0};	// whatever needed
 
void build_nCk() {	// Bottom up approach
	for(int i = 0; i < MAX; ++i)
		for(int j = 0; j < MAX; ++j)
			C[i][j] = (j == 0) ? 1 : ( (i == 0) ? 0 : C[i-1][j-1]+C[i-1][j]);
}
 
 
vector<int> combination;
int n = 20, m = 4, comb_cnt = 0;
 
void get_combination(int i = 0, int last_val = 0) {
	if(i == m) {
		++comb_cnt;		// finally will be 4845
		return;		// you can print combination here
	}
 
	for (int j = last_val+1; j <= n; ++j) {
		combination.push_back(j);
		// Think: dynamically create one more loop
		get_combination(i+1, j);	// backtracking
		combination.pop_back();
	}
}
 
vector<int> permutation;
int n_perm = 4, perm_cnt = 0;
bool is_visited[4];
 
void get_perm(int i = 0) {
	if(i == n_perm){
		++perm_cnt;		// finally will be 4! = 24
		return;		// you can print permutation here
	}
 
	for (int j = 0; j < n_perm; ++j) {
		if(is_visited[j])
			continue;
 
		permutation.push_back(j);
		is_visited[j] = 1;
 
		get_perm(i+1);
 
		is_visited[j] = 0;
		permutation.pop_back();
	}
 
}
 
int main() {
 
	vector<int> p = {0, 1, 2, 3};
 
	do {
		++perm_cnt;
		// use p vector
	} while(next_permutation(p.begin(), p.end()));
 
	cerr<<perm_cnt;	// 24
 
	return 0;
	get_perm();		cerr<<perm_cnt;
 
	return 0;
 
 
	// build_nCk();
 
	///////////////////////////////////////////////////////////////////////////
	return 0;
 
	long long cnt = 0;
 
	for (int i1 = 1; i1 <= 20; ++i1) {
		for (int i2 = i1+1; i2 <= 20; ++i2) {
			for (int i3 = i2+1; i3 <=20; ++i3) {
				for (int i4 = i3+1; i4 <= 20; ++i4) {
					cnt++;
				}
			}
		}
	}
 
	cout<<cnt<<"\n";	// 4845 = C(20, 4)
	// {i1, i2, i3, i4} 4 values selected without repetition
	// from set {1, 2, 3.....20}
 
	return 0;
}