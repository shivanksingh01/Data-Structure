// Kepler Law - codechef JAN LONG - 2022-1 division-3 (rated)
// Kepler’s Law states that the planets move around the sun in elliptical orbits with the sun at one focus. 
// Kepler's 3rd law is The Law of Periods, according to which:
// The square of the time period of the planet is directly proportional to the cube of the semimajor axis of its orbit.
// You are given the Time periods (T1,T2) and Semimajor Axes (R1,R2) of two planets orbiting the same star.

// Please determine if the Law of Periods is satisfied or not, i.e, if the constant of proportionality of both planets is the same.
// Print "Yes" (without quotes) if the law is satisfied, else print "No"

// input : 
// 3
// 1 1 1 1    - yes
// 1 2 3 4    - no
// 1 8 2 8    - yes

// Explanation -  T^2 = K*(r^3)
// t1^2 = K*(r1^3)   --- (1)
// t2^2 = K*(r2^3)   --- (2)
// from 1 and 2nd
// t1^2/r1^3 = t2^2/r2^3


#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    double t1, t2, r1, r2;
	    cin>>t1>>t2>>r1>>r2;
	    double lhs = (pow(t1,2)/pow(r1,3));
	    double rhs = (pow(t2,2)/pow(r2,3));
	    if(lhs==rhs){
	        cout<<"YES"<<endl;
	    }else{
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}
