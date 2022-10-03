#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

int main() {

	const int N = 2, M = 4, O = 4, P = 2;

	int A[N][M], B[O][P], C[N][P];

	int ii = 0, jj = 0;
	
	int aa = 0, bb = 0;

	int uu = 0, vv = 0;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution <double> dist(1.0, 10.0);

	for (int i = 0; i <= N - 1; i++) {

		for (int j = 0; j <= M - 1; j++) {
			
			A[i][j] = dist(mt);
		}
	}

	for (int i = 0; i <= O - 1; i++) {

		for (int j = 0; j <= P - 1; j++) {

			B[i][j] = dist(mt);
		}
	}

	for (int i = 0; i <= N - 1; i++) {

		for (int j = 0; j <= P - 1; j++) {

			C[i][j] = 0;
		}
	}

	for (int i = 0; i <= N - 1; i++) {

		for (int j = 0; j <= M - 1; j++) {

			std::cout << setw(5) << A[i][j] << setw(5);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;


	for (int i = 0; i <= O - 1; i++) {

		for (int j = 0; j <= P - 1; j++) {

			std::cout << setw(5) << B[i][j] << setw(5);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;


	for (int k = 0; k <= N - 1; k++) {

		for (int j = 0; j <= P - 1; j++) {

			for (int i = 0; i <= M - 1; i++) {

				C[uu][vv] += A[aa][bb] * B[jj][ii];

				bb++; jj++;
			}
			bb = 0; jj = 0; ii++; vv++;
		}
		ii = 0; vv = 0; aa++; uu++;
	}

	for (int i = 0; i <= P - 1; i++) {

		for (int j = 0; j <= N - 1; j++) {

			std::cout << setw(5) << C[i][j] << setw(5);
		}
		std::cout << std::endl;
	}

	return 0;
}
