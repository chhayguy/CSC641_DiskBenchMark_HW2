/* Disk Benchmark Program for Seagate 2TB BarraCuda (ST2000DM006). The following information is given
in the specifications sheet provided by Seagate.
Bytes per Sector: 4096
Heads/Disks: 6/3
Interface: SATA 6Gb/s
Cache Size: 64MB

The information below was acquired by running Windows Powershell and using the following command "gwmi win32_diskdrive |select Model,SectorsPerTrack,Size,TotalCylinders,TotalHeads,TotalSectors,BytesP
erSector".
Sectors per Track: 63
Size: 2000396321280
Total Cylinders: 243201
Total Heads: 255
Total Sectors: 3907024065
*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

#define WINPAUSE system("pause")

using namespace std;

// urn() is a random number generator that produces standard uniform random numbers.
// We want good quality of randomness but also a uniform distribution, or that each element
// has equal probability of being chosen.
double urn(void)
{
	static unsigned long r[18] = { 131071,43691,262657,649657,274177,
		524287,121369,61681,179951,513239,
		333667,909091,1777,8617,87211,
		174763,65537,0 },
		xmod = 1048573;
	static double rnmax = xmod;
	static int i = 17, j = 16, k = 0, n = 18;
	double rn;
	r[i] = (r[j] + r[k]) % xmod;
	rn = r[i] / rnmax;
	i = (i + 1) % n;
	j = (j + 1) % n;
	k = (k + 1) % n;
	return rn;
}


// Shuffler method ensures that there is no correlation between the numbers generated in the list produced in urn().
double shuffler(void)
{
	static int n = 200, firstcall = 1;
	static double table[200];
	double rnumber;
	int i, itable;
	if (firstcall)
	{
		for (i = 0; i<n; i++) table[i] = urn(); // populating array with uniform random numbers
		firstcall = 0;
	}
	itable = int(n * urn()); // Uniform selection from table
	rnumber = table[itable];
	table[itable] = urn(); // restore array element
	return rnumber;
}

int main()
{
	const int n = 200;
	double dq[n]; // dq representing Q components

	// Using Shuffler Method for RNG
	for (int i = 0; i < n; i++) {
		dq[i] = shuffler();
	}
	for (int i = 0; i < n; i++) {
		cout << shuffler();
	}
	// dq should be filled with uniformly distributed random numbers
	// pick an initial position in the array call it "X".
	double X = n/2; // middle of the array dq

	// Loop through the array, and move pointer to closest position dq[k]
	for (int i = 0; i < n; i++) {

	}

	// Replace dq with random value, compute seek distance and seek time

	// Compute average seek distance and time for n > 10000 disk accesses

	WINPAUSE;
    return 0;
}

