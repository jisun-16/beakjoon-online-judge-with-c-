#include<iostream>
#include<cstdlib>
using namespace std;
int main() {
	int M, N;
	cin >> M >> N;
	for (int i = M; i <= N; i++) {
		int check = 1;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				check = 0;
				break;
			}
		}
		if (check == 1 && i != 1) cout << i << ' ';
	}
}