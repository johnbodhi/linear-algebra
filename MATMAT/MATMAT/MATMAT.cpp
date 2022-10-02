#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

int main() {

	const int M = 5, N = 5, O = 5;

	int A[N][M], B[N][M], C[N][M];

	int ii = 0, jj = 0;

	int aa = 0, bb = 0;

	int uu = 0, vv = 0;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution <double> dist(1.0, 10.0);


	for (int j = 0; j <= M - 1; j++) {

		for (int i = 0; i <= N - 1; i++) {

			A[i][j] = dist(mt);
			B[i][j] = dist(mt);
			C[i][j] = 0;
		}
	}

	for (int j = 0; j <= M - 1; j++) {

		for (int i = 0; i <= N - 1; i++) {

			std::cout << setw(5) << A[i][j] << setw(5);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;


	for (int j = 0; j <= M - 1; j++) {

		for (int i = 0; i <= N - 1; i++) {

			std::cout << setw(5) << B[i][j] << setw(5);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;


	for (int k = 0; k <= O - 1; k++) {

		for (int j = 0; j <= M - 1; j++) {

			for (int i = 0; i <= N - 1; i++) {

				C[uu][vv] += A[aa][bb] * B[jj][ii];

				aa++; ii++;
			}
			aa = 0; ii = 0; jj++; uu++;
		}
		jj = 0; uu = 0; bb++; vv++;
	}

	for (int j = 0; j <= M - 1; j++) {

		for (int i = 0; i <= N - 1; i++) {

			std::cout << setw(5) << C[i][j] << setw(5);
		}
		std::cout << std::endl;
	}

	return 0;
}