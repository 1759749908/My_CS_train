#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Multi(vector<vector<int>> M_A, vector<vector<int>> M_B) {
	int row_A = M_A.size();
	int column_B = M_B[0].size();
	if (row_A != column_B)
		abort();

	vector<vector<int>> M_C(3, vector<int>(3));

	for (int i = 0; i < row_A; i++)
		for (int j = 0; j < column_B; j++) {
			int tmp_ans = 0;
			for (int k = 0; k < row_A; k++) {
				tmp_ans += M_A[i][k] * M_B[k][j];
			}
			M_C[i][j] = tmp_ans;
		}

	return M_C;
}


int main() {
	vector<vector<int>> M_A;
	vector<vector<int>> M_B;

	M_A.push_back(vector<int>({ 1,2,3 }));
	M_A.push_back(vector<int>({ 1,6,3 }));

	M_B.push_back(vector<int>({ 6,1 }));
	M_B.push_back(vector<int>({ -5,6 }));
	M_B.push_back(vector<int>({ 2,9}));

	auto ans = Multi(M_A, M_B);


	int row_A = M_A.size();
	int column_B = M_B[0].size();
	for (int i = 0; i < row_A; i++){
		for (int u = 0; u < column_B; u++) {
			cout << ans[i][u] << " ";
		}
		cout << endl;
	}
}