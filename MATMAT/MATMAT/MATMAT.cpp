#include <iostream>
#include <random>
#include <iomanip>
#include <chrono>

using namespace std;

using namespace chrono;

auto start = high_resolution_clock::now();

int main() {

	const int X = 50;

	const int N = X, M = X, O = X, P = X;

	float A[N][M], B[O][P], C[N][P];

	int ii = 0, jj = 0;
	
	int aa = 0, bb = 0;

	int uu = 0, vv = 0;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution <float> dist(0.0, 0.99);

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

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << "Time taken by function: " << duration.count() \
		<< " microseconds." << std::endl;

	return 0;
}
