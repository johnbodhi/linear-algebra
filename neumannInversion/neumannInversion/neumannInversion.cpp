#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;

using namespace std::chrono;

auto start = high_resolution_clock::now();

int main() {

	const int X = 5;

	const int N = X, M = X, O = X, P = X, L = 4;

	double A[M][N], S[M][N], I[M][N], Q[L][M][N], R[M][N];

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution <double> dist(0.0, 0.99);


	for (int j = 0; j <= M - 1; j++) {

		for (int i = 0; i <= N - 1; i++) {

			if (i == j) {

				I[i][j] = 1.0;
			}
			else {

				I[i][j] = 0.0;
			}
		}
	}


	for (int j = 0; j <= M - 1; j++) {

		for (int i = 0; i <= N - 1; i++) {


			if (i == j) {

				A[j][i] = dist(mt);
			}
			else {

				A[j][i] = 0.0;
			}

			S[j][i] = 0.0;

			R[j][i] = 0.0;
		}
	}


	for (int j = 0; j <= M - 1; j++) {
		for (int i = 0; i <= N - 1; i++) {

			S[j][i] = I[j][i] - A[j][i];
		}
	}

	for (int k = 0; k <= L - 1; k++) {

		for (int j = 0; j <= M - 1; j++) {

			for (int i = 0; i <= N - 1; i++) {

				Q[k][j][i] = 0.0;

			}
		}
	}


	for (int k = 0; k <= L - 1; k++) {

		for (int j = 0; j <= M - 1; j++) {

			for (int i = 0; i <= N - 1; i++) {

				if ( k == 0 ) {

					Q[0][j][i] = I[j][i];
				}
				else if ( k == 1 ) {

					Q[1][j][i] = S[j][i];
				}
				else if ( i == j ) {

					Q[k][j][i] = pow(S[j][i], k);
				}
			}
		}
	}

	for (int k = 0; k <= L - 1; k++) {
		for (int j = 0; j <= M - 1; j++) {
			for (int i = 0; i <= N - 1; i++) {

				R[j][i] += Q[k][j][i];
			}
		}
	}


	for (int j = 0; j <= M - 1; j++) {

		for (int i = 0; i <= N - 1; i++) {

			std::cout << setw(10) << R[j][i] << setw(10);
		}
		std::cout << std::endl;
	}


	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "Time taken by function: " << duration.count() \
		<< " microseconds." << std::endl;

	return 0;
}
